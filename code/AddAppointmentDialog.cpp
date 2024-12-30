#include "AddAppointmentDialog.h"
#include "ui_AddAppointmentDialog.h"

AddAppointmentDialog::AddAppointmentDialog(QWidget *parent, Appointment* existingAppointment, const QString& ohip)
    : QDialog(parent), ui(new Ui::AddAppointmentDialog), appointment(existingAppointment) {
    ui->setupUi(this);

    data = Singleton::getInstance();
    if (appointment) {
        ui->dateEdit->setDate(QDate::fromString(appointment->getDate(), "yyyy/MM/dd"));
        ui->timeEdit->setTime(QTime::fromString(appointment->getTime(), "hh:mm"));

        setWindowTitle("Edit Appointment");
        ui->submit->setText("Update");
    } else {
        setWindowTitle("Add Appointment");
        ui->dateEdit->setDate(QDate::fromString(QDate::currentDate().toString("yyyy/MM/dd"), "yyyy/MM/dd"));
        ui->submit->setText("Save");
    }

    if (!ohip.isEmpty()) {
        // If OHIP is provided, set it and make the field read-only
        ui->ohipEdit->setText(ohip);
        ui->ohipEdit->setReadOnly(true);
    } else {
        // Allow the user to input OHIP if not provided
        ui->ohipEdit->setPlaceholderText("Enter OHIP...");
    }

    connect(ui->submit, &QPushButton::clicked, this, &AddAppointmentDialog::onSubmitClicked);
    connect(ui->cancel, &QPushButton::clicked, this, &AddAppointmentDialog::onCancelClicked);
}

void AddAppointmentDialog::onSubmitClicked() {
    // Pseudocode for verifying the OHIP input if it's user-provided

    QTime appointmentTime = ui->timeEdit->time();
    int minutes = appointmentTime.minute();

    if (minutes != 0 && minutes != 30) {
        QMessageBox::warning(this, "Invalid Time", "Appointment time must end in :00 or :30.");
        return;
    }

    if (ui->ohipEdit->isReadOnly() == false) {
        QString ohipInput = ui->ohipEdit->text();
        if (!verifyOhip(ohipInput)) {  // Replace with actual verification logic
            QMessageBox::warning(this, "Invalid OHIP", "Please enter a valid OHIP number.");
            return;
        }
    }

    if (!verifyUnique()) {  // Replace with actual verification logic
        QMessageBox::warning(this, "Invalid Time", "This time is already booked.");
        return;
    }
    accept();
}

void AddAppointmentDialog::onCancelClicked() {
    reject();
}

AddAppointmentDialog::~AddAppointmentDialog() {
    delete ui;
}

QString AddAppointmentDialog::getDate() const {
    return ui->dateEdit->text();
}

QString AddAppointmentDialog::getTime() const {
    return ui->timeEdit->text();
}

bool AddAppointmentDialog::getFlu() const {
    return ui->fluEdit->isChecked();
}

bool AddAppointmentDialog::getNew() const {
    return ui->newEdit->isChecked();
}

QString AddAppointmentDialog::getOhip() const {
    return ui->ohipEdit->text();
}

// Pseudocode function for OHIP validation
bool AddAppointmentDialog::verifyOhip(const QString& ohip) const {
    Singleton* singleton = Singleton::getInstance();
    Patient* patient = singleton->searchPatientOHIP(ohip);

    if (patient == nullptr) {
        return false;
    }

    delete patient; // Clean up dynamically created patient object
    return true;
}

bool AddAppointmentDialog::verifyUnique() const {
    std::vector<Appointment*> appoints = data->AppointmentsForDay(ui->dateEdit->text());

    for (const auto& appoint : appoints) {
        if (appoint->getTime() == ui->timeEdit->text() && (appointment == nullptr || appointment->getId() != appoint->getId())) {
            return false;
        }
    }
    return true;
}
