#include "Patient.h"
#include <QString>
#include "Injection.h"

// Constructor
Patient::Patient(const QString& pname, const QString& pdob, const QString& psex, const QString& pohip, const QString& pemail, const QString& paddress)
    : name(pname), DOB(pdob), sex(psex), OHIP(pohip), email(pemail), address(paddress) {}

// Getters
QString Patient::getName() const {
    return name;
}

QString Patient::getDOB() const {
    return DOB;
}

QString Patient::getSex() const {
    return sex;
}

QString Patient::getOHIP() const {
    return OHIP;
}

QString Patient::getEmail() const {
    return email;
}

QString Patient::getAddress() const {
    return address;
}

std::vector<Injection*> Patient::getInjections() const {
    return injections;
}

// Setters
void Patient::setName(const QString& pname) {
    name = pname;
}

void Patient::setDOB(const QString& pdob) {
    DOB = pdob;
}

void Patient::setSex(const QString& psex) {
    sex = psex;
}

void Patient::setOHIP(const QString& pohip) {
    OHIP = pohip;
}

void Patient::setEmail(const QString& pemail) {
    email = pemail;
}

void Patient::setAddress(const QString& paddress) {
    address = paddress;
}

void Patient::setInjections(std::vector<Injection*> pinjections) {
    injections = pinjections;
}
