#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

    void lanzamiento_dados(int cant, int caras, int vec[6]);
    void quien_empieza(int resultado_lanzamiento[3], std::string jugador[2], std::string nombre[2]);
    void datos_PDV(int max_trufas[2], int cada_50_trufas[2],  int cada_oink[2], int acu_trufas[2], int cont_oink[2], int cant_max_lanzamientos[2], int mas_codicioso[2], int vec_lanzamientos[2][5], int total[2], int cerdo_primo[2]);
    void quien_gana(int total[2], std::string &ganador, std::string jugador[2], int &puntaje_ganador);
    void datos_ronda(std::string jugador[2], int acu_trufas[2], int cont_lanzamiento, int trufas_ronda, int x, int y);
    void texto_definicion_jugadores(std::string nombre[2], int i);
    void tabla_puntajes(std::string jugador[2], int acu_trufas[2], int max_trufas[2],int cada_50_trufas[2], int cada_oink[2], int mas_codicioso[2],int total[2],int cant_max_lanzamientos[2], int cont_oink[2], int cerdo_primo[2]);
    void desea_salir(char &salir);
    void datos_estadisticas(int puntaje_ganador, int &puntaje_estadistica, std::string ganador, std::string &jugador_estadistica);



#endif // FUNCIONES_H_INCLUDED
