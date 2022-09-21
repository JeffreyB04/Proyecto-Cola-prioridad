#pragma once
#include<iostream>
using namespace std;
template <class T>
class NodoPrioridad {
private:
	NodoPrioridad<T>* anterior;
	NodoPrioridad<T>* siguinte;
	T* objetoPtr;
public:
	NodoPrioridad(T*, NodoPrioridad<T>*,NodoPrioridad<T>*);
	virtual ~NodoPrioridad();
	T* getObjetoPtr();
	NodoPrioridad<T>* getSiguiente();
	NodoPrioridad<T>* getAnterior();
	void setAnterior(NodoPrioridad<T>*);
	void setObjetoPtr(T*);
	void setSiguiente(NodoPrioridad<T>*);
};


template<class T>
 NodoPrioridad<T>::NodoPrioridad(T* v, NodoPrioridad<T>* n, NodoPrioridad<T>* p)
{
	 this->objetoPtr = v;
	 this->anterior = p;
	 this->siguinte = n;
}

template<class T>
NodoPrioridad<T>::~NodoPrioridad() {
	delete objetoPtr;
}

template<class T>
T* NodoPrioridad<T>::getObjetoPtr() {
	return objetoPtr;
}

template<class T>
NodoPrioridad<T>* NodoPrioridad<T>::getSiguiente() {
	return this->siguinte;
}

template<class T>
 NodoPrioridad<T>* NodoPrioridad<T>::getAnterior()
{
	return anterior;
}

template<class T>
 void NodoPrioridad<T>::setAnterior(NodoPrioridad<T>* an)
{
	 anterior = an;
}

template<class T>
void NodoPrioridad<T>::setObjetoPtr(T* ptr) {
	objetoPtr = ptr;
}

template<class T>
void NodoPrioridad<T>::setSiguiente(NodoPrioridad<T>* nod) {
	this->siguinte = nod;
}

//-----------------------Lista-----------------


template <class T>
class Lista {
private:

	NodoPrioridad<T>* primero;
	NodoPrioridad<T>* actual;
	NodoPrioridad<T>* ultimo;
	int cantidad;
	

public:
	Lista();
	Lista(const Lista<T>& ls);
	virtual ~Lista();
	int getCantidad();
	void limpiaHeap();
	NodoPrioridad<T>* getFront();
	NodoPrioridad<T>* getBack();
	bool empty();
	bool insertar(T*);
	bool eliminar();
	void mostrar();
	T* elemento();
	T* buscarElemento(int);

};

template <class T>
Lista<T>::Lista() {
	primero = nullptr;
	actual = nullptr;
	ultimo = nullptr;
	cantidad = 0;
}


template<class T>
Lista<T>::Lista(const Lista<T>& ls)
{
	int contador = 0;
	T* dato = nullptr;
	NodoPrioridad<T>* aux= ls.primero;
	while (ls.cantidad>=contador)
	{
		dato = new T(*aux->getObjetoPtr());
		this->insertar(dato);
		contador++;
		aux = aux->getSiguiente();
	}
	
}



template <class T>
Lista<T>::~Lista() {
	this->limpiaHeap();
}

template<class T>
int Lista<T>::getCantidad()
{
	return cantidad;
}

template<class T>
void Lista<T>::limpiaHeap() {
	NodoPrioridad<T>* actuall = nullptr;
	while (primero != nullptr)
	{
		actuall = primero;
		cantidad--;
		primero = actuall->getSiguiente(); 
		delete actuall;
	}
}
template<class T>
NodoPrioridad<T>* Lista<T>::getFront()
{
	return primero;
}
template<class T>
 NodoPrioridad<T>* Lista<T>::getBack()
{
	return ultimo;
}
template<class T>
bool Lista<T>::empty()
{
	return primero == nullptr;
}


template<class T>
bool Lista<T>::insertar(T* p)
{
	NodoPrioridad<T>* aux = nullptr;
	actual = primero;

	if (primero == nullptr) {
		this->primero = new NodoPrioridad<T>(p, nullptr, nullptr);
		return true;
	}
	while (actual->getSiguiente()) {
		actual = actual->getSiguiente();
	}
	aux = new NodoPrioridad<T>(p, nullptr, actual);
	this->cantidad++;
	actual->setSiguiente(aux);
	ultimo = aux;
	return true;
	
}

template<class T>
 bool Lista<T>::eliminar()
 {
	 if (!this->empty()) {
		 if (this->getCantidad() == 0) {
			 delete primero;
			 this->primero = nullptr;
			 return true;
		 }
		 NodoPrioridad<T>* aux = nullptr;
		 actual = primero;
		 aux = ultimo->getAnterior();
		 aux->setSiguiente(nullptr);
		 ultimo->setSiguiente(primero->getSiguiente());
		 primero = ultimo;
		 ultimo = aux;
		 aux = actual->getSiguiente();//
		 if (aux == nullptr) {
			 delete actual;
			 cantidad--;
			 return true;
		 }
		 aux->setAnterior(primero);
		 primero->setAnterior(nullptr);
		 delete actual;
		 cantidad--;
		 return  true;
	 }
	 return false;
}


template<class T>
void Lista<T>::mostrar()
{
	actual = primero;
	while (actual) {
		cout << *actual->getObjetoPtr() << endl;
		actual = actual->getSiguiente();
	}
}

template<class T>
 T* Lista<T>::elemento()
{
	return primero->getObjetoPtr();
}

 template<class T>
 T* Lista<T>::buscarElemento(int m)
 {
	 int contador = 0;
	 actual = primero;
	 T* obj = nullptr;
	 while (actual!=nullptr) {
		 if (contador == m) {
			 obj = actual->getObjetoPtr();
			 return obj;
		 }
		 contador++;
		 actual = actual->getSiguiente();
	 }
	 return nullptr;
 }


