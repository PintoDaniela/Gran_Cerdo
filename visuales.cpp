#include<iostream>
#include <cstdlib>
#include <locale.h>
#include "rlutil.h"
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;

///mostrar menú.
void ir_a_menu(bool mostrar_menu){

    if(mostrar_menu==1){
        rlutil::locate(26,8);
        cout << "GRAN CERDO" << endl;
        rlutil::locate(20,9);
        cout << "---------------------" << endl;
        rlutil::locate(20,10);
        cout << "1 - JUGAR" << endl;
        rlutil::locate(20,11);
        cout << "2 - ESTADÍSTICAS" << endl;
        rlutil::locate(20,12);
        cout << "3 - CERDITOS" << endl;
        rlutil::locate(20,13);
        cout << "---------------------" << endl;
        rlutil::locate(20,14);
        cout << "0 - SALIR" << endl << endl;
        cout << endl;
        rlutil::locate(9,20);
        cout << ".-*-.-*-.-*-.-*-.-*-.-*-.-*-.-*-.-*-.-*-.";
        rlutil::locate(9,1);
        cout << "------------------------------------------";
        rlutil::locate(9,19);
        cout << "------------------------------------------";
        rlutil::locate(9,21);
        cout << "------------------------------------------";
        rlutil::locate(9,2);
        cout << ".-*-.-*-.-*-.-*-.-*-.-*-.-*-.-*-.-*-.-*-.";
        rlutil::locate(9,3);
        cout << "------------------------------------------";
        rlutil::locate(2,24);
        cout << "Elija una opción para continuar" << endl;
    }
return;
}


///marco jugadores:
void marco_jugadores(void){
    rlutil::locate(2,2);
            cout << "GRAN CERDO |" << endl;
            rlutil::locate(8,4);
            cout << "********************************************************" << endl;
            rlutil::locate(8,5);
            cout << "--------------------------------------------------------" << endl;
            rlutil::locate(8,13);
            cout << "--------------------------------------------------------" << endl;
            rlutil::locate(8,14);
            cout << "********************************************************" << endl;
}


///mostrar dibujo de cerdito.
void dibujo_cerdito (int cerdito){

    int cara_cerdo[12][15]={
            {2,2,2,0,1,1,1,1,1,1,1,0,2,2,2},
            {2,2,2,1,1,1,1,1,1,1,1,1,2,2,2},
            {2,2,1,1,1,1,1,1,1,1,1,1,1,2,2},
            {2,2,1,1,0,0,1,1,1,0,0,1,1,2,2},
            {0,1,1,1,3,0,1,1,1,3,0,1,1,1,0},
            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
            {0,1,1,1,1,1,2,2,2,1,1,1,1,1,0},
            {0,1,1,1,1,2,3,2,3,2,1,1,1,1,0},
            {0,0,1,1,1,2,2,2,2,2,1,1,1,0,0},
            {0,0,1,1,1,1,2,2,2,1,1,1,1,0,0},
            {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
            {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0}
        };

        if(cerdito==1||cerdito==2){
            std::setlocale(LC_ALL, "C");
            for(int i=0;i<12;i++){
                rlutil::locate(15,5+i);
                for(int j=0; j<15; j++)
                    if(cara_cerdo[i][j]==0){
                        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),92);
                        cout<<char(219) << char(219);
                    }else if(cara_cerdo[i][j]==1){
                        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),92);
                        cout<<char(219) << char(219);
                    }else if(cara_cerdo[i][j]==2){
                        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),94);
                        cout<<char(219) << char(219);
                    }else{
                        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),80);
                        cout<<char(219) << char(219);
                }
                cout << endl;
            }
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),94);
            rlutil::locate(23,20);
            cout << "- GRAN CERDO -";
            rlutil::locate(9,19);
            cout << "------------------------------------------";
            rlutil::locate(9,21);
            cout << "------------------------------------------";
        }
        if(cerdito==1){
            rlutil::locate(9,1);
            cout << "------------------------------------------";
            rlutil::locate(9,2);
            cout << ".-*-.-*-.-*-.-*-.-*-.-*-.-*-.-*-.-*-.-*-.";
            rlutil::locate(9,3);
            cout << "------------------------------------------";
        }
        std::setlocale(LC_ALL, "");
    return;
}


void dibujo_cerdito_oink (void){
    int cara_cerdo[12][15]={
            {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
            {2,2,2,1,1,1,1,1,1,1,1,1,2,2,2},
            {2,2,1,1,1,1,1,1,1,1,1,1,1,2,2},
            {2,2,1,1,0,0,1,1,1,0,0,1,1,2,2},
            {0,1,1,1,3,0,1,1,1,3,0,1,1,1,0},
            {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
            {0,1,1,1,1,1,2,2,2,1,1,1,1,1,0},
            {0,0,1,1,1,2,3,2,3,2,1,1,1,0,0},
            {0,0,1,1,1,2,2,2,2,2,1,1,1,0,0},
            {0,0,0,1,1,1,2,2,2,1,1,1,0,0,0},
            {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
            {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0}
        };


        for(int i=0;i<12;i++){
            rlutil::locate(80,10+i);
            for(int j=0; j<15; j++)
                if(cara_cerdo[i][j]==0){
                    cout<<"  ";
                }else if(cara_cerdo[i][j]==1){
                    cout<<"..";
                }else if(cara_cerdo[i][j]==2){
                    cout<<"@@";
                }else{
                    cout<<"[]";
            }
            cout << endl;
        }


    return;
}



void dibujar_dados (int dado, int posicion){
    int dibujo_dado[5][5];

    int dibujo_dado1[5][5]={
        {2,2,2,2,2},
        {3,0,0,0,4},
        {3,0,1,0,4},
        {3,0,0,0,4},
        {5,5,5,5,5}
    };


    int dibujo_dado2 [5][5]={
        {2,2,2,2,2},
        {3,1,0,0,4},
        {3,0,0,0,4},
        {3,0,0,1,4},
        {5,5,5,5,5}
    };

    int dibujo_dado3 [5][5]={
        {2,2,2,2,2},
        {3,1,0,0,4},
        {3,0,1,0,4},
        {3,0,0,1,4},
        {5,5,5,5,5}
    };

    int dibujo_dado4 [5][5]={
        {2,2,2,2,2},
        {3,1,0,1,4},
        {3,0,0,0,4},
        {3,1,0,1,4},
        {5,5,5,5,5}
    };

    int dibujo_dado5 [5][5]={
        {2,2,2,2,2},
        {3,1,0,1,4},
        {3,0,1,0,4},
        {3,1,0,1,4},
        {5,5,5,5,5}
    };

    int dibujo_dado6 [5][5]={
        {2,2,2,2,2},
        {3,1,0,1,4},
        {3,1,0,1,4},
        {3,1,0,1,4},
        {5,5,5,5,5}
    };

    for(int i=0;i<5;i++){
        for(int j=0; j<5; j++)
            if(dado==1){
                dibujo_dado[i][j]=dibujo_dado1[i][j];
            }else if(dado==2){
                dibujo_dado[i][j]=dibujo_dado2[i][j];
            }else if(dado==3){
                dibujo_dado[i][j]=dibujo_dado3[i][j];
            }else if(dado==4){
                dibujo_dado[i][j]=dibujo_dado4[i][j];
            }else if(dado==5){
                dibujo_dado[i][j]=dibujo_dado5[i][j];
            }else if(dado==6){
                dibujo_dado[i][j]=dibujo_dado6[i][j];
            }
    }



    for(int i=0;i<5;i++){
        rlutil::locate(22+(posicion*12),15+i);
        for(int j=0; j<5; j++){
            if(dibujo_dado[i][j]==0){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),238/*95*/);
                cout<<char(219) << char(219);
               //cout<<"  ";
            }else if(dibujo_dado[i][j]==1){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),224/*240*/);
                cout<<char(223) << char(223);
                //cout<<"[]";
            }else if(dibujo_dado[i][j]==2){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),238/*255*/);
                cout<<char(223) << char(223);
                //cout<<"--";
            }
            else if(dibujo_dado[i][j]==3){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),238/*95*/);
                cout<<char(219) << char(219);
                //cout<<"| ";
            }
            else if(dibujo_dado[i][j]==4){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),238/*95*/);
                cout<<char(219) << char(219);
                //cout<<" |";
            }
            else if(dibujo_dado[i][j]==5){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),94);
                cout<<char(223) << char(223);
                //cout<<"--";
            }
        }

        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),94);//este es el color normal del juego.
        cout << endl;

    }



return;

}


///mostrar estadísticas:
//declaración de funciones utilizadas:
void dibujo_cerdito (int cerdito);

void estadisticas(int puntaje_estadistica, std::string jugador_estadistica, std::string jugador[2], std::string ganador){

    int cerdo=2;
    dibujo_cerdito(cerdo);

    if(puntaje_estadistica==0){
        rlutil::locate(10,3);
        cout << "AÚN NO HAY DATOS DE PUNTAJES ANTERIORES." << endl;
    }else if(ganador=="empate"){
        rlutil::locate(6,3);
        cout << "MAYOR PUNTAJE: " << puntaje_estadistica << " PDV  -  JUGADORES: " << jugador[0] << " y " << jugador[1]<< endl;
    }else{
        rlutil::locate(10,3);
        cout << "MAYOR PUNTAJE: " << puntaje_estadistica << " PDV  -  JUGADOR: " << jugador_estadistica << endl;
    }
    rlutil::locate(2,24);
    cout << "Presione una tecla para volver al menú principal...";
    rlutil::anykey();

    return;
}



///mostrar los créditos:
void creditos (char opcion_menu){
    if (opcion_menu == '3'){
        rlutil::locate(15,6);
        cout << "********************** GRAN CERDO **********************" << endl;
        rlutil::locate(15,8);
        cout << "--------------------------------------------------------" << endl;
        rlutil::locate(15,9);
        cout << "|   TRABAJO INTEGRADOR - LABORATORIO DE COMPUTACIÓN 1  |" << endl;
        rlutil::locate(15,10);
        cout << "--------------------------------------------------------" << endl;
        rlutil::locate(16,11);
        cout << "TECNICATURA UNIVERSIRARIA EN PROGRAMACIÓN - UTN FRGP" << endl;
        rlutil::locate(16,12);
        cout << "PROFESOR: SIMON, ANGEL"<< endl;
        rlutil::locate(16,13);
        cout << "ALUMNA: PINTO, DANIELA"  << endl;
        rlutil::locate(16,14);
        cout << "LEGAJO: 26323" << endl;
        rlutil::locate(16,16);
        cout << "BIBLIOTECAS UTILIZADAS: RLUTIL (TAPIO VIERROS - 2010)" << endl;
        rlutil::locate(15,19);
        cout << "************************* 2022 *************************" << endl;
        rlutil::locate(2,24);
        cout << "Presione una tecla para volver al menú principal... " << endl;
        rlutil::anykey();
    }
    return;
}







