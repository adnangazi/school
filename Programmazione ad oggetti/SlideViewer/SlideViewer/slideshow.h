#ifndef SLIDESHOW_H
#define SLIDESHOW_H
#include "slide.h"
#include <vector>
#include <stdexcept>

typedef unsigned int u_int;

class Slideshow {
private:
    u_int currentSlide;
    std::vector<Slide *> slides;

public:
    Slideshow();
    ~Slideshow();
    void addSlide(Slide * slide);
    void insertSlide(Slide * slide, u_int index);
    Slide * removeSlide(u_int index);
    u_int getCurrentSlide() const;
    Slide * getSlide(u_int index) const;
    u_int getSize() const;
    void previous();
    void next();
    void goToStart();
    void goToEnd();
};

#endif // SLIDESHOW_H
