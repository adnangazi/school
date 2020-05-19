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