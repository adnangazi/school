#include <iostream>
using namespace std;

//PRE=(B array di int [10] completamente definito, bit e x int che indicano i bit designati e il valore da convertire)
void X2B(int x, int B[], int bit){
    for (int i = 0; i < bit; ++i, x/=2) { //R1
        if (x%2!=0) B[(bit-1)-i]=1;
    } //POST-R1
}
//POST=(conversione di x in binario in B[0 ... bit -1])
/*
    R1=(0 <= i <= bit) && (convertito x in binario e inserito in A[0 ... bit - 1])
    Prova di corretteza del ciclo R1:
    R2 sempre valido perchè i = 0 inizialmente e incrementato finchè i < bit: R1 && !(i < bit) => R1 && (i >= bit) => i = bit => convertito x e inserito in tutti i bit disponibili => POST
*/

//PRE=(B array di int [10] completamente definito, bit e y int che indicano i bit designati e il valore da convertire)
void Y2B(float y, int B[], int bit){
    y*=2;
    for (int i = 0; i < bit; ++i, y*=2) { //R2
        if (((int)y)%2!=0) B[i]=1;
    } //POST-R2
}
//POST=(conversione di y in binario in B[0 ... bit -1])
/*
    R2=(0 <= i <= bit) && (convertito y in binario e inserito in A[0 ... bit - 1])
    Prova di corretteza del ciclo R2:
    R2 sempre valido perchè i = 0 inizialmente e incrementato finchè i < bit: R2 && !(i < bit) => R2 && (i >= bit) => i = bit => convertito y e inserito in tutti i bit disponibili => POST
*/

int main(){
    int X, B[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Y;
    cin >> X >> Y;
    X2B(X, B, 4);
    Y2B(Y, B + 4, 6);
    for(int i = 0; i < 10; i++) cout << B[i] << ' ';
    cout << endl;
}