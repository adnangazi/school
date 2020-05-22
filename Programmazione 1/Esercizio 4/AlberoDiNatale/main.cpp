#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n >= 3) {
        n--;
        int space = n - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < space-i; j++) cout << "b";//inserisce spazi vuoti
            for (int j = 0; j < ((i*2)+1); j++) cout << "s";//inserisce stelle
            cout << endl;
        }
        for (int j = 0; j < space; j++) cout << "b";//inserisce spazi vuoti alla base dell'albero
        cout << "s" << endl;//inserisce stelle alla base dell'albero

    } else cout << "Altezza non valida" << endl;
}
