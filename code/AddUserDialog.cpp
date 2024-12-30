#include "AddUserDialog.h"
#include "ui_AddUserDialog.h"

AddUserDialog::AddUserDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddUserDialog)
{
    ui->setupUi(this);
    ui->nameEdit->setPlaceholderText("Name...");
    ui->passEdit->setPlaceholderText("Password...");
    connect(ui->submit, &QPushButton::clicked, this, &AddUserDialog::onSubmitClicked);
    connect(ui->cancel, &QPushButton::clicked, this, &AddUserDialog::onCancelClicked);
}

AddUserDialog::~AddUserDialog()
{
    delete ui;
}

void AddUserDialog::onSubmitClicked() {
    QString password = ui->passEdit->text();
    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    if (!passwordRegex.match(ui->passEdit->text()).hasMatch()) {
        QMessageBox::warning(this, "Invalid Password",
                             "Passwords must be at least 8 characters long and include at least:\n"
                             "- One uppercase letter\n"
                             "- One lowercase letter\n"
                             "- One number\n"
                             "- One special character (e.g., @$!%*?&).");
        return;
    }

    if (!verifyUnique()) {
        QMessageBox::warning(this, "Invalid Username", "Already used.");
        return;
    }
    accept();
}

void AddUserDialog::onCancelClicked() {
    reject();
}


QString AddUserDialog::getName() const {
    return ui->nameEdit->text();
}

QString AddUserDialog::getPass() const {
    return ui->passEdit->text();
}

QString AddUserDialog::getRole() const {
    return ui->roleEdit->currentText();
}


bool AddUserDialog::verifyUnique() const {
    Singleton* singleton = Singleton::getInstance();
    std::vector<User*> users = singleton->getUsers();

    for (const auto& user : users) {
        if (user->getUsername() == ui->nameEdit->text()) {
            return false;
        }
    }
    return true;
}
