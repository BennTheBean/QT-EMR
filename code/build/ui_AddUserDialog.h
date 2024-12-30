/********************************************************************************
** Form generated from reading UI file 'AddUserDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERDIALOG_H
#define UI_ADDUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddUserDialog
{
public:
    QPushButton *submit;
    QPushButton *cancel;
    QLineEdit *nameEdit;
    QLineEdit *passEdit;
    QComboBox *roleEdit;
    QLabel *label;

    void setupUi(QDialog *AddUserDialog)
    {
        if (AddUserDialog->objectName().isEmpty())
            AddUserDialog->setObjectName("AddUserDialog");
        AddUserDialog->resize(400, 155);
        submit = new QPushButton(AddUserDialog);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(10, 120, 75, 24));
        cancel = new QPushButton(AddUserDialog);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(100, 120, 75, 24));
        nameEdit = new QLineEdit(AddUserDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(10, 10, 341, 22));
        passEdit = new QLineEdit(AddUserDialog);
        passEdit->setObjectName("passEdit");
        passEdit->setGeometry(QRect(10, 50, 341, 22));
        roleEdit = new QComboBox(AddUserDialog);
        roleEdit->addItem(QString());
        roleEdit->addItem(QString());
        roleEdit->addItem(QString());
        roleEdit->setObjectName("roleEdit");
        roleEdit->setGeometry(QRect(10, 80, 69, 22));
        label = new QLabel(AddUserDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 80, 49, 16));

        retranslateUi(AddUserDialog);

        QMetaObject::connectSlotsByName(AddUserDialog);
    } // setupUi

    void retranslateUi(QDialog *AddUserDialog)
    {
        AddUserDialog->setProperty("AddUserDialog", QVariant(QCoreApplication::translate("AddUserDialog", "Dialog", nullptr)));
        submit->setText(QCoreApplication::translate("AddUserDialog", "Submit", nullptr));
        cancel->setText(QCoreApplication::translate("AddUserDialog", "Cancel", nullptr));
        roleEdit->setItemText(0, QCoreApplication::translate("AddUserDialog", "Admin", nullptr));
        roleEdit->setItemText(1, QCoreApplication::translate("AddUserDialog", "Receptionist", nullptr));
        roleEdit->setItemText(2, QCoreApplication::translate("AddUserDialog", "Doctor", nullptr));

        label->setText(QCoreApplication::translate("AddUserDialog", "Role", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddUserDialog: public Ui_AddUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERDIALOG_H
