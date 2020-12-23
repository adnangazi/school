#include "sollevamentopesi.h"

SollevamentoPesi::SollevamentoPesi(const string n, const string d, const uint m, const uint & p, const uint & r, const uint & s) : MonoEsercizio(n, d, m), peso(p), ripetizioni(r), serie(s) {}

uint SollevamentoPesi::getPeso() const {
    return peso;
}

void SollevamentoPesi::setPeso(const uint & p) {
    peso = p;
}

uint SollevamentoPesi::getRipetizioni() const {
    return ripetizioni;
}

void SollevamentoPesi::setRipetizioni(const uint & r) {
    ripetizioni = r;
}

uint SollevamentoPesi::getSerie() const {
    return serie;
}

void SollevamentoPesi::setSerie(const uint & s) {
    serie = s;
}

string SollevamentoPesi::getDescrizione() const {
    return Esercizio::getDescrizione() + "i altre sborae varie su SollevamentoPesi...";
}

Orario SollevamentoPesi::getDurata() const {
    return Orario(tempoDiRipetizione.getSecondi() * ripetizioni * serie, serie - 1);
}

void SollevamentoPesi::setDurata(const Orario & o) {
    uint totaleSec = o.getOre() * 3600 + o.getMinuti() * 60 + o.getSecondi();
    totaleSec -= (serie - 1) * 60; //tolgo il minuto di riposo obbligatorio tra una serie e l'altra
    ripetizioni = (totaleSec / serie) / tempoDiRipetizione.getSecondi();
}

uint SollevamentoPesi::stimaCalorieBruciate() const {
    return MonoEsercizio::getMET() * ripetizioni * serie;
}

void SollevamentoPesi::incrementaIntensita() {
    if (serie > 1) {
        serie--;
        ripetizioni += ripetizioni / serie;
        peso += peso / 10;
    } else {
        std::cout << "Impossibile aumentare ulteriormente l'intensità dell'esercizio!" << std::endl;
    }
}

void SollevamentoPesi::decrementaIntesita() {
    serie++;
    ripetizioni -= ripetizioni / serie;
    peso -= peso / 11;
}

SollevamentoPesi * SollevamentoPesi::clone() const {
    return new SollevamentoPesi(*this);
}

const Orario SollevamentoPesi::tempoDiRipetizione = Orario(5);
