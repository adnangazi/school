#ifndef CREAESERCIZIO_H
#define CREAESERCIZIO_H

#include "deepptr.h"
#include "crossfit.h"
#include "riposopassivo.h"
#include "riposoattivo.h"

class CreaEsercizio {
public:
    DeepPtr<Esercizio> createCardio(const string & n, const string & d, const uint m = 0, const Orario & o = 0, const uint v = 0) const;
    DeepPtr<Esercizio> createSollevamentoPesi(const string & n, const string & d, const uint m = 0, const uint p = 0, const uint r = 0, const uint s = 0) const;
    DeepPtr<Esercizio> createCrossFit(const string & n, const string & d, const uint m = 0, const Orario & o = 0, const uint v = 0, const uint p = 0) const;
    DeepPtr<Esercizio> createRiposoPassivo(const string & n, const string & d, const string & ir,const Orario & o = 0) const;
    DeepPtr<Esercizio> createRiposoAttivo(const string & ir, Esercizio * const e = 0) const;
};

#endif // CREAESERCIZIO_H
