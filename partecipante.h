#ifndef PARTECIPANTE_H
#define PARTECIPANTE_H
#include <string>

class partecipante{
private:
    std::string nome;
    unsigned int ELO;
public:
    //COSTRUTTORI
    partecipante(std::string n="",unsigned int e=0);

    //OPERATORI
    bool operator==(const partecipante&) const;
    bool operator<(const partecipante&) const;

    //GETTERS
    std::string getNome() const;
    unsigned int getElo() const;
    std::string toString() const;

    //SETTERS
    void setElo(unsigned int e);
};

#endif // PARTECIPANTE_H
