/********************************************************************************
** Form generated from reading UI file 'AppointmentWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTWINDOW_H
#define UI_APPOINTMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppointmentWindow
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
    QTableWidget *appointments;
    QDateEdit *date;
    QPushButton *add;
    QPushButton *edit;
    QPushButton *cancel;

    void setupUi(QMainWindow *AppointmentWindow)
    {
        if (AppointmentWindow->objectName().isEmpty())
            AppointmentWindow->setObjectName("AppointmentWindow");
        AppointmentWindow->resize(936, 541);
        centralwidget = new QWidget(AppointmentWindow);
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
        verticalFrame_3->setMinimumSize(QSize(220, 200));
        verticalFrame_3->setMaximumSize(QSize(220, 700));
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

        appointments = new QTableWidget(centralwidget);
        if (appointments->columnCount() < 5)
            appointments->setColumnCount(5);
        appointments->setObjectName("appointments");
        appointments->setGeometry(QRect(220, 70, 721, 471));
        appointments->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        appointments->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        appointments->setAlternatingRowColors(true);
        appointments->setWordWrap(false);
        appointments->setColumnCount(5);
        appointments->horizontalHeader()->setVisible(false);
        appointments->verticalHeader()->setHighlightSections(false);
        date = new QDateEdit(centralwidget);
        date->setObjectName("date");
        date->setGeometry(QRect(230, 40, 110, 22));
        date->setCurrentSection(QDateTimeEdit::Section::YearSection);
        date->setCalendarPopup(true);
        add = new QPushButton(centralwidget);
        add->setObjectName("add");
        add->setGeometry(QRect(350, 40, 111, 24));
        edit = new QPushButton(centralwidget);
        edit->setObjectName("edit");
        edit->setGeometry(QRect(470, 40, 111, 24));
        cancel = new QPushButton(centralwidget);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(590, 40, 121, 24));
        AppointmentWindow->setCentralWidget(centralwidget);

        retranslateUi(AppointmentWindow);

        QMetaObject::connectSlotsByName(AppointmentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AppointmentWindow)
    {
        AppointmentWindow->setWindowTitle(QCoreApplication::translate("AppointmentWindow", "AppointmentWindow", nullptr));
        title->setText(QCoreApplication::translate("AppointmentWindow", "Appointments", nullptr));
        HButton->setText(QCoreApplication::translate("AppointmentWindow", "Home", nullptr));
        PButton->setText(QCoreApplication::translate("AppointmentWindow", "Patients", nullptr));
        AButton->setText(QCoreApplication::translate("AppointmentWindow", "Appointments", nullptr));
        SButton->setText(QCoreApplication::translate("AppointmentWindow", "System Settings", nullptr));
        date->setDisplayFormat(QCoreApplication::translate("AppointmentWindow", "yyyy/MM/dd", nullptr));
        add->setText(QCoreApplication::translate("AppointmentWindow", "Add Appointment", nullptr));
        edit->setText(QCoreApplication::translate("AppointmentWindow", "Edit Appointment", nullptr));
        cancel->setText(QCoreApplication::translate("AppointmentWindow", "Cancel Appointment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppointmentWindow: public Ui_AppointmentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTWINDOW_H
