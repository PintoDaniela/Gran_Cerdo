#include <iostream>
#include <locale.h>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "rlutil.h"
#include <windows.h>

//mis bibliotecas
/*
#include "visuales.h"
#include "funciones.h"
#include "jugadas.h"
*/
#include "opcion_jugar.h"
using namespace std;


int main(){
    std::setlocale(LC_ALL, "");

    int presentacion, puntaje_estadistica=0;
    string ganador, jugador_estadistica, jugador[2];
    bool mostrar_menu=1;
    char menu, salir='N';

    system("color 5E");

    presentacion=1;
    dibujo_cerdito(presentacion);
    rlutil::locate(2,24);
    cout << "Presione una tecla para continuar... " << endl;
    rlutil::anykey();
    rlutil::cls();

    ///////////////// Menu /////////////////
    ir_a_menu(mostrar_menu);
    cin >> menu;
    rlutil::cls();

    while(salir!='S'){
        switch(menu){
        case '1':{
           jugar(puntaje_estadistica, jugador_estadistica, jugador, ganador);
        }
        break;

        case '2':
            estadisticas(puntaje_estadistica, jugador_estadistica, jugador, ganador);
            rlutil::cls();

        break;

        case '3':
            creditos (menu);
            rlutil::cls();
        break;

        case '0':
            desea_salir(salir);
            while(salir!='S' && salir!='N'){
                    rlutil::cls();
                    desea_salir(salir);
            }
            rlutil::cls();
        break;
        }//fin switch menu

        if(salir!='S'){
            ir_a_menu(mostrar_menu);
            cin >> menu;
            rlutil::cls();
        }
    }//Fin while grande.
    rlutil::locate(22,15);
    cout << "¡ADIOINK!";
    rlutil::locate(2,24);

    return 0;
}
