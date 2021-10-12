#include "menus.h"

void Menus::createControllerAllenamento(QMenuBar * const menuBar) {
    controllerAllenamento = new QMenu("Controller allenamento", menuBar);
    menuBar->addMenu(controllerAllenamento);
    aggiungiEsercizio = new QMenu("Aggiungi un esercizio", controllerAllenamento);
    cambiaEsercizio = new QMenu("Cambia un esercizio", controllerAllenamento);
    controllerAllenamento->addMenu(aggiungiEsercizio);
    controllerAllenamento->addMenu(cambiaEsercizio);
    controllerAllenamento->addAction(new QAction("Rimuovi un esercizio", controllerAllenamento));
    aggiungiEsercizio->addAction(new QAction("Aggiungi un Cardio", aggiungiEsercizio));
    aggiungiEsercizio->addAction(new QAction("Aggiungi un SollevamentoPesi", aggiungiEsercizio));
    aggiungiEsercizio->addAction(new QAction("Aggiungi un CrossFit", aggiungiEsercizio));
    aggiungiEsercizio->addAction(new QAction("Aggiungi un RiposoPassivo", aggiungiEsercizio));
    aggiungiRiposoAttivo = new QMenu("Aggiungi un RiposoAttivo", aggiungiEsercizio);
    aggiungiEsercizio->addMenu(aggiungiRiposoAttivo);
    aggiungiRiposoAttivo->addAction(new QAction("Con un Cardio"));
    aggiungiRiposoAttivo->addAction(new QAction("Con un SollevamentoPesi"));
    aggiungiRiposoAttivo->addAction(new QAction("Con un CrossFit"));
    cambiaEsercizio->addAction(new QAction("Cambia con un Cardio", cambiaEsercizio));
    cambiaEsercizio->addAction(new QAction("Cambia con un SollevamentoPesi", cambiaEsercizio));
    cambiaEsercizio->addAction(new QAction("Cambia con un CrossFit", cambiaEsercizio));
    cambiaEsercizio->addAction(new QAction("Cambia con un RiposoPassivo", cambiaEsercizio));
    cambiaRiposoAttivo = new QMenu("Cambia un RiposoAttivo", aggiungiEsercizio);
    cambiaEsercizio->addMenu(cambiaRiposoAttivo);
    cambiaRiposoAttivo->addAction(new QAction("Con un Cardio"));
    cambiaRiposoAttivo->addAction(new QAction("Con un SollevamentoPesi"));
    cambiaRiposoAttivo->addAction(new QAction("Con un CrossFit"));
}

void Menus::createAiuto(QMenuBar * const menuBar) {
    aiuto = new QMenu("Aiuto", menuBar);
    menuBar->addMenu(aiuto);
    aiuto->addAction(new QAction("Cos'è MET?", aiuto));
    aiuto->addAction(new QAction("Cos'è un CrossFit?", aiuto));
    aiuto->addAction(new QAction("Cos'è un RiposoAttivo?", aiuto));
}

Menus::Menus(QVBoxLayout * ml) : mainLayout(ml) {}

void Menus::createMenus() {
    QMenuBar * const menuBar = new QMenuBar;
    mainLayout->addWidget(menuBar);
    createControllerAllenamento(menuBar);
    createAiuto(menuBar);
}

QMenu * Menus::getControllerAllenamento() const {
    return controllerAllenamento;
}

QMenu * Menus::getAiuto() const {
    return aiuto;
}

QMenu * Menus::getAggiungiEsercizio() const {
    return aggiungiEsercizio;
}

QMenu * Menus::getCambiaEsercizio() const {
    return cambiaEsercizio;
}

QMenu * Menus::getAggiungiRiposoAttivo() const {
    return aggiungiRiposoAttivo;
}

QMenu * Menus::getCambiaRiposoAttivo() const {
    return cambiaRiposoAttivo;
}
