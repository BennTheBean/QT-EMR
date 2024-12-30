#include "AddInjectionDialog.h"
#include "qregularexpression.h"
#include "ui_AddInjectionDialog.h"

AddInjectionDialog::AddInjectionDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddInjectionDialog) {
    ui->setupUi(this);
    ui->typeEdit->setPlaceholderText("Injection Type...");
    ui->dateEdit->setDate(QDate::fromString(QDate::currentDate().toString("yyyy/MM/dd"), "yyyy/MM/dd"));
    connect(ui->submit, &QPushButton::clicked, this, &AddInjectionDialog::onSubmitClicked);
    connect(ui->cancel, &QPushButton::clicked, this, &AddInjectionDialog::onCancelClicked);
}

void AddInjectionDialog::onSubmitClicked() {
    // Validate Name: nonempty, only letters
    QRegularExpression typeRegex("^[a-zA-Z\\s]+$");
    if (!typeRegex.match(ui->typeEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Invalid Input", "Type must be nonempty and contain only letters.");
        return;
    }
    // If all validations pass, accept the dialog
    accept();
}

void AddInjectionDialog::onCancelClicked() {
    // Reject the dialog to indicate cancellation
    reject();
}

AddInjectionDialog::~AddInjectionDialog() {
    delete ui;
}

QString AddInjectionDialog::getType() const {
    return ui->typeEdit->text();
}

QString AddInjectionDialog::getDate() const {
    return ui->dateEdit->text();
}
