#ifndef ADDPATIENTDIALOG_H
#define ADDPATIENTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include "Patient.h"

namespace Ui {
class AddPatientDialog;
}

class AddPatientDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddPatientDialog(QWidget *parent = nullptr, Patient* existingPatient = nullptr);
    ~AddPatientDialog();

    QString getName() const;
    QString getDOB() const;
    QString getSex() const;
    QString getEmail() const;
    QString getAddress() const;
    QString getOHIP() const;

private:
    Ui::AddPatientDialog *ui;
    Patient* patient;
    void onSubmitClicked();
    void onCancelClicked();
};

#endif // ADDPATIENTDIALOG_H
