#include<iostream>
using namespace std;

//PRE=(x è un array di int [righe][10] completamente definito, sc e rip sono indefiniti e sono la colonna più ripetuta e il numero di ripetizioni)
void superC(int x[][10], int righe, int & sc, int & rip) {
    int colonnaAttuale, ripCA; //ripetizioni colonnaAttuale
    bool colonneUguali;
    sc = 0, rip = 0;

    for (int i = 0; i < 9; ++i) { //R1
        colonnaAttuale = i, ripCA = 0;

        for (int j = i; j < 10; ++j) { //R2
            colonneUguali = true;

            for (int k = 0; k < righe; ++k) { //R3
                if (x[k][i] != x[k][j]) {
                    colonneUguali = false;
                }
            } //POST-R3

            if (colonneUguali) ripCA++;
        } //POST-R2

        //imposto la nuova superColonna e le sue ripetizioni
        if (ripCA > rip) {
            rip = ripCA;
            sc = colonnaAttuale;
        }
    } //POST-R1
}
//POST=(sc è la colonna di x[righe][10] che si ripete più volte tra le altre colonne, sc si ripete rip volte)

//R1=(0 <= i <= 9) && (impostato colonnaAttuale e ripCA) && (impostato la nuova superColonna e le sue ripetizioni: rip = ripCA e sc = colonnaAttuale sse ripCA > rip)
//R2=(0 <= i <= 10) && (colonneUguali) && (incrementato ripCA sse colonneUguali)
//R3=(0 <= i <= 5) && (controllato x[0...righe][i] != x[0...righe][j]) && (colonneUguali sse x[0...righe][i] = x[0...righe][j])

int main() {
    int X[5][10];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> X[i][j];
        }
    }
    int supc, rip;
    superC(X, 5, supc, rip);
    cout << "la super colonna è " << supc << " e ripete " << rip << " volte" << endl;
}