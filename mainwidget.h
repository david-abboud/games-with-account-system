#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>


class mainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainWidget(QWidget *parent = nullptr);
    void createGrid1();
private :
    QLabel *firstname;
    QLabel *lastname;
    QLabel *gender;
    QLabel *signup;
    QLabel *dateOfBirth;
    QLabel *username;
    QLabel *password;
    QLabel *phoneNumber;


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


    QPushButton *finish;
    QPushButton *refresh;
    QPushButton *signupButton;
    QPushButton *signinButton;
    QPushButton *guestButton;

    QGroupBox *group;

    QSpinBox *ageBox;

    QTextEdit *textEdit;

signals:

public slots:
    void fillSummary();
    void clearSummary();
    void signUp();
    //void backToMainPage();
    void signIn();
    void guest();
};

#endif // MAINWIDGET_H
