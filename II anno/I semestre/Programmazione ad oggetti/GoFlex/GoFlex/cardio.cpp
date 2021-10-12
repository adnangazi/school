#include "cardio.h"

Cardio::Cardio(const string & n, const string & d, const uint m, const Orario & o, const uint v) : MonoEsercizio(n, d, m), durata(o), velocita(v <= 10 ? v : 10) {}

Cardio::Cardio(const Cardio & e) : MonoEsercizio(e), durata(e.durata), velocita(e.velocita) {}

uint Cardio::getVelocita() const {
    return velocita;
}

void Cardio::setVelocita(const uint v) {
    if (v <= 10) {
        velocita = v;
    } else {
        velocita = 10;
    }
}

Cardio & Cardio::operator=(const Cardio & e) {
    MonoEsercizio::operator=(e);
    durata = e.durata;
    velocita = e.velocita;
    return * this;
}

string Cardio::getDescrizione() const {
    return Esercizio::getDescrizione() + ". È un esercizio Cardio " + (velocita >= 6 || durata >= Orario(0, 20, 0) || stimaCalorieBruciate() >= 200 ? "molto" : "poco" ) + " faticoso.";
}

Orario Cardio::getDurata() const {
    return durata;
}

void Cardio::setDurata(const Orario & o) {
    durata = o;
}

uint Cardio::stimaCalorieBruciate() const {
    return (velocita * (durata.getOre() * 3600 + durata.getMinuti() * 60 + durata.getSecondi()) * getMET()) / fattoreCalorico;
}

void Cardio::incrementaIntensita() {
    if (velocita < 10) {
        velocita++;
    }
}

void Cardio::decrementaIntesita() {
    if (velocita > 0) {
        velocita--;
    }
}

Cardio * Cardio::clone() const {
    return new Cardio(*this);
}

bool Cardio::operator==(const Esercizio & e) const {
    const Cardio * const temp = dynamic_cast<const Cardio*>(&e);
    return MonoEsercizio::operator== (e) && durata == temp->durata && velocita == temp->velocita;
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

const uint Cardio::fattoreCalorico = 80;
