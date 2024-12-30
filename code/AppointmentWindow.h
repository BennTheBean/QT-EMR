#ifndef APPOINTMENTWINDOW_H
#define APPOINTMENTWINDOW_H

#include <QMainWindow>
#include "Appointment.h"
#include "qdatetime.h"
#include "Singleton.h"

namespace Ui {
class AppointmentWindow;
}

class AppointmentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppointmentWindow(QWidget *parent = nullptr);
    ~AppointmentWindow();

private:
    std::vector<Appointment*> appoints;
    QDate date;
    Singleton* data;
    Ui::AppointmentWindow *ui;
    void openHomeWindow();
    void openPatientWindow();
    void openSettings();

    void displayAppointments(const QString& date);
    void addNewAppointment();
    void editAppointment();
    void cancelAppointment();
};

#endif // APPOINTMENTWINDOW_H
