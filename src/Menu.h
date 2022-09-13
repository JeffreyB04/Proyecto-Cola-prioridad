//
// Created by jeffr on 13/9/2022.
//

#ifndef PROYECTODATOS_MENU_H
#define PROYECTODATOS_MENU_H

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




#endif //PROYECTODATOS_MENU_H
