#include "c.h"
#include <iostream>

const std::string C::path_to_users="users/";
const std::string C::path_to_tornei="tornei/";

const std::string C::estensione_utenti = ".utente";
const std::string C::estensione_tornei = ".torneo";

C::C() : user(nullptr){
    pulisciDBUtenti();
    pulisciDBTornei();
}

bool C::login(std::string un,std::string psw){
    if(!logged()){
        DIR *pDIR;
        struct dirent *entry;
        if((pDIR=opendir(path_to_users.c_str()))){
            while((entry = readdir(pDIR))){
                if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                    //questo ciclo gira tutti i files
                    std::string nome = std::string(entry->d_name);
                    if(nome.size() >= std::string(estensione_utenti).size()
                            && nome.substr( nome.size() - estensione_utenti.size(), - estensione_utenti.size()) == estensione_utenti){
                        //se abbiamo passato questo test nella cartella corrente abbiamo il file .utente
                        //apro il file corrente
                        std::ifstream in(path_to_users+std::string(entry->d_name));
                        if(in){
                            utente* u = utente::leggiDaInput(in,*this);
                            //abbiamo forse letto l utente
                            if(in && u){
                                //l'abbiamo letto
                                if(u->username == un && u->passw == psw ){
                                    //abbiamo effettuato il login
                                    user = u;
                                    in.close();
                                    return true;
                                } else {
                                    //il file letto attualmente non contiene il profilo giusto
                                    delete u;
                                }
                            }
                        }
                        in.close();
                    }
                }
            }
            closedir(pDIR);
        }
        //letto tutti i file utente esistenti
        return false;
    } else //sei già loggato
        return false;
}

const std::vector<torneo *>& C::getModificabili() const{
    if(logged())
        return modificabili;
    else throw(errore("Devi eseguire il login prima di poter accedere ai tornei modificabili"));
}

const std::vector<const torneo*>& C::getVisualizzabili() const{
    if(logged())
        return visualizzabili;
    else throw(errore("Devi eseguire il login prima di poter accedere ai tornei visualizzabili"));
}

void C::svuotaRicerche(){

    salvaModifiche();

    for(size_t i = 0;i<visualizzabili.size();i++)
        delete visualizzabili[i];
    visualizzabili.clear();

    for(size_t i = 0;i<modificabili.size();i++)
        delete modificabili[i];
    modificabili.clear();
}

void C::cerca(std::string n,std::string l,unsigned int p){
    if(logged()){
        svuotaRicerche(); //eliminiamo(e salviamo) quello che abbiamo cercato in precedenza
        DIR *pDIR;
        struct dirent *entry;
        if((pDIR=opendir(path_to_tornei.c_str()))){
            while((entry = readdir(pDIR))){
                if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                    //questo ciclo gira tutti i files
                    std::string nome = std::string(entry->d_name);
                    if(nome.size() >= std::string(estensione_tornei).size()
                            && nome.substr( nome.size() - estensione_tornei.size(), estensione_tornei.size() ) == estensione_tornei){
                        //se abbiamo passato questo test nella cartella corrente abbiamo il file .torneo
                        //apro il file corrente
                        std::ifstream in(path_to_tornei+std::string(entry->d_name));
                        if(in){
                            std::string un;
                            std::getline(in,un);
                            torneo* t = torneo::leggiDaInput(in);
                            if(in && t){
                                //torneo letto correttamente
                                if(user->rispettaParametriRicerca(t,n,l,p)){
                                    permesso per = user->chiediPermesso(t,un);
                                    if(per == permesso::mod)
                                        modificabili.push_back(t);
                                    if(per == permesso::vis)
                                        visualizzabili.push_back(t);
                                    if(per == permesso::nvis)
                                        delete t;
                                } else
                                    delete t;
                            }
                        }
                        in.close();
                    }
                }
            }
            closedir(pDIR);
        }
    }
}

bool C::usernameUtilizzato(std::string us) const{
    DIR *pDIR;
    struct dirent *entry;
    if((pDIR=opendir(path_to_users.c_str()))){
        while((entry = readdir(pDIR))){
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                //questo ciclo gira tutti i files
                std::string nome = std::string(entry->d_name);
                if(nome.size() >= std::string(estensione_utenti).size()
                        && nome.substr( nome.size() - estensione_utenti.size(), estensione_utenti.size()   ) == estensione_utenti){
                    //se abbiamo passato questo test nella cartella corrente abbiamo il file .utente
                    //apro il file corrente
                    std::ifstream in(path_to_users+std::string(entry->d_name));
                    if(in){
                        utente* u = utente::leggiDaInput(in,*this);
                        //abbiamo forse letto l utente
                        if(in && u){
                            //l'abbiamo letto
                            if(u->username == us){
                                //l'username è già stato utilizzato
                                in.close();
                                return true;
                            } else {
                                //il file letto attualmente non contiene il profilo giusto
                                delete u;
                            }
                        }
                    }
                    in.close();
                }
            }
        }
        closedir(pDIR);
    }
    return false;
}

bool C::nomeTorneoUtilizzato(std::string nomeCercato) const{
    DIR *pDIR;
    struct dirent *entry;
    if((pDIR=opendir(path_to_tornei.c_str()))){
        while((entry = readdir(pDIR))){
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                //questo ciclo gira tutti i files
                std::string nome = std::string(entry->d_name);
                if(nome.size() >= std::string(estensione_tornei).size()
                        && nome.substr( nome.size() - estensione_tornei.size(), estensione_tornei.size() ) == estensione_tornei){
                    //se abbiamo passato questo test nella cartella corrente abbiamo il file .utente
                    //apro il file corrente
                    std::ifstream in(path_to_tornei+std::string(entry->d_name));
                    if(in){
                        std::string un;
                        std::getline(in,un);
                        torneo* t = torneo::leggiDaInput(in);
                        //abbiamo forse letto l utente
                        if(in && t){
                            //l'abbiamo letto
                            if(t->getNomeTorneo() == nomeCercato){
                                //l'username è già stato utilizzato
                                in.close();
                                return true;
                            } else {
                                //il file letto attualmente non contiene il profilo giusto
                                delete t;
                            }
                        }
                    }
                    in.close();
                }
            }
        }
        closedir(pDIR);
    }
    return false;
}

bool C::registraUtente(const utente * u) const{
    if(u == nullptr)
        return false;
    if(usernameUtilizzato(u->getUsername()))
        return false;
    //l'username non è già stato utilizzato
    std::ofstream outp(path_to_users+u->getUsername()+estensione_utenti);
    if(outp){
        outp << *u;
        if(outp){
            outp.close();
            return true;
        }else{
            outp.close();
            return false;

        }
    } else{
        outp.close();
        return false;
    }
}

bool C::creaTorneoDisco(const torneo* t) const{
    if(!logged())
        return false;
    if(t == nullptr)
        return false;
    if(nomeTorneoUtilizzato(t->getNomeTorneo()))
        return false;
    //il nome del torneo è disponibile
    std::ofstream outp(path_to_tornei+t->getNomeTorneo()+estensione_tornei);
    if(outp){
        outp << user->username<<'\n';
        outp << *t;
        if(outp){
            outp.close();
            return true;
        }else{
            outp.close();
            return false;
        }
    } else{
        outp.close();
        return false;
    }
}

bool C::creaTorneo(torneo *t){
    if(t == nullptr || !logged())
        return false;
    if(creaTorneoDisco(t)){
        modificabili.push_back(t);
        return true;
    } else {
        return false;
    }
}

void C::logout(){
    if(user){
        svuotaRicerche();
        delete user;
        user = nullptr;
    }
}

bool C::eliminaTorneoDisco(const torneo* daeliminare) const{
    DIR *pDIR;
    struct dirent *entry;
    if((pDIR=opendir(path_to_tornei.c_str()))){
        while((entry = readdir(pDIR))){
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                //questo ciclo gira tutti i files
                std::string nome = std::string(entry->d_name);
                if(nome.size() >= std::string(estensione_tornei).size()
                        && nome.substr( nome.size() - estensione_utenti.size(), estensione_utenti.size() ) == estensione_tornei){
                    //apro il file corrente
                    std::ifstream in(path_to_tornei+std::string(entry->d_name));
                    if(in){
                        std::string un;
                        std::getline(in,un);
                        torneo* t = torneo::leggiDaInput(in);
                        if(in && t){
                            if(t->getNomeTorneo() == daeliminare->getNomeTorneo()){
                                //il torneo t su disco è il torneo che stiamo cercando di eliminare
                                in.close();
                                std::remove((path_to_tornei+std::string(entry->d_name)).c_str());
                                return true;
                            } else {
                                delete t;
                            }
                        }
                    }
                    in.close();
                }
            }
        }
        closedir(pDIR);
    }
    return false;
}

bool C::eliminaTorneo(torneo * t){
    if(!logged())
        return false;
    if(t == nullptr)
        return false;
    for(auto i = modificabili.begin();i!=modificabili.end();i++){
        if(*i == t){
            //il torneo che stiamo cercando è fra i modificabili
            eliminaTorneoDisco(t);
            delete t;
            i = modificabili.erase(i);
            return true;
        }
    }
    return false;
}

bool C::logged() const{ return user != nullptr; }

C::~C(){
    logout();
    for(size_t i=0;i<utenti.size();i++){
        delete utenti[i];
    }
}

void C::salvaModifiche() const{
    if(logged()){
        DIR *pDIR;
        struct dirent *entry;
        if((pDIR=opendir(path_to_tornei.c_str()))){
            while((entry = readdir(pDIR))){
                if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                    //questo ciclo gira tutti i files
                    std::string nome = std::string(entry->d_name);
                    if(nome.size() >= std::string(estensione_tornei).size()
                            && nome.substr( nome.size() - estensione_tornei.size(), estensione_tornei.size() ) == estensione_tornei){
                        //apro il file corrente
                        std::ifstream in(path_to_tornei+std::string(entry->d_name));
                        if(in){
                            std::string un;
                            std::getline(in,un);
                            torneo* t = torneo::leggiDaInput(in);
                            if(in && t){
                                //abbiamo letto il torneo da disco
                                bool aggiornato = false;
                                for(size_t i = 0;i<modificabili.size() && !aggiornato;i++){
                                    if(modificabili[i]->getNomeTorneo() == t->getNomeTorneo()){
                                        //è uno dei tornei da modificare

                                        in.close();
                                        std::ofstream agg(path_to_tornei+std::string(entry->d_name));
                                        if(agg){
                                            agg << un<<'\n';
                                            agg << *modificabili[i];
                                            aggiornato = true;

                                        }
                                        agg.close();
                                        in.open(path_to_tornei+std::string(entry->d_name));
                                    }
                                }
                            }
                        }
                        in.close();
                    }
                }
            }
            closedir(pDIR);
        }
    }
}


bool C::eliminaUtenteDisco(std::string username) const{
    DIR *pDIR;
    struct dirent *entry;
    if((pDIR=opendir(path_to_users.c_str()))){
        while((entry = readdir(pDIR))){
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                //questo ciclo gira tutti i files
                std::string nome = std::string(entry->d_name);
                if(nome.size() >= std::string(estensione_utenti).size()
                        && nome.substr( nome.size() - estensione_utenti.size(), estensione_utenti.size()   ) == estensione_utenti){
                    //apro il file corrente
                    std::ifstream in(path_to_users+std::string(entry->d_name));
                    if(in){
                        utente * u = utente::leggiDaInput(in,*this);
                        if(in && u){
                            if(u->getUsername() == username){
                                //l'utente da eliminare è quello che stiamo cercando
                                eliminaTorneiUtenteDisco(username);
                                in.close();
                                std::remove((path_to_users+std::string(entry->d_name)).c_str());
                                return true;
                            } else {
                                //il file letto attualmente non contiene il profilo giusto
                                delete u;
                            }
                        }
                    }
                    in.close();
                }
            }
        }
        closedir(pDIR);
    }
    return false;
}

void C::eliminaTorneiUtenteDisco(std::string username) const{
    DIR *pDIR;
    struct dirent *entry;
    if((pDIR=opendir(path_to_tornei.c_str()))){
        while((entry = readdir(pDIR))){
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                //questo ciclo gira tutti i files
                std::string nome = std::string(entry->d_name);
                if(nome.size() >= std::string(estensione_tornei).size()
                        && nome.substr( nome.size() - estensione_tornei.size(), estensione_tornei.size()   ) == estensione_tornei){
                    //apro il file corrente
                    std::ifstream in(path_to_tornei+std::string(entry->d_name));
                    if(in){
                        std::string nome;
                        std::getline(in,nome);
                        if(in && nome==username){
                            in.close();
                            std::remove((path_to_tornei+std::string(entry->d_name)).c_str());
                        }
                    }
                    in.close();
                }
            }
        }
        closedir(pDIR);
    }
}

bool C::cancellaProfilo(){
    if(!logged())
        return false;
    //sei loggato
    svuotaRicerche(); //elimina le ricerche.. se lo facessi dopo aver eliminato l utente non avrebbe senso poichè uno dei compiti di elimina utente è eliminare dal disco i tornei dell utente che si vuole cancellare, svuota ricerche salva anche i tornei di un utente!
    eliminaUtenteDisco(user->getUsername()); //elimina dal disco i dati relativi a sto utente e i tornei da lui creati
    logout();
    return true;
}

utente* C::getUtente() const{
    return user;
}

bool C::eliminaUtente(utente *utenteDaEliminare) {
    if(utenteDaEliminare && logged() && dynamic_cast<utenteAdmin*>(user) && (utenteDaEliminare != user)){ //un utente non può eliminare il suo stesso profilo: per quello c'è una funzione apposita

        if(eliminaUtenteDisco(utenteDaEliminare->username)){
            //devo anche toglierlo dalla lista degli utenti
            bool continua = true;
            for(auto i=utenti.begin();i!=utenti.end() && continua;i++)
                if(utenteDaEliminare == *i){
                    delete *i;
                    utenti.erase(i);
                    continua = false;
                }
            return true;
        }
    }
    return false;
}

void C::cercaUtenti(std::string parametro){
    if(parametro != ""){
        if(logged() && dynamic_cast<utenteAdmin*>(user)){
            //svuota precedenti
            for(size_t i = 0;i<utenti.size();i++){
                delete utenti[i];
            }
            utenti.clear();

            DIR *pDIR;
            struct dirent *entry;
            if((pDIR=opendir(path_to_users.c_str()))){
                while((entry = readdir(pDIR))){
                    if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                        //questo ciclo gira tutti i files
                        std::string nome = std::string(entry->d_name);
                        if(nome.size() >= std::string(estensione_utenti).size()
                                && nome.substr( nome.size() - estensione_utenti.size(), estensione_utenti.size()   ) == estensione_utenti){
                            //apro il file corrente
                            std::ifstream in(path_to_users+std::string(entry->d_name));
                            if(in){
                                utente * u = utente::leggiDaInput(in,*this);
                                if(u){
                                    if(u->username != user->username && (utility::toLower(u->username).find(utility::toLower(parametro))!=std::string::npos))
                                        utenti.push_back(u);
                                    else
                                        //non inserisce l'utente loggato all'interno della lista
                                        delete u;
                                }
                            }
                            in.close();
                        }
                    }
                }
                closedir(pDIR);
            }
        }
    } else
        cercaTuttiGliUtenti();
}

void C::cercaTuttiGliUtenti(){
    if(logged() && dynamic_cast<utenteAdmin*>(user)){

        //svuota precedenti
        for(size_t i = 0;i<utenti.size();i++){
            delete utenti[i];
        }
        utenti.clear();

        DIR *pDIR;
        struct dirent *entry;
        if((pDIR=opendir(path_to_users.c_str()))){
            while((entry = readdir(pDIR))){
                if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                    //questo ciclo gira tutti i files
                    std::string nome = std::string(entry->d_name);
                    if(nome.size() >= std::string(estensione_utenti).size()
                            && nome.substr( nome.size() - estensione_utenti.size(), estensione_utenti.size()   ) == estensione_utenti){
                        //apro il file corrente
                        std::ifstream in(path_to_users+std::string(entry->d_name));
                        if(in){
                            utente * u = utente::leggiDaInput(in,*this);
                            if(u){
                                if(u->username != user->username)
                                    utenti.push_back(u);
                                else
                                    //non inserisce l'utente loggato all'interno della lista
                                    delete u;
                            }
                        }
                        in.close();
                    }
                }
            }
            closedir(pDIR);
        }
    }
}

const std::vector<utente *> &C::getUtenti() const{
    if(logged() && dynamic_cast<utenteAdmin*>(user)){
        return utenti;
    }
    else
        throw errore("Non sei un amministratore");
}

bool C::salvaModificheUtente(const utente* daAggiornare) const{
    if(logged()){
        DIR *pDIR;
        struct dirent *entry;
        if((pDIR=opendir(path_to_users.c_str()))){
            while((entry = readdir(pDIR))){
                if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                    //questo ciclo gira tutti i files
                    std::string nome = std::string(entry->d_name);
                    if(nome.size() >= std::string(estensione_utenti).size()
                            && nome.substr( nome.size() - estensione_utenti.size(), estensione_utenti.size()   ) == estensione_utenti){
                        //apro il file corrente
                        std::ifstream in(path_to_users+std::string(entry->d_name));
                        if(in){
                            utente * u = utente::leggiDaInput(in,*this);
                            if(u && (u->username == daAggiornare->username)){
                                //è proprio quello che devo modificare
                                in.close();
                                std::remove((path_to_users+std::string(entry->d_name)).c_str());
                                delete u;
                                if(registraUtente(daAggiornare))
                                    return true; //siamo riusciti ad aggiornare i dati
                                else
                                    return false;
                            }
                            delete u;
                        }
                        in.close();
                    }
                }
            }
            closedir(pDIR);
        }
    }
    return false;
}

void C::pulisciDBUtenti() const{
    DIR *pDIR;
    struct dirent *entry;
    if((pDIR=opendir(path_to_users.c_str()))){
        while((entry = readdir(pDIR))){
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                //questo ciclo gira tutti i files
                std::string nome = std::string(entry->d_name);
                if(nome.size() <= std::string(estensione_utenti).size()
                        || nome.substr( nome.size() - estensione_utenti.size(), estensione_utenti.size()   ) != estensione_utenti){
                    //il file non ha estensione corretta
                    std::remove((path_to_users+std::string(entry->d_name)).c_str());
                }
            }
        }
        closedir(pDIR);
    }
}
void C::pulisciDBTornei() const{
    DIR *pDIR;
    struct dirent *entry;
    if((pDIR=opendir(path_to_tornei.c_str()))){
        while((entry = readdir(pDIR))){
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                //questo ciclo gira tutti i files
                std::string nome = std::string(entry->d_name);
                if(nome.size() <= std::string(estensione_tornei).size()
                        || nome.substr( nome.size() - estensione_tornei.size(), estensione_tornei.size()   ) != estensione_tornei){
                    //il file non ha estensione corretta
                    std::remove((path_to_tornei+std::string(entry->d_name)).c_str());
                }
            }
        }
        closedir(pDIR);
    }
}
