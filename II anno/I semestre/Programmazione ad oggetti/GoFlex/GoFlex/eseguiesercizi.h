#ifndef ESEGUIESERCIZI_H
#define ESEGUIESERCIZI_H

#include "dlist.h"
#include "deepptr.h"
#include "esercizio.h"

class EseguiEsercizi {
private:
    uint esercizioCorrente;
    DList<DeepPtr<Esercizio>> esercizi;

public:
    //costruttori
    EseguiEsercizi();

    //metodi della classe
    void addEsercizio(DeepPtr<Esercizio> e, const uint i = 0);
    void addBackEsercizio(DeepPtr<Esercizio> e);
    void setEsercizio(DeepPtr<Esercizio> e, const uint i);
    DeepPtr<Esercizio> removeEsercizio(const uint i);
    DeepPtr<Esercizio> getEsercizio(const uint i);

    DList<DeepPtr<Esercizio>> getEsercizi() const;
    uint getEsercizioCorrente() const;
    uint getSize() const;
    void previous();
    void next();
    void goToStart();
    void goToEnd();
};

#endif // ESEGUIESERCIZI_H
