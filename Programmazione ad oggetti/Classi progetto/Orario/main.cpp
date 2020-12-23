#include <iostream>
using namespace std;
typedef unsigned int uint;

class Orario {
private:
    uint sec;

public:
    Orario(const uint secondi = 0, const uint minuti = 0, const uint ore = 0) : sec(secondi + minuti * 60 + ore * 3600) {}
    Orario(const Orario & o) : Orario(o.getSecondi(), o.getMinuti(), o.getOre()) {}

    uint getSecondi() const { return sec % 60; }
    uint getMinuti() const { return (sec / 60) % 60; }
    uint getOre() const { return sec / 3600; }

	//FUNZIONI TOLTE DAL DIAGRAMMA UML DELLE CLASSI: USARE METODI DI SET CON I METODI DI GET + 1
	/*
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
	*/

    void setSecondi(const uint s = 0) { sec += (s - getSecondi()); }
    void setMinuti(const uint m = 0) { sec += (m - getMinuti()) * 60; }
    void setOre(const uint o = 0) { sec += (o - getOre()) * 3600; }

    Orario & operator= (const Orario & o);
};

bool operator== (const Orario & a, const Orario & b) { return a.getOre() == b.getOre() && a.getMinuti() == b.getMinuti() && a.getSecondi() == b.getSecondi(); }
bool operator!= (const Orario & a, const Orario & b) { return a.getOre() != b.getOre() || a.getMinuti() != b.getMinuti() || a.getSecondi() != b.getSecondi(); }

Orario & Orario::operator= (const Orario & o) {
    if (*this != o) {
        this->sec = o.sec;
    }
    return *this;
}

bool operator> (const Orario & a, const Orario & b) {
    if (a.getOre() > b.getOre()) return true;
    else if (a.getOre() < b.getOre()) return false;
    else if (a.getMinuti() > b.getMinuti()) return true;
    else if (a.getMinuti() < b.getMinuti()) return false;
    else return a.getSecondi() > b.getSecondi();
}
bool operator>= (const Orario & a, const Orario & b) {return a > b || a == b; }
bool operator< (const Orario & a, const Orario & b) { return b > a;}
bool operator<= (const Orario & a, const Orario & b) { return b >= a; }

Orario operator+ (const Orario & a, const Orario & b) { return Orario(a.getSecondi() + b.getSecondi(), a.getMinuti() + b.getMinuti(), a.getOre() + b.getOre()); }
Orario operator- (const Orario & a, const Orario & b) {
    if (a < b) return Orario();

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

std::ostream & operator<< (std::ostream & os, const Orario & o) {
	//std::os?
    return os << "Ore: " << o.getOre() << ", Minuti: " << o.getMinuti() << ", Secondi: " << o.getSecondi() << std::endl;
}

int main() {
    Orario temp(1, 2, 3);
    cout << temp;
    Orario p(temp); //costruttore di copia!
    cout << p;
    p.impostaOre(p.getOre() - 1); // == p.decrementaOre()
    cout << p;
}