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
int match(int A[], int P[], int dimP, int inizio){
    int p = 0, i = inizio;
    for(; i < dimP + inizio && A[i] == P[p++]; i++);
    return (i - inizio);
}
//POST=(restituito la lunghezza del match tra A e P)

//PRE=(A array di int [dimA] completamente definto, P array di int [dimP] completamente definito, matcha array di int [2] non definito)
void trovaMatch(int dimA, int A[], int dimP, int P[], int matcha[]){
    int lunghezza[100], inizi[100];
    int x = 0,  max = 0, inizio = 0;
    for(int i = 0; i <= dimA - dimP; i++){
        if(A[i] == P[0]){
            lunghezza[x] = match(A, P, dimP, i);
            inizi[x++] = i;
        }
    }

    for(int i = 0; i < x; i++){
        if(lunghezza[i] > max){
            max = lunghezza[i];
            inizio = inizi[i];
        }
    }
    matcha[0] = max;
    matcha[1] = inizio;
}
//POST=(impostato in matcha lunghezza del match maggiore con l'indice di inizio in A)

int main() {
    int A[100],P[20], matcha[2],dimA,dimP,lungmax=0, inizio=-1;
    cin>>dimA>>dimP;
    leggi(A,dimA);
    leggi(P,dimP);

    trovaMatch(dimA, A, dimP, P, matcha);
    lungmax = matcha[0];
    inizio = matcha[1];

    cout<<"il massimo match ha lunghezza "<< lungmax<< " e inizia in posizione "<< inizio <<" di A"<<endl;
}