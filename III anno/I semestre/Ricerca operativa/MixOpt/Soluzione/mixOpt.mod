#DICHIARAZIONE INSIEMI
set Prodotti;
set Risorse;

#DICHIARAZIONE PARAMETRI
param MaxNumProd {Prodotti};	# massima produzione per prodotto
param P {Prodotti};				# profitto unitario
param Q {Risorse};				# disponibilità risorsa
param A {Prodotti,Risorse};		# risorsa per unità di prodotto

var x {i in Prodotti} integer >=0 , <=MaxNumProd[i];

maximize profitto: sum {i in Prodotti} P[i]*x[i];

subject to disponib {j in Risorse}:
	sum {i in Prodotti} A[i,j]*x[i] <= Q[j];


