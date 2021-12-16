<?php
	require_once "db.php"; // include se non già inscluso altri file
	use DB\DBAccess; // permette di usare il namespace (e in particolare il namespace relativo alla classe DBAccess) della pagina inclusa

	// prendere il risultato dal db

	// impaginarlo

	$paginaHTML = file_get_contents("protagonisti_php.html");

	$connessione = new DBAccess();
	$connessioneOK = $connessione->openDBConnection();
	$listaPersonaggi = ""; // contenuto dinamico hmtl
	$personaggi = ""; // risultati query

	if ($connessioneOK) {
		$personaggi = $connessione->getCharacterList();
		$connessione->closeConnection();
		if ($personaggi != null) {
			$listaPersonaggi = '<dl id="CharactersStory">';
			foreach ($personaggi as $personaggio) {
				$listaPersonaggi .= '<dt>' . personaggio['nome'] . '</dt><dd><img src="images/' . $personaggio['immagine'] . '"/><p>' . $personaggio['descrizione'] . '</dd>'; // manca alt e lang, che però devono esserci nel db
			}
			$listaPersonaggi .= '</dl>';
		} else {
			$listaPersonaggi = "<p>Non ci sono informazioni relative ai personaggi!</p>";
		}
	} else {
		$listaPersonaggi = "<p>I sistemi sono al momento non disponibili, riprova più tardi!</p>";
	}

	echo str_replace("<listaPersonaggi/>", $listaPersonaggi, $paginaHTML); // cambio il codice html mediante sostituzione del segnaposto messo originariamente con il risultato ottenuto dal db. Stampa tutto con echo (visualizza sul web perchè carica una pagina html)
?>