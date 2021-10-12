#include<iostream>
using namespace std;

//PRE=(A array di int [dim] indefinito con dim int > 0)
void leggi(int A[],int dim) {
  int i = 0;
  while(i < dim) { //R2
    cin >> A[i++];
  } //POST-R2
}
//POST=(inserito dim elementi in A)
/*
    R2=(0 <= i <= dim) && (letti dim valori in input e inseriti in A[0 ... dim - 1])
    Prova di corretteza del ciclo R2:
    R2 sempre valido perchè i = 0 inizialmente e incrementato finchè i < dim: R2 && !(i < dim) => R2 && (i >= dim) => i = dim => inseriti dim valori => POST
*/

//PRE=(A array di int [dim] completamente definito con dim int > 0)
void trovaSottoArray(int A[], int dimA){
	int sequenzaCrescente = 1, lunghezzaMax = -1, inizio = -1;

	for(int i = 0; i < dimA - 1; i++) { //R1
		if(A[i] <= A[i + 1]) sequenzaCrescente++;
		else sequenzaCrescente = 1;
		if(sequenzaCrescente > lunghezzaMax){
			lunghezzaMax = sequenzaCrescente;
			inizio = i - (sequenzaCrescente - 2);
		}
	} //POST-R1
	cout << "il più lungo SC inizia in " << inizio << " e ha lunghezza " << lunghezzaMax << endl;
}
//POS=(stampato la lunghezza e l'indice di inizio della sequenza crescente più lunga)
/*
    R1=(0 <= i <= dim - 1) && (contato la lunghezza della sequenza crescente) && (impostata la nuova sequenza crescente maggiore sse sequenzaCrescente > lunghezzaMax)
    Prova di corretteza del ciclo R1:
    R1 sempre valido perchè i = 0 inizialmente e incrementato finchè i < dim - 1: R1 && !(i < dim - 1) => R1 && (i >= dim - 1) => i = dim - 1 => controllato la sequenza crescente più lunga in A[0 ... dim - 1] => POST
*/

int main(){
  int A[100],dimA;
  cin>>dimA;
  leggi(A,dimA);
  trovaSottoArray(A, dimA);
}