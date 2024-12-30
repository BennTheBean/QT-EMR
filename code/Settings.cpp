#include "Settings.h"
#include "mainwindow.h"
#include "AppointmentWindow.h"
#include "PatientWindow.h"
#include "ui_Settings.h"
#include "AddUserDialog.h"

Settings::Settings(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Settings)
{
    data = Singleton::getInstance();
    ui->setupUi(this);
    connect(ui->HButton, &QPushButton::clicked, this, &Settings::openHomeWindow);
    connect(ui->PButton, &QPushButton::clicked, this, &Settings::openPatientWindow);
    connect(ui->AButton, &QPushButton::clicked, this, &Settings::openAppointmentWindow);
    connect(ui->deleteU, &QPushButton::clicked, this, &Settings::deleteUser);
    connect(ui->add, &QPushButton::clicked, this, &Settings::addUser);

    displayUsers();
}

Settings::~Settings()
{
    delete ui;
}

void Settings::displayUsers() {
    users = data->getUsers();
    ui->list->clear(); // Clear the UI list

    for (size_t i = 0; i < users.size(); ++i) {
        const auto& user = users[i];
        QListWidgetItem* item = new QListWidgetItem(
            "Username: " + user->getUsername() + "\n"
            "Password: " + user->getPassword() + "\n"
            "Role: " + user->getRole() + "\n"
            );
        item->setData(Qt::UserRole, static_cast<int>(i)); // Store the index
        ui->list->addItem(item);
    }
}

void Settings::openPatientWindow() {
    PatientWindow* patientWindow = new PatientWindow();
    patientWindow->setAttribute(Qt::WA_DeleteOnClose); // Ensures it cleans up properly
    patientWindow->show();
    this->close();
}

void Settings::openHomeWindow() {
    MainWindow* mainWindow = new MainWindow();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose);
    mainWindow->show();
    this->close();
}

void Settings::openAppointmentWindow() {
    AppointmentWindow* appointmentWindow = new AppointmentWindow();
    appointmentWindow->setAttribute(Qt::WA_DeleteOnClose);
    appointmentWindow->show();
    this->close();
}

void Settings::addUser() {
    AddUserDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        data->createUser(dialog.getName(), dialog.getPass(), dialog.getRole());
        displayUsers();
        QMessageBox::information(this, "Success", "User added successfully.");
    }
}

void Settings::deleteUser() {
    QListWidgetItem* selectedItem = ui->list->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "No user Selected", "Please select a user to delete.");
        return;
    }
    int index = selectedItem->data(Qt::UserRole).toInt();
    data->deleteUser(users[index]->getUsername());
    displayUsers();
    QMessageBox::information(this, "Success", "User deleted.");
}
