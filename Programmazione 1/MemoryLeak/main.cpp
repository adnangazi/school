#include <iostream>
using namespace std;

int countDel = 0, countNew = 0;

struct nodo {
    int colonna;
    int val;
    nodo * next;

    nodo(int a = 0, int b = 0, nodo * c = 0) {
        colonna = a;
        val = b;
        next = c;
    }
};

//PRE=(arr va visto come un array di int [dim][dim] con dim >= 0, i e j interi definiti)
int getPos(int * arr, int i, int j, int dim) {
    if (j >= 0 && j < dim && i >= 0 && i < dim) { //controllo limiti bordi matrice
        return *(arr + dim * i + j); //arr[i][j]
    }

    return 0;
}
//POST=(return arr[i][j] sse arr[i][j] elemento di arr (j >= 0 && j < dim && i >= 0 && i < dim) , altrimenti return 0)

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
        countDel++;
    }
}
//POST=(eliminato tutti i nodi della lista dalla memoria dinamica e incrementato countDel)

//PRE=(a, b, c, lista di nodi)
nodo * biggestPath(nodo * x, nodo * y, nodo * z) {
    if (x) {
        if (y && y->val > x->val) {
            del(x);
            x = y;
        } else {
            del(y);
        }
        if (z && z->val > x->val) {
            del(x);
            x = z;
        } else {
            del(z);
        }

        return x;
    } else if (y) { //x non definito
        if (z && z->val > y->val) {
            del(y);
            y = z;
        } else {
            del(z);
        }

        return y;
    } else { //x e y non definiti
        return z; //se z non definito z = 0 ==> return 0;
    }
}
//POST=(return lista di nodi di valore maggiore)

//PRE=(B va visto come un array di int [n][n] con n >= 0, 0 <= r <= n - 1, -1 <= c <= n)
nodo * searchPath(int * B, int r, int c, int n) {
    nodo * x = 0,* y = 0, * z = 0; //cammino del sotto-ramo sinistro, centrale e destro a partire dal nodo attuale

    if (c - 1 >= 0 && r > 0 && r < n && getPos(B, r, c - 1, n) > 0) { //scorro sotto-ramo sinistro a partire dalla posizione attuale
        nodo * a = searchPath(B, r + 1, c - 1, n); //base ricorsiva ==> sotto-ramo sinistro

        if (checkLength(a, n - (r + 1))) { //sotto-ramo lungo abbastanza per essere un commino completo
            int val = a ? a->val : 0; //a->val sse a definito, altrimenti 0
            x = new nodo(c - 1, val + getPos(B, r, c - 1, n), a);
            countNew++;
        }
    }
    if (r < n && getPos(B, r, c, n) > 0) { //scorro sotto-ramo centrale a partire dalla posizione attuale
        nodo * a = searchPath(B, r + 1, c, n); //base ricorsiva ==> sotto-ramo centrale

        if (checkLength(a, n - (r + 1))) { //sotto-ramo lungo abbastanza per essere un commino completo
            int val = a ? a->val : 0; //a->val sse a definito, altrimenti 0
            y = new nodo(c, val + getPos(B, r, c, n), a);
            countNew++;
        }
    }
    if (c + 1 < n && r > 0 && r < n && getPos(B, r, c + 1, n) > 0) { //scorro sotto-ramo destro a partire dalla posizione attuale
        nodo * a = searchPath(B, r + 1, c + 1, n); //base ricorsiva ==> sotto-ramo destro

        if (checkLength(a, n - (r + 1))) { //sotto-ramo lungo abbastanza per essere un commino completo
            int val = a ? a->val : 0; //a->val sse a definito, altrimenti 0
            z = new nodo(c + 1, val + getPos(B, r, c + 1, n), a);
            countNew++;
        }
    }

    return biggestPath(x, y, z); //base 1 ==> cammino completo maggiore oppure 0 sse trovato nessun cammino completo
}
//POST=(se esiste un cammino safe che dalla riga 0 arrivi alla riga n - 1, allora la funzione restituisce la lista concatenata che rappresenta il cammino a valore massimo con la proprietà spiegata nell’Esempio 2, altrimenti, se non esiste alcun cammino safe che attraversi il campo minato, la funzione restituisce 0)

//PRE=(B va visto come un array di int [n][n] con n >= 0)
void leggi(int * X, int n) {
    for(int i = 0; i < n * n; i++) {
        cin >> X[i];
    }
}
//POST=(inseriti n * n valori da input in X)

//PRE=(X lista di nodi, n >= 0)
void stampa(nodo * X, int n) {
    if(X) {
        cout << "riga:" << n << " colonna=" << X->colonna << " val=" << X->val << endl;
        stampa(X->next, n + 1);
    }
}
//POST=(stampato cammino salvato in X)

int main() {
    int n;
    cin >> n;
    int * B = new int [n * n];
    leggi(B, n);

    nodo * x = 0;
    for(int i = 0; i < n; i++) {
        nodo * y = searchPath(B, 0, i, n);

        if (y && !(x && x->val >= y->val)) { //x è cammino completo massimo più a sinistra: dealloco gli altri cammini completi salvati in memoria dinamica
            del(x);
            x = y;
        } else {
            del(y);
        }
    }

    if(!x) {
        cout << "non c'e' cammino" << endl;
    } else {
        stampa(x, 0);
    }
    cout << "nodi creati=" << countNew << " nodi deallocati=" << countDel << endl;
}

/*************************************************************************************************************************************************************************
    Prova induttiva della funzione 'searchPath(int * B, int r, int c, int n)':
	La correttezza di questa funzione ricorsiva (che chiameremo F) è dimostrata eseguendo un'ipotesi induttiva sulla funzione
    richiamata internamente, ovvero la stessa funzione 'searchPath(int * B, int r, int c, int n)' (che chiameremo G).

	G riceve come parametri formali i parametri attuali alla chiamata da F, ovvero:
		- B: array che  va visto come un array di int [n][n] con n >= 0 alla chiamata inizale della funzione ==> non essendo modificato al passaggio in G B rimane
		array che va visto come un array di int [n][n] con n >= 0 ad ogni chiamata.
		- r + 1: inizialmente r == 0 e le chiamate a G vengono effettuate finchè r < n ==> 0 <= r <= n - 1
		- c - 1, c o c + 1 in base a quale funzione G viene chiamata in F: inizialmente c == 0 e le chiamate a G vengono effettuate finchè c < n ==> -1 <= c <= n
		- n: n >= 0 alla chiamata iniziale della funzione ==> n >= 0 ad ogni chiamata in quanto non viene cambiato al passaggio a G.
	==> quindi G rispetta il PRE-condizione della funzione.

	Entrambi i casi base di G rientrano nella definizione del POST-condizione di G:
		- caso base 1: restituito lista completa di nodi di valore massimo tra quelli trovati per il nodo attuale. Se i cammini trovati non sono completi, vengono azzerati.
		Se non sono stati trovati cammini completi viene restituito un cammino qualunque, ovvero 0 (considerabile cammino vuoto). Ogni volto che viene creato un
		nuovo nodo nella memoria dinamica, countNew viene incrementato, mentre a tutti i nodi che vengono deallocati dalla memoria dinamica, in quanto non fanno
		parte del cammino completo di valore maggiore, countDel viene incrementato di 1 o 2 in base al numero di nodi creati per nodo attuale.

	Usando la correttezza di G, dimostro la correttezza di F:
		In F, per ogni radice (cella >= 1 in riga 0: rappresenta possibile inizio di cammino) si scorrono tutti i rami possibili ottenuti dall'albero binario formato
		dall'insieme dei cammini, completi o non completi. Per ogni ramo, si controlla che la lunghezza sia tale che il ramo arrivi fino all'ultima riga della matrice
		B[n][n] ==> trovato cammino completo. A partire dagli elementi in fondo alla matrice si controlla il valore del cammino e si sceglie, tra tutti i cammini completi
		disponibili, quello con il valore massimo. Si crea ricorsivamente e si restituisce una lista di nodi in cui si salvano le colonne del cammino rispetto alla
		relativa riga. Altrimenti non si è trovato nessun cammino completo ==> restituito 0 che indica sia una lista vuota che la presenza di cammini completi.

	==> dimostro così la corretteza della funzione F, e quindi anche di G. Viene dimostrato così la correttezza della funzione 'searchPath(int * B, int r, int c, int n)'
    rispetto al suo PRE e POST condizione.
 *************************************************************************************************************************************************************************/