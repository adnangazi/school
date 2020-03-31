#include<iostream>
using namespace std;

//PRE=(y e z riferimento di interi definiti)
void scambia(int & y, int & z) {
    int scambio = y;
    y = z;
    z = scambio;
}
//POST=(Scambia il riferimento dell'elemento della V-fetta con quello della H-fetta)

//PRE=(p int puntatore al primo elemento di X e definito nelle prime n_ele posizioni, altri parametri sono interi e bool definiti)
int& TV(int*p, int lim1,int lim2, int lim3, int n_ele, int f, int n, bool & ok) {
    if (n_ele > lim1*lim2*lim3) {
        n_ele = lim1*lim2*lim3;
    }
    if ((lim3 * n + f) >= n_ele) {
        ok = false;
    }
    return p[lim3 * n + f];
}
//POST=(ok è true sse l'elemento della V-fetta è definita) && (restituisce il riferimento dell'elemento)

//PRE=(p int puntatore al primo elemento di X e definito nelle prime n_ele posizioni, altri parametri sono interi e bool definiti)
int& TH(int*p, int lim1,int lim2, int lim3, int n_ele, int f, int n, bool & ok) {
    if (n_ele > lim1*lim2*lim3) {
        n_ele = lim1*lim2*lim3;
    }
    int a = 0;
    while (n >= lim3) {
        a++;
        n -= lim3;
    }
    if ((f*lim3 + lim3*lim2*a + n) >= n_ele) {
        ok = false;
    }
    return p[f*lim3 + lim3*lim2*a + n];
}
//POST=(ok è true sse l'elemento della H-fetta è definita) && (restituisce il riferimento dell'elemento)

//PRE=(X int puntatore al primo elemento di X definito nelle prime n_ele posizioni, colonne intero definito)
void stampa(int*X, int n_ele, int colonne) {
    int nr=n_ele/colonne, resto=n_ele%colonne;
    for(int i=0; i<nr; i++) {
        for(int j=0; j<colonne; j++) {
            cout<< X[i*colonne+j]<<' ';
        }
        cout<<endl;
    }
    for(int i=0; i< resto; i++) {
        cout<< X[nr*colonne+i]<<' ';
    }
    cout<< endl;
}
//POST=(Stampa per strati X)

int main() {
    int X[100], lim1, lim2, lim3, n_ele;
    cin >>lim1 >> lim2 >> lim3 >> n_ele;
    for(int i = 0; i < n_ele; i++) {
        cin >> X[i];
    }
    bool stop = false, b1 = true,b2 = true;
    while (!stop) { //R
        int fV, nV, fH, nH;
        cin >> fV;
        if (fV == -1) {
            stop = true;
        } else {
            cin >> nV >> fH >> nH;
            int &y = TV(X, lim1, lim2, lim3, n_ele, fV, nV, b1);
            int &z = TH(X, lim1, lim2, lim3, n_ele, fH, nH, b2);
            if(b1 && b2) {
                scambia(y, z);
            } else {
                cout << "Operazione non consentita" << endl;
            }
        }
    } //POST-R
    stampa(X, n_ele, lim3);
}

/*
 * R=(stop != false per la prima volta) && (inserito la quadrupla da input) && (stop = true sse fv == -1) &&
 * (scambio elementi V-fetta e H-fetta sse gli elementi esistono e sono definiti) && (stampa messaggio di errore sse gli elementi esistono e sono definiti)
 *
 * 
 *
 * Prova di correttezza del ciclo R:
 *
*/