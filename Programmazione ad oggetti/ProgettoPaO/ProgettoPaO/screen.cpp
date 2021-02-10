#include "screen.h"

Screen::Screen(QVBoxLayout * const ml) : mainLayout(ml) {}

QVBoxLayout * Screen::createMainWindow(WidgetCreator & v, QVBoxLayout * screenLayout) {
    QHBoxLayout * sopra = v.createQHLayout(screenLayout);
    v.createQLine(screenLayout, 'H');
    QVBoxLayout * sinistra = v.createQVLayout(sopra);
    v.createQLine(sopra, 'V');
    QVBoxLayout * destra = v.createQVLayout(sopra);

    v.createQLabel(sinistra, "Esercizio attuale");
    QWidget * esercizioW = v.createQWidget(sinistra, 400, 100);
    v.createQLabel(sinistra, "Dettagli dell'esercizio attuale");
    QWidget * dettagliEsercizioW = v.createQWidget(sinistra, 400, 350);
    v.createQLabel(destra, "Dettagli dell'allenamento");
    QWidget * dettagliAllenamentoW = v.createQWidget(destra, 300, 200);
    v.createQLabel(destra, "Lista degli esercizi");
    QWidget * listaEserciziW = v.createQWidget(destra, 300, 300);

    dettagliEsercizio = v.createQScrollArea(dettagliEsercizioW);
    dettagliAllenamento = v.createQScrollArea(dettagliAllenamentoW);
    listaEsercizi = v.createQScrollArea(listaEserciziW);

    esercizio = new QVBoxLayout;
    esercizioW->setLayout(esercizio);

    return sinistra;
}

void Screen::createControllerEsercizi(WidgetCreator & v, QVBoxLayout * sinistra) {
    QWidget * controllerEserciziW = v.createQWidget(sinistra, 400, 50);
    QHBoxLayout * controllerEsercizi = new QHBoxLayout;
    controllerEserciziW->setLayout(controllerEsercizi);

    startButton = v.createQPushButton(controllerEsercizi, "Inizio");
    previousButton = v.createQPushButton(controllerEsercizi, "Precedente");
    nextButton = v.createQPushButton(controllerEsercizi, "Successivo");
    endButton = v.createQPushButton(controllerEsercizi, "Fine");
}

void Screen::createLog(WidgetCreator & v, QVBoxLayout * screenLayout) {
    QVBoxLayout * sotto = v.createQVLayout(screenLayout);
    QWidget * label = v.createQWidget(sotto, 700, 50, 50);
    QVBoxLayout * labelSotto = new QVBoxLayout;
    label->setLayout(labelSotto);

    v.createQLabel(labelSotto, "Log delle operazioni effettuate");
    log = v.createQTextEdit(sotto, "Log delle operazioni effettuate ... ", 700, 150);
    log->setReadOnly(true);
}

void Screen::createScreen() {
    WidgetCreator v;

    QVBoxLayout * screenLayout = v.createQVLayout(mainLayout);

    createControllerEsercizi(v, createMainWindow(v, screenLayout));
    createLog(v, screenLayout);
}

QLabel * Screen::createQLabelOnQVLayout(QVBoxLayout * parent, const string & nome) {
    WidgetCreator v;
    return v.createQLabel(parent, nome);
}

void Screen::createQLabelOnQtext(QTextEdit * parent, const string & nome) {
    WidgetCreator v;
    v.createQLabelOnQText(parent, nome);
}

QVBoxLayout * Screen::getEsercizio() {
    return esercizio;
}

QVBoxLayout * Screen::getDettagliEsercizio() {
    return dettagliEsercizio;
}

QVBoxLayout * Screen::getDettagliAllenamento() {
    return dettagliAllenamento;
}

QVBoxLayout * Screen::getListaEsercizi() {
    return listaEsercizi;
}

QTextEdit * Screen::getLog() {
    return log;
}

QPushButton * Screen::getStart() {
    return startButton;
}

QPushButton * Screen::getPrevious() {
    return previousButton;
}

QPushButton * Screen::getNext() {
    return nextButton;
}

QPushButton * Screen::getEnd() {
    return endButton;
}
