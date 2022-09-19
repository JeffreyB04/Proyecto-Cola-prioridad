//
// Created by jeffr on 13/9/2022.
//

#ifndef PROYECTODATOS_VECTORDINAMICO_H
#define PROYECTODATOS_VECTORDINAMICO_H
#include <stdexcept>
#include <string>
#include <climits>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>

template<class T>
class VectorDinamico {
public:
    VectorDinamico();
    VectorDinamico(const VectorDinamico& orig, unsigned inicio, unsigned num);
    VectorDinamico(const VectorDinamico& orig);
    virtual ~VectorDinamico();
    VectorDinamico& operator=(const VectorDinamico<T>& right);
    VectorDinamico(unsigned tam);
    T& operator[](unsigned int pos);
    void insertar(const T& dato, unsigned int pos = UINT_MAX);
    unsigned int tam();
    T eliminar (unsigned long int pos=UINT_MAX);
    void asigna(const T &p, unsigned int pos);
    T& recupera(unsigned int pos);
    int busquedaBin(T& p);
    VectorDinamico& operator<(const VectorDinamico<T>& right);
    void ordenar();
private:
    void aumenta();
    void disminuye();
    unsigned long int taml, tamf;
    T *vec;
};
//Constructor Defecto

template <class T>
VectorDinamico<T>::VectorDinamico() : taml(0), tamf(1) {
    vec = new T[tamf];
}
//Constructor copia parcial

template <class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico& orig, unsigned inicio, unsigned num) {
    if (inicio < 0 || num < 0) {
        throw std::string("No puede ser negativos");
    }
    for (int i = inicio; i < num; i++) {
        vec[i - inicio] = orig.vec[i];
    }
}
//Constructor copia

template <class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico& orig) : tamf(orig.tamf), taml(orig.taml), vec(new T[orig.tamf]) {
    for (int i = 0; i < taml; i++) {
        vec[i] = orig.vec[i];
    }
}
//Destructor

template <class T>
VectorDinamico<T>::~VectorDinamico() {
    if (vec)
        delete []vec;
}
//Constructor tamaño

template <class T>
VectorDinamico<T>::VectorDinamico(unsigned tam) {
    if (tam < 0) {
        throw std::string("El tamaño no puede ser negativo");
    }
    float a;
    a = ceil(log2(tam));
    tamf = pow(2, a);
    taml = 0;
    vec = new T[this->tamf];
}

template <class T>
VectorDinamico<T>& VectorDinamico<T>::operator=(const VectorDinamico& right) {
    if (right != this) {
        taml = right.taml;
        delete[] vec;
        vec = new T[taml];
        for (int i = 0; i < taml; i++) {
            vec[i] = right.vec[i];

        }
    }
    return *this;
}

template <class T>
T& VectorDinamico<T>::operator[](unsigned int pos) {
    if (pos < 0 || pos > taml) throw std::string("La posicion es erronea");

    return vec[pos];
}

template <class T>
void VectorDinamico<T>::insertar(const T& dato, unsigned int pos) {
    if (pos < 0) {
        throw std::string("La posicion es erronea");
    }
    if (taml == tamf) {
        T *aux;
        aux = new T[tamf = tamf * 2];
        for (int i = 0; i < taml; i++) {
            aux[i] = vec[i];
        }
        delete []vec;
        vec = aux;
    }


    if (pos == UINT_MAX) {
        vec[taml++] = dato;
    } else {
        if (pos != taml) {
            taml++;
            for (int i = taml - i; i >= pos; i--) {
                vec[i + i] = vec[i];
            }
            vec[pos] = dato;
        } else {
            vec[taml++] = dato;
        }
    }
}

template<class T>
void VectorDinamico<T>::aumenta(){
    T *vaux;
    vaux= new T[tamf=tamf*2];
    for(unsigned i=0;i<taml;i++)
        vaux[i]=vec[i];
    delete []vec;
    vec=vaux;
};

template<class T>
void VectorDinamico<T>::disminuye(){
    tamf=tamf/2;
    T *vaux = new T[tamf];
    for(unsigned i=0;i<taml;i++){
        vaux[i]=vec[i];
    };
    delete []vec;
    vec=vaux;
};

template<class T>
T VectorDinamico<T>::eliminar (unsigned long int pos){
    T aux;
    if (taml==0)
        throw std::out_of_range("Error taml=0");
    if (pos==UINT_MAX){
        if(taml*3<tamf) {
            disminuye();
        };
        aux=vec[taml-1];
    }else{
        if (pos>=taml)
            throw std::out_of_range("Error poscion mayor igual a taml");
        if(taml*3<tamf) {
            disminuye();
        };
        aux=vec[pos];
        for(unsigned i=pos;i<taml-1;i++){
            vec[i]=vec[i+1];
        }
    }
    taml--;
    return aux;
};

template <class T>
unsigned int VectorDinamico<T>::tam() {
    return taml;

}
//La busqueda binaria para el nombre del Cliente una vez ya ordenado el vector

template <class T>
int VectorDinamico<T>::busquedaBin(T& p) {
    int inf = 0;
    int sup = taml - 1;
    int curIn;
    while (inf <= sup) {
        curIn = (inf + sup) / 2;
        if (vec[curIn] == p)
            return curIn;
        else if (vec[curIn] < p) inf = curIn + 1;
        else sup = curIn - 1;
    }
    return -1;
}

template <class T>
void VectorDinamico<T>::asigna(const T &p, unsigned int pos) {
    if (pos > taml) throw std::out_of_range("Posicion no valida");
    vec[pos] = p;

}

template <class T>
void VectorDinamico<T>::ordenar() {
    std::sort(vec, vec + taml);
}



#endif //PROYECTODATOS_VECTORDINAMICO_H
