#include "principale.h"

principale::principale(C& c,QWidget*parent) : QWidget(parent),contenitore(c),nt(nullptr),vp(nullptr){
    setWindowTitle("Chess Tournament Handler");
    QRect schermo = QApplication::desktop()->screenGeometry();
    setGeometry(schermo);

    if(dynamic_cast<const utenteRicercaAvanzata*>(contenitore.getUtente()) != 0)
        r = new ricercaAvanzata(this);
    else
        r = new ricerca(this);
    connect(r,SIGNAL(premutoCerca()),this,SLOT(cercaPremuto()));
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(1);
    r->setSizePolicy(spLeft);

    vr = new visualizzatoreRicerche(contenitore,this);
    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(3);
    vr->setSizePolicy(spRight);

    b = new bottoni(dynamic_cast<const utenteAdmin*>(contenitore.getUtente()) != nullptr,this);
    connect(b,SIGNAL(logoutPremuto()),this,SIGNAL(logout()));
    connect(b,SIGNAL(creaTorneoPremuto()),this,SLOT(nuovoTorneoPremuto()));
    connect(b,SIGNAL(profiloPremuto()),this,SLOT(profiloPremuto()));
    connect(b,SIGNAL(amministrazionePremuto()),this,SIGNAL(amministrazionePremuto()));

    icona = new QPixmap("horse.png");
    iconalabel = new QLabel(this);
    iconalabel->setPixmap(*icona);
    iconalabel->setAlignment(Qt::AlignCenter);
    iconalabel->setMaximumHeight(this->height() - r->height() - b->height()-schermo.height()/2 -40);

    contenitore.cerca();
    vr->disegnaTornei();

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(r,0,0,1,1);
    layout->addWidget(iconalabel,1,0,1,1);
    layout->addWidget(b,2,0,1,1);
    layout->addWidget(vr,0,1,3,1);

    setLayout(layout);
}

void principale::cercaPremuto(){
    contenitore.cerca(r->getNomeTorneo(),r->getLuogoTorneo(),r->getPuntiTorneo());
    vr->disegnaTornei();
}

void principale::nuovoTorneoPremuto(){
    if(nt){
        nt->close();
        delete nt;
        nt = nullptr;
    }

    nt = new nuovoTorneo(nullptr);
    nt->show();
    connect(nt,SIGNAL(confermaPremuto()),this,SLOT(datiTorneiInseriti()));
}

void principale::datiTorneiInseriti(){
    if(nt){
        std::string n = nt->getNome().toStdString();
        std::string l = nt->getLuogo().toStdString();
        int i = nt->getPunteggio();
        short int tipo = nt->getTipologia();
        if(contenitore.nomeTorneoUtilizzato(n)){
            QMessageBox * messaggio = new QMessageBox(nullptr);
            messaggio->setWindowTitle("Errore");
            messaggio->setIcon(QMessageBox::Warning);
            messaggio->setText("Impossibile creare il torneo: il nome è già stato utilizzato");
            messaggio->show();
        } else {
            nt->close();
            delete nt;
            nt = nullptr;
            torneo * t = nullptr;
            if(tipo == torneo::trr){
                t = new torneoRr(n,l,i);
            } else if (tipo == torneo::ts){
                t = new torneoSvizzero(n,l,i);
            }else if (tipo == torneo::ted){
                t = new torneoEliminazioneDiretta(n,l,i);
            } else if(tipo == torneo::trrd){
                t= new torneoRrDoppio(n,l,i);
            }
            if(t != nullptr && contenitore.creaTorneo(t)){
                vr->disegnaTornei();
            } else {
                QMessageBox * messaggio = new QMessageBox(nullptr);
                messaggio->setWindowTitle("Errore");
                messaggio->setIcon(QMessageBox::Warning);
                messaggio->setText("Non è stato possibile creare il torneo");
                messaggio->show();
            }
        }
    }
}

void principale::profiloPremuto(){
    if(vp){
        vp->close();
        delete vp;
        vp = nullptr;
    }

    vp = new vistaProfilo(contenitore,*(contenitore.getUtente()),nullptr);
    vp->show();
    connect(vp,SIGNAL(confermaEliminaProfilo()),this,SLOT(confermaEliminaProfilo()));
}

void principale::confermaEliminaProfilo(){
    contenitore.cancellaProfilo();
    QMessageBox * messaggio = new QMessageBox(nullptr);
    messaggio->setWindowTitle("Profilo eliminato");
    messaggio->setIcon(QMessageBox::Warning);
    messaggio->setText("Il tuo profilo è stato eliminato correttamente");
    messaggio->show();
    logout();
}

principale::~principale(){
    if(nt != nullptr) nt->close();
    if(vp != nullptr) vp->close();
}

//BOTTONI
bottoni::bottoni(bool a, QWidget * parent) : amministratore(a),admin(nullptr), QWidget(parent){
    layout = new QVBoxLayout(this);
    creaTorneo = new QPushButton("Crea torneo",this);
    connect(creaTorneo,SIGNAL(clicked(bool)),this,SIGNAL(creaTorneoPremuto()));
    profilo = new QPushButton("Profilo",this);
    connect(profilo,SIGNAL(clicked(bool)),this,SIGNAL(profiloPremuto()));
    logout = new QPushButton("Logout",this);
    connect(logout,SIGNAL(clicked(bool)),this,SIGNAL(logoutPremuto()));
    chiudi = new QPushButton("Chiudi",this);
    connect(chiudi,SIGNAL(clicked(bool)),qApp,SLOT(quit()));
    layout->addWidget(creaTorneo);
    layout->addWidget(profilo);
    layout->addWidget(logout);
    layout->addWidget(chiudi);
    if(amministratore){
        admin = new QPushButton("Amministrazione",this);
        connect(admin,SIGNAL(clicked(bool)),this,SIGNAL(amministrazionePremuto()));
        layout->addWidget(admin);
    }
    layout->setAlignment(Qt::AlignBottom);
    setLayout(layout);
}

//NUOVO TORNEO

nuovoTorneo::nuovoTorneo(QWidget * parent) : QWidget(parent){

    setWindowTitle("Creazione nuovo torneo");
    QRect rec = QApplication::desktop()->screenGeometry();
    int h = rec.height();
    int w = rec.width();
    int larg = w/4;
    int alt = h/4;
    int x = w/2 - larg/2;
    int y = h/2 - alt/2;
    setGeometry(x,y,minimumWidth(),minimumHeight());
    setFixedSize(size());


    layout = new QGridLayout(this);

    nomeLabel= new QLabel("Nome torneo",this);
    nomeLabel->setAlignment(Qt::AlignCenter);
    nome = new QLineEdit(this);
    luogoLabel = new QLabel("Luogo torneo",this);
    luogoLabel->setAlignment(Qt::AlignCenter);
    luogo = new QLineEdit(this);
    punteggioLabel = new QLabel("ELO minimo");
    punteggioLabel->setAlignment(Qt::AlignCenter);
    punteggio = new QSpinBox(this);
    punteggio->setRange(0,INT_MAX);
    conferma = new QPushButton("Conferma",this);
    connect(conferma,SIGNAL(clicked(bool)),this,SLOT(tentaConferma()));

    sv = new QRadioButton("Svizzero",this);
    sv->setChecked(true);
    rr = new QRadioButton("Round Robin",this);
    ed = new QRadioButton("Eliminazione diretta",this);
    rrd = new QRadioButton("Round Robin Doppio",this);

    layout->addWidget(nomeLabel,layout->rowCount(),0,1,4);
    layout->addWidget(nome,layout->rowCount(),0,1,4);
    layout->addWidget(luogoLabel,layout->rowCount(),0,1,4);
    layout->addWidget(luogo,layout->rowCount(),0,1,4);
    layout->addWidget(punteggioLabel,layout->rowCount(),0,1,4);
    layout->addWidget(punteggio,layout->rowCount(),0,1,4);
    layout->addWidget(sv,layout->rowCount(),0);
    layout->addWidget(rr,layout->rowCount()-1,1);
    layout->addWidget(ed,layout->rowCount()-1,2);
    layout->addWidget(rrd,layout->rowCount()-1,3);
    layout->addWidget(conferma,layout->rowCount(),0,1,4);
    setLayout(layout);
}

void nuovoTorneo::tentaConferma() const{
    QString copiaNome = nome->text();
    QString copiaLuogo = nome->text();
    if( copiaNome.replace(' ',"") != "" || copiaLuogo.replace(' ',"") != ""){
        confermaPremuto();
    } else {
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Inserisci un nome per il torneo e il luogo in cui si svolgerà");
        messaggio->show();
    }
}

QString nuovoTorneo::getNome() const{
    return nome->text();
}
QString nuovoTorneo::getLuogo() const{
    return luogo->text();
}
int nuovoTorneo::getPunteggio() const{
    return punteggio->value();
}

short int nuovoTorneo::getTipologia() const{
    if(rr->isChecked())
        return torneo::trr;
    else if(sv->isChecked())
        return torneo::ts;
    else if(ed->isChecked())
        return torneo::ted;
    else if(rrd->isChecked())
        return torneo::trrd;
    return -1;
}



visualizzatoreRicerche::visualizzatoreRicerche(C& contenitore,QWidget* parent) :
    contenitore(contenitore),  QWidget(parent){
    vistatornei = new QTableWidget(this);
    vistatornei->setEditTriggers(QTableView::NoEditTriggers);
    vistatornei->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    QStringList colonne;
    colonne << "Nome" <<"Luogo"<<"ELO minimo"<<"Tipologia"<<""<<"";

    vistatornei->setColumnCount(6);
    vistatornei->setHorizontalHeaderLabels(colonne);

    layout = new QGridLayout(this);
    layout->addWidget(vistatornei);
    setLayout(layout);
}

void visualizzatoreRicerche::disegnaTornei(){
    vistatornei->setRowCount(0);
    torneim.clear();
    torneim = (QVector<torneo *>::fromStdVector(contenitore.getModificabili()));
    for(auto i=0;i<torneim.size();i++){
        vistatornei->insertRow(vistatornei->rowCount());
        vistatornei->setItem(vistatornei->rowCount()-1,NOME,new QTableWidgetItem(QString::fromStdString(torneim[i]->getNomeTorneo())));
        vistatornei->setItem(vistatornei->rowCount()-1,LUOGO,new QTableWidgetItem(QString::fromStdString(torneim[i]->getLuogoTorneo())));
        vistatornei->setItem(vistatornei->rowCount()-1,PUNTI,new QTableWidgetItem(QString::number(torneim[i]->getPunteggioMinimo())));
        vistatornei->setItem(vistatornei->rowCount()-1,TIPOLOGIA, new QTableWidgetItem(QString::fromStdString(torneim[i]->tipologiaTestuale())));
        vistatornei->setCellWidget(vistatornei->rowCount()-1,AZIONE,new bottoneTorneoModificabile(torneim[i],"Modifica",this));
        bottoneEliminazione * b = new bottoneEliminazione(i,"Elimina",this);
        vistatornei->setCellWidget(vistatornei->rowCount()-1,ELIMINA,b);
        connect(b,SIGNAL(torneoEliminato(size_t)),this,SLOT(eliminaTorneo(size_t)));
    }
    torneiv.clear();
    torneiv = (QVector<const torneo *>::fromStdVector(contenitore.getVisualizzabili()));
    for(auto i=0;i<torneiv.size();i++){
        vistatornei->insertRow(vistatornei->rowCount());
        vistatornei->setItem(vistatornei->rowCount()-1,NOME,new QTableWidgetItem(QString::fromStdString(torneiv[i]->getNomeTorneo())));
        vistatornei->setItem(vistatornei->rowCount()-1,LUOGO,new QTableWidgetItem(QString::fromStdString(torneiv[i]->getLuogoTorneo())));
        vistatornei->setItem(vistatornei->rowCount()-1,PUNTI,new QTableWidgetItem(QString::number(torneiv[i]->getPunteggioMinimo())));
        vistatornei->setItem(vistatornei->rowCount()-1,TIPOLOGIA, new QTableWidgetItem(QString::fromStdString(torneiv[i]->tipologiaTestuale())));
        vistatornei->setCellWidget(vistatornei->rowCount()-1,4,new bottoneTorneoVisualizzabile(torneiv[i],"Visualizza",this));
    }
}

void visualizzatoreRicerche::eliminaTorneo(size_t index){
    contenitore.eliminaTorneo(contenitore.getModificabili()[index]);
    disegnaTornei();
}

//BOTTONE TORNEO MODIFICABILE
void bottoneTorneoModificabile::premuto() const{
    vistaTorneoM* fin = new vistaTorneoM(t,nullptr);
    fin->show();
}

bottoneTorneoModificabile::bottoneTorneoModificabile(torneo* tp,QString label,QWidget * parent) : t(tp),QPushButton(label,parent){
    connect(this,SIGNAL(clicked(bool)),this,SLOT(premuto()));
}

//BOTTONE TORNEO VISUALIZZABILE
void bottoneTorneoVisualizzabile::premuto() const{
    vistaTorneoV* v = new vistaTorneoV(t,nullptr);
    v->show();
}

bottoneTorneoVisualizzabile::bottoneTorneoVisualizzabile(const torneo* tp,QString label,QWidget * parent) : t(tp),QPushButton(label,parent){
    connect(this,SIGNAL(clicked(bool)),this,SLOT(premuto()));
}

//BOTTONE TORNEO ELIMINAZIONE
bottoneEliminazione::bottoneEliminazione(size_t i,QString label,QWidget * parent) : index(i),QPushButton(label,parent){
    connect(this,SIGNAL(clicked(bool)),this,SLOT(premuto()));
}

void bottoneEliminazione::premuto() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Conferma", "Sicuro di voler eliminare il torneo? Non sarà possibile recuperarlo in futuro",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      torneoEliminato(index);
    }

}

//RICERCA
ricerca::ricerca(QWidget* parent)
    :QWidget(parent)
{
    nomet = new QLineEdit(this);
    nomet->setPlaceholderText("Non filtrare per nome");
    cercabottone = new QPushButton(this);
    cercabottone->setText("Cerca");
    connect(cercabottone,SIGNAL(clicked(bool)),this,SIGNAL(premutoCerca()));

    nometlabel = new QLabel(this);
    nometlabel->setText("nome torneo: ");

    layout = new QGridLayout(this);
    layout->addWidget(nometlabel,0,0);
    layout->addWidget(nomet,1,0);
    layout->addWidget(cercabottone,6,0);

    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
}
std::string ricerca::getNomeTorneo() const{
    return nomet->text().toUtf8().constData();
}
std::string ricerca::getLuogoTorneo() const{
    return "";
}
unsigned int ricerca::getPuntiTorneo() const{
    return 0;
}

ricercaAvanzata::ricercaAvanzata(QWidget * parent) : ricerca(parent){
    luogot = new QLineEdit(this);
    luogot->setPlaceholderText("Non filtrare per luogo");
    puntit = new QSpinBox(this);
    puntit->setRange(0,INT_MAX);
    luogotlabel = new QLabel(this);
    luogotlabel->setText("luogo torneo: ");
    puntitlabel = new QLabel(this);
    puntitlabel->setText("ELO minimo: ");
    layout->addWidget(luogot,3,0);
    layout->addWidget(luogotlabel,2,0);
    layout->addWidget(puntitlabel,4,0);
    layout->addWidget(puntit,5,0);
}

std::string ricercaAvanzata::getLuogoTorneo() const{
    return luogot->text().toUtf8().constData();
}
unsigned int ricercaAvanzata::getPuntiTorneo() const{
    return puntit->value();
}

ricerca::~ricerca() {}
