#include "datahandler.h"
#include <QFile>
#include <QByteArray>
#include <QJsonValue>
DataHandler::DataHandler()
{

}
QJsonDocument DataHandler:: loadJsonFile()
{
    QFile jsonFile(this->fileName);
    jsonFile.open(QFile::ReadOnly);
    QByteArray byteArray=jsonFile.readAll();
    QJsonDocument jsonDoc;
    jsonDoc=jsonDoc.fromJson(byteArray);
    return jsonDoc;

}
QJsonDocument DataHandler:: loadJsonFileQues()
{
    QFile jsonFile(this->gameFile);
    jsonFile.open(QFile::ReadOnly);
    QByteArray byteArray=jsonFile.readAll();
    QJsonDocument jsonDoc;
    jsonDoc=jsonDoc.fromJson(byteArray);
    return jsonDoc;

}
void DataHandler::saveJsonFile(QJsonDocument jsonDoc)
{
    QFile jsonFile(this->fileName);
    jsonFile.open(QFile::WriteOnly);
    QByteArray byteArray=jsonDoc.toJson();
    jsonFile.write(byteArray);
}

void DataHandler::addObject(player user)
{
    QJsonValue jUsername=QJsonValue(user.username.toLower());
    QJsonValue jPassword=QJsonValue(user.password);
    QJsonValue jFirstName = QJsonValue(user.firstname);
    QJsonValue jLastName = QJsonValue(user.lastname);
    QJsonValue jDateOfBirth = QJsonValue(user.dateOfBirth.toString());
    QJsonValue jPhoneNumber = QJsonValue(user.phoneNumber);
    QJsonValue jGender = QJsonValue(user.gender);
    QJsonValue jPath = QJsonValue(user.filePath);
    QJsonValue jCode = QJsonValue(user.countryCode);



    QJsonObject jUser;
    jUser.insert("username",jUsername);
    jUser.insert("password",jPassword);
    jUser.insert("firstname",jFirstName);
    jUser.insert("lastname",jLastName);
    jUser.insert("dateOfBirth",jDateOfBirth);
    jUser.insert("phoneNumber",jPhoneNumber);
    jUser.insert("gender", jGender);
    jUser.insert("profile_picture_path", jPath);
    jUser.insert("countryCode", jCode);



    QJsonDocument jsonDoc=this->loadJsonFile();
    QJsonObject mainObj=jsonDoc.object();
    QJsonArray jArray=mainObj["data"].toArray();
    jArray.append(jUser);
    mainObj["data"]=jArray;
    jsonDoc=QJsonDocument(mainObj);
    this->saveJsonFile(jsonDoc);
}

QJsonArray DataHandler::loadArray()
{
    QJsonDocument jsonDoc=this->loadJsonFile();
    QJsonObject mainObj=jsonDoc.object();
    return mainObj["data"].toArray();
}
QJsonArray DataHandler::loadArrayQues()
{
    QJsonDocument jsonDoc=this->loadJsonFileQues();
    QJsonObject mainObj=jsonDoc.object();
    return mainObj["data"].toArray();
}
QString DataHandler :: returnQues(int i)
{
    QJsonArray jArray=this->loadArrayQues();
    QJsonObject obj=jArray[i].toObject();
    return obj["Question"].toString();
}
QString DataHandler::returnOption(int i,int j)
{
    QJsonArray jArray=this->loadArrayQues();
    QJsonObject obj=jArray[i].toObject();
    return obj["Answer "+QString::number(j)].toString();
}
QString DataHandler:: returnAns(int i)
{
    QJsonArray jArray= this->loadArrayQues();
    QJsonObject obj=jArray[i].toObject();
    return obj["Answer"].toString();
}
int DataHandler :: arraySize()
{
    QJsonArray jArray= this->loadArrayQues();
    return jArray.size();
}
bool DataHandler::isUnique(QString name)
{
    QJsonArray jArray=this->loadArray();
    for (auto obj:jArray)
    {
            QJsonObject object=obj.toObject();
            if (object.value("username").toString()==name)
            {
                return false;
            }

    }
     return true;
}
bool DataHandler::authenticate(QString name, QString password)
{
    QJsonArray jArray=loadArray();
    for (auto obj:jArray)
    {
        QJsonObject object=obj.toObject();
        if (object.value("username").toString().toLower()==name&&object.value("password").toString()==password)
        {
            return true;
        }
    }
    return false;
}

QJsonObject DataHandler::findName(QString username)
{
    QJsonArray jArray=loadArray();
    for (auto obj:jArray)
    {
        QJsonObject object=obj.toObject();
        if (object.value("username").toString().toLower() == username.toLower())
        {
            return object;
        }
    }
}

