#ifndef GESTORETORNEOGUI_H
#define GESTORETORNEOGUI_H
#include <QObject>
#include <QMessageBox>
#include <QErrorMessage>

#include "principale.h"
#include "loginui.h"
#include "amministrazione.h"
#include "c.h"

class GestoreTorneoGUI : public QObject{
    Q_OBJECT
private slots:
    void loginPremuto();
    void logoutPremuto();
    void creaNuovoProfiloPremuto();
    void profiloConfermato();
    void profiloAnnullato();
    void amministrazionePremuto();
    void amministrazioneChiusa();
private:
    C& contenitore; //passato a tutte le finestre come riferimento
    loginUi* login;
    principale* p;
    nuovoProfilo * n;
    amministrazione * a;
    void nuovoLogin(); //crea nuova finestra di login e fa opportuni connect
    void nuovoPrincipale(); //crea nuova finestra principale e connette
public:
    GestoreTorneoGUI(C& con,QObject * parent = nullptr);
};

#endif // GESTORETORNEOGUI_H
