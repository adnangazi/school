#include "riposopassivo.h"

RiposoPassivo::RiposoPassivo(const string n, const string d, const Orario & o) : Riposo(n, d), durata(o) {}

string RiposoPassivo::getDescrizione() const {
    return Esercizio::getDescrizione() + " i altre sborae varie su RiposoPassivo...";
}

Orario RiposoPassivo::getDurata() const {
    return durata;
}

void RiposoPassivo::setDurata(const Orario & o) {
    durata = o;
}

RiposoPassivo *RiposoPassivo::clone() const {
    return new RiposoPassivo(*this);
}
