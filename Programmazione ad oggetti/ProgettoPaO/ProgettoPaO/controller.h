#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view.h"
#include "model.h"

#include <QObject>
#include <iostream>
using namespace std;

class Controller : public QObject {
    Q_OBJECT
private:
    View * view;
    Model * model;
    QWidget ** dialogPointer;

    void drawEsercizio();
    void drawAllenamento();

public:
    explicit Controller(QObject * parent = nullptr);
    void setModel(Model * m);
    void setView(View * v);

public slots:
    void addCardio();
    void createCardio();
    void addSollevamentoPesi();
    void createSollevamentoPesi();
    void addCrossFit();
    void createCrossFit();
    void addRiposoPassivo();
    void createRiposoPassivo();
    void addRiposoAttivoCardio();
    void createRiposoAttivoCardio();
    void addRiposoAttivoSollevamentoPesi();
    void createRiposoAttivoSollevamentoPesi();
    void addRiposoAttivoCrossFit();
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
