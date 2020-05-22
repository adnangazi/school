#include<iostream>
using namespace std;

//PRE=(A array di int [dim] indefinito con dim int > 0)
void leggi(int A[],int dim){
  int i=0;
  while(i < dim) { //R2
      cin>>A[i++];
  } //POST-R2
}
//POST=(inserito dim elementi in A)
/*
    R2=(0 <= i <= dim) && (letti dim valori in input e inseriti in A[0 ... dim - 1])
    Prova di corretteza del ciclo R2:
    R2 sempre valido perchè i = 0 inizialmente e incrementato finchè i < dim: R2 && !(i < dim) => R2 && (i >= dim) => i = dim => inseriti dim valori => POST
*/

//PRE=(A array di int [dimA] completamente definito, P array di int [dimP] completamente definito, macth array di int [2] completamente definito e inizio int definito)
void patternMatcher (int A[], int P[], int match[], int inizio, int dimA, int dimP) {
	int p = 0, fine = inizio;//p indice di P
	for(; fine < dimA && p < dimP; fine++) if(A[fine] == P[p]) p++;
	if(p == dimP){//trovato tutti gli elementi di P in A
		if(match[1] == -1 || fine - inizio < match[1]){
			match[0] = inizio;//inizio
			match[1] = fine - inizio;//lunghezza
		}
	}
}
//POST=(inseriti in 'match' la lunghezza del match maggiore e l'indice di inizio)

//PRE=((A array di int [dimA] completamente definito, P array di int [dimP] completamente definito, macth array di int [2] completamente definito)
void trovaInizi (int A[], int P[], int match[], int dimA, int dimP) {
	int matchTrovati[dimA], x = 0;//x indice di matchTrovati
	for(int i = 0; i < dimA; i++) if(A[i] == P[0]) matchTrovati[x++] = i;
	for(int i = 0; i < x; i++) patternMatcher(A, P, match, matchTrovati[i], dimA, dimP);
}
//POST=(trova inizi di ogni match parziale tra P e A)

int main() {
  int A[100],P[20],dimA,dimP;
  cin>>dimA>>dimP;
  leggi(A,dimA);
  leggi(P,dimP);
  int match[2] = {-1, -1};//pos 0: inizio, pos 1: lunghezzaMinima
  trovaInizi(A, P, match, dimA, dimP);
  if(match[1]==-1) cout<<" nessun match trovato"<<endl;
  else cout << "il miglior match inizia in " << match[0] << " e ha larghezza " << match[1] << endl;
}