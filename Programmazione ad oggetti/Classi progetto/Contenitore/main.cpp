#include <iostream>
using namespace std;

template <class T>
class Nodo {
public:
    T info;
    Nodo * next;

    Nodo(const T & i, const Nodo * n = 0) : info(i), next(n) {}
    Nodo(const Nodo & o) {

    }
    ~Nodo() {
        delete next;
    }
};

template <class T>
class Contenitore {
private:
    int size;
    Nodo<T> * lista;

public:
    Contenitore(Nodo<T> * l = 0, int s = 0) : lista(l), size(s) {}
    Contenitore(const Contenitore & o) {}
    ~Contenitore() {}

    void push(Nodo<T> * elem, int indice) {
        if (indice > size) {
            //inserimento alla coda
        } else if (indice <= 0) {
            //inserimento in cima
        } else {
            //inserimento in posizione 0 <= indice <= size
        }
        size++;
    }

    Nodo<T> * pop(int indice) {
        Nodo<T> * temp = lista;
        if (indice > size) {
            //rimozione dalla coda
        } else if (indice <= 0) {
            //rimozione dalla cima
            lista = lista->next;
        } else {
            //rimozione dalla posizione 0 <= indice <= size
        }
        size--;
        return temp;
    }

    Nodo<T> * getElem(int indice) {
        if (indice <= size) {
            Nodo<T> * temp = lista;
            for (int i = 0; i < size; ++i) {
                temp = temp->next;
            }
            return temp;
        }
    }
};

int main() {

}
