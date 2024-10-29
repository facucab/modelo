#include "Funciones.h"
int procesar(char * nombre)
{
    FILE * archivo = fopen(nombre, "rt");
    if(!archivo)
    {
        printf("ERROR EN LA APERTURA DEL ARCHIVO: %s", nombre);
        return 0;
    }



    fclose(archivo);
    return 1;
}
///TDA
int insertarOrdenado(void * v, size_t * cantElem, size_t tamElem, int (*comparar)(void *, void *), void * e)
{
    //variables
    int pos = 0;
    void * pr_v = v;

    while(comparar(pr_v, e) <= 0)
    {
        pr_v+= tamElem;
        pos++;
    }
    int offsetFinal = (*cantElem) * tamElem;
    void *pr_final = v + (offsetFinal);


    void * aux;
    for(int i = *cantElem; i > pos; i--)
    {

        aux = pr_final - tamElem;
        memcpy(pr_final, aux, tamElem);
        pr_final-=tamElem;
    }

    v+= (pos * tamElem);
    memcpy(v,e, tamElem);
    *cantElem+=1;

    return 0;
}
int compararINT(void * a, void *b)
{
    int * valor_a =  (int *)(a);
    int * valor_b = (int *)(b);
    return ((*valor_a) - (*valor_b));
}
/*
void crearSensorTDA(VecTDA * v, size_t tamElem)
{
    v->vec = NULL;
    v->tamElem = tamElem;
}
*/


///Generar lote
int generarLotePrueba(char * nombre)
{
    FILE * archivo = fopen(nombre, "wt");

    if(archivo == NULL)
    {
        printf("ERROR EN LA CREACION DEL ARCHIVO: %s", nombre);
        return 0;
    }

    Sensor s[15] = {
        {"1719077360","DEV08",54.4,"OFFLINE"},
        {"1719077360","DEV01",6.5,"READY"},
        {"1719077360","DEV02",7.3,"READY"},
        {"1719077360","DEV08",8.7,"READY"},
        {"1719077360","DEV02",2.4,"READY"},
        {"1719077360","DEV01",56.3,"READY"},
        {"1719077360","DEV06",86.1,"OFFLINE"},
        {"1719077360","DEV08",2.3,"OFFLINE"},
        {"1719077360","DEV08",1.1,"READY"},
        {"1719077360","DEV06",23.5,"OFFLINE"},
        {"1719077360","DEV02",76.2,"READY"},
        {"1719077360","DEV08",8.9,"READY"},
        {"1719077360","DEV06",9.8,"OFFLINE"},
        {"1719077360","DEV01",5.42,"READY"},
        {"1719077360","DEV02",7.62,"OFFLINE"}
    };
    Sensor *pr_s = s;
    for(int i = 0; i<15; i++)
    {
        fprintf(archivo, "%-12s%-8s%06.2f%-12s\n", pr_s->fecha, pr_s->codigo, pr_s->temp, pr_s->estado);
        pr_s++;
    }


    fclose(archivo);
    return 1;
}
