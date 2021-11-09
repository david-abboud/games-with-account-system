#include "error.h"

Error::Error( QString err, QWidget *parent) : QWidget(parent)
{
    grid5 = new QGridLayout();
    errorMessage = new QLabel(err);
    QFont f("Arial", 15, QFont::Bold);
    errorMessage->setFont(f);
    grid5->addWidget(errorMessage, 0,0);
    setLayout(grid5);
    this->show();
}
