#include <iostream>
using namespace std;

//PRE=(S array di caratteri di lunghezza n >= 0 visto come stringa)
bool palindroma(char * S, int n) {
    if (n > 2 && *S == *(S + (n - 1))) { //caso ricorsivo --> per ogni carattere fino a metà stringa controllo che il suo prossimo sia palindromo
        return palindroma(S + 1, n - 2);
    } else if (*S == *(S + (n - 1))) { //base 1 --> stringa palindroma
        return true;
    } else { //base 2 --> stringa non palindroma
        return false;
    }
}
//POST=(ritorna true sse S e' palindroma)

int main() {
    int lung;
    char S[100];
    cin.getline(S, 100); // legge una riga di caratteri da cin
    lung = cin.gcount() - 1; // gcount ritorna il numero di caratteri letti(compreso il terminatore '\n')

    if (palindroma(S, lung)) {
        cout << "la stringa e' palindroma" << endl;
    } else {
        cout << "la stringa non e' palindroma" << endl;
    }
}

/********************************************************************************************************************************************************************
    Prova induttiva della funzione 'palindroma(char * S, int n)':
	La correttezza di questa funzione ricorsiva (che chiameremo F) è dimostrata eseguendo un'ipotesi induttiva sulla funzione
    richiamata internamente, ovvero la stessa funzione 'palindroma(char * S, int n)' (che chiameremo G).

	G riceve come parametri formali i parametri attuali alla chiamata da F, ovvero:
		- S + 1: array di caratteri di lunghezza >= 0, in quanto la chiamata ricorsiva avviene sse la lunghezza si S > 2 ==> S + 1
		è un array di dimensione positiva
		- n - 2: intero >= 0, in quanto la chiamata ricorsiva avviene sse n > 2 ==> n - 2 >= 0
	==> quindi G rispetta il PRE-condizione della funzione.

	Entrambi i casi base di G rientrano nella definizione del POST-condizione di G:
		- caso base 1: return true sse stringa palindroma in tutti gli elementi
		- caso base 2: return false sse stringa non palindroma ad un quanlunque elemento.
	==> presumendo la corretteza del caso ricorsivo in G (che avviene sse n > 2), abbiamo che G rispetta il POST-condizione della funzione.

	Usando la correttezza di G, dimostro la correttezza di F:
		In F, se la lunghezza della stringa è <= 2, si passa direttamente ai casi base:
		- caso base 1: return true sse il primo e l'ultimo elemento sono uguali:
			- se la stringa ha dimensione 1, il primo e l'ultimo elemento coincidono, e quindi sono uguali ==> palindromo.
			- se la striga ha dimensione 2, la stringa è palindroma se il primo elemento coincide con il secondo (anche ultimo) elemento.
		- caso base 2: return false sse il caso base 1 non è verificato ==> stringa di dimensione 2 con primo e ultimo elemento diversi.
		- altrimenti si effttua lo stesso processo in una chiamata alla stessa funzione, in cui si considera una stringa con 2 elementi in meno (i due agli estremi).

	==> dimostro così la corretteza della funzione F, e quindi anche di G. Viene dimostrato così la correttezza della funzione 'palindroma(char * S, int n)'
    rispetto al suo PRE e POST condizione.
 ********************************************************************************************************************************************************************/