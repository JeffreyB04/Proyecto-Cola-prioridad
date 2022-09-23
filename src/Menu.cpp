//
// Created by Paul on 22/9/2022.
//
#include "Menu.h"

void Menu::menuPrincipal() {
    string aux;
    int continuar=-1;
    while(continuar != 0)
    {
        system("cls");
        cout<< "____________________________________Bienvenido____________________________________ "<<endl;
        cout<< "1. Encolar todos los clientes "<<endl;
        cout<< "2. Encolar un cliente "<<endl;
        cout<< "3. Atender los siguientes 5 clientes "<<endl;
        cout<< "4. Mostrar el siguiente cliente a ser atendido"<<endl;
        cout<< "5. Simulacion de atencion de clientes"<<endl;
        cout<< "6. Agregar cliente nuevo "<<endl;
        cout<< "0. Salir"<<endl;

        cout<< " Digite una opcion:  "<<endl;

        cin>> aux;

        continuar=stoi(aux);
        switch(continuar){
            case 1:
                encolaTodos();

                break;

            case 2:
                encolaCliente();

                break;

            case 3:

                this->atender5<Cliente>();

                break;

            case 4:
                //atenderSig();
                this->atenderSig<Cliente>();

                break;
            case 5:
                this->simulacionCliente<Cliente>();

                break;
            case 6:
                agregarCliente();

                break;
            default: {
                cout<<"Opcion invalida";

            }
        }
    }
}

void Menu::encolaTodos() {
    queue=new ColaPrioridad<Cliente>();
    CLIENTECSV = R"(..\..\files\Datos-Banco-uno.csv )";
    clienteManager = FileManager::loadClientes(CLIENTECSV,*queue);
}
void Menu::agregarCliente() {
    string nombre,id,aux;
    bool IngrN,embar,adultM;
    int catergoria;
    cout<<"Digite el Nombre"<<endl;
    cin>>nombre;
    cout<<"Digite el Id"<<endl;
    cin>>id;
    cout<<"Ingresa con niño? Si o No"<<endl;
    cin>>aux;
    if(aux=="Si")
        IngrN=true;
    else
        IngrN=false;
    cout<<"Esta embarazada? Si o No" <<endl;
    cin>>aux;
    if(aux=="Si")
        embar=true;
    else
        embar=false;
    cout<<"Es Adulto Mayor? Si o No"<<endl;
    cin>>aux;
    if(aux=="Si")
        adultM=true;
    else
        adultM=false;
    cout<<"Digite Categoria: 1 - 2 - 3"<<endl;
    cin>>aux;
   catergoria=stoi(aux);
    Cliente* per = new Cliente(id, nombre, IngrN,embar,adultM,catergoria);
    this->clienteManager.ingresarCliente(per);
}

template<class T>
void Menu::simulacionCliente() {

    T* elemento = nullptr;
    while (!queue->isEmpty()) {
        elemento = queue->remove();
        cout << *elemento << endl;
        delete elemento;
    }


}
template<class T>
void Menu::atenderSig() {
    int contador=1;

    T* elemento = nullptr;
    while (contador!=0) {
        elemento = queue->remove();
        cout << *elemento << endl;
        delete elemento;
        contador--;
    }
}
template<class T>
void Menu::atender5() {
int contador=5;

    T* elemento = nullptr;
    while (contador!=0) {
        elemento = queue->remove();
        cout << *elemento << endl;
        delete elemento;
        contador--;
    }

}
void Menu::encolaCliente() {
    string nombre,id,aux;
    bool IngrN,embar,adultM;
    int catergoria;
    cout<<"Digite el Nombre"<<endl;
    cin>>nombre;
    cout<<"Digite el Id"<<endl;
    cin>>id;
    cout<<"Ingresa con niño? Si o No"<<endl;
    cin>>aux;
    if(aux=="Si")
        IngrN=true;
    else
        IngrN=false;
    cout<<"Esta embarazada? Si o No" <<endl;
    cin>>aux;
    if(aux=="Si")
        embar=true;
    else
        embar=false;
    cout<<"Es Adulto Mayor? Si o No"<<endl;
    cin>>aux;
    if(aux=="Si")
        adultM=true;
    else
        adultM=false;
    cout<<"Digite Categoria: 1 - 2 - 3"<<endl;
    cin>>aux;
    catergoria=stoi(aux);
    Cliente* per = new Cliente(id, nombre, IngrN,embar,adultM,catergoria);
    this->clienteManager.ingresarCliente(per);
    queue=new ColaPrioridad<Cliente>();
    queue->insertar(per);
}


Menu::Menu() {
    queue=new ColaPrioridad<Cliente>();
}
Menu::~Menu() {
    delete queue;
}