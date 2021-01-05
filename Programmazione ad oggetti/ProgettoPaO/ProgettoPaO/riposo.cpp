#include "riposo.h"

Riposo::Riposo(const string & n, const string & d, const string & ir) : Esercizio(n, d), istruzioneRiposo(ir) {}

Riposo::Riposo(const Esercizio & e) : Esercizio(e) {
    const Riposo * const temp = dynamic_cast<const Riposo*>(&e);
    if (temp != nullptr) {
        istruzioneRiposo = temp->istruzioneRiposo;
    } else {
        istruzioneRiposo = "";
    }
}

string Riposo::getIstruzioneRiposo() const {
    return istruzioneRiposo;
}

void Riposo::setIstruzioneRiposo(const string & ir) {
    istruzioneRiposo = ir;
}

Esercizio & Riposo::operator=(const Esercizio & e) {
    Esercizio::operator=(e);
    const Riposo * const temp = dynamic_cast<const Riposo*>(&e);
    if (temp != nullptr) {
        istruzioneRiposo = temp->istruzioneRiposo;
    } else {
        istruzioneRiposo = "";
    }
    return *this;
}

bool Riposo::operator==(const Esercizio & e) const {
    return Esercizio::operator==(e) && istruzioneRiposo == static_cast<const Riposo&>(e).istruzioneRiposo;
}

bool Riposo::operator!=(const Esercizio & e) const {
    return !(*this == e);
}
