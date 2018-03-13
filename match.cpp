#include "match.h"

// - - RISULTATO MATCH - -
match::risultatoMatch::risultatoMatch(short int r):ris(r){
    if(ris != -1 && ris != 1 && ris != 2){
        ris =-1;
        throw(errore("Gli unici valori ammessi come risultato sono: 1 se il vincitore è il primo partecipante, 2 se il vincitore è il secondo partecipante o -1 se il match non si è ancora concluso"));
    }
}

match::risultatoMatch::operator short int() const{
    return ris;
}

//COSTRUTTORI
match::match(const partecipante& P1,const partecipante& P2,risultatoMatch r): p1(P1), p2(P2),risultato(r) {}

//GETTERS
const partecipante& match::getP1() const { return p1; }
const partecipante& match::getP2() const { return p2; }
const partecipante& match::getVincitore() const {
    if(risultato.ris == -1)
        throw(errore("Non c'è ancora un vincitore"));
    if(risultato.ris == 1)
        return p1;
    else
        return p2; //posso essere sicuro che ris non assuma valori diversi da 1,2 o -1 poichè il controllo di questo valore è fatto alla creazione di un oggetto risultatoMatch
}
const partecipante& match::getPerdente() const {
    if(risultato.ris == -1)
        throw(errore("Non c'è ancora un perdente"));
    if(risultato.ris == 2)
        return p1;
    else
        return p2; //posso essere sicuro che ris non assuma valori diversi da 1,2 o -1 poichè il controllo di questo valore è fatto alla creazione di un oggetto risultatoMatch
}
match::risultatoMatch match::getRisultato() const{
    return risultato;
}
bool match::finito() const{ return risultato.ris != -1; }
bool match::partecipa(const partecipante& p) const{
    return p1 == p || p2 == p; }
std::string match::toString() const{
    return p1.getNome()+" vs "+p2.getNome()+" - vincitore: "+(finito() ? ( getVincitore().getNome())  : "in corso");
}

//SETTERS
void match::setVincitore(risultatoMatch r){
    risultato.ris = r.ris;
}
