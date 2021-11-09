#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class profilePage : public QWidget
{
    Q_OBJECT
public:
    explicit profilePage(QString firstname_param, QString lastname_param, QString path, QString countryCode_param, QWidget *parent = nullptr);
    explicit profilePage(QWidget *parent = nullptr);
private:
    QGridLayout *grid4;
    QLabel *firstname;
    QLabel *lastname;
    QLabel *date_label;

    QPushButton *battleshipButton;

    QDate *date;

    QImage *profilePictureImage;
    QLabel *profilePictureLabel;

signals:

public slots:
    void playBattleship();
};

#endif // PROFILEPAGE_H
