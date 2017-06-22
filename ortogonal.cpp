#include <ortogonal.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

Nodo::Nodo(int nivel, int fila, int columna, char * valor, int color)
{
    this->nivel = nivel;
    this->fila = fila;
    this->columna = columna;
    this->color = color;
    this->valor = valor;
    this->abajo = NULL;
    this->arriba = NULL;
    this->derecha = NULL;
    this->izquierda = NULL;
    this->enfrente = NULL;
    this->atras = NULL;
}

Encabezado::Encabezado(int id)
{
    this->id = id;
    this->siguiente = NULL;
    this->anterior = NULL;
    this->acceso = NULL;
}

void ListaEncabezados::insertar(Encabezado * nuevo)
{
    if(primero == NULL)
    {
       primero = nuevo;
    }
    else
    {
        if(nuevo->id < primero->id) //Inserción al inicio
        {
            nuevo->siguiente = primero;
            primero->anterior = nuevo;
            primero = nuevo;
        }
        else
        {
            Encabezado * actual = primero;
            while(actual->siguiente != NULL)
            {
                if(nuevo->id < actual->siguiente->id) //Inserción en el medio
                {
                    nuevo->siguiente = actual->siguiente;
                    actual->siguiente->anterior = nuevo;
                    nuevo->anterior = actual;
                    actual->siguiente = nuevo;
                    break;
                }

                actual = actual->siguiente;
            }

            if(actual->siguiente == NULL) //Inserción al final
            {
                actual->siguiente = nuevo;
                nuevo->anterior = actual;
            }
        }
    }
}

Encabezado * ListaEncabezados::getEncabezado(int id)
{
    Encabezado * actual = primero;
    while(actual != NULL)
    {
        if(actual->id == id)
        {
            return actual;
        }

        actual = actual->siguiente;
    }

    return NULL;
}

Nodo * Matriz::getFloor(int fila, int columna)
{
    Encabezado * eColumna = this->eColumnas->getEncabezado(columna);
    if(eColumna != NULL){
        Nodo * actual = eColumna->acceso;

        while (actual != NULL) {

            if(actual->fila == fila)
            {
                return actual;
            }

            actual = actual->abajo;
        }
    }

    return NULL;
}

Nodo * Matriz::getClosest(Nodo *floor, int nivel, int dir)
{
    Nodo * actual = floor;
    Nodo * tmp;
    if(dir == 1)
    {
        actual = actual->derecha;
        while (actual != NULL) {
            tmp = actual;

            while (tmp != NULL) {

                if(tmp->nivel == nivel){
                    return tmp;
                }

                tmp = tmp->enfrente;
            }

            actual = actual->derecha;
        }
    }
    else if(dir == 2)
    {
        actual = actual->izquierda;
        while (actual != NULL) {
            tmp = actual;

            while (tmp != NULL) {

                if(tmp->nivel == nivel) {
                    return tmp;
                }

                tmp = tmp->enfrente;
            }

            actual = actual->izquierda;
        }
    }
    else if(dir == 3)
    {
        actual = actual->arriba;
        while (actual != NULL) {
            tmp = actual;

            while (tmp != NULL) {

                if(tmp->nivel == nivel) {
                    return tmp;
                }

                tmp = tmp->enfrente;
            }

            actual = actual->arriba;
        }
    }
    else if(dir == 4)
    {
        actual = actual->abajo;
        while (actual != NULL) {
            tmp = actual;

            while (tmp != NULL) {

                if(tmp->nivel == nivel) {
                    return tmp;
                }

                tmp = tmp->enfrente;
            }

            actual = actual->abajo;
        }
    }

    return NULL;
}

Matriz::Matriz()
{
    this->eFilas = new ListaEncabezados();
    this->eColumnas = new ListaEncabezados();
    this->eNiveles = new ListaEncabezados();

    this->insertar(0, 1, 1, "C", 0);
    this->insertar(0, 1, 2, "A", 0);
    this->insertar(0, 1, 3, "T", 0);
    this->insertar(0, 1, 4, "D", 0);
    this->insertar(0, 1, 5, "R", 0);
    this->insertar(0, 1, 6, "T", 0);
    this->insertar(0, 1, 7, "A", 0);
    this->insertar(0, 1, 8, "C", 0);

    this->insertar(0, 2, 1, "P", 0);
    this->insertar(0, 2, 2, "P", 0);
    this->insertar(0, 2, 3, "P", 0);
    this->insertar(0, 2, 4, "P", 0);
    this->insertar(0, 2, 5, "P", 0);
    this->insertar(0, 2, 6, "P", 0);
    this->insertar(0, 2, 7, "P", 0);
    this->insertar(0, 2, 8, "P", 0);

    this->insertar(0, 7, 1, "P", 1);
    this->insertar(0, 7, 2, "P", 1);
    this->insertar(0, 7, 3, "P", 1);
    this->insertar(0, 7, 4, "P", 1);
    this->insertar(0, 7, 5, "P", 1);
    this->insertar(0, 7, 6, "P", 1);
    this->insertar(0, 7, 7, "P", 1);
    this->insertar(0, 7, 8, "P", 1);

    this->insertar(0, 8, 1, "C", 1);
    this->insertar(0, 8, 2, "A", 1);
    this->insertar(0, 8, 3, "T", 1);
    this->insertar(0, 8, 4, "D", 1);
    this->insertar(0, 8, 5, "R", 1);
    this->insertar(0, 8, 6, "T", 1);
    this->insertar(0, 8, 7, "A", 1);
    this->insertar(0, 8, 8, "C", 1);

    this->insertar(1, 1, 6, "T", 0);
    this->insertar(1, 1, 7, "A", 0);
    this->insertar(1, 1, 8, "C", 0);

    this->insertar(1, 2, 6, "P", 0);
    this->insertar(1, 2, 7, "P", 0);
    this->insertar(1, 2, 8, "P", 0);

    this->insertar(1, 7, 1, "P", 1);
    this->insertar(1, 7, 2, "P", 1);
    this->insertar(1, 7, 3, "P", 1);

    this->insertar(1, 8, 1, "C", 1);
    this->insertar(1, 8, 2, "A", 1);
    this->insertar(1, 8, 3, "T", 1);

    this->insertar(2, 1, 1, "C", 0);
    this->insertar(2, 1, 2, "A", 0);
    this->insertar(2, 1, 3, "T", 0);

    this->insertar(2, 2, 1, "P", 0);
    this->insertar(2, 2, 2, "P", 0);
    this->insertar(2, 2, 3, "P", 0);

    this->insertar(2, 7, 6, "P", 1);
    this->insertar(2, 7, 7, "P", 1);
    this->insertar(2, 7, 8, "P", 1);

    this->insertar(2, 8, 6, "T", 1);
    this->insertar(2, 8, 7, "A", 1);
    this->insertar(2, 8, 8, "C", 1);

}

void Matriz::insertar(int nivel, int fila, int columna, char * valor, int color)
{
    Nodo * nuevo = new Nodo(nivel, fila, columna, valor, color);

    if(nivel == 0)
    {
        //INSERCION_FILAS
        Encabezado * eFila = eFilas->getEncabezado(fila);
        if(eFila == NULL) //Si no existe encabezado se crea.
        {
            eFila = new Encabezado(fila);
            eFilas->insertar(eFila);
            eFila->acceso = nuevo;
        }
        else
        {
            if(nuevo->columna < eFila->acceso->columna) //Inserción al inicio
            {
                nuevo->derecha = eFila->acceso;
                eFila->acceso->izquierda = nuevo;
                eFila->acceso = nuevo;
            }
            else
            {
                Nodo * actual = eFila->acceso;
                while(actual->derecha != NULL)
                {
                    if(nuevo->columna < actual->derecha->columna) //Inserción en el medio
                    {
                        nuevo->derecha = actual->derecha;
                        actual->derecha->izquierda = nuevo;
                        nuevo->izquierda = actual;
                        actual->derecha = nuevo;
                        break;
                    }

                    actual = actual->derecha;
                }

                if(actual->derecha == NULL) //Inserción al final
                {
                    actual->derecha = nuevo;
                    nuevo->izquierda = actual;
                }
            }
        }
        //FIN_FILAS

        //INSERCION_COLUMNAS
        Encabezado * eColumna = eColumnas->getEncabezado(columna);
        if(eColumna == NULL) //Si no existe encabezado se crea.
        {
            eColumna = new Encabezado(columna);
            eColumnas->insertar(eColumna);
            eColumna->acceso = nuevo;
        }
        else
        {
            if(nuevo->fila < eColumna->acceso->fila) //Inserción al inicio
            {
                nuevo->abajo = eColumna->acceso;
                eColumna->acceso->arriba = nuevo;
                eColumna->acceso = nuevo;
            }
            else
            {
                Nodo * actual = eColumna->acceso;
                while(actual->abajo != NULL)
                {
                    if(nuevo->fila < actual->abajo->fila) //Inserción en el medio
                    {
                        nuevo->abajo = actual->abajo;
                        actual->abajo->arriba = nuevo;
                        nuevo->arriba = actual;
                        actual->abajo = nuevo;
                        break;
                    }

                    actual = actual->abajo;
                }

                if(actual->abajo == NULL) //Inserción al final
                {
                    actual->abajo = nuevo;
                    nuevo->arriba = actual;
                }
            }
        }
        //FIN_COLUMNAS
    }
    else
    {
        Nodo * floor = this->getFloor(fila, columna);
        if(floor == NULL) //Insercion al inicio
        {
            this->insertar(0, fila, columna, "", 0);
            floor = this->getFloor(fila, columna);
        }

        Nodo * actual = floor;
        while (actual->enfrente != NULL)
        {
            if(nuevo->nivel < actual->enfrente->nivel) //Insercion en el medio
            {
                nuevo->enfrente = actual->enfrente;
                actual->enfrente->atras = nuevo;
                nuevo->atras = actual;
                actual->enfrente = nuevo;

                Nodo * tmp = this->getClosest(floor, nivel, 1);
                nuevo->derecha = tmp;
                if(tmp != NULL) tmp->izquierda = nuevo;

                tmp = this->getClosest(floor, nivel, 2);
                nuevo->izquierda = tmp;
                if(tmp != NULL) tmp->derecha = nuevo;

                tmp = this->getClosest(floor, nivel, 3);
                nuevo->arriba = tmp;
                if(tmp != NULL) tmp->abajo = nuevo;

                tmp = this->getClosest(floor, nivel, 4);
                nuevo->abajo = tmp;
                if(tmp != NULL) tmp->arriba = nuevo;
                break;
            }

            actual = actual->enfrente;
        }

        if(actual->enfrente == NULL)
        {
            actual->enfrente = nuevo;
            nuevo->atras = actual;

            Nodo * tmp = this->getClosest(floor, nivel, 1);
            nuevo->derecha = tmp;
            if(tmp != NULL) tmp->izquierda = nuevo;

            tmp = this->getClosest(floor, nivel, 2);
            nuevo->izquierda = tmp;
            if(tmp != NULL) tmp->derecha = nuevo;

            tmp = this->getClosest(floor, nivel, 3);
            nuevo->arriba = tmp;
            if(tmp != NULL) tmp->abajo = nuevo;

            tmp = this->getClosest(floor, nivel, 4);
            nuevo->abajo = tmp;
            if(tmp != NULL) tmp->arriba = nuevo;
        }

    }
}

void Matriz::recorrerFilas()
{
    Encabezado * eFila = eFilas->primero;
    cout << "Recorrido Por Filas: ";

    while(eFila != NULL)
    {
        Nodo * actual = eFila->acceso;
        while(actual != NULL)
        {
            cout << actual->valor;

            if(eFila->siguiente != NULL || actual->derecha != NULL)
            {
                cout << "->";
            }


            actual = actual->derecha;
        }

        eFila = eFila->siguiente;
    }

    cout << endl;
}

void Matriz::recorrerColumnas()
{
    Encabezado * eColumna = eColumnas->primero;
    cout << "Recorrido Por Columnas: ";

    while(eColumna != NULL)
    {
        Nodo * actual = eColumna->acceso;
        while(actual != NULL)
        {
            cout << actual->valor;

            if(eColumna->siguiente != NULL || actual->abajo != NULL)
            {
                cout << "->";
            }

            actual = actual->abajo;
        }

        eColumna = eColumna->siguiente;
    }

    cout << endl;
}

void Matriz::recorrerNiveles()
{
    Encabezado * eColumna = eColumnas->primero;
    cout << "Recorrido por Columnas por niveles: " << endl;

        Nodo * actual = eColumna->acceso;
        while(eColumna != NULL)
        {

            while(actual != NULL)
            {
                cout << actual->valor;

                if(eColumna->siguiente != NULL || actual->abajo != NULL)
                {
                    cout << "->";
                }

                actual = actual->abajo;
            }

            eColumna = eColumna->siguiente;
        }
}


