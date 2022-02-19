# esercizio contadino

# variabili decisionali
var xL >= 0;
var xP >= 0;

# funzione obiettivo
maximize rendita: 3000 * xL + 5000 * xP;

# sistema di vincoli
subject to ettari: xL + xP <= 11;
s.t. semi: 7 * xL <= 70;
s.t. patate: 3 * xP <= 18;
s.t. fertilizzate: 10 * xL + 20 * xP <= 145;