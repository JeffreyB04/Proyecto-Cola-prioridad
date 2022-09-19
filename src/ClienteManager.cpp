//
// Created by jeffr on 17/9/2022.
//

#include "ClienteManager.h"
#include "BST.cpp"

ClienteManager::ClienteManager() {}

ClienteManager::~ClienteManager() {

}

const BST<Cliente> &ClienteManager::getClienteBst() const {
    return clienteBST;
}

void ClienteManager::setClienteBst(const BST<Cliente> &clienteBst) {
    clienteBST = clienteBst;
}

void ClienteManager::ingresarCliente(Cliente *cliente) {
    clienteBST.insertV(cliente);
}

void ClienteManager::mostrarClientes() {
    clienteBST.display();
}

void ClienteManager::buscarCliente(Cliente *cliente) {
    clienteBST.search(cliente);
}
