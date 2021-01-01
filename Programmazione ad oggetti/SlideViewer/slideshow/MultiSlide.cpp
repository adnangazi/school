#include "MultiSlide.h"

MultiSlide::MultiSlide(bool h) : dividedHorizontally(h) {}

MultiSlide::~MultiSlide() {
    for (auto sl : slides) delete sl;
}

void MultiSlide::addSlide(Slide* slide) { slides.push_back(slide); }

Slide* MultiSlide::removeSlide(u_int index) {
    if (index >= static_cast<u_int>(slides.size()))
        throw std::out_of_range("Index greater than the number of existing slides");
    auto sl = slides[index];
    slides.erase(slides.begin() + index);
    return sl;
}

bool MultiSlide::isDividedHorizontally() const { return dividedHorizontally; }

const std::vector<Slide*>& MultiSlide::getSlides() const { return slides; }

u_int MultiSlide::getMaxHeight() const {
    if (isDividedHorizontally()) {
        u_int max = 0;
        for (auto sl : slides) {
            if (sl->getMaxHeight() > max) max = sl->getMaxHeight();
        }
        return max;
    } else {
        return std::accumulate(
                slides.begin(),
                slides.end(),
                0,
                [](int acc, Slide* el) { return acc + el->getMaxHeight(); }
        );
    }
}

u_int MultiSlide::getMaxWidth() const {
    if (isDividedHorizontally()) {
        return std::accumulate(
                slides.begin(), slides.end(), 0,
                [](int acc, Slide* el) { return acc + el->getMaxWidth(); });
    } else {
        u_int max = 0;
        for (auto sl : slides) {
            if (sl->getMaxWidth() > max) max = sl->getMaxWidth();
        }
        return max;
    }
}
