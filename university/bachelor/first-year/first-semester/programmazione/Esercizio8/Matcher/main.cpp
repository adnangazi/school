#include<iostream>
using namespace std;

//PRE=(A array di int [dim] indefinito con dim int > 0)
void leggi(int A[], int dim) {
    int i=0;
    while(i<dim) { //R2
        cin>>A[i++];
    } //POST-R2
}
//POST=(inserito dim elementi in A)
/*
    R2=(0 <= i <= dim) && (letti dim valori in input e inseriti in A[0 ... dim - 1])
    Prova di corretteza del ciclo R2:
    R2 sempre valido perchè i = 0 inizialmente e incrementato finchè i < dim: R2 && !(i < dim) => R2 && (i >= dim) => i = dim => inseriti dim valori => POST
*/

//PRE=(A array di int [dimA] completamente definto, P array di int [dimP] completamente definito, inizio int >= 0)
bool match(int A[], int P[], int dimP, int inizio) {
    int p = 0, i = inizio;
    for(; i < dimP + inizio && A[i] == P[p++]; i++);
    if(i == dimP + inizio) return true;
    else return false;
}
//POST=(restituito vero sse c'è match tra A e P)

//PRE=(A array di int [dimA] completamente definto, P array di int [dimP] completamente definito)
void trovaMatch(int dimA, int A[], int dimP, int P[]) {
    for(int i = 0; i < dimA - (dimP - 1); i++) if(A[i] == P[0] && match(A, P, dimP, i)) cout << "trovato match che inizia in posizione " << i << " di A" << endl;
}
//POST=(stampato ogni match trovato e la posizione di inizio)

int main() {
    int A[100],P[20],dimA,dimP;
    cin>>dimA>>dimP;
    leggi(A,dimA);
    leggi(P,dimP);
    trovaMatch(dimA, A, dimP, P);
}