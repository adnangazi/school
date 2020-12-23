#include "slideviewer.h"

void SlideViewer::clearLayout(QLayout * layout) const {
    QLayoutItem * item;
    while ((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void SlideViewer::showSlideRecursive(Slide *slide, QBoxLayout *layout, double scale) {

}

void SlideViewer::addMenus(QVBoxLayout* mainLayout) {
    QMenuBar* menuBar = new QMenuBar(this);

    QMenu* file = new QMenu("File", menuBar);
    QMenu* riproduzione = new QMenu("Riproduzione", menuBar);
    QMenu* slide = new QMenu("Slide", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(riproduzione);
    menuBar->addMenu(slide);

    // Menù "File"
    file->addAction(new QAction("Chiudi", file));

    // Menù "Riproduzione"
    riproduzione->addAction(new QAction("Inizio", riproduzione));
    riproduzione->addAction(new QAction("Precedente", riproduzione));
    riproduzione->addAction(new QAction("Successiva", riproduzione));
    riproduzione->addAction(new QAction("Fine", riproduzione));
    riproduzione->addAction(new QAction("Autoriproduzione On/Off", riproduzione));

    // Menù "Slide"
    slide->addAction(new QAction("Aggiungi slide", slide));
    slide->addAction(new QAction("Rimuovi slide", slide));
    slide->addAction(new QAction("Unisci slide", slide));

    mainLayout->addWidget(menuBar);
}

void SlideViewer::addScreen(QVBoxLayout* mainLayout) {
    QVBoxLayout* screenLayout = new QVBoxLayout;

    QFrame* image = new QFrame;

    QHBoxLayout* imageLayout = new QHBoxLayout;
    imageLayout->addWidget(new QLabel(this));

    QProgressBar* progressBar = new QProgressBar;
    progressBar->setRange(0, 0);
    progressBar->setValue(0);
    progressBar->setFormat("%v / %m");

    image->setStyleSheet("background-color: rgb(50,50,50)");
    image->setLayout(imageLayout);
    image->layout()->setMargin(0);
    image->layout()->setSpacing(0);
    image->layout()->setAlignment(Qt::AlignCenter);
    image->setMinimumSize(1024, 720);
    image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    screenLayout->addWidget(image);
    screenLayout->addWidget(progressBar);
    screenLayout->setSpacing(0);
    mainLayout->addLayout(screenLayout);
}

void SlideViewer::addControls(QVBoxLayout* mainLayout) {
    QHBoxLayout* controlsLayout = new QHBoxLayout;

    QHBoxLayout* playLayout = new QHBoxLayout;

    QPushButton* startButton = new QPushButton("Inizio");
    QPushButton* prevButton = new QPushButton("Precedente");
    QPushButton* nextButton = new QPushButton("Successiva");
    QPushButton* endButton = new QPushButton("Fine");

    playLayout->addWidget(startButton);
    playLayout->addWidget(prevButton);
    playLayout->addWidget(nextButton);
    playLayout->addWidget(endButton);
    playLayout->setSpacing(5);
    playLayout->setContentsMargins(20, 0, 20, 0);

    controlsLayout->addLayout(playLayout);

    QPushButton* autoButton = new QPushButton("AUTO");
    controlsLayout->addWidget(autoButton);

    controlsLayout->setSpacing(150);
    controlsLayout->setContentsMargins(150, 20, 150, 20);

    mainLayout->addLayout(controlsLayout);
}

SlideViewer::SlideViewer(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout;

    addMenus(mainLayout);

    addScreen(mainLayout);

    addControls(mainLayout);

    mainLayout->setSpacing(0);
    setLayout(mainLayout);
    resize(QSize(1024, 720));

    showWarning("Prova errore errore errore errore errore errore errore errore errore!");

    QString add = showAddDialog();
    int remove = showRemoveDialog();
    std::pair<int, int> unione = showMergeDialog();

    std::cout << add.toStdString() << std::endl << remove << unione.first << " " << unione.second << std::endl;
}

void SlideViewer::showWarning(const QString & comment) {
    QDialog * dialog = new QDialog(this);
    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(new QLabel(comment, dialog));
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setMaximumWidth(120);
    dialog->setMaximumWidth(500);
    dialog->setMaximumHeight(120);
    dialog->setMaximumHeight(120);
    dialog->show();
}

QString SlideViewer::showAddDialog() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Apri il file"), "/home", tr("Immagini (*.png *.jpg)"));
    if (fileName == "") throw std::runtime_error("Nessun file selezionato: aggiunta annullata!");
    return fileName;
}

int SlideViewer::showRemoveDialog() {
    bool ok = false;
    int remove = QInputDialog::getInt(this, tr("Remove slides"), "Indice della slide:", 1, 1, 2147483647, 1, &ok);
    if (!ok) throw std::runtime_error("Nessana slide scelta: rimozione annuallata!");
    return remove;
}

std::pair<int, int> SlideViewer::showMergeDialog() {
    bool ok1 = false;
    bool ok2 = false;
    int first = QInputDialog::getInt(this, tr("Merge slides"), "Indice della slide:", 1, 1, 2147483647, 1, &ok1);
    int second = QInputDialog::getInt(this, tr("Merge slides"), "Indice della slide:", 1, 1, 2147483647, 1, &ok2);
    if (!ok1 || !ok2) throw std::runtime_error("Non sono stati scelti due indici: unione annuallata!");
    return std::pair<int, int>(first, second);
}

void SlideViewer::showSlide(Slide * slide) {
    clearLayout(image->layout());
    Multislide * s = dynamic_cast<Multislide*>(slide);
    if (s && !s->isDividedHorizontaly()) {
        image->setLayout(new QVBoxLayout);
    } else {
        image->setLayout(new QHBoxLayout);
    }

    if (slide) {
        showSlideRecursive(slide, static_cast<QBoxLayout*>(image->layout()), 1);
    } else {
        image->layout()->addWidget(new QLabel(this));
    }
}
