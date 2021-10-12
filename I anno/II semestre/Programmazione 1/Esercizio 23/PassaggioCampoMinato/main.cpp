#include<iostream>
using namespace std;

//PRE=(X array bidimensionale di bool [6][6] definito solo fino alla riga r > 0)

bool tutta_false(bool (*X)[6], int r) {
    for (int i = 0; i < 6; ++i) {
        if (X[r][i] == 1) return false;
    }
    return true;
}
//POST=(true sse la riga r di X è composta solo da 0)


//PRE=(0 <= r <= 4) && (le righe r di B e B1 sono definite)
void newriga(bool (*B)[6], bool (*B1)[6],int r) { //r + 1 riga attuale: inserire in r
    for (int i = 0; i < 6; ++i) {
        B1[r + 1][i] = (B[r + 1][i] == 1 && (((i - 1) >= 0 && B[r][i - 1] == 1) || (B[r][i] == 1) || ((i + 1) < 6 && B[r][i + 1] == 1))) && (((i - 1) >= 0 && B1[r][i - 1] == 1) || (B1[r][i] == 1) || ((i + 1) < 6 && B1[r][i + 1] == 1));
    }
}
//POST=(calcola, nel modo descritto prima, la nuova riga r+1 di B1 usando la riga r+1 di B e la riga r di B1)

//PRE=(X array bidimensionale di bool [6][6] non definito)
void leggi(bool(*X)[6]) {
    bool * y=*X;
    for(int i=0; i<36;i++)
        cin>>y[i];
}
//POST=(inserito da input valori in tutte le posizioni di X)

//PRE=(X array bidimensionale di bool [6][6] definito fino almeno alla riga r >= 0)
void stampa_r(bool(*X)[6], int r) {
    cout<<"riga:"<<r<<'=';
    for(int i=0; i<6;i++)
        cout<<X[r][i]<<' ';
    cout << endl;
}
//POST=(stampato tutta la riga r)

//PRE=(X array bidimensionale di bool [6][6] definito fino alla riga r > 0)
void stampa(bool (*X)[6],int r) {
    for(int i=0; i<r; i++)
        stampa_r(X,i);
}
//POST=(stampato X fino alla riga r)

int main() {
    bool B[6][6],B1[6][6], rigaTrue = true;
    leggi(B);
    for (int i = 0; i < 6; ++i) { //inizializzazione della prima riga di B1
        B1[0][i] = B[0][i];
    }
    int riga = 0;
    for (; riga < 5 && rigaTrue; ++riga) {
        newriga(B, B1, riga);
        if (tutta_false(B1, riga + 1)) {
            rigaTrue = false;
        }
    }
    stampa(B1,riga + 1);
    if(!rigaTrue) {
        cout<< "non c'e' cammino"<<endl;
    }
    else {
        cout<<"c'e' cammmino"<<endl;
    }
}

/* Prova di correttezza di newriga:
 *
 *  Il PRE-condizione è verificato nel seguente modo:
 *      Alla funzione newriga vengono passati come parametri formali:
 *          B array bidimensionale di bool [6][6] completamente definito che rappresenta il campo minato con valori inseriti in input.
 *          B1 array bidimensionale di bool [6][6] definito solo fino alla riga r che rappresenta il campo calcolato dei possibili percorsi.
 *          r int che rappresenta la riga da considerare in B per calcolare la riga r + 1 di B1. 0 <= r <= 4 in quanto la funzione è chiamata in
 *          ogni iterazione del ciclo principale della funzione main(): questo ciclo itera per 5 volte usando come indice la variabile r, passata a newriga.
 *          Essendo r inizializzato a 0 e il ciclo valido finchè r < 5 il range di variazione di r è 0 <= r <= 4, quindi verificato.
 *
 *
 *  Il POST-condizione è verificato nel seguente modo:
 *      La funzione itera su tutte le colonne di B1 e per ogni colonna considera solo l'elemento della colonna che appartiene anche alla riga r:
 *      in questo modo si scorre su tutta la riga r. Su ogni elemento della riga r viene inserito un valore (0 o 1) a seconda che tale cella possa costituire
 *      o meno un possibile cammino nella matrice del campo minato (B): il corpo del ciclo consiste quindi di una semplice assegnazione della cella corrente
 *      in riga r (0 o 1 a seconda che le condizioni del cammino valido siano verificate).
 *
 *      Per controllare che il cammino sia valido, si considerano i seguenti parametri
 *      (tutti e 3 devono essere verificati affinchè la condizione del cammino valido sia verificata):
 *          -L'elemento attuale in B è true (1).
 *          -L'elemento sopra dell'elemento attuale in B sia true (1) o l'elemento sopra e a sinistra dell'elemento attuale
 *           (controllando che non si esca fuori dagli indici) in B sia true (1) o l'elemento sopra a destra dell'elemento attuale
 *           (controllando che non si esca fuori dagli indici) in B sia true (1).
 *          -L'elemento sopra dell'elemento attuale in B1 sia true (1) o l'elemento sopra e a sinistra dell'elemento attuale
 *           (controllando che non si esca fuori dagli indici) in B1 sia true (1) o l'elemento sopra a destra dell'elemento attuale
 *           (controllando che non si esca fuori dagli indici) in B1 sia true (1).
 *
 *      Eseguiti questi controlli il calcolo della validità della cella attuale è verificata, quindi pure la correttezza della funzione newriga.
 *      Quando si esce dal ciclo significa che le iterazioni sulla riga r di B1 sono terminate: è stato scorso tutta la riga e sono stati inseriti tutti
 *      i valori. Quindi è stato calcolato, nel modo descritto prima, la nuova riga r+1 di B1 di cammini validi e possibili, usando la riga r+1 di B e la
 *      riga r di B1, verificando il POST-condizione.
 */