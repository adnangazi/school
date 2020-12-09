#include "slideshow.h"

Slideshow::Slideshow() : currentSlide(0), slides() {}

Slideshow::~Slideshow() {
    for (Slide * sl : slides) {
        delete sl;
    }
}

void Slideshow::addSlide(Slide * slide) {
    slides.push_back(slide);
    currentSlide = slides.size() - 1; //slide corrente è quella appena inserita (ultima)
}

void Slideshow::insertSlide(Slide * slide, u_int index) {
    if (slides.empty()) {
        slides.push_back(slide);
    } else {
        slides.insert(slides.begin() + (index < slides.size() ? index : slides.size() - 1), slide); //insert vuole un iteratore, non un indice di posizione: si crea un iteratore alla prima posizione e si aggiunge l'indice
    }
    currentSlide = index < slides.size() ? index : slides.size() - 1;
}

Slide * Slideshow::removeSlide(u_int index) {
    if (index >= slides.size()) {
        throw std::out_of_range("Indice fuori dai bordi!");
    }

    Slide * sl = slides[index];
    slides.erase(slides.begin() + index);

    if (currentSlide >= slides.size()) {
        (currentSlide == slides.size()) ? (currentSlide = slides.size() - 1) : 0;
    }

    return sl;
}

u_int Slideshow::getCurrentSlide() const {
    return currentSlide;
}

Slide * Slideshow::getSlide(u_int index) const {
    if (index >= slides.size()) {
        throw std::out_of_range("Indice fuori dai bordi!");
    }
    return slides[index];
}

u_int Slideshow::getSize() const {
    return slides.size();
}

void Slideshow::previous() {
    if (currentSlide > 0) {
       currentSlide--;
    }
}

void Slideshow::next() {
    if (currentSlide < slides.size() - 1) {
        currentSlide++;
    } else { //facendo slide successiva quando si è all'ultima slide, si ritorna all'inizio (lista circolare di slides)
        goToStart();
    }
}

void Slideshow::goToStart() {
    currentSlide = 0;
}

void Slideshow::goToEnd() {
    currentSlide = slides.size() - 1;
}
