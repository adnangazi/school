#include "esercizio.h"

Esercizio::Esercizio(const string & n, const string & d) : nome(n), descrizione(d) {}

Esercizio::Esercizio(const Esercizio & e) : Esercizio(e.nome, e.descrizione) {}

string Esercizio::getNome() const {
    return nome;
}

void Esercizio::setNome(const string & n) {
    nome = n;
}

string Esercizio::getDescrizione() const {
    return descrizione;
}

void Esercizio::setDescrizione(const string & d) {
    descrizione = d;
}

Esercizio & Esercizio::operator=(const Esercizio & e) {
    if (this != & e) {
        nome = e.nome;
        descrizione = e.descrizione;
    } else {
        throw std::logic_error("Impossibile assegnare un oggetto a se stesso!");
    }
    return * this;
}

bool Esercizio::operator==(const Esercizio & e) const {
    return typeid(*this) == typeid(e) && nome == e.nome && descrizione == e.descrizione;
}

bool Esercizio::operator!=(const Esercizio & e) const {
    return !(*this == e);
}

std::ostream & Esercizio::operator<<(std::ostream & os) const {
    os << " +---" << std::endl;
    os << " | Nome: " << nome << std::endl;
    os << " | Durata: " << getDurata() << std::endl;
    os << " | Calorie bruciate: " << stimaCalorieBruciate();
    return os;
}
