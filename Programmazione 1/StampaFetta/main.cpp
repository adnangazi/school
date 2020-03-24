#include<iostream>
using namespace std;

void stampaH (int x[][4][5], int strati, int fetta) {
    for (int i = 0; i < strati; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << x[i][fetta][j] << ' ';
        }
        cout << endl;
    }
}

void stampaV (int x[][4][5], int strati, int fetta) {
    for (int i = 0; i < strati; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << x[i][j][fetta] << ' ';
        }
        cout << endl;
    }
}

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