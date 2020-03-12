#include <iostream>
using namespace std;

int X2B(int B[]){
    int x = 0;
    for (int i = 3, esp = 1; i >= 0; i--, esp *= 2) x += B[i]*esp;
    return x;
}

float Y2B(int B[]){
    float y= 0, esp = 0.5;
    for (int i = 0; i < 6; ++i, esp /= 2) y += B[i]*esp;
    return y;
}

int main(){
  int B[10];
  for(int i=0; i<10; i++) cin >>B[i];
  cout<<"value="<<X2B(B) + Y2B(B+4)<<endl;
}