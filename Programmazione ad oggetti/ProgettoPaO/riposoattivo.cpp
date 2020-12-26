#include "riposoattivo.h"

Esercizio & RiposoAttivo::deepCopy(const Esercizio & e) {
    Riposo::operator=(e);
    const RiposoAttivo * const temp = dynamic_cast<const RiposoAttivo*>(&e);
    if (temp != nullptr) {
        *esercizioAttivo = *temp->esercizioAttivo;
    } else {
        esercizioAttivo = 0;
    }
    return * this;
}

RiposoAttivo::RiposoAttivo(const string & ir, const Esercizio * const e) : Riposo(e->getNome(), e->getDescrizione(), ir), esercizioAttivo((e) ? e->clone() : 0) {}

RiposoAttivo::RiposoAttivo(const Esercizio & e) : Riposo(e) {
    const RiposoAttivo * const temp = dynamic_cast<const RiposoAttivo*>(&e);
    if (temp != nullptr) {
        *esercizioAttivo = *temp->esercizioAttivo;
    } else {
        esercizioAttivo = 0;
    }
}

Esercizio * RiposoAttivo::getEsercizio() const {
    return esercizioAttivo;
}

void RiposoAttivo::setEsercizio(const Esercizio * const e) {
    esercizioAttivo = (e) ? e->clone() : 0;
}

uint RiposoAttivo::getMET() const {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->getMET();
    } else {
        std::cout << "Impossibile restituire il MET: esercizioAttivo non è un sottitipo di Esericizio!" << std::endl;
        return 0;
    }
}

void RiposoAttivo::setMET(const uint & m) {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->setMET(m);
    } else {
        std::cout << "Impossibile impostare il MET: esercizioAttivo non è un sottitipo di Esercizio!" << std::endl;
    }
}

uint RiposoAttivo::stimaCalorieBruciate() const {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->stimaCalorieBruciate();
    } else {
        std::cout << "Impossibile restituire la stima delle colorie bruciate: esercizioAttivo non è un sottitipo di Esercizio!" << std::endl;
        return 0;
    }
}

void RiposoAttivo::incrementaIntensita() {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->incrementaIntensita();
    } else {
        std::cout << "Impossibile incrementare l'intesità: esercizioAttivo non è un sottitipo di Esercizio!" << std::endl;
    }
}

void RiposoAttivo::decrementaIntesita() {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->decrementaIntesita();
    } else {
        std::cout << "Impossibile decrementare l'intesità: esercizioAttivo non è un sottitipo di Esercizio!" << std::endl;
    }
}

//necessario ridefinire operator=() della classe RiposoAttivo: altrimenti viene eseguito una shallow copy dell'oggetto durante l'assegnazione e l'attributo 'esercizioAttivo' dei due oggetti RiposoAttivo usati nell'assegnazione puntano allo stesso oggetto
Esercizio & RiposoAttivo::operator=(const RiposoAttivo & r) {
    return deepCopy(r);
}

std::string RiposoAttivo::getDescrizione() const {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->getDescrizione();
    } else {
        std::cout << "Impossibile restituire la descrzione: esercizioAttivo non è un sottitipo di Esercizio!" << std::endl;
        return "";
    }
}

Orario RiposoAttivo::getDurata() const {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->getDurata();
    } else {
        std::cout << "Impossibile restituire la durata: esercizioAttivo non è un sottitipo di Esercizio!" << std::endl;
        return Orario();
    }
}

void RiposoAttivo::setDurata(const Orario & o) {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->setDurata(o);
    } else {
        std::cout << "Impossibile impostare la durata: esercizioAttivo non è un sottitipo di Esercizio!" << std::endl;
    }
}

RiposoAttivo * RiposoAttivo::clone() const {
    return new RiposoAttivo(*this);
}

Esercizio & RiposoAttivo::operator=(const Esercizio & e) {
    return deepCopy(e);
}

bool RiposoAttivo::operator==(const Esercizio & e) const {
    const RiposoAttivo temp = static_cast<const RiposoAttivo&>(e);
    return getIstruzioneRiposo() == temp.getIstruzioneRiposo() && *esercizioAttivo == *temp.esercizioAttivo;
}

bool RiposoAttivo::operator!=(const Esercizio & e) const {
    return !(*this == e);
}
