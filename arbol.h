#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>

struct aNodo
{
    aNodo * izq;
    aNodo * der;
    char * info;
    int wins;
    int lost;
    aNodo(char * info, int wins, int lost);
};

struct Arbol
{
    aNodo * raiz;

    Arbol();
    aNodo * buscar(char * info);
    aNodo * buscar(aNodo * actual, char * info);
    aNodo * getMinimo(aNodo * actual);
    bool insertar(char * info, int wins, int lost);
    bool insertar(aNodo * actual, aNodo * nuevo);
    void eliminar(char * info);
    aNodo *eliminar(aNodo * actual, char * info);
    void preOrden();
    void preOrden(FILE *fs, aNodo * actual);
    void inOrden();
    void inOrden(aNodo * actual);
    void postOrden();
    void postOrden(aNodo * actual);
    int calcularAltura();
    int calcularAltura(aNodo * actual);
    int getNodosHoja();
    int getNodosHoja(aNodo * actual);

};

#endif // ARBOL_H
