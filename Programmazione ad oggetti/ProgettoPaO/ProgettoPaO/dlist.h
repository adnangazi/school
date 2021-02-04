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
        T info;
        Nodo * prev;
        Nodo * next;

    public:
        //costruttori e distruttori
        Nodo(const T & i, Nodo * const p = nullptr, Nodo * const n = nullptr);
    };

    uint size;
    Nodo * first;
    Nodo * last;

    //metodi privati della classe
    static void destroy(Nodo * const first);
    static void deepCopy(Nodo * const first, Nodo *& f, Nodo *& l);

public:
    //costruttori e distruttori
    DList(Nodo * const f = nullptr, Nodo * const l = nullptr);
    ~DList();
    DList(const DList & d);

    //metodi della classe
    uint getSize() const;
    bool isEmpty() const;
    void pushBack(const T & i);
    void pushFront(const T & i);
    void push(const T & i, const uint pos = 0);
    T popBack();
    T popFront();
    T pop(const uint pos);
    void set(const T & i, const uint pos);
    bool deepCheckEquals(const DList & d) const;
    bool deepCheckNotEquals(const DList & d) const;

    //@overload operatori
    DList & operator=(const DList & d);
    bool operator==(const DList & d) const;
    bool operator!=(const DList & d) const;
    T & operator[](const uint pos) const;

    class Iterator {
        friend class DList<T>;
    private:
        Nodo * ptr;
        bool past_the_end;

    public:
        //costruttori e distruttori
        Iterator(Nodo * const p = nullptr, const bool pte = false);

        //@overload operatori
        Iterator & operator++();
        Iterator operator++(int);
        Iterator & operator--();
        Iterator operator--(int);
        bool operator==(const Iterator & it) const;
        bool operator!=(const Iterator & it) const;
        T & operator*() const;
        T * operator->() const;
    };

    //metodi della classe
    Iterator begin() const;
    Iterator end() const;
};

template<class T>
DList<T>::Nodo::Nodo(const T & i, Nodo * const p, Nodo * const n) : info(i), prev(p), next(n) {}

template<class T>
void DList<T>::destroy(Nodo * const first) {
    if (first != nullptr) {
        destroy(first->next);
        delete first;
    }
}

template<class T>
void DList<T>::deepCopy(Nodo * const first, Nodo *& f, Nodo *& l) {
    if (first == nullptr) {
        f = l = nullptr;
    } else {
        f = l = new Nodo(first->info);
        Nodo * temp = first->next;
        while (temp != nullptr) {
            l = new Nodo(temp->info, l);
            l->prev->next = l;
            temp = temp->next;
        }
    }
}

template<class T>
DList<T>::DList(Nodo * const f, Nodo * const l) : first(f), last(l) {
    size = 0;
    for (Nodo * temp = first; temp != nullptr; size++) {
        temp = temp->next;
    }
}

template<class T>
DList<T>::~DList() {
    destroy(first);
}

template<class T>
DList<T>::DList(const DList<T> & d) : size(d.size) {
    deepCopy(d.first, first, last);
}

template<class T>
uint DList<T>::getSize() const {
    return size;
}

template<class T>
bool DList<T>::isEmpty() const {
    return size == 0;
}

template<class T>
void DList<T>::pushBack(const T & i) {
    size++;
    if (last != nullptr) {
        last = new Nodo(i, last);
        last->prev->next = last;
    } else {
        first = last = new Nodo(i);
    }
}

template<class T>
void DList<T>::pushFront(const T & i) {
    size++;
    first = new Nodo(i, nullptr, first);
    if (first->next != nullptr) {
        first->next->prev = first;
    } else {
        last = first;
    }
}

template <class T>
void DList<T>::push(const T & i, const uint pos) {
    if (pos >= size) {
        pushBack(i);
    } else if (pos == 0) {
        pushFront(i);
    } else {
        size++;
        Nodo * temp = first;
        for (uint i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        temp->next = new Nodo(i, temp, temp->next);
        temp->next->next->prev = temp->next;
    }
}

template<class T>
T DList<T>::popBack() {
    if (isEmpty()) {
        throw std::out_of_range("Impossibile fare popBack su una lista vuota!");
    }
    T temp = last->info;
    if (size == 1) {
        delete first;
        first = last = nullptr;
    } else {
        last = last->prev;
        delete last->next;
        last->next = nullptr;
    }
    size--;
    return temp;
}

template<class T>
T DList<T>::popFront() {
    if (isEmpty()) {
        throw std::out_of_range("Impossibile fare popFront su una lista vuota!");
    }
    T temp = first->info;
    if (size == 1) {
        delete first;
        first = last = nullptr;
    } else {
        first = first->next;
        delete first->prev;
        first->prev = nullptr;
    }
    size--;
    return temp;
}

template<class T>
T DList<T>::pop(const uint pos) {
    if (isEmpty()) {
        throw std::out_of_range("Impossibile fare pop su una lista vuota!");
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
        T info = temp->info;
        delete temp;
        return info;
    }
}

template<class T>
void DList<T>::set(const T & i, const uint pos) {
    if (isEmpty() || pos >= size) {
        throw std::out_of_range("Impossibile fare set in una cella su una lista vuota o IndexOutOfBoundError!");
    }
    pop(pos);
    push(i, pos);
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
bool DList<T>::deepCheckEquals(const DList<T> & d) const {
    if (size != d.size) {
        return false;
    }
    Nodo * tempA = first;
    Nodo * tempB = d.first;
    for (uint i = 0; i < size; i++) {
        if (*(tempA->info) != *(tempB->info)) { //confronto gli oggetti puntati e non i puntatori
            return false;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return true;
}

template<class T>
bool DList<T>::deepCheckNotEquals(const DList<T> & d) const {
    return !deepCheckEquals(d);
}

template<class T>
bool DList<T>::operator==(const DList<T> & d) const {
    if (size != d.size) {
        return false;
    }
    Nodo * tempA = first;
    Nodo * tempB = d.first;
    for (uint i = 0; i < size; i++) {
        if (tempA->info != tempB->info) {
            return false;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return true;
}

template<class T>
bool DList<T>::operator!=(const DList<T> & d) const {
    return !(*this == d);
}

template<class T>
T & DList<T>::operator[](const uint pos) const {
    if (isEmpty() || pos >= size) {
        throw std::out_of_range("Impossibile accedere in una cella su una lista vuota o IndexOutOfBoundError!");
    }
    if (pos == size - 1) {
        return last->info;
    } else if (pos == 0) {
        return first->info;
    } else {
        Nodo * temp = first;
        for (uint i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return temp->info;
    }
}

template<class T>
DList<T>::Iterator::Iterator(Nodo * const p, const bool pte) : ptr(p), past_the_end(pte) {}

template<class T>
typename DList<T>::Iterator & DList<T>::Iterator::operator++() {
    if (ptr != nullptr) {
        if (!past_the_end) {
            if (ptr->next != nullptr) {
                ptr = ptr->next;
            } else {
                ptr++;
                past_the_end = true;
            }
        }
    }
    return *this;
}

template<class T>
typename DList<T>::Iterator DList<T>::Iterator::operator++(int) {
    Iterator temp(*this);
    if (ptr != nullptr) {
        if(!past_the_end) {
            if (ptr->next != nullptr) {
                ptr = ptr->next;
            } else {
                ptr++;
                past_the_end = true;
            }
        }
    }
    return temp;
}

template<class T>
typename DList<T>::Iterator & DList<T>::Iterator::operator--() {
    if (ptr != nullptr) {
        if (ptr->prev == nullptr)
            ptr = nullptr;
        else if (!past_the_end) {
            ptr = ptr->prev;
        } else {
            ptr--;
            past_the_end = false;
        }
    }
    return *this;
}

template<class T>
typename DList<T>::Iterator DList<T>::Iterator::operator--(int) {
    Iterator temp(*this);
    if (ptr != nullptr) {
        if (ptr->prev == nullptr) {
              ptr = nullptr;
        } else if (!past_the_end) {
               ptr = ptr->prev;
        } else {
            ptr--;
            past_the_end = false;
        }
    }
    return temp;
}

template<class T>
bool DList<T>::Iterator::operator==(const Iterator & it) const {
    return ptr == it.ptr;
}

template<class T>
bool DList<T>::Iterator::operator!=(const Iterator & it) const {
    return ptr != it.ptr;
}

template<class T>
T & DList<T>::Iterator::operator*() const {
    return ptr->info;
}

template<class T>
T * DList<T>::Iterator::operator->() const {
    return &(ptr->info);
}

template<class T>
typename DList<T>::Iterator DList<T>::begin() const {
    return Iterator(first);
}

template<class T>
typename DList<T>::Iterator DList<T>::end() const {
    if (!last) {
        return Iterator();
    } else {
        return Iterator(last + 1, true);
    }
}

template<class T>
std::ostream & operator<<(std::ostream & os, const DList<T> & d) {
    os << "[" << std::endl << std::endl;
    for (uint i = 0; i < d.getSize(); i++) {
        os << " +---" << std::endl << " | Esercizio numero " << i + 1 << std::endl;
        (d[i])->operator<<(os) << std::endl << std::endl;
    }
    os << "]";
    return os;
}

#endif // DLIST_H
