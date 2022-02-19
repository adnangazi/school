#include<iostream>
using namespace std;

//PRE=(X contiene almeno n_ele elementi, n_ele, lim1, lim2 e lim3 sono >0, cin contiene n_ele valori)
void leggiV(int* x, int n_ele, int lim1, int lim2, int lim3) {
    int y = 0;
    for (int i = 0; i < lim3; ++i) {
            for (int z = 0; z < lim1*lim2*lim3; z += lim3) {
                if (y++ >= n_ele) return;
                cin >> x[z + i];
            }
        }
    }
//POST=(in X vista come int[lim1][lim2][lim3] sono stati letti gli n_ele valori di cin per V-fette)

void stampaS(int* x, int n_ele, int lim1, int lim2, int lim3, int strato) {
    if (n_ele > lim1*lim2*lim3) n_ele = lim1*lim2*lim3; //siccome sono stati inseriti al massimo lim1*lim2*lim3 elementi, se ne potranno stampare altrettanto
    for (int i = 0, k; i < lim2; ++i) { //scorro le righe dello strato indicato
        k = i + lim2*strato; //riga corrente di tutta la matrice
        bool newLine = true, endLine = false;
        for (int j = k*lim3, z = k; j < (k+1)*lim3; ++j) { //stampo gli elementi definiti della riga attuale
            if (z < n_ele) {
                if (newLine) {
                    cout << "r" << i << ": ";
                    newLine = !newLine;
                    endLine = !endLine;
                }
                cout << x[j] << ' ';
            }
            z += lim1*lim2;
        }
        if (endLine) cout << endl;
    }
}

int main() {
    int A[400], n_ele, lim1, lim2, lim3, strato;
    cin >> n_ele >> lim1 >> lim2 >> lim3 >> strato;
    leggiV(A, n_ele, lim1, lim2, lim3);
    stampaS(A, n_ele, lim1, lim2, lim3, strato);
}

/*
 *R1=(0 <= c <= lim3) && (0 <= i <= n_ele) && (itera sulle colonne)
 *R2=(0 <= s <= lim1) && (0 <= i <= n_ele) && (itera sugli strati)
 *R3=(0 <= r <= lim2) && (0 <= i <= n_ele) && (itera sulle righe) && (inserisce da input l'elemento in X vista come int[lim1][lim2][lim3])
 *
 *Prova di correttezza di leggiV:
 *1. I 3 cicli annidati permettono di simulare X visto come una matrice tridimensionale. Siccome bisogna inserire gli elementi per fetta, bisogna prima scorrere sulle colonne, poi sugli strati, e infine sulle righe.
 *2. Ogni ciclo viene fatto iterare su una dimensione della matrice tridimensionale controllando sempre ci siano ancora elementi da inserire.
 *3. Nel momento in cui termina l'iterazione dei 3 cicli significa che o sono stati inseriti tutti gli elementi, e quindi si può far terminare la funzione, oppure la matrice è completa, e anche in questo caso si può uscire dalla funzione.
 *4. In ogni caso la funzione è corretta perchè se terminati i cicli, significa che sono stati letti gli elementi utili e inseriti in X.
*/