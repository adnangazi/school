#include<iostream>
using namespace std;

//PRE=(A array di int [dimA] completamente definito con dimA > 0, x e i int > 0 che indicano l'elemento da eliminare e l'indice attuale)
void elimina(int A[], int & dimA, int x, int i) {
    while (i < dimA) { //R2
        if (A[i] != x) {
            i++;
        } else {
            for (int j = i; j < dimA - 1; ++j) {
                A[j] = A[j + 1];
            }
            dimA--;
        }
    } //POST-R2
}
//POST=(eliminato ogni occorrenza di x in A[i...dimA] e modificato la dimensione dell'array)
/*
  R1=(0 < = i <= dimA) && (eliminato ogni occorrenza di x in A[i ... dimA])
  Prova di correttezza del ciclo R1:
  R1 sempre vero perchè i = 0 inizialmente e incrementato finchè i < dimA: R2 && !(i < dimA) => R2 && (i >= dimA) => i = dimA => eliminato tutte le occorrenze di x in A[i ... dimA] => POST
*/

//PRE=(A array di int [dimA] completamente definito con dimA > 0)
void togliDoppi(int A[], int & dimA) {
    int i = 0;

    while (i < dimA - 1) { //R1
        elimina(A, dimA, A[i], i + 1);
        i++;
    } //POST-R
}
//POST=(eliminate tutte le occorrenze doppie in A[0...dimA-1])
/*
  R1=(0 < = i <= dimA - 1) && (eliminato ogni occorrenza di A[i] in A[i + 1 ... dimA])
  Prova di correttezza del ciclo R1:
  R1 sempre vero perchè i = 0 inizialmente e incrementato finchè i < dimA - 1: R1 && !(i < dimA - 1) => R1 && (i >= dimA - 1) => i = dimA - 1 => eliminato tutte le occorrenze doppie in A[0 ... dimA - 1] => POST
*/

int main() {
    int A[20], dimA, i=0;
    cin >> dimA;
    while(i < dimA) {
        cin >> A[i];
        i = i + 1;
    }
    togliDoppi(A, dimA);
    i=0;
    while(i<dimA) {
        cout << A[i] << ' ';
        i=i+1;
    }
    cout<<endl;
}