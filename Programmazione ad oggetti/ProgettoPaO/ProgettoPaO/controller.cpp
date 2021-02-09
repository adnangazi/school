#include "controller.h"

void Controller::drawEsercizio() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    cout << "Controller::drawEsercizio()" << endl;
}

void Controller::drawAllenamento() {
    view->getScreen()->createQLabelOnQtext(view->getScreen()->getLog(), "Una scritta");
    cout << "Controller::drawAllenamento()" << endl;
}

Controller::Controller(QObject * parent) : QObject(parent), view(nullptr), model(nullptr), dialogPointer(nullptr) {}

void Controller::setModel(Model * m) { model = m; }

void Controller::setView(View * v) { view = v; }

void Controller::addCardio() {
    dialogPointer = view->showCreateCardioDialog(this);
}

void Controller::createCardio() {
    model->addCardio(
                     static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                     static_cast<QTextEdit*>(dialogPointer[6])->toPlainText().toStdString(),
                     stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                     Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                            stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                            stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                     stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString()));
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addSollevamentoPesi() {
    dialogPointer = view->showCreateSollevamentoPesiDialog(this);
}

void Controller::createSollevamentoPesi() {
    model->addSollevamentoPesi(
                               static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                               static_cast<QTextEdit*>(dialogPointer[5])->toPlainText().toStdString(),
                               stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                               stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString()),
                               stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                               stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()));
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addCrossFit() {
    dialogPointer = view->showCreateCrossFitDialog(this);
}

void Controller::createCrossFit() {
    model->addCrossFit(
                       static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                       static_cast<QTextEdit*>(dialogPointer[7])->toPlainText().toStdString(),
                       stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                       Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                              stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                              stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                       stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString()),
                       stoi(static_cast<QLineEdit*>(dialogPointer[6])->text().toStdString()));
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addRiposoPassivo() {
    dialogPointer = view->showCreateRiposoPassivoDialog(this);
}

void Controller::createRiposoPassivo() {
    model->addRiposoPassivo(
                            static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                            static_cast<QTextEdit*>(dialogPointer[5])->toPlainText().toStdString(),
                            static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString(),
                            Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                   stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                   stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())));
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addRiposoAttivoCardio() {
    dialogPointer = view->showCreateRiposoAttivoCardioDialog(this);
}

void Controller::createRiposoAttivoCardio() {
    model->addRiposoAttivo(
                           static_cast<QLineEdit*>(dialogPointer[7])->text().toStdString(),
                           new Cardio(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                      static_cast<QTextEdit*>(dialogPointer[6])->toPlainText().toStdString(),
                                      stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                      Orario(stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString()),
                                             stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                             stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString())),
                                      stoi(static_cast<QLineEdit*>(dialogPointer[5])->text().toStdString())));
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addRiposoAttivoSollevamentoPesi() {
    dialogPointer = view->showCreateRiposoAttivoSollevamentoPesiDialog(this);
}

void Controller::createRiposoAttivoSollevamentoPesi() {
    model->addRiposoAttivo(
                           static_cast<QLineEdit*>(dialogPointer[6])->text().toStdString(),
                           new SollevamentoPesi(static_cast<QLineEdit*>(dialogPointer[0])->text().toStdString(),
                                                static_cast<QTextEdit*>(dialogPointer[5])->toPlainText().toStdString(),
                                                stoi(static_cast<QLineEdit*>(dialogPointer[1])->text().toStdString()),
                                                stoi(static_cast<QLineEdit*>(dialogPointer[2])->text().toStdString()),
                                                stoi(static_cast<QLineEdit*>(dialogPointer[3])->text().toStdString()),
                                                stoi(static_cast<QLineEdit*>(dialogPointer[4])->text().toStdString())));
    delete [] dialogPointer;
    // chiusura dialog
    drawAllenamento();
}

void Controller::addRiposoAttivoCrossFit() {
    dialogPointer = view->showCreateRiposoAttivoCrossFitDialog(this);
}

void Controller::createRiposoAttivoCrossFit() {
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
