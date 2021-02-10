#ifndef RIPOSOATTIVO_H
#define RIPOSOATTIVO_H

#include "riposo.h"
#include "monoesercizio.h"

class RiposoAttivo : public Riposo {
private:
    Esercizio * esercizioAttivo;

public:
    //costruttori e distruttori
    RiposoAttivo(const string & ir = 0, Esercizio * const e = nullptr);
    RiposoAttivo(const RiposoAttivo & e);
    ~RiposoAttivo();

    //metodi della classe
    Esercizio * getEsercizio() const;
    void setEsercizio(Esercizio * const e = 0);
    uint getMET() const;
    void setMET(const uint m = 0);

    //overload operatori
    RiposoAttivo & operator=(const RiposoAttivo & e);

    //override Esercizio
    string getDescrizione() const override;
    Orario getDurata() const override;
    void setDurata(const Orario & o = 0) override;
    uint stimaCalorieBruciate() const override;
    void incrementaIntensita() override;
    void decrementaIntesita() override;
    RiposoAttivo * clone() const override;

    bool operator==(const Esercizio & e) const override;
    bool operator!=(const Esercizio & e) const override;
    std::ostream & operator<<(std::ostream & os) const override;
};

#endif // RIPOSOATTIVO_H
