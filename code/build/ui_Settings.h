/********************************************************************************
** Form generated from reading UI file 'Settings.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
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
    QVBoxLayout *Misc;
    QPushButton *deleteU;
    QPushButton *add;
    QListWidget *list;

    void setupUi(QMainWindow *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(960, 541);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        Settings->setMinimumSize(QSize(960, 540));
        Settings->setMaximumSize(QSize(1920, 1080));
        centralwidget = new QWidget(Settings);
        centralwidget->setObjectName("centralwidget");
        title = new QLabel(centralwidget);
        title->setObjectName("title");
        title->setGeometry(QRect(210, -10, 771, 51));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy1);
        title->setBaseSize(QSize(300, 20));
        title->setStyleSheet(QString::fromUtf8("background-color: rgb(14, 10, 25);\n"
"color: rgb(232, 223, 224);"));
        title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        title->setWordWrap(true);
        verticalFrame_3 = new QFrame(centralwidget);
        verticalFrame_3->setObjectName("verticalFrame_3");
        verticalFrame_3->setGeometry(QRect(0, 0, 220, 540));
        verticalFrame_3->setMinimumSize(QSize(220, 540));
        verticalFrame_3->setMaximumSize(QSize(220, 1080));
        verticalFrame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(14, 10, 25);"));
        verticalLayout_3 = new QVBoxLayout(verticalFrame_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        Tabs = new QVBoxLayout();
        Tabs->setObjectName("Tabs");
        HButton = new QPushButton(verticalFrame_3);
        HButton->setObjectName("HButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(HButton->sizePolicy().hasHeightForWidth());
        HButton->setSizePolicy(sizePolicy2);
        HButton->setMinimumSize(QSize(200, 20));
        HButton->setMaximumSize(QSize(200, 25));
        HButton->setBaseSize(QSize(200, 20));
        HButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 23, 246);\n"
"color: rgb(232, 223, 224);"));

        Tabs->addWidget(HButton);

        PButton = new QPushButton(verticalFrame_3);
        PButton->setObjectName("PButton");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(PButton->sizePolicy().hasHeightForWidth());
        PButton->setSizePolicy(sizePolicy3);
        PButton->setMinimumSize(QSize(200, 20));
        PButton->setMaximumSize(QSize(200, 25));
        PButton->setBaseSize(QSize(200, 20));
        PButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 23, 246);\n"
"color: rgb(232, 223, 224);"));

        Tabs->addWidget(PButton);

        AButton = new QPushButton(verticalFrame_3);
        AButton->setObjectName("AButton");
        sizePolicy3.setHeightForWidth(AButton->sizePolicy().hasHeightForWidth());
        AButton->setSizePolicy(sizePolicy3);
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
        sizePolicy3.setHeightForWidth(SButton->sizePolicy().hasHeightForWidth());
        SButton->setSizePolicy(sizePolicy3);
        SButton->setMinimumSize(QSize(200, 20));
        SButton->setMaximumSize(QSize(200, 25));
        SButton->setBaseSize(QSize(200, 20));
        SButton->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 23, 246);\n"
"color: rgb(232, 223, 224);"));

        verticalLayout_3->addWidget(SButton);

        Misc = new QVBoxLayout();
        Misc->setObjectName("Misc");

        verticalLayout_3->addLayout(Misc);

        deleteU = new QPushButton(centralwidget);
        deleteU->setObjectName("deleteU");
        deleteU->setGeometry(QRect(430, 260, 101, 24));
        add = new QPushButton(centralwidget);
        add->setObjectName("add");
        add->setGeometry(QRect(270, 260, 101, 24));
        list = new QListWidget(centralwidget);
        list->setObjectName("list");
        list->setGeometry(QRect(240, 60, 331, 192));
        Settings->setCentralWidget(centralwidget);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QMainWindow *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Settings", nullptr));
        title->setText(QCoreApplication::translate("Settings", "Settings", nullptr));
        HButton->setText(QCoreApplication::translate("Settings", "Home", nullptr));
        PButton->setText(QCoreApplication::translate("Settings", "Patients", nullptr));
        AButton->setText(QCoreApplication::translate("Settings", "Appointments", nullptr));
        SButton->setText(QCoreApplication::translate("Settings", "System Settings", nullptr));
        deleteU->setText(QCoreApplication::translate("Settings", "Delete User", nullptr));
        add->setText(QCoreApplication::translate("Settings", "Add User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
