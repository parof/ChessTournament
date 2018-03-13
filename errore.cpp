#include "errore.h"

errore::errore(std::string s) : messaggio(s) {}
std::string errore::getMessaggio() const{ return messaggio; }
