#include "monoesercizio.h"

MonoEsercizio::MonoEsercizio(const string & n, const string & d, const uint & m) : Esercizio(n, d), MET(m) {}

MonoEsercizio::MonoEsercizio(const Esercizio & e) : Esercizio(e) {
    const MonoEsercizio * const temp = dynamic_cast<const MonoEsercizio*>(&e);
    if (temp != nullptr) {
        MET = temp->MET;
    } else {
        MET = 0;
    }
}

uint MonoEsercizio::getMET() const {
    return MET;
}

void MonoEsercizio::setMET(const uint & m) {
    MET = m;
}

Esercizio & MonoEsercizio::operator=(const Esercizio & e) {
    Esercizio::operator=(e);
    const MonoEsercizio * const temp = dynamic_cast<const MonoEsercizio*>(&e);
    if (temp != nullptr) {
        MET = temp->MET;
    } else {
        MET = 0;
    }
    return * this;
}

bool MonoEsercizio::operator==(const Esercizio & e) const {
    return Esercizio::operator==(e) && MET == static_cast<const MonoEsercizio&>(e).MET;
}

bool MonoEsercizio::operator!=(const Esercizio & e) const {
    return !(*this == e);
}
