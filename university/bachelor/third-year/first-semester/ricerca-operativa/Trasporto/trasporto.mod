### TRASPORTO: modello ###
##########################

#INSIEMI
set I; 			# insieme delle origini
set J; 			# insieme delle destinazioni

#PARAMETRI
param C {I,J};	# costi unitari di trasporto
param O {I};	# disponibilita` presso le origini (capacita`)
param D {J};	# richiesta delle destinazioni

#VARIABILI
var x {I,J}	>= 0	integer;	# quantita` trasportate

#FUNZIONE OBIETTIVO
minimize 	costo_totale:	sum {i in I, j in J} C[i,j] * x[i,j];

#VINCOLI
subject to	origine {i in I}:
		sum{j in J} x[i,j] <= O[i];

subject to	destinazione {j in J}:
		sum{i in I} x[i,j] >= D[j];













