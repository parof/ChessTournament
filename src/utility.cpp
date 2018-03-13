#include "utility.h"

bool utility::isPotenzaDiDue(unsigned int n){
    return !(n == 0) && !(n & (n - 1));
}
int utility::prossimaPotenzaDiDue(int n){
    return pow(2,ceil(log2(n)));
}
int utility::prossimoEsponenteDiDue(int n){
    return ceil(log2(n));
}
std::string utility::toLower(const std::string& s){
    std::string copia = s;
    std::transform(copia.begin(),copia.end(),copia.begin(),::tolower);
    return copia;
}
