#include<iostream>
using namespace std;

//PRE=(x array tridimensionale di int [3][4][5] definito solo nelle prime n_ele posizioni, fetta int >= 0 e <= 4)
void stampaH (int x[][4][5], int n_ele, int fetta) {
    int k, s; //k contiene il numero di elementi definiti nella riga da stampare
    for (int i = 0; i < 3; ++i) {
        s = 20 * i;
        if (n_ele - (fetta*5 + s) >= 5) { //tutta la riga è definita
            k = 5;
        } else { //definita parzialmente o non definita
            k = n_ele - (fetta*5 + s);
        }

        if (k <= 0) { //riga da stampare completamente vuota
            cout << "fetta richiesta vuota";
            return;
        } else { //riga da stampare completamente o parzialmente definita
            for (int j = 0; j < k; ++j) {
                cout << x[i][fetta][j] << ' ';
            }
            cout << endl;
        }
    }
}
//POST=(stampa solo gli elementi definiti della riga fetta di x)

//PRE=(x array tridimensionale di int [3][4][5] definito solo nelle prime n_ele posizioni, fetta int >= 0 e <= 5)
void stampaV (int x[][4][5], int n_ele, int fetta) {
    int s;
    for (int i = 0; i < 3; ++i) {
        s = 20 * i;
        if (n_ele <= fetta + s) { //colonna da stampare completamente vuota
            cout << "fetta richiesta vuota";
            return;
        } else { //colonna da stampare completamente o parzialmente definita
            for (int j = 0; j < 4; ++j) {
                if (n_ele > s + fetta + 5*j) { //elemento della colonna è definito
                    cout << x[i][j][fetta] << ' ';
                }
            }
            cout << endl;
        }
    }
}
//POST=(stampa solo gli elementi definiti della colonna fetta di x)

int main() {
  cout<<"start"<<endl;

  int A[3][4][5], *p =A[0][0], n_ele;
  cin >> n_ele;

  for(int i = 0; i < n_ele; i = i + 1) {
      cin >> p[i];
  }

   char c; //caratere: H o V
   int f; //fetta
   cin >> c >> f;

   if(c=='H') {
        //stampa H fetta
        stampaH(A, n_ele, f);
   } else {
       //stampa V fetta
       stampaV(A, n_ele, f);
   }

    cout<<"end"<<endl;
}

/*
 * Prova di correttezza di stampaH:
 * 1. Vengono iterati tutti gli strati di x in modo da stampare la riga fetta per ogni strato => (0 <= i < strati).
 * 2. Ad ogni iterazione degli strati vengono iterate tutte le colonne di x => (0 <= j < 5).
 * 3. Per ogni strato vengono quindi stampati tutti gli elementi della riga fetta in x: gli elementi della
 * riga fetta sono le colonne di x in cui vengono tenute fissate la riga fetta da stampare.
 * 4. Terminato di stampare una riga il ciclo interno che scorre le colonne termina perchè una riga ha lo stesso numero di elementi
 * del numero delle colonne, e si passa allo strato successivo.
 * 6. Terminato di scorrere gli strati, tutte le righe sono state stampate, e quindi si esce dal ciclo esterno e la  funzione termina.
 */