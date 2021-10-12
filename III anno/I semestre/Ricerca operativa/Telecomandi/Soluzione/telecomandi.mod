#DICHIARAZIONE VARIABILI

var xA >= 0 , <= 5 integer;	# numero di telecomandi A
var xB >= 0 integer;	# numero di telecomandi B


#MODELLO

maximize 	profitto:	3 * xA + 6 * xB;

s.t.	display:	    xA + 2 * xB <= 10;
s.t.	navigation:	    xA          <= 9;
s.t. 	keyboard:	2 * xA + 3 * xB <= 21;
s.t.	logic: 	    2 * xA + 2 * xB <= 18;
s.t.	tx:			    xA + 3 * xB <= 12;
s.t.	led:            xA          <= 10;
