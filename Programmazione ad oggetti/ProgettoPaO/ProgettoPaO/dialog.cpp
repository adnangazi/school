#include "dialog.h"

QWidget ** Dialog::createShowCreateCardioDialog(QWidget * parent) {
    WidgetCreator dialog;

    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

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
    QLineEdit * velocitaLine = dialog.createQLineEdit(velocita, "0-10'", 2);

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    QWidget ** arr = new QWidget*[8]{nomeLine, METLine, durataLineOre, durataLineMinuti, durataLineSecondi, velocitaLine, textEdit, crea};

    d->show();

    return arr;
}

QWidget ** Dialog::createShowCreateSollevamentoPesiDialog(QWidget * parent) {
    WidgetCreator dialog;
    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

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

    QWidget ** arr = new QWidget*[7]{nomeLine, METLine, PesoLine, RipetizioniLine, SerieLine, textEdit, crea};

    d->show();

    return arr;
}

QWidget ** Dialog::createShowCreateCrossFitDialog(QWidget * parent) {
    WidgetCreator dialog;
    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

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
    QLineEdit * velocitaLine = dialog.createQLineEdit(velocita, "0-10'", 2);
    QLineEdit * pesoLine = dialog.createQLineEdit(peso, "Peso");

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    QWidget ** arr = new QWidget*[9]{nomeLine, METLine, durataLineOre, durataLineMinuti, durataLineSecondi, velocitaLine, pesoLine, textEdit, crea};

    d->show();

    return arr;
}

QWidget ** Dialog::createShowCreateRiposoPassivoDialog(QWidget * parent) {
    WidgetCreator dialog;
    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

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

    QWidget ** arr = new QWidget*[7]{nomeLine, istruzioniRiposoLine, durataLineOre, durataLineMinuti, durataLineSecondi, textEdit, crea};

    d->show();

    return arr;
}

QWidget ** Dialog::createShowCreateRiposoAttivoCardioDialog(QWidget * parent) {
    WidgetCreator dialog;

    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

    QHBoxLayout * scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * durata = dialog.createQHLayout(screenLayout);
    QHBoxLayout * velocita = dialog.createQHLayout(screenLayout);
    QHBoxLayout * istruzioniRiposo = dialog.createQHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQHLayout(screenLayout);

    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(durata, "Durata: ");
    dialog.createQLabel(velocita, "Velocita': ");
    dialog.createQLabel(istruzioniRiposo, "Istruzioni riposo: ");
    dialog.createQLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * METLine = dialog.createQLineEdit(MET, "MET", 2);
    QLineEdit * durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    QLineEdit * durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    QLineEdit * durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    QLineEdit * velocitaLine = dialog.createQLineEdit(velocita, "0-10'", 2);
    QLineEdit * istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    QWidget ** arr = new QWidget*[9]{nomeLine, METLine, durataLineOre, durataLineMinuti, durataLineSecondi, velocitaLine, textEdit, istruzioniRiposoLine, crea};

    d->show();

    return arr;
}

QWidget ** Dialog::createShowCreateRiposoAttivoSollevamentoPesiDialog(QWidget * parent) {
    WidgetCreator dialog;
    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

    QHBoxLayout * scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * peso = dialog.createQHLayout(screenLayout);
    QHBoxLayout * ripetizioni = dialog.createQHLayout(screenLayout);
    QHBoxLayout * serie = dialog.createQHLayout(screenLayout);
    QHBoxLayout * istruzioniRiposo = dialog.createQHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQHLayout(screenLayout);

    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(peso, "Peso: ");
    dialog.createQLabel(ripetizioni, "Ripetizioni: ");
    dialog.createQLabel(serie, "Serie: ");
    dialog.createQLabel(istruzioniRiposo, "Istruzioni riposo: ");
    dialog.createQLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * METLine = dialog.createQLineEdit(MET, "MET", 2);
    QLineEdit * PesoLine = dialog.createQLineEdit(peso, "Peso");
    QLineEdit * RipetizioniLine = dialog.createQLineEdit(ripetizioni, "Ripetizioni");
    QLineEdit * SerieLine = dialog.createQLineEdit(serie, "Serie");
    QLineEdit * istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    QWidget ** arr = new QWidget*[8]{nomeLine, METLine, PesoLine, RipetizioniLine, SerieLine, textEdit, istruzioniRiposoLine, crea};

    d->show();

    return arr;
}

QWidget ** Dialog::createShowCreateRiposoAttivoCrossFitDialog(QWidget * parent) {
    WidgetCreator dialog;
    QDialog * d = dialog.createQDialog(parent, 400, 500, 400, 400);

    QVBoxLayout * screenLayout = new QVBoxLayout;
    d->setLayout(screenLayout);

    QHBoxLayout * scritta = dialog.createQHLayout(screenLayout);
    QHBoxLayout * nome = dialog.createQHLayout(screenLayout);
    QHBoxLayout * MET = dialog.createQHLayout(screenLayout);
    QHBoxLayout * durata = dialog.createQHLayout(screenLayout);
    QHBoxLayout * velocita = dialog.createQHLayout(screenLayout);
    QHBoxLayout * peso = dialog.createQHLayout(screenLayout);
    QHBoxLayout * istruzioniRiposo = dialog.createQHLayout(screenLayout);
    QHBoxLayout * descrizione = dialog.createQHLayout(screenLayout);
    QHBoxLayout * text = dialog.createQHLayout(screenLayout);
    QHBoxLayout * bottoni = dialog.createQHLayout(screenLayout);

    dialog.createQLabel(scritta, "Inserire i dati relativi all'esericizio SollevamentoPesi");
    dialog.createQLabel(nome, "Nome: ");
    dialog.createQLabel(MET, "MET: ");
    dialog.createQLabel(durata, "Durata: ");
    dialog.createQLabel(velocita, "Velocita': ");
    dialog.createQLabel(peso, "Peso: ");
    dialog.createQLabel(istruzioniRiposo, "Istruzioni riposo: ");
    dialog.createQLabel(descrizione, "Descrizione");

    QLineEdit * nomeLine = dialog.createQLineEdit(nome, "Nome");
    QLineEdit * METLine = dialog.createQLineEdit(MET, "MET", 2);
    QLineEdit * durataLineOre = dialog.createQLineEdit(durata, "HH", 2);
    QLineEdit * durataLineMinuti = dialog.createQLineEdit(durata, "MM", 2);
    QLineEdit * durataLineSecondi = dialog.createQLineEdit(durata, "SS", 2);
    QLineEdit * velocitaLine = dialog.createQLineEdit(velocita, "0-10", 2);
    QLineEdit * istruzioniRiposoLine = dialog.createQLineEdit(istruzioniRiposo, "Istruzioni riposo");
    QLineEdit * pesoLine = dialog.createQLineEdit(peso, "Peso");

    QTextEdit * textEdit = dialog.createQTextEdit(text, "Descrizione esercizio ... ");

    QPushButton * crea = dialog.createQPushButton(bottoni, "Crea");

    QWidget ** arr = new QWidget*[10]{nomeLine, METLine, durataLineOre, durataLineMinuti, durataLineSecondi, velocitaLine, pesoLine, textEdit, istruzioniRiposoLine, crea};

    d->show();

    return arr;
}

void Dialog::createShowMessageDialog(QWidget * parent, const string & message) {
    QDialog * dialog = new QDialog(parent);
    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(new QLabel(QString::fromStdString(message), dialog));
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setMaximumSize(QSize(500, 200));
    dialog->setMinimumSize(QSize(300, 100));
    dialog->show();
}

int Dialog::createShowGetNumberDialog(QWidget * parent, const string & tipoDialog) {
    bool ok = false;
    string fun = tipoDialog + " un Esercizio";
    string fun1 = "Nessun Esercizio scelto: " + tipoDialog + "() annullata!";
    int num = QInputDialog::getInt(parent, tr(fun.c_str()), "Indice dell'Esercizio: ", 1, 1, 2147483647, 1, &ok);
    if (!ok) {
        throw std::runtime_error(fun1);
    }

    return num;
}
