//
// Created by jeffr on 6/9/2022.
//

#include "Cliente.h"
Cliente::Cliente() {}

Cliente::Cliente(const string &id, const string &nombre) : id(id), nombre(nombre) {}

Cliente::~Cliente() {

}

const string &Cliente::getId() const {
    return id;
}

void Cliente::setId(const string &id) {
    Cliente::id = id;
}

const string &Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const string &nombre) {
    Cliente::nombre = nombre;
}


ostream &operator<<(ostream &os, const Cliente &cliente) {
    os << "id: " << cliente.id << " nombre: " << cliente.nombre;
    return os;
    /*
      << " Online: ";
    if (cliente.online)
        os << "Si";
    else
        os << "No";
    return os;
}
     */
}

string Cliente::toString() {
    stringstream ss;
    ss << (*this);
    return ss.str();
}
