#ifndef ESERCIZIO_H
#define ESERCIZIO_H

#include "orario.h"
using std::string;

class Esercizio {
private:
    string nome;
    string descrizione;

public:
    //costruttori e distruttori
    Esercizio(const string & n, const string & d);
    Esercizio(const Esercizio & e);
    virtual ~Esercizio() = default;

    //metodi della classe
    string getNome() const;
    void setNome(const string & n);
    virtual string getDescrizione() const;
    void setDescrizione(const string & d);

    //metodi virtuali puri
    virtual Orario getDurata() const = 0;
    virtual void setDurata(const Orario & = 0) = 0;
    virtual uint stimaCalorieBruciate() const = 0;
    virtual void incrementaIntensita() = 0;
    virtual void decrementaIntesita() = 0;
    virtual Esercizio * clone() const = 0;

    //@overload operatori
    Esercizio & operator=(const Esercizio & e);
    virtual bool operator==(const Esercizio & e) const;
    virtual bool operator!=(const Esercizio & e) const;
    virtual std::ostream & operator<<(std::ostream & os) const;
};

#endif // ESERCIZIO_H
