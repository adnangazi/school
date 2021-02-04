#include "cardio.h"

Cardio::Cardio(const string & n, const string & d, const uint m, const Orario & o, const uint v) : MonoEsercizio(n, d, m), durata(o), velocita(v) {}

Cardio::Cardio(const Cardio & e) : MonoEsercizio(e), durata(e.durata), velocita(e.velocita) {}

uint Cardio::getVelocita() const {
    return velocita;
}

void Cardio::setVelocita(const uint v) {
    if (v <= 10) {
        velocita = v;
    } else {
        velocita = 10;
        throw std::out_of_range("Impossibile impostare la velocità a tale valore (troppo elevato). Velocità impostata al valore massimo 10!");
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
        throw std::out_of_range("Impossibile incrementare ulteriormente la velocità!");
    }
}

void Cardio::decrementaIntesita() {
    if (velocita > 0) {
        velocita--;
    } else {
        throw std::out_of_range("Impossibile decrementare ulteriormente la velocità!");
    }
}

Cardio * Cardio::clone() const {
    return new Cardio(*this);
}

Cardio & Cardio::operator=(const Cardio & e) {
    MonoEsercizio::operator=(e);
    durata = e.durata;
    velocita = e.velocita;
    return *this;
}

bool Cardio::operator==(const Esercizio & e) const {
    const Cardio temp = dynamic_cast<const Cardio&>(e); //dynamic_cast per via della base virtuale
    return MonoEsercizio::operator== (e) && durata == temp.durata && velocita == temp.velocita;
}

bool Cardio::operator!=(const Esercizio & e) const {
    return !(*this == e);
}

std::ostream & Cardio::operator<<(std::ostream & os) const {
    MonoEsercizio::operator<<(os) << std::endl;
    os << " | Descrizione: " << getDescrizione() << std::endl;
    os << " | Velocita': " << velocita << std::endl;
    os << " +---";
    return os;
}
