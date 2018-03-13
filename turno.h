#ifndef TURNO_H
#define TURNO_H
#include <vector>
#include "match.h"

class turno{
    friend class torneo;
private:
    std::vector<match> matches; //perchè vector e non list? a parte l'inserimento iniziale dei match non sono previste operazioni di inserimento e rimozione(sia in coda che in centro) e l'accesso casuale può essere effettuato
public:
    //PER INTERFACCIARSI AI MATCH
    void aggiungiMatch(const match&);
    const std::vector<match>& getMatches() const;
    void copiaMatchImpostandoRisultatoNullo(const turno& copiaDaQui); //copia i match del turno "copiaDaQui", senza però inserire i risultati

    //FUNZIONI DI INTERROGAZIONE
    bool siSonoScontrati(const partecipante&, const partecipante&) const;
    bool finito() const;
    bool partecipa(const partecipante&) const;
    std::string toString() const;

};

#endif // TURNO_H
