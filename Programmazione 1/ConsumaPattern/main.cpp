#include<iostream>
using namespace std;

//PRE=(tutti int definiti >= 0)
int F(int i, int lim1, int lim2, int lim3) {
    int quoziente = 0;
    while (i >= lim3) { //i resto della divisione intera i/lim3
        i -= lim3;
        quoziente++;
    }
    return lim2 * lim3 * quoziente + i;
}
//POST=(restituisce la distanza in X tra il primo elemento di una qualsiasi H-fetta e l’elemento i della fetta)

//PRE=(a array di int [lim1 * lim2 * lim3 >= 0], fetta, elem >= 0)
void stampa(int * a, int fetta, int elem, int lim1, int lim2, int lim3) {
    for (int i = 0; i < elem; ++i) {
        cout << a[fetta * lim3 + F(i, lim1, lim2, lim3)] << " ";
    }
    cout << endl;
}
//POST=(stampato tutta la H-Fetta hf di a)

//PRE=(a array di int [fine >= 0] completamente definito, inizio >= 0)
void stampaPatternRimasto(int * a, int inizio, int fine) {
    for (; inizio < fine; ++inizio) {
        cout << a[inizio];
    }
    cout << endl;
}
//POST=(stampato tutti gli elementi da iniizio di a)

//PRE=(P, X array di int [nP >= 0] e [n_ele >= 0]; i, h, f, lim1, lim2, lim3, z, j, hf >= 0)
void accompatta(int h, int i, int f, int n_ele, int & z, int & j, int * P, int lim1, int lim2, int lim3, int hf, int * X) {
    if (X[F(j, lim1, lim2, lim3) + hf * lim3] == P[z]) {
        while (i < n_ele) {
            X[f] = X[i]; //accompatto a sx di una posizione
            f = i;
            i = F(h++, lim1, lim2, lim3) + hf * lim3;
        }
        z++;
    } else {
        j++;
    }
}
//POST=(restituito X con tutti gli elementi della H-Fetta hf accompattati a sx) && (eliminati tutti gli elementi della H-Fetta hf di X presenti anche in P)

int main() {
    int X[400], P[20], n_ele, nP, lim1, lim2, lim3;
    cin >> n_ele;
    for(int i = 0; i < n_ele; i++) {
        cin >> X[i];
    }
    cin >> lim1 >> lim2 >> lim3;
    if (lim1 * lim2 * lim3 < n_ele) {
        n_ele = lim1 * lim2 * lim3;
    }
    cin >> nP;
    for (int i = 0; i < nP; i++) {
        cin >> P[i];
    }
    int nsp = n_ele/(lim2*lim3), eus= n_ele%(lim2*lim3), rpus= eus/lim3, ur= eus%lim3; //non usati
    cout<<"start"<<endl;

    int hf;
    cin >> hf; // fetta da trattare
    int j = 0; // lunghezza della H-fetta hf
    bool fineHfetta = false;
    int z = 0; //numero di elementi consumati nel pattern

    for (; j < lim1 * lim3 && !fineHfetta;) { //R
        if (F(j, lim1, lim2, lim3) + hf * lim3 < n_ele) {
            accompatta(j, F(j + 1, lim1, lim2, lim3) + hf * lim3, F(j, lim1, lim2, lim3) + hf * lim3, n_ele, z, j, P, lim1, lim2, lim3, hf, X);
        } else {
            fineHfetta = true;
        }
    } //POST-R

    if (z == nP) { //z non può essere maggiore di nP per condizione sul ciclo for precedente
        cout << "pattern consumato tutto" << endl;
    } else {
        cout << "pattern rimasto ";
        stampaPatternRimasto(P, z, nP);
    }

    cout << "la H-fetta " << hf << " e' diventata:" << endl;
    stampa(X, hf, j - z, lim1, lim2, lim3); //stampa H-Fetta
    cout << endl << "end" << endl;
}
     /**
     * R = (0 <= j <= lim1 * lim3) && (fineHfetta solo per la prima volta) && (iterato su tutta la H-Fetta di X) &&
     * (cercato nella H-Fetta hf di X un elemento di P, poi eliminato tale elemento e accompattato tutti gli elementi a sx sse elemento j della H-Fetta non è definta (numero elementi inseriti in X non sufficienti) e trovato match con un elemento in P: F(j, lim1, lim2, lim3) + hf * lim3 < n_ele) &&
     * (fineHfetta sse elemento j della H-Fetta non è definta (numero elementi inseriti in X non sufficienti): F(j, lim1, lim2, lim3) + hf * lim3 >= n_ele)
     *
     * Prova di correttezza del ciclo R:
     *  Il cilco R è sempre corretto in quanto:
     *  Corretto la prima volta che si entra nel ciclo: inizialmente j = 0 e fineHfetta = false => rispettate le condizioni necessarrie per entrare nel ciclo.
     *  Corretto ad ogni iterazione dentro il cilco: il ciclo viene eseguito finchè fineHfetta o k > lim1 * lim3.
     *  Corretto all'ultima iterazione del ciclo (quando si esce): R && !( (0 <= j <= lim1 * lim3) && (!fineHfetta) ) => R && ( (j > lim1 * lim3) || (fineHfetta) ) => iterato su tutti gli elementi definiti della H-Fetta hf di X => inseriti gli elementi in b.
     **/