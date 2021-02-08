#ifndef VIEWCREATOR_H
#define VIEWCREATOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <string>
using std::string;

class ViewCreator : public QWidget {
    Q_OBJECT
private:

public:
    ViewCreator();

    QDialog * createQDialog(QWidget * parent = nullptr, const int MH = -1, const int MW = -1, const int RH = -1, const int RW = -1);

    QVBoxLayout * createQVVLayout(QVBoxLayout * parent);
    QVBoxLayout * createQHVLayout(QHBoxLayout * parent);
    QHBoxLayout * createQVHLayout(QVBoxLayout * parent);
    QHBoxLayout * createQHHLayout(QHBoxLayout * parent);

    QLineEdit * createQLineEdit(QHBoxLayout * parent, const string & ph = "", const int ml = -1);
    QTextEdit * createQTextEdit(QHBoxLayout * parent, const string & ph = "");

    void createQHLabel(QHBoxLayout * parent, const string & nome);
    void createQVLabel(QVBoxLayout * parent, const string & nome);

    QPushButton * createQPushButton(QHBoxLayout * parent, const string & nome);
    QFrame * createQVLine(QHBoxLayout * parent);
    QFrame * createQHLine(QVBoxLayout * parent);
};

#endif // VIEWCREATOR_H
