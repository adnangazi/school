#include <iostream>
typedef unsigned int uint;

class Orario {
	private:
		uint sec;
	
	public:
		//COSTRUTTORI
		Orario(const uint ore, const uint minuti, const uint secondi) {} //explicit
		Orario(const uint minuti, const uint secondi) {} //explicit
		Orario(const uint secondi = 0) {} //non-explicit
		
		Orario(const Orario & o) {
			sec = o.Secondi();
		}
		
		//GETTERS
		uint Ore() const {
			return sec / 3600;
		}
		
		uint Minuti() const {
			return (sec / 60) % 60;
		}
		
		uint Secondi() const {
			return sec % 60;
		}
		
		//METODI PROPRIETARI DELLA CLASSE
		void IncrementaSecondi() {
			sec++;
		}
		
		void IncrementaMinuti() {
			sec += 60;
		}
		
		void IncrementaOre() {
			sec += 3600;
		}
		
		void DecrementaSecondi() {
			if (sec > 0) {
				sec--;
			} else {
				sec = 0;
			}
		}
		
		void DecrementaMinuti() {
			if (sec >= 60) {
				sec -= 60;
			} else {
				sec = 0;
			}
		}
		
		void DecrementaOre() {
			if (sec >= 3600) {
				sec -= 3600;
			} else {
				sec = 0;
			}
		}

		void ImpostaSecondi(const uint secondi = 0) {
			sec -= (sec - secondi);
		}
		
		void ImpostaMinuti(const uint minuti = 0) {
			sec -= (Minuti() - minuti) * 60;
		}
		
		void ImpostaOre(const uint ore = 0) {
			sec -= (Ore() - ore) * 3600;
		}		
};

//OPERATORI DI CALCOLO
Orario operator= (const Orario & a, const Orario & b) {
	if (a != b) {
		a(b);
	}
	return * this;
}

Orario operator+ (const Orario & a, const Orario & b) const {
	return Orario(a.Ore() + b.Ore(), a.Minuti() + b.Minuti(), a.Secondi() + b.Secondi());
}

Orario operator- (const Orario & a, const Orario & b) const {
	if (a >= b) { //a - b ==> a >= (0, 0, 0)
		return Orario(a.Ore() - b.Ore(), a.Minuti() - b.Minuti(), a.Secondi() - b.Secondi());
	} else {
		return Orario(); //default (0, 0, 0)
	}
}

//OPERATORI DI CONFRONTO
bool operator== (const Orario & a, const Orario & b) const {
	return a.Ore() == b.Ore() && a.Minuti() == b.Minuti() && a.Secondi() == b.Secondi();
}

bool operator<= (const Orario & a, const Orario & b) const {
	if (a.Ore() < b.Ore()) {
		return true;
	} else if (a.Ore() == b.Ore()) {
		if (a.Ore() < b.Ore()) {
			return true;
		} else if (a.Ore() == b.Ore()) {
			if (a.Ore() < b.Ore()) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool operator< (const Orario & a, const Orario & b) const {}

bool operator>= (const Orario & a, const Orario & b) const {}

bool operator> (const Orario & a, const Orario & b) const {}

bool operator!= (const Orario & a, const Orario & b) const {}

//OPERATORI DI STAMPA
std::ostream & operator<< (std::ostream & os, const Orario & o) const {}