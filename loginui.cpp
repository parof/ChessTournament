#include "loginui.h"

loginUi::loginUi(QWidget * parent):  QWidget(parent){
    QRect rec = QApplication::desktop()->screenGeometry();
    int h = rec.height();
    int w = rec.width();
    int larg = w/5;
    int alt = h/2;
    int x = w/2 - larg/2;
    int y = h/2 - alt/2;

    QShortcut *shortcut = new QShortcut(QKeySequence("l"), this);
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(logPremuto()));

    titolo = new QLabel("Benvenuto in Chess Tournament Handler");
    QLabel* franco = new QLabel();
    titolo->setWordWrap(true);
    titolo->setAlignment(Qt::AlignCenter);
    titolo->setStyleSheet("font-size: 20px;");

    icona = new QLabel(this);
    icona->setTextFormat(Qt::RichText);
    icona->setText("<img src=\"torre.png\"");
    icona->setAlignment(Qt::AlignCenter);

    username = new QLineEdit(this);
    username->setPlaceholderText("username");
    password = new QLineEdit(this);
    password->setEchoMode(QLineEdit::Password);

    usernamelabel = new QLabel("username:");
    passwordlabel = new QLabel("password:");

    login = new QPushButton("&Login",this);
    nuovoUtente = new QPushButton("Crea nuovo profilo",this);
    connect(nuovoUtente,SIGNAL(clicked(bool)),this,SIGNAL(creaNuovoProfilo()));

    layout = new QGridLayout(this);
    layout->addWidget(titolo,0,0,1,2);
    layout->addWidget(icona,1,0,1,2);
    layout->addWidget(username,2,1);
    layout->addWidget(password,3,1);
    layout->addWidget(usernamelabel,2,0);
    layout->addWidget(passwordlabel,3,0);
    layout->addWidget(login,4,0,1,2);
    layout->addWidget(nuovoUtente,5,0,1,2);
    setLayout(layout);

    connect(login,SIGNAL(pressed()),this,SLOT(logPremuto()));
    setGeometry(x,y,larg,alt);
    setFixedSize(size());
}

void loginUi::logPremuto() const{
    provaLogin();
}

std::string loginUi::getUsername() const{
    return username->text().toUtf8().constData();
}
std::string loginUi::getPassword() const{
    return password->text().toUtf8().constData();
}


// NUOVO PROFILO

nuovoProfilo::nuovoProfilo(C& c, QWidget * parent):QWidget(parent),contenitore(c){
    setWindowTitle("Nuovo profilo");

    usernamelabel = new QLabel("Username",this);
    usernamelabel->setAlignment(Qt::AlignRight);
    luogolabel  = new QLabel("Luogo",this);
    luogolabel->setAlignment(Qt::AlignRight);
    passwordlabel  = new QLabel("Password",this);
    passwordlabel->setAlignment(Qt::AlignRight);
    ripetipasswordlabel  = new QLabel("Ripeti password",this);
    ripetipasswordlabel->setAlignment(Qt::AlignRight);
    tipologialabel  = new QLabel("Tipologia",this);
    tipologialabel->setAlignment(Qt::AlignRight);

    username = new QLineEdit(this);
    luogo  = new QLineEdit(this);
    password  = new QLineEdit(this);
    password->setEchoMode(QLineEdit::Password);
    ripetipassword  = new QLineEdit(this);
    ripetipassword->setEchoMode(QLineEdit::Password);
    conferma = new QPushButton("Conferma",this);
    connect(conferma,SIGNAL(clicked(bool)),this,SLOT(provaConferma()));
    annulla = new QPushButton("Annulla",this);
    connect(annulla,SIGNAL(clicked(bool)),this,SIGNAL(annullato()));

    basic = new QRadioButton("Basic",this);
    basic->setChecked(true);
    pro = new QRadioButton("Pro",this);
    admin = new QRadioButton("Admin",this);

    descrizioneBasic = new QLabel(QString::fromStdString(utente::descrizioneBasic),this);
    QFont font = descrizioneBasic->font();
    font.setPointSize(10);
    font.setItalic(true);
    descrizioneBasic->setFont(font);
    descrizioneBasic->setWordWrap(true);
    descrizionePro = new QLabel(QString::fromStdString(utente::descrizionePro),this);
    descrizionePro->setWordWrap(true);
    descrizionePro->setFont(font);
    descrizioneAdmin  = new QLabel(QString::fromStdString(utente::descrizioneAdmin),this);
    descrizioneAdmin->setWordWrap(true);
    descrizioneAdmin->setFont(font);

    layout = new QGridLayout(this);
    layout->addWidget(usernamelabel,0,0);
    layout->addWidget(username,0,1,1,3);
    layout->addWidget(luogolabel,1,0);
    layout->addWidget(luogo,1,1,1,3);
    layout->addWidget(passwordlabel,2,0);
    layout->addWidget(password,2,1,1,3);
    layout->addWidget(ripetipasswordlabel,3,0);
    layout->addWidget(ripetipassword,3,1,1,3);
    layout->addWidget(tipologialabel,4,0);
    layout->addWidget(basic,4,1);
    layout->addWidget(pro,4,2);
    layout->addWidget(admin,4,3);
    layout->addWidget(descrizioneBasic,5,1);
    layout->addWidget(descrizionePro,5,2);
    layout->addWidget(descrizioneAdmin,5,3);

    layout->addWidget(conferma,6,0,1,4);
    layout->addWidget(annulla,7,0,1,4);
    setLayout(layout);

    QRect rec = QApplication::desktop()->screenGeometry();
    int h = rec.height();
    int w = rec.width();
    int larg = w/3;
    int alt = h/2;
    int x = w/2 - larg/2;
    int y = h/2 - alt/2;
    setGeometry(x,y,larg,alt);
    setFixedSize(size());
}

void nuovoProfilo::provaConferma() const{
    if(password->text() == ripetipassword->text()){
        if(!contenitore.usernameUtilizzato(username->text().toStdString())){
            if(!username->text().length() == 0){
                if(!password->text().length() == 0){
                    if(!luogo->text().length() == 0){
                        confermato();

                    } else   {
                        QMessageBox * messaggio = new QMessageBox(nullptr);
                        messaggio->setWindowTitle("Errore");
                        messaggio->setIcon(QMessageBox::Warning);
                        messaggio->setText("Impossibile creare il profilo: il luogo deve consistere di almeno un carattere");
                        messaggio->show();
                    }
                } else {
                    QMessageBox * messaggio = new QMessageBox(nullptr);
                    messaggio->setWindowTitle("Errore");
                    messaggio->setIcon(QMessageBox::Warning);
                    messaggio->setText("Impossibile creare il profilo: la password deve consistere di almeno un carattere");
                    messaggio->show();
                }
            } else {
                QMessageBox * messaggio = new QMessageBox(nullptr);
                messaggio->setWindowTitle("Errore");
                messaggio->setIcon(QMessageBox::Warning);
                messaggio->setText("Impossibile creare il profilo: l'username deve consistere di almeno un carattere");
                messaggio->show();
            }
        } else {
            QMessageBox * messaggio = new QMessageBox(nullptr);
            messaggio->setWindowTitle("Errore");
            messaggio->setIcon(QMessageBox::Warning);
            messaggio->setText("Impossibile creare il profilo: username già utilizzato");
            messaggio->show();
        }
    } else {
        QMessageBox * messaggio = new QMessageBox(nullptr);
        messaggio->setWindowTitle("Errore");
        messaggio->setIcon(QMessageBox::Warning);
        messaggio->setText("Impossibile creare il profilo: le password inserite non corrispondono");
        messaggio->show();
    }
}


std::string nuovoProfilo::getUsername() const{
    return username->text().toStdString();
}
std::string nuovoProfilo::getLuogo() const{
    return luogo->text().toStdString();
}
std::string nuovoProfilo::getPassword() const{
    return password->text().toStdString();
}
short int nuovoProfilo::getTipologia() const{
    if(basic->isChecked())
        return utente::basic;
    if(pro->isChecked())
        return utente::pro;
    if(admin->isChecked())
        return utente::admin;

}
