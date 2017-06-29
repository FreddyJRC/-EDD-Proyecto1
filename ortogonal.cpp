#include <ortogonal.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

Nodo::Nodo(int nivel, int fila, int columna, char * valor, int color)
{
    this->nivel = nivel;
    this->fila = fila;
    this->columna = columna;
    this->color = color;
    this->valor = valor;
    this->isDrawable = true;
    this->abajo = NULL;
    this->arriba = NULL;
    this->derecha = NULL;
    this->izquierda = NULL;
    this->enfrente = NULL;
    this->atras = NULL;
}

Nodo* Nodo::hasMached()
{
    if(this->enfrente != NULL){
        if(strcmp(this->enfrente->valor, this->valor) == 0){
            return this->enfrente;
        } else if(this->enfrente->enfrente != NULL){
            if(strcmp(this->enfrente->enfrente->valor, this->valor) == 0){
                return this->enfrente->enfrente;
            }
        }
    } else if(this->atras != NULL){
        if(strcmp(this->atras->valor, this->valor) == 0){
            return this->atras;
        } else if(this->atras->atras != NULL){
            if(strcmp(this->atras->atras->valor, this->valor) == 0){
                return this->atras->atras;
            }
        }
    }

    return NULL;
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

Nodo *Matriz::findNodo(int nivel, int fila, int columna)
{
    Encabezado * eColumna = this->eColumnas->getEncabezado(columna);
    if(eColumna != NULL){
        Nodo * actual = eColumna->acceso, *tmp;

        while (actual != NULL) {

            if(actual->fila == fila)
            {
                if(nivel == 0)
                    return actual;
                else{
                    tmp = actual;
                    while (tmp != NULL) {
                        if(tmp->nivel == nivel)
                            return tmp;
                        tmp = tmp->enfrente;
                    }
                }
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
            floor->isDrawable = false;
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

void Matriz::eliminar(Nodo *actual)
{
    if(actual->nivel == 0 && actual->enfrente != NULL){
        actual->valor = "";
        actual->color = 0;
        actual->isDrawable = false;
    } else {
        if(actual->nivel == 0){
            if(actual->derecha == NULL && actual->izquierda == NULL){
                Encabezado *fila = this->eFilas->getEncabezado(actual->fila);

                if(fila->anterior == NULL){
                    this->eFilas->primero = fila->siguiente;
                    fila->siguiente->anterior = NULL;
                }else{
                    fila->anterior->siguiente = fila->siguiente;
                    if(fila->siguiente != NULL) fila->siguiente->anterior = fila->anterior;
                }
                free(fila);
            }

            if(actual->abajo == NULL && actual->arriba == NULL){
                Encabezado * columna = this->eColumnas->getEncabezado(actual->columna);

                if(columna->anterior == NULL){
                    this->eColumnas->primero = columna->siguiente;
                    columna->siguiente->anterior = NULL;
                } else {
                    columna->anterior->siguiente = columna->siguiente;
                    if(columna->siguiente != NULL) columna->siguiente->anterior = columna->anterior;
                }
                free(columna);
            }
        }

        if(actual->derecha != NULL)
            actual->derecha->izquierda = actual->izquierda;

        if(actual->izquierda != NULL)
            actual->izquierda->derecha = actual->derecha;

        if(actual->abajo != NULL)
            actual->abajo->arriba = actual->arriba;

        if(actual->arriba != NULL)
            actual->arriba->abajo = actual->abajo;

        if(actual->nivel != 0){
            Nodo * floor = this->getFloor(actual->fila, actual->columna);

            if(actual->atras == floor && !floor->isDrawable && actual->enfrente == NULL)
                this->eliminar(floor);
            else {
                if(actual->atras != NULL)
                    actual->atras->enfrente = actual->enfrente;
            }
        }

        if(actual->enfrente != NULL)
            actual->enfrente->atras = actual->atras;

        free(actual);
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

void Matriz::graficar(int nivel)
{
    FILE *fs = fopen("matriz.dot", "w+");
    Encabezado *tmp;
    fprintf(fs, "digraph G{ \n node[shape=box]; \n rankdir=UD; \n");

    if(nivel == 0){
        fprintf(fs, "{rank=min;\"matriz\";");
        tmp = this->eColumnas->primero;
        while (tmp != NULL){
            fprintf(fs, "\"x%d\";", tmp->id);
            tmp = tmp->siguiente;
        }
        fprintf(fs, "}; \n");
    }

    tmp = this->eFilas->primero;
    while (tmp != NULL) {
        (nivel == 0) ? fprintf(fs, "{rank=same;\"y%d\";", tmp->id) : fprintf(fs, "{");
        Nodo * actual = tmp->acceso;
        while (actual != NULL) {
            if(nivel == 0){
                if(actual->isDrawable) fprintf(fs, "\"pieza: %s \\n color: %d \\n xy: %d%d\";", actual->valor, actual->color, actual->columna, actual->fila);
            }else{
                Nodo *tmp1 = actual;
                while (tmp1 != NULL) {
                    if(tmp1->nivel == nivel) fprintf(fs, "\"pieza: %s \\n color: %d \\n xy: %d%d\";", tmp1->valor, tmp1->color, actual->columna, actual->fila);
                    tmp1 = tmp1->enfrente;
                }
            }
            actual = actual->derecha;
        }
        fprintf(fs, "}; \n");
        tmp = tmp->siguiente;
    }


    tmp = this->eColumnas->primero;
    while (tmp != NULL) {
        Nodo * actual = tmp->acceso;

        if(nivel == 0){
            if(actual->isDrawable) fprintf(fs, "\"pieza: %s \\n color: %d \\n xy: %d%d\"", actual->valor, actual->color, actual->columna, actual->fila);
        }else{
            Nodo *tmp1 = actual;
            while (tmp1 != NULL) {
                if(tmp1->nivel == nivel) {
                    fprintf(fs, "\"pieza: %s \\n color: %d \\n xy: %d%d\"", tmp1->valor, tmp1->color, actual->columna, actual->fila);
                    break;
                }
                tmp1 = tmp1->enfrente;
            }
            if(tmp1 == NULL) fprintf(fs, "\" \"");
        }
        actual = actual->abajo;

        while (actual != NULL) {
            if(nivel == 0){
                if(actual->isDrawable) fprintf(fs, " -> \"pieza: %s \\n color: %d \\n xy: %d%d\"", actual->valor, actual->color, actual->columna, actual->fila);
            }else{
                Nodo *tmp1 = actual;
                while (tmp1 != NULL) {
                    if(tmp1->nivel == nivel) fprintf(fs, " -> \"pieza: %s \\n color: %d \\n xy: %d%d\"", tmp1->valor, tmp1->color, actual->columna, actual->fila);
                    tmp1 = tmp1->enfrente;
                }
            }
            actual = actual->abajo;
        }
        fprintf(fs, "[dir=both]; \n");
        tmp = tmp->siguiente;
    }


    if(nivel == 0) {
        tmp = this->eColumnas->primero;
        while (tmp != NULL) {
            fprintf(fs, "\"x%d\"", tmp->id);
            Nodo * actual = tmp->acceso;

            while (actual != NULL) {
                if(actual->isDrawable){
                    fprintf(fs, "-> \"pieza: %s \\n color: %d \\n xy: %d%d\"; \n", actual->valor, actual->color, actual->columna, actual->fila);
                    break;
                }
                actual = actual->abajo;
            }
            tmp = tmp->siguiente;
        }
    }


    tmp = this->eFilas->primero;
    while (tmp != NULL) {
        Nodo * actual = tmp->acceso;

        if(nivel == 0){
            if(actual->isDrawable) fprintf(fs, "\"pieza: %s \\n color: %d \\n xy: %d%d\"", actual->valor, actual->color, actual->columna, actual->fila);
        }else{
            Nodo *tmp1 = actual;
            while (tmp1 != NULL) {
                if(tmp1->nivel == nivel){
                    fprintf(fs, "\"pieza: %s \\n color: %d \\n xy: %d%d\"", tmp1->valor, tmp1->color, actual->columna, actual->fila);
                    break;
                }
                tmp1 = tmp1->enfrente;
            }
            if(tmp1 == NULL) fprintf(fs, "\" \"");
        }
        actual = actual->derecha;

        while (actual != NULL) {
            if(nivel == 0){
                if(actual->isDrawable) fprintf(fs, " -> \"pieza: %s \\n color: %d \\n xy: %d%d\"", actual->valor, actual->color, actual->columna, actual->fila);
            }else{
                Nodo *tmp1 = actual;
                while (tmp1 != NULL) {
                    if(tmp1->nivel == nivel) fprintf(fs, " -> \"pieza: %s \\n color: %d \\n xy: %d%d\"", tmp1->valor, tmp1->color, actual->columna, actual->fila);
                    tmp1 = tmp1->enfrente;
                }
            }
            actual = actual->derecha;
        }
        fprintf(fs, "[constraint=false, dir=both]; \n");
        tmp = tmp->siguiente;
    }


    if(nivel == 0){
        tmp = this->eFilas->primero;
        while (tmp != NULL) {
            fprintf(fs, "\"y%d\"", tmp->id);
            Nodo * actual = tmp->acceso;

            while (actual != NULL) {
                if(actual->isDrawable){
                    fprintf(fs, "-> \"pieza: %s \\n color: %d \\n xy: %d%d\"; \n", actual->valor, actual->color, actual->columna, actual->fila);
                    break;
                }
                actual = actual->abajo;
            }
            tmp = tmp->siguiente;
        }
    }


    if(nivel == 0){
        tmp = this->eColumnas->primero;
        fprintf(fs, "\"matriz\" -> \"x%d\" ", tmp->id);
        while (tmp != NULL) {
            fprintf(fs, "-> \"x%d\" ", tmp->id);
            tmp = tmp->siguiente;
        }
        fprintf(fs, "; \n");

        tmp = this->eFilas->primero;
        fprintf(fs, "\"matriz\" -> \"y%d\" ", tmp->id);
        while (tmp != NULL) {
            fprintf(fs, "-> \"y%d\" ", tmp->id);
            tmp = tmp->siguiente;
        }
        fprintf(fs, "[rankdir=UD]; \n");
    }
    fprintf(fs, "}");
    fclose(fs);

    system("dot -Tpng matriz.dot -o matriz.png");
}

void Matriz::mover(std::vector<std::string> move, int turn)
{
    int fila = idToInt(move[2][0]);
    int columna = (move[2][1] - '0');
    int nivel = stoi(move[1]);

    Nodo *tmp, *tmp1, *objetivo, *floor;

    if(move[0].compare("P") == 0){
        objetivo = this->findNodo(nivel, fila, columna);
        tmp = (turn == 0) ? findNodo(nivel, fila - 1, columna) : findNodo(nivel, fila + 1, columna);
        if(tmp != NULL){
            if(strcmp(tmp->valor, "P") == 0 && tmp->color == turn){
                if(objetivo == NULL){
                    this->eliminar(tmp);
                    insertar(nivel, fila, columna, "P", turn);
                    return;
                }
            }
        } else {
            if(objetivo != NULL && objetivo->color != turn){
                tmp = (turn == 0) ? findNodo(nivel, fila +1, columna +1) : findNodo(nivel, fila -1, columna+1);
                if(tmp == NULL) tmp = (turn == 0) ? findNodo(nivel, fila +1, columna -1) : findNodo(nivel, fila -1, columna -1);
                if(tmp != NULL && strcmp(tmp->valor, "P") == 0 && tmp->color == turn) {
                    objetivo->valor = tmp->valor;
                    objetivo->color = tmp->color;
                    this->eliminar(tmp);
                    return;
                }
            } else {
                tmp = (turn == 0) ? findNodo(nivel, fila -1, columna +1) : findNodo(nivel, fila +1, columna+1);
                if(tmp == NULL) tmp = (turn == 0) ? findNodo(nivel, fila -1, columna -1) : findNodo(nivel, fila +1, columna -1);
                if(tmp != NULL && strcmp(tmp->valor, "P") == 0 && tmp->color == turn) {
                    bool posInicial = false;
                    posInicial = ((tmp->color == 0) && (tmp->fila == 2)) ? true : false;
                    posInicial = ((tmp->color == 1) && (tmp->fila == 7)) ? true : false;
                    if(tmp->hasMached() != NULL && !posInicial){
                        this->eliminar(tmp);
                        insertar(nivel, fila, columna, "P", turn);
                        return;
                    }
                }
            }
        }
    } else if(move[0].compare("A") == 0) {
        objetivo = this->findNodo(nivel, fila, columna);
        if(objetivo == NULL){
            this->insertar(nivel, fila, columna, "A", turn);
            objetivo = this->findNodo(nivel, fila, columna);
        }

        if(nivel != 0) floor = this->getFloor(fila, columna);
        else floor = objetivo;

        tmp = this->getClosest(floor, nivel, 1);
        if(tmp == NULL) tmp = this->getClosest(floor, nivel, 2);
        if(tmp == NULL) tmp = this->getClosest(floor, nivel, 3);
        if(tmp == NULL) tmp = this->getClosest(floor, nivel, 4);

        if(tmp != NULL && strcmp(tmp->valor, "A") == 0 && tmp->color == turn){
            if(objetivo->color == turn){
                objetivo->valor = tmp->valor;
                objetivo->color = tmp->color;
                this->eliminar(tmp);
                return;
            }else{
                this->eliminar(tmp);
                return;
            }
        } else {
            this->insertar(nivel, fila, columna, "A", turn);
            objetivo = this->findNodo(nivel, columna, fila);
            tmp = objetivo->hasMached();
            if(tmp != NULL){
                int i = 1;
                while (tmp->fila - i > 0 || tmp->columna > 0) {
                    tmp1 = this->findNodo(tmp->nivel, tmp->fila - i, tmp->columna - i);
                    if(tmp1 != NULL && strcmp(tmp1->valor, "A") == 0 && tmp1->color == turn){
                        this->eliminar(tmp);
                        return;
                    }
                    ++i;
                }
                i = 1;
                while (tmp->fila + i <= 8 || tmp->columna <= 8) {
                    tmp1 = this->findNodo(tmp->nivel, tmp->fila + i, tmp->columna + i);
                    if(tmp1 != NULL && strcmp(tmp1->valor, "A") == 0 && tmp1->color == turn){
                        this->eliminar(tmp);
                        return;
                    }
                    ++i;
                }
            } else {
                this->eliminar(objetivo);
                return;
            }
        }
    }
}



int idToInt(char id)
{
    if(id == 'A')
        return 8;
    else if(id == 'B')
        return 7;
    else if(id == 'C')
        return 6;
    else if(id == 'D')
        return 5;
    else if(id == 'E')
        return 4;
    else if(id == 'F')
        return 3;
    else if(id == 'G')
        return 2;
    else if(id == 'H')
        return 1;

    return 0;
}
