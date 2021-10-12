#include "Model.h"

Model::Model() : slideshow(new SlideShow) {}

Model::~Model() { delete slideshow; }

void Model::addNewSlide(string path) const {
    SlideCreator creator;
    slideshow->addSlide(creator.createSlide(path));
}

void Model::mergeSlides(u_int firstIndex, u_int secondIndex) const {
    SlideCreator creator;

    if (firstIndex > secondIndex) {
        std::swap(firstIndex, secondIndex);
    }
    Slide* first;
    Slide* second = slideshow->removeSlide(secondIndex);

    if (firstIndex != secondIndex)
        first = slideshow->removeSlide(firstIndex);
    else
        first = second;
    Slide* newSlide =
            creator.composeSlides(first, second,
                                                        first->getMaxWidth() + second->getMaxWidth() <=
                                                                first->getMaxHeight() + second->getMaxHeight());

    slideshow->insertSlide(newSlide, firstIndex);
}

void Model::removeSlide(u_int index) const { slideshow->removeSlide(index); }

void Model::nextSlide() const { slideshow->next(); }

void Model::previousSlide() const { slideshow->previous(); }

void Model::restartSlideShow() const { slideshow->goToStart(); }

void Model::endSlideShow() const { slideshow->goToEnd(); }

Slide* Model::getSlide() const {
    return slideshow->getSlide(slideshow->getCurrentSlide());
}

u_int Model::getCurrent() const { return slideshow->getCurrentSlide(); }

u_int Model::getSlideShowSize() const { return slideshow->getSize(); }
