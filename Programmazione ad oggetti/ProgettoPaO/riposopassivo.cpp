#include "riposopassivo.h"

RiposoPassivo::RiposoPassivo(const string n, const string d, const string ir, const Orario & o) : Riposo(n, d, ir), durata(o) {}

string RiposoPassivo::getDescrizione() const {
    return Esercizio::getDescrizione() + " i altre sborae varie su RiposoPassivo...";
}

Orario RiposoPassivo::getDurata() const {
    return durata;
}

void RiposoPassivo::setDurata(const Orario & o) {
    durata = o;
}

RiposoPassivo * RiposoPassivo::clone() const {
    return new RiposoPassivo(*this);
}

bool RiposoPassivo::operator== (const Esercizio & e) const {
    std::cout << "RiposoPassivo::operator==()" << std::endl;
    return Riposo::operator==(e) && durata == static_cast<const RiposoPassivo&>(e).durata;
}

bool RiposoPassivo::operator!= (const Esercizio & e) const {
    std::cout << "RiposoPassivo::operator!=()" << std::endl;
    return ! (*this == e);
}
