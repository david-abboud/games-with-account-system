#include "battleship.h"
#include "game1.h"

battleship::battleship(QWidget *parent) : QWidget(parent)
{

    gameLabel = new QLabel("Battleship Game");
    QFont f("Arial", 15, QFont::Bold);
    gameLabel->setFont(f);

    description = new QLabel("Click on Start when you're ready!");

    view = new QGraphicsView();

    playButton = new QToolButton();
    playButton->setText(QString("Start"));
    playButton->setShortcut(tr("F1"));
    QObject::connect(playButton, SIGNAL(clicked(bool)), this, SLOT(startGame()));

    scene = new QGraphicsScene();

    QGraphicsProxyWidget* pw = scene->addWidget(gameLabel);
    pw->setPos(10,10);

    QGraphicsProxyWidget* pw2 = scene->addWidget(description);
    pw2->setPos(20,50);

    QGraphicsProxyWidget* pw3 = scene->addWidget(playButton);
    pw3->setPos(200,420);

    scene->setSceneRect(0,0,500,500);
    view->setFixedSize(600,600);
    QImage image;
    image.load(":/Battleship_images/background_battleship");
    view->setBackgroundBrush(image.scaled(600,600));
    view->setScene(scene);
    view->show();
}

void battleship::startGame(){
    view->close();
    game1* g = new game1();
}
