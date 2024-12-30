#include "Injection.h"

Injection::Injection(const QString& itype, const QString& idate)
    : injectionType(itype), dateInjected(idate) {}

const QString& Injection::getType() const {
    return injectionType;
}

const QString& Injection::getDate() const {
    return dateInjected;
}
