#ifndef INJECTION_H
#define INJECTION_H

#include <QString>

class Injection {
protected:
    QString injectionType;
    QString dateInjected;

public:
    Injection(const QString& itype, const QString& idate);
    const QString& getType() const;
    const QString& getDate() const;
};

#endif // INJECTION_H
