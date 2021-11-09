#include "profilepage.h"
#include "battleship.h"

profilePage::profilePage(QString firstname_param, QString lastname_param, QString path, QString countryCode_param, QWidget *parent) : QWidget(parent)
{
    grid4 = new QGridLayout();
    date = new QDate();

    QDate date2 = date->currentDate();
        date_label = new QLabel(date2.toString());
        grid4->addWidget(date_label,4,1);

    firstname = new QLabel ("First Name: " + firstname_param);
    grid4 -> addWidget(firstname, 1, 0);

    lastname = new QLabel("Last Name: " + lastname_param);
    grid4 -> addWidget(lastname, 2, 0);

    QImage image;
    image.load(path);
    QLabel* profilePicture = new QLabel();
    image = image.scaledToWidth(90, Qt::SmoothTransformation);
    profilePicture->setPixmap(QPixmap::fromImage(image));
    grid4->addWidget(profilePicture,3,1);

    QImage image2;
    QString flag;

    if(countryCode_param == "971"){
        flag = "UAE";
    }
    else if(countryCode_param == "377"){
        flag = "Monaco";
    }
    else if(countryCode_param == "354"){
        flag =  "Iceland";
    }
    else if(countryCode_param == "357"){
        flag = "Cyprus";
    }
    else if(countryCode_param == "352"){
        flag = "Luxembourg";
    }
    else{
        flag = "QR";
    }

    image2.load(":/Flags/" + flag);
    QLabel* flagLabel = new QLabel();
    image2 = image2.scaledToWidth(45, Qt::SmoothTransformation);
    flagLabel->setPixmap(QPixmap::fromImage(image2));
    grid4->addWidget(flagLabel,4,0);

    QLabel* countryName = new QLabel(flag);
    grid4->addWidget(countryName,5,0);

    battleshipButton = new QPushButton("Battleship");
    grid4->addWidget(battleshipButton,6,0);
    QObject::connect(battleshipButton, SIGNAL(clicked(bool)), this, SLOT(playBattleship()));

    setLayout(grid4);
    this->show();
}
profilePage::profilePage(QWidget *parent) : QWidget(parent)
{
    grid4 = new QGridLayout();
    date = new QDate();

    QDate date2 = date->currentDate();
        date_label = new QLabel(date2.toString());
        grid4->addWidget(date_label,4,1);
    firstname = new QLabel ("Signed in as guest.");
    grid4 -> addWidget(firstname, 1, 0);


    profilePictureImage = new QImage();


    setLayout(grid4);
    this->show();
}
void profilePage::playBattleship(){
    this->close();
    battleship *bship = new battleship();
//    bship->show();
}

