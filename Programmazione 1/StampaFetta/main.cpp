#include<iostream>
using namespace std;

//PRE=(x è array tridimensionale di int [strati][4][5] completamente definito, fetta è int >= 0 e <= 3)
void stampaH (int x[][4][5], int strati, int fetta) {
    for (int i = 0; i < strati; ++i) { //R1
        for (int j = 0; j < 5; ++j) { //R2
            cout << x[i][fetta][j] << ' ';
        } //POST-R2
        cout << endl;
    } //POST-R1
}
//POST=(stampa la riga fetta in x)

//PRE=(x è array tridimensionale di int [strati][4][5] completamente definito, fetta è int >= 0 e <= 4)
void stampaV (int x[][4][5], int strati, int fetta) {
    for (int i = 0; i < strati; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << x[i][j][fetta] << ' ';
        }
        cout << endl;
    }
}
//POST=(stampa la colonna fetta in x)

int main() {
  int A[3][4][5];

  for(int i=0; i<3; i=i+1) {
      for(int j=0; j<4; j=j+1) {
          for(int k=0; k<5; k=k+1) {
              cin >> A[i][j][k];
          }
      }
  }


  cout<<"start"<<endl;

  char c; //carattere: H o V
  int f; //fetta
  cin >> c >> f;

  if(c=='H') {
      //stampa H fetta f
      stampaH(A, 3, f);
  } else {
      //stampa V fetta f
      stampaV(A, 3, f);
  }

  cout<<"end"<<endl;
}

/*
 * R1=(0 <= i <= strati) && (itera negli strati di x)
 * POST-R1=(iterato tutti gli strati di x)
 *
 * R2=(0 <= j <= 5) && (itera nelle colonne di x) && (stampa tutte le colonne della riga fetta)
 * POST-R2=(iterato tutte le colonne di x && stampato riga fetta di x)
 *
 * Prova di correttezza di stampaH:
 * 1. Vengono iterati tutti gli strati di x in modo da stampare la riga fetta per ogni strato => (0 <= i < strati).
 * 2. Ad ogni iterazione degli strati vengono iterate tutte le colonne di x => (0 <= j < 5).
 * 3. Per ogni strato vengono quindi stampati tutti gli elementi della riga fetta in x: gli elementi della
 * riga fetta sono le colonne di x in cui vengono tenute fissate la riga fetta da stampare.
 * 4. Terminato di stampare una riga il ciclo interno che scorre le colonne termina perchè una riga ha lo stesso numero di elementi
 * del numero delle colonne, e si passa allo strato successivo.
 * 6. Terminato di scorrere gli strati, tutte le righe sono state stampate, e quindi si esce dal ciclo esterno e la  funzione termina.
 */