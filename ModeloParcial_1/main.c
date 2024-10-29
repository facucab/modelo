#include "Funciones.h"
int main(int argc, char * argv[])
{
    //generarLotePrueba(argv[1]);

    int vec[5] = {2,4,6,8,10};
    int e = 5;
    int cant = 5;
    insertarOrdenado(vec, &cant, sizeof(vec[0]), compararINT, &e);

    for(int i = 0; i<cant; i++)
    {
        printf("%d\n", vec[i]);
    }
    return 0;
}
