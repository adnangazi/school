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


nodo * faiL(int n) {
    if (n) {
        int x;
        cin >> x;
        return new nodo(x, faiL(n - 1));
    }
    return 0;

}

void stampa(nodo * L) {
    if (L) {
        cout << L->info << ' ';
        stampa(L->next);
    } else
        cout << endl;

}

nodo * clone(nodo * L) {
    if (L)
        return new nodo(L->info, clone(L->next));
    return 0;
}

nodo * ord_ric(nodo * L) {
    if (!L || !L->next) return L; //lista vuota o con un solo elemento ==> già ordinata

    //lista con 2 o più elementi rimasti
    if (L->info > L->next->info) {

    }
}

nodo * scorritore(nodo * a, int n) {
    for (int i = 0; i < n; ++i) {
        a = a->next;
    }

    return a;
}

void scambiatore(nodo *& a, nodo *& b) {
    nodo * temp = a;
    a = b;
}

nodo * ord_iter(nodo * P, int dim) { //bubble sort
    for (int i = 0; i < dim - 1; dim--) {
        for (int j = 0; j < dim - 1; ++j) {
            if (scorritore(P, j)->info > scorritore(P, j + 1)->info) {

            }
        }
    }

    return P;
}

int main() {
    int m;
    cin >> m;
    nodo * L = faiL(m);
    nodo * P = clone(L);

    L = ord_ric(L);
    P = ord_iter(P, m);
    stampa(L);
    stampa(P);
}
