#ifndef ESERCIZIO_H
#define ESERCIZIO_H

#include <typeinfo>
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
    virtual Esercizio * clone() const = 0;

    //@overload operatori
    virtual Esercizio & operator=(const Esercizio & e);
    virtual bool operator==(const Esercizio & e) const;
    virtual bool operator!=(const Esercizio & e) const;
    Esercizio * operator+(const Esercizio & e) const;
    Esercizio * operator-(const Esercizio & e) const;
};

#endif // ESERCIZIO_H
