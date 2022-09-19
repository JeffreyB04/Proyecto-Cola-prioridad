//
// Created by jeffr on 6/9/2022.
//

#include "FileManager.h"

 void FileManager::saveClientes(ClienteManager &listaVehiculo, const string &fileName) {
    ofstream myFile(fileName);
    writeClientes(myFile, listaVehiculo);
    myFile.close();
}
ostream &FileManager::writeClientes(ostream &out, const ClienteManager &cliente) {

    char delimitador = ',';
    //for (auto &i : cliente.getClienteBst()) {
        ClienteManager clienteManager;
        BST<Cliente> clienteBST;
        clienteManager.getClienteBst();
        clienteBST.search(cliente);
        out << i.getId() << delimitador;
        out << i.getNombre() << delimitador;
        out << i.isIngresaNino() << delimitador;
        out << i.isEmbarazada() << delimitador;
        out << i.isAdultoMayor() << delimitador;
        out << i.getCategoria << delimitador;
        out << endl;
   // }
    return out;
}
ClienteManager FileManager::loadClientes(const std::string &filename) {

 //   Cliente cliente;
    Cliente *cliente;
    ClienteManager clienteManager;
    BST<Cliente> clienteBST;

    string id;
    string nombre;
    string ingresaNino;
    string embarazada;
    string adultoMayor;
    bool bIngresaNino; //20%
    bool bEmbarazada; //25%
    bool bAdultoMayor; //35%
    string categoria;
    int iCategoria;  //categoria 1 20%, 2 10%, 3 0%

    char delimitador = ',';
    std::ifstream in(filename, std::ios::in | ios::binary);

    while(in.good()) {
        getline(in, id, delimitador);
        getline(in, nombre, delimitador);
        getline(in, ingresaNino, delimitador);
        getline(in, embarazada, delimitador);
        getline(in, adultoMayor, delimitador);
        getline(in, categoria, '\n');

        if(!id.empty()){
            bIngresaNino = stoi(ingresaNino);
            bEmbarazada = stoi(embarazada);
            bAdultoMayor = stoi(adultoMayor);
            iCategoria = stoi(categoria);
            cliente->setId(id);
            cliente->setNombre(nombre);
            cliente->setCategoria(iCategoria);
            clienteManager.ingresarCliente(cliente);
        }
    }
    return clienteManager;
}
