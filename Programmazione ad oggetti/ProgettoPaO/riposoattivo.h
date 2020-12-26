#ifndef RIPOSOATTIVO_H
#define RIPOSOATTIVO_H

#include "riposo.h"
#include "monoesercizio.h"

class RiposoAttivo : public Riposo {
private:
    Esercizio * esercizioAttivo;

    //metodi privati della classe
    Esercizio & deepCopy(const Esercizio & e);

public:
    //costruttori e distruttori
    RiposoAttivo(const string & ir, const Esercizio * const e = 0);
    RiposoAttivo(const Esercizio & e);
    ~RiposoAttivo() = default;

    //metodi della classe
    Esercizio * getEsercizio() const;
    void setEsercizio(const Esercizio * const e = 0);
    uint getMET() const;
    void setMET(const uint & m = 0);
    uint stimaCalorieBruciate() const;
    void incrementaIntensita();
    void decrementaIntesita();

    //@overload operatori
    Esercizio & operator=(const RiposoAttivo & r);

    //@override Esercizio
    string getDescrizione() const override;
    Orario getDurata() const override;
    void setDurata(const Orario & o) override;
    RiposoAttivo * clone() const override;
    Esercizio & operator=(const Esercizio & e) override;
    bool operator==(const Esercizio & e) const override;
    bool operator!=(const Esercizio & e) const override;
};

#endif // RIPOSOATTIVO_H
