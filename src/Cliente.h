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
    bool ingresaNino; //20%
    bool embarazada; //25%
    bool adultoMayor; //35%
    int categoria;  //categoria 1 20%, 2 10%, 3 0%
public:
    Cliente();

    Cliente(const string &id, const string &nombre, bool ingresaNino, bool embarazada, bool adultoMayor, int categoria);

    virtual ~Cliente();

    const string &getId() const;

    void setId(const string &id);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    bool isIngresaNino() const;

    void setIngresaNino(bool ingresaNino);

    bool isEmbarazada() const;

    void setEmbarazada(bool embarazada);

    bool isAdultoMayor() const;

    void setAdultoMayor(bool adultoMayor);

    int getCategoria() const;

    void setCategoria(int categoria);

    friend ostream &operator<<(ostream &os, const Cliente &cliente);

    virtual string toString();
    operator int const();
};


#endif //PROYECTODATOS_CLIENTE_H
