#ifndef SCREEN_H
#define SCREEN_H

#include "widgetcreator.h"
#include <QProgressBar>

class Screen : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout * mainLayout;
    QVBoxLayout * esercizio;
    QVBoxLayout * dettagliEsercizio;
    QVBoxLayout * dettagliAllenamento;
    QVBoxLayout * listaEsercizi;
    QTextEdit * log;
    QPushButton * startButton;
    QPushButton * previousButton;
    QPushButton * nextButton;
    QPushButton * endButton;
    QProgressBar * progressBar;

public:
    //costruttori
    explicit Screen(QVBoxLayout * const ml);

    //metodi della classe
    QVBoxLayout * createMainWindow(WidgetCreator & v, QVBoxLayout * const screenLayout);
    void createControllerEsercizi(WidgetCreator & v, QVBoxLayout * const sinistra);
    void createLog(WidgetCreator & v, QVBoxLayout * const screenLayout);
    void createScreen();
    QLabel * createQLabelOnQVLayout(QVBoxLayout * const parent, const string & nome, const bool bald = false, const int size = -1);
    void createQLabelOnQtext(QTextEdit * const parent, const string & nome);
    void clearLayout(QVBoxLayout * const layout);
    void updateProgressBar(const uint current, const uint limit);

    QVBoxLayout * getEsercizio();
    QVBoxLayout * getDettagliEsercizio();
    QVBoxLayout * getDettagliAllenamento();
    QVBoxLayout * getListaEsercizi();

    QTextEdit * getLog();

    QPushButton * getStart();
    QPushButton * getPrevious();
    QPushButton * getNext();
    QPushButton * getEnd();
};

#endif // SCREEN_H
