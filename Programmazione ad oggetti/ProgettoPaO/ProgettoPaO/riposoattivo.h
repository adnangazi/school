#ifndef RIPOSOATTIVO_H
#define RIPOSOATTIVO_H

#include "riposo.h"
#include "monoesercizio.h"

class RiposoAttivo : public Riposo {
private:
    Esercizio * esercizioAttivo;

    //metodi privati della classe
    static void deepCopy(const Esercizio & e, Esercizio *& esercizioAttivo);

public:
    //costruttori e distruttori
    RiposoAttivo(const string & ir, Esercizio * const e = 0);
    RiposoAttivo(const Esercizio & e);
    ~RiposoAttivo();

    //metodi della classe
    Esercizio * getEsercizio() const;
    void setEsercizio(Esercizio * const e = 0);
    uint getMET() const;
    void setMET(const uint m = 0);

    //@overload operatori
    Esercizio & operator=(const RiposoAttivo & r);

    //@override Esercizio
    string getDescrizione() const override;
    Orario getDurata() const override;
    void setDurata(const Orario & o) override;
    uint stimaCalorieBruciate() const override;
    void incrementaIntensita() override;
    void decrementaIntesita() override;
    RiposoAttivo * clone() const override;
    Esercizio & operator=(const Esercizio & e) override;
    bool operator==(const Esercizio & e) const override;
    bool operator!=(const Esercizio & e) const override;
    std::ostream & operator<<(std::ostream & os) const override;
};

#endif // RIPOSOATTIVO_H
