#include <iostream>
using namespace std;

//PRE=(A array di int [dim] indefinito con n int > 0)
void lettura(int A[], int n) {
    for (int i = 0; i < n; i++) { //R2
        cin >> A[i];
    } //POST-R2
}
//POST=(inserito dim elementi in A)
/*
    R2=(0 <= i <= n) && (letti dim valori in input e inseriti in A[0 ... n - 1])
    Prova di corretteza del ciclo R2:
    R2 sempre valido perchè i = 0 inizialmente e incrementato finchè i < n: R2 && !(i < n) => R2 && (i >= n) => i = n => inseriti n valori => POST
*/

//PRE=(A è array di int [n] completamente definito con n > 0)
int trovaPorz(int A[], int n) {
    int i = 0;
    while (i < n-1 && A[i] < A[i+1]) i++; //R1
    return ++i;
}
//POST=(restituisce il numero di elementi consecutivi e crescenti in A)
/*
    R1=(0 <= i <= n - 1) && (A[i ... n - 1] < A[i + 1 ... n]: elementi consecutivi crescenti)
    Prova di corretteza del ciclo R2:
    R1 sempre valido perchè i = 0 inizialmente e incrementato finchè i < n - 1: R1 && !(i < n - 1 && A[i] < A[i+1]) => R1 && (i >= n - 1 || A[i] >= A[i+1]) => i = n -1 || elementi consecutivi non crescenti => trovato numero di elementi consecutivi => POST
*/

int main() {
    int A[100];
    for (int i = 0; i < 100; i++) A[i] = 0;
    int n;
    cin >> n;
    lettura(A, n);
    cout << "k=" << trovaPorz(A, n) << endl;
}