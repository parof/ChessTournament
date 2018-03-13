#ifndef UTENTE_H
#define UTENTE_H
#include <string>
#include <ostream>
#include <istream>
#include "errore.h"
#include "torneo.h"

class permesso{
private:
    short int tipo;
public:
    static const short int nvis;
    static const short int vis;
    static const short int mod;
    permesso(short int t=nvis); //può sollvare eccezione se non usi 0,1,2. inoltre è un convertitore di tipo
    bool operator ==(const permesso& ) const;
};

class C;

class utente{
    friend class C; //permetto a C la modifica dei campi dati
    friend std::ostream& operator <<(std::ostream& o,const utente& u);
    friend std::istream& operator >>(std::istream& i,utente& u);
private:
    std::string username;
    std::string passw;
    std::string luogo; //luogo in cui l'utente agisce(per esempio la città in cui abita)
protected:
    class funtoreRicerca {
    public:
        int tipoRicerca;
        funtoreRicerca(int x=0);
        bool operator() (const torneo* t, std::string nomeT="",std::string luogoT="",unsigned int puntiMin=0) const; //true se il torneo rispetta i parametri della ricerca
    };
    const C& contenitore; //necessito di questa informazione per poter chiedere al contenitore di aggiornare le informazioni su disco
public:
    //IDENTIFICATORI STATICI
    static const short int basic;
    static const short int pro;
    static const short int admin;
    static const std::string descrizioneBasic;
    static const std::string descrizionePro;
    static const std::string descrizioneAdmin;

    //COSTRUTTORI
    utente(const C& c, std::string un="usr",std::string p="psw",std::string l="");
    //DISTRUTTORE VIRTUALE
    virtual ~utente();
    //GETTERS
    bool operator ==(const utente& ) const;
    std::string getUsername() const;
    std::string getLuogo() const;
    std::string getPassword() const;
    virtual short int tipo() const=0;
    virtual std::string tipologiaTestuale() const=0;
    virtual std::string descrizioneTipologia() const=0;
    //OPERAZIONI
    bool sonoIo(std::string u,std::string p) const; //case sensitive, per effettuare login. nb:non serve il luogo
    virtual permesso chiediPermesso(const torneo*,std::string creatore) const = 0; //ritorna il tipo di permesso sul torneo in base all'utente
    virtual bool rispettaParametriRicerca(const torneo* t, std::string nomeT="",std::string luogoT="",unsigned int puntiMin=0) const=0; //usa il funtore
    static utente* leggiDaInput(std::istream& i, const C &c); //restituisce un puntatore a un utente del tipo corretto. lo stream di input deve essere aperto
    //MODIFICA DEI PROPRI CAMPI DATI
    bool modificaPassword(std::string nuovaPassword);
    bool modificaLuogo(std::string nuovoLuogo);
};

class utenteBasic : public utente{
    //può modificare i suoi tornei, visualizzare solo quelli nel suo luogo o cercare solo per nome del torneo
public:
    utenteBasic(const C& c,std::string un="usr",std::string p="psw",std::string l="");
    virtual permesso chiediPermesso(const torneo*t,std::string creatore) const;
    virtual bool rispettaParametriRicerca(const torneo* t, std::string nomeT="",std::string luogoT="",unsigned int puntiMin=0) const;
    virtual short int tipo() const;
    virtual std::string tipologiaTestuale() const;
    virtual std::string descrizioneTipologia() const;
};

class utenteRicercaAvanzata : public utente{
    //utenti che possono fare ricerca sul nome del torneo, ma anche sul luogo o il punteggio minimo  iscriversi
public:
    utenteRicercaAvanzata(const C& c,std::string un="usr",std::string p="psw",std::string l="");
    virtual bool rispettaParametriRicerca(const torneo* t, std::string nomeT="",std::string luogoT="",unsigned int puntiMin=0) const;
};

class utentePro : public utenteRicercaAvanzata{
    //può modificare i suoi tornei e visualizzare tutti quelli esistenti, cerca per nome, punteggio minimo e luogo di svolgimento
public:
    utentePro(const C& c,std::string un="usr",std::string p="psw",std::string l="");
    virtual permesso chiediPermesso(const torneo*t,std::string creatore) const;
    virtual short int tipo() const;
    virtual std::string tipologiaTestuale() const;
    virtual std::string descrizioneTipologia() const;
};

class utenteAdmin : public utenteRicercaAvanzata{
    //può modificare e visualizzare tutti i tornei esistenti. può effettuare ricerche per nome del torneo, luogo di svolgimento e punteggio minimo
public:
    utenteAdmin(const C& c,std::string un="usr",std::string p="psw",std::string l="");
    virtual permesso chiediPermesso(const torneo*t,std::string creatore) const;
    virtual short int tipo() const;
    virtual std::string tipologiaTestuale() const;
    virtual std::string descrizioneTipologia() const;
    bool modificaPasswordUtente(std::string nuovaPassword, utente& u) const;
    bool modificaLuogoUtente(std::string nuovoLuogo,utente& u) const;
};

#endif // UTENTE_H
