#include "dialogcreator.h"

DialogCreator::DialogCreator(QWidget * parent, const int MH, const int MW, const int RH, const int RW) : dialog(new QDialog(parent)) {
    if (MH >= 0) {
        dialog->setMaximumHeight(MH);
    }
    if (MW >= 0) {
        dialog->setMaximumWidth(MW);
    }
    if (RH >= 0) {
        dialog->setMinimumHeight(RH);
    }
    if (RW >= 0) {
        dialog->setMinimumWidth(RW);
    }
    if (RH >= 0 && RW >= 0) {
        dialog->resize(QSize(RH, RW));
    }
}

void DialogCreator::show() {
    dialog->show();
}

QDialog * DialogCreator::getDialog() {
    return dialog;
}

QVBoxLayout * DialogCreator::createQVLayout() {
    QVBoxLayout * layout = new QVBoxLayout;
    dialog->setLayout(layout);
    return layout;
}

QHBoxLayout * DialogCreator::createQHLayout(QVBoxLayout * parent) {
    QHBoxLayout * layout = new QHBoxLayout;
    parent->addLayout(layout);
    return layout;
}

QLineEdit * DialogCreator::createQLineEdit(QHBoxLayout * parent, const string & ph, const int ml) {
    QLineEdit * line = new QLineEdit;
    line->setAlignment(Qt::AlignCenter);
    line->setPlaceholderText(QString::fromStdString(ph));
    line->setClearButtonEnabled(true);
    line->setDragEnabled(true);
    if (ml >= 0) {
        line->setMaxLength(ml);
    }
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    parent->addWidget(line);
    return line;
}

QTextEdit * DialogCreator::createQTextEdit(QHBoxLayout * parent, const string & ph) {
    QTextEdit * text = new QTextEdit;
    text->setPlaceholderText(QString::fromStdString(ph));
    text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    parent->addWidget(text);
    return text;
}

void DialogCreator::createQLabel(QHBoxLayout * parent, const string & nome) {
    QLabel * label = new QLabel(tr(nome.c_str()));
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    parent->addWidget(label);
}

QPushButton * DialogCreator::createQPushButton(QHBoxLayout * parent, const string & nome) {
    QPushButton * button = new QPushButton(QString::fromStdString(nome));
    parent->addWidget(button);
    parent->setAlignment(Qt::AlignRight);
    return button;
}
