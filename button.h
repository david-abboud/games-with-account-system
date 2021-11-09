#ifndef BUTTON_H
#define BUTTON_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtWidgets>

//#include "game1.h"

class button : public QWidget
{
    Q_OBJECT
public:
    explicit button(int index, bool ship);
    QToolButton* toolButton;
    int index;
    bool ship;

signals:

};

#endif // BUTTON_H
