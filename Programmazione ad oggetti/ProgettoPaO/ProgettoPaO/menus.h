#ifndef MENUS_H
#define MENUS_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>

class Menus : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout * mainLayout;
    QMenu * controllerAllenamento;
    QMenu * aiuto;
    QMenu * aggiungiEsercizio;
    QMenu * cambiaEsercizio;
    QMenu * aggiungiRiposoAttivo;
    QMenu * cambiaRiposoAttivo;

public:
    Menus(QVBoxLayout * ml);
    void createMenus();
    QMenu * getControllerAllenamento();
    QMenu * getAiuto();
    QMenu * getAggiungiEsercizio();
    QMenu * getCambiaEsercizio();
    QMenu * getAggiungiRiposoAttivo();
    QMenu * getCambiaRiposoAttivo();
};

#endif // MENUS_H
