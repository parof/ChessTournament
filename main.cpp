#include <QApplication>
#include <iostream>
#include "loginui.h"
#include "gestoretorneogui.h"
#include "principale.h"
#include "utente.h"
#include "c.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    C contenitore;
    GestoreTorneoGUI g(contenitore);
    return QApplication::exec();
}
