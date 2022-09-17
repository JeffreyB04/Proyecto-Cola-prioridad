//
// Created by jeffr on 3/9/2022.
//

#include "BST.h"
template<class T>
BST<T>::BST() {
    root = nullptr;
}
template<class T>
BST<T>::~BST() {
    root = makeEmpty(root);
}
template<class T>
Nodo<T> *BST<T>::makeEmpty(Nodo<T> *t) {//duda en Nodo<T> *BST<T>
    if (t == nullptr)
        return nullptr;
    {
        makeEmpty(t->getLeft());
        makeEmpty(t->getRight());
        delete t;
    }
    return nullptr;
}
template<class T>
Nodo<T> *BST<T>::insert(T *valor, Nodo<T> *t) {
    if (t == nullptr) {
        t = new Nodo<T>(*valor);  //duda con parentesis no se si lleva *
    } else if (*valor < t->getElemento())
        t->setLeft(insert(*valor, t->getLeft()));
    else if (*valor < t->getElemento())
        t->setRight(insert(*valor, t->getRight()));
    return t;
}
template<class T>
Nodo<T> *BST<T>::findMin(Nodo<T> *t) {
    if (t == nullptr)
        return nullptr;
    else if (t->getLeft() == nullptr)
        return t;
    else
        return findMin(t->getLeft());
}
template<class T>
Nodo<T> *BST<T>::findMax(Nodo<T> *t) {
    if (t == nullptr)
        return nullptr;
    else if (t->getRight() == nullptr)
        return t;
    else
        return findMax(t->getRight());
}
template<class T>
Nodo<T> *BST<T>::remove(T *valor, Nodo<T> *t) {
    Nodo<T> *temp;
    if (t == nullptr) {
        return nullptr;
    } else if (valor < t->getElemento()) {
        t->setLeft(remove(valor, t->getLeft()));
    } else if (valor > t->getElemento()) {
        t->setRight(remove(valor, t->getRight()));
    } else if (t->getLeft() && t->getRight()) {
        temp = findMin(t->getRight());
        t->setElemento(temp->getElemento());
        t->setRight(remove(t->getElemento(), t->getRight()));
    } else {
        temp = t;
        if (t->getLeft() == nullptr)
            t = t->getRight();
        else if (t->getRight() == nullptr)
            t = t->getLeft();
        delete temp;
    }
    return t;
}
template<class T>
void BST<T>::inOrder(Nodo<T> *t) {
    if (t == nullptr)
        return;
    inOrder(t->getLeft());
    cout << t->getElemento() << " ";
    inOrder(t->getRight());
}
template<class T>
Nodo<T> *BST<T>::find(Nodo<T> *t, T *valor) {
    if (t == nullptr)
        return nullptr;
    else if (valor < t->getElemento())
        return find(t->getLeft(), valor);
    else if (valor > t->getElemento())
        return find(t->getRight(), valor);
}
template<class T>
void BST<T>::insert(T *valor) {
    root = insert(valor, root);
}
template<class T>
void BST<T>::remove(T *valor) {
    root = remove(valor, root);
}
template<class T>
void BST<T>::display() {
    inOrder(root);
    cout << endl;
}
template<class T>
void BST<T>::search(T *valor) {
    root = find(root, valor);
}
