#include "Slide.h"

bool Slide::isHorizontal() const {
    return getMaxWidth() >= getMaxHeight();
}
