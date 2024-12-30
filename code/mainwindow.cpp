#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PatientWindow.h"
#include "AppointmentWindow.h"
#include "Settings.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    data = Singleton::getInstance();
    // Connect button to openPatientWindow
    connect(ui->PButton, &QPushButton::clicked, this, &MainWindow::openPatientWindow);
    connect(ui->AButton, &QPushButton::clicked, this, &MainWindow::openAppointmentWindow);
    connect(ui->SButton, &QPushButton::clicked, this, &MainWindow::openSettings);
    connect(ui->LButton, &QPushButton::clicked, this, &MainWindow::login);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openPatientWindow() {
    if (data->currentUser != nullptr) {
        PatientWindow* patientWindow = new PatientWindow();
        patientWindow->setAttribute(Qt::WA_DeleteOnClose);
        patientWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Not Logged in", "Please log in to your account");
    }
}

void MainWindow::openSettings() {
    if (data->currentUser != nullptr) {
        if (data->currentUser->getRole() == "Admin") {
            Settings* settings = new Settings();
            settings->setAttribute(Qt::WA_DeleteOnClose);
            settings->show();
            this->close();
        } else {
            QMessageBox::warning(this, "Restricted", "Must be an admin to access system settings");
        }
    } else {
        QMessageBox::warning(this, "Not Logged in", "Please log in to your account");
    }
}

void MainWindow::openAppointmentWindow() {
    if (data->currentUser != nullptr) {
        AppointmentWindow* appointmentWindow = new AppointmentWindow();
        appointmentWindow->setAttribute(Qt::WA_DeleteOnClose);
        appointmentWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Not Logged in", "Please log in to your account");
    }
}

void MainWindow::login() {
    QString username = ui->username->text();
    QString password = ui->password->text();

    if (data->login(username, password)) {
        QMessageBox::information(this, "Login Successful", "Welcome " + username);
        ui->username->clear();
        ui->password->clear();
    } else {
        QMessageBox::warning(this, "Login Failed", "Username or password was incorrect");
    }
}

