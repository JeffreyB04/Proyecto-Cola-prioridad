//
// Created by jeffr on 6/9/2022.
//

#include "FileManager.h"

 void FileManager::saveClientes(ClienteManager &listaCliente, const string &fileName) {
    ofstream myFile(fileName);
    writeClientes(myFile, listaCliente);
    myFile.close();
}
ostream &FileManager::writeClientes(ostream &out, const ClienteManager &cliente) {

    char delimitador = ',';
    //for (auto &i : cliente.getClienteBst()) {
        Cliente *clienteptr;
        ClienteManager clienteManager;
        clienteManager.buscarCliente(clienteptr);
        out << clienteptr->getId() << delimitador;
        out << clienteptr->getNombre() << delimitador;
        out << clienteptr->isIngresaNino() << delimitador;
        out << clienteptr->isEmbarazada() << delimitador;
        out << clienteptr->isAdultoMayor() << delimitador;
        out << clienteptr->getCategoria() << delimitador;

        //out << i.getId() << delimitador;
        //out << i.getNombre() << delimitador;
        //out << i.isIngresaNino() << delimitador;
        //out << i.isEmbarazada() << delimitador;
        //out << i.isAdultoMayor() << delimitador;
        //out << i.getCategoria << delimitador;
        out << endl;
   // }
    return out;
}
ClienteManager FileManager::loadClientes(const std::string &filename,ColaPrioridad<Cliente>& queue) {

 //   Cliente cliente;
    Cliente *cliente;
    ClienteManager clienteManager;
    BST<Cliente> clienteBST;

    string id;
    string nombre;
    string ingresaNino;
    string embarazada;
    string adultoMayor;
    string bIngresaNino; //20%
    string bEmbarazada; //25%
    string bAdultoMayor; //35%
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
            cliente=new Cliente();
            if(bIngresaNino=="Yes")
            cliente->setIngresaNino(true);
            else
                cliente->setIngresaNino(false);
            if(bEmbarazada=="Yes")
                cliente->setEmbarazada(true);
            else
               cliente->setEmbarazada(false);
            if(bAdultoMayor=="Yes")
                cliente->setAdultoMayor(true);
            else
                cliente->setAdultoMayor(false);
            iCategoria = stoi(categoria);
            cliente->setId(id);
            cliente->setNombre(nombre);
            cliente->setCategoria(iCategoria);
            clienteManager.ingresarCliente(cliente);
            queue.insertar(cliente);
        }
    }
    return clienteManager;
}
