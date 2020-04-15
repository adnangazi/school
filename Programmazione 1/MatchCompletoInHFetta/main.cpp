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

//PRE=(X array di int [n_ele], dim, lim1, lim2, lim3 >= 0)
void stampa(int * X, int dim, int hf, int lim1, int lim2, int lim3) {
    for (int i = 0; i < dim; ++i) {
        cout << X[hf * lim3 + F(i, lim1, lim2, lim3)] << " ";
    }
    cout << endl;
}
//POST=(stampa tutti gli elementi definiti della H-Fetta hf di X)

//PRE=(X array di int [n_ele >= 0], tutte le altre variabili int >= 0)
void scambio(int * X, int elem, int nP, int lim1, int lim2, int lim3, int hf, int n_ele) {
    for (int i = 0; i < nP; ++i) { //porto gli nP elementi del match completo a dx
        for (int j = elem; j < lim3 * lim1 && hf * lim3 + F(j + 1, lim1, lim2, lim3) < n_ele; ++j) { //accompatto a sx di 1 posizione tutti gli elementi a dx dell'elemento da eliminare
            X[hf * lim3 + F(j, lim1, lim2, lim3)] = X[hf * lim3 + F(j + 1, lim1, lim2, lim3)];
        }
    }
}
//POST=(restituito X con eliminati gli elementi del match completo nella H-Fetta e compattati a sx gli altri elementi)

//PRE=(X e P array di int [n_ele >= 0] e [nP], tutte le altre variabili int >= 0)
bool match(int * X, int * P, int elem, int n_ele, int nP, int hf, int lim1, int lim2, int lim3) {
    if (hf * lim3 + F(elem + nP - 1, lim1, lim2, lim3) < n_ele) { //abbastanza elementi defniniti nella H-Fetta tale da poterci essere un match completo
        bool match = true;
        for (int i = 0; i < nP && match; ++i) { //cerco match completo
            if (X[hf * lim3 + F(elem + i, lim1, lim2, lim3)] != P[i]) {
                match = false;
            }
        }
        if (match) { //trovato un match completo in posizione elem
            scambio(X, elem, nP, lim1, lim2, lim3, hf, n_ele);
            return true;
        }
    }
    return false;
}
//POST=(true sse trovato un match completo di nP elementi nella H-Fetta hf di X a partire dall'elemento in posizione elem) && (restituito X con eliminati gli elementi del match completo nella H-Fetta e compattati a sx gli altri elementi)

int main() {
    int X[400], P[20], n_ele, nP, lim1, lim2,lim3, hf, lung = 0; //lunghezza H-Fetta
    bool fineHfetta = false, isMatch = false;

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

    int nsp= n_ele/(lim2*lim3), eus= n_ele%(lim2*lim3), rpus= eus/lim3, ur= eus%lim3; //non usati

    cout << "start" << endl;
    cin >> hf;

    for (int j = 0; j < lim1 * lim3 && !fineHfetta; ++j) { //R
        if (hf * lim3 + F(j, lim1, lim2, lim3) < n_ele) { //elemento j della H-Fetta definita
            lung++;
            if (!isMatch && match(X, P, j, n_ele, nP, hf, lim1, lim2, lim3)) { //trovato un match completo
                isMatch = true;
                j--;
                lung--;
            }
        } else {
            fineHfetta = true;
        }
    } //POST-R

    if (isMatch) {
        lung -= nP;
        cout << "H-fetta " << hf << " rimasti i seguenti " << lung << " valori:" << endl;
    } else {
        cout << "H-fetta " << hf << " non è cambiata, i suoi " << lung << " valori seguono:" << endl;
    }
    stampa(X, lung, hf, lim1, lim2, lim3);
    cout << "end" << endl;
}

/*
 * R = (0 <= j <= lim1 * lim3) && (fineHfetta solo per la prima volta)
 * (iterato su tutti gli elementi definiti della H-Fetta hf di X) &&
 * (cercato un match completo di nP elementi di P a partire dallìelemento j della H-Fetta) &&
 * (eliminato nP elementi a partire da j e accompattato a sx tutti gli elementi sse trovato match completo) &&
 * (fineHfetta sse elemento j della H-Fetta hf di X non definito: hf * lim3 + F(j, lim1, lim2, lim3) >= n_ele) &&
 * (definito la lunghezza della H-Fetta hf: lung++ sse elemento j della H-Fetta definito (hf * lim3 + F(j, lim1, lim2, lim3) < n_ele))
 *
 * Prova di correttezza del ciclo R:
 *  Il ciclo R è sempre corretto in quanto:
 *  Corretto la prima volta che si entra nel ciclo: inizialmente j = 0 e fineHfetta = false => rispettate le condizioni necessarrie per entrare nel ciclo.
 *  Corretto ad ogni iterazione dentro il cilco: il ciclo viene eseguito finchè fineHfetta o j > lim1 * lim3.
 *  Corretto all'ultima iterazione del ciclo (quando si esce): R && !( (0 <= j <= lim1 * lim3) && (!fineHfetta) ) => R && ( (k > lim1 * lim3) || (fineHfetta) ) => iterato
 *  su tutti gli elementi definiti della H-Fetta hf di X => Cercato match completo sella H-Fetta hf con gli nP elementi in p => eliminati elementi del match completo e accompattato a sx tutti gli altri.
*/