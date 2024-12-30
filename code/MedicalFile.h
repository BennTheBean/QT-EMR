#ifndef MEDICALFILE_H
#define MEDICALFILE_H

#include <QString>
#include "Patient.h"
#include <QDir>
#include <QDesktopServices>
#include <QFile>
#include <QTextStream>

class MedicalFile {
protected:
    QString dateCreated;
    Patient* patient;  // Pointer to the Patient object
    QString type;
    QString data;
    QString sanitizeDate(const QString& date);

public:
    MedicalFile(const QString& fdate, Patient* patient, const QString& data);
    virtual void print() = 0;
    void deleteMedicalFile();
    void openFile();
    QString getDate();
    QString getData();
    virtual QString getFileName() = 0;
    virtual QString getType() = 0;
    virtual ~MedicalFile() {}  // Virtual destructor for polymorphism
};

class ImmunizationRecord : public MedicalFile {
public:
    ImmunizationRecord(const QString& fdate, Patient* patient, const QString& data);
    void print() override;
    QString getFileName() override;
    QString getType() override;
};

class LabReq : public MedicalFile {
public:
    LabReq(const QString& fdate, Patient* patient, const QString& data);
    void print() override;
    QString getFileName() override;
    QString getType() override;
};

class Prescription : public MedicalFile {
public:
    Prescription(const QString& fdate, Patient* patient, const QString& drug);
    void print() override;
    QString getFileName() override;
    QString getType() override;
};

class FileFactory {
public:
    virtual MedicalFile* createFile(const QString& fdate, Patient* patient, const QString& data) = 0;  // 3 arguments
    virtual ~FileFactory() {}
};

class ImmunizationRecordFactory : public FileFactory {
public:
    MedicalFile* createFile(const QString& fdate, Patient* patient, const QString& data) override {
        return new ImmunizationRecord(fdate, patient, data);
    }
};

class LabReqFactory : public FileFactory {
public:
    MedicalFile* createFile(const QString& fdate, Patient* patient, const QString& data) override {
        return new LabReq(fdate, patient, data);
    }
};

class PrescriptionFactory : public FileFactory {
public:
    MedicalFile* createFile(const QString& fdate, Patient* patient, const QString& data) override {
        return new Prescription(fdate, patient, data);
    }
};

#endif // MEDICALFILE_H
