#include "riposo.h"

Riposo::Riposo(const string n, const string d, const string ir) : Esercizio(n, d), istruzioneRiposo(ir) {}

string Riposo::getIstruzioneRiposo() const {
    return istruzioneRiposo;
}

void Riposo::setIstruzioneRiposo(const string ir) {
    istruzioneRiposo = ir;
}

bool Riposo::operator== (const Esercizio & e) const {
    std::cout << "Riposo::operator==()" << std::endl;
    return Esercizio::operator==(e) && istruzioneRiposo == static_cast<const Riposo&>(e).istruzioneRiposo;
}

bool Riposo::operator!= (const Esercizio & e) const {
    std::cout << "Riposo::operator!=()" << std::endl;
    return ! (*this == e);
}
