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

std::vector<std::string> backend::explode(std::string& str, const char& ch) {
    std::string next;
    std::vector<std::string> result;

    // For each character in the string
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
         result.push_back(next);
    return result;
}
