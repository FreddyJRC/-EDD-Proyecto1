#ifndef ORTOGONAL_H
#define ORTOGONAL_H

#include <vector>
#include <string>

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
    int color;
    bool isDrawable;
    Nodo * derecha;
    Nodo * izquierda;
    Nodo * arriba;
    Nodo * abajo;
    Nodo * enfrente;
    Nodo * atras;

    Nodo(int nivel, int fila, int columna, char * valor, int color);
    Nodo *hasMached();
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
    void insertar(int nivel, int fila, int columna, char * valor, int color);
    void eliminar(Nodo * actual);
    void recorrerFilas();
    void recorrerColumnas();
    void graficar(int nivel);
    void mover(std::vector<std::string> move, int turn);
    Nodo * getFloor(int fila, int columna);
    Nodo * getClosest(Nodo * floor, int nivel, int dir);
    Nodo * findNodo(int nivel, int fila, int columna);
};

int idToInt(char id);

#endif // ORTOGONAL_H
