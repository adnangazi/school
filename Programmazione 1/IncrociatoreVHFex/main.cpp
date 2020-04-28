#include<iostream>
using namespace std;

//PRE=(numeri interi definiti >= 0)
void divisioneIntera (int divisore, int & quoziente, int & dividendo) {
    while (dividendo >= divisore) {
        dividendo -= divisore;
        quoziente++;
    }
}
//POST=(restituito per referenza quoiente e resto della divisione intera dividendo / divisore)

//PRE=(lim1 * lim2 * lim3 elementi della matrice e ha nele valori definiti e inseriti per V-fette, 0 <= fex < lim3, j >= 0)
bool definito (int lim1, int lim2, int lim3, int nele, int fex, int j) {
    int s = 0; //strato dell'elemento attuale
    divisioneIntera(lim3, s, j);
    return (j * lim1 * lim2 + s * lim2 + fex < nele);
}
//POST=(true sse elemento j-esimo della H-Fetta fex definito)

//PRE=(x ha lim1 * lim2 * lim3 elementi e ha nele valori definiti e inseriti per V-fette, 0 <= fex < lim3, e >= 0)
int & ritornaIPos (int * x, int lim1, int lim2, int lim3, int fex, int e) {
    int s = 0; //strato dell'elemento attuale
    divisioneIntera(lim3, s, e);
    return x[lim3 * lim2 * s + fex * lim3 + e];
}
//POST=(return e-esimo elemento della H-Fetta fex)

//PRE=(x ha lim1 * lim2 * lim3 elementi e ha nele valori definiti e inseriti per V-fette, 0 <= fex < lim3, n >= 0)
int & f(int * x, int lim1, int lim2, int lim3, int nele, int fex, int n) {
    int i = 0, k = 0; //i: numero di elementi definiti nella H-Fetta fex, k: numero di elementi non definiti nella H-Fetta fex

    for (int j = 0; j < lim1 * lim3; ++j) { //R
        if (definito(lim1, lim2, lim3, nele, fex, j)) { //conto il numero di elementi definiti nella H-Fetta fex
            i++;
        } else { //conto il numero di elementi non definiti nella H-Fetta fex
            k++;
        }
        if (i == n + 1) { //elemento trovato: esistono abbastanza elementi definiti nella H-Fetta fex
            return ritornaIPos(x, lim1, lim2, lim3, fex, n + k); //n + k = posizione del n-esimo elemento definito della H-Fetta fex
        }
    } //POST-R

    //elemento non esistente
    throw(0);
}
//POST=(iterato sulla H-Fetta fex di x) && (lanciato eccezione sse non esistono n elementi definiti nella H-Fetta fex) && (return n-esimo elemento definito della H-Fetta fex sse esistono n elementi definiti nella H-Fetta fex)

int main() {
    int X[400], lim1, lim2, lim3, nele;
    cin >> lim1 >> lim2 >> lim3 >> nele;
    int nfvp = nele / (lim1 * lim2), resto = nele % (lim1 * lim2);

    for (int i = 0; i < nfvp; i++) {
        for(int r = 0; r < lim2 * lim1; r++)
            cin >> X[i + r * lim3];
    }

    for (int r = 0; r < resto; r++) {
        cin >> X[nfvp + r * lim3];
    }

    bool avanti = true;
    while(avanti) {
        int fex, n;
        cin >> fex;
        if(fex == -1)
            avanti = false;
        else {
            try {
                cin >> n;
                int & y = f(X, lim1, lim2, lim3, nele, fex, n);
                cout << "elemento n." << n << " della H-fetta " << fex << " e' =" << y << endl;
            } catch(int x) {
                cout << "elemento non esiste" << endl;
            }
        }
    }
}

/*
 * R=(itero sulla H-Fetta fex) && (conto numero di elementi definiti e non definiti nella H-Fetta fex) && (return n-esimo elemento definito della H-Fetta fex sse n-esimo elemento è definito)
 * Prova di correttezza di R:
 * R vero la prima volta che si entra nel ciclo perchè inizialmente j = 0
 * R vero ogni volta che si entra nel ciclo perchè il ciclo viene eseguito finchè j < lim1 * lim3 (lim1 * lim3 > 0)
 * R vero l'ultima volta che si entra nel ciclo perchè R && !(j < lim1 * lim3) => R && (j >= lim1 * lim3) => restituito n-esimo elemento definito della H-Fetta fex sse esiste n-esimo elemento, altrimenti lanciato eccezione
*/