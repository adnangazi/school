#include "riposopassivo.h"

RiposoPassivo::RiposoPassivo(const string & n, const string & d, const string & ir, const Orario & o) : Riposo(n, d, ir), durata(o) {}

RiposoPassivo::RiposoPassivo(const Esercizio & e) : Riposo(e) {
    const RiposoPassivo * const temp = dynamic_cast<const RiposoPassivo*>(&e);
    if (temp) {
        durata = temp->durata;
    } else {
        durata = Orario();
    }
}

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

Esercizio & RiposoPassivo::operator=(const Esercizio & e) {
    Riposo::operator=(e);
    const RiposoPassivo * const temp = dynamic_cast<const RiposoPassivo*>(&e);
    if (temp) {
        durata = temp->durata;
    } else {
        durata = Orario();
    }
    return * this;
}

bool RiposoPassivo::operator==(const Esercizio & e) const {
    return Riposo::operator==(e) && durata == static_cast<const RiposoPassivo&>(e).durata;
}

bool RiposoPassivo::operator!=(const Esercizio & e) const {
    return !(*this == e);
}
