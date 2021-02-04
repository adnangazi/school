#ifndef CROSSFIT_H
#define CROSSFIT_H

#include "cardio.h"
#include "sollevamentopesi.h"

class CrossFit : public Cardio, public SollevamentoPesi {
public:
    //costruttori e distruttori
    CrossFit(const string & n, const string & d, const uint m = 0, const Orario & o = 0, const uint v = 0, const uint p = 0);
    CrossFit(const CrossFit & e);
    ~CrossFit() = default;

    //@override Esercizio
    string getDescrizione() const override;
    Orario getDurata() const override;
    void setDurata(const Orario & o) override;
    uint stimaCalorieBruciate() const override;
    void incrementaIntensita() override;
    void decrementaIntesita() override;
    CrossFit * clone() const override;


    CrossFit & operator=(const CrossFit & e);
    bool operator==(const Esercizio & e) const override;
    bool operator!=(const Esercizio & e) const override;
    std::ostream & operator<<(std::ostream & os) const override;
};

#endif // CROSSFIT_H
