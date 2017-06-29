#include <arbol.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//*******CONSTRUCTORES*******
aNodo::aNodo(char *info, int wins, int lost)
{
    this->info = (char*)malloc(sizeof(char) * strlen(info));
    strcpy(this->info, info);
    this->wins = wins;
    this->lost = lost;
    this->izq = NULL;
    this->der = NULL;
}

Arbol::Arbol()
{
    this->raiz = NULL;
}
//*******FIN CONSTRUCTORES*******


//*******BUSQUEDA*******
aNodo * Arbol::buscar(char * info)
{
    return buscar(this->raiz, info);
}

aNodo * Arbol::buscar(aNodo * actual, char *info)
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
bool Arbol::insertar(char *info, int wins, int lost)
{
    if (buscar(info) == NULL)
    {
        if(raiz == NULL)
        {
            raiz = new aNodo(info, wins, lost);
            return true;
        }
        else
        {
            return insertar(raiz, new aNodo(info, wins, lost));
        }
    }

    return false;
}

bool Arbol::insertar(aNodo * actual, aNodo * nuevo)
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

//*******ELIMINAR*********
void Arbol::eliminar(char *info){
    this->eliminar(this->raiz, info);
}

aNodo * Arbol::eliminar(aNodo * actual, char *info){

    if(actual == NULL) return actual;

    if(strcmp(nuevo->info, actual->info) < 0){
        actual->izq = eliminar(actual->izq, info);
    } else if(strcmp(nuevo->info, actual->info) < 0){
        actual->der = eliminar(actual->der, info);
    } else {

        if(actual->izq == NULL){
            aNodo *tmp = actual->der;
            free(actual);
            return tmp;
        } else if(actual->der == NULL){
            aNodo *tmp = actual->izq;
            free(actual);
            return tmp;
        } else {
            aNodo *tmp = getMinimo(actual->der);
            actual->info = tmp->info;
            actual->der = eliminar(actual->der, tmp->info);
        }

    }
    return actual;
}

aNodo * Arbol::getMinimo(aNodo * actual){
    aNodo *tmp = actual;

    while (tmp->izq != NULL) {
        tmp = tmp->izq;
    }
    return tmp;
}

//*******RECORRIDOS*******
void Arbol::preOrden()
{
    FILE *fs = fopen("arbol.dot", "w+");
    fprintf(fs, "digraph G{ \n");
    preOrden(fs, raiz);
    fprintf(fs, "}");
    fclose(fs);

    system("dot -Tpng arbol.dot -o arbol.png");
}

void Arbol::preOrden(FILE *fs, aNodo *actual)
{
    if(actual != NULL)
    {
        if(actual->izq != NULL) fprintf(fs, "%s -> %s; \n", actual->info, actual->izq->info);
        if(actual->der != NULL) fprintf(fs, "%s -> %s; \n", actual->info, actual->der->info);
        preOrden(fs, actual->izq);
        preOrden(fs, actual->der);
    }
}

void Arbol::inOrden()
{
    cout << endl;
    cout << "*****Recorrido InOrden*****" << endl;
    inOrden(raiz);
    cout << "*****Fin Recorrido InOrden*****" << endl;
}

void Arbol::inOrden(aNodo *actual)
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

void Arbol::postOrden(aNodo *actual)
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

int Arbol::calcularAltura(aNodo * actual)
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

int Arbol::getNodosHoja(aNodo * actual)
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
