#include <iostream>
using namespace std;
int main() {
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
    return 0;
}
