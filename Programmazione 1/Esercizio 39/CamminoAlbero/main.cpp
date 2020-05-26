#include<iostream>
using namespace std;

struct nodo {
    int info;
    nodo * left;
    nodo * right;

    nodo (int x = 0, nodo * l = 0, nodo * r = 0) {
        info = x;
        left = l;
        right = r;
    }
};

//FUNZIONI AUSILIARIE FORNITE
//PRE=(arr array di interi dim n definito e >= 0, i intero definito)
nodo * buildTree (int arr[], int i, int n) {
    if (i >= n) {
        return NULL;
    }
    nodo * root = new nodo(arr[i]);
    root->left = buildTree(arr, 2 * i + 1, n); //insert left child
    root->right = buildTree(arr, 2 * i + 2, n); //insert right child
    return root;
}
//POST=(return albero binario costruito con gli elementi di arr)

//PRE=(root albero binario ben formato)
int height (nodo * root) {
    if (!root) {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}
//POST=(return altezza dell'albero)

//PRE=(r albero binario ben definito)
void stampa_l (nodo * r) {
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
void sc (int * C) {
    cout << *C << ' ';
    if (*C != -1) {
        sc(C + 1);
    }
}
//POST=(stampa tutti i valori dell'array fino a sentinella -1)
//FINE FUNZIONI AUSILIARIE FORNITE

//PRE=(albero(r) è ben formato e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi quanta è l'altezza di albero(r))
bool cerca_cam (nodo * r, int k, int y, int * C) {
    //scorrimento dell'albero per profondità in modo prefisso
    if (r->info == y) { //conto occorrenze di nodi con info == y
        k--;
    }
    if (r->left || r->right) { //r nodo interno
        if (r->left) {
            *C = 0;
            bool temp = cerca_cam(r->left, k, y, C + 1); //caso ricorsivo 1: scorro ramo sinistro e salvo risultato del sottoalbero del nodo attuale
            if (temp) return true; //caso base 1: trovato cammino corretto
        }
        if (r->right) {
            *C = 1;
            bool temp = cerca_cam(r->right, k, y, C + 1); //caso ricorsivo 2: scorro ramo destro e salvo risultato del sottoalbero del nodo attuale
            if (temp) return true; //caso base 2: trovato cammino corretto
        }
    } else { //r foglia
        *C = -1; //sentinella
        return k == 0; //caso base 3: trovato cammino corretto sse ci sono esattamente k occorrenze di nodi con info == y
    }

    return false; //caso base 4: non trovato nessun cammino corretto nel sottoalbero del nodo attuale
}
//POST= (restituisce true sse in albero(r) esiste un cammino da r ad una foglia con esattamente k nodi con campo info=y e false altrimenti) &&(in caso restituisca true, C contiene una sequenza (anche vuota) di 0/1 seguita da -1 e che individua il cammino più a sinistra in albero(r) con esattamente k nodi con campo info=y)

int main () {
    int dim;
    cin >> dim;
    int * a = new int[dim];
    for (int i = 0; i < dim; i++) {
        cin >> a[i];
    }
    nodo * root = NULL;
    root = buildTree(a, 0, dim);
    stampa_l(root);
    cout << endl;
    int h = height(root);
    int * C = new int[h];

    int k, val;
    cin >> val >> k;

    bool b = cerca_cam(root, k, val, C);
    cout << endl;
    if (b) {
        cout << "trovato  cammino= ";
        sc(C);
        cout << endl;
    } else {
        cout << " nessun cammino con " << k << " valori=" << val << endl;
    }
}
