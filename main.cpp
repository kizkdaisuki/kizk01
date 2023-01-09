#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "mainwindow.h"

#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QString qss;
    QFile qssFile(":/main.qss");
    qssFile.open(QFile::ReadOnly);

    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
    }
    MainWindow w;
    w.show();
    return a.exec();
}
