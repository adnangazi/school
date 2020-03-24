#include<iostream>
using namespace std;

void stampaH (int x[][4][5], int n_ele, int fetta) {
    int k, s; //k contiene il numero di elementi definiti nella riga da stampare
    for (int i = 0; i < 3; ++i) {
        s = 20 * i;
        if (n_ele - (fetta*5 + s) >= 5) {
            k = 5;
        } else {
            k = n_ele - (fetta*5 + s);
        }

        if (k <= 0) { //riga da stampare completamente vuota
            cout << "fetta richiesta vuota";
            return;
        } else { //riga da stampare completamente o parzialmente definita
            for (int j = 0; j < k; ++j) {
                cout << x[i][fetta][j] << ' ';
            }
        }
        cout << endl;
    }
}

void stampaV (int x[][4][5], int n_ele, int fetta) {
    int k, s;
    for (int i = 0; i < 3; ++i) {
        s = 20 * i;
        if (n_ele <= fetta + s) { //colonna da stampare completamente vuota
            cout << "fetta richiesta vuota";
            return;
        } else { //colonna da stampare completamente o parzialmente definita
            for (int j = 0; j < 4; ++j) {
                if (n_ele > s + fetta + 5*j) {
                    cout << x[i][j][fetta] << ' ';
                }
            }
        }
        cout << endl;
    }
}

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

