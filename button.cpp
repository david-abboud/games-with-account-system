#include "button.h"
#include "game1.h"

button::button(int index, bool ship){
    this->index = index;
    this->ship = ship;
    toolButton = new QToolButton();
 //   toolButton->setIcon(QIcon(":/Battleship_images/square"));
    toolButton->setFixedSize(100,100);
    toolButton->setIconSize(QSize(100, 100));
   // QObject::connect(toolButton, SIGNAL(clicked(bool)), this, SLOT(game1::attempt(toolButton->index)));
}
