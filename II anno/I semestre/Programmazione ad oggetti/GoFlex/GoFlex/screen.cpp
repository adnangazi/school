#include "screen.h"

Screen::Screen(QVBoxLayout * const ml) : mainLayout(ml) {}

QVBoxLayout * Screen::createMainWindow(WidgetCreator & v, QVBoxLayout * const screenLayout) {
    QHBoxLayout * const sopra = v.createQHLayout(screenLayout);
    v.createQLine(screenLayout, 'H');
    QVBoxLayout * const sinistra = v.createQVLayout(sopra);
    v.createQLine(sopra, 'V');
    QVBoxLayout * const destra = v.createQVLayout(sopra);
    v.createQLabel(sinistra, "   Esercizio attuale", true, 8);
    QWidget * const esercizioW = v.createQWidget(sinistra, 400, 75);
    v.createQLabel(sinistra, "   Dettagli dell'esercizio attuale", true, 8);
    QWidget * const dettagliEsercizioW = v.createQWidget(sinistra, 400, 390);
    v.createQLabel(destra, "   Dettagli dell'allenamento", true, 8);
    QWidget * const dettagliAllenamentoW = v.createQWidget(destra, 315, 340);
    progressBar = v.createQProgressBar(destra);
    v.createQLabel(destra, "   Lista degli esercizi", true, 8);
    QWidget * const listaEserciziW = v.createQWidget(destra, 315, 175);
    dettagliEsercizio = v.createQScrollArea(dettagliEsercizioW);
    dettagliAllenamento = v.createQScrollArea(dettagliAllenamentoW);
    listaEsercizi = v.createQScrollArea(listaEserciziW);
    esercizio = v.createQScrollArea(esercizioW);

    return sinistra;
}

void Screen::createControllerEsercizi(WidgetCreator & v, QVBoxLayout * const sinistra) {
    QWidget * const controllerEserciziW = v.createQWidget(sinistra, 400, 50);
    QHBoxLayout * const controllerEsercizi = new QHBoxLayout;
    controllerEserciziW->setLayout(controllerEsercizi);
    startButton = v.createQPushButton(controllerEsercizi, "Inizio");
    previousButton = v.createQPushButton(controllerEsercizi, "Precedente");
    nextButton = v.createQPushButton(controllerEsercizi, "Successivo");
    endButton = v.createQPushButton(controllerEsercizi, "Fine");
}

void Screen::createLog(WidgetCreator & v, QVBoxLayout * const screenLayout) {
    QVBoxLayout * const sotto = v.createQVLayout(screenLayout);
    QWidget * const label = v.createQWidget(sotto, 715, 45, 45);
    QVBoxLayout * const labelSotto = new QVBoxLayout;
    label->setLayout(labelSotto);
    v.createQLabel(labelSotto, "Log delle operazioni effettuate", true, 8);
    log = v.createQTextEdit(sotto, "Log delle operazioni effettuate ... ", 715, 150);
    log->setReadOnly(true);
}

void Screen::createScreen() {
    WidgetCreator v;
    QVBoxLayout * const screenLayout = v.createQVLayout(mainLayout);
    createControllerEsercizi(v, createMainWindow(v, screenLayout));
    createLog(v, screenLayout);
}

QLabel * Screen::createQLabelOnQVLayout(QVBoxLayout * const parent, const string & nome, const bool bald, const int size) {
    WidgetCreator v;
    return v.createQLabel(parent, nome, bald, size);
}

void Screen::createQLabelOnQtext(QTextEdit * const parent, const string & nome) {
    WidgetCreator v;
    v.createQLabelOnQText(parent, nome);
}

void Screen::clearLayout(QVBoxLayout * const layout) {
    QLayoutItem * layoutChild;
    while ((layoutChild = layout->takeAt(0)) != nullptr) {
        delete layoutChild->widget();
        delete layoutChild;
    }
}

void Screen::updateProgressBar(const uint current, const uint limit) {
    progressBar->setRange(0, limit);
    progressBar->setValue(current);
    progressBar->show();
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
