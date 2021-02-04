#include "riposopassivo.h"

RiposoPassivo::RiposoPassivo(const string & n, const string & d, const string & ir, const Orario & o) : Riposo(n, d, ir), durata(o) {}

RiposoPassivo::RiposoPassivo(const RiposoPassivo & e) : Riposo(e), durata(e.durata) {}

string RiposoPassivo::getDescrizione() const {
    return Esercizio::getDescrizione() + " i altre sborae varie su RiposoPassivo...";
}

Orario RiposoPassivo::getDurata() const {
    return durata;
}

void RiposoPassivo::setDurata(const Orario & o) {
    durata = o;
}

uint RiposoPassivo::stimaCalorieBruciate() const {
    return 0;
}

void RiposoPassivo::incrementaIntensita() { //meno riposo
    durata = durata - Orario(durata.getSecondi() / 10, durata.getMinuti() / 10, durata.getOre() / 10);
}

void RiposoPassivo::decrementaIntesita() { //più riposo
    durata = durata + Orario(durata.getSecondi() / 10, durata.getMinuti() / 10, durata.getOre() / 10);
}

RiposoPassivo * RiposoPassivo::clone() const {
    return new RiposoPassivo(*this);
}

RiposoPassivo & RiposoPassivo::operator=(const RiposoPassivo & e) {
    Riposo::operator=(e);
    durata = e.durata;
    return *this;
}

bool RiposoPassivo::operator==(const Esercizio & e) const {
    return Riposo::operator==(e) && durata == static_cast<const RiposoPassivo&>(e).durata;
}

bool RiposoPassivo::operator!=(const Esercizio & e) const {
    return !(*this == e);
}

std::ostream & RiposoPassivo::operator<<(std::ostream & os) const {
    Riposo::operator<<(os) << std::endl;
    os << " | Descrizione: " << getDescrizione() << std::endl;
    os << " +---";
    return os;
}
