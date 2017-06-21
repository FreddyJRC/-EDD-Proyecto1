#ifndef ARBOL_H
#define ARBOL_H

struct Nodo
{
    Nodo * izq;
    Nodo * der;
    char * info;
    Nodo(char * info);
};

struct Arbol
{
    Nodo * raiz;

    Arbol();
    Nodo * buscar(char * info);
    Nodo * buscar(Nodo * actual, char * info);
    bool insertar(char * info);
    bool insertar(Nodo * actual, Nodo * nuevo);
    void preOrden();
    void preOrden(Nodo * actual);
    void inOrden();
    void inOrden(Nodo * actual);
    void postOrden();
    void postOrden(Nodo * actual);
    int calcularAltura();
    int calcularAltura(Nodo * actual);
    int getNodosHoja();
    int getNodosHoja(Nodo * actual);

};

#endif // ARBOL_H
