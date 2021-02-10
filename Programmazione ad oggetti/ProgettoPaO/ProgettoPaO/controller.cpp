#include "controller.h"

void Controller::drawEsercizio() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");

    QVBoxLayout * esercizio = view->getScreen()->getEsercizio();
    QLayoutItem * esercizioChild;
    while ((esercizioChild = esercizio->takeAt(0)) != nullptr) {
        delete esercizioChild->widget();
        delete esercizioChild;
    }

    view->getScreen()->createQLabelOnQVLayout(esercizio, "Nome esercizio: " + model->getEsercizio(model->getEsercizioCorrente())->getNome());

    QVBoxLayout * dettagliEsercizio = view->getScreen()->getDettagliEsercizio();
    QLayoutItem * dettagliEsercizioChild;
    while ((dettagliEsercizioChild = dettagliEsercizio->takeAt(0)) != nullptr) {
        delete dettagliEsercizioChild->widget();
        delete dettagliEsercizioChild;
    }

    DeepPtr<Esercizio> a = model->getEsercizio(model->getEsercizioCorrente());
    CrossFit * crossFit = dynamic_cast<CrossFit*>(a.get());
    Cardio * cardio = dynamic_cast<Cardio*>(a.get());
    SollevamentoPesi * sollevamentoPesi = dynamic_cast<SollevamentoPesi*>(a.get());
    RiposoPassivo * riposoPassivo = dynamic_cast<RiposoPassivo*>(a.get());
    RiposoAttivo * riposoAttivo = static_cast<RiposoAttivo*>(a.get());

    if (crossFit) {
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Tipo esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "CrossFit");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Descrizione esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, crossFit->getDescrizione());
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Durata esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(crossFit->getDurata().getOre()) + ":" + to_string(crossFit->getDurata().getMinuti()) + ":" + to_string(crossFit->getDurata().getSecondi()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Calorie bruciate:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(crossFit->stimaCalorieBruciate()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "MET:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(crossFit->getMET()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Velocita':");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(crossFit->getVelocita()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Peso:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(crossFit->getPeso()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Ripetizioni:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(crossFit->getRipetizioni()));
    } else if (cardio) {
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Tipo esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Cardio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Descrizione esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, cardio->getDescrizione());
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Durata esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(cardio->getDurata().getOre()) + ":" + to_string(cardio->getDurata().getMinuti()) + ":" + to_string(cardio->getDurata().getSecondi()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Calorie bruciate:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(cardio->stimaCalorieBruciate()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "MET:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(cardio->getMET()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Velocita':");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(cardio->getVelocita()));
    } else if (sollevamentoPesi) {
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Tipo esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "SollevamentoPesi");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Descrizione esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, sollevamentoPesi->getDescrizione());
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Durata esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(sollevamentoPesi->getDurata().getOre()) + ":" + to_string(sollevamentoPesi->getDurata().getMinuti()) + ":" + to_string(sollevamentoPesi->getDurata().getSecondi()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Calorie bruciate:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(sollevamentoPesi->stimaCalorieBruciate()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "MET:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(sollevamentoPesi->getMET()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Peso:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(sollevamentoPesi->getPeso()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Ripetizioni:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(sollevamentoPesi->getRipetizioni()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Serie:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(sollevamentoPesi->getSerie()));
    } else if (riposoPassivo) {
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Tipo esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "RiposoPassivo");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Descrizione esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, riposoPassivo->getDescrizione());
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Durata esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(riposoPassivo->getDurata().getOre()) + ":" + to_string(riposoPassivo->getDurata().getMinuti()) + ":" + to_string(riposoPassivo->getDurata().getSecondi()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "IstruzioniRiposo:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, riposoPassivo->getIstruzioneRiposo());
    } else if (riposoAttivo) {
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Tipo esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "RiposoAttivo");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Descrizione esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, riposoAttivo->getDescrizione());
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "Durata esercizio:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(riposoAttivo->getDurata().getOre()) + ":" + to_string(riposoAttivo->getDurata().getMinuti()) + ":" + to_string(riposoAttivo->getDurata().getSecondi()));
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "IstruzioniRiposo:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, riposoAttivo->getIstruzioneRiposo());
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, "MET:");
        view->getScreen()->createQLabelOnQVLayout(dettagliEsercizio, to_string(riposoAttivo->getMET()));
    }
}

void Controller::drawAllenamento() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");

    QVBoxLayout * dettagliAllenamento = view->getScreen()->getDettagliAllenamento();
    QLayoutItem * dettagliAllenamentoChild;
    while ((dettagliAllenamentoChild = dettagliAllenamento->takeAt(0)) != nullptr) {
        delete dettagliAllenamentoChild->widget();
        delete dettagliAllenamentoChild;
    }

    uint calorieTotali = 0;
    Orario o;
    DList<DeepPtr<Esercizio>> dl1 = model->getEsercizi();
    for (auto it = dl1.begin(); it != dl1.end(); it++) {
        calorieTotali += (*it)->stimaCalorieBruciate();
        o = o + (*it)->getDurata();
    }

    view->getScreen()->createQLabelOnQVLayout(dettagliAllenamento, "Numero totale esercizi:");
    view->getScreen()->createQLabelOnQVLayout(dettagliAllenamento, to_string(model->getSize()));
    view->getScreen()->createQLabelOnQVLayout(dettagliAllenamento, "Calorie totali bruciate:");
    view->getScreen()->createQLabelOnQVLayout(dettagliAllenamento, to_string(calorieTotali));
    view->getScreen()->createQLabelOnQVLayout(dettagliAllenamento, "Calorie medie bruciate per esercizio:");
    view->getScreen()->createQLabelOnQVLayout(dettagliAllenamento, to_string(calorieTotali / model->getSize()));
    view->getScreen()->createQLabelOnQVLayout(dettagliAllenamento, "Durata totale:");
    view->getScreen()->createQLabelOnQVLayout(dettagliAllenamento, to_string(o.getOre()) + ":" + to_string(o.getMinuti()) + ":" + to_string(o.getSecondi()));
    view->getScreen()->createQLabelOnQVLayout(dettagliAllenamento, "Durata media per esercizio:");
    view->getScreen()->createQLabelOnQVLayout(dettagliAllenamento, to_string(o.getOre() / model->getSize()) + ":" + to_string(o.getMinuti() / model->getSize()) + ":" + to_string(o.getSecondi() / model->getSize()));

    QVBoxLayout * layout = view->getScreen()->getListaEsercizi();
    QLayoutItem * child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    int i = 0;
    DList<DeepPtr<Esercizio>> dl = model->getEsercizi();
    for (auto it = dl.begin(); it != dl.end(); it++) {
        view->getScreen()->createQLabelOnQVLayout(layout, "Esercizio numero " + to_string(++i) + ": " + (*it)->getNome());
    }
}

Controller::Controller(QObject * parent) : QObject(parent), view(nullptr), model(nullptr), dialogPointer(nullptr), cambia(false), posizione(0) {}

void Controller::setModel(Model * m) { model = m; }

void Controller::setView(View * v) { view = v; }

void Controller::addCardio() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateCardioDialog(this);
}

void Controller::setCardio() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    cambia = true;
    posizione = view->showGetNumberDialog("Cambia") - 1;
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateCardioDialog(this);
}

void Controller::createCardio() {
    if (!cambia) {
        model->addCardio(
                         static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                         static_cast<QTextEdit*>(dialogPointer[6])->toPlainText().toStdString(),
                         stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                         Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                         stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString()));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new Cardio(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                                          static_cast<QTextEdit*>(dialogPointer[6])->toPlainText().toStdString(),
                                                          stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                                          Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                                                 stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                                 stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                                                          stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString()))), posizione);
        cambia = false;
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
        if (posizione == model->getEsercizioCorrente()) {
            drawEsercizio();
        }
    }
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addSollevamentoPesi() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateSollevamentoPesiDialog(this);
}

void Controller::setSollevamentoPesi() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    cambia = true;
    posizione = view->showGetNumberDialog("Cambia") - 1;
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateSollevamentoPesiDialog(this);
}

void Controller::createSollevamentoPesi() {
    if (!cambia) {
        model->addSollevamentoPesi(
                               static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                               static_cast<QTextEdit*>(dialogPointer[5])->toPlainText().toStdString(),
                               stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                               stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString()),
                               stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                               stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new SollevamentoPesi(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                                                    static_cast<QTextEdit*>(dialogPointer[5])->toPlainText().toStdString(),
                                                                    stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                                                    stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString()),
                                                                    stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                                    stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()))), posizione);
        cambia = false;
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
        if (posizione == model->getEsercizioCorrente()) {
            drawEsercizio();
        }
    }
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addCrossFit() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateCrossFitDialog(this);
}

void Controller::setCrossFit() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    cambia = true;
    posizione = view->showGetNumberDialog("Cambia") - 1;
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateCrossFitDialog(this);
}

void Controller::createCrossFit() {
    if (!cambia) {
        model->addCrossFit(
                           static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                           static_cast<QTextEdit*>(dialogPointer[7])->toPlainText().toStdString(),
                           stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                           Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                  stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                  stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                           stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString()),
                           stoi(static_cast<QLineEdit*>(dialogPointer[6])->text().toStdString()));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new CrossFit(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                                            static_cast<QTextEdit*>(dialogPointer[7])->toPlainText().toStdString(),
                                                            stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                                            Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                                                   stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                                   stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                                                            stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString()),
                                                            stoi(static_cast<QLineEdit*>(dialogPointer[6])->text().toStdString()))), posizione);
        cambia = false;
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
        if (posizione == model->getEsercizioCorrente()) {
            drawEsercizio();
        }
    }
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addRiposoPassivo() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateRiposoPassivoDialog(this);
}

void Controller::setRiposoPassivo() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    cambia = true;
    posizione = view->showGetNumberDialog("Cambia") - 1;
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateRiposoPassivoDialog(this);
}

void Controller::createRiposoPassivo() {
    if (!cambia) {
        model->addRiposoPassivo(
                                static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                static_cast<QTextEdit*>(dialogPointer[5])->toPlainText().toStdString(),
                                static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString(),
                                Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                       stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                       stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new RiposoPassivo(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                                                 static_cast<QTextEdit*>(dialogPointer[5])->toPlainText().toStdString(),
                                                                 static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString(),
                                                                 Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                                                        stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                                        stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())))), posizione);
        cambia = false;
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
        if (posizione == model->getEsercizioCorrente()) {
            drawEsercizio();
        }
    }
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addRiposoAttivoCardio() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateRiposoAttivoCardioDialog(this);
}

void Controller::setRiposoAttivoCardio() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    cambia = true;
    posizione = view->showGetNumberDialog("Cambia") - 1;
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateRiposoAttivoCardioDialog(this);
}

void Controller::createRiposoAttivoCardio() {
    if (!cambia) {
        model->addRiposoAttivo(
                               static_cast<QLineEdit*>(dialogPointer[7])->text().toStdString(),
                               new Cardio(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                          static_cast<QTextEdit*>(dialogPointer[6])->toPlainText().toStdString(),
                                          stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                          Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                                 stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                 stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                                          stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString())));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new RiposoAttivo(static_cast<QLineEdit*>(dialogPointer[7])->text().toStdString(),
                                                                new Cardio(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                                                           static_cast<QTextEdit*>(dialogPointer[6])->toPlainText().toStdString(),
                                                                           stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                                                           Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                                                                  stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                                                  stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                                                                           stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString())))), posizione);
        cambia = false;
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
        if (posizione == model->getEsercizioCorrente()) {
            drawEsercizio();
        }
    }
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addRiposoAttivoSollevamentoPesi() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateRiposoAttivoSollevamentoPesiDialog(this);
}

void Controller::setRiposoAttivoSollevamentoPesi() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    cambia = true;
    posizione = view->showGetNumberDialog("Cambia") - 1;
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateRiposoAttivoSollevamentoPesiDialog(this);
}

void Controller::createRiposoAttivoSollevamentoPesi() {
    if (!cambia) {
        model->addRiposoAttivo(
                               static_cast<QLineEdit*>(dialogPointer[6])->text().toStdString(),
                               new SollevamentoPesi(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                                    static_cast<QTextEdit*>(dialogPointer[5])->toPlainText().toStdString(),
                                                    stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                                    stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString()),
                                                    stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                    stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString())));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new RiposoAttivo(static_cast<QLineEdit*>(dialogPointer[6])->text().toStdString(),
                                                                new SollevamentoPesi(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                                                                     static_cast<QTextEdit*>(dialogPointer[5])->toPlainText().toStdString(),
                                                                                     stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                                                                     stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString()),
                                                                                     stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                                                     stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString())))), posizione);
        cambia = false;
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
        if (posizione == model->getEsercizioCorrente()) {
            drawEsercizio();
        }
    }
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addRiposoAttivoCrossFit() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateRiposoAttivoCrossFitDialog(this);
}

void Controller::setRiposoAttivoCrossFit() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    cambia = true;
    posizione = view->showGetNumberDialog("Cambia") - 1;
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    dialogPointer = view->showCreateRiposoAttivoCrossFitDialog(this);
}

void Controller::createRiposoAttivoCrossFit() {
    if (!cambia) {
        model->addRiposoAttivo(
                               static_cast<QLineEdit*>(dialogPointer[8])->text().toStdString(),
                               new CrossFit(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                            static_cast<QTextEdit*>(dialogPointer[7])->toPlainText().toStdString(),
                                            stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                            Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                                   stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                   stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                                            stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString()),
                                            stoi(static_cast<QLineEdit*>(dialogPointer[6])->text().toStdString())));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new RiposoAttivo(static_cast<QLineEdit*>(dialogPointer[8])->text().toStdString(),
                                                                new CrossFit(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                                                             static_cast<QTextEdit*>(dialogPointer[7])->toPlainText().toStdString(),
                                                                             stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                                                             Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                                                                    stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                                                    stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                                                                             stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString()),
                                                                             stoi(static_cast<QLineEdit*>(dialogPointer[6])->text().toStdString())))), posizione);
        cambia = false;
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
        if (posizione == model->getEsercizioCorrente()) {
            drawEsercizio();
        }
    }
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::remove() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    uint pos = view->showGetNumberDialog("Rimuovi") - 1;
    model->removeEsercizio(pos);
    if (pos == model->getEsercizioCorrente()) {
        drawEsercizio();
    }
    drawAllenamento();
}

void Controller::whatIsMET() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    string s = "Cos'è MET?\n"
               "MET(Metabolic Equivalent Task) è una costante che stima la quantità di energia\n"
               "utilizzata dall'organismo durante un'attività fisica. Ogni attività ha il proprio\n"
               "valore MET, in relazione alla difficoltà richiesta all'organismo per compiere tale\n"
               "lavoro. Il MET viene utilizzato come coefficiente per calcolare le kcal bruciate\n"
               "durante l'attività svolta."
               "\n   - MET < 3 è un'attività leggera"
               "\n   - 3 <= MET <= 6 è un'attività moderata"
               "\n   - MET > 6 è un'attività ad alta intensità";
    view->showMessageDialog(s);
}

void Controller::whatIsCrossFit() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    string s = "Cos'è CrossFit?\n"
               "CrossFit è un tipo di esercizio che unisce il Cardio all'SollevamentoPesi:\n"
               "è quindi un'attività aerobica che allena anche la muscolatura. La durata e\n"
               "la velocità dell'esercizio sono fattori fondamentali per questo tipo di\n"
               "esercizio, ma anche il peso utilizzato importa.";
    view->showMessageDialog(s);
}

void Controller::whatIsRiposoAttivo() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    string s = "Cos'è RiposoAttivo?\n"
               "RiposoAttivo è un particolare tipo di esercizio di riposo e recupero  in cui,\n"
               "a seguito di un'attività, si recupera facendo un altro esercizio ad un'intensità\n"
               "molto bassa. Es: camminare per recuperare da un'attività di corsa.";
    view->showMessageDialog(s);
}

void Controller::next() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    model->next();
    drawEsercizio();
}

void Controller::previous() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    model->previous();
    drawEsercizio();
}

void Controller::goToStart() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    model->goToStart();
    drawEsercizio();
}

void Controller::goToEnd() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    model->goToEnd();
    drawEsercizio();
}
