#include <iostream>
using namespace std;
typedef unsigned int uint;

//CLASSE ORARIO---------------------------------------------------------------------------------------------------------
class Orario {
private:
    uint sec;
public:
    Orario(const uint secondi = 0, const uint minuti = 0, const uint ore = 0) : sec(secondi + minuti * 60 + ore * 3600) {}
    Orario(const Orario & o) : Orario(o.getSecondi(), o.getMinuti(), o.getOre()) {}

    uint getSecondi() const { return sec % 60; }
    uint getMinuti() const { return (sec / 60) % 60; }
    uint getOre() const { return sec / 3600; }

    //FUNZIONI TOLTE DAL DIAGRAMMA UML DELLE CLASSI: USARE METODI DI SET CON I METODI DI GET + 1
    /*
    void incrementaSecondi() { sec++; }
    void incrementaMinuti() { sec += 60; }
    void incrementaOre() { sec += 3600; }

    void decrementaSecondi() {
        if (sec > 0) sec--;
        else sec = 0;
    }
    void decrementaMinuti() {
        if (sec >= 60) sec -= 60;
        else sec = 0;
    }
    void decrementaOre() {
        if (sec >= 3600) sec -= 3600;
        else sec = 0;
    }
    */

    void setSecondi(const uint s = 0) { sec += (s - getSecondi()); }
    void setMinuti(const uint m = 0) { sec += (m - getMinuti()) * 60; }
    void setOre(const uint o = 0) { sec += (o - getOre()) * 3600; }

    Orario & operator= (const Orario & o);
};
bool operator== (const Orario & a, const Orario & b) { return a.getOre() == b.getOre() && a.getMinuti() == b.getMinuti() && a.getSecondi() == b.getSecondi(); }
bool operator!= (const Orario & a, const Orario & b) { return a.getOre() != b.getOre() || a.getMinuti() != b.getMinuti() || a.getSecondi() != b.getSecondi(); }
Orario & Orario::operator= (const Orario & o) {
    if (*this != o) {
        this->sec = o.sec;
    }
    return *this;
}
bool operator> (const Orario & a, const Orario & b) {
    if (a.getOre() > b.getOre()) return true;
    else if (a.getOre() < b.getOre()) return false;
    else if (a.getMinuti() > b.getMinuti()) return true;
    else if (a.getMinuti() < b.getMinuti()) return false;
    else return a.getSecondi() > b.getSecondi();
}
bool operator>= (const Orario & a, const Orario & b) {return a > b || a == b; }
bool operator< (const Orario & a, const Orario & b) { return b > a;}
bool operator<= (const Orario & a, const Orario & b) { return b >= a; }
Orario operator+ (const Orario & a, const Orario & b) { return Orario(a.getSecondi() + b.getSecondi(), a.getMinuti() + b.getMinuti(), a.getOre() + b.getOre()); }
Orario operator- (const Orario & a, const Orario & b) {
    if (a < b) return Orario();

    int secondi = a.getSecondi() - b.getSecondi(); //int perchè può andare in negativo (riporto necessario)
    int minuti = a.getMinuti() - b.getMinuti(); //int perchè può andare in negativo (riporto necessario)
    uint ore = a.getOre() - b.getOre(); //non può andare in negativo perchè a >= b

    if (secondi < 0) { //riporto un minuto nei secondi
        secondi += 60;
        minuti--;
    }
    if (minuti < 0) { //riporto un'ora nei minuti
        minuti += 60;
        ore--;
    }

    return Orario(secondi, minuti, ore);
}
std::ostream & operator<< (std::ostream & os, const Orario & o) {
    return os << "Ore: " << o.getOre() << ", Minuti: " << o.getMinuti() << ", Secondi: " << o.getSecondi();
}
//FINE CLASSE ORARIO----------------------------------------------------------------------------------------------------

//CLASSE ESERCIZIO------------------------------------------------------------------------------------------------------
class Esercizio {
private:
    string nome;
    string descrizione;
public:
    Esercizio(const string n, const string d) : nome(n), descrizione(d) {}
    Esercizio(const Esercizio & e) : Esercizio(e.getNome(), e.getDescrizione()) {}

    string getNome() const { return nome; }
    void setNome(const string n) { nome = n; }
    virtual string getDescrizione() const { return descrizione; }
    void setDescrizione(const string d) { descrizione = d; }
    virtual Orario getDurata() const = 0;
    virtual void setDurata(const Orario & o = 0) = 0;
};
//FINE CLASSE ESERCIZIO-------------------------------------------------------------------------------------------------

//CLASSE MONOESERCIZIO--------------------------------------------------------------------------------------------------
class MonoEsercizio : public Esercizio {
private:
    uint MET;
public:
    MonoEsercizio(const string n, const string d, const uint m = 0) : Esercizio(n, d), MET(m) {}
    //MonoEsercizio(const Esercizio & e) {}

    uint getMET() const { return MET; }
    void setMET(const uint & m = 0) { MET = m; }
    virtual uint stimaCalorieBruciate() const = 0;
    virtual void incrementaIntensita() = 0;
    virtual void decrementaIntesita() = 0;
};
//FINE CLASSE MONOESERCIZIO---------------------------------------------------------------------------------------------

//CLASSE CARDIO---------------------------------------------------------------------------------------------------------
class Cardio : virtual public MonoEsercizio {
private:
    Orario durata;
    uint velocita;
public:
    Cardio(const string n, const string d, const uint m = 0, const Orario & o = 0, const uint & v = 0) : MonoEsercizio(n, d, m), durata(o), velocita(v) {}
    //Cardio(const Esercizio & e) {}

    uint getVelocita() const { return velocita; }
    void setVelocita(const uint & v = 0) { velocita = v; }

    //@override Esercizio
    string getDescrizione() const { return Esercizio::getDescrizione() + "i altre sborae varie su Cardio..."; }
    Orario getDurata() const override { return durata; }
    void setDurata(const Orario & o) override { durata = o; }

    //@override MonoEsercizio
    uint stimaCalorieBruciate() const override { return (velocita * (durata.getOre() * 3600 + durata.getMinuti() * 60 + durata.getSecondi()) * MonoEsercizio::getMET()) / 100; }
    void incrementaIntensita() override { velocita++; }
    void decrementaIntesita() override {
        if (velocita > 0) {
            velocita--;
        } else {
            cout << "Impossibile diminuire ulteriormente la velocità dell'esercizio!" << endl;
        }
    }
};
//FINE CLASSE CARDIO----------------------------------------------------------------------------------------------------

//CLASSE SOLLEVAMENTOPESI-----------------------------------------------------------------------------------------------
class SollevamentoPesi : virtual public MonoEsercizio {
private:
    uint peso;
    uint ripetizioni;
    uint serie;
public:
    static const Orario tempoDiRipetizione;

    SollevamentoPesi(const string n, const string d, const uint m = 0, const uint & p = 0, const uint & r = 0, const uint & s = 0) : MonoEsercizio(n, d, m), peso(p), ripetizioni(r), serie(s) {}
    //SollevamentoPesi(const Esercizio & e) {}

    uint getPeso() const { return peso; }
    void setPeso(const uint & p = 0) { peso = p; }
    uint getRipetizioni() const { return ripetizioni; }
    void setRipetizioni(const uint & r = 0) { ripetizioni = r; }
    uint getSerie() const { return serie; }
    void setSerie(const uint & s = 0) { serie = s; }

    //@override Esercizio
    string getDescrizione() const { return Esercizio::getDescrizione() + "i altre sborae varie su SollevamentoPesi..."; }
    Orario getDurata() const override { return Orario(tempoDiRipetizione.getSecondi() * ripetizioni * serie, serie - 1); }
    void setDurata(const Orario & o) override {
        uint totaleSec = o.getOre() * 3600 + o.getMinuti() * 60 + o.getSecondi();
        totaleSec -= (serie - 1) * 60; //tolgo il minuto di riposo obbligatorio tra una serie e l'altra
        ripetizioni = (totaleSec / serie) / tempoDiRipetizione.getSecondi();
    }

    //@override MonoEsercizio
    uint stimaCalorieBruciate() const override { return MonoEsercizio::getMET() * ripetizioni * serie; }
    void incrementaIntensita() override {
        if (serie > 1) {
            serie--;
            ripetizioni += ripetizioni / serie;
            peso += peso / 10;
        } else {
            cout << "Impossibile aumentare ulteriormente l'intensità dell'esercizio!" << endl;
        }
    }
    void decrementaIntesita() override {
        serie++;
        ripetizioni -= ripetizioni / serie;
        peso -= peso / 11;
    }
};
const Orario SollevamentoPesi::tempoDiRipetizione = Orario(5);
//FINE CLASSE SOLLEVAMENTOPESI------------------------------------------------------------------------------------------

//CLASSE CROSSFIT-------------------------------------------------------------------------------------------------------
class CrossFit : public Cardio, public SollevamentoPesi {
public:
    CrossFit(const string n, const string d, const uint m = 0, const Orario & o = 0, const uint & v = 0, const uint & p = 0) : MonoEsercizio(n, d, m), Cardio(n, d, m, o, v), SollevamentoPesi(n, d, m, p, 0, 1) { SollevamentoPesi::setDurata(o); }
    //CrossFit(const Esercizio & e) {}

    //@override Esercizio
    string getDescrizione() const { return Esercizio::getDescrizione() + Cardio::getDescrizione() + SollevamentoPesi::getDescrizione() + "i altre sborae varie su CrossFit..."; }
    Orario getDurata() const override { return Cardio::getDurata(); }
    void setDurata(const Orario & o) override {
        Cardio::setDurata(o);
        SollevamentoPesi::setDurata(o);
    }

    //@override MonoEsercizio
    uint stimaCalorieBruciate() const override { return Cardio::stimaCalorieBruciate() + SollevamentoPesi::stimaCalorieBruciate(); }
    void incrementaIntensita() override {
        Cardio::incrementaIntensita();
        uint pesoTemp = getPeso();
        pesoTemp += pesoTemp / 10;
        setPeso(pesoTemp);
    }
    void decrementaIntesita() override {
        Cardio::decrementaIntesita();
        uint pesoTemp = getPeso();
        pesoTemp -= pesoTemp / 11;
        setPeso(pesoTemp);
    }
};
//FINE CLASSE CROSSFIT--------------------------------------------------------------------------------------------------

//CLASSE RIPOSO---------------------------------------------------------------------------------------------------------
class Riposo : public Esercizio {
private:
    Orario durata;
public:
    Riposo(const string n, const string d, const Orario & o = 0) : Esercizio(n, d), durata(o) {}
    //Riposo(const Esercizio & e) {}

    //@override Esercizio
    string getDescrizione() const {
        return Esercizio::getDescrizione() + "i altre sborae varie su Riposo...";
    }
    Orario getDurata() const override { return durata; }
    void setDurata(const Orario & o) override { durata = o; }
};
//FINE CLASSE RIPOSO----------------------------------------------------------------------------------------------------

//CLASSE RIPOSOATTIVO---------------------------------------------------------------------------------------------------
class RiposoAttivo : public Riposo {
private:
    Esercizio * esercizioAttivo; //utilizzo (super)polimorfo di puntatore
public:
    //RiposoAttivo(const Esercizio e) {}
    //RiposoAttivo(const Esercizio & e) {}

    Esercizio * getEsercizio() { return esercizioAttivo; }
    void setEsercizio(Esercizio * e) { esercizioAttivo = e; }
    void setMET(uint i = 0) { }

    //@override Esercizio
    virtual string getDescrizione() const override { cout << "Riposo::getDescrizione() Da fare!" << endl; return const_cast<char*>("sdv"); }
    virtual Orario getDurata() const override { return Riposo::getDurata(); }
    virtual void setDurata(const Orario & o) override { Riposo::setDurata(o); }

    uint stimaCalorieBruciate() { cout << "Cardio::stimaCalorieBruciate() Da fare!" << endl; return 0; }
    void incrementaIntensita() { cout << "Cardio::incrementaIntesita() Da fare!" << endl; }
    void decrementaIntesita() { cout << "Cardio::decrementaIntensita() Da fare!" << endl; }
};
//FINE CLASSE RIPOSOATTIVO----------------------------------------------------------------------------------------------

int main() {
    cout << "Inizio programma ... " << endl;
    cout << "Test Cardio" << endl;
    Cardio c(const_cast<char*>("Corsa"), const_cast<char*>("Corri negro!"), 3, Orario(0, 30), 7);
    c.setVelocita(c.getVelocita() + 1);
    cout << c.getVelocita() << endl; // 8
    cout << c.getDescrizione() << endl; // Corri negro! i altre sborae varie su Cardio...
    c.setDurata(Orario(0, 31));
    cout << c.getDurata() << endl; // 0:31:0
    cout << c.stimaCalorieBruciate() << endl; // 400
    c.incrementaIntensita();
    cout << c.stimaCalorieBruciate() << endl; // 450
    c.decrementaIntesita();
    cout << c.stimaCalorieBruciate() << endl; // 400
    cout << "Test SollevamentoPesi" << endl;
    SollevamentoPesi s(const_cast<char*>("Push-up"), const_cast<char*>("Flessioni a più non posso"), 2, 0, 15, 4);
    cout << s.getPeso() << endl; // 0
    s.setPeso(s.getPeso() + 1);
    cout << s.getPeso() << endl; // 1
    cout << s.stimaCalorieBruciate() << endl; // 120
    cout << s.getRipetizioni() << endl; // 15
    s.setRipetizioni(s.getRipetizioni() + 1);
    cout << s.getRipetizioni() << endl; // 16
    cout << s.getSerie() << endl; // 4
    s.setSerie(s.getSerie() + 1);
    cout << s.getSerie() << endl; // 5
    cout << s.getDescrizione() << endl; //Push-up i altre sborae varie su SollevamentoPeso...
    cout << s.getDurata() << endl; // 0:10:40
    s.setDurata(Orario(0, 8));
    cout << s.getDurata() << endl; // 0:9:0
    cout << s.getRipetizioni() << endl; // < 15
    cout << s.stimaCalorieBruciate() << endl; // 130?
    s.incrementaIntensita();
    cout << s.stimaCalorieBruciate() << " " << s.getDurata() << " " << s.getSerie() << " " << s.getRipetizioni() << " " << s.getPeso() << endl;
    s.decrementaIntesita();
    cout << s.stimaCalorieBruciate() << " " << s.getDurata() << " " << s.getSerie() << " " << s.getRipetizioni() << " " << s.getPeso() << endl;
    cout << "Test CrossFit" << endl;
    CrossFit f(const_cast<char*>("Ball-Wall"), const_cast<char*>("Tira la palla medica contro il muro"), 3, Orario(30), 7, 10);
    cout << f.getNome() << " " << f.getDescrizione() << " " << f.getDurata() << endl;
    f.setDurata(Orario(0, 10));
    cout << f.getDurata() << endl;
    cout << f.getPeso() << " " << f.getRipetizioni() << " " << f.getSerie() << " " << f.getVelocita() << endl;
    f.setVelocita(f.getVelocita() + 1);
    cout << f.getVelocita() << endl;
    cout << f.stimaCalorieBruciate() << endl;
    f.incrementaIntensita();
    cout << f.stimaCalorieBruciate() << endl;
    f.decrementaIntesita();
    cout << f.stimaCalorieBruciate() << endl;
    cout << "Test Riposo" << endl;
    Riposo r("Rip", "Rippa bene", Orario(30));
    cout << r.getNome() <<" " << r.getDescrizione() << " " << r.getDurata() << endl;
    r.setDurata(Orario(0, 1));
    cout << r.getDurata() << endl;
    cout << "Fine programma ... " << endl;
}