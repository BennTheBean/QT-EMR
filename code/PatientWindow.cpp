#include "mainwindow.h"
#include "PatientWindow.h"
#include "ui_PatientWindow.h"
#include "AddPatientDialog.h"
#include "AddInjectionDialog.h"
#include "AddFileDialog.h"
#include "AddAppointmentDialog.h"
#include "AppointmentWindow.h"
#include "Settings.h"

PatientWindow::PatientWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::PatientWindow) {
    data = Singleton::getInstance();
    ui->setupUi(this);

    connect(ui->HButton, &QPushButton::clicked, this, &PatientWindow::openHomeWindow);
    connect(ui->AButton, &QPushButton::clicked, this, &PatientWindow::openAppointmentWindow);
    connect(ui->SButton, &QPushButton::clicked, this, &PatientWindow::openSettings);
    connect(ui->search, &QPushButton::clicked, this, &PatientWindow::SearchPatient);
    connect(ui->addPatient, &QPushButton::clicked, this, &PatientWindow::addNewPatient);
    connect(ui->editPatient, &QPushButton::clicked, this, &PatientWindow::editPatient);
    connect(ui->addInjection, &QPushButton::clicked, this, &PatientWindow::addNewInjection);
    connect(ui->addAppoint, &QPushButton::clicked, this, &PatientWindow::addNewAppointment);
    connect(ui->editAppoint, &QPushButton::clicked, this, &PatientWindow::editAppointment);
    connect(ui->cancel, &QPushButton::clicked, this, &PatientWindow::cancel);
    connect(ui->addFile, &QPushButton::clicked, this, &PatientWindow::addNewFile);
    connect(ui->delete_2, &QPushButton::clicked, this, &PatientWindow::deleteFile);
    connect(ui->openFile, &QPushButton::clicked, this, &PatientWindow::openFile);
}

PatientWindow::~PatientWindow() {
    delete ui;
}

void PatientWindow::openHomeWindow() {
    MainWindow* mainWindow = new MainWindow();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose); // Ensures it cleans up properly
    mainWindow->show();

    // Close and delete the current window (this will end the application when all windows are closed)
    this->close();
}

void PatientWindow::openSettings() {
    if (data->currentUser->getRole() == "Admin") {
        Settings* settings = new Settings();
        settings->setAttribute(Qt::WA_DeleteOnClose);
        settings->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Restricted", "Must be an admin to access system settings");
    }
}

void PatientWindow::openAppointmentWindow() {
    AppointmentWindow* appointmentWindow = new AppointmentWindow();
    appointmentWindow->setAttribute(Qt::WA_DeleteOnClose); // Ensures it cleans up properly
    appointmentWindow->show();

    // Close and delete the current window (this will end the application when all windows are closed)
    this->close();
}

void PatientWindow::SearchPatient() {
    QString ohip = ui->OHIP->text();
    patient = data->searchPatientOHIP(ohip);
    displayPatient();
    displayInjections();
    displayAppointments();
    displayFiles();
}

void PatientWindow::displayAppointments() {
    if (patient != nullptr) {
        appoints = data->searchAppointments(patient->getOHIP());
        ui->appoint->clear(); // Clear the UI list

        for (size_t i = 0; i < appoints.size(); ++i) {
            const auto& appointment = appoints[i];
            QListWidgetItem* item = new QListWidgetItem(
                appointment->getType() + ", Date: " + appointment->getDate() + "\n"
                + "Time: " + appointment->getTime() + ", Duration: " + QString::number(appointment->getDuration())
                );
            item->setData(Qt::UserRole, static_cast<int>(i)); // Store the index
            ui->appoint->addItem(item);
        }
    }
}

void PatientWindow::displayFiles() {
    if (patient != nullptr) {
        files = data->searchFiles(patient->getOHIP());
        ui->files->clear(); // Clear the UI list

        for (size_t i = 0; i < files.size(); ++i) {
            const auto& file = files[i];
            QListWidgetItem* item = new QListWidgetItem(
                file->getFileName()
            );
            item->setData(Qt::UserRole, static_cast<int>(i)); // Store the index
            ui->files->addItem(item);
        }
    }
}

void PatientWindow::displayInjections()
{
    if (patient != nullptr) {
        injections = data->searchInjections(patient->getOHIP());
        patient->setInjections(injections);
        ui->shots->clear();
        for (const auto& injection : injections) {
            QListWidgetItem* item = new QListWidgetItem(
                "Injection Type: " + injection->getType() + "\n"
                    + "Date Administered: " + injection->getDate() + "\n"
                );
            ui->shots->addItem(item);
        }
    }
}


void PatientWindow::displayPatient()
{
    if (patient != nullptr) {
        QListWidgetItem* item = new QListWidgetItem("Name: " + patient->getName() + "\n"
                               + "DOB: " + patient->getDOB() + "\n"
                               + "Sex: " + patient->getSex() + "\n"
                               + "OHIP: " + patient->getOHIP() + "\n"
                               + "Address: " + patient->getAddress() + "\n"
                               + "Email: " + patient->getEmail()
                               );
        ui->demo->addItem(item);
    } else {
        QMessageBox::warning(this, "Patient not found", "Please input a valid OHIP");
    }
}

void PatientWindow::addNewPatient() {
    AddPatientDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        QString dob = dialog.getDOB();
        QString sex = dialog.getSex();
        QString email = dialog.getEmail();
        QString address = dialog.getAddress();
        QString ohip = dialog.getOHIP();

        // Save new patient
        Patient* newPatient = new Patient(name, dob, sex, ohip, email, address);
        data->savePatient(newPatient);
        patient = newPatient;
        displayPatient();
        QMessageBox::information(this, "Success", "Patient added successfully.");
    }
}

void PatientWindow::editPatient() {
    if (patient != nullptr) {
        AddPatientDialog dialog(this, patient);

        if (dialog.exec() == QDialog::Accepted) {
            QString name = dialog.getName();
            QString dob = dialog.getDOB();
            QString sex = dialog.getSex();
            QString email = dialog.getEmail();
            QString address = dialog.getAddress();
            QString ohip = dialog.getOHIP();

            // Save new patient
            Patient* newPatient = new Patient(name, dob, sex, ohip, email, address);
            data->savePatient(newPatient);
            patient = newPatient;
            displayPatient();
            QMessageBox::information(this, "Success", "Patient edited successfully.");
        }
    } else {
        QMessageBox::warning(this, "No Patient Selected", "Please select a patient");
    }
}

void PatientWindow::addNewInjection() {
    if (patient != nullptr) {
        AddInjectionDialog dialog(this);

        if (dialog.exec() == QDialog::Accepted) {
            QString type = dialog.getType();
            QString date = dialog.getDate();

            // Save new patient
            Injection* newInjection = new Injection(type, date);
            data->saveInjection(newInjection, patient->getOHIP());
            displayInjections();
            QMessageBox::information(this, "Success", "Injection added successfully.");
        }
    } else {
        QMessageBox::warning(this, "No Patient Selected", "Please select a patient");
    }
}

void PatientWindow::addNewFile() {
    if (data->currentUser->getRole() == "Receptionist") {
        QMessageBox::warning(this, "Invalid Credentials", "Only Admins and Doctors can create medical files");
        return;
    }
    if (patient != nullptr) {
        AddFileDialog dialog(this);

        if (dialog.exec() == QDialog::Accepted) {
            QString fileData = dialog.getData();
            QString date = dialog.getDate();
            QString fileType = dialog.getFile();

            FileFactory* factory = nullptr;
            if (fileType == "Laboratory Requisition") {
                factory = new LabReqFactory;
            } else if (fileType == "Immunization Record") {
                factory = new ImmunizationRecordFactory;
            } else {
                factory = new PrescriptionFactory;
            }

            MedicalFile* file = factory->createFile(date, patient, fileData);
            try {
                file->print();
            } catch (const std::runtime_error& e) {
                QMessageBox::critical(this, "Error", e.what());
                delete factory;
                return;
            }
            data->saveFile(file, patient->getOHIP());
            displayFiles();
            delete factory;
            QMessageBox::information(this, "Success", "File added successfully.");
        }
    } else {
        QMessageBox::warning(this, "No Patient Selected", "Please select a patient");
    }
}

void PatientWindow::addNewAppointment() {
    if (patient != nullptr) {
        AddAppointmentDialog dialog(this, nullptr, patient->getOHIP());

        if (dialog.exec() == QDialog::Accepted) {
            QString date = dialog.getDate();
            QString time = dialog.getTime();

            Appointment* newAppointment = new ConcreteAppointment(date, time, patient, 0);
            if (dialog.getNew()) {
                newAppointment = new NewPatientDecorator(newAppointment);
            } else {
                newAppointment = new ReturningPatientDecorator(newAppointment);
            }

            if (dialog.getFlu()){
                newAppointment = new FluShotDecorator(newAppointment);
            }

            data->saveAppointment(newAppointment, patient->getOHIP());
            displayAppointments();
            QMessageBox::information(this, "Success", "Appointment added successfully.");
        }
    } else {
        QMessageBox::warning(this, "No Patient Selected", "Please select a patient");
    }
}

void PatientWindow::editAppointment() {
    if (patient != nullptr) {
        QListWidgetItem* selectedItem = ui->appoint->currentItem();
        if (!selectedItem) {
            QMessageBox::warning(this, "No Appointment Selected", "Please select an appointment to edit.");
            return;
        }
        int index = ui->appoint->currentRow();
        if (appoints[index]) {
            AddAppointmentDialog dialog(this, appoints[index], patient->getOHIP()); // Pass the appointment to the dialog
            if (dialog.exec() == QDialog::Accepted) {
                QString date = dialog.getDate();
                QString time = dialog.getTime();

                // Update appointment details
                appoints[index] = new ConcreteAppointment(date, time, patient, 0);
                if (dialog.getNew()) {
                    appoints[index] = new NewPatientDecorator(appoints[index]);
                } else {
                    appoints[index] = new ReturningPatientDecorator(appoints[index]);
                }
                if (dialog.getFlu()){
                    appoints[index] = new FluShotDecorator(appoints[index]);
                }

                data->saveAppointment(appoints[index], patient->getOHIP()); // Implement updateAppointment in your Singleton
                displayAppointments();
                QMessageBox::information(this, "Success", "Appointment updated successfully.");
            }
        }
    } else {
        QMessageBox::warning(this, "No Patient Selected", "Please select a patient");
    }
}

void PatientWindow::cancel() {
    if (patient != nullptr) {
        QListWidgetItem* selectedItem = ui->appoint->currentItem();
        if (!selectedItem) {
            QMessageBox::warning(this, "No Appointment Selected", "Please select an appointment to cancel.");
            return;
        }
        int index = ui->appoint->currentRow();

                // Save changes and refresh the UI
        Appointment* appointment = appoints[index];
        data->deleteAppointment(appointment->getId()); // Implement updateAppointment in your Singleton
        displayAppointments();
        QMessageBox::information(this, "Success", "Appointment canceled successfully.");
    } else {
        QMessageBox::warning(this, "No Patient Selected", "Please select a patient");
    }
}

void PatientWindow::deleteFile() {
    if (patient != nullptr) {
        QListWidgetItem* selectedItem = ui->files->currentItem();
        if (!selectedItem) {
            QMessageBox::warning(this, "No File Selected", "Please select a file to delete.");
            return;
        }
        int index = selectedItem->data(Qt::UserRole).toInt();
        MedicalFile* file = files[index];
        data->deleteFile(patient->getOHIP(), file->getType(), file->getDate());
        displayFiles();
        try {
            file->deleteMedicalFile();
        } catch (const std::runtime_error& e) {
            QMessageBox::critical(this, "Error", e.what());
            return;
        }
        QMessageBox::information(this, "Success", "File deleted.");
    } else {
        QMessageBox::warning(this, "No Patient Selected", "Please select a patient");
    }
}

void PatientWindow::openFile() {
    if (patient != nullptr) {
        QListWidgetItem* selectedItem = ui->files->currentItem();
        if (!selectedItem) {
            QMessageBox::warning(this, "No File Selected", "Please select a file to open.");
            return;
        }
        int index = selectedItem->data(Qt::UserRole).toInt();
        MedicalFile* file = files[index];
        try {
            file->openFile();
        } catch (const std::runtime_error& e) {
            QMessageBox::critical(this, "Error", e.what());
            return;
        }
    } else {
        QMessageBox::warning(this, "No Patient Selected", "Please select a patient");
    }
}
