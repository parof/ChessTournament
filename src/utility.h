#ifndef UTILITY_H
#define UTILITY_H
#include <string>
#include <algorithm>
#include "math.h"

namespace utility{
    bool isPotenzaDiDue(unsigned int n);
    int prossimaPotenzaDiDue(int n);
    int prossimoEsponenteDiDue(int n);
    std::string toLower(const std::string& ); //ritorna una copia della stringa però al lowercase
}

#endif // UTILITY_H
