#ifndef MONOESERCIZIO_H
#define MONOESERCIZIO_H

#include "esercizio.h"

class MonoEsercizio : public Esercizio {
private:
    uint MET;

public:
    MonoEsercizio(const string n, const string d, const uint m = 0);
    //MonoEsercizio(const Esercizio & e);
    virtual ~MonoEsercizio() = default;
    uint getMET() const;
    void setMET(const uint & m = 0);
    virtual uint stimaCalorieBruciate() const = 0;
    virtual void incrementaIntensita() = 0;
    virtual void decrementaIntesita() = 0;
    virtual bool operator== (const Esercizio & e) const override;
    virtual bool operator!= (const Esercizio & e) const override;
};

#endif // MONOESERCIZIO_H
