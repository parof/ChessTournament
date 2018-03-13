#include "torneo.h"

// - TORNEO -

//COSTANTI STATICHE
const short int torneo::trr=1;
const short int torneo::ts=2;
const short int torneo::ted=3;
const short int torneo::trrd=4;

//OPERAZIONI GENERALI
void torneo::inizia(){
    if(partecipanti.size() > 1)
        if(!iniziato){
            if(utility::isPotenzaDiDue(partecipanti.size())){
                rimescolaPartecipanti();
                iniziato=true;
                turno tmp;
                for(size_t i=0;i<partecipanti.size()/2;i++){
                    int index = i*2;
                    tmp.aggiungiMatch(match(partecipanti[index],partecipanti[index+1]));
                }
                turni.push_back(tmp);
            }
            else
                throw(errore("Servono almeno " + std::to_string(utility::prossimaPotenzaDiDue(partecipanti.size())) + " partecipanti per poter iniziare il torneo"));
        } else throw(errore("Il torneo è già iniziato"));
    else throw(errore("Il numero minimo di partecipanti per un torneo è 2"));
}

void torneo::checkProssimoTurno() const{
    if(!iniziato)
        throw errore("Il torneo non è iniziato");
    if(!turni[turni.size()-1].finito())
        throw errore("Non puoi passare al turno successivo se alcuni match sono in corso");
    if(finito())
        throw errore("Il torneo è finito");
}

void torneo::setVincitoreUltimoTurno(size_t indice_match,match::risultatoMatch ris){
    if(iniziato)
        turni[turni.size()-1].matches[indice_match].setVincitore(ris);
    else
        throw(errore("Il torneo non è ancora iniziato"));
}

bool torneo::ultimoTurnoFinito() const{
    return turni[turni.size()-1].finito();
}

bool torneo::finito() const {
    return iniziato && turni.size() == nTurniTotale() && ultimoTurnoFinito();
}

void torneo::rimescolaPartecipanti(){
    if(!iniziato){
        std::srand( std::time(0));
        std::random_shuffle(partecipanti.begin(),partecipanti.end());
    }
    else
        throw(errore("Non puoi rimescolare i partecipanti quando il torneo è iniziato"));
}

bool torneo::siSonoScontrati(const partecipante& p1,const partecipante& p2) const{
    for(auto i =turni.begin();i != turni.end();i++)
        for(auto j=(*i).matches.begin();j != (*i).matches.end();j++)
            if(j->partecipa(p1) && j->partecipa(p2))
                return true;
    return false;
}

//COSTRUTTORI
torneo::torneo(std::string n, std::string l, unsigned int p) : iniziato(false),nomeTorneo(n), luogoTorneo(l),punteggioMinimo(p) {}

//DISTRUTTORE VIRTUALE
torneo::~torneo(){}

//GETTERS
std::string torneo::getLuogoTorneo() const{ return luogoTorneo; }
std::string torneo::getNomeTorneo() const { return nomeTorneo; }
unsigned int torneo::getPunteggioMinimo() const { return punteggioMinimo; }
bool torneo::getIniziato() const { return iniziato; }
const std::vector<turno>& torneo::getTurni() const{ return turni; }
const std::vector<partecipante>& torneo::getPartecipanti() const{return partecipanti;}
std::string torneo::toString() const{
    std::string s="";
    s+= ("**************************************\n>Nome: "+nomeTorneo+"\n>Luogo: "+luogoTorneo+"\n>Punteggio minimo iscrizione: "+std::to_string(punteggioMinimo)+"\n>Tipologia: "+tipologiaTestuale()+"\n**************************************\n\n>Numero di partecipanti: "+std::to_string(partecipanti.size())+"\n\n");
    for(size_t i=0;i<partecipanti.size();i++){
        s+=(partecipanti[i].toString()+"\n");
    }

    s+=("\n>Numero di turni: "+std::to_string(turni.size())+"\n\n");
    for(size_t i=0;i<turni.size();i++){
        s+=("Turno "+std::to_string(i+1)+"\n"+turni[i].toString());
    }
    if(finito())
        s+="\n>Vincitore: "+getVincitore().getNome()+"\n";
    return s;
}

const turno& torneo::getUltimoTurno() const{ return turni[turni.size()-1]; }

//OPERAZIONI SUI PARTECIPANTI

bool torneo::partecipa(const partecipante& p) const{
    auto i = partecipanti.begin();
    for(; i != partecipanti.end(); i++){
        if(i->getNome() == p.getNome())
            return true;
    }
    return false;
}

void torneo::inserisciPartecipante(const partecipante& p){
    if(!iniziato)
        if(!partecipa(p))
            if(p.getElo() >= punteggioMinimo)
                partecipanti.push_back(p);
            else{
                std::string s = p.getNome() + " ha un ELO troppo basso per partecipare al torneo: il punteggio minimo per partecipare è " + std::to_string(punteggioMinimo);
                throw(errore(s));
            }
        else throw(errore(std::string(p.getNome() + " partecipa già al torneo")));
    else throw(errore("Non si possono aggiungere partecipanti una volta iniziato il torneo"));
}

size_t torneo::indicePartecipante(const partecipante& p) const{
    for(size_t i=0;i<partecipanti.size();i++)
        if(p == partecipanti[i])
            return i;
    throw errore(p.getNome()+" non partecipa al torneo");
}

std::ostream& operator <<(std::ostream& o,const torneo& t){
    //INTESTAZIONE
    o   <<t.tipo()<<"\n"
        <<t.nomeTorneo<<"\n"
        <<t.luogoTorneo+"\n"
        <<(t.punteggioMinimo)<<"\n"
        <<t.tipologiaTestuale()<<"\n";

    //PARTECIPANTI
    for(size_t i =0;i<(t.partecipanti).size();i++){
        o<<"("<<(t.partecipanti)[i].getNome()<<","<<(t.partecipanti)[i].getElo()<<")\n";
    }
    o<<t.iniziato<<"\n"; //iniziato



    //TURNI
    for(size_t i=0;i<(t.turni).size();i++){
        o<<i<<"\n"; //stampo l indice del turno
        const std::vector<match>& m=(t.turni[i]).getMatches();
        for(size_t j=0;j<m.size();j++){
            //o<<"\t"<<t.indicePartecipante(m[j].getP1())<<" vs "<<t.indicePartecipante(m[j].getP2())<<" - ";
            o<<"\t"<<m[j].getRisultato()<<"\n";
        }
    }

    return o;
}

torneo* torneo::leggiDaInput(std::istream& i){
    if(!i){
        return nullptr;
    }
    torneo* ret = nullptr;
    try{
        std::string ti; //prima legge il tipo
        std::getline(i,ti);
        int tipo=stoi(ti);
        switch (tipo) {
        case torneo::trr:
            ret = new torneoRr();
            break;
        case torneo::ts:
            ret = new torneoSvizzero();
            break;
        case torneo::ted:
            ret = new torneoEliminazioneDiretta();
            break;
        case torneo::trrd:
            ret = new torneoRrDoppio();
            break;
        default:
            return nullptr;
            break;
        }
        i.unget();i.unget();

        i >> *ret;
        if(!i){
            delete ret;
            return nullptr;
        }return ret;
    } catch(...){
        i.clear(std::ios::failbit);
        return nullptr;
    }
}

std::istream& operator >>(std::istream& i,torneo& t){
    std::stringstream copia;
    copia << t;
    try{
        std::string s;
        std::getline(i,s); //leggo la tipologia
        short int x = std::stoi(s);
        if(x != t.tipo())
            throw(errore("Errore nell'input: si cerca di inserire un torneo di tipo errato in un torneo" + t.tipo()));
        std::getline(i,s);
        t.nomeTorneo = s;
        std::getline(i,s);
        t.luogoTorneo = s;
        std::getline(i,s);
        t.punteggioMinimo = std::stoul(s);
        std::getline(i,s);
        if(s != t.tipologiaTestuale()){
            throw(errore("Errore nell'input: si cerca di inserire un torneo di tipo "+s+" in un torneo di tipo "+t.tipologiaTestuale()));
        }
        t.partecipanti.clear();
        t.turni.clear();
        std::getline(i,s);
        while(s.substr(0,1) == "("){
            //sto leggendo partecipanti
            size_t ind = s.find(',');
            if(ind == std::string::npos)
                throw(errore("Errore nel formato di input"));
            std::string nomep = s.substr(1,ind-1);
            size_t ind1 = s.find(')');
            if(ind1 == std::string::npos)
                throw(errore("Errore nel formato di input"));
            unsigned int elop = std::stoul(s.substr(ind+1,s.size()-2)); //-2 poichè nell ultima posizione ho un )
            if(elop < t.punteggioMinimo)
                throw(errore(nomep+" non ha abbastanza punti per iscriversi al torneo"));
            t.partecipanti.push_back(partecipante(nomep,elop));

            std::getline(i,s);
        }

        if(s.substr(0,1) == "0") //il torneo non è iniziato
            return i;
        if(s.substr(0,1) != "1")
            throw(errore("errore nell input"));
        //s[0] == 1, dunque il torneo è iniziato e devo mettere un po' di turni in modo corretto
        if(t.partecipanti.size() <= 1)
            throw(errore("Il numero minimo di partecipanti per un torneo è 2"));
        if(!(utility::isPotenzaDiDue(t.partecipanti.size())))
            throw(errore("Servono almeno " + std::to_string(utility::prossimaPotenzaDiDue(t.partecipanti.size())) + " partecipanti per poter iniziare il torneo"));

        //ho un numero giusto di partecipanti, già mescolati nell'ordine giusto al momento del salvataggio
        t.iniziato=true;
        turno tmp;
        for(size_t i=0;i<t.partecipanti.size()/2;i++){
            //inizio standard di un torneo
            int index = i*2;
            tmp.aggiungiMatch(match(t.partecipanti[index],t.partecipanti[index+1]));
        }
        t.turni.push_back(tmp);

        //ora devo iniziare a leggere i risultati dei turni
        int indice = 0;
        std::getline(i,s);

        while(i && (std::stoi(s.substr(0,1)) == indice)){
            std::vector<match::risultatoMatch> risultati;
            std::getline(i,s);

            while(i && s.substr(0,1) == "\t"){
                if(s.size() <= 2)
                    risultati.push_back(std::stoi(s.substr(1,s.size()-1))); //magari qui puoi mettere anche 2 o più
                else
                    risultati.push_back(std::stoi(s.substr(1,s.size()-1)));
                std::getline(i,s);
            }

            if(risultati.size() != t.turni[t.turni.size()-1].getMatches().size())
                throw(errore("Errore nell'input: non sono stati dati il giusto numero di risultati dei match nel turno "+std::to_string(indice)));
            //ho il giusto numero di risultati dei match
            for(size_t i =0;i<risultati.size();i++)
                //imposto i risultati dei match
                t.setVincitoreUltimoTurno(i,risultati[i]);

            if(!t.finito() && t.ultimoTurnoFinito()){
                indice++;
                if(i && (std::stoi(s.substr(0,1)) == indice))
                    t.prossimoTurno();
            }
        }
        i.clear();
    }
    catch(...){
        //se un errore di qualunque tipo viene lanciato provando a leggere il file la situazione viene ripristinata come prima dell'input, settando il bit di fail
        copia>>t;
        i.clear(std::ios::failbit);
    }
    return i;
}

std::vector<turno> torneo::copiaTurni(const torneo& daCopiare,const std::vector<partecipante>& nuoviPartecipanti){
    std::vector<turno> ret;
    for(size_t i=0;i<daCopiare.turni.size();i++){
        turno tmp;
        //RIEMPIO IL TURNO
        for(size_t j=0;j<daCopiare.turni[i].matches.size();j++){
            //per ogni match del turno preso in considerazione
            size_t indicep1 = daCopiare.indicePartecipante
                    (daCopiare.turni[i].matches[j].getP1());
            size_t indicep2 = daCopiare.indicePartecipante
                    (daCopiare.turni[i].matches[j].getP2());
            tmp.aggiungiMatch(match(nuoviPartecipanti[indicep1],nuoviPartecipanti[indicep2],daCopiare.turni[i].matches[j].getRisultato()));
        }
        ret.push_back(tmp);
    }
    return ret;
}

torneo& torneo::operator =(const torneo& t){
    if(this != &t){
        nomeTorneo = t.nomeTorneo;
        luogoTorneo = t.luogoTorneo;
        punteggioMinimo = t.punteggioMinimo;
        iniziato = t.iniziato;
        partecipanti = t.partecipanti;
        turni = copiaTurni(t,partecipanti); //è proprio per questo che va definito questo operatore
    }
    return *this;
}

torneo::torneo(const torneo& t) : nomeTorneo(t.nomeTorneo), luogoTorneo(t.luogoTorneo), punteggioMinimo(t.punteggioMinimo),iniziato(t.iniziato),partecipanti(t.partecipanti), turni(copiaTurni(t,partecipanti)){}


// - TORNEO VITTORIE CONTATE -
torneoVittorieContate::vittoriePartecipante::vittoriePartecipante(const partecipante& part,unsigned int v) : p(&part),vittorie(v){}

torneoVittorieContate::torneoVittorieContate(std::string n, std::string l, unsigned int p): torneo(n,l,p) {}

const partecipante& torneoVittorieContate::getVincitore() const{
    if(!finito())
        throw(errore("Ci sarà un vincitore solo quando il torneo sarà finito"));
    //il torneo è finito, possiamo determinare il vincitore
    std::vector<vittoriePartecipante> vit;
    for(size_t i=0;i<partecipanti.size();i++)
        vit.push_back(vittoriePartecipante(partecipanti[i]));

    //nel ciclo qui sotto leggo tutti i match di tutti i turni e assegno il valore delle vittorie ai giocatori
    for(size_t i=0;i<turni.size();i++){
        const std::vector<match>& m = turni[i].getMatches();
        for(size_t j=0;j<m.size();j++){
            //per ogni match di ogni turno
            bool continua = true;
            for(size_t z=0;z<vit.size() && continua;z++){
                if(m[j].getVincitore() == *(vit[z].p)){
                    //il vincitore del match che stiamo prendendo in esame è il partecipante che sto leggendo
                    vit[z].vittorie++;
                    continua=false;
                }
            }
        }
    }

    unsigned int vittoriemax = vit[0].vittorie;
    //calcolo il numero massimo di vittorie
    for(size_t i=1;i<vit.size();i++)
        if(vit[i].vittorie > vittoriemax)
            vittoriemax=vit[i].vittorie;

    //prima selezioniamo i giocatori che hanno il numero massimo di vittorie(potrebbero essere più di 1)
    std::vector<vittoriePartecipante> migliori;
    for(size_t i=0;i<vit.size();i++)
        if(vit[i].vittorie == vittoriemax)
            migliori.push_back(vit[i]);

    //calcolo l elo massimo fra i migliori
    unsigned int max = (*(migliori[0].p)).getElo();
    for(size_t i=1;i<migliori.size();i++)
        if((*(migliori[i].p)).getElo() > max)
            max = (*(migliori[i].p)).getElo();

    for(size_t i=0;i<migliori.size();i++)
        if((*(migliori[i].p)).getElo() == max)
            return *(migliori[i].p);
}


// - TORNEO ROUND ROBIN -

const std::string torneoRr::tipoTesto="Round Robin";

unsigned int torneoRr::nTurniTotale() const{
    if(torneo::getIniziato())
        return partecipanti.size() -1; //ogni giocatore si deve scontrare con ogni altro giocatore
    else
        throw(errore("Non si possono determinare il numero di turni totali prima dell'inizio del torneo"));
}

void torneoRr::prossimoTurno(){
    checkProssimoTurno();
    turno tmp;
    for(size_t i=0;i<partecipanti.size();i++){
        const partecipante& p1 = partecipanti[i];
        if(! (tmp.partecipa(p1))){ //non abbiamo già scelto il partecipante
            bool trovato = false;
            //in questo ciclo scelgo un altro partecipante che non sia già stato scelto o che non sia p1 stesso
            for(auto j = partecipanti.begin();j != partecipanti.end() && !trovato ;j++){
                const partecipante& p2 = *j;
               if(!(p2 == p1) ){
                    if (!siSonoScontrati(p1,p2)){
                        if(!(tmp.partecipa(p2))){
                                tmp.aggiungiMatch(match(p1,p2));
                                trovato = true;
                        }
                    }
                }
            }
        }
    }

    turni.push_back(tmp);
}

std::string torneoRr::tipologiaTestuale() const{
    return tipoTesto;
}

short int torneoRr::tipo() const{
    return torneo::trr;
}

torneoRr::torneoRr(std::string n, std::string l, unsigned int p) : torneoVittorieContate(n,l,p) {}

// - TORNEO ROUND ROBIN DOPPIO

const std::string torneoRrDoppio::tipoTesto="Round Robin Doppio";

torneoRrDoppio::torneoRrDoppio(std::string n,std::string l,unsigned int p) : torneoRr(n,l,p){}

unsigned int torneoRrDoppio::nTurniTotale() const{
    if(torneo::getIniziato())
        return (partecipanti.size() -1)*2; //ogni giocatore si deve scontrare con ogni altro giocatore due volte
    else
        throw(errore("Non si possono determinare il numero di turni totali prima dell'inizio del torneo"));
}

void torneoRrDoppio::prossimoTurno(){
    //DA FARE
    checkProssimoTurno();
    if(turni.size() < (nTurniTotale()/2)){
        //siamo nella prima metà del torneo: qui i match possono essere determinati in modalità round robin
        torneoRr::prossimoTurno();
        return;
    }
    //dobbiamo aggiungere un turno nella seconda metà del torneo: basta replicare quelli già determinati nella prima metà
    turno tmp;
    size_t predecessore=((turni.size()+1)-nTurniTotale()/2)-1; //corrispondente turno nella prima metà
    tmp.copiaMatchImpostandoRisultatoNullo(turni[predecessore]); //copia dalla prima metà dei turni il turno corrispondente, già con risultato ancora da impostare
    turni.push_back(tmp);
}

std::string torneoRrDoppio::tipologiaTestuale() const{
    return tipoTesto;
}
short int torneoRrDoppio::tipo() const{
    return torneo::trrd;
}

// - TORNEO SVIZZERO -

const std::string torneoSvizzero::tipoTesto="Svizzero";

unsigned int torneoSvizzero::nTurniTotale() const{
    if(torneo::getIniziato())
        return utility::prossimoEsponenteDiDue(partecipanti.size()); //ogni giocatore si deve scontrare con ogni altro giocatore
    else
        throw(errore("Non si possono determinare il numero di turni totali prima dell'inizio del torneo"));
}

void torneoSvizzero::prossimoTurno(){
    checkProssimoTurno();

    //suddivido in due vettori di puntatori a partecipanti vincitori e perdenti relativi all ultimo turno
    std::vector<const partecipante*> vincitori;
    std::vector<const partecipante*> perdenti;
    const std::vector<match>& ultimiMatch = turni[turni.size()-1].getMatches();
    for(size_t i=0;i<ultimiMatch.size();i++){
        //ciclo tutti gli ultimi match
        vincitori.push_back(&(ultimiMatch[i].getVincitore()));
        perdenti.push_back(&(ultimiMatch[i].getPerdente()));
    }

    turno tmp;
    //primo ciclo per accoppiare i vincitori
    for(size_t i=0;i<vincitori.size();i++){
        const partecipante* p1 = vincitori[i];
        if(! (tmp.partecipa(*p1))){ //non abbiamo già scelto il partecipante
            bool trovato=false;
            for(size_t j=0;j<vincitori.size() && !trovato;j++){
                //controllo se sia possibile prima accoppiare vincitori con vincitori
                const partecipante* p2 = vincitori[j];
                //sappiamo che p1 e p2 sono due giocatori che hanno vinto l ultimo turno... vediamo se non sono la stessa persona o non hanno giocato già insieme
                if(!(*p2 == *p1) ){ //QUESTO È IL CONTROLLO CHE NON FA QUELLO CHE VOGLIAMO
                     if (!siSonoScontrati(*p1,*p2)){
                         if(!(tmp.partecipa(*p2))){
                                 tmp.aggiungiMatch(match(*p1,*p2));
                                 trovato = true;
                         }
                     }
                 }
            }

            //se non sono riuscito ad accoppiarlo con un vincitore lo accoppio con un perdente...
            for(size_t j=0;j<perdenti.size() && !trovato;j++){
                //controllo se sia possibile prima accoppiare vincitori con vincitori
                const partecipante* p2 = perdenti[j];
                //sappiamo che p1 e p2 sono due giocatori che hanno vinto l ultimo turno... vediamo se non sono la stessa persona o non hanno giocato già insieme
                if(!(*p2 == *p1) ){
                     if (!siSonoScontrati(*p1,*p2)){
                         if(!(tmp.partecipa(*p2))){
                                 tmp.aggiungiMatch(match(*p1,*p2));
                                 trovato = true;
                         }
                     }
                 }
            }
        }
    }


    //secondo ciclo per accoppiare i perdenti
    for(size_t i=0;i<perdenti.size();i++){
        const partecipante* p1 = perdenti[i];
        if(! (tmp.partecipa(*p1))){ //non abbiamo già scelto il partecipante
            bool trovato=false;
            for(size_t j=0;j<perdenti.size() && !trovato;j++){
                //controllo se sia possibile prima accoppiare perdenti con perdenti
                const partecipante* p2 = perdenti[j];
                //sappiamo che p1 e p2 sono due giocatori che hanno vinto l ultimo turno... vediamo se non sono la stessa persona o non hanno giocato già insieme
                if(!(*p2 == *p1) ){
                     if (!siSonoScontrati(*p1,*p2)){
                         if(!(tmp.partecipa(*p2))){
                                 tmp.aggiungiMatch(match(*p1,*p2));
                                 trovato = true;
                         }
                     }
                 }
            }

            //se non sono riuscito ad accoppiarlo con un perdente lo accoppio con un vincitore...
            for(size_t j=0;j<vincitori.size() && !trovato;j++){
                //controllo se sia possibile prima accoppiare vincitori con vincitori
                const partecipante* p2 = vincitori[j];
                //sappiamo che p1 e p2 sono due giocatori che hanno vinto l ultimo turno... vediamo se non sono la stessa persona o non hanno giocato già insieme
                if(!(*p2 == *p1) ){
                     if (!siSonoScontrati(*p1,*p2)){
                         if(!(tmp.partecipa(*p2))){
                                 tmp.aggiungiMatch(match(*p1,*p2));
                                 trovato = true;
                         }
                     }
                 }
            }
        }
    }

    turni.push_back(tmp);
}

std::string torneoSvizzero::tipologiaTestuale() const{
    return tipoTesto;
}

void torneoSvizzero::inizia(){
    if(partecipanti.size() > 1)
        if(!iniziato){
            if(utility::isPotenzaDiDue(partecipanti.size())){
                //si differenzia da un inizio normale per questa operazione: si ordinano i partecipanti per abilità(ovvero elo discendenti)
                std::sort(partecipanti.begin(),partecipanti.end()); //possibile grazie alla ridefinizione dell'operatore < su partecipante
                iniziato=true;
                turno tmp;
                for(size_t i=0;i<partecipanti.size()/2;i++){
                    int index = i*2;
                    tmp.aggiungiMatch(match(partecipanti[index],partecipanti[index+1]));
                }
                turni.push_back(tmp);
            }
            else
                throw(errore("Servono almeno " + std::to_string(utility::prossimaPotenzaDiDue(partecipanti.size())) + " partecipanti per poter iniziare il torneo"));
        } else throw(errore("Il torneo è già iniziato"));
    else throw(errore("Il numero minimo di partecipanti per un torneo è 2"));
}

short int torneoSvizzero::tipo() const{
    return torneo::ts;
}

torneoSvizzero::torneoSvizzero(std::string n, std::string l, unsigned int p) : torneoVittorieContate(n,l,p) {}

// - TORNEO ELIMINAZIONE DIRETTA -

const std::string torneoEliminazioneDiretta::tipoTesto="Eliminazione diretta";

unsigned int torneoEliminazioneDiretta::nTurniTotale() const{
    if(torneo::getIniziato())
        return utility::prossimoEsponenteDiDue(partecipanti.size()); //ogni giocatore si deve scontrare con ogni altro giocatore
    else
        throw(errore("Non si possono determinare il numero di turni totali prima dell'inizio del torneo"));
}
void torneoEliminazioneDiretta::prossimoTurno(){
    checkProssimoTurno();
    //sappiamo che l ultimo turno è finito, abbiamo iniziato il torneo e si possono ancora aggiugnere turni

    turno tmp;

    const std::vector<match>& matchesUltimoTurno = turni[turni.size()-1].getMatches();
    for(size_t i=0;i<matchesUltimoTurno.size() / 2;i++){
        size_t index = i*2;
        tmp.aggiungiMatch(match(matchesUltimoTurno[index].getVincitore(),matchesUltimoTurno[index+1].getVincitore()  ));
    }

    turni.push_back(tmp);
}

const partecipante& torneoEliminazioneDiretta::getVincitore() const{
    if(!finito())
        throw(errore("Ci sarà un vincitore solo quando il torneo sarà finito"));
    return (turni[turni.size()-1].getMatches())[0].getVincitore();
}

short int torneoEliminazioneDiretta::tipo() const{
    return torneo::ted;
}

std::string torneoEliminazioneDiretta::tipologiaTestuale() const{
    return tipoTesto;
}

torneoEliminazioneDiretta::torneoEliminazioneDiretta(std::string n, std::string l, unsigned int p):torneo(n,l,p){}
