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
    esercizi.set(e, i);
}

DeepPtr<Esercizio> EseguiEsercizi::removeEsercizio(const uint i) {
    if (i < esercizioCorrente) {
        previous();
    }
    if (i == esercizi.getSize() - 1) {
        goToStart();
    }
    return esercizi.pop(i);
}

DeepPtr<Esercizio> EseguiEsercizi::getEsercizio(const uint i) {
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
    esercizioCorrente = esercizi.getSize() == 0 ? 0 : esercizi.getSize() - 1;
}
