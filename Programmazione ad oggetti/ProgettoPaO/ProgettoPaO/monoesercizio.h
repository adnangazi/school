#ifndef MONOESERCIZIO_H
#define MONOESERCIZIO_H

#include "esercizio.h"

class MonoEsercizio : public Esercizio {
private:
    uint MET;

public:
    //costruttori e distruttori
    MonoEsercizio(const string & n, const string & d, const uint m = 0);
    MonoEsercizio(const MonoEsercizio & e);
    virtual ~MonoEsercizio() = default;

    //metodi della classe
    uint getMET() const;
    void setMET(const uint m = 0);

    //@override Esercizio
    MonoEsercizio & operator=(const MonoEsercizio & e);
    virtual bool operator==(const Esercizio & e) const override;
    virtual bool operator!=(const Esercizio & e) const override;
    virtual std::ostream & operator<<(std::ostream & os) const override;
};

#endif // MONOESERCIZIO_H
