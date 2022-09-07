//
// Created by jeffr on 29/8/2022.
//

#include "Nodo.h"

template<class T>
Nodo<T>::Nodo(T *dato, Nodo *parent, Nodo *left, Nodo *right):dato(dato), parent(parent), left(left), right(right) {}

template<class T>
Nodo<T>::~Nodo() {

}

template<class T>
T *Nodo<T>::getDato() const {
    return dato;
}

template<class T>
void Nodo<T>::setDato(T *dato) {
    Nodo::dato = dato;
}

template<class T>
Nodo *Nodo<T>::getParent() const {
    return parent;
}

template<class T>
void Nodo<T>::setParent(Nodo *parent) {
    Nodo::parent = parent;
}

template<class T>
Nodo *Nodo<T>::getLeft() const {
    return left;
}

template<class T>
void Nodo<T>::setLeft(Nodo *left) {
    Nodo::left = left;
}

template<class T>
Nodo *Nodo<T>::getRight() const {
    return right;
}

template<class T>
void Nodo<T>::setRight(Nodo *right) {
    Nodo::right = right;
}
