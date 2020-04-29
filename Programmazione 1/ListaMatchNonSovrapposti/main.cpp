#include<iostream>
using namespace std;

struct nodo {
    int info;
    nodo * next;

    nodo(int a = 0, nodo * b = 0) {
        info = a;
        next = b;
    }
};

//PRE=(X e P array di interi parzialmente o completamente definito, dimP >= 0)
void match(int * X, int * P, int dimP) {
    for (int i = 0; i < dimP; ++i) {
        if (X[i] != P[i]) {
            throw (0);
        }
    }
}
//POST=(termina sse X[0 ... dimP - 1] == P[0 ... dimP - 1]) && (altrimenti lancia eccezione)

//PRE=(a puntatore a nodo)
nodo * getCoda(nodo * a) {
    while (a->next) {
        a = a->next;
    }

    return a;
}
//POST=(restituisce l'ultimo nodo di a)

//PRE=(a e b puntatori a nodo passati)
void insert(nodo *& a, nodo *& b) {
    if (a) {
        getCoda(a)->next = b;
    } else { //a vuoto: il nodo concatenato è b
        a = b;
    }
}
//POST=(concatena l'ultimo nodo di a con il primo nodo di b)

//PRE=(a array di int completamente definito, inizio, fine e sm >=0)
void shifter(int * a, int inizio, int & fine, int sm, int & indice) { //sm = shift amaunt
    for (int i = inizio; i < inizio + fine - sm; ++i) {
        a[i] = a[i + sm];
    }

    fine -= sm;
    indice += sm;
}
//POST=(eliminati sm elementi in X a partire dalla posizione inizio: scambiati gli sm elementi a parire da posizione inizio di X a destra e diminuito la dimensione di X)

//PRE=(X e P array di interi completamente o parzialmente definito, inizio, lungS e dimP >= 0)
nodo * matchStrato(int * X, int inizio, int lungS, int * P, int dimP) {
    nodo * listaMatch = 0;

    for (int i = inizio, k = inizio - dimP, indice = inizio; i <= inizio + lungS - dimP;) {
        try {
            match(X + inizio, P, dimP);
            if (k + (dimP - 1) >= i) { //trovato un match, ma è sovrapposto
                throw (0);
            }
            //trovato un match non sovrapposto
            nodo * temp = new nodo(indice); //inserimento nella lista dei match dello strato
            insert(listaMatch, temp);
            shifter(X, inizio, lungS, dimP, indice); //passo alla posizione successiva agli elementi del match
        } catch (int e) { //non trovato match non sovrapposto nella posizione i di X
            shifter(X, inizio, lungS, 1, indice); //passo alla posizione successiva dello strato
        }
    }

    return listaMatch;
}
//POST=(restituito la lista dei match non sovrapposti nello strato attuale di X)

//PRE=(y puntatore a nodo)
void stampa(nodo * y) {
    while(y) {
        cout << y->info << ' ';
        y = y->next;
    }

    cout << endl;
}
//POST=(stampato le informazioni della lista di nodi)

int main() {
    int X[100], lim1, lim2, lim3, nele, P[20], dimP;
    nodo * Y = 0;

    cin >> lim1 >> lim2 >> lim3 >> nele;
    for (int i = 0; i < nele; i++) {
        cin >> X[i];
    }

    if (nele > lim1 * lim2 * lim3) { //inseriti al massimo tanti elementi quante le posizioni della matrice
        nele =  lim1 * lim2 * lim3;
    }

    cin >> dimP;
    for (int i = 0; i < dimP; i++) {
        cin >> P[i];
    }

    for (int str = 0, lungS; lim3 * lim2 * str < nele; ++str) { //R
        if (lim3 * lim2 * (str + 1) > nele) { //strato parzialmente riempito
            lungS = nele - lim3 * lim2 * str;
        } else { //strato completamente riempito
            lungS = lim3 * lim2;
        }

        nodo * temp = matchStrato(X, lim3 * lim2 * str, lungS, P, dimP); //lista dei match non sovrapposti dello strato str
        insert(Y, temp); //concateno la lista dei match dello strato str a tutti i match degli strati precedenti
    } //POST-R

    stampa(Y);
}

/*
 * R=(0 <= str * lim2 * lim3 <= nele) &&
 * (itero sugli strati con elementi definiti di X)
 * (lungS numero di elementi definiti dello strato str: lungS = nele - lim3 * lim2 * str sse lim3 * lim2 * (str + 1) > nele, altrimenti lungS = lim3 * lim2) &&
 * (concateno la lista dei match non sovrapposti dello strato str a tutti i match non sovrapposti degli strati precedenti)
 *
 * POST-R=(Y lista di nodi concatenati dei match non sovrapposti di tutti gli strati con elementi definiti di X)
 *
 * Prova di correttezza di R:
 * R corretto la prima volta che si entra nel ciclo perchè inizialmente str = 0 => lim1 * lim2 * str = 0 ==> (0 <= 0 <= nele).
 * R corretto ogni volta che si entra nel ciclo perchè se nello strato str c'è almeno un elemento definito ==> lim1 * lim2 * str < nele. Se str * lim2 * lim3 > nele ==> strato str (è quelli successivi) non ha elementi definiti ==> trovati tutti e concatenati i match negli strati di X ==> POST-R
 * R corretto dopo che si entra nel ciclo per l'ultima volta perchè: R && !(0 <= str * lim2 * lim3 <= nele) ==> R && (str * lim2 * lim3 > nele) ==> iterato su tutti gli strati di X ==> trovato tutti i match non sovrapposti di ciascuno strato e concatenato i match ==> POST-R
*/