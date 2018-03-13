#include "vistaprofilo.h"


//VISTA PROFILO

vistaProfilo::vistaProfilo(C& c, utente &u, QWidget * parent) : profilo(u),contenitore(c),QWidget(parent),m(nullptr){
    setWindowTitle(QString::fromStdString(profilo.getUsername()));
    QRect rec = QApplication::desktop()->screenGeometry();
    int h = rec.height();
    int w = rec.width();
    int larg = w/4;
    int alt = h/3;
    int x = w/2 - larg/2;
    int y = h/2 - alt/2;
    setGeometry(x,y,larg,alt);
    setFixedSize(size());



    nomeint = new QLabel("Nome: ",this);
    nomeint->setAlignment(Qt::AlignTop);
    nome = new QLabel();
    nome->setAlignment(Qt::AlignTop);
    nome->setText(QString::fromStdString(profilo.getUsername()));

    luogoint = new QLabel("Luogo: ",this);
    luogoint->setAlignment(Qt::AlignTop);
    luogo = new QLabel(this);
    luogo->setAlignment(Qt::AlignTop);
    luogo->setText(QString::fromStdString(profilo.getLuogo()));

    tipologiaint = new QLabel("Tipologia utente: ",this);
    tipologiaint->setAlignment(Qt::AlignTop);
    tipologia = new QLabel(this);
    tipologia->setAlignment(Qt::AlignTop);
    tipologia->setText(QString::fromStdString(profilo.tipologiaTestuale()));

    privilegi= new QLabel(this);
    privilegi->setWordWrap(true);
    privilegi->setAlignment(Qt::AlignJustify);
    privilegi->setText(QString::fromStdString(profilo.descrizioneTipologia()));
    QString italic("font-style: italic;");
    privilegi->setStyleSheet(italic);

    chiudi = new QPushButton("Chiudi",this);
    connect(chiudi,SIGNAL(clicked(bool)),this,SLOT(close()));

    eliminaProfilo = new QPushButton("Elimina Profilo",this);
    connect(eliminaProfilo,SIGNAL(clicked(bool)),this,SLOT(cliccaEliminaProfilo()));
    cambiaLuogo = new QPushButton("Cambia luogo",this);
    connect(cambiaLuogo,SIGNAL(clicked(bool)),this,SLOT(cliccaCambiaLuogo()));
    cambiaPassword = new QPushButton("Cambia password",this);
    connect(cambiaPassword,SIGNAL(clicked(bool)),this,SLOT(cliccaCambiaPassword()));

    layout = new QGridLayout(this);
    layout->addWidget(nomeint,0,0);
    layout->addWidget(nome,0,1);
    layout->addWidget(luogoint,1,0);
    layout->addWidget(luogo,1,1);

    layout->addWidget(tipologiaint,2,0);
    layout->addWidget(tipologia,2,1);

    layout->addWidget(privilegi,3,0,1,2);
    layout->addWidget(cambiaLuogo,4,0);
    layout->addWidget(cambiaPassword,4,1);
    layout->addWidget(eliminaProfilo,5,0);
    layout->addWidget(chiudi,5,1);
    setLayout(layout);
}

void vistaProfilo::cliccaEliminaProfilo() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Conferma", "Confermi di voler eliminare il tuo profilo? Non sarà più possibile in un secondo momento recuperarne i dati",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      confermaEliminaProfilo();
    }
}

void vistaProfilo::cliccaCambiaLuogo(){
    if(m){
        m->close();
        delete m;
        m = nullptr;
    }
    m = new modificaLuogo(contenitore,nullptr);
    connect(m,SIGNAL(fatto()),this,SLOT(parametroModificato()));
    m->show();
}

void vistaProfilo::cliccaCambiaPassword(){
    if(m){
        m->close();
        delete m;
        m = nullptr;
    }
    m = new modificaPassword(contenitore,nullptr);
    connect(m,SIGNAL(fatto()),this,SLOT(parametroModificato()));
    m->show();
}

void vistaProfilo::parametroModificato(){
    if(m){
        m->close();
        delete m;
        m = nullptr;
    }
    luogo->setText(QString::fromStdString(profilo.getLuogo()));
    modificaEffettuata();
}

//VISTA PROFILO PER ADMIN

vistaProfiloPerAdmin::vistaProfiloPerAdmin(C& c,utente& u,QWidget * parent) : vistaProfilo(c,u,parent){}

void vistaProfiloPerAdmin::cliccaEliminaProfilo(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Conferma", "Confermi di voler eliminare il profilo di "+QString::fromStdString(profilo.getUsername())+"? Non sarà più possibile in un secondo momento recuperarne i dati",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if(contenitore.eliminaUtente(&profilo)){
            QMessageBox * messaggio = new QMessageBox(nullptr);
            messaggio->setWindowTitle("Successo");
            messaggio->setIcon(QMessageBox::Information);
            messaggio->setText("Il profilo è stato eliminato correttamente");
            messaggio->show();
            confermaEliminaProfilo();
        } else {
            QMessageBox * messaggio = new QMessageBox(nullptr);
            messaggio->setWindowTitle("Errore");
            messaggio->setIcon(QMessageBox::Warning);
            messaggio->setText("Non è stato possibile eliminare il profilo");
            messaggio->show();
        }
    }
}

void vistaProfiloPerAdmin::cliccaCambiaLuogo(){
    if(m){
        m->close();
        delete m;
        m = nullptr;
    }
    m = new modificaLuogoPerAdmin(contenitore,profilo,nullptr);
    connect(m,SIGNAL(fatto()),this,SLOT(parametroModificato()));
    m->show();
}

void vistaProfiloPerAdmin::cliccaCambiaPassword(){
    if(m){
        m->close();
        delete m;
        m = nullptr;
    }
    m = new modificaPasswordPerAdmin(contenitore,profilo,nullptr);
    connect(m,SIGNAL(fatto()),this,SLOT(parametroModificato()));
    m->show();
}

//MODIFICA PARAMETRO

modificaParametroUtente::modificaParametroUtente(C& c,QWidget * parent ):QWidget(parent),contenitore(c){
    QRect rec = QApplication::desktop()->screenGeometry();
    int h = rec.height();
    int w = rec.width();
    int larg = w/4;
    int alt = h/5;
    int x = w/2 - larg/2;
    int y = h/2 - alt/2;

    setGeometry(x,y,larg,alt);
    setFixedSize(size());

    parametrolabel = new QLabel(this);
    parametrolabel->setAlignment(Qt::AlignRight);
    passwordlabel = new QLabel("La tua password attuale",this);
    passwordlabel->setAlignment(Qt::AlignRight);
    parametro = new QLineEdit(this);
    password = new QLineEdit(this);
    password->setEchoMode(QLineEdit::Password);

    conferma = new QPushButton("Conferma",this);
    connect(conferma,SIGNAL(clicked(bool)),this,SLOT(modificaParametro()));

    annulla = new QPushButton("Annulla",this);
    connect(annulla,SIGNAL(clicked(bool)),this,SIGNAL(fatto()));

    layout = new QGridLayout(this);
    layout->addWidget(parametrolabel,0,0);
    layout->addWidget(parametro,0,1);
    layout->addWidget(passwordlabel,1,0);
    layout->addWidget(password,1,1);
    layout->addWidget(conferma,2,0,1,2);
    layout->addWidget(annulla,3,0,1,2);
    setLayout(layout);
}

modificaParametroUtente::~modificaParametroUtente(){}

//MODIFICA PASSWORD

modificaPassword::modificaPassword(C& c,QWidget * parent) : modificaParametroUtente(c,parent){
    parametrolabel->setText("Nuova password");
    setWindowTitle("Cambia password");
}

bool modificaPassword::modificaParametro(){
    if(parametro->text().length() == 0){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("La nuova password deve avere almeno un carattere");
        messaggio->show();
        return false;
    }
    if(!contenitore.logged()){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non è stato effettuato il login");
        messaggio->show();
        return false;
    }
    if(password->text().toStdString() != contenitore.getUtente()->getPassword()){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("La password non è corretta");
        messaggio->show();
        return false;
    }
    utente * u = contenitore.getUtente();
    if(u->modificaPassword(parametro->text().toStdString())){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Successo");
        messaggio->setIcon(QMessageBox::Information);
        messaggio->setText("La password è stata modificata correttamente");
        messaggio->show();
        fatto();
        return true;
    } else {
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non è stato possibile modificare la password");
        messaggio->show();
        fatto();
        return false;
    }
}

//MODIFICA PASSWORD PER ADMIN

modificaPasswordPerAdmin::modificaPasswordPerAdmin(C& c,utente& u,QWidget * parent) : modificaPassword(c,parent),profilo(u){}

bool modificaPasswordPerAdmin::modificaParametro(){
    if(parametro->text().length() == 0){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("La nuova password deve avere almeno un carattere");
        messaggio->show();
        return false;
    }
    if(!contenitore.logged()){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non è stato effettuato il login");
        messaggio->show();
        return false;
    }
    if(dynamic_cast<utenteAdmin *>(contenitore.getUtente()) == nullptr){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non hai i privilegi per cambiare la password di un altro utente");
        messaggio->show();
        return false;
    }
    if(password->text().toStdString() != contenitore.getUtente()->getPassword()){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("La password non è corretta");
        messaggio->show();
        return false;
    }
    if(dynamic_cast<utenteAdmin*>(contenitore.getUtente())->modificaPasswordUtente(parametro->text().toStdString(),profilo)){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Successo");
        messaggio->setIcon(QMessageBox::Information);
        messaggio->setText("La password è stata modificata correttamente");
        messaggio->show();
        fatto();
        return true;
    } else {
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non è stato possibile modificare la password");
        messaggio->show();
        fatto();
        return false;
    }
}

//MODIFICA LUOGO

modificaLuogo::modificaLuogo(C& c,QWidget * parent) : modificaParametroUtente(c,parent){
    parametrolabel->setText("Nuovo luogo");
    setWindowTitle("Cambia luogo");
}

bool modificaLuogo::modificaParametro(){
    if(parametro->text().length() == 0){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Il nuovo luogo deve avere almeno un carattere");
        messaggio->show();
        return false;
    }
    if(!contenitore.logged()){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non è stato effettuato il login");
        messaggio->show();
        return false;
    }
    if(password->text().toStdString() != contenitore.getUtente()->getPassword()){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("La password non è corretta");
        messaggio->show();
        return false;
    }
    utente * u = contenitore.getUtente();
    if(u->modificaLuogo(parametro->text().toStdString())){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Successo");
        messaggio->setIcon(QMessageBox::Information);
        messaggio->setText("La password è stata modificata correttamente");
        messaggio->show();
        fatto();
        return true;
    } else {
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non è stato possibile modificare il luogo");
        messaggio->show();
        fatto();
        return false;
    }
}

// MODIFICA LUOGO PER ADMIN

modificaLuogoPerAdmin::modificaLuogoPerAdmin(C& c,utente& u,QWidget * parent) : modificaLuogo(c,parent),profilo(u){}

bool modificaLuogoPerAdmin::modificaParametro(){
    if(parametro->text().length() == 0){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Il nuovo luogo deve avere almeno un carattere");
        messaggio->show();
        return false;
    }
    if(!contenitore.logged()){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non è stato effettuato il login");
        messaggio->show();
        return false;
    }
    if(dynamic_cast<utenteAdmin *>(contenitore.getUtente()) == nullptr){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non hai i privilegi per cambiare la password di un altro utente");
        messaggio->show();
        return false;
    }
    if(password->text().toStdString() != contenitore.getUtente()->getPassword()){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("La password non è corretta");
        messaggio->show();
        return false;
    }
    if((dynamic_cast<utenteAdmin*>(contenitore.getUtente())->modificaLuogoUtente(parametro->text().toStdString(),profilo))){
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Successo");
        messaggio->setIcon(QMessageBox::Information);
        messaggio->setText("Il luogo è stato modificato correttamente");
        messaggio->show();
        fatto();
        return true;
    } else {
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Non è stato possibile modificare il luogo");
        messaggio->show();
        fatto();
        return false;
    }
}
