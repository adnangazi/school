#include<iostream>
using namespace std;

struct orario {
    int ore, minuti, secondi;

    orario (int a = 0, int b = 0, int c = 0) {
        ore = a;
        minuti = b;
        secondi = c;
    }
};

struct rileva {
    int ril, corr;
    orario time;

    rileva (int a = 0, int b = 0, orario c = orario()) {
        ril = a;
        corr = b;
        time = c;
    }
};

istream & operator>> (istream & s, orario & x) {
    //lettura ordinata in input dell'ora in formato HH:MM:SS
    s >> x.ore;
    s >> x.minuti;
    s >> x.secondi;

    return s;
}

istream & operator>> (istream & s, rileva & x) {
    //lettura ordinata della rilevazione in formato SENSORE, PARTECIPANTE, ORARIO
    //s >> x.ril; --> non necessario: ril inserito manualmente nel ciclo di lettura in input del main
    s >> x.corr;
    s >> x.time;

    return s;
}

//DEFINIZIONE OPERATORE PER LA STAMPA DELLA STRUTTURA ORARIO: NON USATO E NON RICHIESTO
ostream & operator<< (ostream & s, orario & x) {
    s << x.ore << " ";
    s << x.minuti << " ";
    s << x.secondi << " ";

    return s;
}

//DEFINIZIONE OPERATORE PER LA STAMPA DELLA STRUTTURA RILEVA: NON USATO E NON RICHIESTO
ostream & operator<< (ostream & s, rileva & x) {
    s << x.ril << " ";
    s << x.corr << " ";
    s << x.time << " ";

    return s;
}

//PRE=(inizio e fine ORARIO definiti)
bool differenzaTempo(orario inizio, orario fine) {
    int ora, minuti, secondi;

    ora = fine.ore - inizio.ore; //non può essere < 0
    minuti = fine.minuti - inizio.minuti;
    secondi = fine.secondi - inizio.secondi;

    if (secondi < 0) { //riporto al minuto
        secondi = 60 + secondi;
        minuti--;
    }
    if (minuti < 0) { //riporto all'ora
        minuti = 60 + minuti;
        ora--;
    }

    return ora > 0 || minuti > 30 || (minuti == 30 && secondi >= 25);
}
//POST=(true sse differenza tempo tra inizio e fine >= 2' 45" al Km: 30' 25" in totale tra 2 sensori adiacenti)

//PRE=(r array di RILEVA [ncorr * 3] definito solo nelle prime dim < ncorr * 3 posizioni)
void ordinaRilevazioni(rileva r[], int dim) {
    for (int i = 0; i < dim - 1; ++i) {
        for (int j = 0; j < dim - 1; ++j) {
            if (r[j].corr > r[j + 1].corr || (r[j].corr == r[j + 1].corr && r[j].ril > r[j + 1].ril)) {

                rileva temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;

            }
        }
    }
}
//POST=(iterato su r ed effettuato bubble-sort su r) && (r ordinato in base al numero del corridore e del sensore)

//PRE=(r array di RILEVA [ncorr * 3] definito solo nelle prime dim < ncorr * 3 posizioni) --> NON USATO
void stampa (rileva r[], int dim) {
    for (int i = 0; i < dim; ++i) {
        cout << r[i] << endl;
    }
}
//POST=(stampato i valori di tutti i campi di ogni RILEVA in r)

int main() {
    int ncorr, w, RPC = 1, RF = 0; //numero partecipanti, elementi inseriti in input, rilevazioni per corridore, numero di rilevazioni fatte
    bool garaRegolare = true;
    orario z;

    cin >> ncorr;
    cin >> z; //orario inizio maratona
    cin >> w; //prima rilevazione

    rileva r[ncorr * 3]; //[massimo numero di rilevazioni possibili]

    while (w != -1) { //fine ciclo alla sentinella -1
        r[RF].ril = w; //inserimento manuale del primo elemento
        cin >> r[RF]; //tutti gli altri elementi inseriti tramite istream dell'operatore >> per la struttura RILEVA
        RF++;
        cin >> w; //primo valore della prossima rilevazione
    }

    ordinaRilevazioni(r, RF); //ordinamento in base al corridore e al sensore

    for (int i = 0; i < RF - 1; ++i) { //R <-- invariante del ciclo che determina se ci sono 3 rilevazioni per corridore
        if (r[i].corr == r[i + 1].corr) {

            if (r[i + 1].ril - r[i].ril != 1) {
                garaRegolare = false;
                cout << r[i].corr << ": salto sensore" << endl;
            }
            if (!differenzaTempo(r[i].time, r[i + 1].time)) {
                garaRegolare = false;
                cout << r[i].corr << ": tempo sospetto" << endl;
            }
            RPC++;

        } else if (RPC < 3) { //non ci sono 3 rilevazioni per corridore
            RPC = 1;
            garaRegolare = false;
            cout << r[i].corr << ": salto sensore" << endl;
        }
    } //POST-R

    if (garaRegolare) {
        cout << "gara regolare" << endl;
    }
}
//R=(0 <= i < RF) && (salto sensore sse per uno stesso corridore 2 sensori consecutivi non sono adiacenti o non sono state effettuate tutte e 3 le rilevazioni: r[i].corr == r[i + 1].corr && r[i + 1].ril - r[i].ril != 1) || r[i].corr != r[i + 1].corr && RPC < 3) && (tempo sospetto sse per uno stesso corridore la differenza di tempo nella percorrenza del tratto tra 2 sensori adiacenti è troppo breve: r[i].corr == r[i + 1].corr && !differenzaTempo(r[i].time, r[i + 1].time))