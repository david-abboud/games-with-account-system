#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "profilepage.h"
#include "error.h"
#include "datahandler.h"
#include <QFileDialog>

class SignUp : public QWidget
{
        Q_OBJECT
public:
    explicit SignUp(QWidget *parent = nullptr);
private:
    QLabel *firstname;
    QLabel *lastname;
    QLabel *gender;
    QLabel *signup;
    QLabel *dateOfBirth;
    QLabel *username;
    QLabel *password;
    QLabel *phoneNumber;
    QLabel *profilePicture;


    QLineEdit *firstnametxt;
    QLineEdit *lastnametxt;
    QLineEdit *fullname;
    QLineEdit *usernametxt;
    QLineEdit *passwordtxt;
    QLineEdit *phoneNumberTxt;

    QDateEdit *dateOfBirthTxt;

    QGridLayout *grid1; //sign up, sign in, guest
    QGridLayout *grid2; //sign up
    QVBoxLayout *box1;

    QDialogButtonBox *dialButtonBox;

    QRadioButton *male;
    QRadioButton *female;
    QRadioButton *other;
    QString gender_string;

    QPushButton *finish;
    QPushButton *refresh;
    QPushButton *signupButton;
    QPushButton *signinButton;
    QPushButton *guestButton;
    QPushButton *mainPage;
    QPushButton *profilePictureButton;

    QGroupBox *group;

    QSpinBox *ageBox;

    QTextEdit *textEdit;

    QImage image;
    QString path;

    QString countryCode;



signals:

public slots:
   void backToMainPage();
   void goToProfile2();
   void insertProfilePicture();
};

#endif // SIGNUP_H
