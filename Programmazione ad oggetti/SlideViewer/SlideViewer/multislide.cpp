#include "multislide.h"

Multislide::Multislide(bool h) : dividedHorizontally(h) {}

Multislide::~Multislide() {
    for (Slide * sl : slides) delete sl;
}

void Multislide::addSlide(Slide * slide) {
    slides.push_back(slide);
}

Slide * Multislide::removeSlide(u_int index) {
    if (index >= static_cast<u_int>(slides.size())) {
        throw std::out_of_range("Index greater than the number of the existing slides!");
    }
    Slide * sl = slides[index];
    slides.erase(slides.begin() + index);
    return sl;
}

bool Multislide::isDividedHorizontaly() const {
    return dividedHorizontally;
}

const std::vector <Slide *> & Multislide::getSlides() const {
    return slides;
}

u_int Multislide::getMaxHeight() const {
    if (isDividedHorizontaly()) {
        u_int max = 0;
        for (Slide * sl : slides) {
            if (sl->getMaxHeight() >= max) {
                max = sl->getMaxHeight();
            }
        }
        return max;
    } else {
        return std::accumulate(
                    slides.begin(),
                    slides.end(),
                    0,
                    [](int acc, Slide * el) {
                        return acc + el->getMaxHeight();
                    }
        );
    }
}

u_int Multislide::getMaxWidth() const {
    if (isDividedHorizontaly()) {
        return std::accumulate(
                    slides.begin(),
                    slides.end(),
                    0,
                    [](int acc, Slide * el) {
                        return acc + el->getMaxWidth();
                    }
        );
    } else {
        u_int max = 0;
        for (Slide * sl : slides) {
            if (sl->getMaxWidth() >= max) {
                max = sl->getMaxWidth();
            }
        }
        return max;
    }
}
