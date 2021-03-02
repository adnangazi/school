#include "dialog.h"

void Dialog::createShowCreateCardioDialog(QWidget *  const parent) {
    WidgetCreator dialog;
    d = dialog.createQDialog(parent, 400, 500, 400, 400);
    QVBoxLayout * const screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);
    QHBoxLayout * const scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const durata = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const velocita = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const bottoni = dialog.createQHLayout(screenLayout);
    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio Cardio", true);
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(durata, "Durata: ");
    dialog.createQLabel(velocita, "Velocita': ");
    dialog.createQLabel(descrizione, "Descrizione");
    nomeLine = dialog.createQLineEdit(nome, "Nome");
    METLine = dialog.createQLineEdit(MET, "MET", 2);
    durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    velocitaLine = dialog.createQLineEdit(velocita, "0-10", 2);
    textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");
    crea = dialog.createQPushButton(bottoni, "Crea");
    d->show();
}

void Dialog::createShowCreateSollevamentoPesiDialog(QWidget * const parent) {
    WidgetCreator dialog;
    d = dialog.createQDialog(parent, 400, 500, 400, 400);
    QVBoxLayout * const screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);
    QHBoxLayout * const scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const peso = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const ripetizioni = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const serie = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const bottoni = dialog.createQHLayout(screenLayout);
    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi", true);
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(peso, "Peso: ");
    dialog.createQLabel(ripetizioni, "Ripetizioni: ");
    dialog.createQLabel(serie, "Serie: ");
    dialog.createQLabel(descrizione, "Descrizione");
    nomeLine = dialog.createQLineEdit(nome, "Nome");
    METLine = dialog.createQLineEdit(MET, "MET", 2);
    pesoLine = dialog.createQLineEdit(peso, "Peso");
    ripetizioniLine = dialog.createQLineEdit(ripetizioni, "Ripetizioni");
    serieLine = dialog.createQLineEdit(serie, "Serie");
    textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");
    crea = dialog.createQPushButton(bottoni, "Crea");
    d->show();
}

void Dialog::createShowCreateCrossFitDialog(QWidget * const parent) {
    WidgetCreator dialog;
    d = dialog.createQDialog(parent, 400, 500, 400, 400);
    QVBoxLayout * const screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);
    QHBoxLayout * const scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const durata = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const velocita = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const peso = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const bottoni = dialog.createQHLayout(screenLayout);
    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio CrossFit", true);
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(durata, "Durata: ");
    dialog.createQLabel(velocita, "Velocita': ");
    dialog.createQLabel(peso, "Peso: ");
    dialog.createQLabel(descrizione, "Descrizione");
    nomeLine = dialog.createQLineEdit(nome, "Nome");
    METLine = dialog.createQLineEdit(MET, "MET", 2);
    durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    velocitaLine = dialog.createQLineEdit(velocita, "0-10", 2);
    pesoLine = dialog.createQLineEdit(peso, "Peso");
    textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");
    crea = dialog.createQPushButton(bottoni, "Crea");
    d->show();
}

void Dialog::createShowCreateRiposoPassivoDialog(QWidget * const parent) {
    WidgetCreator dialog;
    d = dialog.createQDialog(parent, 400, 500, 400, 400);
    QVBoxLayout * const screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);
    QHBoxLayout * const scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const istruzioniRiposo = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const durata = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const bottoni = dialog.createQHLayout(screenLayout);
    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio RiposoPassivo", true);
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(istruzioniRiposo, "Istruzioni riposo: ");
    dialog.createQLabel(durata, "Durata: ");
    dialog.createQLabel(descrizione, "Descrizione");
    nomeLine = dialog.createQLineEdit(nome, "Nome");
    istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");
    durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");
    crea = dialog.createQPushButton(bottoni, "Crea");
    d->show();
}

void Dialog::createShowCreateRiposoAttivoCardioDialog(QWidget * const parent) {
    WidgetCreator dialog;
    d = dialog.createQDialog(parent, 400, 500, 400, 450);
    QVBoxLayout * const screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);
    QHBoxLayout * const scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const durata = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const velocita = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const istruzioniRiposo = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const bottoni = dialog.createQHLayout(screenLayout);
    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio RiposoAttivo con Cardio", true);
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(durata, "Durata: ");
    dialog.createQLabel(velocita, "Velocita': ");
    dialog.createQLabel(istruzioniRiposo, "Istruzioni riposo: ");
    dialog.createQLabel(descrizione, "Descrizione");
    nomeLine = dialog.createQLineEdit(nome, "Nome");
    METLine = dialog.createQLineEdit(MET, "MET", 2);
    durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    velocitaLine = dialog.createQLineEdit(velocita, "0-10", 2);
    istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");
    textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");
    crea = dialog.createQPushButton(bottoni, "Crea");
    d->show();
}

void Dialog::createShowCreateRiposoAttivoSollevamentoPesiDialog(QWidget * const parent) {
    WidgetCreator dialog;
    d = dialog.createQDialog(parent, 400, 525, 400, 525);
    QVBoxLayout * const screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);
    QHBoxLayout * const scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const peso = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const ripetizioni = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const serie = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const istruzioniRiposo = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const bottoni = dialog.createQHLayout(screenLayout);
    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio RiposoAttivo con SollevamentoPesi", true);
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(peso, "Peso: ");
    dialog.createQLabel(ripetizioni, "Ripetizioni: ");
    dialog.createQLabel(serie, "Serie: ");
    dialog.createQLabel(istruzioniRiposo, "Istruzioni riposo: ");
    dialog.createQLabel(descrizione, "Descrizione");
    nomeLine = dialog.createQLineEdit(nome, "Nome");
    METLine = dialog.createQLineEdit(MET, "MET", 2);
    pesoLine = dialog.createQLineEdit(peso, "Peso");
    ripetizioniLine = dialog.createQLineEdit(ripetizioni, "Ripetizioni");
    serieLine = dialog.createQLineEdit(serie, "Serie");
    istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");
    textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");
    crea = dialog.createQPushButton(bottoni, "Crea");
    d->show();
}

void Dialog::createShowCreateRiposoAttivoCrossFitDialog(QWidget * const parent) {
    WidgetCreator dialog;
    d = dialog.createQDialog(parent, 400, 500, 400, 465);
    QVBoxLayout * const screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);
    QHBoxLayout * const scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const durata = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const velocita = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const peso = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const istruzioniRiposo = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * const bottoni = dialog.createQHLayout(screenLayout);
    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio RiposoAttivo con CrossFit", true);
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(durata, "Durata: ");
    dialog.createQLabel(velocita, "Velocita': ");
    dialog.createQLabel(peso, "Peso: ");
    dialog.createQLabel(istruzioniRiposo, "Istruzioni riposo: ");
    dialog.createQLabel(descrizione, "Descrizione");
    nomeLine = dialog.createQLineEdit(nome, "Nome");
    METLine = dialog.createQLineEdit(MET, "MET", 2);
    durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    velocitaLine = dialog.createQLineEdit(velocita, "0-10", 2);
    istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");
    pesoLine = dialog.createQLineEdit(peso, "Peso");
    textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");
    crea = dialog.createQPushButton(bottoni, "Crea");
    d->show();
}

void Dialog::createShowMessageDialog(QWidget * const parent, const string & message) {
    QDialog * const dialog = new QDialog(parent);
    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(new QLabel(QString::fromStdString(message), dialog));
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setMaximumSize(QSize(500, 200));
    dialog->setMinimumSize(QSize(300, 100));
    dialog->show();
}

uint Dialog::createShowGetNumberDialog(QWidget * const parent, const string & tipoDialog) {
    bool ok = false;
    string scritta = tipoDialog + " un Esercizio";
    string errore = "Nessun Esercizio scelto: " + tipoDialog + "() annullata!";
    uint num = QInputDialog::getInt(parent, tr(scritta.c_str()), "Indice dell'Esercizio: ", 1, 1, 2147483647, 1, &ok);
    if (!ok) {
        num = 0;
    }
    return num;
}

QDialog * Dialog::getDialog() {
    return d;
}

QLineEdit * Dialog::getNomeLine() {
    return nomeLine;
}

QLineEdit * Dialog::getMETLine() {
    return METLine;
}

QLineEdit * Dialog::getPesoLine() {
    return pesoLine;
}

QLineEdit * Dialog::getRipetizioniLine() {
    return ripetizioniLine;
}

QLineEdit * Dialog::getSerieLine() {
    return serieLine;
}

QLineEdit * Dialog::getIstruzioniRiposoLine() {
    return istruzioniRiposoLine;
}

QLineEdit * Dialog::getDurataLineOre() {
    return durataLineOre;
}

QLineEdit * Dialog::getDurataLineMinuti() {
    return durataLineMinuti;
}

QLineEdit * Dialog::getDurataLineSecondi() {
    return durataLineSecondi;
}

QLineEdit * Dialog::getVelocitaLine() {
    return velocitaLine;
}

QTextEdit * Dialog::getTextEdit() {
    return textEdit;
}

QPushButton * Dialog::getCrea() {
    return crea;
}
