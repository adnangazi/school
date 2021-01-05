#ifndef SOLLEVAMENTOPESI_H
#define SOLLEVAMENTOPESI_H

#include <cmath>
#include "monoesercizio.h"

class SollevamentoPesi : virtual public MonoEsercizio {
private:
    uint peso;
    uint ripetizioni;
    uint serie;

public:
    //attributi statici della classe
    static const Orario tempoDiRipetizione;

    //costruttori e distruttori
    SollevamentoPesi(const string & n, const string & d, const uint m = 0, const uint p = 0, const uint r = 0, const uint s = 0);
    SollevamentoPesi(const Esercizio & e);
    ~SollevamentoPesi() = default;

    //metodi della classe
    uint getPeso() const;
    void setPeso(const uint p = 0);
    uint getRipetizioni() const;
    void setRipetizioni(const uint r = 0);
    uint getSerie() const;
    void setSerie(const uint s = 0);

    //@override Esercizio
    string getDescrizione() const override;
    Orario getDurata() const override;
    void setDurata(const Orario & o) override;
    uint stimaCalorieBruciate() const override;
    void incrementaIntensita() override;
    void decrementaIntesita() override;
    SollevamentoPesi * clone() const override;
    Esercizio & operator=(const Esercizio & e) override;
    bool operator==(const Esercizio & e) const override;
    bool operator!=(const Esercizio & e) const override;
};

#endif // SOLLEVAMENTOPESI_H
