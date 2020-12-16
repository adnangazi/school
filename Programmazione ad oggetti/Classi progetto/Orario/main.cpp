#include <iostream>
using namespace std;
typedef unsigned int uint;

class Orario {
private:
    uint sec;

public:
    Orario(const uint secondi = 0, const uint minuti = 0, const uint ore = 0) : sec(secondi + minuti * 60 + ore * 3600) {}
    Orario(const Orario & o) : Orario(o.Secondi(), o.Minuti(), o.Ore()) {std::cout << "chiamato!" << endl;}

    uint Secondi() const { return sec % 60; }
    uint Minuti() const { return (sec / 60) % 60; }
    uint Ore() const { return sec / 3600; }

    void IncrementaSecondi() { sec++; }
    void IncrementaMinuti() { sec += 60; }
    void IncrementaOre() { sec += 3600; }

    void DecrementaSecondi() {
        if (sec > 0) sec--;
        else sec = 0;
    }
    void DecrementaMinuti() {
        if (sec >= 60) sec -= 60;
        else sec = 0;
    }
    void DecrementaOre() {
        if (sec >= 3600) sec -= 3600;
        else sec = 0;
    }

    void ImpostaSecondi(const uint secondi = 0) { sec -= (Secondi() - secondi); }
    void ImpostaMinuti(const uint minuti = 0) { sec -= (Minuti() - minuti) * 60; }
    void ImpostaOre(const uint ore = 0) { sec -= (Ore() - ore) * 3600; }

    Orario & operator= (const Orario & o);
};

bool operator== (const Orario & a, const Orario & b) { return a.Ore() == b.Ore() && a.Minuti() == b.Minuti() && a.Secondi() == b.Secondi(); }
bool operator!= (const Orario & a, const Orario & b) { return a.Ore() != b.Ore() || a.Minuti() != b.Minuti() || a.Secondi() != b.Secondi(); }

Orario & Orario::operator= (const Orario & o) {
    if (*this != o) {
        *this = o;
    }
    return *this;
}

bool operator> (const Orario & a, const Orario & b) {
    if (a.Ore() > b.Ore()) return true;
    else if (a.Ore() < b.Ore()) return false;
    else if (a.Minuti() > b.Minuti()) return true;
    else if (a.Minuti() < b.Minuti()) return false;
    else return a.Secondi() > b.Secondi();
}
bool operator>= (const Orario & a, const Orario & b) {return a > b || a == b; }
bool operator< (const Orario & a, const Orario & b) { return b > a;}
bool operator<= (const Orario & a, const Orario & b) { return b >= a; }

Orario operator+ (const Orario & a, const Orario & b) { return Orario(a.Secondi() + b.Secondi(), a.Minuti() + b.Minuti(), a.Ore() + b.Ore()); }
Orario operator- (const Orario & a, const Orario & b) {
    if (a < b) return Orario();

    int secondi = a.Secondi() - b.Secondi(); //int perchè può andare in negativo (riporto necessario)
    int minuti = a.Minuti() - b.Minuti(); //int perchè può andare in negativo (riporto necessario)
    uint ore = a.Ore() - b.Ore(); //non può andare in negativo perchè a >= b

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
    return os << "Ore: " << o.Ore() << ", Minuti: " << o.Minuti() << ", Secondi: " << o.Secondi() << std::endl;
}

template <class T>
class DeepPtr {
private:
    T * ptr;

public:
    DeepPtr(T * p = 0) : ptr(p) {}

    ~DeepPtr() {
        delete ptr;
    }

    DeepPtr(const DeepPtr<T> & dp) : ptr(dp.ptr) {cout << "qua" << endl;}

    /*DeepPtr<T> & operator= (const DeepPtr<T> & dp) {
        if (this != & dp) {
            delete ptr;
            //ptr = dp.ptr;
            *this = DeepPtr(dp);
        }
        return * this;
    }*/

    void prova() {
        cout << *ptr << endl;
    }
};

int main() {
    int * a = new int(10);
    int * b = new int(20);

    DeepPtr<int> x(a);
    DeepPtr<int> y(b);

    x.prova();
    y.prova();

    cout << endl;

    x = y;

    x.prova();
    y.prova();
}