#ifndef MODEL_H
#define MODEL_H

#include "eseguiesercizi.h"
#include "creaesercizio.h"

class Model {
private:
    EseguiEsercizi * eseguiEsercizi;

public:
    //costruttori e distruttori
    Model();
    ~Model();

    //metodi della classe
    void addCardio(const string & n, const string & d = "", const uint m = 0, const Orario & o = 0, const uint v = 0);
    void addSollevamentoPesi(const string & n, const string & d = "", const uint m = 0, const uint p = 0, const uint r = 0, const uint s = 0);
    void addCrossFit(const string & n, const string & d = "", const uint m = 0, const Orario & o = 0, const uint v = 0, const uint p = 0);
    void addRiposoPassivo(const string & n, const string & d = "", const string & ir = "", const Orario & o = 0);
    void addRiposoAttivo(const string & ir = "", Esercizio * const e = 0);

    void setEsercizio(DeepPtr<Esercizio> e, const uint i);
    void removeEsercizio(const uint i);
    DeepPtr<Esercizio> getEsercizio(const uint i);

    DList<DeepPtr<Esercizio>> getEsercizi() const;
    uint getEsercizioCorrente() const;
    uint getSize() const;
    void previous();
    void next();
    void goToStart();
    void goToEnd();
};

#endif // MODEL_H
