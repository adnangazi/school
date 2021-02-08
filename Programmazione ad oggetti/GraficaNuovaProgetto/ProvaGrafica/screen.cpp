#include "screen.h"

Screen::Screen(QVBoxLayout * const ml) : mainLayout(ml) {}

void Screen::createScreen() {
    ViewCreator v;

    QVBoxLayout * screenLayout = v.createQVLayout(mainLayout);
    QHBoxLayout * sopra = v.createQHLayout(screenLayout);
    v.createQLine(screenLayout, 'H');
    QVBoxLayout * sotto = v.createQVLayout(screenLayout);
    QVBoxLayout * sinistra = v.createQVLayout(sopra);
    v.createQLine(sopra, 'V');
    QVBoxLayout * destra = v.createQVLayout(sopra);

    QWidget * esercizioW = v.createQWidget(sinistra, 400, 100);
    QWidget * dettagliEsercizioW = v.createQWidget(sinistra, 400, 350);
    QWidget * controllerEserciziW = v.createQWidget(sinistra, 400, 50);
    QWidget * dettagliAllenamentoW = v.createQWidget(destra, 300, 200);
    QWidget * listaEserciziW = v.createQWidget(destra, 300, 300);

    dettagliEsercizio = v.createQScrollArea(dettagliEsercizioW);
    dettagliAllenamento = v.createQScrollArea(dettagliAllenamentoW);
    listaEsercizi = v.createQScrollArea(listaEserciziW);

    esercizio = new QVBoxLayout;
    esercizioW->setLayout(esercizio);
    QHBoxLayout * controllerEsercizi = new QHBoxLayout;
    controllerEserciziW->setLayout(controllerEsercizi);

    // i 5 successivi
    QPushButton * startButton = v.createQPushButton(controllerEsercizi, "Inizio");
    QPushButton * previousButton = v.createQPushButton(controllerEsercizi, "Precedente");
    QPushButton * nextButton = v.createQPushButton(controllerEsercizi, "Successivo");
    QPushButton * endButton = v.createQPushButton(controllerEsercizi, "Fine");

    QWidget * label = v.createQWidget(sotto, 700, 50, 50);
    QVBoxLayout * labelSotto = new QVBoxLayout;
    label->setLayout(labelSotto);

    v.createQLabel(labelSotto, "Log delle operazioni effettuate");
    log = v.createQTextEdit(sotto, "Log delle operazioni effettuate ... ", 700, 150);
    log->setReadOnly(true);
}

QLabel * Screen::createQLabelOnQVLayout(QVBoxLayout * parent, const string & nome) {
    ViewCreator v;
    return v.createQLabel(parent, nome);
}

void Screen::createQLabelOnQtext(QTextEdit * parent, const string & nome) {
    ViewCreator v;
    v.createQLabelOnQText(parent, nome);
}
