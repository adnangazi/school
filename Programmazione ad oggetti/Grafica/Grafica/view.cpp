#include "view.h"

void View::addMenus(QVBoxLayout * const mainLayout) {
    QMenuBar * menuBar = new QMenuBar(this);

    QMenu * file = new QMenu("File", menuBar);
    QMenu * controllerAllenamento = new QMenu("Controller allenamento", menuBar);
    QMenu * visualizza = new QMenu("Visualizza", menuBar);
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

    visualizza->addAction(new QAction("Chiudi parte sinistra", visualizza));
    visualizza->addAction(new QAction("Chiudi parte destra", visualizza));

    aiuto->addAction(new QAction("Cos'è MET?", aiuto));
    aiuto->addAction(new QAction("Cos'è un CrossFit?", aiuto));
    aiuto->addAction(new QAction("Cos'è un RiposoAttivo?", aiuto));

    menuBar->addMenu(file);
    menuBar->addMenu(controllerAllenamento);
    menuBar->addMenu(visualizza);
    menuBar->addMenu(aiuto);

    mainLayout->addWidget(menuBar);
}

void View::addScreens(QVBoxLayout * const mainLayout) {
    QHBoxLayout * screenLayout = new QHBoxLayout;

    QVBoxLayout * sinistra = new QVBoxLayout;
    QVBoxLayout * centro = new QVBoxLayout;
    QVBoxLayout * destra = new QVBoxLayout;

    QVBoxLayout * dettagliAllenamento = new QVBoxLayout;
    QVBoxLayout * log = new QVBoxLayout;

    QHBoxLayout * esercizioAttuale = new QHBoxLayout;
    QHBoxLayout * cronometro = new QHBoxLayout;
    QVBoxLayout * dettagliEsercizioAttuale = new QVBoxLayout;
    QHBoxLayout * controllerEsercizi = new QHBoxLayout;

    QVBoxLayout * listaEsercizi = new QVBoxLayout;

    //-----------//

    QFrame * dettagliAllenamentoFrame = new QFrame;

    QVBoxLayout * dettagliAllenamentoFrameLayout = new QVBoxLayout;
    dettagliAllenamentoFrameLayout->addWidget(new QLabel(this));

    dettagliAllenamentoFrame->setStyleSheet("background-color: rgb(0,50,50)");
    dettagliAllenamentoFrame->setLayout(dettagliAllenamentoFrameLayout);
    dettagliAllenamentoFrame->layout()->setMargin(0);
    dettagliAllenamentoFrame->layout()->setSpacing(0);
    dettagliAllenamentoFrame->layout()->setAlignment(Qt::AlignCenter);
    dettagliAllenamentoFrame->setMinimumSize(100, 100);
    dettagliAllenamentoFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    dettagliAllenamento->addWidget(dettagliAllenamentoFrame);

    //---//

    QFrame * logFrame = new QFrame;

    QVBoxLayout * logFrameLayout = new QVBoxLayout;
    logFrameLayout->addWidget(new QLabel(this));

    logFrame->setStyleSheet("background-color: rgb(50,0,50)");
    logFrame->setLayout(logFrameLayout);
    logFrame->layout()->setMargin(0);
    logFrame->layout()->setSpacing(0);
    logFrame->layout()->setAlignment(Qt::AlignCenter);
    logFrame->setMinimumSize(100, 100);
    logFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    log->addWidget(logFrame);

    //---//

    QFrame * esercizioAttualeFrame = new QFrame;

    QVBoxLayout * esercizioAttualeFrameLayout = new QVBoxLayout;
    esercizioAttualeFrameLayout->addWidget(new QLabel(this));

    esercizioAttualeFrame->setStyleSheet("background-color: rgb(50,50,0)");
    esercizioAttualeFrame->setLayout(esercizioAttualeFrameLayout);
    esercizioAttualeFrame->layout()->setMargin(0);
    esercizioAttualeFrame->layout()->setSpacing(0);
    esercizioAttualeFrame->layout()->setAlignment(Qt::AlignCenter);
    esercizioAttualeFrame->setMinimumSize(100, 100);
    esercizioAttualeFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    esercizioAttuale->addWidget(esercizioAttualeFrame);

    //---//

    QFrame * cronometroFrame = new QFrame;

    QVBoxLayout * cronometroFrameLayout = new QVBoxLayout;
    cronometroFrameLayout->addWidget(new QLabel(this));

    cronometroFrame->setStyleSheet("background-color: rgb(0,0,50)");
    cronometroFrame->setLayout(cronometroFrameLayout);
    cronometroFrame->layout()->setMargin(0);
    cronometroFrame->layout()->setSpacing(0);
    cronometroFrame->layout()->setAlignment(Qt::AlignCenter);
    cronometroFrame->setMinimumSize(100, 100);
    cronometroFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    cronometro->addWidget(cronometroFrame);

    //---//

    QFrame * dettagliEsercizioAttualeFrame = new QFrame;

    QVBoxLayout * dettagliEsercizioAttualeFrameLayout = new QVBoxLayout;
    dettagliEsercizioAttualeFrameLayout->addWidget(new QLabel(this));

    dettagliEsercizioAttualeFrame->setStyleSheet("background-color: rgb(0,50,0)");
    dettagliEsercizioAttualeFrame->setLayout(dettagliEsercizioAttualeFrameLayout);
    dettagliEsercizioAttualeFrame->layout()->setMargin(0);
    dettagliEsercizioAttualeFrame->layout()->setSpacing(0);
    dettagliEsercizioAttualeFrame->layout()->setAlignment(Qt::AlignCenter);
    dettagliEsercizioAttualeFrame->setMinimumSize(100, 100);
    dettagliEsercizioAttualeFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    dettagliEsercizioAttuale->addWidget(dettagliEsercizioAttualeFrame);

    //---//

    QFrame * listaEserciziFrame = new QFrame;

    QVBoxLayout * listaEserciziFrameLayout = new QVBoxLayout;
    listaEserciziFrameLayout->addWidget(new QLabel(this));

    listaEserciziFrame->setStyleSheet("background-color: rgb(50,0,0)");
    listaEserciziFrame->setLayout(listaEserciziFrameLayout);
    listaEserciziFrame->layout()->setMargin(0);
    listaEserciziFrame->layout()->setSpacing(0);
    listaEserciziFrame->layout()->setAlignment(Qt::AlignCenter);
    listaEserciziFrame->setMinimumSize(100, 100);
    listaEserciziFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    listaEsercizi->addWidget(listaEserciziFrame);

    //------------------//

    QPushButton * startButton = new QPushButton("Inizio");
    QPushButton * previousButton = new QPushButton("Precedente");
    QPushButton * nextButton = new QPushButton("Successiva");
    QPushButton * endButton = new QPushButton("Fine");
    QPushButton * autoPlayButton = new QPushButton("AutoPlay");

    controllerEsercizi->addWidget(startButton);
    controllerEsercizi->addWidget(previousButton);
    controllerEsercizi->addWidget(nextButton);
    controllerEsercizi->addWidget(endButton);
    controllerEsercizi->addWidget(autoPlayButton);
    controllerEsercizi->setSpacing(5);
    controllerEsercizi->setContentsMargins(20, 0, 20, 0);

    //----------------//

    QProgressBar * progressBar = new QProgressBar;
    progressBar->setRange(0, 0);
    progressBar->setValue(0);
    progressBar->setFormat("%v / %m");

    //----------------//

    sinistra->addLayout(dettagliAllenamento);
    sinistra->addLayout(log);

    centro->addLayout(esercizioAttuale);
    centro->addLayout(cronometro);
    centro->addLayout(dettagliEsercizioAttuale);
    centro->addLayout(controllerEsercizi);

    destra->addLayout(listaEsercizi);
    destra->addWidget(progressBar);

    screenLayout->addLayout(sinistra);
    screenLayout->addLayout(centro);
    screenLayout->addLayout(destra);

    screenLayout->setSpacing(0);

    //----------------//

    mainLayout->addLayout(screenLayout);
}

View::View(QWidget * parent) : QWidget(parent) {
    QVBoxLayout * mainLayout = new QVBoxLayout;

    addMenus(mainLayout);

    addScreens(mainLayout);

    setLayout(mainLayout);
    resize(QSize(1024, 720));

    /*showCreateCardioDialog();
    showCreateSollevamentoPesiDialog();
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
