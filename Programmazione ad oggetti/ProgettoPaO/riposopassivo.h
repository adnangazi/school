#ifndef RIPOSOPASSIVO_H
#define RIPOSOPASSIVO_H

#include "riposo.h"

class RiposoPassivo : public Riposo {
private:
    Orario durata;

public:
    RiposoPassivo(const string n, const string d, const string ir,const Orario & o = 0);
    //RiposoPassivo(const Esercizio & e);
    ~RiposoPassivo() = default;
    //@override Esercizio
    string getDescrizione() const override;
    Orario getDurata() const override;
    void setDurata(const Orario & o) override;
    RiposoPassivo * clone() const override;
    bool operator== (const Esercizio & e) const override;
    bool operator!= (const Esercizio & e) const override;
};

#endif // RIPOSOPASSIVO_H
