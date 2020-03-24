#include<iostream>
using namespace std;

//PRE=(x array tridimensionale di int [3][4][5] definito solo nelle prime n_ele posizioni, fetta int >= 0 e <= 4)
void stampaH (int x[][4][5], int n_ele, int fetta) {
    int k, s; //k contiene il numero di elementi definiti nella riga da stampare
    for (int i = 0; i < 3; ++i) {
        s = 20 * i;
        if (n_ele - (fetta*5 + s) >= 5) { //tutta la riga è definita
            k = 5;
        } else { //definita parzialmente o non definita
            k = n_ele - (fetta*5 + s);
        }

        if (k <= 0) { //riga da stampare completamente vuota
            cout << "fetta richiesta vuota" << endl;
            return;
        } else { //riga da stampare completamente o parzialmente definita
            for (int j = 0; j < k; ++j) {
                cout << x[i][fetta][j] << ' ';
            }
            cout << endl;
        }
    }
}
//POST=(stampa solo gli elementi definiti della riga fetta di x)

//PRE=(x array tridimensionale di int [3][4][5] definito solo nelle prime n_ele posizioni, fetta int >= 0 e <= 5)
void stampaV (int x[][4][5], int n_ele, int fetta) {
    int s;
    for (int i = 0; i < 3; ++i) {
        s = 20 * i;
        if (n_ele <= fetta + s) { //colonna da stampare completamente vuota
            cout << "fetta richiesta vuota" << endl;
            return;
        } else { //colonna da stampare completamente o parzialmente definita
            for (int j = 0; j < 4; ++j) {
                if (n_ele > s + fetta + 5*j) { //elemento della colonna è definito
                    cout << x[i][j][fetta] << ' ';
                }
            }
            cout << endl;
        }
    }
}
//POST=(stampa solo gli elementi definiti della colonna fetta di x)

int main() {
    cout<<"start"<<endl;

    int A[3][4][5], *p =A[0][0], n_ele;
    cin >> n_ele;

    for(int i = 0; i < n_ele; i = i + 1) {
        cin >> p[i];
    }

    char c; //caratere: H o V
    int f; //fetta
    cin >> c >> f;

    if(c=='H') {
        //stampa H fetta
        stampaH(A, n_ele, f);
    } else {
        //stampa V fetta
        stampaV(A, n_ele, f);
    }

    cout<<"end"<<endl;
}

/*
 * Prova di correttezza di stampaH:
 * 1. Vengono iterati tutti gli strati di x in modo da stampare la riga fetta per ogni strato => (0 <= i < 3).
 * 2. Ad ogni iterazione degli strati viene calcolato ai numeri che gli elementi della riga fetta corrispondono nell'ordine degli inserimenti in input.
 * 3. K viene assegnato a 5 (numero di elementi in una riga) se la riga è completamente definita, altrimenti al numero di elementi che riempono parzialmente
 * la riga oppure ad un numero negativo o zero se la riga è completamente vuota.
 * 4. In base ad un controllo sul valore di k si scorrono solo gli elementi definiti della riga da stampare.
 * 5. Se k <= 0 (riga vuota) si stampa un messaggio in uscita e la funzione viene fatta terminare.
 * 6. Altrimenti si scorrono k colonne (0 <= j < k) che, mantenendo fisso la riga fetta, indicano gli elementi definiti della riga.
 * 7. Tali elementi vengono stampati.
 * 8. Terminato di stampare una riga il ciclo interno che scorre le colonne termina perchè una riga ha lo stesso numero di elementi
 * del numero delle colonne, e si passa allo strato successivo.
 * 9. Terminato di scorrere gli strati, tutte le righe sono state stampate, e quindi si esce dal ciclo esterno e la  funzione termina.
 */