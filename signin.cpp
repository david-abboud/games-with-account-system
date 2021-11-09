#include "signin.h"

SignIn::SignIn(QWidget *parent) : QWidget(parent)
{
    grid3 = new QGridLayout();
    signin = new QLabel("Sign in:");
    QFont f("Arial", 15, QFont::Bold);
    signin->setFont(f);
    grid3->addWidget(signin, 0,0);

    username = new QLabel("Username:");
    usernametxt = new QLineEdit();
    grid3->addWidget(username, 1,0);
    grid3->addWidget(usernametxt,1,1);

    password = new QLabel("Password:");
    passwordtxt = new QLineEdit();
    passwordtxt->setEchoMode(QLineEdit::Password);
    grid3->addWidget(password,2,0);
    grid3->addWidget(passwordtxt,2,1);

    signinButton = new QPushButton("Sign in");
    QObject::connect(signinButton, SIGNAL(clicked(bool)), this, SLOT(goToProfile()));
    grid3->addWidget(signinButton,3,2);

    backToMainPage = new QPushButton("Back to main page");
    QObject::connect(backToMainPage, SIGNAL(clicked(bool)), this, SLOT(backToMainPage2()));
    grid3->addWidget(backToMainPage,3,0);

    setLayout(grid3);

}

void SignIn::backToMainPage2(){
     this->close();
     mainWidget *main1 = new mainWidget();

}

void SignIn::goToProfile(){
    DataHandler* handler = new DataHandler();
    if(handler->authenticate(usernametxt->text(),passwordtxt->text())){
        this->close();
        QJsonObject obj = handler->findName(usernametxt->text());
        profilePage *prof = new profilePage(obj["firstname"].toString(),obj["lastname"].toString(),obj["profile_picture_path"].toString(),obj["countryCode"].toString());
    }
    else{
        Error *err = new Error("Incorrect username or password.");
    }


}
