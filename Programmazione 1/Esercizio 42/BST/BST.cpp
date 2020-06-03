#include<iostream>
#include "BST.h"

using namespace std;
using namespace BST;

//PRE(r BST ben formato)
void BST::stampa_l(nodo * r) {
    if (r) { //c'è almeno 1 un elemento da stampare
        cout << r->info << '('; //caso base 1: stampa nodo centrale
        if (r->left) {
            stampa_l(r->left);
        } else {
            cout << '_';
        } //caso ricorsivo 1: stampa ramo sx
        cout << ',';
        if (r->right) {
            stampa_l(r->right); //caso ricorsivo 2: stampa ramo dx
        } else {
            cout << '_';
        }
        cout << ')';
    }
}
//POST=(stampa lineare-infissa dei nodi di r)

//PRE=(r BST ben formato, x intero definito)
nodo * BST::insert(nodo * r, int x){
    if (!r) {
        return new nodo(x); //caso base 1: BST vuoto ==> nodo con info == x è nuovo BST
    } else if (r->info >= x) {
        r->left = insert(r->left, x); //caso ricorsivo 1: scorro BST a sx e inserisco nodo con info == x
        return r;
    } else {
        r->right = insert(r->right, x); //caso ricorsivo 2: scorro BST a dx e inserisco nodo con info == x
        return r;
    }
}
//POST=(return BST ben formato con inserito nodo con info == x)

//PRE=(r BST ben formato, x intero definito)
bool BST::search(nodo * r, int x) {
    if (!r) {
        return false; //caso base 1: BST vuoto ==> elemento non trovato
    } else if (r->info == x) {
        return true; //caso base 2: radice è elemento cercato
    } else if (r->info > x) {
        return search(r->left, x); //caso ricorsivo 1: search e return true sse trovato nodo con info == x nel sotto-albero sx
    } else {
        return search(r->right, x); //caso ricorsivo 2: search e return true sse trovato nodo con info == x nel sotto-albero dx
    }
}
//POST=(return true sse trovato nodo con info == x in r)

//PRE(r BST ben formato)
nodo *& BST::max(nodo *& r) {
    return (!r)? r: (!r->right)? r: max(r->right); //caso ricorsivo 1: return 0 sse BST vuoto, radice sse non esiste sotto-albero dx, altrimenti return max nodo del sotto-albero dx
}
//POST=(return nodo in r con info massimo)

//PRE(r BST ben formato)
nodo *& BST::min(nodo *& r) {
    return (!r)? r: (!r->left)? r: min(r->left); //caso ricorsivo 1: return 0 sse BST vuoto, radice sse non esiste sotto-albero sx, altrimenti return max nodo del sotto-albero sx
}
//POST=(return nodo in r con info minimo)

//PRE=(a e b interi definiti)
int maxVal(int a, int b) {
    return (a >= b)? a: b;
}
//POST=(return maggiore tra a e b)

//PRE=(a e b interi definiti)
int minVal(int a, int b) {
    return (a <= b)? a: b;
}
//POST=(return minore tra a e b)

//PRE(r BST ben formato)
int BST::altezza(nodo * r) {
    return (!r)? -1: 1 + maxVal(altezza(r->left), altezza(r->right)); //caso ricorsivo 1: return -1 sse albero vuoto, altrimenti altezza maggiore tra altezza del sotto-albero sx e altezza del sotto-albero dx
}
//POST=(return altezza di r)

//PRE(r BST ben formato)
int BST::altMin(nodo * r) {
    return (!r)? -1: 1 + minVal(altezza(r->left), altMin(r->right)); //caso ricorsivo 1: return -1 sse albero vuoto, altrimenti altezza minore tra altezza del sotto-albero sx e altezza del sotto-albero dx
}
//POST=(return altezza minima di r)

//PRE=(r BST ben formato, x intero definito)
void BST::elim(nodo *& r, int x) {
    if (r) {
        if (r->info == x) { //radice è il nodo da eliminare
            if (r->left && r->right) { //caso c: nodo ha 2 figli
               nodo *& temp = min(r->right); //temp = minimo del sotto-albero dx del nodo da eliminare
               r->info = temp->info; //aggiustamento nuovo BST con eliminazione del nodo con info == x
               temp = 0;
            } else if (r->left || r->right) { //caso b: nodo ha 1 figlio
                r = (r->left)? r->left: r->right; //nodo eliminato e nuovo nodo è l'unico figlio left/right del nodo precedente
            } else { //caso a: nodo è foglia
                r = 0;
            }
        } else if (r->info > x) {
            elim(r->left, x); //caso ricorsivo 1: scorro BST nel sotto-albero sx
        } else {
            elim(r->right, x); //caso ricorsivo 2: scorro BST nel sotto-albero dx
        }
    }
}
//POST=(scorro in r fino a trovare nodo con info == x) && (imposto tale nodo a 0 sse è foglia, al figlio sse ha un solo figlio, altrimenti al nodo minimo del suo sotto-albero dx, che poi viene eliminato) && (eliminato da r nodo con info == x)