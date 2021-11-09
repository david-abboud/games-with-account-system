#include "player.h"

player::player(QString username, QString password, QString firstname,
               QString lastname, QString gender, QDate dateOfBirth, QString phoneNumber, QString path, QString code)
{
    this->username = username;
    this->password = password;
    this->firstname = firstname;
    this->lastname = lastname;
    this->gender = gender;
    this->dateOfBirth = dateOfBirth;
    this->phoneNumber = phoneNumber;
    this->filePath = path;
    this->countryCode = code;
}
