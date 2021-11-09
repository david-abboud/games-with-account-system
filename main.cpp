#include <QApplication>
#include <QPushButton>
#include "mainwidget.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    mainWidget *wid = new mainWidget();
    wid->show();
    return app.exec();

}
