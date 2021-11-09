#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "player.h"
class DataHandler
{
public:
    QString fileName="/home/eece435l/Merged2/data.json";
    QString gameFile="/home/eece435l/Merged2/qna.json";
    DataHandler();
    QJsonDocument loadJsonFile();
    void saveJsonFile(QJsonDocument jsonDoc);
    void addObject(player user);
    QJsonArray loadArray();
    bool isUnique(QString name);
    bool authenticate(QString name, QString password);
    QJsonArray loadArrayQues();
    QJsonDocument loadJsonFileQues();
    QJsonObject findName(QString username);
    QString returnQues(int i);
    QString returnAns(int i);
    QString returnOption(int i,int j);
    int arraySize();
};

#endif // DATAHANDLER_H
