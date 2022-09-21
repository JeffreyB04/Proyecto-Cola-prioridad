//
// Created by jeffr on 29/8/2022.
//

#ifndef ARBOLBINARIOVINCULADO_NODO_H
#define ARBOLBINARIOVINCULADO_NODO_H
#include<iostream>
using namespace std;

template<class T>
class Nodo {
private:
    T *dato;
    Nodo *parent;
    Nodo *left;
    Nodo *right;
public:
    Nodo(T *dato = nullptr, Nodo *parent = nullptr, Nodo *left = nullptr, Nodo *right = nullptr);

    virtual ~Nodo();

    T *getDato() const;

    void setDato(T *dato);

    Nodo *getParent() const;

    void setParent(Nodo *parent);

    Nodo *getLeft() const;

    void setLeft(Nodo *left);

    Nodo *getRight() const;

    void setRight(Nodo *right);
};

#endif //ARBOLBINARIOVINCULADO_NODO_H