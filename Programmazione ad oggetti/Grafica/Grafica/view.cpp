#include "view.h"

void View::addMenus(QVBoxLayout * const mainLayout) {
    QMenuBar * menuBar = new QMenuBar(this);

    QMenu * file = new QMenu("File", menuBar);
    QMenu * controllerAllenamento = new QMenu("Controller allenamento", menuBar);
    QMenu * aiuto = new QMenu("Aiuto", menuBar);

    file->addAction(new QAction("Chiudi", file));

    QMenu * aggiungiEsercizio = new QMenu("Aggiungi un esercizio", controllerAllenamento);
    QMenu * cambiaEsercizio = new QMenu("Cambia un esercizio", controllerAllenamento);

    aggiungiEsercizio->addAction(new QAction("Aggiungi un Cardio", aggiungiEsercizio));
    aggiungiEsercizio->addAction(new QAction("Aggiungi un SollevamentoPesi", aggiungiEsercizio));
    aggiungiEsercizio->addAction(new QAction("Aggiungi un CrossFit", aggiungiEsercizio));
    aggiungiEsercizio->addAction(new QAction("Aggiungi un RiposoPassivo", aggiungiEsercizio));

    QMenu * aggiungiRiposoAttivo = new QMenu("Aggiungi un RiposoAttivo", aggiungiEsercizio);
    aggiungiRiposoAttivo->addAction(new QAction("Con un Cardio"));
    aggiungiRiposoAttivo->addAction(new QAction("Con un SollevamentoPesi"));
    aggiungiRiposoAttivo->addAction(new QAction("Con un CrossFit"));

    aggiungiEsercizio->addMenu(aggiungiRiposoAttivo);

    cambiaEsercizio->addAction(new QAction("Cambia con un Cardio", cambiaEsercizio));
    cambiaEsercizio->addAction(new QAction("Cambia con un SollevamentoPesi", cambiaEsercizio));
    cambiaEsercizio->addAction(new QAction("Cambia con un CrossFit", cambiaEsercizio));
    cambiaEsercizio->addAction(new QAction("Cambia con un RiposoPassivo", cambiaEsercizio));

    QMenu * cambiaRiposoAttivo = new QMenu("Cambia un RiposoAttivo", aggiungiEsercizio);
    cambiaRiposoAttivo->addAction(new QAction("Con un Cardio"));
    cambiaRiposoAttivo->addAction(new QAction("Con un SollevamentoPesi"));
    cambiaRiposoAttivo->addAction(new QAction("Con un CrossFit"));

    cambiaEsercizio->addMenu(cambiaRiposoAttivo);

    controllerAllenamento->addMenu(aggiungiEsercizio);
    controllerAllenamento->addMenu(cambiaEsercizio);

    controllerAllenamento->addAction(new QAction("Modifica un esercizio", controllerAllenamento));
    controllerAllenamento->addAction(new QAction("Rimuovi un esercizio", controllerAllenamento));

    aiuto->addAction(new QAction("Cos'è MET?", aiuto));
    aiuto->addAction(new QAction("Cos'è un CrossFit?", aiuto));
    aiuto->addAction(new QAction("Cos'è un RiposoAttivo?", aiuto));

    menuBar->addMenu(file);
    menuBar->addMenu(controllerAllenamento);
    menuBar->addMenu(aiuto);

    mainLayout->addWidget(menuBar);
}

void View::addScreens(QVBoxLayout * const mainLayout) {
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
    sotto->addWidget(new QLabel(tr("Log delle operazioni effettuate")));
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

View::View(QWidget * parent) : QWidget(parent) {
    QVBoxLayout * mainLayout = new QVBoxLayout;

    addMenus(mainLayout);

    addScreens(mainLayout);

    setLayout(mainLayout);
    //resize(QSize(1024, 720));

    showCreateCardioDialog();
    /*showCreateSollevamentoPesiDialog();
    showCreateCrossFitDialog();
    showCreateRiposoPassivoDialog();
    showCreateRiposoAttivoDialog();*/
    //showMessageDialog("View::showMessageDialog()");
    //showGetNumberDialog("Cambia");
    //showGetNumberDialog("Modifica");
    //showGetNumberDialog("Rimuovi");
}

void View::showCreateCardioDialog() {
    DialogCreator dialog(this, 400, 500, 400, 400);
    QVBoxLayout * screenLayout = dialog.createQVLayout();

    QHBoxLayout * scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * durata = dialog.createQHLayout(screenLayout);    
    QHBoxLayout * velocita = dialog.createQHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQHLayout(screenLayout);

    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(durata, "Durata: ");
    dialog.createQLabel(velocita, "Velocita': ");
    dialog.createQLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * METLine = dialog.createQLineEdit(MET, "MET", 2);
    QLineEdit * durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    QLineEdit * durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    QLineEdit * durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    QLineEdit * velocitaLine = dialog.createQLineEdit(velocita, "Velocita'", 2);

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    dialog.show();
}

void View::showCreateSollevamentoPesiDialog() {
    DialogCreator dialog(this, 400, 500, 400, 400);
    QVBoxLayout * screenLayout = dialog.createQVLayout();

    QHBoxLayout * scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * peso = dialog.createQHLayout(screenLayout);
    QHBoxLayout * ripetizioni = dialog.createQHLayout(screenLayout);
    QHBoxLayout * serie = dialog.createQHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQHLayout(screenLayout);

    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(peso, "Peso: ");
    dialog.createQLabel(ripetizioni, "Ripetizioni: ");
    dialog.createQLabel(serie, "Serie: ");
    dialog.createQLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * METLine = dialog.createQLineEdit(MET, "MET", 2);
    QLineEdit * PesoLine = dialog.createQLineEdit(peso, "Peso");
    QLineEdit * RipetizioniLine = dialog.createQLineEdit(ripetizioni, "Ripetizioni");
    QLineEdit * SerieLine = dialog.createQLineEdit(serie, "Serie");

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    dialog.show();
}

void View::showCreateCrossFitDialog() {
    DialogCreator dialog(this, 400, 500, 400, 400);
    QVBoxLayout * screenLayout = dialog.createQVLayout();

    QHBoxLayout * scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * durata = dialog.createQHLayout(screenLayout);
    QHBoxLayout * velocita = dialog.createQHLayout(screenLayout);
    QHBoxLayout * peso = dialog.createQHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQHLayout(screenLayout);

    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(durata, "Durata: ");
    dialog.createQLabel(velocita, "Velocita': ");
    dialog.createQLabel(peso, "Peso: ");
    dialog.createQLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * METLine = dialog.createQLineEdit(MET, "MET", 2);
    QLineEdit * durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    QLineEdit * durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    QLineEdit * durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    QLineEdit * velocitaLine = dialog.createQLineEdit(velocita, "Velocita'", 2);
    QLineEdit * PesoLine = dialog.createQLineEdit(peso, "Peso");

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    dialog.show();
}

void View::showCreateRiposoPassivoDialog() {
    DialogCreator dialog(this, 400, 500, 400, 400);
    QVBoxLayout * screenLayout = dialog.createQVLayout();

    QHBoxLayout * scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * istruzioniRiposo = dialog.createQHLayout(screenLayout);
    QHBoxLayout * durata = dialog.createQHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQHLayout(screenLayout);

    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(istruzioniRiposo, "Istruzioni riposo: ");
    dialog.createQLabel(durata, "Durata: ");
    dialog.createQLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");
    QLineEdit * durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    QLineEdit * durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    QLineEdit * durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    dialog.show();
}

void View::showCreateRiposoAttivoDialog() {
    DialogCreator dialog(this, 100, 500, 100, 400);
    QVBoxLayout * screenLayout = dialog.createQVLayout();

    QHBoxLayout * scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * istruzioniRiposo = dialog.createQHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQHLayout(screenLayout);

    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQLabel(istruzioniRiposo, "Istruzioni riposo: ");

    QLineEdit * istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    dialog.show();
}

void View::showMessageDialog(const string & message) {
    QDialog * dialog = new QDialog(this);
    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(new QLabel(QString::fromStdString(message), dialog));
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setMaximumWidth(500);
    dialog->setMaximumHeight(200);
    dialog->setMinimumWidth(300);
    dialog->setMinimumHeight(100);
    dialog->resize(QSize(300, 100));
    dialog->show();
}

int View::showGetNumberDialog(const string & tipoDialog) {
    bool ok = false;
    string fun = tipoDialog + " un Esercizio";
    string fun1 = "Nessun Esercizio scelto: " + tipoDialog + " annullata!";
    int num = QInputDialog::getInt(this, tr(fun.c_str()), "Indice dell'Esercizio: ", 1, 1, 2147483647, 1, &ok);
    if (!ok) {
        throw std::runtime_error(fun1);
    }

    return num;
}
