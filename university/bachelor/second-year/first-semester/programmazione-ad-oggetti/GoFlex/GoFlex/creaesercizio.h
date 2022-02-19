#ifndef CREAESERCIZIO_H
#define CREAESERCIZIO_H

#include "deepptr.h"
#include "crossfit.h"
#include "riposopassivo.h"
#include "riposoattivo.h"

class CreaEsercizio {
public:
    //metodi della classe
    static DeepPtr<Esercizio> createCardio(const string & n, const string & d = "", const uint m = 0, const Orario & o = 0, const uint v = 0);
    static DeepPtr<Esercizio> createSollevamentoPesi(const string & n, const string & d = "", const uint m = 0, const uint p = 0, const uint r = 0, const uint s = 0);
    static DeepPtr<Esercizio> createCrossFit(const string & n, const string & d = "", const uint m = 0, const Orario & o = 0, const uint v = 0, const uint p = 0);
    static DeepPtr<Esercizio> createRiposoPassivo(const string & n, const string & d = "", const string & ir = "",const Orario & o = 0);
    static DeepPtr<Esercizio> createRiposoAttivo(const string & ir = "", Esercizio * const e = 0);
};

#endif // CREAESERCIZIO_H
