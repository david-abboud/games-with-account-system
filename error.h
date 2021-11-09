#ifndef ERROR_H
#define ERROR_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class Error : public QWidget
{
    Q_OBJECT
public:
    Error(QString err, QWidget *parent = nullptr);
private:
    QLabel *errorMessage;
    QGridLayout *grid5;
signals:

};

#endif // ERROR_H
