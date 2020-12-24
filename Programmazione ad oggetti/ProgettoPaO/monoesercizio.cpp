#include "monoesercizio.h"

MonoEsercizio::MonoEsercizio(const string n, const string d, const uint m) : Esercizio(n, d), MET(m) {}

uint MonoEsercizio::getMET() const {
    return MET;
}

void MonoEsercizio::setMET(const uint & m) {
    MET = m;
}

bool MonoEsercizio::operator== (const Esercizio & e) const {
    std::cout << "MonoEsercizio::operator==()" << std::endl;
    return Esercizio::operator== (e) && MET == static_cast<const MonoEsercizio&>(e).MET;
}

bool MonoEsercizio::operator!= (const Esercizio & e) const {
    std::cout << "MonoEsercizio::operator!=()" << std::endl;
    return ! (*this == e); //!MonoEsercizio::operator== (e);
}
