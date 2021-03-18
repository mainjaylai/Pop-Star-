#include "choose.h"
#include "ui_choose.h"
#include"login.h"
choose::choose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
    ui->model_choose->hide();
    ui->label->setScaledContents(true);
    movie = new QMovie(":/image/消灭星星素材/欢呼的gif/背景.gif");
    ui->label->setMovie(movie);
    movie->start();
    ui->model_choose->hide();
    ui->toolBox->hide();
    player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/消灭星星素材/游戏中音效/游戏开始结束声/游戏开始（新的一关）.mp3"));
    player->setVolume(50);
}
choose::~choose()
{
    delete ui;
}

void choose::on_pushButton_clicked()
{
    ui->first->hide();
    ui->model_choose->show();
}

void choose::on_pushButton_2_clicked()
{
    ui->first->hide();
}

void choose::on_pushButton_5_clicked()
{
    this->close();
    player->play();
    w->model=1000;
    w->show();
}

void choose::on_pushButton_6_clicked()
{
    this->close();
     player->play();
    w->model=1500;
    w->show();
}

void choose::on_pushButton_7_clicked()
{
    this->close();
    player->play();
    w->model=2000;
    w->show();
}

void choose::on_pushButton_3_clicked()
{
    ui->first->hide();
    ui->toolBox->show();
}
void choose::mousePressEvent(QMouseEvent *event){
    ui->first->show();
    ui->toolBox->hide();
    ui->model_choose->hide();
}

void choose::on_pushButton_4_clicked()
{
  this->close();
}
