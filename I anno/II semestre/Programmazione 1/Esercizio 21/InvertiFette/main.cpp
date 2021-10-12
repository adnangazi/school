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
        n_ele = lim1*lim2*lim3; //considero al massimo tutti gli elementi dell'array
    }
    if ((lim3 * n + f) >= n_ele) { //non sono stati inseriti elementi fino all'elemento della V-fetta indicata
        ok = false;
    }
    return p[lim3 * n + f];
}
//POST=(ok è true sse l'elemento della V-fetta è definita) && (restituisce il riferimento dell'elemento)

//PRE=(p int puntatore al primo elemento di X e definito nelle prime n_ele posizioni, altri parametri sono interi e bool definiti)
int& TH(int*p, int lim1,int lim2, int lim3, int n_ele, int f, int n, bool & ok) {
    if (n_ele > lim1*lim2*lim3) {
        n_ele = lim1*lim2*lim3; //considero al massimo tutti gli elementi dell'array
    }
    int a = 0; //quoziente della divisione intera n:lim3
    while (n >= lim3) { //divisione intera n:lim3
        a++;
        n -= lim3;
    } //n è il resto della divisione intera n:lim3
    if ((f*lim3 + lim3*lim2*a + n) >= n_ele) { //non sono stati inseriti elementi fino all'elemento della H-fetta indicata
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
 * R=(stop == true per la prima volta) && (inserito la quadrupla da input) && (stop = true sse fv == -1) && (scambio elementi V-fetta e H-fetta sse gli elementi esistono e sono definiti) && (stampa messaggio di errore sse gli elementi non esistono o non sono definiti)
 *
 * POST-R=(eseguito operazioni di scambio elementi V-fetta/H-fetta sse l'operazione era consentita e finchè non inserita la sentinella)
 *
 * Prova di correttezza del ciclo R:
 *  R vero la prima che si entra nel ciclo perche inizialmente stop == false => stop != true
 *  R vero ogni volta successiva in cui si enta nel ciclo perchè in ciclo viene eseguito finchè fv == -1 => stop == true
 *  R vero l'ultima volta in cui si entra nel ciclo perchè R && !(!stop) => R1 && stop => inserita la sentinella che indica fine delle operazioni di scambio
*/