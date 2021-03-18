#include "begin.h"
#include "ui_begin.h"
#include<QElapsedTimer>
#include"login.h"
begin::begin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::begin)
{
    ui->setupUi(this);
    player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/消灭星星素材/music/开场.mp3"));
    player->setVolume(50);
    ui->label->setScaledContents(true);
    mv = new QMovie(":/image/消灭星星素材/欢呼的gif/开场.gif");
    ui->label->setMovie(mv);
    player->play();
    mv->start();
    time=new QTimer;
    small_time=new QTimer;
    pro=0;
    ui->progressBar->setValue(pro);
    ui->progressBar->setStyleSheet("QProgressBar{color:Gray;background-color:white;font:italic 10pt;text-align:center;}QProgressBar::chunk{background-color:rgb(0,0,0)}");
   connect(time,SIGNAL(timeout()),this,SLOT(timedo()));
   connect(small_time,SIGNAL(timeout()),this,SLOT(smalldo()));
   time->start(8000);
   small_time->start(70);
}

begin::~begin()
{
    delete ui;
    delete player;
    delete time;
    delete small_time;
    delete mv;
}
void begin::timedo(){
    this->close();
    time->stop();
    player->stop();
    mv->stop();
    login *w=new login;
    w->show();

}
void begin::smalldo(){
    pro++;
    ui->progressBar->setValue(pro);
    this->update();

}
