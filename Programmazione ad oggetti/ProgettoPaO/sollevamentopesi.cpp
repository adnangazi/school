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
    return Esercizio::getDescrizione() + " i altre sborae varie su SollevamentoPesi...";
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
    return getMET() * ripetizioni * serie;
}

void SollevamentoPesi::incrementaIntensita() {
    if (serie > ripetizioni) {
        if (serie > 1) {
            serie--;
            ripetizioni += ripetizioni / serie;
            peso += peso / 10;
        } else {
            std::cout << "Impossibile incrementare ulteriormente l'intensità dell'esercizio: numero di serie troppo basso!" << std::endl;
        }
    } else if (ripetizioni > 1) {
        ripetizioni--;
        serie += serie / ripetizioni;
        peso += peso / 10;
    } else {
        std::cout << "Impossibile incrementare ulteriormente l'intensità dell'esercizio: numero di ripetizioni troppo basso!" << std::endl;
    }
}

void SollevamentoPesi::decrementaIntesita() {
    if (serie > ripetizioni) {
        if (serie > 1) {
            serie++;
            ripetizioni -= ripetizioni / serie;
            peso -= peso / 11;
        } else {
            std::cout << "Impossibile decrementare ulteriormente l'intensità dell'esercizio: numero di serie troppo basso!" << std::endl;
        }
    } else if (ripetizioni > 1) {
        ripetizioni++;
        serie -= serie / ripetizioni;
        peso -= peso / 11;
    } else {
        std::cout << "Impossibile decrementare ulteriormente l'intensità dell'esercizio: numero di ripetizioni troppo basso!" << std::endl;
    }
}

SollevamentoPesi * SollevamentoPesi::clone() const {
    return new SollevamentoPesi(*this);
}

bool SollevamentoPesi::operator== (const Esercizio & e) const {
    std::cout << "SollevamentoPesi::operator==()" << std::endl;
    SollevamentoPesi temp = dynamic_cast<const SollevamentoPesi&>(e);
    return MonoEsercizio::operator== (e) && peso == temp.peso && ripetizioni == temp.ripetizioni && serie == temp.serie;
}

bool SollevamentoPesi::operator!= (const Esercizio & e) const {
    std::cout << "SollevamentoPesi::operator!=()" << std::endl;
    return ! (*this == e);
}

const Orario SollevamentoPesi::tempoDiRipetizione = Orario(5);
