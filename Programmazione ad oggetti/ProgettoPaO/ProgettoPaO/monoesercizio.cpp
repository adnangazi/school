#include "monoesercizio.h"

MonoEsercizio::MonoEsercizio(const string & n, const string & d, const uint m) : Esercizio(n, d), MET(m) {}

MonoEsercizio::MonoEsercizio(const MonoEsercizio & e) : Esercizio(e), MET(e.MET) {}

uint MonoEsercizio::getMET() const {
    return MET;
}

void MonoEsercizio::setMET(const uint m) {
    MET = m;
}

MonoEsercizio & MonoEsercizio::operator=(const MonoEsercizio & e) {
    Esercizio::operator=(e);
    MET = e.MET;
    return *this;
}

bool MonoEsercizio::operator==(const Esercizio & e) const {
    return Esercizio::operator==(e) && MET == static_cast<const MonoEsercizio&>(e).MET;
}

bool MonoEsercizio::operator!=(const Esercizio & e) const {
    return !(*this == e);
}

std::ostream & MonoEsercizio::operator<<(std::ostream & os) const {
    Esercizio::operator<<(os) << std::endl;
    os << " | MET: " << MET;
    return os;
}
