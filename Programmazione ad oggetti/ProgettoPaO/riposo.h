#ifndef RIPOSO_H
#define RIPOSO_H

#include "esercizio.h"

class Riposo : public Esercizio {
private:
    string istruzioneRiposo;

public:
    Riposo(const string n, const string d, string ir);
    virtual ~Riposo() = default;
    string getIstruzioneRiposo() const;
    void setIstruzioneRiposo(const string ir);
    virtual bool operator== (const Esercizio & e) const override;
    virtual bool operator!= (const Esercizio & e) const override;
};

#endif // RIPOSO_H
