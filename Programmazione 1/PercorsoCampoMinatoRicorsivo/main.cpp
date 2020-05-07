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

//PRE=(a lista di nodi)
void del(nodo * a) {
    while (a) {
        nodo * b = a;
        a = a->next;
        delete b;
    }
}
//POST=(eliminato tutti i nodi di a dalla memoria dinamica)

//PRE=(B va visto come un array di bool [n][n] con n >= 0, 0 <= r <= n - 1, -1 <= c <= n)
nodo * searchPath(bool * B, int r, int c, int n) {
    if (c - 1 >= 0 && r > 0 && r < n && getPos(B, r, c - 1, n)) { //scorro sotto-ramo sinistro a partire dalla posizione attuale
        nodo * a = new nodo(c - 1, searchPath(B, r + 1, c - 1, n)); //
        if (checkLength(a, n - r)) { //sotto-ramo lungo abbastanza da completare un commino completo
            return a; //base 1 ==> trovato un cammino completo
        } else { //elimino i nodi dalla memoria dinamica
            del(a);
            a = 0;
        }
    }
    if (r < n && getPos(B, r, c, n)) { //scorro sotto-ramo centrale a partire dalla posizione attuale
        nodo * a = new nodo(c, searchPath(B, r + 1, c, n));
        if (checkLength(a, n - r)) { //sotto-ramo lungo abbastanza da completare un commino completo
            return a; //base 1 ==> trovato un cammino completo
        } else { //elimino i nodi dalla memoria dinamica
            del(a);
            a = 0;
        }
    }
    if (c + 1 < n && r > 0 && r < n && getPos(B, r, c + 1, n)) { //scorro sotto-ramo destro a partire dalla posizione attuale
        nodo * a = new nodo(c + 1, searchPath(B, r + 1, c + 1, n));
        if (checkLength(a, n - r)) { //sotto-ramo lungo abbastanza da completare un commino completo
            return a; //base 1 ==> trovato un cammino completo
        } else { //elimino i nodi dalla memoria dinamica
            del(a);
            a = 0;
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

/*************************************************************************************************************************************************************************
    Prova induttiva della funzione 'searchPath(bool * B, int r, int c, int n)':
	La correttezza di questa funzione ricorsiva (che chiameremo F) è dimostrata eseguendo un'ipotesi induttiva sulla funzione
    richiamata internamente, ovvero la stessa funzione 'searchPath(bool * B, int r, int c, int n)' (che chiameremo G).

	G riceve come parametri formali i parametri attuali alla chiamata da F, ovvero:
		- B: array che  va visto come un array di bool [n][n] con n >= 0 alla chiamata inizale della funzione ==> non essendo modificato al passaggio in G B rimane
		array che va visto come un array di bool [n][n] con n >= 0 ad ogni chiamata.
		- r + 1: inizialmente r == 0 e le chiamate a G vengono effettuate finchè r < n ==> 0 <= r <= n - 1
		- c - 1, c o c + 1 in base a quale funzione G viene chiamata in F: inizialmente c == 0 e le chiamate a G vengono effettuate finchè c < n ==> -1 <= c <= n
		- n: n >= 0 alla chiamata iniziale della funzione ==> n >= 0 ad ogni chiamata in quanto non viene cambiato al passaggio a G.
	==> quindi G rispetta il PRE-condizione della funzione.

	Entrambi i casi base di G rientrano nella definizione del POST-condizione di G:
		- caso base 1: return lista degli elementi in modo da costituire un cammino sse la lunghezza della lista è tale che il cammino è un cammino completo
		(fino all'ultima riga).
		- caso base 2: return 0 (considerabile come lista vuota) sse se non esiste un cammino completo.
	==> abbiamo che G rispetta il POST-condizione della funzione.

	Usando la correttezza di G, dimostro la correttezza di F:
		In F, per ogni radice (cella = 1 in riga 0: rappresenta possibile inizio di cammino) si scorrono tutti i rami possibili ottenuti dall'albero binario formato
		dall'insieme dei cammini, completi o non completi. Per ogni ramo, si controlla che la lunghezza sia tale che il ramo arrivi fino all'ultima riga della matrice
		B[n][n] ==> trovato cammino completo. Si crea ricorsivamente e si restituisce una lista di nodi in cui si salvano le colonne del cammino rispetto alla relativa
		riga. Altrimenti non si è trovato nessun cammino completo ==> restituito 0 che indica sia una lista vuota che la presenza di cammini completi.

	==> dimostro così la corretteza della funzione F, e quindi anche di G. Viene dimostrato così la correttezza della funzione 'searchPath(bool * B, int r, int c, int n)'
    rispetto al suo PRE e POST condizione.
 *************************************************************************************************************************************************************************/