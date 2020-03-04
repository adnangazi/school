#include <iostream>
using namespace std;

bool parentesiAccavallate(char s[], int i) {
    int k = 0;//contatore delle parentesi chiuse pendenti
    char pp[50];//array parentesi chiuse pendenti: dimensione 50 perchè la sequenza di parentesi può avere al massimo elementi (50 parentesi aperte, 50 chiuse)
    for (int j = 0; j < i; j++) {
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
    }
    return false;
}

int main() {
    string a = "Troppe parentesi aperte";
    string b = "Troppe parentesi chiuse";
    string c = "Parentesi accavallate";
    string d = "Sequenza bilanciata";
    char s[100]; //array sequenza parentesi: dimensioni massime 100 parentesi
    char inserito;

    int ct = 0, cq = 0, cg = 0, i = 0;//conta tonde, conta quadre, conta graffe, contatore posizioni array parentesi

    while (inserito != '0') {
        cin >> inserito;

        if (inserito == '(') {ct++;  s[i++] = inserito;}
        else if (inserito == ')') {ct--; s[i++] = inserito;}
        else if (inserito == '[') {cq++; s[i++] = inserito;}
        else if (inserito == ']') {cq--; s[i++] = inserito;}
        else if (inserito == '{') {cg++; s[i++] = inserito;}
        else if (inserito == '}') {cg--; s[i++] = inserito;}

        if(ct < 0 || cq < 0 || cg < 0) {cout << b << endl; return 0;}
    }

    if(ct > 0 || cq > 0 || cg > 0) cout << a << endl;
    else if (parentesiAccavallate(s, i)) cout << c << endl;//tutti i contatori sono 0
    else cout << d << endl;
}