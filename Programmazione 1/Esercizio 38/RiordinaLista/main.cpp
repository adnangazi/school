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
        return listaOrdinata;
    } else {
        nodo * temp = L;
        L = L->next;
        temp->next = 0; //temp nodo isolato da inserire nella lista ordinata

        listaOrdinata = insOrd_ric(listaOrdinata, temp); //inserimento nodo nella lista ordinata
        return ord_ric(L, listaOrdinata);
    }
}
//POST=(restituisce una lista ordinata composta con tutti i nodi di L(n))

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
//POST=(restituisce una lista ordinata composta con tutti i nodi di L(n))

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

/*******************************************************************************************************************************************************************************
Prova induttiva della funzione 'elimOne2(nodo * L, int x)':
La correttezza di questa funzione ricorsiva (che chiameremo F) è dimostrata eseguendo un'ipotesi induttiva sulla funzione richiamata internamente, ovvero la stessa
funzione 'elimOne2(nodo * L, int x)' (che chiameremo G).

G riceve come parametri formali i parametri attuali alla chiamata da F, ovvero:
- L->next: nodo successivo di L, ovvero una lista ben formata e non vuota perchè la chiamata a G viene effettuata sse esiste L->next. Inoltre ogni nodo di della
        nuova Lista(L->next) ha info != x.
- x: intero che non viene modificato, quindi definito e uguale al parametro formale di F.
==> quindi G rispetta il PRE-condizione della funzione.

Entrambi i casi base di G rientrano nella definizione del POST-condizione di G:
- caso base 1: L->next != x ==> il prossimo elemento è diverso da x nel campo info, si esegue una chiamata ricorsiva in cui si passa Lista(L->next).
- caso base 2: il prossimo elemento è x nel campo info, tale nodo viene deallocato, il nodo attaule viene collegato con il nodo successivo dell'elemento deallocato.
==> viene quindi passato la Lista(L) ricevuta da G con tutti i nodi di vLista(L) a parte tutti quelli con info = x e questi nodi vengono anche deallocati.
Presumendo la corretteza del caso ricorsivo in G, abbiamo che G rispetta il POST-condizione della funzione.

Usando la correttezza di G, dimostro la correttezza di F:
In F si scorre ricorsivamente dal primo al penultimo elemento della lista L, controllando rispettivamente il secondo elemento della lista per ogni primo elemento della
lista passata alla funzione ricorsiva chiamata: in questo modo si controlla dal secondo all'ultimo nodo della lista L di partenza. Infatti non serve controllare anche
il primo elemento della lista iniziale perchè in tale nodo non potrà esserci x nel campo info (condizione definita dal PRE-condizione di G). Per ogni lista passata
alla funzione ricorsiva chiamata, si controlla che il secondo elemento sia diverso da x nel campo info, quindi si controlla che nella lista iniziale L dal secondo
        all'ultimo campo sia diversi da x nel campo info. Se la condizione non viene verificata, il relativo nodo viene deallocato, il nodo precedente viene collegato con il
nodo successivo dell'elemento deallocato.

==> dimostro così la corretteza della funzione F, e quindi anche di G. Viene dimostrato così la correttezza della funzione 'palindroma(char * S, int n)' rispetto al suo
        PRE e POST condizione.
*******************************************************************************************************************************************************************************/