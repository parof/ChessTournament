#include "amministrazione.h"

amministrazione::amministrazione(C& c,QWidget* parent) :v(nullptr), contenitore(c),QWidget(parent){
    setWindowTitle("Amministrazione utenti");
    QRect schermo = QApplication::desktop()->screenGeometry();
    setGeometry(schermo);


    tabella = new QTableWidget(this);
    tabella->setEditTriggers(QTableView::NoEditTriggers);
    tabella->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList colonne;
    colonne << "Username" <<"Password"<<"Luogo"<<"Tipologia"<<"";
    tabella->setColumnCount(colonne.size());
    tabella->setHorizontalHeaderLabels(colonne);
    contenitore.cercaTuttiGliUtenti();
    disegnaUtenti();

    chiudi = new QPushButton("Chiudi",this);
    connect(chiudi,SIGNAL(clicked(bool)),this,SIGNAL(chiudiPremuto()));

    usrname = new QLineEdit(this);
    usrname->setPlaceholderText("Cerca utente per username");
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(3);
    usrname->setSizePolicy(spLeft);

    cerca = new QPushButton("Cerca",this);
    connect(cerca,SIGNAL(clicked(bool)),this,SLOT(ricerca()));
    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(1);
    cerca->setSizePolicy(spRight);

    intestazione = new QLabel("Pannello di Amministrazione",this);
    intestazione->setStyleSheet("font-size: 60px");
    intestazione->setAlignment(Qt::AlignCenter);

    layout = new QGridLayout(this);
    layout->addWidget(intestazione,0,0,1,2);
    layout->addWidget(usrname,1,0);
    layout->addWidget(cerca,1,1);
    layout->addWidget(tabella,2,0,1,2);
    layout->addWidget(chiudi,3,0,1,2);
    setLayout(layout);
}

void amministrazione::disegnaUtenti(){
    tabella->setRowCount(0);
    utenti.clear();
    utenti = (QVector<utente *>::fromStdVector(contenitore.getUtenti()));
    for(auto i=0;i<utenti.size();i++){
        tabella->insertRow(tabella->rowCount());
        tabella->setItem(tabella->rowCount()-1,USERNAME,new QTableWidgetItem(QString::fromStdString(utenti[i]->getUsername())));
        tabella->setItem(tabella->rowCount()-1,PASSWORD,new QTableWidgetItem(QString::fromStdString(utenti[i]->getPassword())));
        tabella->setItem(tabella->rowCount()-1,LUOGO,new QTableWidgetItem(QString::fromStdString(utenti[i]->getLuogo())));
        tabella->setItem(tabella->rowCount()-1,TIPOLOGIA,new QTableWidgetItem(QString::fromStdString(utenti[i]->tipologiaTestuale())));
        bottoneIndice * b = new bottoneIndice(i,"Scheda utente",this);
        tabella->setCellWidget(tabella->rowCount()-1,SCHEDA,b);
        connect(b,SIGNAL(premuto(size_t)),this,SLOT(schedaPremuta(size_t)));
    }
}

void amministrazione::schedaPremuta(size_t i){ //indice dell'utente da modificare
    if(v){
        v->close();
        delete v;
        v=nullptr;
    }
    v = new vistaProfiloPerAdmin(contenitore,*(contenitore.getUtenti()[i]),nullptr);
    connect(v,SIGNAL(confermaEliminaProfilo()),this,SLOT(profiloEliminato()));
    connect(v,SIGNAL(modificaEffettuata()),this,SLOT(disegnaUtenti()));
    v->show();

}

void amministrazione::profiloEliminato(){
    if(v){
        v->close();
        delete v;
        v=nullptr;
    }
    disegnaUtenti();
}

void amministrazione::ricerca(){
    contenitore.cercaUtenti(usrname->text().toStdString());
    disegnaUtenti();
}

//BOTTONE INDICE

bottoneIndice::bottoneIndice(size_t i, QString testo, QWidget * parent) : QPushButton(testo,parent), indice(i){
    connect(this,SIGNAL(clicked(bool)),this,SLOT(tentaPressione()));
}

void bottoneIndice::tentaPressione() const{
    premuto(indice);
}
