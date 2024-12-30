/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
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
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *LButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(960, 541);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(960, 540));
        MainWindow->setMaximumSize(QSize(1920, 1080));
        centralwidget = new QWidget(MainWindow);
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

        username = new QLineEdit(centralwidget);
        username->setObjectName("username");
        username->setGeometry(QRect(240, 70, 191, 24));
        password = new QLineEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(450, 70, 191, 24));
        LButton = new QPushButton(centralwidget);
        LButton->setObjectName("LButton");
        LButton->setGeometry(QRect(660, 70, 80, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 50, 71, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 50, 71, 16));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        HButton->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        PButton->setText(QCoreApplication::translate("MainWindow", "Patients", nullptr));
        AButton->setText(QCoreApplication::translate("MainWindow", "Appointments", nullptr));
        SButton->setText(QCoreApplication::translate("MainWindow", "System Settings", nullptr));
        username->setText(QString());
        password->setText(QString());
        LButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
