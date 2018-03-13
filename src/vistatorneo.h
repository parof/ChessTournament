#ifndef VISTATORNEO_H
#define VISTATORNEO_H
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QVector>
#include <QScrollArea>
#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
#include <QGroupBox>
#include <QKeyEvent>
#include <QSpinBox>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QRect>
#include <QScreen>
#include <QMessageBox>
#include <QSignalMapper>
#include <QTextStream>

#include "torneo.h"

class vistaInfo : public QWidget{
private:
    QLabel * nome;
    QLabel * luogo;
    QLabel * tipologia;
    QLabel * punteggio;
    QLabel * nomeint; //int sta per intestazione
    QLabel * luogoint;
    QLabel * tipologiaint;
    QLabel * punteggioint;
    QLabel * nturni;
    QLabel * nturniint;
    QVBoxLayout * layout;
    const torneo* t;
    static std::string stile;
public:
    vistaInfo(const torneo* tor,QWidget* parent=nullptr);
    void aggiornaNTurni();
};

class vistaPartecipanti : public QWidget{
private:
    const std::vector<partecipante>& part;
    QListWidget * listaPartecipanti;
    QVBoxLayout * layout;
    QLabel * intestazione;
    QString stringaIntestazione() const;
public:
    vistaPartecipanti(const std::vector<partecipante>& p, QWidget * parent=nullptr);
    void disegnaVistaPartecipanti();
};

class vistaMatch: public QWidget{
    Q_OBJECT
signals:
    void risultatoCliccato() const;
private:
    const match& m;
    QLabel* testo;
    QGridLayout* layout;
    QPushButton* mettiRisultato;
    static std::string stile;
    QString testoDaScrivere() const;
public:
    vistaMatch(const match& mat,QWidget* parent=nullptr);
    void mostraBottone();
    void togliBottone();
    void aggiornaTesto();
};

class vistaTurno: public QWidget{
    Q_OBJECT
signals:
    void risultatoMatchCliccato(int index) const;
public:
    vistaTurno(const turno& tur,QWidget* parent=nullptr);
    void mostraBottoniRisultati();
    void togliBottoniRisultati();
    void aggiornaTestoMatch(size_t id);
private:
    const turno& t;
    QVector<vistaMatch*> matches;
    QVBoxLayout* layout;
    QSignalMapper * mappaRisultati;
};

class vistaTurni : public QWidget{
    Q_OBJECT
signals:
    void risultatoCliccato(int id) const;
private:
    const std::vector<turno>& turnidata;
    QVector<vistaTurno *> turni;
    QGridLayout* layout;
    static std::string stileIntestazione;
public:
    vistaTurni(const std::vector<turno>& t,QWidget*parent =nullptr);
    void mostraBottoniUltimoTurno();
    void aggiornaTestoMatchUltimoTurno(size_t idMatch);
    void disegnaProssimoTurno();
};

class vistaTorneoV : public QWidget{
    Q_OBJECT
protected:
    void keyPressEvent(QKeyEvent * evento);
private slots:
    void tentaVincitore();
private:
    const torneo* t;
    QPushButton* vincitore;
    QGridLayout* layout;
    vistaTurni* vistat;
    QScrollArea * scroll;
    vistaInfo * info;
    vistaPartecipanti * partecipanti;
public:
    vistaTorneoV(const torneo* tp,QWidget*parent=nullptr);
};

class richiestaRisultato: public QWidget{
    Q_OBJECT
signals:
    void sceltoVincitore() const;
private slots:
    void sceltoUno();
    void sceltoDue();
    void sceltoNessuno();
private:
    QPushButton * uno;
    QPushButton * due;
    QPushButton * nessuno;
    QLabel * descrizione;
    QHBoxLayout * layoutgruppo;
    QGridLayout * layout;
    match::risultatoMatch risposta;
    QGroupBox * gruppo;
    const size_t id;
public:
    size_t getIndice() const;
    match::risultatoMatch getRisultato() const;
    richiestaRisultato(const match& m,size_t i,QWidget * parent=nullptr);
};

class vistaAggiungiPartecipante : public QWidget{
    Q_OBJECT
signals:
    void premuto() const;
private:
    QLabel * nomelabel;
    QLineEdit * nome;
    QLabel * punteggiolabel;
    QSpinBox * punteggio;
    QGridLayout * layout;
    QPushButton * conferma;
public:
    vistaAggiungiPartecipante(QWidget * parent = nullptr);
    QString getNome() const;
    int getElo() const;
};

class vistaOperazioni : public QWidget{ //i bottoni di torneo modificabile
    Q_OBJECT
signals:
    void prossimoTurnoPremuto() const;
    void aggiungiPartecipantePremuto() const;
    void iniziaPremuto() const;
    void vincitorePremuto() const;
public:
    vistaOperazioni(QWidget * parent=nullptr);
    void cliccaProssimoTurno();
    void cliccaAggiungiPartecipante();
    void cliccaInizia();
    void cliccaChiudi();
    void cliccaVincitore();
private:
    QGridLayout * layout;
    QPushButton * prossimoTurno;
    QPushButton * aggiungiPartecipante;
    QPushButton * chiudi;
    QPushButton * inizia;
    QPushButton * vincitore;
};

class vistaTorneoM : public QWidget{
    Q_OBJECT
public:
    vistaTorneoM(torneo* tp,QWidget*parent=nullptr);
public slots:
    void risultatoMatchCliccato(int id);
    void risultatoMatchDato();
    void tentaProssimoTurno();
    void tentaAggiungiPartecipante();
    void datiPartecipanteInseriti();
    void tentaInizia();
    void tentaVincitore() const;
private:
    torneo* t;
    QGridLayout* layout;
    vistaTurni* vistat;
    QScrollArea * scroll;
    vistaInfo * info;
    vistaPartecipanti * partecipanti;
    richiestaRisultato * selezioneRisultato;
    vistaOperazioni * operazioni;
    vistaAggiungiPartecipante * aggiungiPartecipante;
protected:
    void keyPressEvent(QKeyEvent * evento);
};

#endif // VISTATORNEO_H
