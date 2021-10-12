#include "widgetcreator.h"

QDialog * WidgetCreator::createQDialog(QWidget * const parent, const uint MH, const uint MW, const uint RH, const uint RW) {
    QDialog * const dialog = new QDialog(parent);
    dialog->setMaximumSize(QSize(MW, MH));
    dialog->setMinimumSize(QSize(RW, RH));
    dialog->resize(QSize(RW, RH));
    dialog->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    return dialog;
}

QVBoxLayout * WidgetCreator::createQVLayout(QBoxLayout * const parent) {
    QVBoxLayout * const layout = new QVBoxLayout;
    parent->addLayout(layout);
    return layout;
}

QHBoxLayout * WidgetCreator::createQHLayout(QBoxLayout * const parent) {
    QHBoxLayout * const layout = new QHBoxLayout;
    parent->addLayout(layout);
    return layout;
}

QLineEdit * WidgetCreator::createQLineEdit(QBoxLayout * const parent, const string & ph, const int ml) {
    QLineEdit * const line = new QLineEdit;
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

QTextEdit * WidgetCreator::createQTextEdit(QBoxLayout * const parent, const string & ph, const int minW, const int minH) {
    QTextEdit * text = new QTextEdit;
    text->setPlaceholderText(QString::fromStdString(ph));
    if (minW >= 0) {
        text->setMinimumSize(QSize(minW, minH));
    }
    parent->addWidget(text);
    text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    text->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    return text;
}

QLabel * WidgetCreator::createQLabel(QBoxLayout * const parent, const string & nome, const bool bald, const int size) {
    QLabel * const label = new QLabel(tr(nome.c_str()));
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    parent->addWidget(label);
    QFont f("Arial");
    f.setBold(bald);
    if (size >= 0) {
        f.setPointSize(size);
    }
    label->setFont(f);

    return label;
}

void WidgetCreator::createQLabelOnQText(QTextEdit * const parent, const string & nome) {
    parent->setText(parent->toPlainText() + QString::fromStdString(nome) + "\n");
}

QPushButton * WidgetCreator::createQPushButton(QBoxLayout * const parent, const string & nome) {
    QPushButton * const button = new QPushButton(QString::fromStdString(nome));
    parent->addWidget(button);
    parent->setAlignment(nome == "Crea" ? Qt::AlignRight : Qt::AlignCenter);
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    return button;
}

void WidgetCreator::createQLine(QBoxLayout * const parent, const char tipo) {
    QFrame * const line = new QFrame;
    line->setFrameShape(tipo == 'H' ? QFrame::HLine : QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    parent->addWidget(line);
}

QWidget * WidgetCreator::createQWidget(QBoxLayout * const parent, const int minW, const uint minH, const int maxH) {
    QWidget * const w = new QWidget;
    w->setMinimumSize(QSize(minW, minH));
    if (maxH >= 0) {
        w->setMaximumHeight(maxH);
    }
    w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    parent->addWidget(w);
    return w;
}

QVBoxLayout * WidgetCreator::createQScrollArea(QWidget * const parent) {
    QVBoxLayout * const layout = new QVBoxLayout;
    parent->setLayout(layout);
    QScrollArea * const scrollArea = new QScrollArea;
    layout->addWidget(scrollArea);
    QWidget * const scrollWidget= new QWidget;
    scrollArea->setWidget(scrollWidget);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    QVBoxLayout * const scrollLayout= new QVBoxLayout(scrollWidget);
    scrollWidget->setLayout(scrollLayout);
    scrollWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    return scrollLayout;
}

QProgressBar * WidgetCreator::createQProgressBar(QVBoxLayout * const parent) {
    QProgressBar * const progressBar = new QProgressBar;
    progressBar->setAlignment(Qt::AlignCenter);
    progressBar->setRange(0, 0);
    progressBar->setValue(0);
    progressBar->setFormat("%v / %m");
    parent->addWidget(progressBar);
    progressBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    return progressBar;
}
