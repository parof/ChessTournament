#ifndef MATCH_H
#define MATCH_H
#include "errore.h"
#include "partecipante.h"

class match{
public:

    class risultatoMatch{ //astrazione del risultato
        friend class match;
    private:
        short int ris;
    public:
        risultatoMatch(short int r=-1); //unici valori ammessi: {1,2,-1}, può sollevare eccezione. funziona da convertitore di tipo
        operator short int() const;
    };

    //COSTRUTTORE
    match(const partecipante& P1,const partecipante& P2,risultatoMatch r = risultatoMatch());

    //GETTERS
    const partecipante& getP1() const;
    const partecipante& getP2() const;
    const partecipante& getVincitore() const; //può sollevare eccezione se la si chiama quando non c'è ancora un vincitore
    const partecipante& getPerdente() const; //può sollevare eccezione se la si chiama quando non c'è ancora un vincitore
    risultatoMatch getRisultato() const;
    bool finito() const;
    bool partecipa(const partecipante&) const;
    std::string toString() const;

    //SETTERS
    void setVincitore(risultatoMatch r);
private:
    const partecipante& p1;
    const partecipante& p2;
    risultatoMatch risultato;
};

#endif // MATCH_H
