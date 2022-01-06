<?php
	require_once "db.php"; // include se non già inscluso altri file
	use DB\DBAccess; // permette di usare il namespace (e in particolare il namespace relativo alla classe DBAccess) della pagina inclusa

	$paginaHTML = file_get_contents("nuovoProtagonistaFrom.html");

	$messaggi = "";
	$nome = "";
	$colore = "";
	$peso = "";
	$potenza = "";
	$descrizione = "";
	$edizioni = array();

	if (isset($_POST['submit'])) {
		$nome = $_POST['nome'];
		if (strlen($nome) == 0) {
			$messaggi .= "<li>Nome non presente</li>";
		} elseif (preg_match('/\d/', $nome)) {
			$messaggi .= "<li>Il nome non può contenere numeri</li>";
		}
		$nome = $_POST['colore'];
		if (strlen($colore) == 0) {
			$messaggi .= "<li>colore non presente</li>";
		} elseif (preg_match('/\d/', $colore)) {
			$messaggi .= "<li>Il colore non può contenere numeri</li>";
		}
		$nome = $_POST['peso'];
		if (strlen($peso) == 0) {
			$messaggi .= "<li>peso non presente</li>";
		} elseif (!ctype_digit($peso)) {
			$messaggi .= "<li>Il peso non può contenere numeri</li>";
		}

		if (isset($_POST['presenteIn'])) {
			$edizioni = $_POST['presenteIn'];
		}

		if ($messaggi == "") {
			$ab = 0;
			$abr = 0;
			if (in_array("angry birds", edizioni)) {
				$ab = 1;
			}
			if (in_array("angry birds rio", edizioni)) {
				$abr = 1;
			}
		} else {
			$messaggi = '<ul>' . $messaggi . '</ul>';
		}
	


	$connessione = new DBAccess();
	$connessioneOK = $connessione->openDBConnection();

	if ($connessioneOK) {
		$risultatoQuery = $connessione->insertNewCharacter($nome, $colore, $peso, $potenza, $ab, $abr, $absw, $abs, $descrizione);
		if ($risultatoQuery) {
			$messaggi = '<div id="greetings"><p>...</p></div>';
		} else {
			$messaggi = '<div id="errors"><p>...</p></div>';
		}
	} else {
		$messaggi = '<div id="errors"><p>...</p></div>';
	}
	$connessione->closeConnection();
	}

	$paginaHTML = str_replace("<messaggiForm/>", $messaggi, $paginaHTML);
	$paginaHTML .= str_replace("<messaggiForm/>", $nome, $paginaHTML);
	$paginaHTML .= str_replace("<messaggiForm/>", $colore, $paginaHTML);
	$paginaHTML .= str_replace("<messaggiForm/>", $peso, $paginaHTML);
	$paginaHTML .= str_replace("<messaggiForm/>", $messaggi, $paginaHTML);

	echo $paginaHTML;
?>