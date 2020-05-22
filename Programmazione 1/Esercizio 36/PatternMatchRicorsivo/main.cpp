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

//PRE=(L(T) e L(P) sono ben formate)
nodo * matchCompleto(nodo *& T, nodo * P) {
    if (!T) return 0; //caso base 1: match completo e contiguo non trovato

    if ((T->info == P->info) && (!P->next || matchCompleto(T->next, P->next))) { //effettuo controllo ricorsivo finchè match contiguo
        T = T->next; //ricucio il taglio in T
        return P; //caso base 2:
    }

    return 0; //caso base 3: match completo e contiguo non trovato
}
//POST=()

//PRE =(L(T) e L(P) sono ben formate)
nodo * match(nodo *& T, nodo * P) {
    //impossibile trovare match completo e contiguo su liste vuote
    if (!T || !P) return 0; //base 1: restituisco lista vuota (0) perchè impossibile trovare match

    if (T->info == P->info) { //trovato match completo e contiguo
        nodo * a = matchCompleto(T, P);
        if (a) return a; //base ricorsiva 1: ricucisco il buco in T e restituisco la lista del match completo e contiguo
    }

    return match(T->next, P); //base ricorsiva 2: scorro ricorsivamente T finchè non trovo un inizio di match completo e contiguo e restiuisco il risultato di tale match
}
//POST=(se in T c’è un match di P contiguo e completo, allora la funzione estrae i nodi del match più a sinistra e la restituisce col return mentre T è la lista che resta, se non c’è match la funzione restituisce 0 e L(T) non cambia)

int main() {
    int m, n;
    cin >> m >> n;
    nodo * T = faiL(m);
    nodo * P = faiL(n);
    P = match(T, P);
    stampa(P);
    stampa(T);
}

/*********************************************************************************************************************************************************************************
    Prova induttiva della funzione 'nodo * match(nodo *& T, nodo * P)':
	La correttezza di questa funzione ricorsiva (che chiameremo F) è dimostrata eseguendo un'ipotesi induttiva sulla funzione richiamata internamente, ovvero la stessa
    funzione 'nodo * match(nodo *& T, nodo * P)' (che chiameremo G).

	G riceve come parametri formali i parametri attuali alla chiamata da F, ovvero:
		- L->next: nodo successivo di L passato per riferimento, ovvero una lista ben formata anche vuota.
		- P: lista ben formata anche vuota.
	==> quindi G rispetta il PRE-condizione della funzione.

	Entrambi i casi base di G rientrano nella definizione del POST-condizione di G:
        - caso base 1: restituisco una lista vuota (0) perchè impossibile trovare match, in quanto la lista in cui controllare il match completo e contiguo o la lista degli elementi
        del match completo e contiguo o entrambi sono vuoti.
        - caso ricorsivo 1: trovato un match completo e contiguo di P in T (è anche quello più a sinistra) ==> ricucisco il buco in T in modo che il nuovo T sia formato dai nodi di
        T originale tranne che dai nodi del match completo e contiguo e restituisco la lista del match completo e contiguo.
        - caso ricorsivo 2: se non ho trovato un inizio di match completo e contiguo in T di P scorro ricorsivamente T finchè non trovo un inizio di match completo e contiguo e
        restiuisco il risultato di tale match.
    ==> quindi se in T c’è un match di P contiguo e completo, allora la funzione estrae i nodi del match più a sinistra e la restituisce col return mentre T è la lista che resta,
    se non c’è match la funzione restituisce 0 e L(T) non cambia ==> G rispetta il POST-condizione della funzione.

	Usando la correttezza di G, dimostro la correttezza di F:
		In F si scorre ricorsivamente la lista T fino a che non si trova un match completo e contiguo di P in T oppure fino alla fine della lista, ovvero finechè non si arriva al
		nodo nullo, per verificare non ci siano match completi e contigui. In questo ultimo caso T non viene modificato e viene restituito una lista vuota, che indica la presenza
		di nessun match completo tra T e P. In caso di trovi un inizio di match completo si chiama una funzione ausiliaria che controlla che ci sia un match completo e contiguo
		di P in T a partire dal nodo attuale di T in cui è stato trovato l'inizio di match. La funzione ausiliaria restituisce una lista vuota se non è stato trovato un match
		completo e contiguo a partire da tale nodo di T oppure restituisce la lista dei nodi del match completo e contiguo se tale match completo e contiguo è stato trovato.
		Se è stato trovato un match continuo e contiguo, la funzione ausiliaria estrae i nodi del match da T, ricucendo la lista.
		F controlla che l'inizio del possibile match completo e contiguo corrisponda ad un effettivo match completo e contiguo: in tale caso viene restituito la lista dei match,
		altrimenti si continua a scorrere su T in cerca di altri match continui e contigui.

	==> dimostro così la corretteza della funzione F, e quindi anche di G. Viene dimostrato così la correttezza della funzione 'nodo * match(nodo *& T, nodo * P)' rispetto al suo
 PRE e POST condizione.
 *********************************************************************************************************************************************************************************/