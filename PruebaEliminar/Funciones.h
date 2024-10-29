#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nombre[30];
    float precio;
}Producto;
typedef struct {
    int idVenta;
    int idProducto;
    int cantVendida;
}Pedido;
void trozarPedido(char * linea, Pedido * p);
void trozarProducto(char * linea, Producto * p);
int crearLotePedidos(char * nombre);
int crearLotesProductos(char * nombre);
int procesar(char * nombre_producto, char * nombre_pedido);
#endif // FUNCIONES_H_INCLUDED
