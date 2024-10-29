#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char fecha[12];
    char codigo[8];
    float temp; // 6 digitos
    char estado[12];
}Sensor;
/*
typedef struct{
    void * vec;
    size_t tamElem;
    size_t cantElem;
}VecTDA;
void crearSensorTDA(VecTDA * v, size_t tamElem);
*/
int insertarOrdenado(void * v, size_t * cantElem, size_t tamElem, int (*comparar)(void *, void *), void * e);
int generarLotePrueba(char * nombre);
int compararINT(void * a, void *b);
#endif // FUNCIONES_H_INCLUDED
