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

    //metodi privati della classe
    void createControllerAllenamento(QMenuBar * const menuBar);
    void createAiuto(QMenuBar * const menuBar);

public:
    //costruttori
    explicit Menus(QVBoxLayout * const ml);

    //metodi della classe
    void createMenus();
    QMenu * getControllerAllenamento() const;
    QMenu * getAiuto() const;
    QMenu * getAggiungiEsercizio() const;
    QMenu * getCambiaEsercizio() const;
    QMenu * getAggiungiRiposoAttivo() const;
    QMenu * getCambiaRiposoAttivo() const;
};

#endif // MENUS_H
