#ifndef ADDAPPOINTMENTDIALOG_H
#define ADDAPPOINTMENTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include "Appointment.h"
#include "Singleton.h"
#include "Patient.h"

namespace Ui {
class AddAppointmentDialog;
}

class AddAppointmentDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddAppointmentDialog(QWidget *parent = nullptr, Appointment* existingAppointment = nullptr, const QString& ohip = QString());
    ~AddAppointmentDialog();

    QString getDate() const;
    QString getTime() const;
    bool getFlu() const;
    bool getNew() const;
    QString getPatientType() const;
    QString getOhip() const; // Added getter for OHIP

private:
    Ui::AddAppointmentDialog *ui;
    Appointment* appointment;
    Singleton* data;

    void onSubmitClicked();
    void onCancelClicked();

    bool verifyOhip(const QString& ohip) const; // Added OHIP verification method
    bool verifyUnique() const;
};

#endif // ADDAPPOINTMENTDIALOG_H
