#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <string>
#include "rlutil.h"
#include<stdlib.h>
#include <ctime>

using namespace std;


///Lanzamiento de dados
void lanzamiento_dados(int cant, int caras, int vec[]){

    srand(time(0));
    for(int i=0; i<cant; i++){
      vec[i]= 1+(rand()%caras);
    }

    return;
}
///Texto que s emuestra cuando se define quien empieza a jugar:
void texto_definicion_jugadores(std::string nombre[2], int i){
    rlutil::locate(2,2);
    cout << "GRAN CERDO |" << endl;
    rlutil::locate(2,4);
    cout << "****************************************************************" << endl;
    rlutil::locate(2,6);
    cout << "Ambos jugadores deben tirar un dado para definir quién comienza." << endl;
    rlutil::locate(2,8);
    cout << "****************************************************************" << endl;
    rlutil::locate(10,11);
    cout << nombre[i] << ", presiona una tecla para lanzar tus dados." << endl;

    return;
}


///Ingreso de nombres y definición de Quién empieza:

//declaracion de funciones involucradas:
void texto_definicion_jugadores(std::string nombre[2], int i);
void lanzamiento_dados(int cant, int caras, int vec[]);
void dibujar_dados (int dado, int posicion);
void marco_jugadores(void);


void quien_empieza(int resultado_lanzamiento[3], std::string jugador[2], std::string nombre[2]){

    int max_dado, max_dado_jugador[2]={}, resultado_inicio[2]={};//variables locales.


    marco_jugadores();
            cin.ignore();
            for(int i=0;i<2;i++){
                rlutil::locate(20,i*3+7);
                cout << "Nombre del jugador "<< i+1 <<": ";
                getline(cin, nombre[i]);
            }
    rlutil::cls();

    while(resultado_inicio[0]== resultado_inicio[1]&& max_dado_jugador[0]== max_dado_jugador[1]){
        for(int i=0;i<2;i++){
            max_dado=0;

            texto_definicion_jugadores(nombre,  i);
            rlutil::anykey();
            lanzamiento_dados(2, 6, resultado_lanzamiento);
            for(int j=0; j<2; j++){
                std::setlocale(LC_ALL, "C");
                dibujar_dados(resultado_lanzamiento[j], j);
                std::setlocale(LC_ALL, "");
                resultado_inicio[i]+=resultado_lanzamiento[j];
                if(resultado_lanzamiento[j]>max_dado){
                    max_dado=resultado_lanzamiento[j];
                }
            }
            max_dado_jugador[i]=max_dado;
            rlutil::anykey();
            rlutil::cls();
        }
    }

    if(resultado_inicio[0] > resultado_inicio[1] || (resultado_inicio[0] == resultado_inicio[1] && max_dado_jugador[0] > max_dado_jugador[1])){
        jugador[0]=nombre[0];
        jugador[1]=nombre[1];
    }else{
        jugador[0]=nombre[1];
        jugador[1]=nombre[0];
    }

    marco_jugadores();
    for(int i=0;i<2;i++){
        rlutil::locate(25,i*3+7);
        cout << "JUGADOR " <<  i+1 << ": " << jugador[i]<< endl;
    }

    rlutil::locate(2,24);
    cout << "Presione una tecla para continuar... " << endl;
    rlutil::anykey();
}


///Datos de cada ronda (nombres, trufas, numero de ronda, num de lanzamiento)
void datos_ronda(std::string jugador[2], int acu_trufas[2], int cont_lanzamiento, int trufas_ronda, int x, int y){

    setlocale(LC_ALL, "");
    rlutil::cls();
    rlutil::locate(2,2);
    cout << "GRAN CERDO |   TRUFAS ACUMULADAS "<< jugador[0]<<": "<<acu_trufas[0]<<"  -  TRUFAS ACUMULADAS "<< jugador[1]<<": " <<acu_trufas[1]<< endl;
    rlutil::locate(2,4);
    cout << "************************************ Ronda " << x+1 << " ************************************" << endl;
    rlutil::locate(10,6);
    cout << "ES EL TURNO DE " << jugador[y] << endl;
    rlutil::locate(10,7);
    cout << "+------------------------------------------------------+" << endl;

    rlutil::locate(10,8);
    cout << "|";
    rlutil::locate(66,8);
    cout << "|";
    rlutil::locate(10,9);
    cout << "| LANZAMIENTO # " << cont_lanzamiento << endl;
    rlutil::locate(66,9);
    cout << "|";
    rlutil::locate(10,10);
    cout << "| TRUFAS DE LA RONDA ACTUAL: " << trufas_ronda  << endl;
    rlutil::locate(66,10);
    cout << "|";
    rlutil::locate(10,11);
    cout << "|";
    rlutil::locate(66,11);
    cout << "|";
    rlutil::locate(10,12);
    cout << "+------------------------------------------------------+" << endl;

    return;

 }





///datos para la tabla de puntajes
void datos_PDV(int max_trufas[2], int cada_50_trufas[2], int cada_oink[2], int acu_trufas[2], int cont_oink[2], int cant_max_lanzamientos[2], int mas_codicioso[2], int mat_lanzamientos[2][5], int total[2], int cerdo_primo[2]){

    //Más trufas en total:
    if(acu_trufas[0]>acu_trufas[1]){
        max_trufas[0]=5;
        max_trufas[1]=0;
    }else if(acu_trufas[0]<acu_trufas[1]){
        max_trufas[0]=0;
        max_trufas[1]=5;
    }else{
        max_trufas[0]=5;
        max_trufas[1]=5;
    }
    //Cada 50 trufas:
    cada_50_trufas[0]=acu_trufas[0]/50;
    cada_50_trufas[1]=acu_trufas[1]/50;

    //cada un oink:
    cada_oink[0]= cont_oink[0]*2;
    cada_oink[1]= cont_oink[1]*2;

    //más codicioso:
    for(int y=0; y<2; y++){
        for(int x=0; x<5; x++){
            if (mat_lanzamientos[y][x]>cant_max_lanzamientos[y]){
               cant_max_lanzamientos[y]=mat_lanzamientos[y][x];
            }
        }
    }
    if(cant_max_lanzamientos[0]==cant_max_lanzamientos[1]){
        mas_codicioso[0]=2;
        mas_codicioso[1]=2;
    }else if(cant_max_lanzamientos[0]>cant_max_lanzamientos[1]){
        mas_codicioso[0]=2;
    }else{
        mas_codicioso[1]=2;
    }
    total[0] = mas_codicioso[0]+cada_oink[0]+cada_50_trufas[0]+max_trufas[0]+cerdo_primo[0];
    total[1] = mas_codicioso[1]+cada_oink[1]+cada_50_trufas[1]+max_trufas[1]+cerdo_primo[1];

return;
}

void tabla_puntajes(std::string jugador[2], int acu_trufas[2], int max_trufas[2],int cada_50_trufas[2], int cada_oink[2], int mas_codicioso[2],int total[2], int cant_max_lanzamientos[2], int cont_oink[2], int cerdo_primo[2]){

    rlutil::locate(2,2);
    cout << "GRAN CERDO "<< endl;
    rlutil::locate(2,4);
    cout << "************************************************************" << endl;
    rlutil::locate(2,5);
    cout << "|";
    rlutil::locate(7,5);
    cout << "HITO";
    rlutil::locate(30,5);
    cout << jugador[0];
    rlutil::locate(45,5);
    cout << jugador[1];
    rlutil::locate(60,5);
    cout << "|";

    rlutil::locate(2,6);
    cout << "|";
    rlutil::locate(60,6);
    cout << "|";

    rlutil::locate(2,7);
    cout << "|";
    rlutil::locate(7,7);
    cout << "Más trufas en total";
    rlutil::locate(30,7);
    cout << max_trufas[0] << " PDV";
    rlutil::locate(45,7);
    cout << max_trufas[1] << " PDV";
    rlutil::locate(60,7);
    cout << "|";

    rlutil::locate(2,8);
    cout << "|";
    rlutil::locate(7,8);
    cout << "Cada 50 trufas";
    rlutil::locate(30,8);
    cout << cada_50_trufas[0] << " PDV";
    rlutil::locate(45,8);
    cout << cada_50_trufas[1] << " PDV";
    rlutil::locate(60,8);
    cout << "|";

    rlutil::locate(2,9);
    cout << "|";
    rlutil::locate(7,9);
    cout << "Oinks";
    rlutil::locate(30,9);
    cout << cada_oink[0] << " PDV";
    rlutil::locate(45,9);
    cout << cada_oink[1] << " PDV";
    rlutil::locate(60,9);
    cout << "|";

    rlutil::locate(2,10);
    cout << "|";
    rlutil::locate(7,10);
    cout << "Cerdo más codicioso";
    rlutil::locate(30,10);
    cout << mas_codicioso[0] << " PDV";
    rlutil::locate(45,10);
    cout << mas_codicioso[1] << " PDV";
    rlutil::locate(60,10);
    cout << "|";
    rlutil::locate(2,11);
    cout << "************************************************************" << endl;


    rlutil::locate(2,12);
    cout << "|";
    rlutil::locate(7,12);
    cout << "Humcerdo Primo";
    rlutil::locate(30,12);
    cout << cerdo_primo[0] << " PDV";
    rlutil::locate(45,12);
    cout << cerdo_primo[1] << " PDV";
    rlutil::locate(60,12);
    cout << "|";



    rlutil::locate(2,13);
    cout << "************************************************************" << endl;

    rlutil::locate(2,14);
    cout << "|";
    rlutil::locate(7,14);
    cout << "TOTAL";
    rlutil::locate(30,14);
    cout << total[0] << " PDV";
    rlutil::locate(45,14);
    cout << total[1] << " PDV";
    rlutil::locate(60,14);
    cout << "|";

    /////////////////
    rlutil::locate(65,4);
    cout << "------------------------";
    rlutil::locate(65,5);
    cout << jugador[0];
    rlutil::locate(65,6);
    cout << "------------------------";
    rlutil::locate(65,7);
    cout << "Trufas: " << acu_trufas[0];
    rlutil::locate(65,8);
    cout << "Lanzamientos (cant. máx): " << cant_max_lanzamientos[0];
    rlutil::locate(65,9);
    cout << "Oinks: " << cont_oink[0];
    rlutil::locate(65,10);
    cout << "------------------------";
    rlutil::locate(65,11);
    cout << jugador[1];
    rlutil::locate(65,12);
    cout << "------------------------";
    rlutil::locate(65,13);
    cout << "Trufas: " << acu_trufas[1];
    rlutil::locate(65,14);
    cout << "Lanzamientos (cant. máx): " << cant_max_lanzamientos[1];
    rlutil::locate(65,15);
    cout << "Oinks: " << cont_oink[1];


    return;
}

///Ganador:

void quien_gana(int total[2], std::string &ganador, std::string jugador[2], int &puntaje_ganador){

    if(total[0]>total[1]){
        ganador=jugador[0];
        puntaje_ganador=total[0];
    }else if (total[0]<total[1]){
        ganador=jugador[1];
        puntaje_ganador=total[1];
    }else{
        ganador="empate";
        puntaje_ganador=total[0];
    }
    if(ganador!= "empate"){
        rlutil::locate(7,16);
        cout << "¡El ganador es " << ganador << ", con " << puntaje_ganador << " PDV!" ;
    }else{
        rlutil::locate(7,16);
        cout << "¡Hubo un empate! El puntaje de ambos fue " << puntaje_ganador << " PDV.";
    }

    return;

}

///Estadístic:
void datos_estadisticas(int puntaje_ganador, int &puntaje_estadistica, std::string ganador, std::string &jugador_estadistica){
    if(puntaje_ganador>puntaje_estadistica && ganador != "empate"){
        puntaje_estadistica=puntaje_ganador;
        jugador_estadistica=ganador;
    }
}

///Funcion para preguntar si desea salir e ingresar por teclado la respuesta:

void desea_salir(char &salir){
    rlutil::locate(22,15);
    cout << "¿DESEA SALIR? (S / N)" << endl;
    cin >> salir;
    salir = toupper(salir);

    return;
}
