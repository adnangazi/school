#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view.h"
#include "model.h"
#include <QLabel>
#include <QObject>
#include <iostream>

class Controller : public QObject {
    Q_OBJECT
private:
    View * view;
    Model * model;
    bool cambia;
    int posizione;
    uint operazioneLog;

    //metodi privati della classe
    bool checkMargini(const string & tipoOperazione = "");
    void drawLine(QVBoxLayout * const layout, const string & titolo = "", const string & valore = "");
    void drawEsercizio();
    void drawDettagliEsercizio();
    void drawDettagliAllenamento();
    void drawAllenamento();
    void updateGrafica();

public:
    //costruttori
    explicit Controller(QObject * const parent = nullptr);

    //metodi della classe
    void setModel(Model * const m);
    void setView(View * const v);

public slots:
    void addCardio();
    void setCardio();
    void createCardio();
    void addSollevamentoPesi();
    void setSollevamentoPesi();
    void createSollevamentoPesi();
    void addCrossFit();
    void setCrossFit();
    void createCrossFit();
    void addRiposoPassivo();
    void setRiposoPassivo();
    void createRiposoPassivo();
    void addRiposoAttivoCardio();
    void setRiposoAttivoCardio();
    void createRiposoAttivoCardio();
    void addRiposoAttivoSollevamentoPesi();
    void setRiposoAttivoSollevamentoPesi();
    void createRiposoAttivoSollevamentoPesi();
    void addRiposoAttivoCrossFit();
    void setRiposoAttivoCrossFit();
    void createRiposoAttivoCrossFit();

    void remove();

    void whatIsMET();
    void whatIsCrossFit();
    void whatIsRiposoAttivo();

    void next();
    void previous();
    void goToStart();
    void goToEnd();
};

#endif // CONTROLLER_H
