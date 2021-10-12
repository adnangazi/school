#include "riposo.h"

Riposo::Riposo(const string & n, const string & d, const string & ir) : Esercizio(n, d), istruzioneRiposo(ir) {}

Riposo::Riposo(const Riposo & e) : Esercizio(e), istruzioneRiposo(e.istruzioneRiposo) {}

string Riposo::getIstruzioneRiposo() const {
    return istruzioneRiposo;
}

void Riposo::setIstruzioneRiposo(const string & ir) {
    istruzioneRiposo = ir;
}

Riposo & Riposo::operator=(const Riposo & e) {
    Esercizio::operator=(e);
    istruzioneRiposo = e.istruzioneRiposo;
    return * this;
}

bool Riposo::operator==(const Esercizio & e) const {
    return Esercizio::operator==(e) && istruzioneRiposo == static_cast<const Riposo*>(&e)->istruzioneRiposo;
    //istruzioneRiposo == static_cast<const Riposo*>(&e)->istruzioneRiposo è un controllo sicuro nonostante lo static_cast, per via del controllo del tipo dinamico fatto in Esercizio::operator==(e)
}

bool Riposo::operator!=(const Esercizio & e) const {
    return !(*this == e);
}

std::ostream & Riposo::operator<<(std::ostream & os) const {
    Esercizio::operator<<(os) << std::endl;
    os << " | Istruzioni riposo: " << istruzioneRiposo;
    return os;
}
