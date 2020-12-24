#include "riposoattivo.h"

RiposoAttivo::RiposoAttivo(const string ir, const Esercizio * const e) : Riposo(e->getNome(), e->getDescrizione(), ir), esercizioAttivo((e) ? e->clone() : 0) {}

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
        std::cout << "Impossibile restituire il MET dell'esercizio: esercizioAttivo non è un Esercizio o un suo sottitipo!" << std::endl;
        return 0;
    }
}

void RiposoAttivo::setMET(const uint & m) {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->setMET(m);
    } else {
        std::cout << "Impossibile impostare il MET dell'esercizio: esercizioAttivo non è un Esercizio o un suo sottitipo!" << std::endl;
    }
}

uint RiposoAttivo::stimaCalorieBruciate() const {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->stimaCalorieBruciate();
    } else {
        std::cout << "Impossibile restituire la stima delle colorie bruciate dell'esercizio: esercizioAttivo non è un Esercizio o un suo sottitipo!" << std::endl;
        return 0;
    }
}

void RiposoAttivo::incrementaIntensita() {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->incrementaIntensita();
    } else {
        std::cout << "Impossibile incrementare l'intesità dell'esercizio: esercizioAttivo non è un Esercizio o un suo sottitipo!" << std::endl;
    }
}

void RiposoAttivo::decrementaIntesita() {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->decrementaIntesita();
    } else {
        std::cout << "Impossibile decrementare l'intesità dell'esercizio: esercizioAttivo non è un Esercizio o un suo sottitipo!" << std::endl;
    }
}

std::string RiposoAttivo::getDescrizione() const {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->getDescrizione();
    } else {
        std::cout << "Impossibile restituire la descrzione dell'esercizio: esercizioAttivo non è un Esercizio o un suo sottitipo!" << std::endl;
        return " ";
    }
}

Orario RiposoAttivo::getDurata() const {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        return temp->getDurata();
    } else {
        std::cout << "Impossibile restituire la durata dell'esercizio: esercizioAttivo non è un Esercizio o un suo sottitipo!" << std::endl;
        return Orario();
    }
}

void RiposoAttivo::setDurata(const Orario & o) {
    MonoEsercizio * temp = dynamic_cast<MonoEsercizio*>(esercizioAttivo);
    if (temp) {
        temp->setDurata(o);
    } else {
        std::cout << "Impossibile impostare la durata dell'esercizio: esercizioAttivo non è un Esercizio o un suo sottitipo!" << std::endl;
    }
}

RiposoAttivo * RiposoAttivo::clone() const {
    return new RiposoAttivo(*this);
}

bool RiposoAttivo::operator== (const Esercizio & e) const {
    std::cout << "RiposoAttivo::operator==()" << std::endl;
    RiposoAttivo temp = static_cast<const RiposoAttivo&>(e);
    return getIstruzioneRiposo() == temp.getIstruzioneRiposo() && *esercizioAttivo == *temp.esercizioAttivo;
}

bool RiposoAttivo::operator!= (const Esercizio & e) const {
    std::cout << "RiposoAttivo::operator!=()" << std::endl;
    return ! (*this == e);
}
