#ifndef CARDIO_H
#define CARDIO_H

#include "monoesercizio.h"

class Cardio : virtual public MonoEsercizio {
private:
    Orario durata;
    uint velocita;

public:
    Cardio(const string n, const string d, const uint m = 0, const Orario & o = 0, const uint & v = 0);
    //Cardio(const Esercizio & e);
    virtual ~Cardio() = default;
    uint getVelocita() const;
    void setVelocita(const uint & v = 0);
    //@override Esercizio
    string getDescrizione() const override;
    Orario getDurata() const override;
    void setDurata(const Orario & o) override;
    //@override MonoEsercizio
    uint stimaCalorieBruciate() const override;
    void incrementaIntensita() override;
    void decrementaIntesita() override;
    Cardio * clone() const override;
};

#endif // CARDIO_H
