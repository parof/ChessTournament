#ifndef VISTAPROFILO_H
#define VISTAPROFILO_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QRect>
#include <QScreen>
#include <QApplication>

#include "c.h"


class modificaParametroUtente : public QWidget{
    Q_OBJECT
signals:
    void fatto(); //innescato quando premuto annulla oppure quando è stato modificato il parametro
protected slots:
    virtual bool modificaParametro() = 0;
private:
    QLabel * passwordlabel;
    QPushButton * conferma;
    QPushButton * annulla;
    QGridLayout * layout;
protected: //nella parte protected solo ciò che serve alle sottoclassi
    C& contenitore;
    QLabel * parametrolabel;
    QLineEdit * parametro;
    QLineEdit * password;
public:
    modificaParametroUtente(C& c,QWidget * parent = nullptr);
    virtual ~modificaParametroUtente();
};


class modificaPassword : public modificaParametroUtente{
    Q_OBJECT
protected slots:
    virtual bool modificaParametro();
public:
    modificaPassword(C& c,QWidget * parent = nullptr);
};

class modificaPasswordPerAdmin : public modificaPassword{
    Q_OBJECT
protected slots:
    virtual bool modificaParametro();
private:
    utente& profilo;
public:
    modificaPasswordPerAdmin(C& c,utente& u,QWidget * parent = nullptr);
};

class modificaLuogo : public modificaParametroUtente{
    Q_OBJECT
protected slots:
    virtual bool modificaParametro();
public:
    modificaLuogo(C& c,QWidget * parent = nullptr);
};

class modificaLuogoPerAdmin : public modificaLuogo{
    Q_OBJECT
protected slots:
    virtual bool modificaParametro();
private:
    utente& profilo;
public:
     modificaLuogoPerAdmin(C& c,utente& u,QWidget * parent = nullptr);
};

class vistaProfilo : public QWidget{
    Q_OBJECT
signals:
    void confermaEliminaProfilo() const;
    void modificaEffettuata() const;
public slots:
    void parametroModificato();
protected slots:
    virtual void cliccaEliminaProfilo();
    virtual void cliccaCambiaLuogo();
    virtual void cliccaCambiaPassword();
private:
    QLabel * nomeint; //nome intestazione
    QLabel * nome;
    QLabel * luogoint;
    QLabel * luogo;
    QLabel * privilegi;
    QLabel * tipologiaint;
    QLabel * tipologia;

    QPushButton * chiudi;
    QPushButton * eliminaProfilo;
    QPushButton * cambiaLuogo;
    QPushButton * cambiaPassword;

    QGridLayout * layout;
protected:
    C& contenitore;
    utente& profilo;
    modificaParametroUtente * m;
public:
    vistaProfilo(C& c,utente& u,QWidget * parent=nullptr);
};

class vistaProfiloPerAdmin : public vistaProfilo{
    Q_OBJECT
protected slots:
    virtual void cliccaEliminaProfilo();
    virtual void cliccaCambiaLuogo();
    virtual void cliccaCambiaPassword();
public:
    vistaProfiloPerAdmin(C& c, utente &u, QWidget * parent=nullptr);
};

#endif // VISTAPROFILO_H
