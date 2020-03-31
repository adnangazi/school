#include<iostream>
using namespace std;

//PRE=(A contiene una sequenza di interi che termina con -2 e che consiste di una serie (possibilmente vuota) di sottosequenze ciascuna delle quali termina con -1, inoltre n >=0)
int S(int*A, int n) {
    int lsc = 1; //lunghezza sottosequenza corrente
    int inizio = 0;

    //scorre tutti gli elementi inseriti
    for (int i = 0; A[i] != -2; ++i) { //R
        if (A[i] != -1) {
            lsc++;
        } else if (lsc == n) { //sottosequenza terminata ed è quella cercata
            return inizio;
        } else { //sottosequenza terminata ma non è quella cercata
            lsc = 1;
            inizio = i + 1;
        }
    } //POST-R
    return -2;
}
//POST=(se A contiene la sottosequenza n ed essa inizia in A[i], allora S restituisce i, altrimenti S restituisce -2)

int main() {
    int X[400];
    cin >> X[0];
    for(int i = 1; i < 400 && X[i - 1] != -2; i++) {
        cin >> X[i];
    }
    int n;
    cin >> n; //lunghezza della sottosequenza cercata
    cout << "start" << endl;
    int b = S(X, n);
    if(b == -2) {
        cout << "sottosequenza " << n << " non presente" << endl;
    } else {
        cout << "inizio sottosequenza " << n << " indice=" << b << endl;
    }
    cout << "end" << endl;
}

/*
 * R=(0 <= i && A[i] == -2 per la prima volta) && (itera sugli elementi di A) && (incrementa lunghezza sottosequenza corrente sse sotto sequenza corrente non è terminata, != -1) && (restituisce inizio se sottosequenza corrente è terminata ed è quella cercata) && (ricomncia il conteggio di una nuova sottosequenza sse sottosequenza corrente terminata ma non è quella cercata)
 *
 * Prova di correttezza di R:
 *  Se S verifica la PRE-condizione, allora quando termina verifica la POST-condizione perchè:
 *  R vero la prima volta che si entra nel ciclo perche inizialmento i == 0 && al massimo A[i] == -2 ma per la prima volta
 *  R vero ogni volta successiva in cui si enta nel ciclo perchè in ciclo viene eseguito finchè A[i] != -2
 *  R vero l'ultima volta in cui si entra nel ciclo o ad un qualunque stato del calcolo che fa terminare R, perchè R && !(0 <= i && A[i] == -2 per la prima volta) => R && (A[i] != -2 per la prima volta) => scorso A completamente => se A contiene la sottosequenza n ed essa inizia in A[i], allora S restituisce i, altrimenti S restituisce -2 => POST
*/