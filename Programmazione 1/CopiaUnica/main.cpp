#include<iostream>
using namespace std;

void elimina(int A[], int & dimA, int x, int i) {
    while (i < dimA) {
        if (A[i] != x) {
            i++;
        } else {
            for (int j = i; j < dimA - 1; ++j) {
                A[j] = A[j + 1];
            }
            dimA--;
        }
    }
}

void togliDoppi(int A[], int & dimA) {
    int i = 0;
    while (i < dimA - 1) {
        elimina(A, dimA, A[i], i + 1);
        i++;
    }
}

int main() {
    int A[20], dimA, i=0;
    cin >> dimA;
    while(i < dimA) {
        cin >> A[i];
        i = i + 1;
    }
    togliDoppi(A, dimA);
    i=0;
    while(i<dimA) {
        cout << A[i] << ' ';
        i=i+1;
    }
    cout<<endl;
}