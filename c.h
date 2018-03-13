#ifndef C_H
#define C_H
#include <string>
#include <dirent.h>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdio>
#include "utente.h"
#include "torneo.h"

class C{
private:
    //DATI
    utente* user;
    std::vector<torneo *> modificabili;
    std::vector<const torneo *> visualizzabili;

    //UTILIZZABILE SOLO DA UTENTI ADMIN
    std::vector<utente*> utenti;

    //STRINGHE PER LA GESTIONE DEI FILE
    static const std::string path_to_users;
    static const std::string path_to_tornei;
    static const std::string estensione_utenti;
    static const std::string estensione_tornei;

    //OPERAZIONI SU DISCO
    bool creaTorneoDisco(const torneo*) const; //false se nometorneo già utilizzato
    bool eliminaTorneoDisco(const torneo*) const; //false se non ha trovato il file corrispondente al torneo
    void eliminaTorneiUtenteDisco(std::string username) const; //elimina i tornei dell'utente
    bool eliminaUtenteDisco(std::string username) const; //false se non ha trovato l'utente
    void pulisciDBUtenti() const; //elimina file non dell'estensione .utente nella cartella degli utenti, chiamato alla creazione di C
    void pulisciDBTornei() const; //elimina file non dell'estensione .torneo nella cartella dei tornei, chiamato alla creazione di C
public:
    //ACCESSO UTENTE AL CONTENITORE
    bool login(std::string un,std::string psw);
    void logout(); //se è loggato elimina l utente, salva le modifiche e svuota le ricerche
    bool logged() const;
    bool cancellaProfilo(); //elimina il profilo dell'utente loggato e relativi tornei
    bool registraUtente(const utente*) const; //false se username già preso
    bool salvaModificheUtente(const utente* daAggiornare) const; //un utente ha modificato qualche attributo come password o luogo, tali cambiamenti vanno effettuati anche su disco: tale compito spetta a C

    //FUNZIONI DEGLI AMMINISTRATORI
    bool eliminaUtente(utente* utenteDaEliminare); //elimina un utente dal disco e anche dal vettore utenti
    void cercaUtenti(std::string parametro=""); //cerca per username che contenga parametro
    void cercaTuttiGliUtenti(); //se sei amministratore riempie il vettore utenti con tutti quelli esistenti, tranne te stesso
    const std::vector<utente *>& getUtenti() const; //ritorna gli utenti del sistema, se sono stati letti

    //RICERCA
    void cerca(std::string n="",std::string l="",unsigned int p=0);
    bool usernameUtilizzato(std::string ) const;
    bool nomeTorneoUtilizzato(std::string ) const;
    void svuotaRicerche();

    //LETTURA ELEMENTI
    const std::vector<torneo *>& getModificabili() const;
    const std::vector<const torneo*>& getVisualizzabili() const;
    utente *getUtente() const;

    //GESTIONE DEI TORNEI UTENTE
    bool creaTorneo(torneo *); //prova a inserire fra i tornei modificabili il nuovo torneo, operazione fatta anche su disco
    bool eliminaTorneo(torneo *); //prova ad eliminare dai tornei modificabili il torneo, stessa cosa su disco
    void salvaModifiche() const;

    //COSTRUTTORE/DISTRUTTORE
    ~C(); //richiama logout
    C();
};

#endif // C_H
