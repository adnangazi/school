#include "cardio.h"

Cardio::Cardio(const string & n, const string & d, const uint & m, const Orario & o, const uint & v) : MonoEsercizio(n, d, m), durata(o), velocita(v) {}

Cardio::Cardio(const Esercizio & e) : MonoEsercizio(e) {
    const Cardio * const temp = dynamic_cast<const Cardio*>(&e);
    if (temp != nullptr) {
        durata = temp->durata;
        velocita = temp->velocita;
    } else {
        durata = Orario();
        velocita = 0;
    }
}

uint Cardio::getVelocita() const {
    return velocita;
}

void Cardio::setVelocita(const uint & v) {
    if (v <= 10) {
        velocita = v;
    } else {
        velocita = 10;
        std::cout << "Impossibile impostare la velocità a " << v << ": valore troppo elevato. Velocità impostata al valore massimo 10!" << std::endl;
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

Cardio * Cardio::clone() const {
    return new Cardio(*this);
}

Esercizio & Cardio::operator=(const Esercizio & e) {
    MonoEsercizio::operator=(e);
    const Cardio * const temp = dynamic_cast<const Cardio*>(&e);
    if (temp != nullptr) {
        durata = temp->durata;
        velocita = temp->velocita;
    } else {
        durata = Orario();
        velocita = 0;
    }
    return * this;
}

bool Cardio::operator==(const Esercizio & e) const {
    const Cardio temp = dynamic_cast<const Cardio&>(e); //dynamic_cast per via della base virtuale
    return MonoEsercizio::operator== (e) && durata == temp.durata && velocita == temp.velocita;
}

bool Cardio::operator!=(const Esercizio & e) const {
    return !(*this == e);
}

uint Cardio::stimaCalorieBruciate() const {
    return (velocita * (durata.getOre() * 3600 + durata.getMinuti() * 60 + durata.getSecondi()) * getMET()) / 80;
}

void Cardio::incrementaIntensita() {
    if (velocita < 10) {
        velocita++;
    } else {
        std::cout << "Impossibile incrementare ulteriormente la velocità!" << std::endl;
    }
}

void Cardio::decrementaIntesita() {
    if (velocita > 0) {
        velocita--;
    } else {
        std::cout << "Impossibile decrementare ulteriormente la velocità!" << std::endl;
    }
}
