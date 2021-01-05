#ifndef RIPOSO_H
#define RIPOSO_H

#include "esercizio.h"

class Riposo : public Esercizio {
private:
    string istruzioneRiposo;

public:
    //costruttori e distruttori
    Riposo(const string & n, const string & d, const string & ir);
    Riposo(const Esercizio & e);
    virtual ~Riposo() = default;

    //metodi della classe
    string getIstruzioneRiposo() const;
    void setIstruzioneRiposo(const string & ir);

    //@override Esericizio
    virtual Esercizio & operator=(const Esercizio & e) override;
    virtual bool operator==(const Esercizio & e) const override;
    virtual bool operator!=(const Esercizio & e) const override;
};

#endif // RIPOSO_H
