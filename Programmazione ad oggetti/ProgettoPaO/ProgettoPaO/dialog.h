#ifndef DIALOG_H
#define DIALOG_H

#include "widgetcreator.h"
#include <QInputDialog>

class Dialog : public QWidget {
    Q_OBJECT
public:
    Dialog();

    static QWidget** createShowCreateCardioDialog(QWidget * parent);
    static QWidget** createShowCreateSollevamentoPesiDialog(QWidget * parent);
    static QWidget** createShowCreateCrossFitDialog(QWidget * parent);
    static QWidget** createShowCreateRiposoPassivoDialog(QWidget * parent);
    static QWidget** createShowCreateRiposoAttivoDialog(QWidget * parent);

    static void createShowMessageDialog(QWidget * parent, const string & message);
    static int createShowGetNumberDialog(QWidget * parent, const string & tipoDialog);
};

#endif // DIALOG_H
