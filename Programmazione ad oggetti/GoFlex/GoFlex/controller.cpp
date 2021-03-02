#include "controller.h"

bool Controller::checkMargini(const string & tipoOperazione) {
    if (model->getSize() == 0) {
        string s = "Impossibile fare " + tipoOperazione + "() in una lista vuota!";
        view->showMessageDialog(s);
        return false;
    }
    posizione = view->showGetNumberDialog(tipoOperazione) - 1;
    if (posizione < 0 || static_cast<uint>(posizione) >= model->getSize()) {
        string s = "Valore inserito errato:\n"
                   "(<= 0 o > " + std::to_string(model->getSize()) + " o annullato inserimento numero)\n"
                   "Inserire un valore compreso tra 1 e " + std::to_string(model->getSize()) + " o confermare il numero inserito!";
        view->showMessageDialog(s);
        return false;
    }
    return true;
}

void Controller::drawLine(QVBoxLayout * const layout, const string & titolo, const string & valore) {
    view->getScreen()->createQLabelOnQVLayout(layout, titolo, true);
    view->getScreen()->createQLabelOnQVLayout(layout, valore);
}

void Controller::drawEsercizio() {
    QVBoxLayout * esercizio = view->getScreen()->getEsercizio();
    view->getScreen()->clearLayout(esercizio);
    if (model->getSize() > 0) {
        view->getScreen()->createQLabelOnQVLayout(esercizio, "Nome esercizio: " + model->getEsercizio(model->getEsercizioCorrente())->getNome(), true, 10);
    }
}

void Controller::drawDettagliEsercizio() {
    QVBoxLayout * dettagliEsercizio = view->getScreen()->getDettagliEsercizio();
    view->getScreen()->clearLayout(dettagliEsercizio);

    if (model->getSize() > 0) {
        DeepPtr<Esercizio> a = model->getEsercizio(model->getEsercizioCorrente());
        CrossFit * crossFit = dynamic_cast<CrossFit*>(a.get());
        Cardio * cardio = dynamic_cast<Cardio*>(a.get());
        SollevamentoPesi * sollevamentoPesi = dynamic_cast<SollevamentoPesi*>(a.get());
        RiposoPassivo * riposoPassivo = dynamic_cast<RiposoPassivo*>(a.get());
        RiposoAttivo * riposoAttivo = static_cast<RiposoAttivo*>(a.get());

        if (crossFit) {
            drawLine(dettagliEsercizio, "Tipo esercizio: ", "CrossFit");
            drawLine(dettagliEsercizio, "Descrizione esercizio: ", crossFit->getDescrizione());
            drawLine(dettagliEsercizio, "Durata esercizio: ", std::to_string(crossFit->getDurata().getOre()) + ":" + std::to_string(crossFit->getDurata().getMinuti()) + ":" + std::to_string(crossFit->getDurata().getSecondi()));
            drawLine(dettagliEsercizio, "Calorie bruciate: ", std::to_string(crossFit->stimaCalorieBruciate()));
            drawLine(dettagliEsercizio, "MET: ", std::to_string(crossFit->getMET()));
            drawLine(dettagliEsercizio, "Velocita': ", std::to_string(crossFit->getVelocita()));
            drawLine(dettagliEsercizio, "Peso: ", std::to_string(crossFit->getPeso()));
            drawLine(dettagliEsercizio, "Ripetizioni: ", std::to_string(crossFit->getRipetizioni()));
        } else if (cardio) {
            drawLine(dettagliEsercizio, "Tipo esercizio: ", "Cardio");
            drawLine(dettagliEsercizio, "Descrizione esercizio: ", cardio->getDescrizione());
            drawLine(dettagliEsercizio, "Durata esercizio: ", std::to_string(cardio->getDurata().getOre()) + ":" + std::to_string(cardio->getDurata().getMinuti()) + ":" + std::to_string(cardio->getDurata().getSecondi()));
            drawLine(dettagliEsercizio, "Calorie bruciate: ", std::to_string(cardio->stimaCalorieBruciate()));
            drawLine(dettagliEsercizio, "MET: ", std::to_string(cardio->getMET()));
            drawLine(dettagliEsercizio, "Velocita': ", std::to_string(cardio->getVelocita()));
        } else if (sollevamentoPesi) {
            drawLine(dettagliEsercizio, "Tipo esercizio: ", "SollevamentoPesi");
            drawLine(dettagliEsercizio, "Descrizione esercizio: ", sollevamentoPesi->getDescrizione());
            drawLine(dettagliEsercizio, "Durata esercizio: ", std::to_string(sollevamentoPesi->getDurata().getOre()) + ":" + std::to_string(sollevamentoPesi->getDurata().getMinuti()) + ":" + std::to_string(sollevamentoPesi->getDurata().getSecondi()));
            drawLine(dettagliEsercizio, "Calorie bruciate: ", std::to_string(sollevamentoPesi->stimaCalorieBruciate()));
            drawLine(dettagliEsercizio, "MET: ", std::to_string(sollevamentoPesi->getMET()));
            drawLine(dettagliEsercizio, "Peso: ", std::to_string(sollevamentoPesi->getPeso()));
            drawLine(dettagliEsercizio, "Ripetizioni: ", std::to_string(sollevamentoPesi->getRipetizioni()));
            drawLine(dettagliEsercizio, "Serie: ", std::to_string(sollevamentoPesi->getSerie()));
        } else if (riposoPassivo) {
            drawLine(dettagliEsercizio, "Tipo esercizio: ", "RiposoPassivo");
            drawLine(dettagliEsercizio, "Descrizione esercizio: ", riposoPassivo->getDescrizione());
            drawLine(dettagliEsercizio, "Durata esercizio: ", std::to_string(riposoPassivo->getDurata().getOre()) + ":" + std::to_string(riposoPassivo->getDurata().getMinuti()) + ":" + std::to_string(riposoPassivo->getDurata().getSecondi()));
            drawLine(dettagliEsercizio, "Istruzioni riposo: ", riposoPassivo->getIstruzioneRiposo());
        } else if (riposoAttivo) {
            drawLine(dettagliEsercizio, "Tipo esercizio: ", "RiposoAttivo");
            drawLine(dettagliEsercizio, "Descrizione esercizio: ", riposoAttivo->getDescrizione());
            drawLine(dettagliEsercizio, "Durata esercizio: ", std::to_string(riposoAttivo->getDurata().getOre()) + ":" + std::to_string(riposoAttivo->getDurata().getMinuti()) + ":" + std::to_string(riposoAttivo->getDurata().getSecondi()));
            drawLine(dettagliEsercizio, "Istruzioni riposo: ", riposoAttivo->getIstruzioneRiposo());
            drawLine(dettagliEsercizio, "MET: ", std::to_string(riposoAttivo->getMET()));
        }
    }
}

void Controller::drawDettagliAllenamento() {
    QVBoxLayout * dettagliAllenamento = view->getScreen()->getDettagliAllenamento();
    view->getScreen()->clearLayout(dettagliAllenamento);

    if (model->getSize() > 0) {
        uint pos = 0;
        uint calorieTotali = 0;
        uint calorieAttuali = 0;
        Orario o;
        Orario attuale;
        DList<DeepPtr<Esercizio>> dl1 = model->getEsercizi();
        for (auto it = dl1.begin(); it != dl1.end(); it++, pos++) {
            calorieTotali += (*it)->stimaCalorieBruciate();
            o = o + (*it)->getDurata();
            if (pos == model->getEsercizioCorrente()) {
                calorieAttuali = calorieTotali;
                attuale = o;
            }
        }

        drawLine(dettagliAllenamento, "Calorie totali bruciate: ", std::to_string(calorieTotali));
        drawLine(dettagliAllenamento, "Calorie medie bruciate per esercizio: ", std::to_string(calorieTotali / model->getSize()));
        drawLine(dettagliAllenamento, "Calorie attualmente bruciate: ", std::to_string(calorieAttuali));
        drawLine(dettagliAllenamento, "Durata totale: ", std::to_string(o.getOre()) + ":" + std::to_string(o.getMinuti()) + ":" + std::to_string(o.getSecondi()));
        drawLine(dettagliAllenamento, "Durata media per esercizio: ", std::to_string(o.getOre() / model->getSize()) + ":" + std::to_string(o.getMinuti() / model->getSize()) + ":" + std::to_string(o.getSecondi() / model->getSize()));
        drawLine(dettagliAllenamento, "Durata attuale: ", std::to_string(attuale.getOre()) + ":" + std::to_string(attuale.getMinuti()) + ":" + std::to_string(attuale.getSecondi()));
    }
}

void Controller::drawAllenamento() {
    QVBoxLayout * listaEsercizi = view->getScreen()->getListaEsercizi();
    view->getScreen()->clearLayout(listaEsercizi);

    if (model->getSize() > 0) {
        int i = 0;
        DList<DeepPtr<Esercizio>> dl = model->getEsercizi();
        for (auto it = dl.begin(); it != dl.end(); it++) {
            view->getScreen()->createQLabelOnQVLayout(listaEsercizi, "Esercizio " + std::to_string(++i) + ": " + (*it)->getNome(), true);
        }
    }
}

void Controller::updateGrafica() {
    drawEsercizio();
    drawDettagliEsercizio();
    drawDettagliAllenamento();
    drawAllenamento();
    view->getScreen()->updateProgressBar(model->getEsercizioCorrente() + 1, model->getSize());
}

Controller::Controller(QObject * const parent) : QObject(parent), view(nullptr), model(nullptr), cambia(false), posizione(0), operazioneLog(0) {}

void Controller::setModel(Model * const m) {
    model = m;
}

void Controller::setView(View * const v) {
    view = v;
}

void Controller::addCardio() {
    cambia = false;
    view->showCreateCardioDialog(this);
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per l'aggiunta di un esercizio Cardio");
}

void Controller::setCardio() {
    if (checkMargini("Cambia")) {
        cambia = true;
        view->showCreateCardioDialog(this);
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per il cambiamento di un esercizio con un esercizio Cardio");
    }
}

void Controller::createCardio() {
    if (!cambia) {
        model->addCardio(view->getDialog()->getNomeLine()->text().toStdString(),
                         view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                         atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                         Orario(atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) : 0),
                         atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) : 0);
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aggiunto un esercizio Cardio");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new Cardio(view->getDialog()->getNomeLine()->text().toStdString(),
                                                          view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                                          atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                                                          Orario(atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) : 0),
                                                          atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) : 0)), static_cast<uint>(posizione));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Cambiato l'esercizio in posizione " + std::to_string(posizione) + " con un esercizio Cardio");
    }
    delete view->getDialog()->getDialog();
    updateGrafica();
}

void Controller::addSollevamentoPesi() {
    cambia = false;
    view->showCreateSollevamentoPesiDialog(this);
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per l'aggiunta di un esercizio SollevamentoPesi");
}

void Controller::setSollevamentoPesi() {
    if (checkMargini("Cambia")) {
        cambia = true;
        view->showCreateSollevamentoPesiDialog(this);
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per il cambiamento di un esercizio con un esercizio SollevamentoPesi");
    }
}

void Controller::createSollevamentoPesi() {
    if (!cambia) {
        model->addSollevamentoPesi(view->getDialog()->getNomeLine()->text().toStdString(),
                                   view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                   atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                                   atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) : 0,
                                   atoi(view->getDialog()->getRipetizioniLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getRipetizioniLine()->text().toStdString().c_str()) : 0,
                                   atoi(view->getDialog()->getSerieLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getSerieLine()->text().toStdString().c_str()) : 0);
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aggiunto un esercizio SollevamentoPesi");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new SollevamentoPesi(view->getDialog()->getNomeLine()->text().toStdString(),
                                                                    view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                                                    atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                                                                    atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) : 0,
                                                                    atoi(view->getDialog()->getRipetizioniLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getRipetizioniLine()->text().toStdString().c_str()) : 0,
                                                                    atoi(view->getDialog()->getSerieLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getSerieLine()->text().toStdString().c_str()) : 0)), static_cast<uint>(posizione));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Cambiato l'esercizio in posizione " + std::to_string(posizione) + " con un esercizio SollevamentoPesi");
    }
    delete view->getDialog()->getDialog();
    updateGrafica();
}

void Controller::addCrossFit() {
    cambia = false;
    view->showCreateCrossFitDialog(this);
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per l'aggiunta di un esercizio CrossFit");
}

void Controller::setCrossFit() {
    if (checkMargini("Cambia")) {
        cambia = true;
        view->showCreateCrossFitDialog(this);
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per il cambiamento di un esercizio con un esercizio CrossFit");
    }
}

void Controller::createCrossFit() {
    if (!cambia) {
        model->addCrossFit(view->getDialog()->getNomeLine()->text().toStdString(),
                           view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                           atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                           Orario(atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) : 0),
                           atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) : 0,
                           atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) : 0);
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aggiunto un esercizio CrossFit");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new CrossFit(view->getDialog()->getNomeLine()->text().toStdString(),
                                                            view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                                            atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                                                            Orario(atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) : 0),
                                                            atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) : 0,
                                                            atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) : 0)), static_cast<uint>(posizione));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Cambiato l'esercizio in posizione " + std::to_string(posizione) + " con un esercizio CrossFit");
    }
    delete view->getDialog()->getDialog();
    updateGrafica();
}

void Controller::addRiposoPassivo() {
    cambia = false;
    view->showCreateRiposoPassivoDialog(this);
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per l'aggiunta di un esercizio RiposoPassivo");
}

void Controller::setRiposoPassivo() {
    if (checkMargini("Cambia")) {
        cambia = true;
        view->showCreateRiposoPassivoDialog(this);
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per il cambiamento di un esercizio con un esercizio RiposoPassivo");
    }
}

void Controller::createRiposoPassivo() {
    if (!cambia) {
        model->addRiposoPassivo(view->getDialog()->getNomeLine()->text().toStdString(),
                                view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                view->getDialog()->getIstruzioniRiposoLine()->text().toStdString(),
                                Orario(atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) : 0));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aggiunto un esercizio RiposoPassivo");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new RiposoPassivo(view->getDialog()->getNomeLine()->text().toStdString(),
                                                                 view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                                                 view->getDialog()->getIstruzioniRiposoLine()->text().toStdString(),
                                                                 Orario(atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) : 0))), static_cast<uint>(posizione));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Cambiato l'esercizio in posizione " + std::to_string(posizione) + " con un esercizio RiposoPassivo");
    }
    delete view->getDialog()->getDialog();
    updateGrafica();
}

void Controller::addRiposoAttivoCardio() {
    cambia = false;
    view->showCreateRiposoAttivoCardioDialog(this);
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per l'aggiunta di un esercizio RiposoAttivo di tipo Cardio");
}

void Controller::setRiposoAttivoCardio() {
    if (checkMargini("Cambia")) {
        cambia = true;
        view->showCreateRiposoAttivoCardioDialog(this);
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per il cambiamento di un esercizio con un esercizio RiposoAttivo di tipo Cardio");
    }
}

void Controller::createRiposoAttivoCardio() {
    if (!cambia) {
        model->addRiposoAttivo(view->getDialog()->getIstruzioniRiposoLine()->text().toStdString(),
                               new Cardio(view->getDialog()->getNomeLine()->text().toStdString(),
                                          view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                          atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                                          Orario(atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) : 0),
                                          atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) : 0));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aggiunto un esercizio RiposoAttivo di tipo Cardio");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new RiposoAttivo(view->getDialog()->getIstruzioniRiposoLine()->text().toStdString(),
                                                                new Cardio(view->getDialog()->getNomeLine()->text().toStdString(),
                                                                           view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                                                           atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                                                                           Orario(atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) : 0),
                                                                           atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) : 0))), static_cast<uint>(posizione));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Cambiato l'esercizio in posizione " + std::to_string(posizione) + " con un esercizio RiposoAttivo di tipo Cardio");
    }
    delete view->getDialog()->getDialog();
    updateGrafica();
}

void Controller::addRiposoAttivoSollevamentoPesi() {
    cambia = false;
    view->showCreateRiposoAttivoSollevamentoPesiDialog(this);
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per l'aggiunta di un esercizio RiposoAttivo di tipo SollevamentoPesi");
}

void Controller::setRiposoAttivoSollevamentoPesi() {
    if (checkMargini("Cambia")) {
        cambia = true;
        view->showCreateRiposoAttivoSollevamentoPesiDialog(this);
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per il cambiamento di un esercizio con un esercizio RiposoAttivo di tipo SollevamentoPesi");
    }
}

void Controller::createRiposoAttivoSollevamentoPesi() {
    if (!cambia) {
        model->addRiposoAttivo(view->getDialog()->getIstruzioniRiposoLine()->text().toStdString(),
                               new SollevamentoPesi(view->getDialog()->getNomeLine()->text().toStdString(),
                                                    view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                                    atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                                                    atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) : 0,
                                                    atoi(view->getDialog()->getRipetizioniLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getRipetizioniLine()->text().toStdString().c_str()) : 0,
                                                    atoi(view->getDialog()->getSerieLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getSerieLine()->text().toStdString().c_str()) : 0));
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aggiunto un esercizio RiposoAttivo di tipo SollevamentoPesi");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new RiposoAttivo(view->getDialog()->getIstruzioniRiposoLine()->text().toStdString(),
                                                                new SollevamentoPesi(view->getDialog()->getNomeLine()->text().toStdString(),
                                                                                     view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                                                                     atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                                                                                     atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) : 0,
                                                                                     atoi(view->getDialog()->getRipetizioniLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getRipetizioniLine()->text().toStdString().c_str()) : 0,
                                                                                     atoi(view->getDialog()->getSerieLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getSerieLine()->text().toStdString().c_str()) : 0))), static_cast<uint>(posizione));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Cambiato l'esercizio in posizione " + std::to_string(posizione) + " con un esercizio RiposoAttivo di tipo SollevamentoPesi");
    }
    delete view->getDialog()->getDialog();
    updateGrafica();
}

void Controller::addRiposoAttivoCrossFit() {
    cambia = false;
    view->showCreateRiposoAttivoCrossFitDialog(this);
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per l'aggiunta di un esercizio RiposoAttivo di tipo CrossFit");
}

void Controller::setRiposoAttivoCrossFit() {
    if (checkMargini("Cambia")) {
        cambia = true;
        view->showCreateRiposoAttivoCrossFitDialog(this);
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog per il cambiamento di un esercizio con un esercizio RiposoAttivo di tipo CrossFit");
    }
}

void Controller::createRiposoAttivoCrossFit() {
    if (!cambia) {
        model->addRiposoAttivo(view->getDialog()->getIstruzioniRiposoLine()->text().toStdString(),
                               new CrossFit(view->getDialog()->getNomeLine()->text().toStdString(),
                                            view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                            atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                                            Orario(atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) : 0),
                                            atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) : 0,
                                            atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) : 0));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aggiunto un esercizio RiposoAttivo di tipo CrossFit");
    } else {
        model->setEsercizio(DeepPtr<Esercizio>(new RiposoAttivo(view->getDialog()->getIstruzioniRiposoLine()->text().toStdString(),
                                                                new CrossFit(view->getDialog()->getNomeLine()->text().toStdString(),
                                                                             view->getDialog()->getTextEdit()->toPlainText().toStdString(),
                                                                             atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getMETLine()->text().toStdString().c_str()) : 0,
                                                                             Orario(atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineSecondi()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineMinuti()->text().toStdString().c_str()) : 0, atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getDurataLineOre()->text().toStdString().c_str()) : 0),
                                                                             atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getVelocitaLine()->text().toStdString().c_str()) : 0,
                                                                             atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) >= 0 ? atoi(view->getDialog()->getPesoLine()->text().toStdString().c_str()) : 0))), static_cast<uint>(posizione));
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Cambiato l'esercizio in posizione " + std::to_string(posizione) + " con un esercizio RiposoAttivo di tipo CrossFit");
    }
    delete view->getDialog()->getDialog();
    updateGrafica();
}

void Controller::remove() {
    if (checkMargini("Rimuovi")) {
        model->removeEsercizio(static_cast<uint>(posizione));
        updateGrafica();
        view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Rimosso l'esercizio in poszione " + std::to_string(posizione));
    }
}

void Controller::whatIsMET() {
    string s = "Cos'è MET?\n"
               "MET(Metabolic Equivalent Task) è una costante che stima la quantità di\n"
               "energia utilizzata dall'organismo durante un'attività fisica.\n"
               "Ogni attività ha il proprio valore MET, in relazione alla difficoltà\n"
               "richiesta all'organismo per compiere tale lavoro. Il MET viene utilizzato\n"
               "come coefficiente per calcolare le kcal bruciate durante l'attività svolta."
               "\n   - MET < 3 è un'attività leggera"
               "\n   - 3 <= MET <= 6 è un'attività moderata"
               "\n   - MET > 6 è un'attività ad alta intensità";
    view->showMessageDialog(s);
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog 'Cos'è MET'");
}

void Controller::whatIsCrossFit() {
    string s = "Cos'è CrossFit?\n"
               "CrossFit è un tipo di esercizio che unisce il Cardio all'SollevamentoPesi:\n"
               "è quindi un'attività aerobica che allena anche la muscolatura. La durata e\n"
               "la velocità dell'esercizio sono fattori fondamentali per questo tipo di\n"
               "esercizio, ma anche il peso utilizzato importa.";
    view->showMessageDialog(s);
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog 'Cos'è CrossFit'");
}

void Controller::whatIsRiposoAttivo() {
    string s = "Cos'è RiposoAttivo?\n"
               "RiposoAttivo è un particolare tipo di esercizio di riposo e recupero in\n"
               "cui, a seguito di un'attività, si recupera facendo un altro esercizio ad\n"
               "un'intensità molto bassa (Cardio, SollevamentoPesi o CrossFit).\n"
               "Es: camminare per recuperare da un'attività di corsa.";
    view->showMessageDialog(s);
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Aperto il dialog 'Cos'è RiposoAttivo'");
}

void Controller::next() {
    model->next();
    updateGrafica();
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Premuto il bottone 'Successivo'");
}

void Controller::previous() {
    model->previous();
    updateGrafica();
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Premuto il bottone 'Precedente'");
}

void Controller::goToStart() {
    model->goToStart();
    updateGrafica();
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Premuto il bottone 'Inizio'");
}

void Controller::goToEnd() {
    model->goToEnd();
    updateGrafica();
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), std::to_string(++operazioneLog) + ". Premuto il bottono 'Fine'");
}
