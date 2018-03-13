#include "vistatorneo.h"

//VISTA TORNEO MODIFICABILE

vistaTorneoM::vistaTorneoM(torneo*tp,QWidget*parent) : QWidget(parent),t(tp),selezioneRisultato(nullptr),aggiungiPartecipante(nullptr){
    setWindowTitle(QString::fromStdString(tp->getNomeTorneo()));
    QRect schermo = QApplication::desktop()->screenGeometry();
    setGeometry(schermo);

    vistat = new vistaTurni(t->getTurni(),this);
    vistat->setStyleSheet("background-color:white;");
    vistat->mostraBottoniUltimoTurno();
    connect(vistat,SIGNAL(risultatoCliccato(int)),this,SLOT(risultatoMatchCliccato(int)));
    scroll = new QScrollArea(this);
    info = new vistaInfo(t,this);
    partecipanti = new vistaPartecipanti(t->getPartecipanti(),this);
    operazioni = new vistaOperazioni(this);
    connect(operazioni,SIGNAL(prossimoTurnoPremuto()),this,SLOT(tentaProssimoTurno()));
    connect(operazioni,SIGNAL(aggiungiPartecipantePremuto()),this,SLOT(tentaAggiungiPartecipante()));
    connect(operazioni,SIGNAL(iniziaPremuto()),this,SLOT(tentaInizia()));
    connect(operazioni,SIGNAL(vincitorePremuto()),this,SLOT(tentaVincitore()));


    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(1);
    partecipanti->setSizePolicy(spLeft);

    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(5);
    scroll->setSizePolicy(spRight);

    scroll->setWidgetResizable(true);
    scroll->setWidget(vistat);


    layout = new QGridLayout(this);
    layout->addWidget(info,0,0);
    layout->addWidget(partecipanti,1,0);
    layout->addWidget(operazioni,2,0);
    layout->addWidget(scroll,0,1,3,1);
    setLayout(layout);


}

void vistaTorneoM::risultatoMatchCliccato(int id){
    //chiedi il vincitore dell ultimo turno
    if(selezioneRisultato != nullptr){
        selezioneRisultato->close();
        delete selezioneRisultato;
        selezioneRisultato = nullptr;
    }
    const match& m = (t->getUltimoTurno()).getMatches()[id];
    selezioneRisultato = new richiestaRisultato(m,id,nullptr);
    connect(selezioneRisultato,SIGNAL(sceltoVincitore()),this,SLOT(risultatoMatchDato()));
    selezioneRisultato->show();
}

void vistaTorneoM::risultatoMatchDato(){
    if(selezioneRisultato){
        size_t id = selezioneRisultato->getIndice();
        match::risultatoMatch ris = selezioneRisultato->getRisultato();
        t->setVincitoreUltimoTurno(id,ris);
        vistat->aggiornaTestoMatchUltimoTurno(id);
        selezioneRisultato->close();
    }
}

void vistaTorneoM::keyPressEvent(QKeyEvent * evento){
    if(evento->key() == Qt::Key_P)
        operazioni->cliccaProssimoTurno();
    else if(evento->key() == Qt::Key_A)
        operazioni->cliccaAggiungiPartecipante();
    else if(evento->key() == Qt::Key_I)
            operazioni->cliccaInizia();
    else if(evento->key() == Qt::Key_T)
            operazioni->cliccaVincitore();
    else if(evento->key() == Qt::Key_C)
            operazioni->cliccaChiudi();
}

void vistaTorneoM::tentaProssimoTurno(){
    try{
        t->prossimoTurno();
        vistat->disegnaProssimoTurno();
        vistat->mostraBottoniUltimoTurno();
    } catch(errore e){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText(QString::fromStdString(e.getMessaggio()));
        messaggio->show();
    }
}

void vistaTorneoM::tentaAggiungiPartecipante(){

    if(t->getIniziato()){
        //è iniziato, non puoi aggiungere partecipanti
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non puoi inserire partecipanti una volta iniziato il torneo");
        messaggio->show();
    } else {
        if(aggiungiPartecipante != nullptr){
            aggiungiPartecipante->close();
            delete aggiungiPartecipante;
            aggiungiPartecipante = nullptr;
        }
        aggiungiPartecipante = new vistaAggiungiPartecipante(nullptr);
        aggiungiPartecipante->show();
        connect(aggiungiPartecipante,SIGNAL(premuto()),this,SLOT(datiPartecipanteInseriti()));
    }

}

void vistaTorneoM::datiPartecipanteInseriti(){
    if(aggiungiPartecipante){
        QString s = aggiungiPartecipante->getNome();
        int punti = aggiungiPartecipante->getElo();
        aggiungiPartecipante->close();
        delete aggiungiPartecipante;
        aggiungiPartecipante = nullptr;
        QString copia = s;
        if(copia.replace(' ',"") != ""){
            partecipante p(s.toStdString(),punti);
            try{
                t->inserisciPartecipante(p);
                partecipanti->disegnaVistaPartecipanti();
            }  catch(errore e){
                QMessageBox * messaggio = new QMessageBox(nullptr);
                messaggio->setWindowTitle("Errore");
                messaggio->setIcon(QMessageBox::Warning);
                messaggio->setText(QString::fromStdString(e.getMessaggio()));
                messaggio->show();
            }
        } else {
            QMessageBox * messaggio = new QMessageBox(nullptr);
            messaggio->setWindowTitle("Errore");
            messaggio->setIcon(QMessageBox::Warning);
            messaggio->setText("Inserisci un nome per il partecipante");
            messaggio->show();
        }

    }
}

void vistaTorneoM::tentaInizia(){
    try{
        t->inizia();
        info->aggiornaNTurni();
        vistat->disegnaProssimoTurno();
        vistat->mostraBottoniUltimoTurno();
    } catch(errore e){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText(QString::fromStdString(e.getMessaggio()));
        messaggio->show();
    }
}

void vistaTorneoM::tentaVincitore() const{
    try{
        std::string s = "Il vincitore è "+t->getVincitore().getNome();
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Vincitore");
        messaggio->setIcon(QMessageBox::Information);
        messaggio->setText(QString::fromStdString(s));
        messaggio->show();
    } catch(errore e){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText(QString::fromStdString(e.getMessaggio()));
        messaggio->show();
    }
}

//VISTA TORNEO VISUALIZZABILE

vistaTorneoV::vistaTorneoV(const torneo*tp,QWidget*parent) : QWidget(parent),t(tp){
    setWindowTitle(QString::fromStdString(tp->getNomeTorneo()));
    QRect schermo = QApplication::desktop()->screenGeometry();
    setGeometry(schermo);

    vistat = new vistaTurni(t->getTurni(),this);
    vistat->setStyleSheet("background-color:white;");
    scroll = new QScrollArea(this);
    info = new vistaInfo(t,this);
    partecipanti = new vistaPartecipanti(t->getPartecipanti(),this);

    vincitore = new QPushButton("Vinci&tore",this);
    connect(vincitore,SIGNAL(clicked(bool)),this,SLOT(tentaVincitore()));


    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(1);
    partecipanti->setSizePolicy(spLeft);

    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(5);
    scroll  ->setSizePolicy(spRight);

    scroll->setWidgetResizable(true);
    scroll->setWidget(vistat);


    layout = new QGridLayout(this);
    layout->addWidget(info,0,0);
    layout->addWidget(partecipanti,1,0);
    layout->addWidget(vincitore,2,0);
    layout->addWidget(scroll,0,1,3,1);
    setLayout(layout);
}

void vistaTorneoV::tentaVincitore(){
    try{
        std::string s = "Il vincitore è "+t->getVincitore().getNome();
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Vincitore");
        messaggio->setIcon(QMessageBox::Information);
        messaggio->setText(QString::fromStdString(s));
        messaggio->show();
    } catch(errore e){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText(QString::fromStdString(e.getMessaggio()));
        messaggio->show();
    }
}

void vistaTorneoV::keyPressEvent(QKeyEvent * evento){
    if(evento->key() == Qt::Key_T)
            tentaVincitore();
}

//VISTA TURNI

std::string vistaTurni::stileIntestazione="background-color: #A0A0A0; border: 1px solid black; border-radius: 10px; font-weight: bold;";

vistaTurni::vistaTurni(const std::vector<turno>& t,QWidget*parent) : QWidget(parent),turnidata(t){

    layout= new QGridLayout(this);
    QRect schermo = QApplication::desktop()->screenGeometry();

    for(size_t i = 0;i<turnidata.size();i++){
        turni.push_back(new vistaTurno(turnidata[i],this));

        std::string s= "Turno " + std::to_string(i+1);

        QLabel * intestazione = new QLabel(this);
        intestazione->setStyleSheet(QString::fromStdString(stileIntestazione));
        intestazione->setText(QString::fromStdString(s));
        intestazione->setAlignment(Qt::AlignCenter);
        intestazione->setFixedHeight(schermo.height()/7);
        intestazione->setFixedWidth(schermo.width()/5 );
        intestazione->setAlignment(Qt::AlignCenter);

        layout->addWidget(intestazione,0,i);
        layout->addWidget(turni[i],1,i);
    }
    layout->setAlignment(Qt::AlignLeft);
    setLayout(layout);
}

void vistaTurni::aggiornaTestoMatchUltimoTurno(size_t idMatch){
    if(turni.size() > 0){
        turni[turni.size()-1]->aggiornaTestoMatch(idMatch);
    }
}

void vistaTurni::mostraBottoniUltimoTurno(){
    if(turni.size() > 0){
        turni[turni.size()-1]->mostraBottoniRisultati();
        connect(turni[turni.size()-1],SIGNAL(risultatoMatchCliccato(int)),this,SIGNAL(risultatoCliccato(int)));
    }
}

void vistaTurni::disegnaProssimoTurno(){
    if(turnidata.size() > turni.size()){
        //posso aggiornare
        QRect schermo = QApplication::desktop()->screenGeometry();
        int i = turnidata.size()-1;
        turni.push_back(new vistaTurno(turnidata[i],this));
        std::string s= "Turno " + std::to_string(i+1);
        QLabel * intestazione = new QLabel(this);
        intestazione->setStyleSheet(QString::fromStdString(stileIntestazione));
        intestazione->setText(QString::fromStdString(s));
        intestazione->setAlignment(Qt::AlignCenter);
        intestazione->setFixedHeight(schermo.height()/7);
        intestazione->setFixedWidth(schermo.width()/5 );
        intestazione->setAlignment(Qt::AlignCenter);
        layout->addWidget(intestazione,0,i);
        layout->addWidget(turni[i],1,i);

        if(i > 0){
            //toglo i bottoni al turno precedente
            turni[i-1]->togliBottoniRisultati();
        }
    }
}

//VISTA TURNO

vistaTurno::vistaTurno(const turno& tur,QWidget* parent) : t(tur), QWidget(parent),mappaRisultati(nullptr){
    layout = new QVBoxLayout(this);
    for(size_t i = 0;i<t.getMatches().size();i++){
        vistaMatch* m = new vistaMatch(t.getMatches()[i],this);
        matches.push_back(m);
        layout->addWidget(matches[i]);
    }
    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
}

void vistaTurno::aggiornaTestoMatch(size_t id){
    if(id < matches.size())
        matches[id]->aggiornaTesto();
}

void vistaTurno::mostraBottoniRisultati(){
    if(mappaRisultati){
        delete mappaRisultati;
        mappaRisultati = nullptr;
    }
    mappaRisultati = new QSignalMapper(this);
    for(size_t i =0;i<matches.size();i++){
        matches[i]->mostraBottone();
        connect(matches[i],SIGNAL(risultatoCliccato()),mappaRisultati,SLOT(map()));
        mappaRisultati->setMapping(matches[i],i);
    }
    connect(mappaRisultati,SIGNAL(mapped(int)),this,SIGNAL(risultatoMatchCliccato(int)));
}

void vistaTurno::togliBottoniRisultati(){
    if(mappaRisultati){
        delete mappaRisultati;
        mappaRisultati = nullptr;
    }
    for(size_t i = 0;i<matches.size();i++){
        matches[i]->togliBottone();
    }
}

//VISTA MATCH

std::string vistaMatch::stile = "background-color: lightgrey; border: 1px solid black; border-radius: 10px;";

vistaMatch::vistaMatch(const match& mat,QWidget* parent) : QWidget(parent),m(mat),mettiRisultato(nullptr){
    QRect schermo = QApplication::desktop()->screenGeometry();
    setFixedHeight(schermo.height()/5);
    setFixedWidth(schermo.width()/5 );

    testo = new QLabel(this);
    testo->setText(testoDaScrivere());
    testo->setAlignment(Qt::AlignCenter);
    testo->setStyleSheet(QString::fromStdString(stile));

    layout= new QGridLayout(this);
    layout->addWidget(testo,0,0);
    setLayout(layout);
}

QString vistaMatch::testoDaScrivere() const{
    std::string s = m.getP1().getNome() + "\n"
            +   "vs\n"
            + m.getP2().getNome()+"\n"
            + (m.finito() ? (std::string("vincitore: " + m.getVincitore().getNome())) : ("in corso"))
            ;
    return QString::fromStdString(s);
}

void vistaMatch::aggiornaTesto(){
    if(testo)
        testo->setText(testoDaScrivere());
}

void vistaMatch::mostraBottone(){
    if(!mettiRisultato){
        mettiRisultato = new QPushButton("Inserisci risultato",this);
        connect(mettiRisultato,SIGNAL(clicked(bool)),this,SIGNAL(risultatoCliccato())); //quando premuto manda un signal ai connessi
        layout->addWidget(mettiRisultato,1,0);
    }
}

void vistaMatch::togliBottone(){
    if(mettiRisultato && mettiRisultato->isVisible()){
        layout->removeWidget(mettiRisultato);
        mettiRisultato->close();
        delete mettiRisultato;
        mettiRisultato = nullptr;
    }
}

// VISTAINFO

std::string vistaInfo::stile="background-color: #77C7EE; border: 1px solid black; border-radius: 10px;";

vistaInfo::vistaInfo(const torneo* tor,QWidget* parent): QWidget(parent),nturni(nullptr),nturniint(nullptr),t(tor){
    QString fontint("font-style: italic;"); //da mettere static
    QString fontattr("font-weight: bold;"); //font attributo

    nome = new QLabel(QString::fromStdString(t->getNomeTorneo()),this);
    nome->setStyleSheet(fontattr);
    nome->setAlignment(Qt::AlignCenter);
    luogo= new QLabel(QString::fromStdString(t->getLuogoTorneo()),this);
    luogo->setStyleSheet(fontattr);
    luogo->setAlignment(Qt::AlignCenter);
    tipologia= new QLabel(QString::fromStdString(t->tipologiaTestuale()),this);
    tipologia->setStyleSheet(fontattr);
    tipologia->setAlignment(Qt::AlignCenter);
    punteggio= new QLabel(QString::fromStdString(std::to_string(t->getPunteggioMinimo())),this);
    punteggio->setStyleSheet(fontattr);
    punteggio->setAlignment(Qt::AlignCenter);

    nomeint = new QLabel("Nome: ",this);
    nomeint->setStyleSheet(fontint);
    luogoint= new QLabel("Luogo: ",this);
    luogoint->setStyleSheet(fontint);
    tipologiaint= new QLabel("Tipologia: ",this);
    tipologiaint->setStyleSheet(fontint);
    punteggioint= new QLabel("ELO minimo: ",this);
    punteggioint->setStyleSheet(fontint);

    layout= new QVBoxLayout(this);
    layout->addWidget(nomeint);
    layout->addWidget(nome);
    layout->addWidget(luogoint);
    layout->addWidget(luogo);
    layout->addWidget(tipologiaint);
    layout->addWidget(tipologia);
    layout->addWidget(punteggioint);
    layout->addWidget(punteggio);

    aggiornaNTurni();
    setLayout(layout);

    QPalette p;
    p.setColor(QPalette::Background,QColor::fromRgb(128,128,128));
    setAutoFillBackground(true);
    setPalette(p);
}

void vistaInfo::aggiornaNTurni(){
    if(t->getIniziato()){
        if(nturni && nturniint){
            layout->removeWidget(nturni);
            layout->removeWidget(nturniint);
            nturni->close();
            nturniint->close();
            delete nturni;
            delete nturniint;
        }
        QString fontint("font-style: italic;"); //font intestazione
        QString fontattr("font-weight: bold;"); //font attributo
        nturni = new QLabel(QString::fromStdString(std::to_string(t->nTurniTotale())),this);
        nturni->setStyleSheet(fontattr);
        nturni->setAlignment(Qt::AlignCenter);
        nturniint = new QLabel("Numero di turni in totale: ",this);
        nturniint->setStyleSheet(fontint);
        layout->addWidget(nturniint);
        layout->addWidget(nturni);
    }
}

//VISTA PARTECIPANTI

vistaPartecipanti::vistaPartecipanti(const std::vector<partecipante>& p, QWidget * parent) : part(p),QWidget(parent),listaPartecipanti(nullptr),intestazione(nullptr){

    layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);
    disegnaVistaPartecipanti();
    setLayout(layout);
    QPalette pal;
    pal.setColor(QPalette::Background,QColor::fromRgb(128,128,128));
    setAutoFillBackground(true);
    setPalette(pal);
}

QString vistaPartecipanti::stringaIntestazione() const{
    std::string s = "Partencipanti["+std::to_string(part.size())+"]";
    return QString::fromStdString(s);
}

void vistaPartecipanti::disegnaVistaPartecipanti(){
    if(intestazione){
        layout->addWidget(intestazione);
        intestazione->close();
        delete intestazione;
        intestazione = nullptr;
    }

    intestazione = new QLabel(stringaIntestazione(),this);
    layout->addWidget(intestazione);

    if(listaPartecipanti){
        layout->addWidget(listaPartecipanti);
        listaPartecipanti->close();
        delete listaPartecipanti;
        listaPartecipanti = nullptr;
    }

    listaPartecipanti = new QListWidget(this);
    for(size_t i = 0;i<part.size(); i++){
        QString partec;
        partec = QString::fromStdString(part[i].getNome() + " - " +std::to_string(part[i].getElo()));
        listaPartecipanti->addItem(partec);
    }
    listaPartecipanti->setStyleSheet("background-color:#A0A0A0;");
    layout->addWidget(listaPartecipanti);
}

//RICHIESTA RISULTATO

richiestaRisultato::richiestaRisultato(const match &m,size_t i, QWidget * parent):QWidget(parent),risposta(-1),id(i){
    setWindowTitle("Immetti risultato");
    QRect rec = QApplication::desktop()->screenGeometry();
    int h = rec.height();
    int w = rec.width();
    int larg = w/3;
    int alt = h/4;
    int x = w/2 - larg/2;
    int y = h/2 - alt/2;
    setGeometry(x,y,larg,alt);
    setFixedSize(size());

    gruppo = new QGroupBox(this);
    uno = new QPushButton(this);
    uno->setText(QString::fromStdString(m.getP1().getNome()));
    uno->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(uno,SIGNAL(clicked(bool)),this,SLOT(sceltoUno()));
    due = new QPushButton(this);
    due->setText(QString::fromStdString(m.getP2().getNome()));
    due->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(due,SIGNAL(clicked(bool)),this,SLOT(sceltoDue()));
    nessuno = new QPushButton(this);
    nessuno->setText("In corso");
    nessuno->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(nessuno,SIGNAL(clicked(bool)),this,SLOT(sceltoNessuno()));

    layoutgruppo = new QHBoxLayout(this);
    layoutgruppo->addWidget(uno);
    layoutgruppo->addWidget(due);
    layoutgruppo->addWidget(nessuno);
    gruppo->setLayout(layoutgruppo);

    QString s = QString::fromStdString("Inserisci il risultato del match di " + m.getP1().getNome() + " contro "+m.getP2().getNome());
    descrizione = new QLabel(s,this);
    descrizione->setStyleSheet("font-style: italic;");
    descrizione->setAlignment(Qt::AlignCenter);

    layout = new QGridLayout(this);
    layout->addWidget(descrizione,0,0);
    layout->addWidget(gruppo,1,0);
    setLayout(layout);
}


void richiestaRisultato::sceltoUno(){
    risposta = 1;
    sceltoVincitore();
}

void richiestaRisultato::sceltoDue(){
    risposta = 2;
    sceltoVincitore();
}

void richiestaRisultato::sceltoNessuno(){
    risposta=-1;
    sceltoVincitore();
}

size_t richiestaRisultato::getIndice() const {return id;}

match::risultatoMatch richiestaRisultato::getRisultato() const{return risposta;}

//VISTA OPZIONI

vistaOperazioni::vistaOperazioni(QWidget * parent):QWidget(parent){
    prossimoTurno = new QPushButton("&Prossimo turno",this);
    connect(prossimoTurno,SIGNAL(clicked(bool)),this,SIGNAL(prossimoTurnoPremuto()));
    aggiungiPartecipante = new QPushButton("&Aggiungi partecipante",this);
    connect(aggiungiPartecipante,SIGNAL(clicked(bool)),this,SIGNAL(aggiungiPartecipantePremuto()));
    inizia = new QPushButton("&Inizia torneo",this);
    connect(inizia,SIGNAL(clicked(bool)),this,SIGNAL(iniziaPremuto()));
    chiudi = new QPushButton("&Chiudi",this);
    connect(chiudi,SIGNAL(clicked(bool)),parent,SLOT(close()));

    vincitore = new QPushButton("Vinci&tore",this);
    connect(vincitore,SIGNAL(clicked(bool)),this,SIGNAL(vincitorePremuto()));

    layout = new QGridLayout(this);
    layout->addWidget(prossimoTurno,0,0);
    layout->addWidget(aggiungiPartecipante,1,0);
    layout->addWidget(inizia,2,0);
    layout->addWidget(vincitore,3,0);
    layout->addWidget(chiudi,4,0);
    setLayout(layout);
}

void vistaOperazioni::cliccaProssimoTurno(){
    if(prossimoTurno)
        prossimoTurno->click();
}

void vistaOperazioni::cliccaAggiungiPartecipante(){
    if(aggiungiPartecipante)
        aggiungiPartecipante->click();
}

void vistaOperazioni::cliccaInizia(){
    if(inizia)
        inizia->click();
}

void vistaOperazioni::cliccaChiudi(){
    if(chiudi)
        chiudi->click();
}

void vistaOperazioni::cliccaVincitore(){
    if(vincitore)
        vincitore->click();
}

//VISTA AGGIUNGI PARTECIPANTE

vistaAggiungiPartecipante::vistaAggiungiPartecipante(QWidget * parent) : QWidget(parent){
    setWindowTitle("Inserisci partecipante");
    QRect rec = QApplication::desktop()->screenGeometry();
    int h = rec.height();
    int w = rec.width();
    int larg = w/5;
    int alt = h/7;
    int x = w/2 - larg/2;
    int y = h/2 - alt/2;

    setGeometry(x,y,larg,this->minimumHeight());
    setFixedSize(size());

    nomelabel = new QLabel("Nome",this);
    nomelabel->setAlignment(Qt::AlignCenter);
    nome = new QLineEdit(this);

    punteggiolabel = new QLabel("ELO",this);
    punteggiolabel->setAlignment(Qt::AlignCenter);
    punteggio = new QSpinBox(this);
    punteggio->setRange(0,INT_MAX);

    conferma = new QPushButton("Conferma",this);
    connect(conferma,SIGNAL(clicked(bool)),this,SIGNAL(premuto()));

    layout = new QGridLayout(this);
    layout->addWidget(nomelabel,0,0);
    layout->addWidget(nome,1,0);
    layout->addWidget(punteggiolabel,2,0);
    layout->addWidget(punteggio,3,0);
    layout->addWidget(conferma,4,0);
}

QString vistaAggiungiPartecipante::getNome() const{
    return nome->text();
}
int vistaAggiungiPartecipante::getElo() const{
    return punteggio->value();
}
