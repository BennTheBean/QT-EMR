#include "User.h"

User::User(const QString& uname, const QString& pwd)
    : username(uname), password(pwd) {}

const QString& User::getUsername() const {
    return username;
}

const QString& User::getPassword() const {
    return password;
}

Doctor::Doctor(const QString& uname, const QString& pwd)
    : User(uname, pwd) {}

QString Doctor::getRole() const {
    return "Doctor";
}

Admin::Admin(const QString& uname, const QString& pwd)
    : User(uname, pwd) {}

QString Admin::getRole() const {
    return "Admin";
}

Receptionist::Receptionist(const QString& uname, const QString& pwd)
    : User(uname, pwd) {}

QString Receptionist::getRole() const {
    return "Receptionist";
}
