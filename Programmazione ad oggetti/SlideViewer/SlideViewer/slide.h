#ifndef SLIDE_H
#define SLIDE_H

typedef unsigned int u_int;

class Slide {
    public:
        virtual ~Slide() = default;
        virtual u_int getMaxWidth() const = 0;
        virtual u_int getMaxHeight() const = 0;
        bool isHorizontal() const;
};

#endif // SLIDE_H
