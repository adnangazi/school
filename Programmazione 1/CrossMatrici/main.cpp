#include<iostream>
using namespace std;

bool elementiComuni(int A1[][5], int A2[][5], int riga, int colonna) {
    //controllo ogni elemento della riga
    for (int i = 0; i < 5; ++i) { //R3

        //controllo ogni elemento della colonna
        for (int j = 0; j < 10; ++j) { //R4

            if (A1[riga][i] == A2[j][colonna]) { //trovato un elemento in comune: non serve continuare
                return true;
            }
        } //POST-R4
    } //POST-R3

    //trovato nessun elemento in comune
    return false;
}

void cross(int A1[][5], int A2[][5], bool B[][5]) {

    //riempio B per righe
    for (int i = 0; i < 10; ++i) { //R1
        for (int j = 0; j < 5; ++j) { //R2
            if (elementiComuni(A1, A2, i, j)) {
                B[i][j] = true;
            } else {
                B[i][j] = false;
            }
        } //POST-R2
    } //POST-R1

    //stampo B per righe
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }
}

void riempi(int A1[][5], int A2[][5]) {
    int inserito = 0;

    //riempio A1 per righe e A2 per colonne: x e y sono gli indici per A2
    for (int i = 0, x = 0, y = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {

            //y = 10 => fine colonna, riga successiva
            if (y >= 10) {
                y = 0;
                x++;
            }

            cin >> inserito;
            A1[i][j] = inserito;
            A2[y][x] = inserito;

            y++;
        }
    }

    //stampo A1 per righe
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << A1[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    //stampo A2 per righe
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << A2[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int A1[10][5], A2[10][5];
    riempi(A1,A2);
    bool B[10][5];
    cross(A1,A2,B);
}

/*
	R1=(0 <= i <= 10) && (incrementa i e itera sulle righe)
	R1 è vero ad ogni controllo del ciclo: inizialmente i = 0 e quando R1 && (i > 10) => iterato tutte le righe e riepito completamente B => POST

	R2=(0 <= j <= 5) && (B[0 ... 4][0 ... 9] sse ci sono elementi in comune tra A1[i][0 ... 9] e A2[0 ... 4][j]) && (incrementa j e itera sulle colonne)
	R2 è vero ad ogni controllo del ciclo: inizialmente j = 0 e quando R2 && (j > 5) => iterato tutte le colonne e riempito completamente B => POST

	R3=(0 <= i <= 5) && (incrementa i e itera sulla riga)
	R3 è vero ad ogni controllo del ciclo: inizialmente i = 0 e quando R3 && (i > 5) => iterato tutta la riga e cercato elemento comune => POST

	R4=(0 <= j <= 10) && (ritorna true sse trovato un elemento in comune tra  A1[riga][0 ... 9] e A2[0 ... 4][colonna]) && (incrementa j e itera sulla colonna)
	R4 è vero ad ogni controllo del ciclo: inizialmente j = 0 e quando R4 && (j > 10) => iterato tutta la colonna e cercato elemento comune => POST
*/
