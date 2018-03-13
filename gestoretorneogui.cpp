#include "gestoretorneogui.h"

GestoreTorneoGUI::GestoreTorneoGUI(C &con, QObject * parent) : QObject(parent),contenitore(con),a(nullptr),n(nullptr),p(nullptr),login(nullptr){
    nuovoLogin();
}

void GestoreTorneoGUI::loginPremuto(){

    bool riuscito = contenitore.login(login->getUsername(),login->getPassword());

    if(riuscito){
        login->close();
        delete login;
        login=nullptr;
        nuovoPrincipale();
    }else{
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Login fallito");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Login fallito: username o password errati");
        messaggio->show();
    }
}

void GestoreTorneoGUI::logoutPremuto(){
    if(p){
        p->close();
        delete p;
        p = nullptr;
        contenitore.logout();
        nuovoLogin();
    }
}

void GestoreTorneoGUI::creaNuovoProfiloPremuto(){
    if(login){
        login->close();
        delete login;
        login=nullptr;
    }
    if(n){
        n->close();
        delete n;
        n=nullptr;
    }
    n = new nuovoProfilo(contenitore,nullptr);
    connect(n,SIGNAL(confermato()),this,SLOT(profiloConfermato()));
    connect(n,SIGNAL(annullato()),this,SLOT(profiloAnnullato()));
    n->show();
}

void GestoreTorneoGUI::profiloConfermato(){
    short int tipologia = n->getTipologia();
    utente * u = nullptr;
    std::string username = n->getUsername();
    std::string luogo = n->getLuogo();
    std::string password = n->getPassword();
    if(tipologia == utente::basic){
        u = new utenteBasic(contenitore,username,password,luogo);
    } else if(tipologia == utente::pro){
        u = new utentePro(contenitore,username,password,luogo);
    } else if(tipologia == utente::admin){
        u = new utenteAdmin(contenitore,username,password,luogo);
    }

    n->close();
    delete n;
    n=nullptr;

    if(u){
        contenitore.registraUtente(u); //non è necessario un check sul fatto che sia già stato utilizzato poichè ha già controllato la finestra nuovoProfilo
        if(contenitore.logged())
            contenitore.logout();
        delete u;
        contenitore.login(username,password); //riuscirà sicuramente
        nuovoPrincipale();
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Benvenuto!");
        messaggio->setIcon(QMessageBox::Information);
        messaggio->setText("Benvenuto, il tuo nuovo profilo è stato creato, puoi iniziare subito ad utilizzare \"Chess Tournament Handler\" per cercare, consultare e creare tornei!");
        messaggio->show();
    } else {
        nuovoLogin();
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Critical);
        messaggio->setText("Non è stato possibile creare il profilo");
        messaggio->show();
    }
}

void GestoreTorneoGUI::nuovoLogin(){
    if(login){
        login->close();
        delete login;
        login=nullptr;
    }
    login = new loginUi(nullptr);
    login->setWindowTitle("Login");
    connect(login,SIGNAL(provaLogin()),this,SLOT(loginPremuto()));
    connect(login,SIGNAL(creaNuovoProfilo()),this,SLOT(creaNuovoProfiloPremuto()));
    login->show();
}

void GestoreTorneoGUI::nuovoPrincipale(){
    if(p){
        p->close();
        delete p;
        p = nullptr;
    }
    p = new principale(contenitore,nullptr);
    connect(p,SIGNAL(logout()),this,SLOT(logoutPremuto()));
    connect(p,SIGNAL(amministrazionePremuto()),this,SLOT(amministrazionePremuto()));
    p->show();
}

void GestoreTorneoGUI::profiloAnnullato(){
    if(n){
        n->close();
        delete n;
        n=nullptr;
    }
    nuovoLogin();
}

void GestoreTorneoGUI::amministrazionePremuto(){
    if(p){
        p->close();
        delete p;
        p = nullptr;
    }
    a = new amministrazione(contenitore,nullptr);
    connect(a,SIGNAL(chiudiPremuto()),this,SLOT(amministrazioneChiusa()));
    a->show();
}

void GestoreTorneoGUI::amministrazioneChiusa(){
    if(a){
        a->close();
        delete a;
        a = nullptr;
    }
    nuovoPrincipale();
}
