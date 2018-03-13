#ifndef LOGINUI_H
#define LOGINUI_H
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QDesktopWidget>
#include <QRect>
#include <QScreen>
#include <QApplication>
#include <QMessageBox>
#include <QShortcut>
#include <QRadioButton>
#include <QFont>
#include <string>
#include <c.h>

class loginUi : public QWidget{
    Q_OBJECT
signals:
    void provaLogin() const;
    void creaNuovoProfilo() const;
private slots:
    void logPremuto() const;
private:
    QLineEdit * username;
    QLineEdit * password;
    QGridLayout * layout;
    QLabel * usernamelabel;
    QLabel * passwordlabel;
    QPushButton * login;
    QPushButton * nuovoUtente;
    QLabel * titolo;
    QLabel * icona;
public:
    loginUi(QWidget * parent = nullptr);
    std::string getUsername() const;
    std::string getPassword() const;
};

class nuovoProfilo : public QWidget{
    Q_OBJECT
private slots:
    void provaConferma() const;
signals:
    void confermato() const;
    void annullato() const;
private:
    C& contenitore;
    QLabel * usernamelabel;
    QLabel * luogolabel;
    QLabel * passwordlabel;
    QLabel * ripetipasswordlabel;
    QLabel * tipologialabel;
    QLineEdit * username;
    QLineEdit * luogo;
    QLineEdit * password;
    QLineEdit * ripetipassword;
    QPushButton * conferma;
    QPushButton * annulla;
    QRadioButton * basic;
    QRadioButton * pro;
    QRadioButton * admin;
    QGridLayout * layout;
    QLabel * descrizioneBasic;
    QLabel * descrizionePro;
    QLabel * descrizioneAdmin;
public:
    nuovoProfilo(C &c, QWidget * parent=nullptr);
    std::string getUsername() const;
    std::string getLuogo() const;
    std::string getPassword() const;
    short int getTipologia() const;
};

#endif // LOGINUI_H
