#include <iostream>
using namespace std;

void lettura(int A[], int n) {
    for (int i = 0; i < n; i++) cin >> A[i];
}

int trovaPorz(int A[], int n) {
    int i = 0;
    while (i < n-1 && A[i] < A[i+1]) i++;
    return ++i;
}

int main() {
    int A[100];
    for (int i = 0; i < 100; i++) A[i] = 0;
    int n;
    cin >> n;
    lettura(A, n);
    cout << "k=" << trovaPorz(A, n) << endl;
}