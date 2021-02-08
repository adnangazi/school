#ifndef VIEWCREATOR_H
#define VIEWCREATOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QDialog>
#include <QScrollArea>
#include <QLineEdit>
#include <QTextEdit>
#include <string>
using std::string;

class ViewCreator : public QWidget {
    Q_OBJECT
public:
    ViewCreator();

    static QDialog * createQDialog(QWidget * parent, const int MH, const int MW, const int RH, const int RW);
    static QVBoxLayout * createQVLayout(QBoxLayout * parent);
    static QHBoxLayout * createQHLayout(QBoxLayout * parent);
    static QLineEdit * createQLineEdit(QBoxLayout * parent, const string & ph = "", const int ml = -1);
    static QTextEdit * createQTextEdit(QBoxLayout * parent, const string & ph = "", const int minW = -1, const int minH = -1, const int maxW = -1, const int maxH = -1);
    static void createQLabel(QBoxLayout * parent, const string & nome);
    static QPushButton * createQPushButton(QBoxLayout * parent, const string & nome);
    static void createQLine(QBoxLayout * parent, const char tipo);
    static QWidget * createQWidget(QBoxLayout *parent, const int minW, const int minH, const int maxW, const int maxH);
    static QVBoxLayout * createQScrollArea(QWidget *parent);
};

#endif // VIEWCREATOR_H
