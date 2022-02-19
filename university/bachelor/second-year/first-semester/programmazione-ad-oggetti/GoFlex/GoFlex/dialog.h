#ifndef DIALOG_H
#define DIALOG_H

#include "widgetcreator.h"
#include <QInputDialog>

class Dialog : public QWidget {
    Q_OBJECT
private:
    QDialog * d;
    QLineEdit * nomeLine;
    QLineEdit * METLine;
    QLineEdit * pesoLine;
    QLineEdit * ripetizioniLine;
    QLineEdit * serieLine;
    QLineEdit * istruzioniRiposoLine;
    QLineEdit * durataLineOre;
    QLineEdit * durataLineMinuti;
    QLineEdit * durataLineSecondi;
    QLineEdit * velocitaLine;
    QTextEdit * textEdit;
    QPushButton * crea;

public:
    //metodi della classe
    void createShowCreateCardioDialog(QWidget * const parent);
    void createShowCreateSollevamentoPesiDialog(QWidget * const parent);
    void createShowCreateCrossFitDialog(QWidget * const parent);
    void createShowCreateRiposoPassivoDialog(QWidget * const parent);
    void createShowCreateRiposoAttivoCardioDialog(QWidget * const parent);
    void createShowCreateRiposoAttivoSollevamentoPesiDialog(QWidget * const parent);
    void createShowCreateRiposoAttivoCrossFitDialog(QWidget * const parent);

    static void createShowMessageDialog(QWidget * const parent, const string & message);
    static uint createShowGetNumberDialog(QWidget * const parent, const string & tipoDialog);

    QDialog * getDialog();
    QLineEdit * getNomeLine();
    QLineEdit * getMETLine();
    QLineEdit * getPesoLine();
    QLineEdit * getRipetizioniLine();
    QLineEdit * getSerieLine();
    QLineEdit * getIstruzioniRiposoLine();
    QLineEdit * getDurataLineOre();
    QLineEdit * getDurataLineMinuti();
    QLineEdit * getDurataLineSecondi();
    QLineEdit * getVelocitaLine();
    QTextEdit * getTextEdit();
    QPushButton * getCrea();
};

#endif // DIALOG_H
