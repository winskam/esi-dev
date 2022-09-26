#include <QApplication>

#include "mainwindow.h"
#include "game.h"
#include "observable.h"

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);
    abalone::model::Game g;
    abalone::view::MainWindow w = abalone::view::MainWindow(&g);
    w.show();
    return a.exec();
}
