#include "cardio.h"

Cardio::Cardio(const string n, const string d, const uint m, const Orario & o, const uint & v) : MonoEsercizio(n, d, m), durata(o), velocita(v) {}

uint Cardio::getVelocita() const {
    return velocita;
}

void Cardio::setVelocita(const uint & v) {
    if (v <= 10) {
        velocita = v;
    } else {
        velocita = 10;
        std::cout << "Impossibile impostare la velocità dell'esercizio a " << v << ": valore troppo elevato. Velocità impostata al valore massimo 10!" << std::endl;
    }
}

string Cardio::getDescrizione() const {
    return Esercizio::getDescrizione() + " i altre sborae varie su Cardio...";
}

Orario Cardio::getDurata() const {
    return durata;
}

void Cardio::setDurata(const Orario & o) {
    durata = o;
}

uint Cardio::stimaCalorieBruciate() const {
    return (velocita * (durata.getOre() * 3600 + durata.getMinuti() * 60 + durata.getSecondi()) * getMET()) / 80;
}

void Cardio::incrementaIntensita() {
    if (velocita < 10) {
        velocita++;
    } else {
        std::cout << "Impossibile incrementare ulteriormente la velocità dell'esercizio!" << std::endl;
    }
}

void Cardio::decrementaIntesita() {
    if (velocita > 0) {
        velocita--;
    } else {
        std::cout << "Impossibile decrementare ulteriormente la velocità dell'esercizio!" << std::endl;
    }
}

Cardio * Cardio::clone() const {
    return new Cardio(*this);
}

bool Cardio::operator== (const Esercizio & e) const {
    std::cout << "Cardio::operator==()" << std::endl;
    Cardio temp = dynamic_cast<const Cardio&>(e);
    return MonoEsercizio::operator== (e) && durata == temp.durata && velocita == temp.velocita;
}

bool Cardio::operator!= (const Esercizio & e) const {
    std::cout << "Cardio::operator!=()" << std::endl;
    return ! (*this == e);
}
