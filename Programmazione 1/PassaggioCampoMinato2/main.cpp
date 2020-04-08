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
    for(int i=0; i<36;i++) {
        cin>>y[i];
    }
}
//POST=(inserito da input valori in tutte le posizioni di X)

//PRE=(X array bidimensionale di bool [6][6] definito fino almeno alla riga r >= 0)
void stampa_r(bool(*X)[6], int r) {
    cout<<"riga:"<<r<<'=';
    for(int i=0; i<6;i++) {
        cout<<X[r][i]<<' ';
    }
    cout << endl;
}
//POST=(stampato tutta la riga r)

//PRE=(X array bidimensionale di bool [6][6] definito fino alla riga r > 0)
void stampa(bool (*X)[6],int r) {
    for(int i=0; i<r; i++) {
        stampa_r(X,i);
    }
}
//POST=(stampato X fino alla riga r)

//PRE=(B1 array bidimensionale di bool [6][6] completamente definito, T array di int [6] non definito, j int >= 0)
void riempiCammino(bool (*B1)[6], int * T, int j) {
    T[5] = j;
    for (int i = 5; i > 0; --i) { //R
        if (j - 1 >= 0 && B1[i - 1][j - 1] == 1) {
            T[i - 1] = j - 1;
            j--;
        } else if (B1[i - 1][j] == 1) {
            T[i - 1] = j;
        } else if (j + 1 < 6 && B1[i - 1][j + 1] == 1) {
            T[i - 1] = j + 1;
            j++;
        }
    } //POST-R
}
//POST=(riempito tutti gli elementi di T corrispondenti ad una riga con il numero della colonna più a sinistra tale da formare un cammino)
//R=(0 < i <= 5) && (iterati tutte le righe di B1 eccetto la prima) && (j è la posizione della colonna attuale che forma il cammino) && (inserito in T nella cella corrispondente alla riga di B1, il numero della colonna che forma un cammino => T[i - 1] = j - 1 sse j - 1 >= 0 && B1[i - 1][j - 1] == 1, T[i - 1] = j sse B1[i - 1][j] == 1, T[i - 1] = j + 1 sse j + 1 < 6 && B1[i - 1][j + 1] == 1)

//PRE=(T array di int [6] completamente definito)
void stampaCammino(int *T) {
    for (int i = 0; i < 6; ++i) {
        cout << "riga " << i << ", colonna " << T[i] << endl;
    }
}
//POST=(stampato tutto T che indica un cammino che attraversi l'intera matrice)

int main() {
    bool B[6][6],B1[6][6], rigaTrue = true;
    leggi(B);
    for (int i = 0; i < 6; ++i) { //inizializzazione della prima riga di B1
        B1[0][i] = B[0][i];
    }

    int T[6], riga = 0;
    for (; riga < 5 && rigaTrue; ++riga) {
        newriga(B, B1, riga);
        if (tutta_false(B1, riga + 1)) {
            rigaTrue = false;
        }
    }

    stampa(B1,riga + 1);

    if(!rigaTrue) {
        cout<< "non c'e' cammino"<<endl;
    } else {
        cout<<"un cammino e':"<<endl;
        int j = 0;
        for (; j < 6 && B1[5][j] == 0; ++j); //cerco l'1 più a sinistra nell'ultima riga
        riempiCammino(B1, T, j);
        stampaCammino(T);
    }
}