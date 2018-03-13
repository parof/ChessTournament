#include "partecipante.h"

//COSTRUTTORI
partecipante::partecipante(std::string n,unsigned int e) : nome(n), ELO(e){}

//OPERATORI
bool partecipante::operator ==(const partecipante& p) const{
    return nome==p.nome && ELO==p.ELO;}
bool partecipante::operator<(const partecipante& p) const{
    return ELO < p.ELO;}

//GETTERS
std::string partecipante::getNome() const{ return nome; }
unsigned int partecipante::getElo() const {return ELO; }
std::string partecipante::toString() const{
    return ">Nome: "+nome+" \tELO: "+std::to_string(ELO);
}

//SETTERS
void partecipante::setElo(unsigned int e) {ELO=e; }
