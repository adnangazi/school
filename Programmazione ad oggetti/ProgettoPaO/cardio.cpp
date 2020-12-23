#include "cardio.h"

Cardio::Cardio(const string n, const string d, const uint m, const Orario & o, const uint & v) : MonoEsercizio(n, d, m), durata(o), velocita(v) {}

uint Cardio::getVelocita() const {
    return velocita;
}

void Cardio::setVelocita(const uint & v) {
    velocita = v;
}

string Cardio::getDescrizione() const {
    return Esercizio::getDescrizione() + "i altre sborae varie su Cardio...";
}

Orario Cardio::getDurata() const {
    return durata;
}

void Cardio::setDurata(const Orario & o) {
    durata = o;
}

uint Cardio::stimaCalorieBruciate() const {
    return (velocita * (durata.getOre() * 3600 + durata.getMinuti() * 60 + durata.getSecondi()) * MonoEsercizio::getMET()) / 100;
}

void Cardio::incrementaIntensita() {
    velocita++;
}

void Cardio::decrementaIntesita() {
    if (velocita > 0) {
        velocita--;
    } else {
        std::cout << "Impossibile diminuire ulteriormente la velocità dell'esercizio!" << std::endl;
    }
}

Cardio *Cardio::clone() const {
    return new Cardio(*this);
}
