#include "monoesercizio.h"

MonoEsercizio::MonoEsercizio(const string n, const string d, const uint m) : Esercizio(n, d), MET(m) {}

uint MonoEsercizio::getMET() const {
    return MET;
}

void MonoEsercizio::setMET(const uint & m) {
    MET = m;
}
