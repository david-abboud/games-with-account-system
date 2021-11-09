#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtWidgets>

class battleship : public QWidget
{
    Q_OBJECT
public:
    explicit battleship(QWidget *parent = nullptr);

    QLabel* gameLabel;
    QLabel* description;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QToolButton* playButton;

signals:

public slots:
    void startGame();

};

#endif // BATTLESHIP_H
