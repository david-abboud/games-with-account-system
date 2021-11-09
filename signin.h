#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "mainwidget.h"
#include "profilepage.h"
#include "datahandler.h"
#include "error.h"

class SignIn : public QWidget
{
    Q_OBJECT
public:
    explicit SignIn(QWidget *parent = nullptr);

private:
    QLabel *username;
    QLabel *password;
    QLabel *signin;
    QLineEdit *usernametxt;
    QLineEdit *passwordtxt;
    QPushButton *signinButton;
    QPushButton *backToMainPage;
    QGridLayout *grid3;


public slots:
   void backToMainPage2();
   void goToProfile();
signals:

};

#endif // SIGNIN_H
