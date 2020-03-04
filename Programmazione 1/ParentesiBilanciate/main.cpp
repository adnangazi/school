#include<iostream>
using namespace std;
int main() {
    cout << "start"<<endl;

    string r1 = "la sequenza non e' bilanciata: ci sono parentesi aperte senza match";
    string r2 = "la sequenza non e' bilanciata: ci sono parentesi chiuse senza match";
    string r3 = "la sequenza e' bilanciata";
    char insert;
    int parentesi = 0;

    while (insert != '0') {
        cin >> insert;
        if (insert == '(') parentesi++;
        else if (insert == ')') parentesi--;
        if (parentesi < 0) {cout << r2 << endl << "end" << endl; return 0;}
    }

    if (parentesi > 0) cout << r1 << endl;
    else cout << r3 << endl;

    cout << "end"<<endl;
}
