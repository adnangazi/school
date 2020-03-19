#include<iostream>
using namespace std;

//PRE=(A array di int [dimA ] completamente definito con dimA > 0, x int > 0 da eliminare in A)
void elimina(int A[], int & dimA, int x){
    int i = 0;

    while (i < dimA) { //R
        if (A[i] != x) {
            i++;
        } else {
            for (int j = i; j < dimA - 1; ++j) {
                A[j] = A[j + 1];
            }
            dimA--;
        }
    } //POST-R
}
//POST=(occorrenze di x in A eliminati ed elementi in A mantenuti nel loro ordine originale)
/*
    R=(0 <= i <= dimA) && (compattati a sinistra tutti gli elementi in A[i ... dimA - 1] sse A[i] = x e modificato la dimensione dell'array) && (incrementato i sse A[i] != x)
    Prova di correttezza del ciclo:
    R sempre vero perchè i = 0 inizialmente e incrementato nel ciclo finchè i < dimA: R && (i >= dimA) => i = dimA => tutte le occorrenze di x in A[0 ... dimA - 1] eliminate => POST
*/


int main() {
    int A[20], dimA, x, i = 0;
    cin >> dimA;
    while (i < dimA) {
        cin >> A[i];
        i = i + 1;
    }
    cin >> x;
    elimina(A, dimA, x);
    i = 0;
    while (i < dimA) {
        cout << A[i] << ' ';
        i = i + 1;
    }
    cout << endl;
}