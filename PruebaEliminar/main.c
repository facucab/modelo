#include "Funciones.h"
/*
    Aumentar el precio a cada producto que tiene mas de una 4 productos vendidos.
    Ningun archivo, contiene repetidos.
*/

int main(int argc, char *argv[])
{
    crearLotesProductos(argv[1]);
    crearLotePedidos(argv[2]);
    procesar(argv[1], argv[2]);

    return 0;
}
