#include "crossfit.h"

CrossFit::CrossFit(const string n, const string d, const uint m, const Orario & o, const uint & v, const uint & p) : MonoEsercizio(n, d, m), Cardio(n, d, m, o, v), SollevamentoPesi(n, d, m, p, 0, 1) {
    SollevamentoPesi::setDurata(o);
}

string CrossFit::getDescrizione() const {
    return Esercizio::getDescrizione() + Cardio::getDescrizione() + SollevamentoPesi::getDescrizione() + "i altre sborae varie su CrossFit...";
}

Orario CrossFit::getDurata() const {
    return Cardio::getDurata();
}

void CrossFit::setDurata(const Orario & o) {
    Cardio::setDurata(o);
    SollevamentoPesi::setDurata(o);
}

uint CrossFit::stimaCalorieBruciate() const {
    return Cardio::stimaCalorieBruciate() + SollevamentoPesi::stimaCalorieBruciate();
}

void CrossFit::incrementaIntensita() {
    Cardio::incrementaIntensita();
    uint pesoTemp = getPeso();
    pesoTemp += pesoTemp / 10;
    setPeso(pesoTemp);
}

void CrossFit::decrementaIntesita() {
    Cardio::decrementaIntesita();
    uint pesoTemp = getPeso();
    pesoTemp -= pesoTemp / 11;
    setPeso(pesoTemp);
}

CrossFit *CrossFit::clone() const {
    return new CrossFit(*this);
}
