#include "orario.h"

Orario::Orario(const uint secondi, const uint minuti, const uint ore) : sec(secondi + minuti * 60 + ore * 3600) {}

Orario::Orario(const Orario & o) : Orario(o.getSecondi(), o.getMinuti(), o.getOre()) {}

uint Orario::getSecondi() const {
    return sec % 60;
}

uint Orario::getMinuti() const {
    return (sec / 60) % 60;
}

uint Orario::getOre() const {
    return sec / 3600;
}

void Orario::setSecondi(const uint s) {
    sec += (s - getSecondi());
}

void Orario::setMinuti(const uint m) {
    sec += (m - getMinuti()) * 60;
}

void Orario::setOre(const uint o) {
    sec += (o - getOre()) * 3600;
}

bool operator==(const Orario & a, const Orario & b) {
    return a.getOre() == b.getOre() && a.getMinuti() == b.getMinuti() && a.getSecondi() == b.getSecondi();
}

bool operator!=(const Orario & a, const Orario & b) {
    return a.getOre() != b.getOre() || a.getMinuti() != b.getMinuti() || a.getSecondi() != b.getSecondi();
}

Orario & Orario::operator=(const Orario & o) {
    if (this != & o) {
        this->sec = o.sec;
    } else {
        throw std::logic_error("Impossibile assegnare un oggetto a se stesso!");
    }
    return *this;
}

bool operator>(const Orario & a, const Orario & b) {
    if (a.getOre() == b.getOre()) {
        if (a.getMinuti() == b.getMinuti()) {
            return a.getSecondi() > b.getSecondi();
        } else {
            return a.getMinuti() > b.getMinuti();
        }
    } else {
        return a.getOre() > b.getOre();
    }
}

bool operator>=(const Orario & a, const Orario & b) {
    return (a > b) || (a == b);
}

bool operator<(const Orario & a, const Orario & b) {
    return b > a;
}

bool operator<=(const Orario & a, const Orario & b) {
    return b >= a;
}

Orario operator+(const Orario & a, const Orario & b) {
    return Orario(a.getSecondi() + b.getSecondi(), a.getMinuti() + b.getMinuti(), a.getOre() + b.getOre());
}

Orario operator-(const Orario & a, const Orario & b) {
    if (a < b) return Orario(); //azzeramento

    int secondi = a.getSecondi() - b.getSecondi(); //int perchè può andare in negativo (riporto necessario)
    int minuti = a.getMinuti() - b.getMinuti(); //int perchè può andare in negativo (riporto necessario)
    uint ore = a.getOre() - b.getOre(); //non può andare in negativo perchè a >= b

    if (secondi < 0) { //riporto un minuto nei secondi
        secondi += 60;
        minuti--;
    }

    if (minuti < 0) { //riporto un'ora nei minuti
        minuti += 60;
        ore--;
    }

    return Orario(secondi, minuti, ore);
}

std::ostream & operator<<(std::ostream & os, const Orario & o) {
    return os << "(" << o.getOre() << ":" << o.getMinuti() << ":" << o.getSecondi() << ")";
}
