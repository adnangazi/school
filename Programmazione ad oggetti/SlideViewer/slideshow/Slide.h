#ifndef _SLIDE_H
#define _SLIDE_H

typedef unsigned int u_int;

class Slide {
 public:

    virtual ~Slide() = default;

    /**
     * @brief getMaxHeight		Restituisce l'altezza massima della slide
     * @return u_int					Altezza massima della slide
     */
    virtual u_int getMaxHeight() const = 0;

    /**
     * @brief getMaxWidth			Restituisce la larghezza massima della slide
     * @return u_int					Larghezza massima della slide
     */
    virtual u_int getMaxWidth() const = 0;

    /**
     * @brief isHorizontal		Restituisce true se la slide è orizzontale
     * @return bool						true sse slide orizzontale
     */
    bool isHorizontal() const;
};

#endif  //_SLIDE_H
