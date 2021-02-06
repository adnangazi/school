#include "model.h"

Model::Model() : eseguiEsercizi(new EseguiEsercizi()) {}

Model::~Model() {
    delete eseguiEsercizi;
}

void Model::addCardio(const string & n, const string & d, const uint m, const Orario & o, const uint v) {
    CreaEsercizio creator;
    eseguiEsercizi->addBackEsercizio(creator.createCardio(n, d, m, o, v));
}

void Model::addSollevamentoPesi(const string & n, const string & d, const uint m, const uint p, const uint r, const uint s) {
    CreaEsercizio creator;
    eseguiEsercizi->addBackEsercizio(creator.createSollevamentoPesi(n, d, m, p, r, s));
}

void Model::addCrossFit(const string & n, const string & d, const uint m, const Orario & o, const uint v, const uint p) {
    CreaEsercizio creator;
    eseguiEsercizi->addBackEsercizio(creator.createCrossFit(n, d, m, o, v, p));
}

void Model::addRiposoPassivo(const string & n, const string & d, const string & ir, const Orario & o) {
    CreaEsercizio creator;
    eseguiEsercizi->addBackEsercizio(creator.createRiposoPassivo(n, d, ir, o));
}

void Model::addRiposoAttivo(const string & ir, Esercizio * const e) {
    CreaEsercizio creator;
    eseguiEsercizi->addBackEsercizio(creator.createRiposoAttivo(ir, e));
}

void Model::setCardio(const string & n, const string & d, const uint i, const uint m, const Orario & o, const uint v) {
    CreaEsercizio creator;
    eseguiEsercizi->setEsercizio(creator.createCardio(n, d, m, o, v), i);
}

void Model::setSollevamentoPesi(const string & n, const string & d, const uint i, const uint m, const uint p, const uint r, const uint s) {
    CreaEsercizio creator;
    eseguiEsercizi->setEsercizio(creator.createSollevamentoPesi(n, d, m, p, r, s), i);
}

void Model::setCrossFit(const string & n, const string & d, const uint i, const uint m, const Orario & o, const uint v, const uint p) {
    CreaEsercizio creator;
    eseguiEsercizi->setEsercizio(creator.createCrossFit(n, d, m, o, v, p), i);
}

void Model::setRiposoPassivo(const string & n, const string & d, const string & ir, const uint i, const Orario & o) {
    CreaEsercizio creator;
    eseguiEsercizi->setEsercizio(creator.createRiposoPassivo(n, d, ir, o), i);
}

void Model::setRiposoAttivo(const string & ir, const uint i, Esercizio * const e) {
    CreaEsercizio creator;
    eseguiEsercizi->setEsercizio(creator.createRiposoAttivo(ir, e), i);
}

void Model::removeEsercizio(const uint i) {
    eseguiEsercizi->removeEsercizio(i);
}

DeepPtr<Esercizio> Model::getEsercizio(const uint i) {
    return eseguiEsercizi->getEsercizio(i);
}

DList<DeepPtr<Esercizio> > Model::getEsercizi() const {
    return eseguiEsercizi->getEsercizi();
}

uint Model::getEsercizioCorrente() const {
    return eseguiEsercizi->getEsercizioCorrente();
}

uint Model::getSize() const {
    return eseguiEsercizi->getSize();
}

void Model::previous() {
    eseguiEsercizi->previous();
}

void Model::next() {
    eseguiEsercizi->next();
}

void Model::goToStart() {
    eseguiEsercizi->goToStart();
}

void Model::goToEnd() {
    eseguiEsercizi->goToEnd();
}
