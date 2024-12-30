/********************************************************************************
** Form generated from reading UI file 'AddInjectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINJECTIONDIALOG_H
#define UI_ADDINJECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddInjectionDialog
{
public:
    QLineEdit *typeEdit;
    QPushButton *submit;
    QPushButton *cancel;
    QDateEdit *dateEdit;
    QLabel *label;

    void setupUi(QDialog *AddInjectionDialog)
    {
        if (AddInjectionDialog->objectName().isEmpty())
            AddInjectionDialog->setObjectName("AddInjectionDialog");
        AddInjectionDialog->resize(400, 137);
        typeEdit = new QLineEdit(AddInjectionDialog);
        typeEdit->setObjectName("typeEdit");
        typeEdit->setGeometry(QRect(10, 10, 341, 24));
        submit = new QPushButton(AddInjectionDialog);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(10, 100, 75, 24));
        cancel = new QPushButton(AddInjectionDialog);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(100, 100, 75, 24));
        dateEdit = new QDateEdit(AddInjectionDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(10, 50, 110, 25));
        dateEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(19, 0, 0)));
        dateEdit->setCalendarPopup(true);
        dateEdit->setTimeSpec(Qt::TimeSpec::LocalTime);
        label = new QLabel(AddInjectionDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 50, 121, 21));

        retranslateUi(AddInjectionDialog);

        QMetaObject::connectSlotsByName(AddInjectionDialog);
    } // setupUi

    void retranslateUi(QDialog *AddInjectionDialog)
    {
        AddInjectionDialog->setWindowTitle(QCoreApplication::translate("AddInjectionDialog", "AddInjectionDialog", nullptr));
        typeEdit->setText(QString());
        submit->setText(QCoreApplication::translate("AddInjectionDialog", "Submit", nullptr));
        cancel->setText(QCoreApplication::translate("AddInjectionDialog", "Cancel", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("AddInjectionDialog", "yyyy/MM/dd", nullptr));
        label->setText(QCoreApplication::translate("AddInjectionDialog", "Date Administered", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddInjectionDialog: public Ui_AddInjectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINJECTIONDIALOG_H
