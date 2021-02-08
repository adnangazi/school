#include "screen.h"

Screen::Screen(QVBoxLayout * const ml) : mainLayout(ml) {}

void Screen::createScreen() {
    QVBoxLayout * screenLayout = new QVBoxLayout;
    QHBoxLayout * sopra = new QHBoxLayout;
    QVBoxLayout * sotto = new QVBoxLayout;
    QVBoxLayout * sinistra = new QVBoxLayout;
    QVBoxLayout * destra = new QVBoxLayout;
    QHBoxLayout * nomeEsercizio = new QHBoxLayout;
    QVBoxLayout * dettagliEsercizio = new QVBoxLayout;
    QHBoxLayout * controllerEsercizio = new QHBoxLayout;
    QVBoxLayout * dettagliAllenamento = new QVBoxLayout;
    QVBoxLayout * listaAllenamento = new QVBoxLayout;

    QFrame * vline = new QFrame;
    vline->setFrameShape(QFrame::VLine);

    QFrame * hline = new QFrame;
    hline->setFrameShape(QFrame::HLine);

    sopra->addLayout(sinistra);
    sopra->addWidget(vline);
    sopra->addLayout(destra);
    sinistra->addLayout(nomeEsercizio);
    sinistra->addLayout(dettagliEsercizio);
    sinistra->addLayout(controllerEsercizio);
    destra->addLayout(dettagliAllenamento);
    destra->addLayout(listaAllenamento);

    screenLayout->addLayout(sopra);
    screenLayout->addWidget(hline);
    screenLayout->addLayout(sotto);

    QTextEdit * log = new QTextEdit;
    log->setMinimumSize(750, 200);

    sotto->addWidget(new QLabel(tr("Log delle operazioni effettuate")));
    sotto->addWidget(log);

    QFrame * nomeEsercizioFrame = new QFrame;
    QFrame * dettagliEsercizioFrame = new QFrame;
    QFrame * dettagliAllenamentoFrame = new QFrame;
    QFrame * listaAllenamentoFrame = new QFrame;

    nomeEsercizioFrame->setFrameShape(QFrame::Box);
    nomeEsercizioFrame->setMinimumSize(500, 100);
    dettagliEsercizioFrame->setFrameShape(QFrame::Box);
    dettagliEsercizioFrame->setMinimumSize(500, 400);
    dettagliAllenamentoFrame->setFrameShape(QFrame::Box);
    dettagliAllenamentoFrame->setMinimumSize(250, 100);
    listaAllenamentoFrame->setFrameShape(QFrame::Box);
    listaAllenamentoFrame->setMinimumSize(250, 350);

    nomeEsercizio->addWidget(nomeEsercizioFrame);
    dettagliEsercizio->addWidget(dettagliEsercizioFrame);
    dettagliAllenamento->addWidget(dettagliAllenamentoFrame);
    listaAllenamento->addWidget(listaAllenamentoFrame);

    QPushButton * startButton = new QPushButton("Inizio");
    QPushButton * previousButton = new QPushButton("Precedente");
    QPushButton * nextButton = new QPushButton("Successiva");
    QPushButton * endButton = new QPushButton("Fine");
    QPushButton * autoPlayButton = new QPushButton("AutoPlay");

    controllerEsercizio->addWidget(startButton);
    controllerEsercizio->addWidget(previousButton);
    controllerEsercizio->addWidget(nextButton);
    controllerEsercizio->addWidget(endButton);
    controllerEsercizio->addWidget(autoPlayButton);

    mainLayout->addLayout(screenLayout);
}
