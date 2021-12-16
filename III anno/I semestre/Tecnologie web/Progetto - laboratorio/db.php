<?php
	namespace DB; // insieme di nomi a funzioni

	class DBAccess {
		private const HOST_DB = "127.0.0.1"; // a qualunque macchina sul localhost
		private const DATABASE_NAME = "agazi"; // coincide per creazione a nome utente
		private const USERNAME = "agazi"; // coincide con nome utente db
		private const PASSWORD = "HeYool1zai2iePoh"; // password db (HeYool1zai2iePoh) o password utente (Adnan23!) ?

		private $connection;
		public function openDBConnection () {
			// mysql"i"
			$this->connection = mysqli_connect(DBAccess::HOST_DB, DBAccess::USERNAME, DBAccess::PASSWORD, DBAccess::DATABASE_NAME); // stabilisce la connessione dentro la variabile
			if (mysqli_connect_errno($this->connection)) { // controlla sulla buona riuscita della connesione
				return false;
			} else {
				return true;
			}
		}

		public function closeDBConnection() {
			mysqli_close($this->connection); // chiusura della connessione direttamente dalla variabile con dentro la connessione
		}

		public function getCharacterList() {
			$query = "SELECT * FROM personaggi ORDER BY ID ASC"; // si possono fare strighe parametriche per query con contenuto runtime
			$queryResult = mysqli_query($this->connection, $query) or die("Errore in getCharacterList: " . mysqli_error($this->connection)); // eseguo query nellla stringa sulla connessione e carico il risultato il formato stringa sulla variabile. Se vado in errore abortisco il processo e stampo un messaggio d'errore in cui includo la catch automatica di errore rilevata da mysqli 
			
			// tutto quello che c'è qua sotto viene effettuato solo se il passaggio precedente riesce correttamente
			if (mysqli_num_rows($queryResult) != 0) {
				$result = array();
				while ($row = mysqli_fetch_assoc($queryResult)) { // ogni riga è un array associativo con chiave il nome del campo e valore il valore del campo e viene messa in row
					array_push($result, $row); // ogni riga viene messo in una cella di result
				}
				$queryResult->free(); // libero questa variabile perchè molto pesante
				return $result;
			} else { // più efficiente così perchè il ramo then è quello eseguito prima dal processo e al tempo stesso deve essere quello più probabile che avvenga
				return null; // verrà considerata come stringa vuota (corrretto perchè non ho risultati) e in più faccio sapere che non sono stati restituiti righe dalla query
			}
		}
	}

	// funzione cancella
	// funzione inserisce
	public function insertNewCharacter($nome, $colore, $peso, $potenza, $ab, $abr, $absw, $abs, $descrizione) {
		$stringaQuery="INSERT personaggi(nome, colore, peso, potenza, angry_birs, angry_birs_rio, angry_birs_star_wars, angry_birs_space) INTO VALUES(\"$nome\")";

		$risultato = msqli_query($this->connection, $stringaQuery) or die(msqli_error($this->connection));
		if (msqli_affected_rows($this->connection) > 0) {
			return true;
		} else {
			return false;
		}
	}

?>