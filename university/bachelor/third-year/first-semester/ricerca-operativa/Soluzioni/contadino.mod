#DICHIARAZIONE VARIABILI

var xL;	#ettari a lattuga
var xP;	#ettari a patate


#MODELLO

maximize 	resa:	3000 * xL + 5000 * xP;

subject to	ettari:	xL + xP <= 11;
subject to	semi:	7 * xL <= 70;
s.t. 		tuberi:	3 * xP <= 18;
s.t.		conc: 	10 * xL + 20 * xP <= 145;
s.t.		dominio1: 	xL >= 0;
s.t.		dominio2: 	xP >= 0;

