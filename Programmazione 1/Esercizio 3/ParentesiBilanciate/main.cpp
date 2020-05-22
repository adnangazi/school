#include<iostream>
using namespace std;
int main() {
    cout << "start"<<endl;

    string r1 = "la sequenza non e' bilanciata: ci sono parentesi aperte senza match";
    string r2 = "la sequenza non e' bilanciata: ci sono parentesi chiuse senza match";
    string r3 = "la sequenza e' bilanciata";
    char insert;
    int parentesi = 0;

    while (insert != '0') { //R
        cin >> insert;
        if (insert == '(') parentesi++;
        else if (insert == ')') parentesi--;
        if (parentesi < 0) {cout << r2 << endl << "end" << endl; return 0;}
    }

    if (parentesi > 0) cout << r1 << endl;
    else cout << r3 << endl;

    cout << "end"<<endl;
}
/*
    R=(0 <= i <= n*2) && (letti valori in input e incrementati contatori parentesi aperte e chiuse)
    Prova di corretteza del ciclo R:
    R sempre valido perchè nessun '0' inserito prima: R && !(i < n*2) => R && (i >= n*2) => i = n*2 => giocato il numero massimo di volte necessarie per decretare il vincitore => POST
*/