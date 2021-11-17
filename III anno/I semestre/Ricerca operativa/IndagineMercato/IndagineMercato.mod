#Esercizio IndagineMercato.mod

#set
set I;
set J;

#param
param C{I};
param D{I};
param A{I, J};

#variabili decisionali
var x {i in I} >= 0 integer;

#funzione obiettivo
minimize costo: 
	sum{i in I} C[i] * x[i];

#sistema di vincoli
s.t. cover{j in J}:
	sum{i in I} A[i, j] * x[i] >= D[j];