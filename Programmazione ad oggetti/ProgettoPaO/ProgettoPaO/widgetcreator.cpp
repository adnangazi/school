#include "viewcreator.h"

ViewCreator::ViewCreator() {}

QDialog * ViewCreator::createQDialog(QWidget * parent, const int MH, const int MW, const int RH, const int RW) {
    QDialog * dialog = new QDialog(parent);
    dialog->setMaximumHeight(MH);
    dialog->setMaximumWidth(MW);
    dialog->setMinimumHeight(RH);
    dialog->setMinimumWidth(RW);
    dialog->resize(QSize(RH, RW));

    return dialog;
}

QVBoxLayout * ViewCreator::createQVLayout(QBoxLayout * parent) {
    QVBoxLayout * layout = new QVBoxLayout;
    parent->addLayout(layout);
    return layout;
}

QHBoxLayout * ViewCreator::createQHLayout(QBoxLayout * parent) {
    QHBoxLayout * layout = new QHBoxLayout;
    parent->addLayout(layout);
    return layout;
}

QLineEdit * ViewCreator::createQLineEdit(QBoxLayout * parent, const string & ph, const int ml) {
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

QTextEdit * ViewCreator::createQTextEdit(QBoxLayout * parent, const string & ph, const int minW, const int minH) {
    QTextEdit * text = new QTextEdit;
    text->setPlaceholderText(QString::fromStdString(ph));
    if (minW >= 0) {
        text->setMinimumSize(QSize(minW, minH));
    }
    parent->addWidget(text);
    return text;
}

QLabel * ViewCreator::createQLabel(QBoxLayout * parent, const string & nome) {
    QLabel * label = new QLabel(tr(nome.c_str()));
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    parent->addWidget(label);

    return label;
}

void ViewCreator::createQLabelOnQText(QTextEdit *parent, const string & nome) {
    parent->setText(parent->toPlainText() + QString::fromStdString(nome) + "\n");
}

QPushButton * ViewCreator::createQPushButton(QBoxLayout * parent, const string & nome) {
    QPushButton * button = new QPushButton(QString::fromStdString(nome));
    parent->addWidget(button);
    parent->setAlignment(nome == "Crea" ? Qt::AlignRight : Qt::AlignCenter);
    return button;
}

void ViewCreator::createQLine(QBoxLayout * parent, const char tipo) {
    QFrame * line = new QFrame;
    line->setFrameShape(tipo == 'H' ? QFrame::HLine : QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    parent->addWidget(line);
}

QWidget *ViewCreator::createQWidget(QBoxLayout *parent, const int minW, const int minH, const int maxH) {
    QWidget * w = new QWidget;
    w->setMinimumSize(QSize(minW, minH));
    if (maxH >= 0) {
        w->setMaximumHeight(maxH);
    }
    w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    parent->addWidget(w);
    return w;
}

QVBoxLayout * ViewCreator::createQScrollArea(QWidget * parent) {
    QVBoxLayout * layout = new QVBoxLayout;
    parent->setLayout(layout);
    QScrollArea * scrollArea = new QScrollArea;
    layout->addWidget(scrollArea);
    QWidget* scrollWidget= new QWidget;
    scrollArea->setWidget(scrollWidget);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    QVBoxLayout * scrollLayout= new QVBoxLayout(scrollWidget);
    scrollWidget->setLayout(scrollLayout);

    return scrollLayout;
}
