#include<iostream>
using namespace std;

//PRE=(i, lim1, lim2, lim3 >= 0)
int F(int i, int lim1, int lim2, int lim3) {
    int quoziente = 0;
    while (i >= lim3) {
        i -= lim3; //i resto della divisione intera i/lim3
        quoziente++;
    }
    return lim2 * lim3 * quoziente + i;
}
//POST=(restituisce la distanza in X tra il primo elemento di una qualsiasi H-fetta e l’elemento i della fetta)

//PRE=(b array di int [dim >= 0], pos e nP >= 0)
void scambio(int * b, int & dim, int pos, int nP) {
    for (int i = 0; i < nP; ++i) {
        for (int j = pos; j < dim - 1; ++j) { //porto pos-esimo elemento in fondo a b e diminuisco dimensioni => elimino pos-esimo elemento
            b[j] = b[j + 1];
        }
        dim--;
    }
}
//POST=(scambia a dx nP elementi in b a partire da posizione pos) && (restituisce H-Fetta b compattata a sx e di dimensioni ridotte in base al numero di elementi tolti (nP))

//PRE=(b e P array di int [lung >= 0] e [nP >= 0])
bool match(int * b, int * P, int & lung, int nP) {
    bool trovatoMatch, result = false;
    for (int i = 0; i <= lung - nP; ++i) { //cerco match completo con P per ogni elemento della H-Fetta hf
        trovatoMatch = true;
        for (int j = 0; j < nP && trovatoMatch; ++j) { //cerco match completo per i-esimo elemento di b
            if (b[i + j] != P[j]) {
                trovatoMatch = false;
            }
        }
        if (trovatoMatch) {
            scambio(b, lung, i, nP); //elimino nP elementi del match completo dalla H-Fetta hf
            result = true;
        }
    }
    return result;
}
//POST=(true sse trovato un match completo tra b e P) && (effettuato scambi eliminando gli elementi del match da b e compattato tutti gli elementi di b a sx sse trovato match completo)

//PRE=(b array di int [dim >= 0])
void stampa(int * b, int dim) {
    for (int i = 0; i < dim; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
}
//POST=(stampa tutti gli elementi di b)

int main() {
    int X[400], P[20], n_ele, nP, lim1, lim2,lim3, hf, lung = 0; //lunghezza H-Fetta
    bool fineHfetta = false;

    cin >> n_ele;
    for(int i=0; i<n_ele; i++) {
        cin >> X[i];
    }

    cin >> lim1 >> lim2 >> lim3;
    if(lim1 * lim2 * lim3 < n_ele) {
        n_ele = lim1 * lim2 * lim3;
    }

    cin >> nP;
    for(int i = 0; i < nP; i++) {
        cin >> P[i];
    }

    int b[lim1 * lim3]; // H-Fetta [massimo numero di elemento possibile in una H-Fetta]
    int nsp= n_ele/(lim2*lim3), eus= n_ele%(lim2*lim3), rpus= eus/lim3, ur= eus%lim3; //non usati

    cout << "start" << endl;
    cin >> hf;

    for (int j = 0; j < lim1 * lim3 && !fineHfetta; ++j) { //R
        if (hf * lim3 + F(j, lim1, lim2, lim3) < n_ele) {
            b[lung++] = X[hf * lim3 + F(j, lim1, lim2, lim3)];
        } else {
            fineHfetta = true;
        }
    } //POST-R

    if (match(b, P, lung, nP)) {
        cout << "H-fetta " << hf << " rimasti i seguenti " << lung << " valori:" << endl;
    } else {
        cout << "H-fetta " << hf << " non è cambiata, i suoi " << lung << " valori seguono:" << endl;
    }
    stampa(b, lung);
    cout << "end" << endl;
}

    /*
     * R = (0 <= j <= lim1 * lim3) && (fineHfetta solo per la prima volta)
     * (iterato su tutti gli elementi definiti della H-Fetta hf di X) &&
     * (elemento j della H-Fetta hf di X aggiunto in b sse tale elemento è definito: hf * lim3 + F(j, lim1, lim2, lim3) < n_ele) &&
     * (fineHfetta sse elemento j della H-Fetta hf di X non definito: hf * lim3 + F(j, lim1, lim2, lim3) >= n_ele)
     *
     * Prova di correttezza del ciclo R:
     *  Il ciclo R è sempre corretto in quanto:
     *  Corretto la prima volta che si entra nel ciclo: inizialmente j = 0 e fineHfetta = false => rispettate le condizioni necessarrie per entrare nel ciclo.
     *  Corretto ad ogni iterazione dentro il cilco: il ciclo viene eseguito finchè fineHfetta o j > lim1 * lim3.
     *  Corretto all'ultima iterazione del ciclo (quando si esce): R && !( (0 <= j <= lim1 * lim3) && (!fineHfetta) ) => R && ( (k > lim1 * lim3) || (fineHfetta) ) => iterato su tutti gli elementi definiti della H-Fetta hf di X => inseriti gli elementi in b.
    */