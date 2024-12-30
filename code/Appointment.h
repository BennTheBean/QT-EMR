#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QString>

class Patient;  // Forward declaration

class Appointment {
public:
    virtual ~Appointment() {}
    virtual QString getType() const = 0;
    virtual QString getDate() const = 0;
    virtual QString getTime() const = 0;
    virtual int getDuration() const = 0;
    virtual int getId() const = 0;
    virtual Patient* getPatient() const = 0;
    virtual void reschedule(const QString& newTime, const QString& newDate) = 0;
};
// Concrete Appointment class
class ConcreteAppointment : public Appointment {
private:
    int id;
    QString date;
    QString time;
    Patient* patient;

public:
    // Constructor to initialize all attributes
    ConcreteAppointment(const QString& date, const QString& time, Patient* patient, int newID)
        : id(newID), date(date), time(time), patient(patient) {}


    QString getType() const override { return "Checkup"; }
    QString getDate() const override { return date; }
    QString getTime() const override { return time; }
    int getDuration() const override { return 20; }
    int getId() const override { return id; }
    Patient* getPatient() const override { return patient; }
    void reschedule(const QString& newTime, const QString& newDate) override {
        time = newTime;
        date = newDate;
    }
};

// Appointment Decorator (Base Class)
class AppointmentDecorator : public Appointment {
protected:
    Appointment* appointment;

public:
    AppointmentDecorator(Appointment* appointment)
        : appointment(appointment) {}

    QString getType() const override { return appointment->getType(); }
    QString getDate() const override { return appointment->getDate(); }
    QString getTime() const override { return appointment->getTime(); }
    int getDuration() const override { return appointment->getDuration(); }
    int getId() const override { return appointment->getId(); }
    Patient* getPatient() const override { return appointment->getPatient(); }
    void reschedule(const QString& newTime, const QString& newDate) override {
        appointment->reschedule(newTime, newDate);
    }
};

// NewPatientDecorator
class NewPatientDecorator : public AppointmentDecorator {
public:
    NewPatientDecorator(Appointment* appointment)
        : AppointmentDecorator(appointment) {}

    QString getType() const override {
        return "New Patient - " + appointment->getType();
    }

    int getDuration() const override {
        return appointment->getDuration() + 5;
    }
};

// ReturningPatientDecorator
class ReturningPatientDecorator : public AppointmentDecorator {
public:
    ReturningPatientDecorator(Appointment* appointment)
        : AppointmentDecorator(appointment) {}

    QString getType() const override {
        return "Returning Patient - " + appointment->getType();
    }

    int getDuration() const override {
        return appointment->getDuration();
    }
};

// FluShotDecorator
class FluShotDecorator : public AppointmentDecorator {
public:
    FluShotDecorator(Appointment* appointment)
        : AppointmentDecorator(appointment) {}

    QString getType() const override {
        return appointment->getType() + " and Flu Shot";
    }

    int getDuration() const override {
        return appointment->getDuration() + 5;
    }
};

#endif // APPOINTMENT_H
