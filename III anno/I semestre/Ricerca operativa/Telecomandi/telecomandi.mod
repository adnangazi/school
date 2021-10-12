# model telecomandi

# variabili decisionali
var xA >= 0, <= 5 integer;
var xB >= 0 integer;

# funzione obiettivo
maximize rendita: 3 * xA + 6 * xB;

# sistema di vincoli
subject to display: xA + 2 * xB <= 10;
subject to logica: 2 * xA + 2 * xB <= 18;
subject to trasmissione: xA + 3 * xB <= 12;
subject to tastierini: 2 * xA + 3 * xB <= 21;
subject to navigazione: xA <= 9;
subject to led: xA <= 10;