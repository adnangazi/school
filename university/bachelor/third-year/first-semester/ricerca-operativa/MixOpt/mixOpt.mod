set Prodotti;
set Risorse;

param N {Prodotti} default 5;
param P {Prodotti};
param R {Risorse};
param A {Prodotti, Risorse};

var x {i in Prodotti} >= 0, <= N[i];

maximize rendita:
	sum {i in Prodotti} P[i] * x[i];

subject to disponib {j in Risorse}:
	sum {i in Prodotti} A[i, j] * x[i] <= R[j];