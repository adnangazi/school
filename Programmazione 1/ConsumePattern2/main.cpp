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

//PRE=(a array di int [fine >= 0] completamente definito)
void stampa(int * a, int inizio, int fine) {
    for (; inizio < fine; ++inizio) {
        cout << a[inizio] << " ";
    }
    cout << endl;
}
//POST=(stampato tutti gli elementi di a)

//PRE=(b array di int [lung >= 0] completamente definito, inizio >= 0)
void accompattaSx(int * b, int inizio, int & lung) {
    for (int i = inizio; i < lung; ++i) { //compatto verso sinistra
        b[i] = b[i + 1];
    }
    lung--;
}
//POST=(restituito b con tutti gli elementi a dx di inizio compattati a sx di una posizione) && (impostato la nuova lunghezza della H-Fetta)

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
    int lung = 0; // lunghezza della H-fetta hf
    bool fineHfetta = false;
    int z = 0; //numero di elementi consumati nel pattern
    int b[lim1 * lim3]; //H-Fetta: [lunghezza massima H-Fetta]

    for (int j = 0; j < lim1 * lim3 && !fineHfetta; ++j) { //R
        if (F(j, lim1, lim2, lim3) + hf * lim3 < n_ele) {
            b[j] = X[F(j, lim1, lim2, lim3) + hf * lim3];
            lung++;
        } else {
            fineHfetta = true;
        }
    } //POST-R

    for (int l = 0; l < lung && z < nP;) { //elimino gli elementi della H-Fetta che si presentano anche nel pattern
        if (b[l] == P[z]) { //scorro sul pattern
            accompattaSx(b, l, lung);
            z++;
        } else { //scorro su H-Fetta
            l++;
        }
    }

    if (z == nP) { //z non può essere maggiore di nP per condizione sul ciclo for precedente
        cout << "pattern consumato tutto" << endl;
    } else {
        cout << "pattern rimasto ";
        stampa(P, z, nP);
    }

    cout << "la H-fetta " << hf << " e' diventata:" << endl;
    stampa(b, 0, lung);
    cout<< endl << "end" << endl;
}
     /**
     * R = (0 <= k <= lim1) && (fineHfetta solo per la prima volta) && (iterato su tutta la H-Fetta di X) &&
     * (inserimento ordinato di un nuovo elemento della H-Fetta in b sse elemento definito, ovvero posizione in X minore degli elementi inseriti n_ele: F(j, lim1, lim2, lim3) + hf * lim3 < n_ele) &&
     * (fineHfetta sse nuovo elemento della H-Fetta non è definito, ovvero non sono stati inseriti abbastanza elementi (posizione elemento < n_ele): F(j, lim1, lim2, lim3) + hf * lim >= n_ele) &&
     * (incrementato lunghezza di b sse inserito nuovo elemento nella H-Fetta)
     *
     * Prova di correttezza del ciclo R:
     *  Il cilco R è sempre corretto in quanto:
     *  Corretto la prima volta che si entra nel ciclo: inizialmente k = 0 e fineHfetta = false => rispettate le condizioni necessarrie per entrare nel ciclo.
     *  Corretto ad ogni iterazione dentro il cilco: il ciclo viene eseguito finchè fineHfetta 0 k > lim1.
     *  Corretto all'ultima iterazione del ciclo (quando si esce): R && !( (0 <= k <= lim1) && (!fineHfetta) ) => R && ( (k > lim1) || (fineHfetta) ) => iterato su tutti gli elementi definiti della H-Fetta hf di X => inseriti gli elementi in b.
     **/