#DICHIARAZIONE VARIABILI

var xM >= 0 integer;	# numero di magliette
var xB >= 0 integer;	# numero di borse


#MODELLO

maximize profitto: 24 * xM + 16 * xB;

s.t.	etichette:	    xM +  2 * xB <= 22;
s.t. 	riquadri:	6 * xM +  3 * xB <= 31;
s.t.	profilo:    2 * xM +  5 * xB <= 40;
s.t.	bottoni:	          2 * xB <= 15;
s.t.	magliette:      xM           <= 10;
s.t.	borse:                    xB <= 15;
