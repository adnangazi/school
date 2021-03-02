#ifndef RIPOSOPASSIVO_H
#define RIPOSOPASSIVO_H

#include "riposo.h"

class RiposoPassivo : public Riposo {
private:
    Orario durata;

public:
    //costruttori e distruttori
    RiposoPassivo(const string & n, const string & d = 0, const string & ir = 0, const Orario & o = 0);
    RiposoPassivo(const RiposoPassivo & e);
    ~RiposoPassivo() = default;

    //overload operatori
    RiposoPassivo & operator=(const RiposoPassivo & e);

    //override Esercizio
    string getDescrizione() const override;
    Orario getDurata() const override;
    void setDurata(const Orario & o = 0) override;
    uint stimaCalorieBruciate() const override;
    void incrementaIntensita() override;
    void decrementaIntesita() override;
    RiposoPassivo * clone() const override;

    bool operator==(const Esercizio & e) const override;
    bool operator!=(const Esercizio & e) const override;
    std::ostream & operator<<(std::ostream & os) const override;
};

#endif // RIPOSOPASSIVO_H
