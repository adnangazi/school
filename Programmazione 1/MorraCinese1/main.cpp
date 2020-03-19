#include<iostream>
using namespace std;
int main() {
    cout << "start"<<endl;

    char g1, g2;
    string v1 = "vince il giocatore 1";
    string v2 = "vince il giocatore 2";
    string p = "pareggio";
    string mnv = "mossa non valida";

    cin >> g1 >> g2;

    if (((g1 == 'f' || g1 == 's' || g1 == 'c') && (g2 == 'f' || g2 == 's' || g2 == 'c'))) {
        if (g1 == 's' && g2 == 'f') cout << v1 << endl;
        else if (g1 == 's' && g2 == 'c') cout << v2<< endl;
        else if (g1 == 's' && g2 == 's') cout << p << endl;
        else if (g1 == 'c' && g2 == 's') cout << v1 << endl;
        else if (g1 == 'c' && g2 == 'f') cout << v2 << endl;
        else if (g1 == 'c' && g2 == 'c') cout << p << endl;
        else if (g1 == 'f' && g2 == 'c') cout << v1 << endl;
        else if (g1 == 'f' && g2 == 's') cout << v2 << endl;
        else if (g1 == 'f' && g2 == 'f') cout << p << endl;

    } else cout << mnv << endl;

    cout << "end" << endl;
}