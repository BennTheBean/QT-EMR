#include "AddPatientDialog.h"
#include "ui_AddPatientDialog.h"

AddPatientDialog::AddPatientDialog(QWidget* parent, Patient* existingPatient)
    : patient(existingPatient), QDialog(parent), ui(new Ui::AddPatientDialog) {
    ui->setupUi(this);

    if (patient) {
        ui->nameEdit->setText(patient->getName());
        ui->dateEdit->setDate(QDate::fromString(patient->getDOB(), "yyyy/MM/dd"));
        ui->sexEdit->setCurrentText(patient->getSex());
        ui->emailEdit->setText(patient->getEmail());
        ui->addressEdit->setText(patient->getAddress());
        ui->ohipEdit->setText(patient->getOHIP());
        ui->ohipEdit->setDisabled(true);

        // Update UI labels
        setWindowTitle("Edit Patient");
        ui->submit->setText("Update");
    } else {
        ui->nameEdit->setPlaceholderText("Name...");
        ui->emailEdit->setPlaceholderText("Email...");
        ui->addressEdit->setPlaceholderText("Address...");
        ui->ohipEdit->setPlaceholderText("OHIP...");

        setWindowTitle("Add Patient");
        ui->submit->setText("Save");
    }

    connect(ui->submit, &QPushButton::clicked, this, &AddPatientDialog::onSubmitClicked);
    connect(ui->cancel, &QPushButton::clicked, this, &AddPatientDialog::onCancelClicked);
}

void AddPatientDialog::onSubmitClicked() {
    // Validate Name: nonempty, only letters
    QRegularExpression nameRegex("^[a-zA-Z\\s]+$");
    if (!nameRegex.match(ui->nameEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Invalid Input", "Name must be nonempty and contain only letters.");
        return;
    }

    // Validate OHIP: 10 digits followed by 2 capital letters
    QRegularExpression ohipRegex("^\\d{10}[A-Z]{2}$");
    if (!ohipRegex.match(ui->ohipEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Invalid Input", "OHIP must be a 10-digit number followed by 2 capital letters.");
        return;
    }

    // Validate Email: contains @ and a .
    QRegularExpression emailRegex("^[\\w._%+-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(ui->emailEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Invalid Input", "Email must be a valid email address.");
        return;
    }

    // Validate Address: letters followed by numbers followed by letters
    QRegularExpression addressRegex("^\\d+\\s+[a-zA-Z\\s]+$");
    if (!addressRegex.match(ui->addressEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Invalid Input", "Address must be nonempty and be valid.");
        return;
    }

    // If all validations pass, accept the dialog
    accept();
}

void AddPatientDialog::onCancelClicked() {
    // Reject the dialog to indicate cancellation
    reject();
}

AddPatientDialog::~AddPatientDialog() {
    delete ui;
}

QString AddPatientDialog::getName() const {
    return ui->nameEdit->text();
}

QString AddPatientDialog::getDOB() const {
    return ui->dateEdit->text();
}

QString AddPatientDialog::getSex() const {
    return ui->sexEdit->currentText();
}

QString AddPatientDialog::getEmail() const {
    return ui->emailEdit->text();
}

QString AddPatientDialog::getAddress() const {
    return ui->addressEdit->text();
}

QString AddPatientDialog::getOHIP() const {
    return ui->ohipEdit->text();
}
