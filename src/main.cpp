#include <iostream>
#include "Menu.h"

using namespace std;
int main() {
  /*  char opc = 's';
    char continuar = 's';
    while(continuar != '0')
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

        cout<< "\n Digite una opcion:  "<<endl;
        cin>> continuar;

        switch(continuar){
            //ingreso a inventario
            case '1':
                cin>>opc;
                if(opc=='1'){

                }
                if(opc=='2'){

                }
                break;

            case '2':

                break;

            case '3':

                break;

            case '4':

               break;
            default: {

            }
        }
    }

/*
 *
 * Menu<float> *m = new Menu<float>;
 * m->menuPrincipal();
 * delete m;
 * return 0;
 */


    Cliente* per = new Cliente("David", "123", true,true,true,2);
    cout << per->getNombre()<< endl;
    cout << per->getCategoria() << endl;
    cout<< per->isIngresaNino()<<endl;
    cout<<per->isEmbarazada()<<endl;
    cout<<per->isAdultoMayor()<<endl;
    cout<<per->getId()<<endl;
    ClienteManager clien;
    clien.ingresarCliente(per);
    ColaPrioridad<Cliente>* colita = new ColaPrioridad<Cliente>();
    colita->insertar(per);



    Cliente* per2 = new Cliente("Juan", "123", true,true,true,2);
    cout << per2->getNombre()<< endl;
    cout << per2->getCategoria() << endl;
    cout<< per2->isIngresaNino()<<endl;
    cout<<per2->isEmbarazada()<<endl;
    cout<<per2->isAdultoMayor()<<endl;
    cout<<per2->getId()<<endl;


    clien.ingresarCliente(per2);
    colita->insertar(per2);
    cout << "-----------------------" << endl;




    return 0;
}