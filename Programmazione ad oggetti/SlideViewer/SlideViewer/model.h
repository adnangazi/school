#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <utility>

#include "slide.h"
#include "slidecreator.h"
#include "slideshow.h"

typedef unsigned int u_int;
using std::string;

class Model {
private:
    Slideshow * slideshow;

public:
    Model();
    ~Model();
    void addNewSlide(string path) const;
    void mergeSlide(u_int firstSlide, u_int secondSlide) const;
    void removeSlide(u_int index) const;
    void previousSlide() const;
    void restartSlideShow() const;
    void endSlideShow() const;
    Slide * getSlide() const;
    u_int getCurrent() const;
    u_int getSlideShowSize() const;
};

#endif // MODEL_H
