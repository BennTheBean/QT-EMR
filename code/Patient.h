#ifndef PATIENT_H
#define PATIENT_H

#include <QString>

class Appointment;
class MedicalFile;
class Injection;

class Patient {
private:
    QString name;
    QString DOB;
    QString sex;
    QString OHIP;
    QString email;
    QString address;
    std::vector<Injection*> injections;

public:
    // Constructor
    Patient(const QString& pname, const QString& pdob, const QString& psex, const QString& pohip, const QString& pemail, const QString& paddress);

    // Getters
    QString getName() const;
    QString getDOB() const;
    QString getSex() const;
    QString getOHIP() const;
    QString getEmail() const;
    QString getAddress() const;
    std::vector<Injection*> getInjections() const;

    // Setters
    void setName(const QString& pname);
    void setDOB(const QString& pdob);
    void setSex(const QString& psex);
    void setOHIP(const QString& pohip);
    void setEmail(const QString& pemail);
    void setAddress(const QString& paddress);
    void setInjections(std::vector<Injection*> pinjections);
};

#endif // PATIENT_H
