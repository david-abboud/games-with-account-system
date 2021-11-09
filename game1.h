#ifndef GAME1_H
#define GAME1_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtWidgets>

#include "button.h"

class game1 : public QWidget
{
    Q_OBJECT

    bool playing = true;

    int number_of_ships = 0;
    int number_of_enemy_ships = 0;

    int number_of_attempts_left = 16;

    bool ships_initialized = false;
    bool choseShips=false;
    int correct=0;
    int wrong=0;
    QGraphicsView* view;
    QGraphicsScene*  scene;
    QLabel* goodC;
    QLabel* badC;

    QWidget* widget;
    QHBoxLayout* box;
    QGridLayout* grid1;
    QGridLayout* grid2;

//    QToolButton* b1_1;
//    QToolButton* b1_2;
//    QToolButton* b1_3;

    QVector<button*> arr1;
    QVector<button*> arr2;

public:
    explicit game1(QWidget *parent = nullptr);
    void place_enemy(QVector<button*> &vec);
    void attempt(int i, QVector<button*> &vec);
    bool question();
public slots:
    void place(button* b);

signals:

};

#endif // GAME1_H
