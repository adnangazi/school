#ifndef DIALOG_H
#define DIALOG_H

#include "viewcreator.h"
#include <QInputDialog>

class Dialog : public QWidget {
    Q_OBJECT
public:
    Dialog();

    static void createShowCreateCardioDialog(QWidget * parent);
    static void createShowCreateSollevamentoPesiDialog(QWidget * parent);
    static void createShowCreateCrossFitDialog(QWidget * parent);
    static void createShowCreateRiposoPassivoDialog(QWidget * parent);
    static void createShowCreateRiposoAttivoDialog(QWidget * parent);

    void createShowMessageDialog(QWidget * parent, const string & message);
    int createShowGetNumberDialog(QWidget * parent, const string & tipoDialog);
};

#endif // DIALOG_H
