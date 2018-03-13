#ifndef ERRORE_H
#define ERRORE_H
#include <string>

class errore{
private:
    std::string messaggio;
public:
    errore(std::string s);
    std::string getMessaggio() const;
};


#endif // ERRORE_H
