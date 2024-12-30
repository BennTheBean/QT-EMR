#ifndef PATIENTWINDOW_H
#define PATIENTWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDialog>
#include "Singleton.h"

namespace Ui {
class PatientWindow;
}

class PatientWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit PatientWindow(QWidget *parent = nullptr);
    ~PatientWindow();

private:
    Ui::PatientWindow* ui;
    Singleton* data;
    Patient* patient = nullptr;
    std::vector<Appointment*> appoints;
    std::vector<MedicalFile*> files;
    std::vector<Injection*> injections;

    void openHomeWindow();
    void openAppointmentWindow();
    void openSettings();

    void Print();
    void cancel();
    void deleteFile();
    void openFile();

    void addNewPatient();
    void editPatient();
    void addNewInjection();
    void addNewFile();
    void addNewAppointment();
    void editAppointment();

    void SearchPatient();

    void displayPatient();
    void displayInjections();
    void displayAppointments();
    void displayFiles();
};


#endif // PATIENTWINDOW_H
