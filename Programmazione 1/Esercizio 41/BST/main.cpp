#include<iostream>
#include "BST.h"

using namespace std;
using namespace BST;

int main() {
    //prepara un albero iniziale non triviale
    nodo * r = new nodo(15, new nodo(7), new nodo(19));
    r->left->right = new nodo(9, new nodo(8));
    r->right->right = new nodo(25, new nodo(22));

    bool stop = false;
    while (!stop) {
        int a;
        cin >> a;
        if (!a) break;

        switch (a) {
            case 1:
                stampa_l(r); cout << endl; break;
            case 2:
                int d; cin >> d; r = insert(r, d); stampa_l(r); cout << endl; break;
            case 3:
                int b; cin >> b; search(r, b)? cout << "valore " << b << " presente": cout << "valore " << b << " non presente"; cout << endl; break;
            case 4:
                int c; cin >> c; (c == 1)? cout << max(r)->info: cout << min(r)->info; cout << endl; break;
            case 5:
                cout << altezza(r) << endl; break;
            case 6:
                cout << altMin(r) << endl; break;
        }
    }
}