### PRODUZIONE E DISTRIBUZIONE DI PC: modello ###
#################################################


#INSIEMI
set S; #insieme degli stabilimenti
set B; #insieme delle sedi bancarie

#PARAMETRI
param costo_produzione{S};      #costi unitari di produzione
param costo_spedizione{S,B};	#costi unitari di trasporto
param capacita{S};		        #produzione stabilimenti
param richiesta{B};		        #richiesta magazzini
param stab_bilan symbolic in S;	#stabilimento da bilanciare
param bilan1;			        #richiesta minima bilan / tutti
param bilan2;			        #richiesta minima bilan / ciascuno 

#VARIABILI
var x{S,B}	integer >= 0;		#numero PC trasportati

#FUNZIONE OBIETTIVO
minimize 	costo_totale:	
		sum {i in S, j in B} 
			(costo_produzione[i] + costo_spedizione[i,j]) 
			* x[i,j];

#VINCOLI
subject to	produzione {i in S}:
		sum{j in B} x[i,j] <= capacita[i];

subject to	domanda {j in B}:
		sum{i in S} x[i,j] = richiesta[j];

subject to	bilanciamento1 :
		sum{j in B} x[stab_bilan,j] >= bilan1 * sum{i in S, j in B} x[i,j];

subject to	bilanciamento2 { i in S : i != stab_bilan }:#{S diff {stab_bilan} } }:
		sum{j in B} x[stab_bilan,j] >= bilan2 * sum{jj in B} x[i,jj];
