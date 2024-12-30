/********************************************************************************
** Form generated from reading UI file 'AddPatientDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPATIENTDIALOG_H
#define UI_ADDPATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddPatientDialog
{
public:
    QLineEdit *nameEdit;
    QComboBox *sexEdit;
    QLineEdit *ohipEdit;
    QLineEdit *addressEdit;
    QLineEdit *emailEdit;
    QPushButton *submit;
    QPushButton *cancel;
    QDateEdit *dateEdit;
    QLabel *label;

    void setupUi(QDialog *AddPatientDialog)
    {
        if (AddPatientDialog->objectName().isEmpty())
            AddPatientDialog->setObjectName("AddPatientDialog");
        AddPatientDialog->resize(400, 300);
        nameEdit = new QLineEdit(AddPatientDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(10, 10, 341, 24));
        sexEdit = new QComboBox(AddPatientDialog);
        sexEdit->addItem(QString());
        sexEdit->addItem(QString());
        sexEdit->setObjectName("sexEdit");
        sexEdit->setGeometry(QRect(10, 90, 72, 24));
        ohipEdit = new QLineEdit(AddPatientDialog);
        ohipEdit->setObjectName("ohipEdit");
        ohipEdit->setGeometry(QRect(10, 130, 341, 24));
        addressEdit = new QLineEdit(AddPatientDialog);
        addressEdit->setObjectName("addressEdit");
        addressEdit->setGeometry(QRect(10, 170, 341, 24));
        emailEdit = new QLineEdit(AddPatientDialog);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setGeometry(QRect(10, 210, 341, 24));
        submit = new QPushButton(AddPatientDialog);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(10, 260, 75, 24));
        cancel = new QPushButton(AddPatientDialog);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(100, 260, 75, 24));
        dateEdit = new QDateEdit(AddPatientDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(10, 50, 110, 25));
        dateEdit->setCalendarPopup(true);
        label = new QLabel(AddPatientDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 50, 71, 21));

        retranslateUi(AddPatientDialog);

        QMetaObject::connectSlotsByName(AddPatientDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPatientDialog)
    {
        AddPatientDialog->setWindowTitle(QCoreApplication::translate("AddPatientDialog", "AddPatientDialog", nullptr));
        nameEdit->setText(QString());
        sexEdit->setItemText(0, QCoreApplication::translate("AddPatientDialog", "M", nullptr));
        sexEdit->setItemText(1, QCoreApplication::translate("AddPatientDialog", "F", nullptr));

        submit->setText(QCoreApplication::translate("AddPatientDialog", "Submit", nullptr));
        cancel->setText(QCoreApplication::translate("AddPatientDialog", "Cancel", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("AddPatientDialog", "yyyy/MM/dd", nullptr));
        label->setText(QCoreApplication::translate("AddPatientDialog", "Date of Birth", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPatientDialog: public Ui_AddPatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATIENTDIALOG_H
