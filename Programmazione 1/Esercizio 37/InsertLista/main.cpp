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
    Prova induttiva della funzione 'nodo * insOrd_ric(nodo * L, nodo * x)':
	La correttezza di questa funzione ricorsiva (che chiameremo F) è dimostrata eseguendo un'ipotesi induttiva sulla funzione richiamata internamente, ovvero la stessa
    funzione 'nodo * insOrd_ric(nodo * L, nodo * x)' (che chiameremo G).

	G riceve come parametri formali i parametri attuali alla chiamata da F, ovvero:
		- L->next: nodo successivo di L passato per riferimento, ovvero una lista ben formata anche vuota.
		- X: lista ben formata anche vuota.
	==> quindi G rispetta il PRE-condizione della funzione.

	Entrambi i casi base di G rientrano nella definizione del POST-condizione di G:
        - caso base 1: restituisco L(L) perchè L(X) vuoto, quindi nessun elemento da inserire
        - caso base 2: restituisco L(X) perchè L(L) vuoto, quindi la nuova lista sarà formata solo da L(X)
        - caso ricorsivo 1: restituisco L(L) dopo aver inserito L(X) nella posizione corretta di L(L)
        - caso ricorsivo 2: dopo aver trovato la posizione in cui inserire L(X) e aver fatto l'inserimento, restituisco L(x) @ L(L1): L(L1) è il resto di L(L) dopo L(x), in modo
        da assegnare al nodo precedente di L(L) o restituire la nuova lista modificata
    ==> quindi se in L(L) c’è un nodo X da inserire, allora la funzione scorre ricorsivamente L(L) fino a trovare la posizione in in cui inserire L(X), inserisce tale nodo e
    restituisce vL(L) con X aggiunto in modo che la nuova lista sia ancora ordinata ==> G rispetta il POST-condizione della funzione.

	Usando la correttezza di G, dimostro la correttezza di F:
		In F si scorre ricorsivamente L(L) finchè non si trova la posizione in cui inserire L(X): trovato tale posizione si inserisce il nodo modificando il nodo precedente e
		quello successivo di L(L) e si restituisce la nuova lista per return. Per trovare la posizione in cui inserire L(X) si sfrutta il fatto che L(L) è ordinato in ordine
		crescente, quindi si scorrono i nodi di L(L) da sinistra verso destra finchè x->info <= L->info, ovvero non si trova un nodo di L con info maggiore dell'info di X.
		Vengono controllati ad ogni chiamata ricorsiva i casi limite: quindi se si arriva alla fine di L(L), L(X) verrà inserito automaticamente come nodo finale. Se l'info di
		non è maggiore dell'info primo nodo di L(L) allora L(X) viene inserito come primo nodo di L(L) perchè significa che nessun nodo di L(L) può essere minore di L(X).
		Si controlla anche che L(X) sia definito.

	==> dimostro così la corretteza della funzione F, e quindi anche di G. Viene dimostrato così la correttezza della funzione 'nodo * insOrd_ric(nodo * L, nodo * x)' rispetto al
 suo PRE e POST condizione.
 *********************************************************************************************************************************************************************************/