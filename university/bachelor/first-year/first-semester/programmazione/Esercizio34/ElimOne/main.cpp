#include<iostream>
using namespace std;

struct nodo{
    int info;
    nodo* next;

    nodo(int a = 0, nodo * b = 0) {
        info = a;
        next = b;
    }
};

//PRE=(n intero definito)
nodo * faiL(int n) {
    if(n) {
        int x;
        cin >> x;
        return new nodo(x, faiL(n - 1));
    }

    return 0;
}
//POST=(restituito lista con n nodi con info inseriti da input)

//PRE=(L lista di nodi, anche vuoto)
void stampa(nodo * L) {
    if(L) {
        cout << L->info << ' ';
        stampa(L->next);
    } else {
        cout<<endl;
    }
}
//POST=(stampato Left-To-Right info dei nodi di L)

//PRE=(L lista di nodi, anche vuoto)
nodo * clone(nodo * L) {
    if (L) {
        return new nodo(L->info, clone(L->next));
    }

    return 0;
}
//POST=(restituisce copia di L)

//PRE=(Lista(L) ben formata)
nodo * elimOne(nodo * L, int x) { //restituito nuova lista modificata: termina appena trova nodo con info == x
    if (L) {
        if (L->info != x) {
            return new nodo (L->info, elimOne(L->next, x)); //caso ricorsivo: restituita nuova lista creata con nodi con info != x
        } else {
            nodo * temp = L->next;
            delete L;
            return temp; //caso base 1: restituito resto della lista ben formata
        }
    }

    return 0; //caso base 2: restituito una lista vuota
}
//POST=(restituisce una lista che contiene tutti i nodi di Lista(L) a parte il primo con info = x, che, se esiste, va anche deallocato)

//PRE=(Lista(L) ben formata e non vuota e col primo nodo tale che il suo campo info non sia x, vLista(L) = Lista(L))
void elimOne2(nodo * L, int x) { //modificato direttamente L: termina appena trova nodo con info == x
    if (L->next) {
        if (L->next->info != x) { //caso base 1
            elimOne2(L->next, x);
        } else { //caso base 2
            //swap con deallocazione dei nodi in HEAP
            nodo * temp = L->next;
            L->next = temp->next;
            delete temp;
        }
    }
}
//POST=(Lista(L) contiene tutti i nodi di vLista(L) a parte il primo con info = x, che, se esiste, va anche deallocato)

//PRE=(Lista(L) ben formata e VLista(L) = Lista(L))
void elimOne3(nodo *& L, int x) { //modificato direttamente L: termina appena trova nodo con info == x
    if (L) {
        if (L->info != x) { //caso base 1
            elimOne3(L->next, x);
        } else { //caso base 2
            //swap con deallocazione per riferimento dei puntatori ai nodi in HEAP
            nodo * temp = L->next;
            delete L;
            L = temp;
        }
    }
}
//POST=(Lista(L) è come vLista(L) a parte il primo nodo con info = x, che, se esiste, va anche deallocato)

int main() {
    int m, x;
    cin >> m >> x;
    nodo * L = faiL(m);
    //stampa(L);

    nodo * L2, * L3;
    L2 = clone(L);
    L3 = clone(L);

    if (L2->info == x) {
        L2 = new nodo(x + 1, L2);
    }

    L = elimOne(L, x);
    elimOne2(L2, x);
    elimOne3(L3, x);

    stampa(L);
    stampa(L2);
    stampa(L3);
}

/*******************************************************************************************************************************************************************************
    Prova induttiva della funzione 'elimOne2(nodo * L, int x)':
	La correttezza di questa funzione ricorsiva (che chiameremo F) è dimostrata eseguendo un'ipotesi induttiva sulla funzione richiamata internamente, ovvero la stessa
    funzione 'elimOne2(nodo * L, int x)' (che chiameremo G).

	G riceve come parametri formali i parametri attuali alla chiamata da F, ovvero:
		- L->next: nodo successivo di L, ovvero una lista ben formata e non vuota perchè la chiamata a G viene effettuata sse esiste L->next. Inoltre il primo nodo di della
		nuova Lista(L->next) ha info != x.
		- x: intero che non viene modificato, quindi definito e uguale al parametro formale di F.
	==> quindi G rispetta il PRE-condizione della funzione.

	Entrambi i casi base di G rientrano nella definizione del POST-condizione di G:
        - caso base 1: L->next != x ==> il prossimo elemento è diverso da x nel campo info, si esegue una chiamata ricorsiva in cui si passa Lista(L->next).
        - caso base 2: il prossimo elemento è x nel campo info, tale nodo viene deallocato, il nodo attaule viene collegato con il nodo successivo dell'elemento deallocato.
	==> viene quindi passato la Lista(L) ricevuta da G con tutti i nodi di vLista(L) a parte il primo con info = x e tale nodo viene anche deallocato.
        Presumendo la corretteza del caso ricorsivo in G, abbiamo che G rispetta il POST-condizione della funzione.

	Usando la correttezza di G, dimostro la correttezza di F:
		In F si scorre ricorsivamente dal primo al penultimo elemento della lista L, controllando rispettivamente il secondo elemento della lista per ogni primo elemento della
		lista passata alla funzione ricorsiva chiamata: in questo modo si controlla dal secondo all'ultimo nodo della lista L di partenza. Infatti non serve controllare anche
		il primo elemento della lista iniziale perchè in tale nodo non potrà esserci x nel campo info (condizione definita dal PRE-condizione di G). Per ogni lista passata
		alla funzione ricorsiva chiamata, si controlla che il secondo elemento sia diverso da x nel campo info, quindi si controlla che nella lista iniziale L dal secondo
		all'ultimo campo sia diversi da x nel campo info. Se la condizione non viene verificata, il relativo nodo viene deallocato, il nodo precedente viene collegato con il
		nodo successivo dell'elemento deallocato. Non appena viene trovato un elemento il cui campo info = x, il processo ricorsivo termina: il resto della lista da scorrere
		viene collegata con la parte iniziale della lista in cui non compare x nel campo info di nessun nodo.

	==> dimostro così la corretteza della funzione F, e quindi anche di G. Viene dimostrato così la correttezza della funzione 'palindroma(char * S, int n)' rispetto al suo
 PRE e POST condizione.
 *******************************************************************************************************************************************************************************/