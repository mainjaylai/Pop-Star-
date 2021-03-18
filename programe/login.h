#ifndef LOGIN_H
#define LOGIN_H
#include<QMovie>
#include <QMainWindow>
#include"mainwindow.h"
#include"choose.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
   // MainWindow *w=new MainWindow;
    choose *ww=new choose;
     QMediaPlayer *player=new QMediaPlayer;
     QMediaPlaylist *list=new QMediaPlaylist;
     static QString name1[10];
     static QString passwd1[10];
     static int length;
     bool find(QString a);
     bool isright(QString a,QString b);
      QMovie *movie;
    //  void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
