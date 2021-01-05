#include "sollevamentopesi.h"

SollevamentoPesi::SollevamentoPesi(const string & n, const string & d, const uint m, const uint p, const uint r, const uint s) : MonoEsercizio(n, d, m), peso(p), ripetizioni(r), serie(s) {}

SollevamentoPesi::SollevamentoPesi(const Esercizio & e) : MonoEsercizio(e) {
    const SollevamentoPesi * const temp = dynamic_cast<const SollevamentoPesi*>(&e);
    if (temp != nullptr) {
        peso = temp->peso;
        ripetizioni = temp->ripetizioni;
        serie = temp->serie;
    } else {
        peso = ripetizioni = serie = 0;
    }
}

uint SollevamentoPesi::getPeso() const {
    return peso;
}

void SollevamentoPesi::setPeso(const uint p) {
    peso = p;
}

uint SollevamentoPesi::getRipetizioni() const {
    return ripetizioni;
}

void SollevamentoPesi::setRipetizioni(const uint r) {
    ripetizioni = r;
}

uint SollevamentoPesi::getSerie() const {
    return serie;
}

void SollevamentoPesi::setSerie(const uint s) {
    serie = s;
}

string SollevamentoPesi::getDescrizione() const {
    return Esercizio::getDescrizione() + " i altre sborae varie su SollevamentoPesi...";
}

Orario SollevamentoPesi::getDurata() const {
    return Orario(tempoDiRipetizione.getSecondi() * ripetizioni * serie, serie - 1);
}

void SollevamentoPesi::setDurata(const Orario & o) {
    if (serie > 0) {
        uint totaleSec = o.getOre() * 3600 + o.getMinuti() * 60 + o.getSecondi();
        totaleSec -= (serie - 1) * 60; //tolgo il minuto di riposo obbligatorio tra una serie e l'altra
        ripetizioni = (totaleSec / serie) / tempoDiRipetizione.getSecondi();
    } else {
        throw std::out_of_range("Impossibile impostare la durata: numero di serie troppo basso!");
    }
}

uint SollevamentoPesi::stimaCalorieBruciate() const {
    return getMET() * ripetizioni * serie;
}

void SollevamentoPesi::incrementaIntensita() {
    if (serie <= 1 || ripetizioni <= 0) {
        throw std::out_of_range("Impossibile incrementare ulteriormente l'intensità: numero di serie o ripetizioni troppo basso!");
    } else {
        if (serie > ripetizioni) {
            serie = round(static_cast<double>(ripetizioni * serie) / static_cast<double>(ripetizioni + 1));
            ripetizioni++;
        } else {
            ripetizioni = round(static_cast<double>(ripetizioni * serie) / static_cast<double>(serie - 1));
            serie--;
        }
        peso += (peso < 10) ? 1 : peso / 10;
    }
}

void SollevamentoPesi::decrementaIntesita() {
    if (serie <= 0 || ripetizioni <= 1) {
        throw std::out_of_range("Impossibile decrementare ulteriormente l'intensità: numero di serie o ripetizioni troppo basso!");
    } else {
        if (ripetizioni > serie) {
            ripetizioni = round(static_cast<double>(ripetizioni * serie) / static_cast<double>(serie + 1));
            serie++;
        } else {
            serie = round(static_cast<double>(ripetizioni * serie) / static_cast<double>(ripetizioni - 1));
            ripetizioni--;
        }
        peso -= (peso > 0 && peso < 11) ? 1 : peso / 11;
    }
}

SollevamentoPesi * SollevamentoPesi::clone() const {
    return new SollevamentoPesi(*this);
}

Esercizio & SollevamentoPesi::operator=(const Esercizio & e) {
    MonoEsercizio::operator=(e);
    const SollevamentoPesi * const temp = dynamic_cast<const SollevamentoPesi*>(&e);
    if (temp != nullptr) {
        peso = temp->peso;
        ripetizioni = temp->ripetizioni;
        serie = temp->serie;
    } else {
        peso = ripetizioni = serie = 0;
    }
    return *this;
}

bool SollevamentoPesi::operator==(const Esercizio & e) const {
    const SollevamentoPesi temp = dynamic_cast<const SollevamentoPesi&>(e); //dynamic_cast necessario per visa della base virtuale
    return MonoEsercizio::operator==(e) && peso == temp.peso && ripetizioni == temp.ripetizioni && serie == temp.serie;
}

bool SollevamentoPesi::operator!=(const Esercizio & e) const {
    return !(*this == e);
}

const Orario SollevamentoPesi::tempoDiRipetizione = Orario(5);
