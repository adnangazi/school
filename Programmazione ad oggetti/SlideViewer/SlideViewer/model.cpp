#include "model.h"

Model::Model() : slideshow(new Slideshow) {} //come fare slideshow = new SlideShow(): slideshow puntatore ad un oggetto SlideShow nella HEAP (utilizzo singleton si SlideShow: uno solo nel programma e tutti (controller) usa solo questo)

Model::~Model() {
    delete slideshow;
}

void Model::addNewSlide(string path) const {
    Slidecreator sc;
    slideshow->addSlide(sc.createSlide(path));
}

void Model::mergeSlide(u_int firstSlide, u_int secondSlide) const { //merge e inserimento nella posizione della prima slide
    if (firstSlide > secondSlide) { //riordino gli indici in ordine crescente
        u_int temp = firstSlide;
        firstSlide = secondSlide;
        secondSlide = temp;
    } //INVARIANTE FINE IF: firstSlide <= secondSlide

    Slide * first = slideshow->removeSlide(firstSlide);
    Slide * second;
    if (firstSlide != secondSlide) { //non posso rimuovere una slide due volte: rimuovo una e la assegno all'altra nel caso in cui i due indici si riferiscano alla stessa slide
        second = slideshow->removeSlide(secondSlide);
    } else {
        second = first;
    }

    Slidecreator sc;
    slideshow->insertSlide(sc.composeSlide(first, second), firstSlide);
}

void Model::removeSlide(u_int index) const {
    slideshow->removeSlide(index);
}

void Model::previousSlide() const {
    slideshow->previous();
}

void Model::restartSlideShow() const {
    slideshow->goToStart();
}

void Model::endSlideShow() const {
    slideshow->goToEnd();
}

Slide * Model::getSlide() const {
    return slideshow->getSlide(slideshow->getCurrentSlide());
}

u_int Model::getCurrent() const {
    return slideshow->getCurrentSlide();
}

u_int Model::getSlideShowSize() const {
    return slideshow->getSize();
}
