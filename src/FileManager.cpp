//
// Created by jeffr on 6/9/2022.
//

#include "FileManager.h"
/*
 void FileManager::saveClientes(ClienteManager &listaClientes, const string &fileName) {
    ofstream myFile(fileName);
    writeClientes(myFile, listaClientes);
    myFile.close();
}

 ostream &FileManager::writeClientes(ostream &out, const ClienteManager &cliente) {
    char delimitador = ';';
    for (auto &i: cliente.getClienteList()) {
        out << i->getNombre() << delimitador;
        out << i->getCedula() << delimitador;
        out << i->getCorreoElec() << delimitador;
        out << i->getCodigoPais() << delimitador;
        out << i->isOnline() << delimitador;
        out << i->getPagoSuscrib() << delimitador;
        out << endl;
    }
    return out;
}

 ClienteManager FileManager::loadClientes(const string &filename) {
    ClienteManager clienteManager;
    Cliente *cliente = nullptr;
    string nombre;
    string cedula;
    string correoElec;
    string pais;
    string online;
    int bOnline;
    string pago;
    int pagoSuscrib;
    char delimitador = ';';
    int codigoPais;

    ifstream in(filename, ios::in);
    if (!in.is_open()) {
        throw invalid_argument("Could not open file [" + filename + "]");
    }

    while (in.good()) {
        getline(in, nombre, delimitador);
        getline(in, cedula, delimitador);
        getline(in, correoElec, delimitador);
        getline(in, pais, delimitador);
        getline(in, online, delimitador);
        getline(in, pago, '\n');
        if (!nombre.empty()) {
            cliente = new Cliente();
            cliente->setNombre(nombre);
            cliente->setCedula(cedula);
            cliente->setCorreoElec(correoElec);
            codigoPais = stoi(pais);
            cliente->setCodigoPais(codigoPais);
            bOnline = stoi(online);
            cliente->setOnline(bOnline);
            pagoSuscrib = stoi(pago);
            cliente->setPagoSuscrib(pagoSuscrib);
        }
        clienteManager.ingresarCliente(cliente);
    }
    return clienteManager;
}

 */