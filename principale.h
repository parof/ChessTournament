#ifndef PRINCIPALE_H
#define PRINCIPALE_H
#include <QWidget>
#include <QSpinBox>
#include <QGridLayout>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QIcon>
#include <QInputDialog>
#include <QRadioButton>
#include <QTableWidget>
#include <QTextEdit>
#include <QVector>
#include <QHeaderView>

#include "vistatorneo.h"
#include "vistaprofilo.h"
#include "c.h"

class ricerca : public QWidget{
    Q_OBJECT
signals:
    void premutoCerca() const;
public:
    ricerca(QWidget* parent = nullptr);
    std::string getNomeTorneo() const;
    virtual std::string getLuogoTorneo() const;
    virtual unsigned int getPuntiTorneo() const;
    virtual ~ricerca();
protected:
    QLineEdit* nomet;
    QLabel* nometlabel;
    QPushButton* cercabottone;
    QGridLayout* layout;
};

class ricercaAvanzata : public ricerca{
public:
    ricercaAvanzata(QWidget* parent = nullptr);
    virtual std::string getLuogoTorneo() const;
    virtual unsigned int getPuntiTorneo() const;
private:
    QLineEdit* luogot;
    QSpinBox* puntit;
    QLabel* luogotlabel;
    QLabel* puntitlabel;
};

class visualizzatoreRicerche : public QWidget{
    Q_OBJECT
public slots:
    void disegnaTornei();
    void eliminaTorneo(size_t index);
public:
    visualizzatoreRicerche(C& contenitore,QWidget* parent = nullptr);
private:
    QPushButton* bottone;
    QTableWidget* vistatornei;
    QVector<torneo *> torneim; //tornei modificabili
    QVector<const torneo*> torneiv; //tornei visualizzabili
    QGridLayout* layout;
    C& contenitore;

    enum colonna{ //shortcut per indicizzare le colonne
        NOME,LUOGO,PUNTI,TIPOLOGIA,AZIONE,ELIMINA
    };
};

class bottoneEliminazione : public QPushButton{
    Q_OBJECT
signals:
    void torneoEliminato(size_t indice) const;
private slots:
    void premuto();
private:
    size_t index;
public:
    bottoneEliminazione(size_t i,QString label="",QWidget * parent=nullptr);
};

class bottoneTorneoModificabile : public QPushButton{
    Q_OBJECT
private slots:
    void premuto() const; //apre la finestra di modifca del torneo
private:
    torneo* t;
public:
    bottoneTorneoModificabile(torneo* tp,QString label="",QWidget * parent=nullptr);
};

class bottoneTorneoVisualizzabile : public QPushButton{
    Q_OBJECT
private slots:
    void premuto() const; //apre la finestra di visualizzazione del torneo
private:
    const torneo* t;
public:
    bottoneTorneoVisualizzabile(const torneo* tp,QString label="",QWidget * parent=nullptr);
};

class nuovoTorneo : public QWidget{
    Q_OBJECT
signals:
    void confermaPremuto() const;
private slots:
    void tentaConferma() const;
private:
    QGridLayout * layout;
    QLabel * nomeLabel;
    QLineEdit * nome;
    QLabel * luogoLabel;
    QLineEdit * luogo;
    QLabel * punteggioLabel;
    QSpinBox * punteggio;
    QPushButton * conferma;
    QRadioButton * sv;
    QRadioButton * rr;
    QRadioButton * ed;
    QRadioButton * rrd;
public:
    nuovoTorneo(QWidget * parent = nullptr);
    QString getNome() const;
    QString getLuogo() const;
    int getPunteggio() const;
    short int getTipologia() const;
};

class bottoni : public QWidget{
    Q_OBJECT
signals:
    void creaTorneoPremuto() const;
    void profiloPremuto() const;
    void logoutPremuto() const;
    void amministrazionePremuto() const;
private:
    bool amministratore;
    QVBoxLayout * layout;
    QPushButton * creaTorneo;
    QPushButton * logout;
    QPushButton * profilo;
    QPushButton * chiudi;
    QPushButton * admin;
public:
    bottoni(bool a,QWidget * parent=nullptr); //impostare a ad true se chi è loggato è un amministratore
};

class principale : public QWidget{
    //è la finestra principale tramite la quale un utente interagisce con l'applicazione: permette creare,cercare consultare tornei e fare il logout, oltre che aprire il pannello di amministrazione per amministratori
    Q_OBJECT
signals:
    void logout() const;
    void amministrazionePremuto() const;
private slots:
    void cercaPremuto();
    void nuovoTorneoPremuto();
    void datiTorneiInseriti();
    void profiloPremuto();
    void confermaEliminaProfilo();
public:
    principale(C& c,QWidget * parent=nullptr);
    ~principale();
private:
    ricerca* r;
    visualizzatoreRicerche* vr;
    bottoni * b;
    QLabel * iconalabel;

    QPixmap * icona;

    nuovoTorneo * nt;
    vistaProfilo * vp;
    C& contenitore;
};

#endif // PRINCIPALE_H
