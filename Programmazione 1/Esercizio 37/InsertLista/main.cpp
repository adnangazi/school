#include<iostream>

using namespace std;

struct nodo {
    int info;
    nodo * next;

    nodo (int a = 0, nodo * b = 0) {
        info = a;
        next = b;
    }
};

//PRE=(n intero definito)
nodo * faiL (int n) {
    if (n) {
        int x;
        cin >> x;
        return new nodo(x, faiL(n - 1));
    }

    return 0;
}
//POST=(restituito lista con n nodi con info inseriti da input)

//PRE=(L lista di nodi, anche vuoto)
void stampa (nodo * L) {
    if (L) {
        cout << L->info << ' ';
        stampa(L->next);
    } else {
        cout << endl;
    }
}
//POST=(stampato Left-To-Right info dei nodi di L)

//PRE=(Lista(L) ben formata e ordinata)
nodo * clone (nodo * L) {
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

    while (a) { //R
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
    } //POST-R

    return L; //L(L) = vL(L) @ L(x) ordinato
}
//POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata)

int main () {
    int m, x;
    cin >> m >> x;
    nodo * L = faiL(m);
    nodo * L1 = clone(L);

    L = insOrd_ric(L, new nodo(x));
    L1 = insOrd_iter(L1, new nodo(x));
    stampa(L);
    stampa(L1);
}

/*********************************************************************************************************************************************************************************
    R=(primo nodo di L(a) <= L(a) <= nodo nullo finale di L(a) && !inserito L(x)) &&
    (L(x) inserito all'inizio di L(a) sse x->info < info del primo nodo di a, e quindi degli info di tutti gli altri nodi) &&
    (L(x) inserito alla fine di L(a) sse x->info > info dell'ultimo nodo di a, e quindi degli info di tutti gli altri nodi) &&
    (L(x) inserito in mezzo ad  L(a) nella posizione in cui a->info <= x->info <= a->next->info) &&
    (a = a->next sse x->info > a->info && x->info > a->next->info)

    Prova di corretteza di R:
        - R vero la prima che si entra nel ciclo perche inizialmente L(a) = L(L), quindi lista ben formata (anche vuota) e quindi primo nodo di L(a) <= L(a) <= nodo nullo finale
        di L(a).
		- R vero ogni volta successiva in cui si enta nel ciclo perchè in ciclo viene eseguito fichè L(a) <= nodo nullo finale di L(a) e ad ogni loop a = a->next o la funzione
		viene fatto terminare col return perchè inserito L(x).
		- R vero l'ultima volta in cui si entra nel ciclo perchè R && !(primo nodo di L(a) <= L(a) < nodo nullo finale di L(a) && !inserito L(x)) =>
		R && ((L(a) > primo nodo di L(a) && L(a) > nodo nullo finale di L(a)) || inserito L(x)) =>
		(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata) => POST
*********************************************************************************************************************************************************************************/

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