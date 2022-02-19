-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Creato il: Dic 10, 2019 alle 23:57
-- Versione del server: 8.0.13
-- Versione PHP: 7.1.23

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `tecweb2019`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `personaggi`
--

CREATE TABLE `personaggi` (
  `ID` int(11) NOT NULL,
  `nome` varchar(100) COLLATE utf8_unicode_ci NOT NULL,
  `colore` varchar(100) COLLATE utf8_unicode_ci NOT NULL,
  `peso` int(11) NOT NULL,
  `potenza` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `descrizione` longtext COLLATE utf8_unicode_ci,
  `angry_birds` tinyint(1) NOT NULL,
  `angry_birds_rio` tinyint(1) NOT NULL,
  `angry_birds_star_wars` tinyint(1) NOT NULL,
  `angry_birds_space` tinyint(1) NOT NULL,
  `immagine` varchar(100) COLLATE utf8_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dump dei dati per la tabella `personaggi`
--

INSERT INTO `personaggi` (`ID`, `nome`, `colore`, `peso`, `potenza`, `descrizione`, `angry_birds`, `angry_birds_rio`, `angry_birds_star_wars`, `angry_birds_space`, `immagine`) VALUES
(1, 'Red', 'Rosso', 50, 'Bassa', 'Sono cardinali rossi e non hanno nessuna abilità particolare. Gli unici introdotti immediatamente.', 1, 1, 1, 1, 'red.png'),
(2, 'Blue (Jay, Jake e Jim Blue alias \'The Blues\')', 'Blu', 80, 'Bassa', 'Sono blu, piccoli e apparentemente poco distruttivi. Se però viene toccato un qualsiasi punto dello schermo (touchscreen o click del mouse su schermi tradizionali) mentre uno di questi uccelli è in volo, esso si triplica e viene sostituito da tre uccelli identici, che continuano nella sua traiettoria seguendo un percorso \"a pioggia\". Particolarmente adatti a distruggere elementi in vetro e introdotti dal primo capitolo. In alcuni dei cortometraggi animati pubblicati da Rovio su Angry Birds toons come promozione di nuovi capitoli, appaiono come un gruppetto di tre giovani volatili.', 0, 1, 1, 1, 'blue.png'),
(3, 'Matilda', 'Bianco', 95, 'Media', 'Sono grossi e bianchi, sono galline, e hanno l\'abilità, se viene toccato un qualsiasi punto dello schermo mentre sono in volo, di lasciar cadere un uovo, che cade in verticale ed esplode come una bomba appena tocca qualcosa. Dopo aver sganciato la bomba subiscono un\'accelerazione diagonale verso l\'alto, che può essere a sua volta utilizzata per distruggere o sbalzare via elementi portanti della struttura. Esordiscono nel primo capitolo. Non sono presenti in Angry Birds Space.', 0, 0, 1, 1, 'white.png'),
(4, 'Big Red', 'Rosso', 150, 'Elevata', 'Sono rossi e quasi uguali ai Red ma quattro volte più grandi e pesanti e dunque con forza distruttiva molto maggiore. Appaiono per la prima volta nel quarto capitolo.', 0, 1, 1, 0, 'big_red.png'),
(5, 'Bubbles', 'Arancione', 80, 'Elevata', 'Sono arancioni e nel momento in cui viene toccato un qualsiasi punto dello schermo si gonfiano istantaneamente, aumentando di molte volte il proprio volume, per poi sgonfiarsi come palloncini. Il loro utilizzo tipico consiste nel farli entrare in passaggi stretti, per poi farli espandere in modo da operare una grande distruzione. Se il loro effetto non viene attivato manualmente, si gonfiano automaticamente poco dopo aver toccato qualcosa. Sono presenti nell\'ultimo episodio \"Birdday Party\" di Angry Birds, e nell\'episodio \"Ham\'o\'ween\" di Angry Birds Seasons.', 0, 0, 0, 1, 'orange.png'),
(6, 'Mighty Eagle', 'Nera', 250, 'Elevata', 'è un\'aquila bianca e nera di dimensioni enormi, in grado di distruggere con il suo peso ogni cosa presente nel livello, e funge da aiuto per i livelli difficili, che non si riescono a completare con i normali uccelli. Si attiva lanciando una scatoletta sulla struttura: l\'aquila gigante si abbatte nel punto dove la scatoletta di pesce atterra. Dopo averla usata, si deve attendere un\'ora per poterla riavere a disposizione per superare un nuovo livello, mentre è possibile riutilizzarla a piacere nei livelli già terminati. Superare un livello con la mighty eagle non assegna alcuna \"stella\", e quindi, se si vogliono ottenere le relative stelle, il livello andrà rigiocato successivamente senza usufruire dell\'aquila; tuttavia, il punteggio è calcolato come percentuale di distruzione: in caso si raggiunga il 100%, si è ricompensati con una piuma di aquila.\r\n\r\nLa Mighty Eagle è una sorta di \"minigioco\" o \"espansione\" disponibile, a pagamento, solo in alcune versioni del gioco, con un acquisto in-app. Nel capitolo \"Year of the Dragon\" di Angry Birds Seasons, la Mighty Eagle è eccezionalmente sostituita dal Mighty Dragon e al posto della scatola di sardine viene lanciato un pesce dorato, è reso disponibile anche in versioni gratuite del gioco. In Angry Birds Space è presente la Mighty Space Eagle, che funziona in modo simile alla normale Mighty Eagle, ma invece di picchiare e sumbalzare al suolo con la conseguente distruzione di quasi tutto lo scenario, non essendoci suolo in \"Space\" dopo qualche secondo che le sardine si bloccano essa sbucherà fuori dal buco nero distruggendo solo ciò che è presente nel suo raggio d\'azione. In \"Angry Birds Star Wars\" è invece sostituita dal Mighty Falcon. Si attiva lanciando un uovo robotico sul campo di gioco. Dopo pochi secondi che ha urtato qualcosa o quando viene toccato lo schermo, esso esplode. All\'interno della scenario compare il Millennium Falcon di Guerre Stellari, e comincia a compiere un giro attorno al campo di gioco, sparando una raffica di raggi laser sul punto dove è esploso l\'uovo.', 0, 0, 0, 0, 'mighty_eagle.png');

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `personaggi`
--
ALTER TABLE `personaggi`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `personaggi`
--
ALTER TABLE `personaggi`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
