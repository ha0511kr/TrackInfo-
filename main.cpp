#include "mainwindow.h"
#include <QApplication>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    mkdir("./Output/", S_IRWXU | S_IRWXG | S_IRWXO);
    mkdir("./Data/", S_IRWXU | S_IRWXG | S_IRWXO);
    return a.exec();
}
