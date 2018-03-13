#ifndef TORNEO_H
#define TORNEO_H

#include <string>
#include <vector>
#include <algorithm> //per funzione di shuffle dei partecipanti
#include <ctime> //per funzione shuffle dei partecipanti
#include <ostream>
#include <istream>
#include <ios>
#include <sstream>
#include "utility.h" //alcune funzioni di utilità generali scritte apposta per torneo
#include "errore.h"
#include "partecipante.h"
#include "match.h"
#include "turno.h"

class torneo{
    //OPERATORE DI STAMPA
    friend std::ostream& operator <<(std::ostream&,const torneo&);
    friend std::istream& operator >>(std::istream&,torneo&);
private:
    size_t indicePartecipante(const partecipante&) const; //operatore << stampa i match come riferimenti ai partecipanti e ha bisogno strumentalmente di questa funzione
    std::string nomeTorneo;
    std::string luogoTorneo;
    unsigned int punteggioMinimo;
    static std::vector<turno> copiaTurni(const torneo& daCopiare,const std::vector<partecipante>& nuoviPartecipanti); //strumentale a costruttore di copia e assegnazione
protected:
    std::vector<partecipante> partecipanti; //perchè vector e non set..? perchè set considera diversi due giocatori di nome pippo che hanno punteggi elo diversi, invece noi vogliamo rendere unico il nome pippo per esempio. Si trova nella parte protected così che se ne dovessero avere bisogno le classi derivate possono modificare l'ordine dei partecipanti
    std::vector<turno> turni; //perchè nella parte protected e non private? perchè voglio che all esterno della classe non sia possibile modificare il vettore dei turni: solamente il torneo può creare o aggiungere turni, all esterno deve solo essere possibile modificare i risultati dei match
    bool iniziato; //alcuni tipi di torneo se ridefiniscono iniziato deve poter avere accesso a tale variabile
    void checkProssimoTurno() const; //funzione che serve da shortcut alle classi figlie solamente per controllare che si possa passare al prossimo turno. solleva eccezioni appropriate in caso contrario
public:
    static const short int trr; //torneo round robin: identificatore del tipo 'Round robin'
    static const short int ts; //torneo svizzero: identificatore del tipo 'Svizzero'
    static const short int ted; //torneo eliminazione diretta: identificatore del tipo 'Eliminazione diretta'
    static const short int trrd; //torneo round robin: identificatore del tipo 'Round Robin doppio'

    //OPERAZIONI GENERALI
    virtual void inizia(); //può sollevare un'eccezione
    virtual unsigned int nTurniTotale() const = 0; //ogni torneo deve definire staticamente il numero totale di turni, solleva eccezione se il torneo non è iniziato
    virtual void prossimoTurno() = 0; //solleva eccezione se il turno in corso non è finito o il torneo non è iniziato
    virtual const partecipante& getVincitore() const = 0;
    virtual std::string tipologiaTestuale() const = 0; //descrive le modalità di calcolo dei turni/vincitore del torneo
    virtual short int tipo() const=0;
    void setVincitoreUltimoTurno(size_t indice_match,match::risultatoMatch ris); //può sollevare un'eccezione se si inserisce un valore che non appartiene a -1,1,2
    void rimescolaPartecipanti(); //solleva eccezione se torneo iniziato. randomizza l'ordine
    bool siSonoScontrati(const partecipante&,const partecipante&) const;

    //GETTERS
    std::string getLuogoTorneo() const;
    std::string getNomeTorneo() const;
    unsigned int getPunteggioMinimo() const;
    bool getIniziato() const;
    bool finito() const;
    bool ultimoTurnoFinito() const;
    const std::vector<turno>& getTurni() const;
    const turno& getUltimoTurno() const;
    const std::vector<partecipante>& getPartecipanti() const;
    std::string toString() const;

    //OPERAZIONI SUI PARTECIPANTI
    bool partecipa(const partecipante& p) const; //paragone solamente per nome
    void inserisciPartecipante(const partecipante& p); //può sollevare un'eccezione

    //COSTRUTTORI
    torneo(std::string n="Torneo",std::string l="",unsigned int p=0);
    torneo(const torneo& ); //devo ridefinirlo in quanto i match rappresentano i partecipanti come dei riferimenti costanti e vanno dunque inizializzati al valore corretto

    //OPERATORI
    torneo& operator=(const torneo&); //va ridefinito per lo stesso motivo del costruttore di copia

    //DISTRUTTORE VIRTUALE
    virtual ~torneo();

    //FUNZIONI STATICHE
    static torneo* leggiDaInput(std::istream& i); //restituisce un puntatore a un torneo del tipo corretto. lo steam di input deve essere aperto
};

class torneoVittorieContate: public torneo{ //definisce utilità generali per tornei nei quali il vincitore si determina contando le sue vittorie; durante lo svolgimento del torneo nessuno viene eliminato
protected:
    class vittoriePartecipante{
    public:
        const partecipante* p;
        unsigned int vittorie;
        vittoriePartecipante(const partecipante& part,unsigned int v=0);
    };
public:
    torneoVittorieContate(std::string n="Torneo",std::string l="",unsigned int p=0);
    virtual const partecipante& getVincitore() const;
};

class torneoRr: public torneoVittorieContate{ //torneo Round Robin, ogni giocatore si scontra con ogni altro giocatore
public:
    virtual unsigned int nTurniTotale() const;
    virtual void prossimoTurno();
    virtual std::string tipologiaTestuale() const;
    torneoRr(std::string n="TorneoRr",std::string l="",unsigned int p=0);
    virtual short int tipo() const;
    static const std::string tipoTesto;
};

class torneoRrDoppio: public torneoRr{
public:
    virtual unsigned int nTurniTotale() const;
    virtual void prossimoTurno();
    virtual std::string tipologiaTestuale() const;
    torneoRrDoppio(std::string n="TorneoRrDoppio",std::string l="",unsigned int p=0);
    virtual short int tipo() const;
    static const std::string tipoTesto;
};

class torneoSvizzero: public torneoVittorieContate{ //torneo con modalità Svizzera, inizialmente i partecipanti vengono accoppiati secondo un indice crescente di abilità(ELO) e successivamente i vincitori di ogni turno vanno a scontrarsi con i vincitori degli altri turni. Il torneo si conclude in solo log2(#partecipanti) turni ma da la possibilità anche ai perdenti del primo turno di non essere eliminati
public:
    virtual unsigned int nTurniTotale() const;
    virtual void prossimoTurno();
    virtual void inizia();
    virtual std::string tipologiaTestuale() const;
    torneoSvizzero(std::string n="TorneoSvizzero",std::string l="",unsigned int p=0);
    virtual short int tipo() const;
    static const std::string tipoTesto;
};

class torneoEliminazioneDiretta:public torneo{ //torneo classico ad eliminazione diretta, appena un giocatore perde viene eliminato
public:
    virtual unsigned int nTurniTotale() const; //ogni torneo deve definire staticamente il numero totale di turni
    virtual void prossimoTurno();
    virtual const partecipante& getVincitore() const;
    virtual std::string tipologiaTestuale() const;
    torneoEliminazioneDiretta(std::string n="Torneo ad eliminazione diretta",std::string l="",unsigned int p=0);
    virtual short int tipo() const;
    static const std::string tipoTesto;
};


#endif // TORNEO_H
