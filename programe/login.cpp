#include "login.h"
#include "ui_login.h"
#include<QString>
#include<QMessageBox>
int login::length=0;
QString login::name1[10]={};
QString login::passwd1[10]={};
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->label_5->setScaledContents(true);
    movie = new QMovie(":/image/消灭星星素材/欢呼的gif/背景.gif");
    ui->label_5->setMovie(movie);
    movie->start();
    ui->buttonback->hide();
    ui->putagain->hide();
    list->addMedia(QUrl("qrc:/music/消灭星星素材/music/music1.mp3"));
    list->addMedia(QUrl("qrc:/music/消灭星星素材/music/music2.mp3"));
    list->addMedia(QUrl("qrc:/music/消灭星星素材/music/music3.mp3"));
    list->addMedia(QUrl("qrc:/music/消灭星星素材/music/music4.mp3"));
    list->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(list);
    player->setVolume(30);
    player->play();
}
login::~login()
{
    delete ui;
}
void login::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text();
    QString passwd=ui->lineEdit_2->text();
    if(name==" ")
        QMessageBox::warning(NULL,tr("worning"),tr("密码不能为空"));
    else if(passwd==" ")
        QMessageBox::warning(NULL,tr("worning"),tr("用户名不能为空"));
    else if((name=="root"&&passwd=="123456")||isright(name,passwd))
    {
        QMessageBox::information(NULL,tr("祝贺"),tr("登陆成功"),QMessageBox::Yes);
        this->close();
        ww->show();
    }
    else
    {
        QMessageBox::warning(NULL,tr("worning"),tr("账号密码错误"));
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
}

void login::on_pushButton_2_clicked()
{
    ui->buttonback->show();
    ui->putagain->show();
    ui->buttonlogin->hide();
    ui->label->hide();
    ui->label_6->hide();
}

void login::on_pushButton_4_clicked()
{
    ui->buttonback->hide();
    ui->putagain->hide();
    ui->buttonlogin->show();
    ui->label->show();
    ui->label_6->show();
}

void login::on_pushButton_3_clicked()
{
    QString name=ui->lineEdit->text();
    QString passwd=ui->lineEdit_2->text();
    QString passwd2=ui->lineEdit_3->text();
    if(name=="")
        QMessageBox::warning(NULL,tr("worning"),tr("用户名不能为空"));
    else if(passwd=="")
        QMessageBox::warning(NULL,tr("worning"),tr("密码不能为空"));
    else if(passwd2=="")
        QMessageBox::warning(NULL,tr("worning"),tr("你还未再次输入密码"));
    else if(passwd!=passwd2)
       {
        QMessageBox::warning(NULL,tr("worning"),tr("两次输入的密码不一致"));
        ui->lineEdit_3->clear();
        ui->lineEdit_2->clear();
    }
    else if(!find(name))
    {
        QMessageBox::warning(NULL,tr("worning"),tr("注册失败，该用户名已注册"));
        ui->lineEdit_3->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->clear();
    }
    else {
        name1[length]=name;
        passwd1[length]=passwd;
        length++;
         QMessageBox::information(NULL,tr("恭喜"),tr("注册成功"),QMessageBox::Yes);
         ui->lineEdit->clear();
         ui->lineEdit_2->clear();
         ui->lineEdit_3->clear();

    }
}
bool login::find(QString a){
    for(int i=0;i<=length;i++)
        if(name1[i]==a)
            return false;
    return true;
}
bool login::isright(QString a,QString b){
    for(int i=0;i<=length;i++)
        if(name1[i]==a&&passwd1[i]==b)
            return true;
    return false;
}
