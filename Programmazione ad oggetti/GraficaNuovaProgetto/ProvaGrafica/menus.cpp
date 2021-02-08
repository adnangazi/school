#include "menus.h"

Menus::Menus(QVBoxLayout * const ml) : mainLayout(ml) {}

void Menus::createMenus() {
    QMenuBar * menuBar = new QMenuBar;

    mainLayout->addWidget(menuBar);

    QMenu * file = new QMenu("File", menuBar);
    QMenu * controllerAllenamento = new QMenu("Controller allenamento", menuBar);
    QMenu * aiuto = new QMenu("Aiuto", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(controllerAllenamento);
    menuBar->addMenu(aiuto);

    file->addAction(new QAction("Chiudi", file));

    QMenu * aggiungiEsercizio = new QMenu("Aggiungi un esercizio", controllerAllenamento);
    QMenu * cambiaEsercizio = new QMenu("Cambia un esercizio", controllerAllenamento);

    controllerAllenamento->addMenu(aggiungiEsercizio);
    controllerAllenamento->addMenu(cambiaEsercizio);
    controllerAllenamento->addAction(new QAction("Modifica un esercizio", controllerAllenamento));
    controllerAllenamento->addAction(new QAction("Rimuovi un esercizio", controllerAllenamento));

    aggiungiEsercizio->addAction(new QAction("Aggiungi un Cardio", aggiungiEsercizio));
    aggiungiEsercizio->addAction(new QAction("Aggiungi un SollevamentoPesi", aggiungiEsercizio));
    aggiungiEsercizio->addAction(new QAction("Aggiungi un CrossFit", aggiungiEsercizio));
    aggiungiEsercizio->addAction(new QAction("Aggiungi un RiposoPassivo", aggiungiEsercizio));

    QMenu * aggiungiRiposoAttivo = new QMenu("Aggiungi un RiposoAttivo", aggiungiEsercizio);

    aggiungiEsercizio->addMenu(aggiungiRiposoAttivo);

    aggiungiRiposoAttivo->addAction(new QAction("Con un Cardio"));
    aggiungiRiposoAttivo->addAction(new QAction("Con un SollevamentoPesi"));
    aggiungiRiposoAttivo->addAction(new QAction("Con un CrossFit"));

    cambiaEsercizio->addAction(new QAction("Cambia con un Cardio", cambiaEsercizio));
    cambiaEsercizio->addAction(new QAction("Cambia con un SollevamentoPesi", cambiaEsercizio));
    cambiaEsercizio->addAction(new QAction("Cambia con un CrossFit", cambiaEsercizio));
    cambiaEsercizio->addAction(new QAction("Cambia con un RiposoPassivo", cambiaEsercizio));

    QMenu * cambiaRiposoAttivo = new QMenu("Cambia un RiposoAttivo", aggiungiEsercizio);

    cambiaEsercizio->addMenu(cambiaRiposoAttivo);

    cambiaRiposoAttivo->addAction(new QAction("Con un Cardio"));
    cambiaRiposoAttivo->addAction(new QAction("Con un SollevamentoPesi"));
    cambiaRiposoAttivo->addAction(new QAction("Con un CrossFit"));

    aiuto->addAction(new QAction("Cos'è MET?", aiuto));
    aiuto->addAction(new QAction("Cos'è un CrossFit?", aiuto));
    aiuto->addAction(new QAction("Cos'è un RiposoAttivo?", aiuto));
}
