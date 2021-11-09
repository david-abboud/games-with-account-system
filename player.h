#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <string>
#include <QDate>

class player
{
public:
    int age;

    QString username;
    QString password;
    QString firstname;
    QString lastname;
    QString gender;
    QDate dateOfBirth;
    QString phoneNumber;
    QString filePath;
    QString countryCode;

    player(QString username, QString password, QString firstname,
                   QString lastname, QString gender, QDate dateOfBirth, QString phoneNumber, QString path, QString code);
};

#endif // PLAYER_H
