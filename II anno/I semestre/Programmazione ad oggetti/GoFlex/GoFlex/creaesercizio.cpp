#include "creaesercizio.h"

DeepPtr<Esercizio> CreaEsercizio::createCardio(const string & n, const string & d, const uint m, const Orario & o, const uint v) {
    return DeepPtr<Esercizio>(new Cardio(n, d, m, o, v));
}

DeepPtr<Esercizio> CreaEsercizio::createSollevamentoPesi(const string & n, const string & d, const uint m, const uint p, const uint r, const uint s) {
    return DeepPtr<Esercizio>(new SollevamentoPesi(n, d, m, p, r, s));
}

DeepPtr<Esercizio> CreaEsercizio::createCrossFit(const string & n, const string & d, const uint m, const Orario & o, const uint v, const uint p) {
    return DeepPtr<Esercizio>(new CrossFit(n, d, m, o, v, p));
}

DeepPtr<Esercizio> CreaEsercizio::createRiposoPassivo(const string & n, const string & d, const string & ir, const Orario & o) {
    return DeepPtr<Esercizio>(new RiposoPassivo(n, d, ir, o));
}

DeepPtr<Esercizio> CreaEsercizio::createRiposoAttivo(const string & ir, Esercizio * const e) {
    return DeepPtr<Esercizio>(new RiposoAttivo(ir, e));
}
