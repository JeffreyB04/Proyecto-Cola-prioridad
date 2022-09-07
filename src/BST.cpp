//
// Created by jeffr on 3/9/2022.
//

#include "BST.h"

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    root = makeEmpty(root);
}

Nodo *BST::makeEmpty(Nodo *t) {
    if (t == nullptr)
        return nullptr;
    {
        makeEmpty(t->getLeft());
        makeEmpty(t->getRight());
        delete t;
    }
    return nullptr;
}

Nodo *BST::insert(int x, Nodo *t) {
    if (t == nullptr) {
        t = new Nodo(x);
    } else if (x < t->getElemento())
        t->setLeft(insert(x, t->getLeft()));
    else if (x < t->getElemento())
        t->setRight(insert(x, t->getRight()));
    return t;
}

Nodo *BST::findMin(Nodo *t) {
    if (t == nullptr)
        return nullptr;
    else if (t->getLeft() == nullptr)
        return t;
    else
        return findMin(t->getLeft());
}

Nodo *BST::findMax(Nodo *t) {
    if (t == nullptr)
        return nullptr;
    else if (t->getRight() == nullptr)
        return t;
    else
        return findMax(t->getRight());
}

Nodo *BST::remove(int x, Nodo *t) {
    Nodo *temp;
    if (t == nullptr) {
        return nullptr;
    } else if (x < t->getElemento()) {
        t->setLeft(remove(x, t->getLeft()));
    } else if (x > t->getElemento()) {
        t->setRight(remove(x, t->getRight()));
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

void BST::inOrder(Nodo *t) {
    if (t == nullptr)
        return;
    inOrder(t->getLeft());
    cout << t->getElemento() << " ";
    inOrder(t->getRight());
}

Nodo *BST::find(Nodo *t, int x) {
    if (t == nullptr)
        return nullptr;
    else if (x < t->getElemento())
        return find(t->getLeft(), x);
    else if (x > t->getElemento())
        return find(t->getRight(), x);
}

void BST::insert(int x) {
    root = insert(x, root);
}

void BST::remove(int x) {
    root = remove(x, root);
}

void BST::display() {
    inOrder(root);
    cout << endl;
}

void BST::search(int x) {
    root = find(root, x);
}
