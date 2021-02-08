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

    QWidget * esercizioW = v.createQWidget(sinistra, 500, 50, 1000, 100);
    QWidget * dettagliEsercizioW = v.createQWidget(sinistra, 500, 350, 1000, 700);
    QWidget * controllerEserciziW = v.createQWidget(sinistra, 500, 50, 1000, 100);
    QWidget * dettagliAllenamentoW = v.createQWidget(destra, 250, 150, 500, 300);
    QWidget * listaEserciziW = v.createQWidget(destra, 250, 250, 500, 500);

    // i 3 successivi
    QVBoxLayout * dettagliEsercizio = v.createQScrollArea(dettagliEsercizioW);
    QVBoxLayout * dettagliAllenamento = v.createQScrollArea(dettagliAllenamentoW);
    QVBoxLayout * listaEsercizi = v.createQScrollArea(listaEserciziW);

    QHBoxLayout * esercizio = new QHBoxLayout; // *
    esercizioW->setLayout(esercizio);
    QHBoxLayout * controllerEsercizi = new QHBoxLayout;
    controllerEserciziW->setLayout(controllerEsercizi);

    // i 5 successivi
    QPushButton * startButton = v.createQPushButton(controllerEsercizi, "Inizio");
    QPushButton * previousButton = v.createQPushButton(controllerEsercizi, "Precedente");
    QPushButton * nextButton = v.createQPushButton(controllerEsercizi, "Successivo");
    QPushButton * endButton = v.createQPushButton(controllerEsercizi, "Fine");
    QPushButton * autoPlayButton = v.createQPushButton(controllerEsercizi, "AutoPlay");

    v.createQLabel(sotto, "Log delle operazioni effettuate");
    QTextEdit * log = v.createQTextEdit(sotto, "Log delle operazioni effettuate ... ", 750, 100, 1500, 200); // *
}
