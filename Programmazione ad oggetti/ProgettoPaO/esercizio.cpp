#include "esercizio.h"

Esercizio::Esercizio(const string n, const string d) : nome(n), descrizione(d) {}

Esercizio::Esercizio(const Esercizio & e) : Esercizio(e.getNome(), e.getDescrizione()) {}

string Esercizio::getNome() const {
    return nome;
}

void Esercizio::setNome(const string n) {
    nome = n;
}

string Esercizio::getDescrizione() const {
    return descrizione;
}

void Esercizio::setDescrizione(const string d) {
    descrizione = d;
}
