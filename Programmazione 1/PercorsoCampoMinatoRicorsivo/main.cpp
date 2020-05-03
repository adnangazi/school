#include <iostream>
using namespace std;

struct nodo {
    int colonna;
    nodo * next;

    nodo(int a = 0, nodo * b = 0) {
        colonna = a;
        next = b;
    }
};

//PRE=(arr va visto come un array di bool [n][n] con n >= 0, 0 <= i <= dim - 1, -1 <= j <= dim)
bool getPos(bool * arr, int i, int j, int dim) {
    if (j >= 0 && j < dim) { //controllo limiti bordi della colonna
        return *(arr + dim * i + j); //B[i][j]
    }
    return false;
}
//POST=(return true sse arr[i][j] == true)

//PRE=(X lista di nodi, n >= 0)
bool checkLength(nodo * X, int n) {
    int i = 0;
    while (X) {
        X = X->next;
        i++;
    }

    return i == n;
}
//POST=(return true sse numero di nodi in X == n)

//PRE=(B va visto come un array di bool [n][n] con n >= 0, 0 <= r <= n - 1, -1 <= c <= n)
nodo * searchPath(bool * B, int r, int c, int n) {
    if (c - 1 >= 0 && r < n && getPos(B, r, c - 1, n)) { //scorro sotto-ramo sinistro a partire dalla posizione attuale
        nodo * a = new nodo(c - 1, searchPath(B, r + 1, c - 1, n)); //
        if (checkLength(a, n - r)) { //sotto-ramo lungo abbastanza da completare un commino completo
            return a; //base 1 ==> trovato un cammino completo
        }
    }
    if (r < n && getPos(B, r, c, n)) { //scorro sotto-ramo centrale a partire dalla posizione attuale
        nodo * a = new nodo(c, searchPath(B, r + 1, c, n));
        if (checkLength(a, n - r)) { //sotto-ramo lungo abbastanza da completare un commino completo
            return a; //base 1 ==> trovato un cammino completo
        }
    }
    if (c + 1 < n && r < n && getPos(B, r, c + 1, n)) { //scorro sotto-ramo destro a partire dalla posizione attuale
        nodo * a = new nodo(c + 1, searchPath(B, r + 1, c + 1, n));
        if (checkLength(a, n - r)) { //sotto-ramo lungo abbastanza da completare un commino completo
            return a; //base 1 ==> trovato un cammino completo
        }
    }
    
    return 0; //base 2 ==> nessun elemento trovato che possa appartenente al commino completo o nessun cammino completo trovato
}
//POST=(se c’è un cammino dalla posizione c della riga r fino alla riga n - 1, allora la funzione restituisce una lista concatenata i cui nodi contengono nel loro campo colonna le colonne del cammino più a sinistra che dalla riga i, colonna c, arriva fino alla riga n - 1, se non c’è un tale cammino allora la funzione restituisce 0)

//PRE=(B va visto come un array di bool [n][n] con n >= 0)
void leggi(bool * X, int n) {
    for(int i = 0; i < n * n; i++) {
        cin >> X[i];
    }
}
//POST=(inseriti n * n valori da input in X)

//PRE=(X lista di nodi, n >= 0)
void stampa(nodo * X, int n) {
    if(X) {
        cout << "riga:" << n << " colonna=" << X->colonna << endl;
        stampa(X->next, n + 1);
    }
}
//POST=(stampato cammino salvato in X)

int main() {
    int n;
    cin >> n;
    bool * B = new bool [n * n];
    leggi(B, n);

    nodo * x = 0;
    for(int i = 0; i < n && !x; i++) {
         x = searchPath(B, 0, i, n);
    }

    if(!x) {
        cout << "non c'e' cammino" << endl;
    } else {
        stampa(x, 0);
    }
}