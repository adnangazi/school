#ifndef DLIST_H
#define DLIST_H

#include <iostream>

typedef unsigned int uint;

template <class T>
class DList {
private:
    class Nodo {
        friend class DList<T>;
    private:
        T * info;
        Nodo * prev;
        Nodo * next;
    public:
        //costruttori e distruttori
        Nodo(T * const i, Nodo * const p = 0, Nodo * const n = 0);
        ~Nodo();
    };

    uint size;
    Nodo * first;
    Nodo * last;

    //metodi privati della classe
    static void destroy(Nodo * const n);
    static void deepCopy(Nodo * const first, Nodo *& f, Nodo *& l);
public:
    //costruttori e distruttori
    DList(Nodo * const f = 0, Nodo * const l = 0);
    ~DList();
    DList(const DList<T> & d);

    //metodi della classe
    uint getSize() const;
    bool empty() const;
    void pushBack(T * const i);
    void pushFront(T * const i);
    void push(T * const i, const uint pos);
    T * popBack();
    T * popFront();
    T * pop(const uint pos);
    void set(T * i, const uint pos);

    //@overload operatori
    DList<T> & operator=(const DList<T> & d);
    T operator[](const uint pos) const;
};

template<class T>
DList<T>::Nodo::Nodo(T * const i, Nodo * const p, Nodo * const n) : info(i), prev(p), next(n) {}

template <class T>
DList<T>::Nodo::~Nodo() {
    delete info;
}

template<class T>
void DList<T>::destroy(Nodo * const n) {
    if (n != nullptr) {
        destroy(n->next);
        delete n;
    }
}

template<class T>
void DList<T>::deepCopy(Nodo * const first, Nodo *& f, Nodo *& l) {
    if (first != nullptr) {
        f = l = new Nodo(first->info);
        Nodo * temp = first->next;
        while (temp != nullptr) {
            l = new Nodo(temp->info, l);
            l->prev->next = l;
            temp = temp->next;
        }
    } else {
        f = l = nullptr;
    }
}

template<class T>
DList<T>::DList(Nodo * const f, Nodo * const l) : first(f), last(l) {
    Nodo * temp = first;
    size = 0;
    while (temp) {
        size++;
        temp = temp->next;
    }
}

template<class T>
DList<T>::~DList() {
    size = 0;
    destroy(first);
}

template<class T>
DList<T>::DList(const DList<T> & d) {
    size = d.size;
    deepCopy(d.first, first, last);
}

template<class T>
uint DList<T>::getSize() const {
    return size;
}

template<class T>
bool DList<T>::empty() const {
    return size == 0;
}

template<class T>
void DList<T>::pushBack(T * const i) {
    if (!empty()) {
        last = new Nodo(i, last);
        last->prev->next = last;
    } else {
        first = last = new Nodo(i);
    }
    size++;
}

template<class T>
void DList<T>::pushFront(T * const i) {
    first = new Nodo(i, nullptr, first);
    if (!empty()) {
        first->next->prev = first;
    } else {
        last = first;
    }
    size++;
}

template<class T>
void DList<T>::push(T * const i, const uint pos) {
    if (pos >= size) {
        pushBack(i);
    } else if (pos == 0) {
        pushFront(i);
    } else {
        Nodo * temp = first;
        for (uint i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        temp->next = new Nodo(i, temp, temp->next);
        temp->next->next->prev = temp->next;
        size++;
    }
}

template<class T>
T * DList<T>::popBack() {
    if (empty()) {
        std::cout << "Impossibile fare pop da una lista vuota!" << std::endl;
        exit(1);
    }
    size--;
    Nodo * const temp = last;
    if (last != first) {
        last = last->prev;
    } else {
        first = last = nullptr;
    }
    T * const info = temp->info;
    delete temp;
    return  info;
}

template<class T>
T * DList<T>::popFront() {
    if (empty()) {
        std::cout << "Impossibile fare pop da una lista vuota!" << std::endl;
        exit(1);
    }
    size--;
    Nodo * const temp = first;
    if (first != last) {
        first = first->next;
    } else {
        first = last = nullptr;
    }
    T * const info = temp->info;
    delete temp;
    return  info;
}

template<class T>
T * DList<T>::pop(const uint pos) {
    if (empty()) {
        std::cout << "Impossibile fare pop da una lista vuota!" << std::endl;
        exit(1);
    }
    if (pos >= size - 1) {
        return popBack();
    } else if (pos == 0) {
        return popFront();
    } else {
        size--;
        Nodo * temp = first;
        for (uint i = 0; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        T * info = temp->info;
        delete temp;
        return  info;
    }
}

template<class T>
void DList<T>::set(T * const i, const uint pos) {
    if (empty() || pos >= size) {
        std::cout << "Impossibile fare set da una lista vuota o posizione del set errata!" << std::endl;
        exit(1);
    }
    if (pos == size - 1) {
        last->info = i;
    } else if (pos == 0) {
        first->info = i;
    } else {
        Nodo * temp = first;
        for (uint i = 0; i < pos; i++) {
            temp = temp->next;
        }
        delete temp->info;
        temp->info = i;
    }
}

template<class T>
DList<T> & DList<T>::operator=(const DList<T> & d) {
    if (this != & d) {
        size = d.size;
        destroy(first);
        deepCopy(d.first, first, last);
    }
    return *this;
}

template<class T>
T DList<T>::operator[](const uint pos) const {
    if (empty() || pos >= size) {
        std::cout << "Impossibile fare set da una lista vuota o posizione del set errata!" << std::endl;
        exit(1);
    }
    if (pos == size - 1) {
        return *(last->info);
    } else if (pos == 0) {
        return *(first->info);
    } else {
        Nodo * temp = first;
        for (uint i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return *(temp->info);
    }
}

template <class T>
std::ostream & operator<<(std::ostream & os, const DList<T> & d) {
    for (uint i = 0; i < d.getSize(); i++) {
        os << d[i] << " ";
    }
    return os;
}

#endif // DLIST_H
