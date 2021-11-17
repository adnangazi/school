#Esercizio Cup.mod

#set
set I;

#param
param C{I, I};
param T;

#variabili decisionali
var x {i in I} binary;

#funzione obiettivo
minimize costo: 
	sum{i in I} x[i];

#sistema di vincoli
s.t. cover{i in I}:
	sum{i in I : C[i, j] <= T} x[j] >= D[1];