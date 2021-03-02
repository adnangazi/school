#ifndef ORARIO_H
#define ORARIO_H

#include <ostream>
typedef unsigned int uint;

class Orario {
private:
    uint sec;

public:
    //costruttori
    Orario(const uint secondi = 0, const uint minuti = 0, const uint ore = 0);
    Orario(const Orario & o);

    //metodi della classe
    uint getSecondi() const;
    uint getMinuti() const;
    uint getOre() const;
    void setSecondi(const uint s = 0);
    void setMinuti(const uint m = 0);
    void setOre(const uint o = 0);

    //overload operatori interni alla classe
    Orario & operator=(const Orario & o);
};

//overload operatori esterni alla classe
bool operator==(const Orario & a, const Orario & b);
bool operator!=(const Orario & a, const Orario & b);
bool operator>(const Orario & a, const Orario & b);
bool operator>=(const Orario & a, const Orario & b);
bool operator<(const Orario & a, const Orario & b);
bool operator<=(const Orario & a, const Orario & b);
Orario operator+(const Orario & a, const Orario & b);
Orario operator-(const Orario & a, const Orario & b);
std::ostream & operator<<(std::ostream & os, const Orario & o);

#endif // ORARIO_H
