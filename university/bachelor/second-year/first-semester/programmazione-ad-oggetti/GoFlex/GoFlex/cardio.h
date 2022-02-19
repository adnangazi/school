#ifndef CARDIO_H
#define CARDIO_H

#include "monoesercizio.h"

class Cardio : virtual public MonoEsercizio { // base virtuale per via di CrossFit
private:
    Orario durata;
    uint velocita;

public:
    //attributi statici della classe
    static const uint fattoreCalorico;

    //costruttori e distruttori
    Cardio(const string & n, const string & d = "", const uint m = 0, const Orario & o = 0, const uint v = 0);
    Cardio(const Cardio & e);
    ~Cardio() = default;

    //metodi della classe
    uint getVelocita() const;
    void setVelocita(const uint v = 0);

    //overload operatori
    Cardio & operator=(const Cardio & e);

    //override Esercizio
    string getDescrizione() const override;
    Orario getDurata() const override;
    void setDurata(const Orario & o = 0) override;
    uint stimaCalorieBruciate() const override;
    void incrementaIntensita() override;
    void decrementaIntesita() override;

    Cardio * clone() const override;
    bool operator==(const Esercizio & e) const override;
    bool operator!=(const Esercizio & e) const override;
    std::ostream & operator<<(std::ostream & os) const override;
};

#endif // CARDIO_H
