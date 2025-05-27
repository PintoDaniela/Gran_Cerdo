#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <string>
#include "rlutil.h"
#include<stdlib.h>
#include <ctime>

/*
#include "visuales.h"
#include "funciones.h"
*/
#include "opcion_jugar.h"
using namespace std;


void jugar(int &puntaje_estadistica, string &jugador_estadistica, string jugador[2], string &ganador){
    int cant_dados, trufas_ronda=0, cont_lanzamiento=0, trufas_lanzamiento=0,  puntaje_ganador=0, cant_ases=0,  k=1, con_primos=0;
    int acu_trufas[2]={},resultado_lanzamiento[3]={},cont_oink[2]={}, mas_codicioso[2]={}, max_trufas[2]={}, cada_50_trufas[2]={}, cada_oink[2]={},total[2]={}, cant_max_lanzamientos[2]={}, cerdo_primo[2]={};
    int mat_lanzamientos[2][5]={};
    string nombre[2];
    char cede_turno;

    //////// Ingreso de nombres y definición de jugadores 1 y 2 ////////
    quien_empieza(resultado_lanzamiento, jugador, nombre);

    //////////////////// Empieza el juego //////////////////
    bool tres_dados=0;
    bool humprimo=0;
    bool hundido_en_el_barro=0;
    for(int y=0; y<2; y++){
        for(int x=0; x<5; x++){
           mat_lanzamientos[y][x]=0;
        }
    }
    for(int i=0; i<2; i++){
        acu_trufas[i]=0;
        cont_oink[i]=0;
        cant_max_lanzamientos[i]=0;
        mas_codicioso[i]=0;
    }

    for(int x=0; x<5; x++){//rondas

        for(int y=0; y<2; y++){//jugadores
            cont_lanzamiento=0;
            trufas_ronda=0;
            bool cambio_turno=0;
            bool pierde_turno=0;

            while(cambio_turno==0){//turno
                pierde_turno=0;
                cont_lanzamiento++;
                trufas_lanzamiento=0;
                cant_ases=0;
                con_primos=0;

                datos_ronda(jugador, acu_trufas, cont_lanzamiento, trufas_ronda, x, y);
                rlutil::locate(10,13);
                cout << " ¡Presiona una tecla para lanzar tus dados!" << endl << endl;
                rlutil::anykey();
                rlutil::locate(10,13);
                cout << "                                              " << endl << endl;

                if((acu_trufas[0]>50 && acu_trufas[1]>50)||hundido_en_el_barro){
                    tres_dados=1;
                }

                if(tres_dados==0){ /////////////Jugadas con 2 dados//////////////

                    cant_dados=2;
                    //lanzamiento del turno
                    turno(cant_dados, resultado_lanzamiento,cant_ases, k);
                    humprimo_cerdo(cant_dados, resultado_lanzamiento, humprimo, con_primos, cerdo_primo, y);

                    //dados diferentes distintos de 1:
                    if(resultado_lanzamiento[0]!=resultado_lanzamiento[1] && cant_ases==0){
                        suma_trufas (trufas_lanzamiento, cant_dados, resultado_lanzamiento, trufas_ronda, cede_turno);

                    //Oink:
                    }else if(resultado_lanzamiento[0]==resultado_lanzamiento[1] && cant_ases==0){
                        cont_oink[y]++;
                        dibujo_cerdito_oink();
                        cede_turno=oink(trufas_lanzamiento, trufas_ronda,cant_dados, resultado_lanzamiento);
                        rlutil::anykey();

                    //Pierde trufas ronda:
                    }else if(cant_ases==1){
                        pierde_trufas_ronda(trufas_ronda, pierde_turno);

                    // Se hunde en el barro:
                    }else if(cant_ases==2){
                        se_hunde(acu_trufas, pierde_turno, tres_dados, y);
                        hundido_en_el_barro=1;
                    }

                }else{ /////////////Jugadas con 3 dados//////////////
                    cant_dados=3;

                    //lanzamiento del turno
                    turno(cant_dados, resultado_lanzamiento,cant_ases, k);
                    humprimo_cerdo(cant_dados, resultado_lanzamiento, humprimo, con_primos, cerdo_primo, y);

                    //dados diferentes entre sí y distintos de 1:
                    if((resultado_lanzamiento[0]!=resultado_lanzamiento[1] || resultado_lanzamiento[1]!= resultado_lanzamiento[2] || resultado_lanzamiento[2]!= resultado_lanzamiento[0]) && cant_ases==0){//incluye los casos todos distintos y dos iguales y uno distinto.
                        suma_trufas (trufas_lanzamiento, cant_dados, resultado_lanzamiento, trufas_ronda, cede_turno);

                    //Oink:
                    }else if(resultado_lanzamiento[0]==resultado_lanzamiento[1] && resultado_lanzamiento[1]==resultado_lanzamiento[2] && cant_ases==0){
                        cont_oink[y]++;
                        dibujo_cerdito_oink();
                        cede_turno=oink(trufas_lanzamiento, trufas_ronda,cant_dados, resultado_lanzamiento);
                        rlutil::anykey();

                    //Pierde trufas ronda:
                    }else if(cant_ases == 1 ){
                        pierde_trufas_ronda(trufas_ronda, pierde_turno);

                    //Se hunde en el barro:
                    }else if(cant_ases == 2){
                        se_hunde(acu_trufas, pierde_turno, tres_dados, y);

                    //Se hunde en el barro y pasa las trufas al otro cerdo:
                    }else if(cant_ases == 3){
                        se_hunde_hondirijillo(acu_trufas, y, pierde_turno);
                    }
                }

                //Cambio de turno, suma de puntos, etc.
                if(pierde_turno!=1){
                    while(cede_turno!= 'S' && cede_turno!= 'N'){
                    datos_ronda(jugador, acu_trufas, cont_lanzamiento, trufas_ronda, x, y);
                    rlutil::locate(10,18);
                    cout << "¿Deseás continuar? [S] si tu respuesta es sí o [N] si tu respuesta es no." << endl;
                    rlutil::locate(45,20);
                    cin >> cede_turno;
                    cede_turno = toupper(cede_turno);
                    }
                }

                if(pierde_turno){
                    cambio_turno=1;
                }else if (cede_turno=='N'){
                    datos_ronda(jugador, acu_trufas, cont_lanzamiento, trufas_ronda, x, y);
                    rlutil::locate(20,18);
                    cout << "¡ACUMULASTE " << trufas_ronda << " TRUFAS EN ESTA RONDA!" << endl;
                    acu_trufas[y]+=trufas_ronda;
                    cambio_turno=1;
                }

                if(cede_turno=='N' || pierde_turno){
                    rlutil::anykey();
                }
                //Matriz con cantidad de lanzamientos por ronda:
                if(cambio_turno){
                    mat_lanzamientos[y][x]=cont_lanzamiento; //y=jugador, x=ronda.
                }
            }//fin while (cede o pierde)
        }//fin for turno jugador
    }//fin while ronda


    rlutil::cls();
    //Calculo los PDV por cada hito:
    datos_PDV(max_trufas, cada_50_trufas, cada_oink, acu_trufas, cont_oink, cant_max_lanzamientos, mas_codicioso, mat_lanzamientos, total, cerdo_primo);
    //Definición ganador:
    quien_gana(total, ganador, jugador, puntaje_ganador);
    //Tabla puntajes:
    tabla_puntajes(jugador, acu_trufas, max_trufas, cada_50_trufas, cada_oink, mas_codicioso, total, cant_max_lanzamientos, cont_oink, cerdo_primo);
    //estadisticas:
    datos_estadisticas(puntaje_ganador,puntaje_estadistica, ganador, jugador_estadistica);
    //volver al menú.
    rlutil::locate(2,24);
    cout << "Presione una tecla para volver al menú principal... " << endl;
    rlutil::anykey();
    rlutil::cls();
}
