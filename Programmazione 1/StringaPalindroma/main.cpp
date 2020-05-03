#include <iostream>
using namespace std;

//PRE=(S array di caratteri di lunghezza n >= 0 visto come stringa)
bool palindroma(char * S, int n) {
    if (n > 3) { //caso ricorsivo --> per ogni carattere fino a metà stringa controllo che il suo prossimo sia palindromo
        return palindroma(S + 1, n - 2);
    } else if (*S == *(S + (n - 1))) { //base 1 --> stringa palindroma
        return true;
    } else { //base 2 --> stringa non palindroma
        return false;
    }
}
//POST=(ritorna true sse S e' palindroma)

int main() {
    int lung;
    char S[100];
    cin.getline(S, 100); // legge una riga di caratteri da cin
    lung = cin.gcount() - 1; // gcount ritorna il numero di caratteri letti(compreso il terminatore '\n')

    if (palindroma(S, lung)) {
        cout << "la stringa e' palindroma" << endl;
    } else {
        cout << "la stringa non e' palindroma" << endl;
    }
}