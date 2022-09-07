//
// Created by jeffr on 6/9/2022.
//

#ifndef PROYECTODATOS_CLIENTE_H
#define PROYECTODATOS_CLIENTE_H

#include <iostream>
#include <sstream>
using namespace std;
class Cliente {
private:
    string id;
    string nombre;
public:
    Cliente();

    Cliente(const string &id, const string &nombre);

    virtual ~Cliente();

    const string &getId() const;

    void setId(const string &id);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getNumTarjeta() const;

    void setNumTarjeta(const string &numTarjeta);

    friend ostream &operator<<(ostream &os, const Cliente &cliente);

    virtual string toString();
};


#endif //PROYECTODATOS_CLIENTE_H
