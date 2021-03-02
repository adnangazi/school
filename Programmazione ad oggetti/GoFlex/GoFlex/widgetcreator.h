#ifndef WIDGETCREATOR_H
#define WIDGETCREATOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QDialog>
#include <QScrollArea>
#include <QProgressBar>
#include <QLineEdit>
#include <QTextEdit>
#include <QFont>
#include <string>
using std::string;

class WidgetCreator : public QWidget {
    Q_OBJECT
public:
    //metodi della classe
    static QDialog * createQDialog(QWidget * const parent, const uint MH, const uint MW, const uint RH, const uint RW);
    static QVBoxLayout * createQVLayout(QBoxLayout * const parent);
    static QHBoxLayout * createQHLayout(QBoxLayout * const parent);
    static QLineEdit * createQLineEdit(QBoxLayout * const parent, const string & ph = "", const int ml = -1);
    static QTextEdit * createQTextEdit(QBoxLayout * const parent, const string & ph = "", const int minW = -1, const int minH = -1);
    static QLabel * createQLabel(QBoxLayout * const parent, const string & nome, const bool bald = false, const int size = -1);
    static void createQLabelOnQText(QTextEdit * const parent, const string & nome);
    static QPushButton * createQPushButton(QBoxLayout * const parent, const string & nome);
    static void createQLine(QBoxLayout * const parent, const char tipo);
    static QWidget * createQWidget(QBoxLayout * const parent, const int minW, const uint minH, const int maxH = -1);
    static QVBoxLayout * createQScrollArea(QWidget * const parent);
    static QProgressBar * createQProgressBar(QVBoxLayout * const parent);
};

#endif // WIDGETCREATOR_H
