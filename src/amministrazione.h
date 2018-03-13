#ifndef AMMINISTRAZIONE_H
#define AMMINISTRAZIONE_H
#include <QWidget>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QGridLayout>
#include <QHeaderView>
#include <QVector>

#include "c.h"
#include "vistaprofilo.h"

class bottoneIndice : public QPushButton{
    Q_OBJECT
signals:
    void premuto(size_t indice) const;
private slots:
    void tentaPressione() const;
private:
    size_t indice;
public:
    bottoneIndice(size_t i,QString testo="",QWidget * parent = nullptr);
};


class amministrazione : public QWidget{
    Q_OBJECT
signals:
    void chiudiPremuto() const;
private slots:
    void profiloEliminato();
    void schedaPremuta(size_t i);
    void ricerca();
    void disegnaUtenti();
private:
    C& contenitore;
    vistaProfilo * v;
    QVector<utente *> utenti;
    QTableWidget* tabella;
    QGridLayout * layout;
    QPushButton * chiudi;
    QPushButton * cerca;
    QLineEdit * usrname;
    QLabel * intestazione;

    enum colonna{ //shortcut per indicizzare le colonne
        USERNAME,PASSWORD,LUOGO,TIPOLOGIA,SCHEDA
    };
public:
    amministrazione(C& c,QWidget* parent=nullptr);
};


#endif // AMMINISTRAZIONE_H
