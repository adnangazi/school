#ifndef SCREEN_H
#define SCREEN_H

#include "viewcreator.h"

class Screen : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout * mainLayout;

public:
    QVBoxLayout * esercizio;
    QVBoxLayout * dettagliEsercizio;
    QVBoxLayout * dettagliAllenamento;
    QVBoxLayout * listaEsercizi;
    QTextEdit * log;

    Screen(QVBoxLayout * const ml);
    void createScreen();
    QLabel * createQLabelOnQVLayout(QVBoxLayout * parent, const string & nome);
    void createQLabelOnQtext(QTextEdit * parent, const string & nome);
};

#endif // SCREEN_H
