#include "dialog.h"

Dialog::Dialog() {}

void Dialog::createShowCreateCardioDialog(QWidget * parent) {
    ViewCreator dialog;
    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

    QHBoxLayout * scritta = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * MET = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * durata = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * velocita = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQVHLayout(screenLayout);

    dialog.createQHLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQHLabel(nome, "Nome: ");
    dialog.createQHLabel(MET, "MET: ");
    dialog.createQHLabel(durata, "Durata: ");
    dialog.createQHLabel(velocita, "Velocita': ");
    dialog.createQHLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * METLine = dialog.createQLineEdit(MET, "MET", 2);
    QLineEdit * durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    QLineEdit * durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    QLineEdit * durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    QLineEdit * velocitaLine = dialog.createQLineEdit(velocita, "Velocita'", 2);

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    d->show();
}

void Dialog::createShowCreateSollevamentoPesiDialog(QWidget * parent) {
    ViewCreator dialog;
    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

    QHBoxLayout * scritta = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * MET = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * peso = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * ripetizioni = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * serie = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQVHLayout(screenLayout);

    dialog.createQHLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQHLabel(nome, "Nome: ");
    dialog.createQHLabel(MET, "MET: ");
    dialog.createQHLabel(peso, "Peso: ");
    dialog.createQHLabel(ripetizioni, "Ripetizioni: ");
    dialog.createQHLabel(serie, "Serie: ");
    dialog.createQHLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * METLine = dialog.createQLineEdit(MET, "MET", 2);
    QLineEdit * PesoLine = dialog.createQLineEdit(peso, "Peso");
    QLineEdit * RipetizioniLine = dialog.createQLineEdit(ripetizioni, "Ripetizioni");
    QLineEdit * SerieLine = dialog.createQLineEdit(serie, "Serie");

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    d->show();
}

void Dialog::createShowCreateCrossFitDialog(QWidget * parent) {
    ViewCreator dialog;
    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

    QHBoxLayout * scritta = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * MET = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * durata = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * velocita = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * peso = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQVHLayout(screenLayout);

    dialog.createQHLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQHLabel(nome, "Nome: ");
    dialog.createQHLabel(MET, "MET: ");
    dialog.createQHLabel(durata, "Durata: ");
    dialog.createQHLabel(velocita, "Velocita': ");
    dialog.createQHLabel(peso, "Peso: ");
    dialog.createQHLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * METLine = dialog.createQLineEdit(MET, "MET", 2);
    QLineEdit * durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    QLineEdit * durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    QLineEdit * durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    QLineEdit * velocitaLine = dialog.createQLineEdit(velocita, "Velocita'", 2);
    QLineEdit * PesoLine = dialog.createQLineEdit(peso, "Peso");

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    d->show();
}

void Dialog::createShowCreateRiposoPassivoDialog(QWidget * parent) {
    ViewCreator dialog;
    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

    QHBoxLayout * scritta = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * istruzioniRiposo = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * durata = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQVHLayout(screenLayout);

    dialog.createQHLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQHLabel(nome, "Nome: ");
    dialog.createQHLabel(istruzioniRiposo, "Istruzioni riposo: ");
    dialog.createQHLabel(durata, "Durata: ");
    dialog.createQHLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");
    QLineEdit * durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    QLineEdit * durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    QLineEdit * durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    d->show();
}

void Dialog::createShowCreateRiposoAttivoDialog(QWidget * parent) {
    ViewCreator dialog;
    QDialog * d = dialog.createQDialog(parent, 100, 500, 100, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

    QHBoxLayout * scritta = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * istruzioniRiposo = dialog.createQVHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQVHLayout(screenLayout);

    dialog.createQHLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQHLabel(istruzioniRiposo, "Istruzioni riposo: ");

    QLineEdit * istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    d->show();
}

void Dialog::createShowMessageDialog(QWidget * parent, const string & message) {
    QDialog * dialog = new QDialog(parent);
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

int Dialog::createShowGetNumberDialog(QWidget * parent, const string & tipoDialog) {
    bool ok = false;
    string fun = tipoDialog + " un Esercizio";
    string fun1 = "Nessun Esercizio scelto: " + tipoDialog + " annullata!";
    int num = QInputDialog::getInt(parent, tr(fun.c_str()), "Indice dell'Esercizio: ", 1, 1, 2147483647, 1, &ok);
    if (!ok) {
        throw std::runtime_error(fun1);
    }

    return num;
}
