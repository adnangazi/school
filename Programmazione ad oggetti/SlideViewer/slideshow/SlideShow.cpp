#include "SlideShow.h"

SlideShow::SlideShow() : currentSlide(0), slides() {}

SlideShow::~SlideShow()
{
    for (auto i: slides) delete i;
}

void SlideShow::addSlide(Slide* slide) {
    slides.push_back(slide);
    currentSlide = slides.size() - 1;
}

void SlideShow::insertSlide(Slide* slide, u_int index) {
    if (slides.empty())
        slides.push_back(slide);
    else
        slides.insert(
                slides.begin() + (index < slides.size() ? index : slides.size() - 1),
                slide);
    currentSlide = (index < slides.size() ? index : slides.size() - 1);
}

Slide* SlideShow::removeSlide(u_int index) {
    if (index >= slides.size()) {
        throw std::out_of_range("Index out of range");
    }

    auto sl = slides[index];
    slides.erase(slides.begin() + index);

    // nel caso avessi rimosso l'ultima
    if (currentSlide >= slides.size()) {
        currentSlide = slides.size() ? slides.size() - 1: 0;  // controllo per quando quella rimossa
                                                              // fosse l'ultima di tutta la slideshow
    }
    return sl;
}

u_int SlideShow::getCurrentSlide() const { return currentSlide; }

Slide* SlideShow::getSlide(u_int index) const {
    if (index >= slides.size()) throw std::out_of_range("Index out of range");
    return slides[index];
}

u_int SlideShow::getSize() const { return slides.size(); }

void SlideShow::previous() {
    if (currentSlide > 0) currentSlide--;
}

void SlideShow::next() {
    if (currentSlide < slides.size() - 1) {
        currentSlide++;
    } else {
        goToStart();
    }
}

void SlideShow::goToStart() { currentSlide = 0; }

void SlideShow::goToEnd() { currentSlide = slides.size() - 1; }
