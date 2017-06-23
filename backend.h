#ifndef BACKEND_H
#define BACKEND_H

#include <qpixmap.h>

class backend
{
public:
    backend();
    QPixmap getPieza(char * pieza, int color);
};

#endif // BACKEND_H
