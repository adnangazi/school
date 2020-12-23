#ifndef RIPOSO_H
#define RIPOSO_H

#include "esercizio.h"

class Riposo : public Esercizio {
public:
    Riposo(const string n, const string d);
    virtual ~Riposo() = default;
};

#endif // RIPOSO_H
