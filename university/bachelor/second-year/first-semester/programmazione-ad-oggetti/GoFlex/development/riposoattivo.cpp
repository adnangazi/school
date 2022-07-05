#include "riposoattivo.h"

RiposoAttivo::RiposoAttivo(const string & ir, Esercizio * const e) : Riposo(e->getNome(), e->getDescrizione(), ir), esercizioAttivo((e) ? e->clone() : nullptr) {}

RiposoAttivo::RiposoAttivo(const RiposoAttivo & e) : Riposo(e), esercizioAttivo(e.esercizioAttivo ? e.esercizioAttivo->clone() : nullptr) {}

RiposoAttivo::~RiposoAttivo() {
    delete esercizioAttivo;
}

Esercizio * RiposoAttivo::getEsercizio() const {
    return esercizioAttivo;
}

void RiposoAttivo::setEsercizio(Esercizio * const e) {
    esercizioAttivo = (e) ? e->clone() : 0;
}

uint RiposoAttivo::getMET() const {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->getMET();
    } else {
        throw std::runtime_error("Impossibile restituire il MET: esercizioAttivo non è un sottitipo di Esericizio!");
    }
}

void RiposoAttivo::setMET(const uint m) {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->setMET(m);
    } else {
        throw std::runtime_error("Impossibile impostare il MET: esercizioAttivo non è un sottitipo di Esericizio!");
    }
}

//necessario ridefinire operator=() della classe RiposoAttivo: altrimenti viene eseguito una shallow copy dell'oggetto durante l'assegnazione e l'attributo 'esercizioAttivo' dei due oggetti RiposoAttivo usati nell'assegnazione puntano allo stesso oggetto
RiposoAttivo & RiposoAttivo::operator=(const RiposoAttivo & e) {
    Riposo::operator=(e);
    esercizioAttivo = e.esercizioAttivo ? e.esercizioAttivo->clone() : nullptr;
    return * this;
}

std::string RiposoAttivo::getDescrizione() const {
    MonoEsercizio * const temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->getDescrizione();
    } else {
        throw std::runtime_error("Impossibile restituire la descrzione: esercizioAttivo non è un sottitipo di Esercizio!");
    }
}

Orario RiposoAttivo::getDurata() const {
    MonoEsercizio * const temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->getDurata();
    } else {
        throw std::runtime_error("Impossibile restituire la durata: esercizioAttivo non è un sottitipo di Esercizio!");
    }
}

void RiposoAttivo::setDurata(const Orario & o) {
    MonoEsercizio * const temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->setDurata(o);
    } else {
        throw std::runtime_error("Impossibile impostare la durata: esercizioAttivo non è un sottitipo di Esercizio!");
    }
}

uint RiposoAttivo::stimaCalorieBruciate() const {
    MonoEsercizio * const temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->stimaCalorieBruciate();
    } else {
        throw std::runtime_error("Impossibile restituire la stima delle colorie bruciate: esercizioAttivo non è un sottitipo di Esercizio!");
    }
}

void RiposoAttivo::incrementaIntensita() {
    MonoEsercizio * const temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->incrementaIntensita();
    } else {
        throw std::runtime_error("Impossibile incrementare l'intesita': esercizioAttivo non è un sottitipo di Esercizio!");
    }
}

void RiposoAttivo::decrementaIntesita() {
    MonoEsercizio * const temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->decrementaIntesita();
    } else {
        throw std::runtime_error("Impossibile decrementare l'intesita': esercizioAttivo non è un sottitipo di Esercizio!");
    }
}

RiposoAttivo * RiposoAttivo::clone() const {
    return new RiposoAttivo(*this);
}

bool RiposoAttivo::operator==(const Esercizio & e) const {
    const RiposoAttivo * const temp = static_cast<const RiposoAttivo*>(&e);
    return getIstruzioneRiposo() == temp->getIstruzioneRiposo() && (temp->esercizioAttivo != nullptr && esercizioAttivo != nullptr ? *(temp->esercizioAttivo) == *esercizioAttivo : temp->esercizioAttivo == esercizioAttivo);
}

bool RiposoAttivo::operator!=(const Esercizio & e) const {
    return !(*this == e);
}

std::ostream & RiposoAttivo::operator<<(std::ostream & os) const {
    Riposo::operator<<(os) << std::endl;
    os << " | Descrizione: " << getDescrizione() << std::endl;
    os << " | MET: " << getMET() << std::endl;
    os << " +---";
    return os;
}
