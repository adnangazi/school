#include <iostream>
using namespace std;

//PRE=(s array di char [i] completamente definito di parentesi)
bool parentesiAccavallate(char s[], int i) {
    int k = 0;//contatore delle parentesi chiuse pendenti
    char pp[50];//array parentesi chiuse pendenti: dimensione 50 perchè la sequenza di parentesi può avere al massimo elementi (50 parentesi aperte, 50 chiuse)

    for (int j = 0; j < i; j++) { //R2
        if (s[j] == '(') pp[k++] = ')';
        else if (s[j] == '[') {pp[k++] = ']';}
        else if (s[j] == '{') {pp[k++] = '}';}
        else if (s[j] == ')') {
            if (pp[k-1] == ')') k--;
            else return true;
        }
        else if (s[j] == ']') {
            if (pp[k-1] == ']') k--;
            else return true;
        }
        else if (s[j] == '}') {
            if (pp[k-1] == '}') k--;
            else return true;
        }
    } //POST-R2
    return false;
}
//POST=(restituito vero sse non c'è alcuna parentesi accavallata)
/*
    R2=(0 <= j <= i) && (inseriti o tolti le parentesi pendenti in base alle parentesi in s[0 ... i - 1])
    Prova di correttezza del ciclo R2:
    R2 sempre valido perchè j = 0 inizialmente e incrementato finchè j < i: R2 && !(j < i) => R2 && (j >= i) => j = i => controllati tutte le parentesi accavallate => POST
*/

int main() {
    string a = "Troppe parentesi aperte";
    string b = "Troppe parentesi chiuse";
    string c = "Parentesi accavallate";
    string d = "Sequenza bilanciata";
    char s[100]; //array sequenza parentesi: dimensioni massime 100 parentesi
    char inserito;

    int ct = 0, cq = 0, cg = 0, i = 0;//conta tonde, conta quadre, conta graffe, contatore posizioni array parentesi

    while (inserito != '0') { //R1
        cin >> inserito;

        if (inserito == '(') {ct++;  s[i++] = inserito;}
        else if (inserito == ')') {ct--; s[i++] = inserito;}
        else if (inserito == '[') {cq++; s[i++] = inserito;}
        else if (inserito == ']') {cq--; s[i++] = inserito;}
        else if (inserito == '{') {cg++; s[i++] = inserito;}
        else if (inserito == '}') {cg--; s[i++] = inserito;}

        if(ct < 0 || cq < 0 || cg < 0) {cout << b << endl; return 0;}
    } //POST-R1

    if(ct > 0 || cq > 0 || cg > 0) cout << a << endl;
    else if (parentesiAccavallate(s, i)) cout << c << endl;//tutti i contatori sono 0
    else cout << d << endl;
}
/*
    R1=(inserito carattere in input) && (aggiornato contatori delle parentesi in base alle parantesi aperte o chiuse inserite)
    Prova di correttezza del ciclo R1:
    R1 sempre valido perchè nessun '0' inserito prima: R1 && !(inserito != '0') => R1 && (inserito = '0') => inserito = '0', per la prima volta => inserito sentinella di fine ciclo
*/