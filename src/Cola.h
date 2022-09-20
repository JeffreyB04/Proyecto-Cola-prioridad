//
// Created by Paul on 20/9/2022.
//

#ifndef PROYECTODATOS_COLA_H
#define PROYECTODATOS_COLA_H
using namespace std;
#include "VectorDinamico.h"
template<class C>
class Cola: public VectorDinamico<C>{
private:
    int *arr;
    int cantidad;
public:
    Cola(int tamano);
    ~Cola();
    void encolar(const C& c);
    void descolar();
    const C& frente();
    int tamano()const;
    bool colaVacia()const;

};



template<class C>
Cola<C>::Cola(int tamano){
 arr=new C[tamano];
 cantidad=0;

};

template<class C>
Cola<C>::~Cola(){
    delete[]arr;
}

template<class C>
void Cola<C>::encolar(const C &c) {
    arr[++cantidad]=c;
}

template<class C>
void Cola<C>::descolar() {

    if(colaVacia()){
        cout<<"Cola vacia";
        exit(EXIT_FAILURE);
    } else{
        for(int i=0;i<cantidad;i++){
            arr[i]=arr[i+1];
        }
        --cantidad;
    }
}

template<class C>
const C& Cola<C>::frente(){
if(!colaVacia())
    return arr[0];
else
    cout<<"Frente a una cola Vacia";

}

template<class C>
int Cola<C>::tamano() const{
    return cantidad +1;
}

template<class C>
bool Cola<C>::colaVacia() const {
    return cantidad==-1;
}





#endif //PROYECTODATOS_COLA_H
