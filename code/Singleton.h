#ifndef SINGLETON_H
#define SINGLETON_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QDate>
#include "Patient.h"
#include "Appointment.h"
#include "Injection.h"
#include "User.h"
#include "MedicalFile.h"

class Singleton {
private:
    static Singleton* instance;
    QSqlDatabase db; // Database connection
    void initializeDatabase();
    bool executeQuery(QSqlQuery& query, const QString& errorMessage);
    Singleton();
    ~Singleton();

public:
    static Singleton* getInstance();
    static User* currentUser;

    void savePatient(Patient* patient);
    void saveInjection(Injection* injection, const QString& ohip);
    void saveFile(MedicalFile* file, const QString& ohip);
    void saveAppointment(Appointment* appointment, const QString& ohip);
    void createUser(const QString& username, const QString& password, const QString& role);

    void deleteAppointment(int id);
    void deleteFile(const QString& ohip, const QString& type, const QString& date);
    void deleteUser(const QString& username);

    std::vector<User*> getUsers();
    Patient* searchPatientOHIP(const QString& ohip);
    std::vector<Injection*> searchInjections(const QString& ohip);
    std::vector<MedicalFile*> searchFiles(const QString& ohip);
    std::vector<Appointment*> searchAppointments(const QString& ohip);
    std::vector<Appointment*> AppointmentsForDay(const QString& date);
    bool login(const QString& username, const QString& password);
};
#endif // SINGLETON_H
