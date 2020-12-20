#include <iostream>
using namespace std;
typedef unsigned int uint;

class Orario {
private:
    uint sec;

public:
    Orario(const uint secondi = 0, const uint minuti = 0, const uint ore = 0) : sec(secondi + minuti * 60 + ore * 3600) {}
    Orario(const Orario & o) : Orario(o.secondi(), o.minuti(), o.ore()) {std::cout << "chiamato!" << endl;}

    uint secondi() const { return sec % 60; }
    uint minuti() const { return (sec / 60) % 60; }
    uint ore() const { return sec / 3600; }

    void incrementaSecondi() { sec++; }
    void incrementaMinuti() { sec += 60; }
    void incrementaOre() { sec += 3600; }

    void decrementaSecondi() {
        if (sec > 0) sec--;
        else sec = 0;
    }
    void decrementaMinuti() {
        if (sec >= 60) sec -= 60;
        else sec = 0;
    }
    void decrementaOre() {
        if (sec >= 3600) sec -= 3600;
        else sec = 0;
    }

    void impostaSecondi(const uint s = 0) { sec += (s - secondi()); }
    void impostaMinuti(const uint m = 0) { sec += (m - minuti()) * 60; }
    void impostaOre(const uint o = 0) { sec += (o - ore()) * 3600; }

    Orario & operator= (const Orario & o);
};

bool operator== (const Orario & a, const Orario & b) { return a.ore() == b.ore() && a.minuti() == b.minuti() && a.secondi() == b.secondi(); }
bool operator!= (const Orario & a, const Orario & b) { return a.ore() != b.ore() || a.minuti() != b.minuti() || a.secondi() != b.secondi(); }

Orario & Orario::operator= (const Orario & o) {
    if (*this != o) {
        this->sec = o.sec;
    }
    return *this;
}

bool operator> (const Orario & a, const Orario & b) {
    if (a.ore() > b.ore()) return true;
    else if (a.ore() < b.ore()) return false;
    else if (a.minuti() > b.minuti()) return true;
    else if (a.minuti() < b.minuti()) return false;
    else return a.secondi() > b.secondi();
}
bool operator>= (const Orario & a, const Orario & b) {return a > b || a == b; }
bool operator< (const Orario & a, const Orario & b) { return b > a;}
bool operator<= (const Orario & a, const Orario & b) { return b >= a; }

Orario operator+ (const Orario & a, const Orario & b) { return Orario(a.secondi() + b.secondi(), a.minuti() + b.minuti(), a.ore() + b.ore()); }
Orario operator- (const Orario & a, const Orario & b) {
    if (a < b) return Orario();

    int secondi = a.secondi() - b.secondi(); //int perchè può andare in negativo (riporto necessario)
    int minuti = a.minuti() - b.minuti(); //int perchè può andare in negativo (riporto necessario)
    uint ore = a.ore() - b.ore(); //non può andare in negativo perchè a >= b

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

std::ostream & operator<< (std::ostream & os, const Orario & o) {
    return os << "Ore: " << o.ore() << ", Minuti: " << o.minuti() << ", Secondi: " << o.secondi() << std::endl;
}

int main() {
    Orario temp(1, 2, 3);
    cout << temp;
    Orario p(temp); //costruttore di copia!
    cout << p;
    p.decrementaOre();
    cout << p;
}