#include "MedicalFile.h"
#include "qurl.h"
#include "Injection.h"
#include <fstream>
#include <stdexcept>

// MedicalFile constructor
MedicalFile::MedicalFile(const QString& fdate, Patient* patient, const QString& data)
    : dateCreated(fdate), patient(patient), data(data){}

// Helper method to sanitize dates (replace slashes with dashes)
QString MedicalFile::sanitizeDate(const QString& date) {
    QString sanitizedDate = date;
    sanitizedDate.replace("/", "-");
    return sanitizedDate;
}

// Method to delete the medical file
void MedicalFile::deleteMedicalFile() {
    QString fileName = QDir::homePath() + "/Downloads/" + this->getFileName();
    QFile fileOnDisk(fileName);
    if (fileOnDisk.exists()) {
        if (!fileOnDisk.remove()) {
            throw std::runtime_error("Failed to delete the file on the disk: " + fileName.toStdString());
        }
    } else {
        throw std::runtime_error("The file does not exist on the disk: " + fileName.toStdString());
    }
}

// Method to open the file
void MedicalFile::openFile() {
    QString fileName = QDir::homePath() + "/Downloads/" + getFileName();

    if (QFile::exists(fileName)) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    } else {
        throw std::runtime_error("File does not exist: " + fileName.toStdString());
    }
}

QString MedicalFile::getDate() {
    return dateCreated;
}

QString MedicalFile::getData() {
    return data;
}

ImmunizationRecord::ImmunizationRecord(const QString& fdate, Patient* patient, const QString& data="")
    : MedicalFile(fdate, patient, data) {}

void ImmunizationRecord::print() {
    QString sanitizedDate = sanitizeDate(dateCreated);
    QString fileName = QDir::homePath() + "/Downloads/" + patient->getName() + "_Immunization_Record_" + sanitizedDate + ".txt";
    std::ofstream file(fileName.toStdString());

    if (file.is_open()) {
        file << patient->getName().toStdString() << "'s Immunization Records" << "\n";

        const std::vector<Injection*>& injections = patient->getInjections();
        if (injections.empty()) {
            file << "No immunizations recorded.\n";
        } else {
            for (size_t i = 0; i < injections.size(); ++i) {
                file << injections[i]->getType().toStdString() << " administered on "
                     << injections[i]->getDate().toStdString() << "\n";
            }
        }
        file.close();
    } else {
        throw std::runtime_error("Unable to print file " + fileName.toStdString());
    }
}

QString ImmunizationRecord::getFileName() {
    return patient->getName() + "_Immunization_Record_" + sanitizeDate(dateCreated) + ".txt";
}

QString ImmunizationRecord::getType() {
    return "Immunization Record";
}


LabReq::LabReq(const QString& fdate, Patient* patient, const QString& reqType)
    : MedicalFile(fdate, patient, reqType) {}

void LabReq::print() {
    QString sanitizedDate = sanitizeDate(dateCreated);
    QString fileName = QDir::homePath() + "/Downloads/" + patient->getName() + "_Lab_Requisition_" + sanitizedDate + ".txt";
    std::ofstream file(fileName.toStdString());

    if (file.is_open()) {
        file << "Patient Name: " << patient->getName().toStdString() << "\n";
        file << "Date of Birth: " << patient->getDOB().toStdString() << "\n";
        file << "Sex: " << patient->getSex().toStdString() << "\n";
        file << "OHIP: " << patient->getOHIP().toStdString() << "\n";
        file << "Email: " << patient->getEmail().toStdString() << "\n";
        file << "Address: " << patient->getAddress().toStdString() << "\n";
        file << "Lab Request Type: " << data.toStdString() << "\n";
        file << "Request Date: " << dateCreated.toStdString() << "\n";
        file.close();
    } else {
        throw std::runtime_error("Unable to print file " + fileName.toStdString());
    }
}

QString LabReq::getFileName() {
    return patient->getName() + "_Lab_Requisition_" + sanitizeDate(dateCreated) + ".txt";
}


QString LabReq::getType() {
    return "Laboratory Requisition";
}

Prescription::Prescription(const QString& fdate, Patient* patient, const QString& drug)
    : MedicalFile(fdate, patient, drug) {}

void Prescription::print() {
    QString sanitizedDate = sanitizeDate(dateCreated);
    QString fileName = QDir::homePath() + "/Downloads/" + patient->getName() + "_Prescription_" + sanitizedDate + ".txt";
    std::ofstream file(fileName.toStdString());

    if (file.is_open()) {
        file << "For: " << patient->getName().toStdString() << "\n";
        file << "Address: " << patient->getAddress().toStdString() << "\n";
        file << "Date: " << dateCreated.toStdString() << "\n";
        file << "Drug: " << data.toStdString() << "\n";
        file.close();
    } else {
        throw std::runtime_error("Unable to print file " + fileName.toStdString());
    }
}

QString Prescription::getFileName() {
    return patient->getName() + "_Prescription_" + sanitizeDate(dateCreated) + ".txt";
}

QString Prescription::getType() {
    return "Prescription";
}
