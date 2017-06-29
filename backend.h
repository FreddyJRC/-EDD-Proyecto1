#ifndef BACKEND_H
#define BACKEND_H

#include <qpixmap.h>

class backend
{
public:
    backend();
    QPixmap getPieza(char * pieza, int color);
    std::vector<std::string> explode(std::string& str, const char& ch);
};

#endif // BACKEND_H
