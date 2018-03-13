#include "utente.h"
#include "c.h"
#include <iostream>

const short int utente::basic=1;
const short int utente::pro=2;
const short int utente::admin=3;
const std::string utente::descrizioneBasic="È permesso cercare tornei che si svolgono a nel proprio luogo filtrati per nome. È possibile anche creare e modificare i propri tornei.";
const std::string utente::descrizionePro="È permesso cercare tornei che si svolgono in qualsiasi luogo filtrati per nome,luogo e punteggio ELO minimo. È possibile anche creare e modificare i propri tornei.";
const std::string utente::descrizioneAdmin="È permesso cercare tornei che si svolgono in qualsiasi luogo filtrati per nome,luogo e punteggio ELO minimo. È possibile anche creare e modificare i tornei di tutti gli utenti.";


//UTENTE
utente::utente(const C &c, std::string un, std::string p, std::string l) : contenitore(c), username(un), passw(p),luogo(l) {}
utente::~utente() {}
bool utente::operator ==(const utente& u) const{
    return (username == u.username) && (luogo == u.luogo) && (passw == u.passw);
}
std::string utente::getUsername() const{ return username; }
std::string utente::getLuogo() const{ return luogo; }
std::string utente::getPassword() const{ return passw; }
bool utente::sonoIo(std::string u,std::string p) const{ return u==username && p==passw; }

utente* utente::leggiDaInput(std::istream& i,const  C &c){
    if(!i)
        return nullptr;
    utente* ret = nullptr;
    int tipo=0;
    i>>tipo;
    i.seekg(std::ios::cur - 1);
    switch (tipo) {
    case utente::basic:
        ret = new utenteBasic(c);
        break;
    case utente::pro:
        ret = new utentePro(c);
        break;
    case utente::admin:
        ret = new utenteAdmin(c);
        break;
    default:
        break;
    }

    i >> *ret;
    if(!i)
        return nullptr;
    return ret;
}

bool utente::modificaPassword(std::string nuovaPassword){
    std::string vecchia = passw;
    passw = nuovaPassword;
    if(contenitore.salvaModificheUtente(this))
        return true;
    else{
        passw=vecchia;
        return false;
    }
}

bool utente::modificaLuogo(std::string nuovoLuogo){
    std::string vecchio = luogo;
    luogo = nuovoLuogo;
    if(contenitore.salvaModificheUtente(this))
        return true;
    else{
        luogo = vecchio;
        return false;
    }
}

//UTENTE BASIC
utenteBasic::utenteBasic(const C &c, std::string un, std::string p, std::string l) : utente(c,un,p,l){}
permesso utenteBasic::chiediPermesso(const torneo* t,std::string creatore) const{
    if(creatore == getUsername())
        return permesso(permesso::mod);
    if(t->getLuogoTorneo() == getLuogo())
        return permesso(permesso::vis);
    //se non è stato creato dall utente e nemmeno si è svolto nel luogo dell'utente il torneo non puòessere visualizzato
    return permesso(permesso::nvis);
}
bool utenteBasic::rispettaParametriRicerca(const torneo* t, std::string nomeT,std::string luogoT,unsigned int puntiMin) const{
    if(t == nullptr)
        //nulla in cui cercare
        return false;
    if(nomeT == "") //è stata cercata una stringa vuota, si assume che l utente voglia cercare tutti tornei visualizzabili da lui
        return true;
    funtoreRicerca f(1); //ricerca per nome
    return f(t,nomeT);
}
short int utenteBasic::tipo() const{ return utente::basic;}
std::string utenteBasic::tipologiaTestuale() const{ return "Basic"; }
std::string utenteBasic::descrizioneTipologia() const{
    return utente::descrizioneBasic;
}

//UTENTE RICERCA AVANZATA
utenteRicercaAvanzata::utenteRicercaAvanzata(const C& c, std::string un, std::string p, std::string l): utente(c,un,p,l) {}
bool utenteRicercaAvanzata::rispettaParametriRicerca(const torneo* t, std::string nomeT,std::string luogoT,unsigned int puntiMin) const{
    if((nomeT=="") && (luogoT=="") && (puntiMin==0))
        //non è stato settato alcun parametro e quindi si assumete che all'utente vada bene qualsiasi torneo
        return true;
    //almeno uno edi tre parametri non è nullo
    int tipo_ricerca = 0;
    if((nomeT != "") && (luogoT=="") && (puntiMin==0))
        //quello settato non nullo è il nome del torneo
        tipo_ricerca = 1;
    if((nomeT=="") && (luogoT != "") && (puntiMin==0))
        //quello settato non nullo è il luogo
        tipo_ricerca = 2;
    if((nomeT=="") && (luogoT=="") && (puntiMin != 0))
        //si desiderano tornei da un certo punteggio in su
        tipo_ricerca = 3;
    if((nomeT!="") && (luogoT != "") && (puntiMin==0))
        tipo_ricerca = 4;
    if((nomeT!="") && (luogoT == "") && (puntiMin!=0))
        tipo_ricerca = 5;
    if((nomeT=="") && (luogoT != "") && (puntiMin!=0))
        tipo_ricerca = 6;
    if((nomeT != "") && (luogoT != "") && (puntiMin!=0))
        tipo_ricerca = 7;
    funtoreRicerca f(tipo_ricerca);
    return f(t,nomeT,luogoT,puntiMin);
}

//UTENTE PRO
utentePro::utentePro(const C &c, std::string un, std::string p, std::string l):utenteRicercaAvanzata(c,un,p,l){}
permesso utentePro::chiediPermesso(const torneo*t,std::string creatore) const{
    if(creatore == getUsername())
        return permesso(permesso::mod);
    return permesso(permesso::vis);
}
short int utentePro::tipo() const{ return utente::pro;}
std::string utentePro::tipologiaTestuale() const{ return "Pro"; }
std::string utentePro::descrizioneTipologia() const{
    return utente::descrizionePro;
}

//UTENTE ADMIN
utenteAdmin::utenteAdmin(const C &c, std::string un, std::string p, std::string l):utenteRicercaAvanzata(c,un,p,l){}
permesso utenteAdmin::chiediPermesso(const torneo*t,std::string creatore) const{
    return permesso(permesso::mod);
}
short int utenteAdmin::tipo() const{ return utente::admin;}
std::string utenteAdmin::tipologiaTestuale() const{ return "Admin"; }
std::string utenteAdmin::descrizioneTipologia() const{
    return utente::descrizioneBasic;
}

//FUNTORE RICERCA
utente::funtoreRicerca::funtoreRicerca(int x) : tipoRicerca(x) {}
bool utente::funtoreRicerca::operator() (const torneo* t, std::string nomeT,std::string luogoT,unsigned int puntiMin) const {
    if(t == nullptr)
        return false;

    //porto tutte le stringhe che devo manipolare al caso minuscolo poichè probabilmente per un utente Torneo == torneo

    nomeT = utility::toLower(nomeT);
    luogoT = utility::toLower(luogoT);

    std::string nomeEffettivo = utility::toLower(t->getNomeTorneo());
    std::string luogoEffettivo = utility::toLower(t->getLuogoTorneo());

    switch(tipoRicerca) {
        case 1: //cerco solo per nome, l unica accessibile agli utenti basic
            return nomeEffettivo.find(nomeT) != std::string::npos;
        case 2: //cerco solo per luogo
            return luogoEffettivo.find(luogoT) != std::string::npos;
        case 3: //cerco solo per punteggio
            return t->getPunteggioMinimo() >= puntiMin;
        case 4: //cerco per nome e luogo
            return (nomeEffettivo.find(nomeT) != std::string::npos) && (luogoEffettivo.find(luogoT) != std::string::npos);
        case 5: //cerco per nome e punteggio
            return (nomeEffettivo.find(nomeT) != std::string::npos) && (t->getPunteggioMinimo() >= puntiMin);
        case 6: //cerco per luogo e punteggio
            return (luogoEffettivo.find(luogoT) != std::string::npos) && (t->getPunteggioMinimo() >= puntiMin);
        case 7: //cerco per nome,luogo e punteggio
            return (nomeEffettivo.find(nomeT) != std::string::npos) && (luogoEffettivo.find(luogoT) != std::string::npos) && (t->getPunteggioMinimo() >= puntiMin);
        default:
            return true;
    }
}

//PERMESSO
const short int permesso::nvis=0;
const short int permesso::vis=1;
const short int permesso::mod=2;

permesso::permesso(short int t) : tipo(t){
    if(tipo != nvis && tipo != vis && tipo != mod){
        tipo = 0;
        throw(errore("Permesso creato con un valore errato"));
    }
}

bool permesso::operator ==(const permesso& p) const{
    return tipo == p.tipo;
}

//FUNZIONI AMICHE
std::ostream& operator <<(std::ostream& o,const utente& u){
    o<<u.tipo()<<"\n";
    o<<u.username<<"\n";
    o<<u.passw<<"\n";
    o<<u.luogo;
    return o;
}
std::istream& operator >>(std::istream& i,utente& u){
    using namespace std;
    if(!i)
        return i;
    int tipo =0;
    std::string t;
    std::getline(i,t);
    try{
        tipo = std::stoi(t);
    } catch(...){
        i.clear(std::ios::failbit);
        return i;
    }
    if(!i || tipo != u.tipo()){
        //stai cercando di mettere in un sottotipo sbagliato
        i.clear(std::ios::failbit);
        return i;
    }

    std::string us;
    std::getline(i,us);
    if(!i)
        return i;
    std::string psw;
    std::getline(i,psw);
    if(!i)
        return i;
    std::string l;
    std::getline(i,l);
    if(!i)
        return i;

    u.username=us;
    u.passw = psw;
    u.luogo = l;
    return i;
}

bool utenteAdmin::modificaPasswordUtente(std::string nuovaPassword, utente& u) const{
    u.modificaPassword(nuovaPassword);
}
bool utenteAdmin::modificaLuogoUtente(std::string nuovoLuogo, utente& u) const{
    u.modificaLuogo(nuovoLuogo);
}
