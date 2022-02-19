#include<iostream>
using namespace std;

struct nodo {
    int info;
    nodo * left;
    nodo * right;

    nodo(int x = 0, nodo * l = 0, nodo * r = 0) {
        info = x;
        left = l;
        right = r;
    }
};

//FUNZIONI AUSILIARIE FORNITE
//PRE=(arr array di interi dim n definito e >= 0, i intero definito)
nodo * buildTree(int arr[], int i, int n) {
    if (i >= n) {
        return NULL;
    }
    nodo * root = new nodo(arr[i]);
    root->left = buildTree(arr,  2 * i + 1, n); //insert left child
    root->right = buildTree(arr, 2 * i + 2, n); //insert right child
    return root;
}
//POST=(return albero binario costruito con gli elementi di arr)

//PRE=(root albero binario ben formato)
int height(nodo * root) {
    if (!root) {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}
//POST=(return altezza dell'albero)

//PRE=(r albero binario ben definito)
void stampa_l(nodo * r) {
    if (r) {
        cout << r->info << '(';
        stampa_l(r->left);
        cout << ',';
        stampa_l(r->right);
        cout << ')';
    } else {
        cout << '_';
    }
}
//POST=(stampa r scorrendolo in profondità in modo prefisso)

//PRE=(C intero puntatore al primo elemento di un array)
void sc(int * C) {
    cout << *C << ' ';
    if (*C != -1) {
        sc(C + 1);
    }
}
//POST=(stampa tutti i valori dell'array fino a sentinella -1)
//FINE FUNZIONI AUSILIARIE FORNITE

//PRE=(albero(r) ben formato, 0 <= n <= k, k > 0)
int stampaASPre(nodo * r, int n, int k) {
    if (n == 0) { //saltati n nodi
        cout << r->info << ' ';
        n = k;
    }
    if (r->left) {
        n = stampaASPre(r->left, --n, k) + 1; //caso ricorsivo 1: scorro ramo sinistro e salvo risultato del sottoalbero del nodo attuale
    }
    if (r->right) {
        n = stampaASPre(r->right, --n, k) + 1; //caso ricorsivo 2: scorro ramo destro e salvo risultato del sottoalbero del nodo attuale
    }

    return n - 1; //caso base 1: return numero di nodi mancanti per arrivare al prossimo nodo da stampare
}
//POST=(considerando I nodi di albero® in ordine prefisso, salta n nodi e poi stampa quello successivo e dopo ne salta k-1 e poi stampa il successivo, restituisce il numero di nodi che vanno saltati nelle successive parti dell’albero)

//PRE=(albero(r) ben formato, 0 <= n <= k, k > 0)
int stampaASInf(nodo * r, int n, int k) {
    if (r->left) {
        n = stampaASInf(r->left, n, k); //caso ricorsivo 1: scorro ramo sinistro e salvo risultato del sottoalbero del nodo attuale
    }
    if (n == 0) { //saltati n nodi
        cout << r->info << ' ';
        n = k - 1;
    } else { //nuovo nodo scorso in modo infisso
        n--;
    }
    if (r->right) {
        n = stampaASInf(r->right, n, k); //caso ricorsivo 1: scorro ramo destro e salvo risultato del sottoalbero del nodo attuale
    }

    return n; //caso base 1: return numero di nodi mancanti per arrivare al prossimo nodo da stampare
}
//POST=(considerando I nodi di albero® in ordine prefisso, salta n nodi e poi stampa quello successivo e dopo ne salta k-1 e poi stampa il successivo, restituisce il numero di nodi che vanno saltati nelle successive parti dell’albero)

int main() {
    int dim;
    cin >> dim;
    int * a = new int[dim];
    for (int i = 0; i < dim; i++) {
        cin >> a[i];
    }
    nodo * root = NULL;
    root = buildTree(a, 0, dim);
    //stampa_l(root);

    int k;
    cin >> k;

    int a1 = stampaASPre(root, k - 1, k);
    cout << " con avanzo " << a1 << endl;
    int b1 = stampaASInf(root, k - 1, k);
    cout << " con avanzo " << b1 << endl;
}