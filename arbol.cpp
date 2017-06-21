#include <arbol.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//*******CONSTRUCTORES*******
Nodo::Nodo(char *info)
{
    this->info = (char*)malloc(sizeof(char) * strlen(info));
    strcpy(this->info, info);
    this->izq = NULL;
    this->der = NULL;
}

Arbol::Arbol()
{
    this->raiz = NULL;
}
//*******FIN CONSTRUCTORES*******


//*******BUSQUEDA*******
Nodo * Arbol::buscar(char * info)
{
    return buscar(this->raiz, info);
}

Nodo * Arbol::buscar(Nodo * actual, char *info)
{
    if (actual == NULL)
    {
        return NULL;
    }

    int comparacion = strcmp(info, actual->info);
    if(comparacion == 0)
    {
        return actual;
    }
    else
    {
        return buscar(comparacion < 0 ? actual->izq : actual->der, info);
    }
}
//*******FIN BUSQUEDA*******

//*******INSERCION*******
bool Arbol::insertar(char *info)
{
    if (buscar(info) == NULL)
    {
        if(raiz == NULL)
        {
            raiz = new Nodo(info);
            return true;
        }
        else
        {
            return insertar(raiz, new Nodo(info));
        }
    }

    return false;
}

bool Arbol::insertar(Nodo * actual, Nodo * nuevo)
{
    if(strcmp(nuevo->info, actual->info) < 0)
    {
        if(actual->izq == NULL)
        {
            actual->izq = nuevo;
            return true;
        }
        else
        {
            return insertar(actual->izq, nuevo);
        }
    }
    else
    {
        if(actual->der == NULL)
        {
            actual->der = nuevo;
            return true;
        }
        else
        {
            return insertar(actual->der, nuevo);
        }
    }
}
//*******FIN INSERCION*******

//*******RECORRIDOS*******
void Arbol::preOrden()
{
    cout << endl;
    cout << "*****Recorrido PreOrden*****" << endl;
    preOrden(raiz);
    cout << "*****Fin Recorrido PreOrden*****" << endl;
}

void Arbol::preOrden(Nodo *actual)
{
    if(actual != NULL)
    {
        cout << actual->info << endl;
        preOrden(actual->izq);
        preOrden(actual->der);
    }
}

void Arbol::inOrden()
{
    cout << endl;
    cout << "*****Recorrido InOrden*****" << endl;
    inOrden(raiz);
    cout << "*****Fin Recorrido InOrden*****" << endl;
}

void Arbol::inOrden(Nodo *actual)
{
    if(actual != NULL)
    {
        inOrden(actual->izq);
        cout << actual->info << endl;
        inOrden(actual->der);
    }
}

void Arbol::postOrden()
{
    cout << endl;
    cout << "*****Recorrido PostOrden*****" << endl;
    postOrden(raiz);
    cout << "*****Fin Recorrido PostOrden*****" << endl;
}

void Arbol::postOrden(Nodo *actual)
{
    if(actual != NULL)
    {
        postOrden(actual->izq);
        postOrden(actual->der);
        cout << actual->info << endl;
    }
}
//*******FIN RECORRIDOS*******

//*******CALCULO DE ALTURA****
int Arbol::calcularAltura()
{
    if(this->raiz == NULL)
    {
        return 0;
    }
    else
    {
        return calcularAltura(raiz);
    }
}

int Arbol::calcularAltura(Nodo * actual)
{
    if(actual == NULL)
    {
        return 0;
    }
    else
    {
        int hi = calcularAltura(actual->izq);
        int hd = calcularAltura(actual->der);
        return (hi > hd ? hi : hd) + 1;
    }
}
//******FIN CALCULO DE ALTURA****

//******CALCULO DE NODOS HOJA****
int Arbol::getNodosHoja()
{
    if(this->raiz == NULL)
    {
        return 0;
    }
    else
    {
        return getNodosHoja(this->raiz);
    }
}

int Arbol::getNodosHoja(Nodo * actual)
{
    if(actual == NULL)
    {
        return 0;
    }
    else
    {
        if(actual->izq == NULL && actual->der == NULL)
        {
            return 1;
        }
        else
        {
            return getNodosHoja(actual->izq) + getNodosHoja(actual->der);
        }
    }
}


//******FIN CALCULO DE NODOS HOJA***
