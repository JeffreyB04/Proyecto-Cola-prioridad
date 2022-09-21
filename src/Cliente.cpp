//
// Created by jeffr on 6/9/2022.
//

#include "Cliente.h"

Cliente::Cliente() {}

Cliente::Cliente(const string &id, const string &nombre, bool ingresaNino, bool embarazada, bool adultoMayor,
                 int categoria) : id(id), nombre(nombre), ingresaNino(ingresaNino), embarazada(embarazada),
                                  adultoMayor(adultoMayor), categoria(categoria) {}

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

bool Cliente::isIngresaNino() const {
    return ingresaNino;
}

void Cliente::setIngresaNino(bool ingresaNino) {
    Cliente::ingresaNino = ingresaNino;
}

bool Cliente::isEmbarazada() const {
    return embarazada;
}

void Cliente::setEmbarazada(bool embarazada) {
    Cliente::embarazada = embarazada;
}

bool Cliente::isAdultoMayor() const {
    return adultoMayor;
}

void Cliente::setAdultoMayor(bool adultoMayor) {
    Cliente::adultoMayor = adultoMayor;
}

int Cliente::getCategoria() const {
    return categoria;
}

void Cliente::setCategoria(int categoria) {
    Cliente::categoria = categoria;
}

ostream &operator<<(ostream &os, const Cliente &cliente) {
    os << "id: " << cliente.id << " nombre: " << cliente.nombre << " embarazada: ";
    if (cliente.embarazada)
        os << "Yes";
    else
        os << "No";

    os << " IngresaNino: ";
    if (cliente.ingresaNino)
        os << "Yes";
    else
        os << "No";

    os << " adultoMayor: ";
    if (cliente.adultoMayor)
        os << "Yes";
    else
        os << "No";
    os << " categoria: "
       << cliente.categoria;
    return os;
}

string Cliente::toString() {
    stringstream ss;
    ss << (*this);
    return ss.str();
}

Cliente::operator int const() {

    int total=0;
    if(ingresaNino)
        total=total+20;
    if(embarazada)
        total=total+25;
    if(adultoMayor)
        total=total+35;
    switch(categoria){
        case 1: total=total+20;
            break;
        case 2: total=total+10;
            break;
        case 3: total;
            break;
    }
    return total;
}
