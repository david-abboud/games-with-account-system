#include "mainwidget.h"
#include "signup.h"
#include "signin.h"

mainWidget::mainWidget(QWidget *parent) : QWidget(parent)
{

    grid1 = new QGridLayout();

    signupButton = new QPushButton("Sign up");
    grid1->addWidget(signupButton,0,0);
    QObject::connect(signupButton, SIGNAL(clicked(bool)), this, SLOT(signUp()));


    signinButton = new QPushButton("Sign in");
    grid1->addWidget(signinButton,0,1);
    QObject::connect(signinButton, SIGNAL(clicked(bool)), this, SLOT(signIn()));

    guestButton = new QPushButton("Sign in as guest");
    grid1->addWidget(guestButton,0,2);
    QObject::connect(guestButton, SIGNAL(clicked(bool)), this, SLOT(guest()));

    setLayout(grid1);
    this->show();

}

void mainWidget::fillSummary(){
    QString firstname_str = firstnametxt->text();
    QString lastname_str = lastnametxt->text();
    QString age_str = ageBox->text();
    QString gender_str;
    if (male->isChecked()){
        gender_str = "Male";
    } else if (female->isChecked()){
        gender_str = "Female";
    } else if (other->isChecked()){
        gender_str = "Other";
    }

    textEdit->setText("First Name : " + firstname_str + "\n"
                      + "Last Name : " + lastname_str + "\n"
                      + "Age : " + age_str + "\n"
                      + "Gender : " +  gender_str + "\n");
}
void mainWidget::clearSummary(){
    textEdit->clear();
    firstnametxt->clear();
    lastnametxt->clear();
    ageBox->clear();
}
void mainWidget::createGrid1(){

   }
void mainWidget::signUp(){
    this->close();
    SignUp *signUpObj = new SignUp();
    signUpObj->show();

}

void mainWidget::signIn(){
    this->close();
    SignIn *signInObj = new SignIn();
    signInObj->show();
}
void mainWidget::guest(){
    this->close();
    profilePage *prof = new profilePage();

}
