//
// Created by jeffr on 13/9/2022.
//

#ifndef PROYECTODATOS_MENU_H
#define PROYECTODATOS_MENU_H
#include<iostream>

using namespace std;
template <class T>
class Menu {
private:
    //aca en el video hay una lista
public:
    Menu();
    void menuPrincipal();
    void opcion1();
    void opcion2();
    void opcion3();
    void opcion4();
    void opcion5();
    void opcion6();
    void opcion0();
    virtual ~Menu();
};
template<class T>
Menu<T>::~Menu<T>(){}

template<class T>
Menu<T>::Menu(){
    //aqui creaba una lista
}

template<class T>
void Menu<T>::menuPrincipal() {
     char opc = 's';
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
                opcion1();
                break;

            case '2':
                opcion2();

                break;

            case '3':
                opcion3();

                break;

            case '4':
                opcion4();

               break;
                           case '5':
                opcion5();

               break;
                           case '6':
                opcion6();

               break;
            default: {
opcion0();
            }
        }
    }
}
    template<class T>
    void Menu<T>::opcion1(){
        //desarrollar
    }
        template<class T>
    void Menu<T>::opcion2(){
        //desarrollar
    }
        template<class T>
    void Menu<T>::opcion3(){
        //desarrollar
    }

        template<class T>
    void Menu<T>::opcion4(){
        //desarrollar
    }

        template<class T>
    void Menu<T>::opcion5(){
        //desarrollar
    }

        template<class T>
    void Menu<T>::opcion6(){
        //desarrollar
    }






#endif //PROYECTODATOS_MENU_H
