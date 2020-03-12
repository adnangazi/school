#include <iostream>
using namespace std;

void X2B(int x, int B[], int bit){
    for (int i = 0; i < bit; ++i, x/=2) if (x%2!=0) B[(bit-1)-i]=1;
}

void Y2B(float y, int B[], int bit){
    y*=2;
    for (int i = 0; i < bit; ++i, y*=2) if (((int)y)%2!=0) B[i]=1;
}

int main(){
    int X, B[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Y;
    cin >> X >> Y;
    X2B(X,B,4);
    Y2B(Y,B+4,6);
    for(int i=0; i<10; i++) cout<<B[i]<<' ';
    cout<<endl;
}