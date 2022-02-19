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

//PRE=(n intero definito)
nodo * faiL(int n) {
    if (n) {
        int x;
        cin >> x;
        return new nodo(x, faiL(n - 1));
    }

    return 0;
}
//POST=(restituito lista con n nodi con info inseriti da input)

//PRE=(L lista di nodi, anche vuoto)
void stampa(nodo * L) {
    if (L) {
        cout << L->info << ' ';
        stampa(L->next);
    } else {
        cout << endl;
    }
}
//POST=(stampato Left-To-Right info dei nodi di L)

//PRE=(Lista(L) ben formata e ordinata)
nodo * clone(nodo * L) {
    if (L) {
        return new nodo(L->info, clone(L->next));
    }

    return 0;
}
//POST=(restituito clone di Lista(L))

//PRE=(Lista(L) ben formata e ordinata, x punta ad un nodo)
nodo * insOrd_ric(nodo * L, nodo * x) {
    if (!L) {
        return x; //caso base 1: unione delle due liste è x (anche vuoto)
    } else if (!x) {
        return L; //caso base 2: unione delle due liste è L
    }

    if (x->info > L->info) {
        L->next = insOrd_ric(L->next, x); //scorro ricorsivamene L finchè non trovo la posizione in cui inserire x
        return L; //caso ricorsivo 1: restituisco L(L) = vL(L) @ L(x) ordinato
    } else { //trovato posizione di x in L
        x->next = L;
        return x; //caso ricorsivo 2: restituisco L(x) @ L(L1): L(L1) è il resto di L(L) dopo L(x)
    }
}
//POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata)

//PRE=(Lista(L) ben formata e ordinata, x punta ad un nodo)
nodo * insOrd_iter(nodo * L, nodo * x) {
    nodo * a = L; //lavoro su una copia di L per non perdere il nodo iniziale

    if (!L) {
        return x; //unione delle due liste è x (anche vuoto) perchè L è vuoto
    } else if (!x) {
        return L; //unione delle due liste è L perchè x è vuoto
    }

    while (a) {
        if (a->info <= x->info) { //x da inserire in mezzo ad a
            if (a->next) {
                if (x->info <= a->next->info) { //a <= x <= a.next
                    x->next = a->next; //inserimento x in mezzo
                    a->next = x;
                    return L;
                } else { //a.next < x
                    a = a->next; //continuo a scorrere
                }
            } else { //ultimo elemento di a < x
                a->next = x; //inserimento x in coda
                return L;
            }
        } else { //x < primo elemento di a
            x->next = a;
            return x; //inserimento x all'inizio
        }
    }

    return L; //L(L) = vL(L) @ L(x) ordinato
}
//POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata)

//PRE=(L(L) è ben formata)
nodo * ord_ric(nodo * L, nodo * listaOrdinata) {
    if (!L) {
        return listaOrdinata; //caso base 1: nessuna lista da riordinare: restituito la lista ordinata precedente
    } else {
        nodo * temp = L;
        L = L->next;
        temp->next = 0; //temp nodo isolato da inserire nella lista ordinata

        listaOrdinata = insOrd_ric(listaOrdinata, temp); //inserimento nodo nella lista ordinata
        return ord_ric(L, listaOrdinata); //caso ricorsivo 1: restituito la lista ordinata della sottolista di L(L) formata dal secondo all'ultimo nodo di vL(L)
    }
}
//POST=(restituisce una lista ordinata composta con tutti i nodi di L(L))

//PRE=(L(L) è ben formata)
nodo * ord_iter(nodo * P) {
    nodo * listaOrdinata = 0;

    while (P) {
        nodo * temp = P;
        P = P->next;
        temp->next = 0; //temp nodo isolato da inserire nella lista ordinata

        listaOrdinata = insOrd_ric(listaOrdinata, temp); //inserimento nodo nella lista ordinata
    }

    return listaOrdinata;
}
//POST=(restituisce una lista ordinata composta con tutti i nodi di L(P))

int main() {
    int m;
    cin >> m;
    nodo * L = faiL(m);
    nodo * P = clone(L);

    L = ord_ric(L, 0); //passata una lista vuota in cui verrà inserito la lista ordinata a partire da L(L)
    P = ord_iter(P);
    stampa(L);
    stampa(P);
}

/*********************************************************************************************************************************************************************************
    Prova induttiva della funzione 'nodo * ord_ric(nodo * L, nodo * listaOrdinata)':
	La correttezza di questa funzione ricorsiva (che chiameremo F) è dimostrata eseguendo un'ipotesi induttiva sulla funzione richiamata internamente, ovvero la stessa
    funzione 'nodo * ord_ric(nodo * L, nodo * listaOrdinata)' (che chiameremo G).

	G riceve come parametri formali i parametri attuali alla chiamata da F, ovvero:
		- L->next: nodo successivo di L passato per riferimento, ovvero una lista ben formata anche vuota.
		- listaOrdinata: lista ben formata anche vuota.
	==> quindi G rispetta il PRE-condizione della funzione.

	Entrambi i casi base di G rientrano nella definizione del POST-condizione di G:
        - caso base 1: nessuna lista da riordinare: restituito la lista ordinata precedente
        - caso ricorsivo 1: restituito la lista ordinata della sottolista di L(L) formata dal secondo all'ultimo nodo di vL(L)
    ==> si continua a scarrere L(L) ricorsivamente inserendo ogni nodo di L(L) nella lista ordinata L(listaOrdinata) ==> restituisce una lista ordinata composta con tutti i nodi
    di L(L) ==> G rispetta il POST-condizione della funzione.

	Usando la correttezza di G, dimostro la correttezza di F:
		In F si scorre ricorsivamene L(L) finchè non ci sono più elementi in questa lista: ogni volta viene passato alla funzione ausialiaria nodo * insOrd_ric(nodo * L, nodo * x)
		il nuovo L(L) (L(L) della chiamata precedente escluso il primo nodo) e il primo nodo di L(L). La funzione ausiliaria restituisce una nuova lista per return in cui viene
		inserito il primo nodo di L(L) in una lista ordinata, inizialmente vuota. In questo modo dopo l'nodo di L(L), tutti i nodi della lista originale sono stati inseriti nella
		lista ordinata: tale lista viene restituita.

	==> dimostro così la corretteza della funzione F, e quindi anche di G. Viene dimostrato così la correttezza della funzione 'nodo * ord_ric(nodo * L, nodo * listaOrdinata)'
 rispetto al suo PRE e POST condizione.
 *********************************************************************************************************************************************************************************/