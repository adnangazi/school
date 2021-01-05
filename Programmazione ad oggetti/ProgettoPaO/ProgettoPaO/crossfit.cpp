#include "crossfit.h"

//numero serie e ripetizioni si adeguano alla durata dell'esercizio!
CrossFit::CrossFit(const string & n, const string & d, const uint m, const Orario & o, const uint v, const uint p) : MonoEsercizio(n, d, m), Cardio(n, d, m, o, v), SollevamentoPesi(n, d, m, p, 0, 1) {
    SollevamentoPesi::setDurata(o);
}

CrossFit::CrossFit(const Esercizio & e) : MonoEsercizio(e), Cardio(e), SollevamentoPesi(e) {}

string CrossFit::getDescrizione() const {
    return Esercizio::getDescrizione() + Cardio::getDescrizione() + SollevamentoPesi::getDescrizione() + " i altre sborae varie su CrossFit...";
}

Orario CrossFit::getDurata() const {
    return Cardio::getDurata();
}

void CrossFit::setDurata(const Orario & o) {
    Cardio::setDurata(o); //imposto durata
    SollevamentoPesi::setDurata(o); //adatto numero serie e ripetizioni alla durata impostata
}

uint CrossFit::stimaCalorieBruciate() const {
    return Cardio::stimaCalorieBruciate() + SollevamentoPesi::stimaCalorieBruciate();
}

//esercizi crossfit non sono divisi in serie: si fanno tutto di continuo per la durata dell'esercizio --> non si può incrementare o decrementare l'intesità della parte di sollevamento pesi, perchè quello va a modificare il numero di serie (che invece deve rimanere a 1!).
void CrossFit::incrementaIntensita() {
    Cardio::incrementaIntensita();
    SollevamentoPesi::incrementaIntensita();
}

//esercizi crossfit non sono divisi in serie: si fanno tutto di continuo per la durata dell'esercizio --> non si può incrementare o decrementare l'intesità della parte di sollevamento pesi, perchè quello va a modificare il numero di serie (che invece deve rimanere a 1!).
void CrossFit::decrementaIntesita() {
    Cardio::decrementaIntesita();
    SollevamentoPesi::decrementaIntesita();
}

CrossFit * CrossFit::clone() const {
    return new CrossFit(*this);
}

Esercizio & CrossFit::operator=(const Esercizio & e) {
    Cardio::operator=(e);
    SollevamentoPesi::operator=(e);
    return *this;
}

bool CrossFit::operator==(const Esercizio & e) const {
    const SollevamentoPesi temp = dynamic_cast<const SollevamentoPesi&>(e); //dynamic_cast per base virtuale. Non faccio SollevamentoPeso::operator==(): evito di chiamarre MonoEsercizio::operator==() e Esercizio::operator==() perchè già chiamati da Cardio::operator==()
    return Cardio::operator==(e) && getPeso() == temp.getPeso() && getRipetizioni() == temp.getRipetizioni() && getSerie() == temp.getSerie();
}

bool CrossFit::operator!=(const Esercizio & e) const {
    return !(*this == e);
}
