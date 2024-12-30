QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Link the SQLite library
QT += sql

SOURCES += \
    AddAppointmentDialog.cpp \
    AddFileDialog.cpp \
    AddInjectionDialog.cpp \
    AddPatientDialog.cpp \
    AddUserDialog.cpp \
    AppointmentWindow.cpp \
    Injection.cpp \
    MedicalFile.cpp \
    Patient.cpp \
    PatientWindow.cpp \
    Settings.cpp \
    Singleton.cpp \
    User.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AddAppointmentDialog.h \
    AddFileDialog.h \
    AddInjectionDialog.h \
    AddPatientDialog.h \
    AddUserDialog.h \
    Appointment.h \
    AppointmentWindow.h \
    Injection.h \
    MedicalFile.h \
    Patient.h \
    PatientWindow.h \
    Settings.h \
    Singleton.h \
    User.h \
    mainwindow.h

FORMS += \
    AddAppointmentDialog.ui \
    AddFileDialog.ui \
    AddInjectionDialog.ui \
    AddPatientDialog.ui \
    AddUserDialog.ui \
    AppointmentWindow.ui \
    PatientWindow.ui \
    Settings.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
