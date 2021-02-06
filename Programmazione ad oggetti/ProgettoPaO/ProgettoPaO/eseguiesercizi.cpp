#include "eseguiesercizi.h"

EseguiEsercizi::EseguiEsercizi() : esercizioCorrente(0), esercizi() {}

void EseguiEsercizi::addEsercizio(DeepPtr<Esercizio> e, const uint i) {
    if (i <= esercizioCorrente) {
        next();
    }
    esercizi.push(e, i);
}

void EseguiEsercizi::addBackEsercizio(DeepPtr<Esercizio> e) {
    esercizi.pushBack(e);
}

void EseguiEsercizi::setEsercizio(DeepPtr<Esercizio> e, const uint i) {
    if (esercizi.isEmpty()) {
        throw std::out_of_range("Impossibile fare set in una lista vuota!");
    }
    if (i >= esercizi.getSize()) {
        throw std::out_of_range("Index out of bound!");
    }
    esercizi.set(e, i);
}

DeepPtr<Esercizio> EseguiEsercizi::removeEsercizio(const uint i) {
    if (esercizi.isEmpty()) {
        throw std::out_of_range("Impossibile fare remove in una lista vuota!");
    }
    if (i < esercizioCorrente) {
        previous();
    }
    if (i == esercizi.getSize() - 1) {
        goToStart();
    }
    return esercizi.pop(i);
}

DeepPtr<Esercizio> EseguiEsercizi::getEsercizio(const uint i) {
    if (esercizi.isEmpty()) {
        throw std::out_of_range("Impossibile fare get in una lista vuota!");
    }
    return esercizi[i >= esercizi.getSize() ? esercizi.getSize() - 1 : i];
}

DList<DeepPtr<Esercizio>> EseguiEsercizi::getEsercizi() const {
    return esercizi;
}

uint EseguiEsercizi::getEsercizioCorrente() const {
    return esercizioCorrente;
}

uint EseguiEsercizi::getSize() const {
    return esercizi.getSize();
}

void EseguiEsercizi::previous() {
    if (esercizioCorrente > 0) {
        esercizioCorrente--;
    }
}

void EseguiEsercizi::next() {
    if (esercizioCorrente < esercizi.getSize() - 1) {
        esercizioCorrente++;
    } else {
        goToStart();
    }
}

void EseguiEsercizi::goToStart() {
    esercizioCorrente = 0;
}

void EseguiEsercizi::goToEnd() {
    esercizioCorrente = esercizi.getSize() - 1;
}
