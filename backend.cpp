#include "backend.h"
#include <qpixmap.h>
#include <stdio.h>
#include <string.h>

backend::backend()
{

}

QPixmap backend::getPieza(char *pieza, int color)
{
    if(strcmp(pieza, "R") == 0){
        if(color == 0) return QPixmap("../res/img/R0.png");
        if(color == 1) return QPixmap("../res/img/R1.png");
    }else if(strcmp(pieza, "D") == 0){
        if(color == 0) return QPixmap("../res/img/D0.png");
        if(color == 1) return QPixmap("../res/img/D1.png");
    }else if(strcmp(pieza, "C") == 0){
        if(color == 0) return QPixmap("../res/img/C0.png");
        if(color == 1) return QPixmap("../res/img/C1.png");
    }else if(strcmp(pieza, "T") == 0){
        if(color == 0) return QPixmap("../res/img/T0.png");
        if(color == 1) return QPixmap("../res/img/T1.png");
    }else if(strcmp(pieza, "A") == 0){
        if(color == 0) return QPixmap("../res/img/A0.png");
        if(color == 1) return QPixmap("../res/img/A1.png");
    }else if(strcmp(pieza, "P") == 0){
        if(color == 0) return QPixmap("../res/img/P0.png");
        if(color == 1) return QPixmap("../res/img/P1.png");
    }

}
