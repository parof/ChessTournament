#include "turno.h"

//MANIPOLAZIONE DEL TURNO DAL PUNTO DI VISTA DI UN VETTORE
void turno::aggiungiMatch(const match& m){ matches.push_back(m); }
const std::vector<match>& turno::getMatches() const{return matches;}

//FUNZIONI DI PIÙ ALTO LIVELLO
bool turno::siSonoScontrati(const partecipante& p1, const partecipante& p2) const{
    for(int i=0;i<matches.size();i++)
        if(matches[i].partecipa(p1) && matches[i].partecipa(p2)) //ho bisogno di questa segnatura per non avere una notazione posizionale
            return true;
    return false;
}

bool turno::finito() const{
    for(auto i = matches.begin();i!=matches.end();i++)
        if(!(i->finito()))
            return false;
    return true;
}

bool turno::partecipa(const partecipante& p) const{
    for(auto i = matches.begin();i != matches.end();i++)
        if(i->partecipa(p))
            return true;
    return false;
}
std::string turno::toString() const{
    std::string s="numero match: "+std::to_string(matches.size())+", finito: "+( finito() ? "Si" : "No")+"\n";
    for(int i=0;i<matches.size();i++){
        s+="\t"+matches[i].toString()+"\n";
    }
    return s;
}

void turno::copiaMatchImpostandoRisultatoNullo(const turno& copiaDaQui){
    matches.clear();
    const std::vector<match>& daCopiare = copiaDaQui.getMatches();
    for(size_t i = 0;i<daCopiare.size();i++){
        //per ogni match da copiare...
        match m=daCopiare[i];
        m.setVincitore(-1);
        matches.push_back(m);
    }
}
