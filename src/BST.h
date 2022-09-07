//
// Created by jeffr on 3/9/2022.
//

#ifndef BST_BST_H
#define BST_BST_H
#include "Nodo.cpp"
template<class T>
class BST {
private:
    Nodo<T>* root;

    Nodo<T>* makeEmpty(Nodo<T>* t);
    Nodo<T>* insert(T *valor, Nodo<T>* t);
    Nodo<T>* findMin(Nodo<T>* t);
    Nodo<T>* findMax(Nodo<T>* t);
    Nodo<T>* remove(T *valor, Nodo<T>* t); //en (T )
    void inOrder(Nodo<T>* t);
    Nodo<T>* find(Nodo<T>* t,T *valor);

public:
    BST();
    virtual ~BST();
    void insert(T *valor);
    void remove(T *valor); //tenia (int x)
    void display();
    void search(T *valor);
};


#endif //BST_BST_H
