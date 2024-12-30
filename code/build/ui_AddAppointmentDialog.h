/********************************************************************************
** Form generated from reading UI file 'AddAppointmentDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDAPPOINTMENTDIALOG_H
#define UI_ADDAPPOINTMENTDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AddAppointmentDialog
{
public:
    QPushButton *submit;
    QPushButton *cancel;
    QCheckBox *fluEdit;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QCheckBox *newEdit;
    QLineEdit *ohipEdit;

    void setupUi(QDialog *AddAppointmentDialog)
    {
        if (AddAppointmentDialog->objectName().isEmpty())
            AddAppointmentDialog->setObjectName("AddAppointmentDialog");
        AddAppointmentDialog->resize(360, 102);
        submit = new QPushButton(AddAppointmentDialog);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(10, 70, 75, 24));
        cancel = new QPushButton(AddAppointmentDialog);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(100, 70, 75, 24));
        fluEdit = new QCheckBox(AddAppointmentDialog);
        fluEdit->setObjectName("fluEdit");
        fluEdit->setGeometry(QRect(120, 10, 76, 20));
        dateEdit = new QDateEdit(AddAppointmentDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(10, 10, 91, 25));
        dateEdit->setMinimumDateTime(QDateTime(QDate(2024, 12, 15), QTime(0, 0, 0)));
        dateEdit->setMinimumDate(QDate(2024, 12, 15));
        dateEdit->setMaximumTime(QTime(23, 59, 59));
        dateEdit->setCurrentSection(QDateTimeEdit::Section::YearSection);
        dateEdit->setCalendarPopup(true);
        timeEdit = new QTimeEdit(AddAppointmentDialog);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(10, 40, 118, 22));
        timeEdit->setMaximumTime(QTime(15, 59, 59));
        timeEdit->setMinimumTime(QTime(9, 0, 0));
        timeEdit->setTimeSpec(Qt::TimeSpec::UTC);
        timeEdit->setTime(QTime(9, 0, 0));
        newEdit = new QCheckBox(AddAppointmentDialog);
        newEdit->setObjectName("newEdit");
        newEdit->setGeometry(QRect(190, 10, 91, 20));
        ohipEdit = new QLineEdit(AddAppointmentDialog);
        ohipEdit->setObjectName("ohipEdit");
        ohipEdit->setGeometry(QRect(140, 40, 121, 24));

        retranslateUi(AddAppointmentDialog);

        QMetaObject::connectSlotsByName(AddAppointmentDialog);
    } // setupUi

    void retranslateUi(QDialog *AddAppointmentDialog)
    {
        AddAppointmentDialog->setWindowTitle(QCoreApplication::translate("AddAppointmentDialog", "AddAppointmentDialog", nullptr));
        submit->setText(QCoreApplication::translate("AddAppointmentDialog", "Submit", nullptr));
        cancel->setText(QCoreApplication::translate("AddAppointmentDialog", "Cancel", nullptr));
        fluEdit->setText(QCoreApplication::translate("AddAppointmentDialog", "Injection", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("AddAppointmentDialog", "yyyy/MM/dd", nullptr));
        newEdit->setText(QCoreApplication::translate("AddAppointmentDialog", "New Patient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddAppointmentDialog: public Ui_AddAppointmentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDAPPOINTMENTDIALOG_H
