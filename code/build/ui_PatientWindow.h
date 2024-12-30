/********************************************************************************
** Form generated from reading UI file 'PatientWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTWINDOW_H
#define UI_PATIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientWindow
{
public:
    QWidget *centralwidget;
    QLabel *title;
    QFrame *verticalFrame_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *Tabs;
    QPushButton *HButton;
    QPushButton *PButton;
    QPushButton *AButton;
    QSpacerItem *verticalSpacer;
    QPushButton *SButton;
    QPushButton *search;
    QLineEdit *OHIP;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *addPatient;
    QPushButton *addInjection;
    QPushButton *addAppoint;
    QLabel *label_4;
    QPushButton *editPatient;
    QListWidget *appoint;
    QPushButton *editAppoint;
    QPushButton *cancel;
    QPushButton *addFile;
    QLabel *label_5;
    QPushButton *openFile;
    QPushButton *delete_2;
    QListWidget *files;
    QListWidget *shots;
    QListWidget *demo;

    void setupUi(QMainWindow *PatientWindow)
    {
        if (PatientWindow->objectName().isEmpty())
            PatientWindow->setObjectName("PatientWindow");
        PatientWindow->resize(960, 541);
        centralwidget = new QWidget(PatientWindow);
        centralwidget->setObjectName("centralwidget");
        title = new QLabel(centralwidget);
        title->setObjectName("title");
        title->setGeometry(QRect(210, -10, 771, 41));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        title->setBaseSize(QSize(300, 20));
        title->setStyleSheet(QString::fromUtf8("background-color: rgb(14, 10, 25);\n"
"color: rgb(232, 223, 224);"));
        title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        title->setWordWrap(true);
        verticalFrame_3 = new QFrame(centralwidget);
        verticalFrame_3->setObjectName("verticalFrame_3");
        verticalFrame_3->setGeometry(QRect(0, 0, 220, 541));
        verticalFrame_3->setMinimumSize(QSize(220, 400));
        verticalFrame_3->setMaximumSize(QSize(220, 600));
        verticalFrame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(14, 10, 25);"));
        verticalLayout_3 = new QVBoxLayout(verticalFrame_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        Tabs = new QVBoxLayout();
        Tabs->setObjectName("Tabs");
        HButton = new QPushButton(verticalFrame_3);
        HButton->setObjectName("HButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(HButton->sizePolicy().hasHeightForWidth());
        HButton->setSizePolicy(sizePolicy1);
        HButton->setMinimumSize(QSize(200, 20));
        HButton->setMaximumSize(QSize(200, 25));
        HButton->setBaseSize(QSize(200, 20));
        HButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 23, 246);\n"
"color: rgb(232, 223, 224);"));

        Tabs->addWidget(HButton);

        PButton = new QPushButton(verticalFrame_3);
        PButton->setObjectName("PButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PButton->sizePolicy().hasHeightForWidth());
        PButton->setSizePolicy(sizePolicy2);
        PButton->setMinimumSize(QSize(200, 20));
        PButton->setMaximumSize(QSize(200, 25));
        PButton->setBaseSize(QSize(200, 20));
        PButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 23, 246);\n"
"color: rgb(232, 223, 224);"));

        Tabs->addWidget(PButton);

        AButton = new QPushButton(verticalFrame_3);
        AButton->setObjectName("AButton");
        sizePolicy2.setHeightForWidth(AButton->sizePolicy().hasHeightForWidth());
        AButton->setSizePolicy(sizePolicy2);
        AButton->setMinimumSize(QSize(200, 20));
        AButton->setMaximumSize(QSize(200, 25));
        AButton->setBaseSize(QSize(200, 20));
        AButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 23, 246);\n"
"color: rgb(232, 223, 224);"));

        Tabs->addWidget(AButton);


        verticalLayout_3->addLayout(Tabs);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        SButton = new QPushButton(verticalFrame_3);
        SButton->setObjectName("SButton");
        sizePolicy2.setHeightForWidth(SButton->sizePolicy().hasHeightForWidth());
        SButton->setSizePolicy(sizePolicy2);
        SButton->setMinimumSize(QSize(200, 20));
        SButton->setMaximumSize(QSize(200, 25));
        SButton->setBaseSize(QSize(200, 20));
        SButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 23, 246);\n"
"color: rgb(232, 223, 224);"));

        verticalLayout_3->addWidget(SButton);

        search = new QPushButton(centralwidget);
        search->setObjectName("search");
        search->setGeometry(QRect(610, 470, 101, 24));
        OHIP = new QLineEdit(centralwidget);
        OHIP->setObjectName("OHIP");
        OHIP->setGeometry(QRect(240, 470, 351, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 450, 71, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 40, 111, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(590, 40, 111, 16));
        addPatient = new QPushButton(centralwidget);
        addPatient->setObjectName("addPatient");
        addPatient->setGeometry(QRect(250, 180, 80, 24));
        addInjection = new QPushButton(centralwidget);
        addInjection->setObjectName("addInjection");
        addInjection->setGeometry(QRect(590, 180, 101, 24));
        addAppoint = new QPushButton(centralwidget);
        addAppoint->setObjectName("addAppoint");
        addAppoint->setGeometry(QRect(250, 360, 111, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(250, 220, 111, 16));
        editPatient = new QPushButton(centralwidget);
        editPatient->setObjectName("editPatient");
        editPatient->setGeometry(QRect(340, 180, 80, 24));
        appoint = new QListWidget(centralwidget);
        appoint->setObjectName("appoint");
        appoint->setGeometry(QRect(250, 240, 321, 111));
        editAppoint = new QPushButton(centralwidget);
        editAppoint->setObjectName("editAppoint");
        editAppoint->setGeometry(QRect(370, 360, 111, 24));
        cancel = new QPushButton(centralwidget);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(490, 360, 61, 24));
        addFile = new QPushButton(centralwidget);
        addFile->setObjectName("addFile");
        addFile->setGeometry(QRect(590, 360, 61, 24));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(590, 220, 111, 16));
        openFile = new QPushButton(centralwidget);
        openFile->setObjectName("openFile");
        openFile->setGeometry(QRect(660, 360, 61, 24));
        delete_2 = new QPushButton(centralwidget);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(730, 360, 61, 24));
        files = new QListWidget(centralwidget);
        files->setObjectName("files");
        files->setGeometry(QRect(590, 240, 321, 111));
        shots = new QListWidget(centralwidget);
        shots->setObjectName("shots");
        shots->setGeometry(QRect(590, 60, 321, 111));
        demo = new QListWidget(centralwidget);
        demo->setObjectName("demo");
        demo->setGeometry(QRect(250, 60, 321, 111));
        PatientWindow->setCentralWidget(centralwidget);

        retranslateUi(PatientWindow);

        QMetaObject::connectSlotsByName(PatientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PatientWindow)
    {
        PatientWindow->setWindowTitle(QCoreApplication::translate("PatientWindow", "PatientWindow", nullptr));
        title->setText(QCoreApplication::translate("PatientWindow", "Patients", nullptr));
        HButton->setText(QCoreApplication::translate("PatientWindow", "Home", nullptr));
        PButton->setText(QCoreApplication::translate("PatientWindow", "Patients", nullptr));
        AButton->setText(QCoreApplication::translate("PatientWindow", "Appointments", nullptr));
        SButton->setText(QCoreApplication::translate("PatientWindow", "Appointments", nullptr));
        search->setText(QCoreApplication::translate("PatientWindow", "Search Patients", nullptr));
        label->setText(QCoreApplication::translate("PatientWindow", "Enter OHIP:", nullptr));
        label_2->setText(QCoreApplication::translate("PatientWindow", "Patient Data:", nullptr));
        label_3->setText(QCoreApplication::translate("PatientWindow", "Injection History:", nullptr));
        addPatient->setText(QCoreApplication::translate("PatientWindow", "New Patient", nullptr));
        addInjection->setText(QCoreApplication::translate("PatientWindow", "Add Injection", nullptr));
        addAppoint->setText(QCoreApplication::translate("PatientWindow", "New Appointment", nullptr));
        label_4->setText(QCoreApplication::translate("PatientWindow", "Appointments:", nullptr));
        editPatient->setText(QCoreApplication::translate("PatientWindow", "Edit Patient", nullptr));
        editAppoint->setText(QCoreApplication::translate("PatientWindow", "Edit Appointment", nullptr));
        cancel->setText(QCoreApplication::translate("PatientWindow", "Cancel", nullptr));
        addFile->setText(QCoreApplication::translate("PatientWindow", "New File", nullptr));
        label_5->setText(QCoreApplication::translate("PatientWindow", "Files:", nullptr));
        openFile->setText(QCoreApplication::translate("PatientWindow", "Open File", nullptr));
        delete_2->setText(QCoreApplication::translate("PatientWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientWindow: public Ui_PatientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTWINDOW_H
