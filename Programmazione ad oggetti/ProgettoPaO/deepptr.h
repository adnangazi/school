#ifndef DEEPPTR_H
#define DEEPPTR_H

template <class T>
class DeepPtr {
private:
    T * ptr;

public:
    DeepPtr(T * p = 0);
    ~DeepPtr();
    DeepPtr(const DeepPtr<T> & dp);
    T * operator-> ();
    T & operator* ();
    T * get();
    DeepPtr<T> & operator= (const DeepPtr<T> & dp);
};

template <class T>
DeepPtr<T>::DeepPtr(T * p) : ptr(p) {}

template <class T>
DeepPtr<T>::~DeepPtr() {
    delete ptr;
}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr<T> & dp) : ptr(dp.ptr->clone()) {}

//DeepPtr->funzioneDiClasseT --> (ptr --> *ptr --> *ptr.) automatico
template <class T>
T * DeepPtr<T>::operator-> () {
    return ptr;
}

//*DeepPtr --> riferimento a ptr
template<class T>
T & DeepPtr<T>::operator* () {
    return * ptr;
}

template<class T>
T * DeepPtr<T>::get() {
    return ptr;
}

template <class T>
DeepPtr<T> & DeepPtr<T>::operator= (const DeepPtr<T> & dp) {
    if (this != & dp) {
        delete ptr;
        ptr = dp.ptr->clone();
    }
    return * this;
}

#endif // DEEPPTR_H
