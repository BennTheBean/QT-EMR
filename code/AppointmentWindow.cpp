#include "AppointmentWindow.h"
#include "ui_AppointmentWindow.h"
#include "PatientWindow.h"
#include "Settings.h"
#include "mainwindow.h"
#include "AddAppointmentDialog.h"

AppointmentWindow::AppointmentWindow(QWidget *parent)
    : QMainWindow(parent), date(QDate::currentDate()), ui(new Ui::AppointmentWindow)
{
    ui->setupUi(this);
    data = Singleton::getInstance();

    connect(ui->PButton, &QPushButton::clicked, this, &AppointmentWindow::openPatientWindow);
    connect(ui->HButton, &QPushButton::clicked, this, &AppointmentWindow::openHomeWindow);
    connect(ui->SButton, &QPushButton::clicked, this, &AppointmentWindow::openSettings);
    connect(ui->add, &QPushButton::clicked, this, &AppointmentWindow::addNewAppointment);
    connect(ui->edit, &QPushButton::clicked, this, &AppointmentWindow::editAppointment);
    connect(ui->cancel, &QPushButton::clicked, this, &AppointmentWindow::cancelAppointment);
    connect(ui->date, &QDateEdit::dateChanged, this,
            [this](const QDate& newDate) {
                date = newDate;
                displayAppointments(date.toString("yyyy/MM/dd"));
            });

    ui->date->setDate(QDate::currentDate());
    displayAppointments(QDate::currentDate().toString("yyyy/MM/dd"));
}

AppointmentWindow::~AppointmentWindow()
{
    delete ui;
}

void AppointmentWindow::openPatientWindow() {
    PatientWindow* patientWindow = new PatientWindow();
    patientWindow->setAttribute(Qt::WA_DeleteOnClose); // Ensures it cleans up properly
    patientWindow->show();
    this->close();
}

void AppointmentWindow::openSettings() {
    if (Singleton::getInstance()->currentUser->getRole() == "Admin") {
        Settings* settings = new Settings();
        settings->setAttribute(Qt::WA_DeleteOnClose);
        settings->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Restricted", "Must be an admin to access system settings");
    }
}

void AppointmentWindow::openHomeWindow() {
    MainWindow* mainWindow = new MainWindow();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose); // Ensures it cleans up properly
    mainWindow->show();

    // Close and delete the current window (this will end the application when all windows are closed)
    this->close();
}

void AppointmentWindow::displayAppointments(const QString& date) {
    // Fetch appointments for the selected day from the database (Singleton in this case)
    appoints = data->AppointmentsForDay(date);
    ui->appointments->clear();

    const int startHour = 9;
    const int endHour = 15;
    const int numSlots = (endHour - startHour) * 2 + 2; // Include 15:30 as the last slot
    ui->appointments->setRowCount(numSlots);
    ui->appointments->setColumnCount(5); // Ensure there are enough columns

    for (int i = 0; i < numSlots; ++i) {
        int hour = startHour + i / 2;
        int minute = (i % 2) * 30;
        QString timeSlot = QString("%1:%2").arg(hour, 2, 10, QLatin1Char('0')).arg(minute, 2, 10, QLatin1Char('0'));

        // Set the time in the first column
        ui->appointments->setItem(i, 0, new QTableWidgetItem(timeSlot));

        bool appointmentFound = false;

        // Check for appointments at the current time slot
        for (const auto& appointment : appoints) {
            if (appointment->getTime() == timeSlot) {
                ui->appointments->setItem(i, 1, new QTableWidgetItem(appointment->getType()));
                ui->appointments->setItem(i, 2, new QTableWidgetItem(QString::number(appointment->getDuration()) + " min"));
                ui->appointments->setItem(i, 3, new QTableWidgetItem(appointment->getPatient()->getName()));
                ui->appointments->setItem(i, 4, new QTableWidgetItem(appointment->getPatient()->getOHIP()));
                appointmentFound = true;
                break;
            }
        }

        if (!appointmentFound) {
            ui->appointments->setItem(i, 1, new QTableWidgetItem("No Appointment"));
            ui->appointments->setItem(i, 2, new QTableWidgetItem("-"));
            ui->appointments->setItem(i, 3, new QTableWidgetItem("-"));
            ui->appointments->setItem(i, 4, new QTableWidgetItem("-"));
        }
    }

    ui->appointments->resizeColumnToContents(1); // Type
    ui->appointments->resizeColumnToContents(3); // Name
}




void AppointmentWindow::addNewAppointment() {
        AddAppointmentDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QString date = dialog.getDate();
            QString time = dialog.getTime();

            Appointment* newAppointment = new ConcreteAppointment(date, time, nullptr, 0);
            if (dialog.getNew()) {
                newAppointment = new NewPatientDecorator(newAppointment);
            } else {
                newAppointment = new ReturningPatientDecorator(newAppointment);
            }

            if (dialog.getFlu()){
                newAppointment = new FluShotDecorator(newAppointment);
            }

            data->saveAppointment(newAppointment, dialog.getOhip());
            displayAppointments(dialog.getDate());
            QMessageBox::information(this, "Success", "Appointment added successfully.");
        }
}

void AppointmentWindow::editAppointment() {
    int selectedRow = ui->appointments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Appointment Selected", "Please select an appointment to edit.");
        return;
    }

    QString timeSlot = ui->appointments->item(selectedRow, 0)->text();

    // Find the matching appointment
    Appointment* appointmentToEdit = nullptr;
    for (const auto& appointment : appoints) {
        if (appointment->getTime() == timeSlot) {
            appointmentToEdit = appointment;
            break;
        }
    }

    if (appointmentToEdit) {
        AddAppointmentDialog dialog(this, appointmentToEdit, appointmentToEdit->getPatient()->getOHIP());
        if (dialog.exec() == QDialog::Accepted) {
            QString newDate = dialog.getDate();
            QString newTime = dialog.getTime();
            Patient* patient = appointmentToEdit->getPatient();

            appointmentToEdit = new ConcreteAppointment(newDate, newTime, patient, 0);

            if (dialog.getNew()) {
                appointmentToEdit = new NewPatientDecorator(appointmentToEdit);
            } else {
                appointmentToEdit = new ReturningPatientDecorator(appointmentToEdit);
            }
            if (dialog.getFlu()) {
                appointmentToEdit = new FluShotDecorator(appointmentToEdit);
            }

            // Save changes back to the Singleton database
            data->saveAppointment(appointmentToEdit, dialog.getOhip());

            // Refresh the appointment display
            displayAppointments(date.toString("yyyy/MM/dd"));
            QMessageBox::information(this, "Success", "Appointment updated successfully.");
        }
    } else {
        QMessageBox::warning(this, "Error", "No appointment found to edit for the selected time slot.");
    }
}


void AppointmentWindow::cancelAppointment() {
    int selectedRow = ui->appointments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Appointment Selected", "Please select an appointment to cancel.");
        return;
    }

    QString timeSlot = ui->appointments->item(selectedRow, 0)->text();

    // Find the matching appointment
    Appointment* appointmentToCancel = nullptr;
    for (const auto& appointment : appoints) {
        if (appointment->getTime() == timeSlot) {
            appointmentToCancel = appointment;
            break;
        }
    }

    if (appointmentToCancel) {
        data->deleteAppointment(appointmentToCancel->getId());
        displayAppointments(date.toString("yyyy/MM/dd"));
        QMessageBox::information(this, "Success", "Appointment canceled successfully.");
    } else {
        QMessageBox::warning(this, "Error", "No appointment found to cancel for the selected time slot.");
    }
}

