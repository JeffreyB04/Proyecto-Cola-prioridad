//
// Created by jeffr on 17/9/2022.
//

#ifndef PROYECTODATOS_CLIENTEMANAGER_H
#define PROYECTODATOS_CLIENTEMANAGER_H
#include "BST.cpp"
#include"Cliente.h"

class ClienteManager {
private:
    BST<Cliente> clienteBST;
public:
    ClienteManager();
    virtual ~ClienteManager();

    const BST<Cliente> &getClienteBst() const;
    void setClienteBst(const BST<Cliente> &clienteBst);

    void ingresarCliente(Cliente& cliente);
    void mostrarClientes();
};


#endif //PROYECTODATOS_CLIENTEMANAGER_H
