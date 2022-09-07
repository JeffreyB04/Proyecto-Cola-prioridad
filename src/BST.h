//
// Created by jeffr on 3/9/2022.
//

#ifndef BST_BST_H
#define BST_BST_H
#include "Nodo.cpp"

class BST {
private:
    Nodo* root;

    Nodo* makeEmpty(Nodo* t);
    Nodo* insert(int x, Nodo* t);
    Nodo* findMin(Nodo* t);
    Nodo* findMax(Nodo* t);
    Nodo* remove(int x, Nodo* t);
    void inOrder(Nodo* t);
    Nodo* find(Nodo* t,int x);

public:
    BST();
    virtual ~BST();
    void insert(int x);
    void remove(int x);
    void display();
    void search(int x);
};


#endif //BST_BST_H
