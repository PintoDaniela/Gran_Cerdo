#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <string>
#include "rlutil.h"
#include<stdlib.h>
#include <ctime>

using namespace std;


////////////////////////////// Lanzamientos y Resultados de las jugadas //////////////////////////////



///lanzamiento por turno

//declaracion de funciones para esta función:
void lanzamiento_dados(int cant, int caras, int vec[]);
void dibujar_dados (int dado, int posicion);

void turno(int cant_dados, int resultado_lanzamiento[3], int &cant_ases, int k){

    lanzamiento_dados(cant_dados, 6, resultado_lanzamiento);
    for(int j=0; j<cant_dados; j++){
        std::setlocale(LC_ALL, "C");
        dibujar_dados(resultado_lanzamiento[j], j);
        std::setlocale(LC_ALL, "");
        if(resultado_lanzamiento[j]==k){
            cant_ases++;
        }
    }

}

///Humprimo:
void humprimo_cerdo(int cant_dados, int resultado_lanzamiento[3], bool &humprimo, int con_primos, int cerdo_primo[2], int y){

    if(humprimo==0){
        for(int j=0; j<cant_dados; j++){
            if(resultado_lanzamiento[j]==2|| resultado_lanzamiento[j]==3||resultado_lanzamiento[j]==5){
                    con_primos++;
                }
        }
        if(con_primos==(cant_dados)){
            rlutil::locate(12,26);
            if(cant_dados==2){
                cout << "¡Alcanzaste el HITO Humcerdo Primo! ¡Ganaste 5 PDV!";
                cerdo_primo[y]=5;
            }else if (cant_dados==3){
                cout << "¡Alcanzaste el HITO Humcerdo Primo! ¡Ganaste 7 PDV!";
                cerdo_primo[y]=7;
            }

            humprimo=1;
        }
    }
}

/// Dados diferentes distintos de 1
void suma_trufas (int &trufas_lanzamiento, int cant_dados, int resultado_lanzamiento[2], int &trufas_ronda, char &cede_turno){
    for(int j=0; j<cant_dados; j++){
        trufas_lanzamiento+=resultado_lanzamiento[j];
        trufas_ronda += resultado_lanzamiento[j];
    }

    rlutil::locate(10,20);
    cout << "¡Sumaste " << trufas_lanzamiento << " trufas!" << endl;
    rlutil::locate(10,22);
    cout << "¿Deseás continuar? S/N" << endl;
    rlutil::locate(45,22);
    cin >> cede_turno;
    cede_turno = toupper(cede_turno);

    return;
}



/// Oink
char oink(int &trufas_lanzamiento, int &trufas_ronda, int cant_dados, int resultado_lanzamiento[3]){

    char sigue_jugando;

    for(int j=0; j<cant_dados; j++){
        trufas_lanzamiento+=resultado_lanzamiento[j]*2;
        trufas_ronda += resultado_lanzamiento[j]*2;
    }


    rlutil::locate(10,20);
    cout << "¡Hiciste un OINK y tus trufas se duplican! ¡Sumaste " << trufas_lanzamiento << " trufas!" << endl;
    rlutil::locate(10,22);
    cout << "¡DEBÉS VOLVER A TIRAR TUS DADOS!" << endl;
    rlutil::locate(10,24);
    cout << "PRESIONA UNA TECLA PARA CONTINUAR..." << endl;
    sigue_jugando='S';

    return sigue_jugando;
}

/// Pierde trufas ronda
void pierde_trufas_ronda(int &trufas, bool &turno){
    rlutil::locate(10,20);
    cout << "¡Oh, no! Perdiste todas tus trufas de esta ronda." << endl;
    trufas=0;
    turno=1;

    return;
}

/// Se hunde en el barro
void se_hunde(int acu_trufas[2], bool &turno, bool &tres_dados, int y){
    rlutil::locate(10,20);
    cout << "¡Te hundiste en el barro! ¡Perdiste todas tus trufas acumuladas en todas las rondas!" << endl;
    acu_trufas[y]=0;
    turno=1;
    tres_dados=1;

    return;
}

/// Se hunde y pasa las trufas al otro cerdo
void se_hunde_hondirijillo(int acu_trufas[2], int y, bool &turno){
    rlutil::locate(10,20);
    cout << "¡Oh, no! ¡Te hundiste en el barro! ¡Tu contrincante tomará todas tus trufas acumuladas en todas las rondas!" << endl;
    if (y==0){
        acu_trufas[1]+=acu_trufas[0];
    }else{
        acu_trufas[0]+=acu_trufas[1];
    }
    acu_trufas[y]=0;
    turno=1;

    return;
}
