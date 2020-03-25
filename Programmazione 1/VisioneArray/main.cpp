#include<iostream>
using namespace std;

//PRE=(x array di int [n_ele] completamente o parzialmente definito; strato, lim2, lim3 int >= 0)
void stampaS(int strato, int lim2, int lim3, int n_ele, int x[]) {
    for (int i = 0; i < lim2; ++i) {
        if (n_ele >= strato * lim2 * lim3 + lim3 * i) { //ci sono righe da stampare
            cout << "r" << i << ":";
            for (int j = 0; j < lim3; ++j) {
                if (n_ele > strato * lim2 * lim3 + lim3 * i + j) { //ci sono elementi da stampare
                    cout << x[strato * lim2 * lim3 + lim3 * i + j] << ' ';
                } else { //non ci sono elementi da stampare: termino la stampa
                    cout << endl;
                    return;
                }
            }
            cout << endl;
        } else { //non ci sono righe da stampare: termino la stampa
            return;
        }
    }
}
//POST=(stampa tutti gli elementi definiti in x corrispondenti allo strato 'strato' di un array trimensionale di lim2 righe e lim3 colonne per strato)

int main() {
    int n_ele, lim1, lim2, lim3, X[400];
    cin >> n_ele;

    for(int i = 0; i < n_ele; i = i + 1) {
        cin >> X[i];
    }

    cin >> lim1 >> lim2 >> lim3;
    cout << "start" << endl;
    //da fare
    for (int i = 0; i < lim1; ++i) {
        if (n_ele >= i * lim2 * lim3) { //ci sono strati da stampare
            cout << endl << "strato" << i << endl;
            stampaS(i, lim2, lim3, n_ele, X);
        } else { //non ci sono strati da stampare: termino la stampa
            cout << "end" << endl;
            return 0;
        }
    }
    cout << "end" << endl;
}

/*
 * Prova di correttezza di stampaS:
 * 1. La funzione deve stampare tutti gli elementi definiti in x corrispondenti allo strato 'strato' di un array trimensionale di lim2 righe
 * e lim3 colonne per strato (POST condizione).
 * 2. La funzione viene chiamata ogni volta che bisogna stampare uno strato di elementi dell'array tridimensionale.
 * 3. Si hanno 2 cicli annidati: quello esterno itera sulle righe dello strato dell'array, quello interno itera per ogni riga sulle colonne dell'array:
 * quindi scorre tutti gli elementi di una stessa riga, e assieme al ciclo più esterno, scorrono su tutto lo strato dell'array tridimensionale.
 * 4. Prima di cominciare a stampare una riga o un elemento di una riga, viene controllato che ci siano abbastanza elementi nella tale riga o che
 * l'elemento da stampare sia definito: viene fatto lo stesso controllo anche per gli strati.
 * 5. Quindi vengono effettuate le stampe solo se ci sono elementi definiti da stampare negli strati, nelle righe o nelle colonne:
 * in caso contrario la funzione viene fatto terminare in quanto se l'elemento attuale non è definito, allora nessuno degli elementi successivi lo sarà.
 * 6. Se la funzione termina significa che o non ci sono più elementi definiti da stampare o che si è iterato su tutto lo strato (righe e colonne)
 * dell'array tridimensionale. In ogni caso si arriva al post-condizione.
*/