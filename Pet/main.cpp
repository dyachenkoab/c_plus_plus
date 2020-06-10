#include "mainWindow.h"
#include <QApplication>
#include <QtXlsx>

int
main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    //    QXlsx::Document doc("/home/podkyr/test1.xlsx");//openFile();
    //    qDebug() << doc.read(1,1);

    mainWindow w;
    w.show();

    return a.exec();
}
