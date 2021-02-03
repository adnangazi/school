#ifndef DEEPPTR_H
#define DEEPPTR_H

template <class T>
class DeepPtr {
private:
    T * ptr;

public:
    //costruttori e distruttori
    DeepPtr(T * const p = nullptr);
    DeepPtr(const DeepPtr<T> & dp);
    ~DeepPtr();

    //metodi della classe
    T * get();

    //@overload operatori
    DeepPtr<T> & operator=(const DeepPtr<T> & dp);
    T * operator->();
    T & operator*();
};

//@overload operatori esterni alla classe
template <class T>
bool operator==(const DeepPtr<T> & a, const DeepPtr<T> & b) {
    return a.ptr == b.ptr;
}

template <class T>
bool operator!=(const DeepPtr<T> & a, const DeepPtr<T> & b) {
    return a.ptr != b.ptr;
}

template <class T>
DeepPtr<T>::DeepPtr(T * const p) : ptr(p) {}

template <class T>
DeepPtr<T>::~DeepPtr() {
    delete ptr;
}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr<T> & dp) : ptr(dp.ptr ? dp.ptr->clone() : nullptr) {}

template<class T>
T * DeepPtr<T>::get() {
    return ptr;
}

template <class T>
DeepPtr<T> & DeepPtr<T>::operator=(const DeepPtr<T> & dp) {
    if (this != & dp) {
        delete ptr;
        ptr = dp.ptr ? dp.ptr->clone() : nullptr;
    }
    return * this;
}

//DeepPtr->funzioneDiClasseT --> (ptr --> *ptr --> *ptr.) automatico
template <class T>
T * DeepPtr<T>::operator->() {
    return ptr;
}

//*DeepPtr --> riferimento a ptr
template<class T>
T & DeepPtr<T>::operator*() {
    return * ptr;
}

#endif // DEEPPTR_H
