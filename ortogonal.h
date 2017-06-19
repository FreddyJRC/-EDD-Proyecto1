#ifndef ORTOGONAL_H
#define ORTOGONAL_H

typedef struct Nodo Nodo;
typedef struct Encabezado Encabezado;
typedef struct ListaEncabezados ListaEncabezados;
typedef struct Matriz Matriz;

struct Nodo
{
    int fila;
    int columna;
    int nivel;
    char * valor;
    Nodo * derecha;
    Nodo * izquierda;
    Nodo * arriba;
    Nodo * abajo;
    Nodo * enfrente;
    Nodo * atras;

    Nodo(int nivel, int fila, int columna, char * valor);
};

struct Encabezado
{
    int id;
    Encabezado * siguiente;
    Encabezado * anterior;
    Nodo * acceso;

    Encabezado(int id);
};

struct ListaEncabezados
{
    Encabezado * primero;

    void insertar(Encabezado * nuevo);
    Encabezado * getEncabezado(int id);
};

struct Matriz
{
    ListaEncabezados * eFilas;
    ListaEncabezados * eColumnas;
    ListaEncabezados * eNiveles;

    Matriz();
    void insertar(int nivel, int fila, int columna, char * valor);
    void recorrerFilas();
    void recorrerColumnas();
    void recorrerNiveles();
    Nodo * getFloor(int fila, int columna);
    Nodo * getClosest(Nodo * floor, int nivel, int dir);
};

#endif // ORTOGONAL_H
