#DICHIARAZIONE INSIEMI
set Risorse;
set Domande;

#DICHIARAZIONE PARAMETRI
param C {Risorse};				# costo unitario risorse
param D {Domande};				# ammontare domande
param A {Risorse,Domande};		# capacita` unitaria di risorsa di soddifare domanda

var x {Risorse} >=0 integer;

minimize costo: sum {i in Risorse} C[i]*x[i];

subject to soddisfazione {j in Domande}:
	sum {i in Risorse} A[i,j]*x[i] >= D[j];


