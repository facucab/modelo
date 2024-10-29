#include "Funciones.h"
void trozarProducto(char * linea, Producto * p)
{
    char * token = strtok(linea, "|");
    p->id = atoi(token);

    token = strtok(NULL, "|");
    strcpy(p->nombre, token);

    token = strtok(NULL, "|");
    p->precio = atof(token);

}
void trozarPedido(char * linea, Pedido * p)
{
    char * aux = strchr(linea, '\n');
    aux = '\0';

    aux = strrchr(linea, '|');
    sscanf(aux+1, "%d", &p->cantVendida);
    *aux = '\0';

    aux = strrchr(linea, '|');
    sscanf(aux+1, "%d", &p->idProducto);
    *aux = '\0';

    sscanf(linea, "%d", &p->idVenta);
}
int procesar(char * nombre_producto, char * nombre_pedido)
{
    FILE * producto_arch = fopen(nombre_producto, "r+t");
    FILE * pedido_arch = fopen(nombre_pedido, "rt");

    if(producto_arch == NULL || pedido_arch == NULL)
    {
        printf("Error en la apertura de archivos");
        return 0;
    }
    ///Variables
    char lineaPro[100];
    char lineaPed[100];
    Producto pro;
    Pedido ped;


    fgets(lineaPed, sizeof(lineaPed), pedido_arch);
    while(fgets(lineaPro, sizeof(lineaPro), producto_arch))
    {
        trozarProducto(lineaPro, &pro);
        trozarPedido(lineaPed, &ped);

        if(pro.id != ped.idVenta)
        {
            fgets(lineaPed, sizeof(lineaPed), pedido_arch);
            trozarPedido(lineaPed, &ped);
        }

        /*
        && fgets(lineaPed, sizeof(lineaPed), pedido_arch)
        trozarProducto(lineaPro, &pro);
        trozarPedido(lineaPed, &ped);
        printf("\n%d\t%d", pro.id, ped.idProducto);
        */
    }

    fclose(producto_arch);
    fclose(pedido_arch);
    return 1;
}
int crearLotePedidos(char * nombre)
{
    FILE * archivo = fopen(nombre, "wt");
    if(archivo == NULL)
    {
        printf("ERROR EN LA CREACION/APERTURA DE %s", nombre);
        return 0;
    }

    Pedido p[5] = {
        {1,1,5},
        {2,10,1},
        {3,2,1},
        {4,3,10},
        {5,4,12},
        {6,5,2}
        };

    Pedido * pr_p = p;

    for(int i = 0; i < 5; i++)
    {
        fprintf(archivo, "%d|%d|%d\n", pr_p->idVenta, pr_p->idProducto, pr_p->cantVendida);
        pr_p++;
    }

    fclose(archivo);
    return 1;

}
int crearLotesProductos(char * nombre)
{
    FILE * archivo = fopen(nombre, "wt");
    if(archivo == NULL)
    {
        printf("\nError en la apertura del archivo %s", nombre);
        return 0;
    }
    Producto p[4] = {
        {1,"Cebolla",45.3},
        {2,"Morron",5.3},
        {3, "Manzana", 16.0},
        {4, "Kiwi", 34.2}
    };
    Producto * pr_p = p;
    for(int i = 0; i<4; i++)
    {
        fprintf(archivo, "%d|%s|%.2f\n", pr_p->id, pr_p->nombre, pr_p->precio);
        pr_p++;
    }

    fclose(archivo);
    return 1;
}
