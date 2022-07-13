#ifndef JUGADAS_H_INCLUDED
#define JUGADAS_H_INCLUDED

    void turno(int cant_dados, int resultado_lanzamiento[3], int &cant_ases, int k);
    void humprimo_cerdo(int cant_dados, int resultado_lanzamiento[3], bool &humprimo, int con_primos, int cerdo_primo[2], int y);
    void suma_trufas (int &trufas_lanzamiento, int cant_dados, int resultado_lanzamiento[2], int &trufas_ronda, char &cede_turno);
    char oink(int &trufas_lanzamiento, int &trufas_ronda, int cant_dados, int resultado_lanzamiento[3]);
    void pierde_trufas_ronda(int &trufas, bool &turno);
    void se_hunde(int acu_trufas[2], bool &turno, bool &tres_dados, int y);
    void se_hunde_hondirijillo(int acu_trufas[2], int y, bool &turno);


#endif // JUGADAS_H_INCLUDED
