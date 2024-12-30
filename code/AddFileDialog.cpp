#include "AddFileDialog.h"
#include "qregularexpression.h"
#include "ui_AddFileDialog.h"

AddFileDialog::AddFileDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddFileDialog) {
    ui->setupUi(this);
    ui->dataEdit->setPlaceholderText("Request Type...");

    connect(ui->submit, &QPushButton::clicked, this, &AddFileDialog::onSubmitClicked);
    connect(ui->cancel, &QPushButton::clicked, this, &AddFileDialog::onCancelClicked);
}

void AddFileDialog::onSubmitClicked() {
    // Validate Name: nonempty, only letters
    QRegularExpression typeRegex("^[a-zA-Z\\s]+$");
    if (ui->fileEdit->currentText() != "Immunization Record" && !typeRegex.match(ui->dataEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Invalid Input", "Type must be nonempty and contain only letters.");
        return;
    }

    if (ui->fileEdit->currentText() == "Immunization Record" && ui->dataEdit->text() != "") {
        QMessageBox::warning(this, "Invalid Input", "Immunization Record cannot have a type specified");
        return;
    }
    // If all validations pass, accept the dialog
    accept();
}

void AddFileDialog::onCancelClicked() {
    // Reject the dialog to indicate cancellation
    reject();
}

AddFileDialog::~AddFileDialog() {
    delete ui;
}

QString AddFileDialog::getFile() const {
    return ui->fileEdit->currentText();
}

QString AddFileDialog::getData() const {
    return ui->dataEdit->text();
}

QString AddFileDialog::getDate() const {
    return QDate::currentDate().toString("yyyy/MM/dd");
}
