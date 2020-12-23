#ifndef CROSSFIT_H
#define CROSSFIT_H

#include "cardio.h"
#include "sollevamentopesi.h"

class CrossFit : public Cardio, public SollevamentoPesi {
public:
    CrossFit(const string n, const string d, const uint m = 0, const Orario & o = 0, const uint & v = 0, const uint & p = 0);
    //CrossFit(const Esercizio & e);
    ~CrossFit() = default;
    //@override Esercizio
    string getDescrizione() const override;
    Orario getDurata() const override;
    void setDurata(const Orario & o) override;
    //@override MonoEsercizio
    uint stimaCalorieBruciate() const override;
    void incrementaIntensita() override;
    void decrementaIntesita() override;
    CrossFit * clone() const override;
};

#endif // CROSSFIT_H
