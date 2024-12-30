#include "Singleton.h"
// Initialize static members
Singleton* Singleton::instance = nullptr;
User* Singleton::currentUser = nullptr;

Singleton::Singleton() {
    initializeDatabase();
    createUser("Admin", "1234567890", "Admin");
}

Singleton::~Singleton() {
    if (db.isOpen()) {
        db.close();
    }
}

// Get instance
Singleton* Singleton::getInstance() {
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

bool Singleton::executeQuery(QSqlQuery& query, const QString& errorMessage) {
    if (!query.exec()) {
        qDebug() << errorMessage << query.lastError().text();
        return false;
    }
    return true;
}

// Initialize database
void Singleton::initializeDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("medical_records.db");

    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return;
    }

    std::vector<QString> tableQueries = {
        "CREATE TABLE IF NOT EXISTS patients ("
        "ohip TEXT PRIMARY KEY, "
        "name TEXT NOT NULL, dob TEXT NOT NULL, sex TEXT NOT NULL, "
        "email TEXT, address TEXT)",

        "CREATE TABLE IF NOT EXISTS appointments ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "date TEXT NOT NULL, time TEXT NOT NULL, decorators TEXT, "
        "patient_id TEXT NOT NULL, "
        "FOREIGN KEY(patient_id) REFERENCES patients(ohip), "
        "UNIQUE(date, time, patient_id))",

        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "username TEXT NOT NULL, password TEXT NOT NULL, role TEXT NOT NULL, "
        "UNIQUE(username))",

        "CREATE TABLE IF NOT EXISTS injections ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "type TEXT NOT NULL, date TEXT NOT NULL, patient_id TEXT NOT NULL, "
        "FOREIGN KEY(patient_id) REFERENCES patients(ohip), "
        "UNIQUE(type, date, patient_id))",

        "CREATE TABLE IF NOT EXISTS files ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "type TEXT NOT NULL, date TEXT NOT NULL, data TEXT NOT NULL, "
        "patient_id TEXT NOT NULL, "
        "FOREIGN KEY(patient_id) REFERENCES patients(ohip), "
        "UNIQUE(type, date, data, patient_id))"
    };


    for (const auto& queryStr : tableQueries) {
        QSqlQuery query;
        query.prepare(queryStr); // Prepare the query
        executeQuery(query, "Error creating table:");
    }
}

Patient* Singleton::searchPatientOHIP(const QString& ohip) {
    QSqlQuery query;
    query.prepare("SELECT * FROM patients WHERE ohip = :ohip");
    query.bindValue(":ohip", ohip);
    if (!executeQuery(query, "Error retrieving patient:")) return nullptr;

    if (query.next()) {
        return new Patient(query.value("name").toString(),
                           query.value("dob").toString(),
                           query.value("sex").toString(),
                           query.value("ohip").toString(),
                           query.value("email").toString(),
                           query.value("address").toString());
    } return nullptr;
}

std::vector<User*> Singleton::getUsers() {
    std::vector<User*> users;
    QSqlQuery query;
    query.prepare("SELECT * FROM users");

    if (!executeQuery(query, "Error retrieving users:")) return users;

    while (query.next()) {
        QString role = query.value("role").toString();
        if (role == "Doctor"){
            users.push_back(new Doctor(query.value("username").toString(), query.value("password").toString()));
        } else if (role == "Admin") {
            users.push_back(new Admin(query.value("username").toString(), query.value("password").toString()));
        } else {
            users.push_back(new Receptionist(query.value("username").toString(), query.value("password").toString()));
        }
    }
    return users;
}

std::vector<Injection*> Singleton::searchInjections(const QString& ohip) {
    std::vector<Injection*> injections;
    QSqlQuery query;
    query.prepare("SELECT * FROM injections WHERE patient_id = :ohip ORDER BY date DESC");
    query.bindValue(":ohip", ohip);

    if (!executeQuery(query, "Error retrieving injections:")) return injections;

    while (query.next()) {
        Injection* injection = new Injection(
            query.value("type").toString(),
            query.value("date").toString()
            );
        injections.push_back(injection);
    }

    return injections;
}

std::vector<MedicalFile*> Singleton::searchFiles(const QString& ohip) {
    std::vector<MedicalFile*> files;
    QSqlQuery query;
    // Query to fetch all injections for a patient based on ohip
    query.prepare("SELECT * FROM files WHERE patient_id = :ohip ORDER BY date DESC");
    query.bindValue(":ohip", ohip);

    if (!executeQuery(query, "Error retrieving files:")) return files;

    FileFactory* factory = nullptr;
    while (query.next()) {
        if (query.value("type").toString() == "Laboratory Requisition") {
            factory = new LabReqFactory;
        } else if (query.value("type").toString() == "Immunization Record") {
            factory = new ImmunizationRecordFactory;
        } else {
            factory = new PrescriptionFactory;
        }

        files.push_back(factory->createFile(
            query.value("date").toString(),
            searchPatientOHIP(query.value("patient_id").toString()),
            query.value("data").toString()
            ));
        delete factory; // Delete in each iteration
        factory = nullptr;
    }
    return files;
}

std::vector<Appointment*> Singleton::searchAppointments(const QString& ohip) {
    std::vector<Appointment*> appointments;
    QSqlQuery query;

    QString today = QDate::currentDate().toString("yyyy/MM/dd");

    // Query to fetch all appointments from today onwards in ascending order
    query.prepare("SELECT * FROM appointments WHERE date >= :today AND patient_id = :ohip ORDER BY date ASC, time ASC");
    query.bindValue(":today", today);
    query.bindValue(":ohip", ohip);

    if (!executeQuery(query, "Error retrieving future appointments:")) return appointments;

    while (query.next()) {
        QString date = query.value("date").toString();
        QString time = query.value("time").toString();
        QString decoratorStr = query.value("decorators").toString();
        int id = query.value("id").toInt();

        // Construct the base appointment
        Appointment* appointment = new ConcreteAppointment(date, time, nullptr, id); // Patient will be linked later

        // Apply decorators
        QStringList decorators = decoratorStr.split(",");
        for (const QString& decorator : decorators) {
            if (decorator == "NewPatient") {
                appointment = new NewPatientDecorator(appointment);
            } else if (decorator == "ReturningPatient") {
                appointment = new ReturningPatientDecorator(appointment);
            } else if (decorator == "FluShot") {
                appointment = new FluShotDecorator(appointment);
            }
        }

        appointments.push_back(appointment);
    }

    return appointments;
}

std::vector<Appointment*> Singleton::AppointmentsForDay(const QString& date) {
    std::vector<Appointment*> appointments;
    QSqlQuery query;
    query.prepare("SELECT * FROM appointments WHERE date = :date ORDER BY time ASC");
    query.bindValue(":date", date);

    if (!executeQuery(query, "Error finding appointments:")) return appointments; // Return empty list if query fails

    while (query.next()) {
        // Extract appointment details from query result
        QString date = query.value("date").toString();
        QString time = query.value("time").toString();
        QString decoratorStr = query.value("decorators").toString();
        int id = query.value("id").toInt();
        QString patientOHIP = query.value("patient_id").toString();

        // Create the patient object
        Patient* patient = searchPatientOHIP(patientOHIP); // Use the search function to fetch the patient by OHIP
        if (!patient) {
            qDebug() << "Patient with OHIP" << patientOHIP << "not found.";
            continue; // Skip this appointment if the patient is not found
        }
        // Construct the base appointment
        Appointment* appointment = new ConcreteAppointment(date, time, patient, id);

        // Apply decorators (if any)
        QStringList decorators = decoratorStr.split(",");
        for (const QString& decorator : decorators) {
            if (decorator == "NewPatient") {
                appointment = new NewPatientDecorator(appointment);
            } else if (decorator == "ReturningPatient") {
                appointment = new ReturningPatientDecorator(appointment);
            } else if (decorator == "FluShot") {
                appointment = new FluShotDecorator(appointment);
            }
        }

        appointments.push_back(appointment);
    }

    return appointments;
}


// Save patient to database
void Singleton::savePatient(Patient* patient) {
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO patients (ohip, name, dob, sex, email, address) "
                  "VALUES (:ohip, :name, :dob, :sex, :email, :address)");
    query.bindValue(":ohip", patient->getOHIP());
    query.bindValue(":name", patient->getName());
    query.bindValue(":dob", patient->getDOB());
    query.bindValue(":sex", patient->getSex());
    query.bindValue(":email", patient->getEmail());
    query.bindValue(":address", patient->getAddress());

    executeQuery(query, "Error saving patient:");
}

// Save injection to database
void Singleton::saveInjection(Injection* injection, const QString& ohip) {
    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO injections (type, date, patient_id) "
                  "VALUES (:type, :date, :patient_id)");
    query.bindValue(":type", injection->getType());
    query.bindValue(":date", injection->getDate());
    query.bindValue(":patient_id", ohip);

    executeQuery(query, "Error saving injection:");
}

// Save injection to database
void Singleton::saveFile(MedicalFile* file, const QString& ohip) {
    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO files (type, date, data, patient_id) "
                  "VALUES (:type, :date, :data, :patient_id)");
    query.bindValue(":type", file->getType());
    query.bindValue(":date", file->getDate());
    query.bindValue(":data", file->getData());
    query.bindValue(":patient_id", ohip);

    executeQuery(query, "Error saving file:");
}

void Singleton::saveAppointment(Appointment* appointment, const QString& ohip) {
    QSqlQuery query;
    QString decorators;
    QString modifiedType = appointment->getType();

    if (modifiedType.contains("New Patient")) {
        decorators += "NewPatient,";
        modifiedType.remove("New Patient - ");
    } else {
        decorators += "ReturningPatient,";
        modifiedType.remove("Returning Patient - ");
    }
    if (modifiedType.contains("Flu Shot")) {
        decorators += "FluShot";
        modifiedType.remove(" and Flu Shot");
    }

    // Use INSERT OR REPLACE to handle both new and existing appointments
    query.prepare("INSERT OR REPLACE INTO appointments (id, date, time, decorators, patient_id) "
                  "VALUES (:id, :date, :time, :decorators, :patient_id)");
    if (appointment->getId() == 0) {
        QSqlQuery idQuery;
        if (!idQuery.exec("SELECT MAX(id) FROM appointments")) {
            qDebug() << "Error generating new appointment ID:" << idQuery.lastError().text();
            return;
        }
        if (idQuery.next()) {
            query.bindValue(":id", idQuery.value(0).toInt() +1);
        } else {
            query.bindValue(":id", 1);
        }
    } else {
        query.bindValue(":id", appointment->getId());
    }
    query.bindValue(":date", appointment->getDate());
    query.bindValue(":time", appointment->getTime());
    query.bindValue(":decorators", decorators);
    query.bindValue(":patient_id", ohip);

    if (executeQuery(query, "Error saving appointment:")) return;
}

void Singleton::deleteAppointment(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM appointments WHERE id = :id");
    query.bindValue(":id", id);

    if (executeQuery(query, "Error deleting appointment:")) return;
}

void Singleton::deleteFile(const QString& ohip, const QString& type, const QString& date) {
    QSqlQuery query;
    query.prepare("DELETE FROM files WHERE patient_id = :id AND type = :type AND date = :date");
    query.bindValue(":id", ohip);
    query.bindValue(":type", type);
    query.bindValue(":date", date);

    if (executeQuery(query, "Error deleting file:")) return;
}

// Create a new user
void Singleton::createUser(const QString& username, const QString& password, const QString& role) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, role) VALUES (:username, :password, :role)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":role", role);

    executeQuery(query, "Error creating user:");
}

// Log in a user
bool Singleton::login(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!executeQuery(query, "Error logging in user:")) return false;

    if (query.next()) {
        QString role = query.value("role").toString();
        if (role == "Doctor"){
            currentUser = new Doctor(username, password);
        } else if (role == "Admin") {
            currentUser = new Admin(username, password);
        } else {
            currentUser = new Receptionist(username, password);
        }

        return true;
    } else {
        qDebug() << "Invalid username or password.";
        return false;
    }
}

// Delete a user
void Singleton::deleteUser(const QString& username) {
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE username = :username");
    query.bindValue(":username", username);

    executeQuery(query, "Error deleting user:");
}
