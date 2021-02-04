#include "creaesercizio.h"

DeepPtr<Esercizio> CreaEsercizio::createCardio(const string & n, const string & d, const uint m, const Orario & o, const uint v) const {
    return DeepPtr<Esercizio>(new Cardio(n, d, m, o, v));
}

DeepPtr<Esercizio> CreaEsercizio::createSollevamentoPesi(const string & n, const string & d, const uint m, const uint p, const uint r, const uint s) const {
    return DeepPtr<Esercizio>(new SollevamentoPesi(n, d, m, p, r, s));
}

DeepPtr<Esercizio> CreaEsercizio::createCrossFit(const string & n, const string & d, const uint m, const Orario & o, const uint v, const uint p) const {
    return DeepPtr<Esercizio>(new CrossFit(n, d, m, o, v, p));
}

DeepPtr<Esercizio> CreaEsercizio::createRiposoPassivo(const string & n, const string & d, const string & ir, const Orario & o) const {
    return DeepPtr<Esercizio>(new RiposoPassivo(n, d, ir, o));
}

DeepPtr<Esercizio> CreaEsercizio::createRiposoAttivo(const string & ir, Esercizio * const e) const {
    return DeepPtr<Esercizio>(new RiposoAttivo(ir, e));
}
