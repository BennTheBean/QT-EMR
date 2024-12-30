/********************************************************************************
** Form generated from reading UI file 'AddFileDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFILEDIALOG_H
#define UI_ADDFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddFileDialog
{
public:
    QPushButton *submit;
    QPushButton *cancel;
    QComboBox *fileEdit;
    QLineEdit *dataEdit;

    void setupUi(QDialog *AddFileDialog)
    {
        if (AddFileDialog->objectName().isEmpty())
            AddFileDialog->setObjectName("AddFileDialog");
        AddFileDialog->resize(400, 137);
        submit = new QPushButton(AddFileDialog);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(10, 100, 75, 24));
        cancel = new QPushButton(AddFileDialog);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(100, 100, 75, 24));
        fileEdit = new QComboBox(AddFileDialog);
        fileEdit->addItem(QString());
        fileEdit->addItem(QString());
        fileEdit->addItem(QString());
        fileEdit->setObjectName("fileEdit");
        fileEdit->setGeometry(QRect(10, 10, 181, 24));
        dataEdit = new QLineEdit(AddFileDialog);
        dataEdit->setObjectName("dataEdit");
        dataEdit->setGeometry(QRect(10, 50, 113, 24));

        retranslateUi(AddFileDialog);

        QMetaObject::connectSlotsByName(AddFileDialog);
    } // setupUi

    void retranslateUi(QDialog *AddFileDialog)
    {
        AddFileDialog->setWindowTitle(QCoreApplication::translate("AddFileDialog", "AddFileDialog", nullptr));
        submit->setText(QCoreApplication::translate("AddFileDialog", "Submit", nullptr));
        cancel->setText(QCoreApplication::translate("AddFileDialog", "Cancel", nullptr));
        fileEdit->setItemText(0, QCoreApplication::translate("AddFileDialog", "Laboratory Requisition", nullptr));
        fileEdit->setItemText(1, QCoreApplication::translate("AddFileDialog", "Immunization Record", nullptr));
        fileEdit->setItemText(2, QCoreApplication::translate("AddFileDialog", "Prescription", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AddFileDialog: public Ui_AddFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFILEDIALOG_H
