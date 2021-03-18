#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include<QMessageBox>
#include<QDateTime>
#include"choose.h"
#include<QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),model(1000)
{
    ui->setupUi(this);
    w=new star();
    timer=new QTimer;
    m_timer=new QTimer;
    pass_timer=new QTimer;
    much_pass=1;
    flag_1=0;
    num=0;
    title=" ";
    begin=false;
    player1=new QMediaPlayer;
    player_vctory=new QMediaPlayer;
    player_fail=new QMediaPlayer;
    player_pass=new QMediaPlayer;
    player_fire=new QMediaPlayer;
    un=new QMediaPlayer;
    ex=new QMediaPlayer;
    player1->setMedia(QUrl("qrc:/music/消灭星星素材/游戏中音效/消除方块声/ci.wav"));
    player_vctory->setMedia(QUrl("qrc:/music/消灭星星素材/music/欢呼.mp4"));
    player_fail->setMedia(QUrl("qrc:/music/消灭星星素材/游戏中音效/游戏开始结束声/游戏失败（得分低3）.mp3"));
    player_pass->setMedia(QUrl("qrc:/music/消灭星星素材/music/过关.mp4"));
    player_fire->setMedia(QUrl("qrc:/music/消灭星星素材/music/fire.mp3"));
    un->setMedia(QUrl("qrc:/music/消灭星星素材/music/un.mp3"));
    ex->setMedia(QUrl("qrc:/music/消灭星星素材/music/ex.mp3"));
    player1->setVolume(50);
    player_pass->setVolume(100);
    player_vctory->setVolume(100);
    player_fail->setVolume(50);
    player_fire->setVolume(80);
    ex->setVolume(80);
    un->setVolume(80);
    connect(timer,SIGNAL(timeout()),this,SLOT(doTimerService()));
    connect(m_timer,SIGNAL(timeout()),this,SLOT(tryonce()));
    connect(pass_timer,SIGNAL(timeout()),this,SLOT(trytwice()));
    ui->label_4->setScaledContents(true);
    movie = new QMovie(":/image/消灭星星素材/欢呼的gif/欢呼3.gif");
    ui->label_4->setMovie(movie);
    ui->label_3->setScaledContents(true);
    movie1 = new QMovie(":/image/消灭星星素材/欢呼的gif/欢呼5.gif");
    ui->label_3->setMovie(movie1);
    ui->pass->setScaledContents(true);
    movie2 = new QMovie(":/image/消灭星星素材/欢呼的gif/欢呼4.gif");
    ui->pass->setMovie(movie2);
    ui->ex->setScaledContents(true);
    exm = new QMovie(":/image/消灭星星素材/欢呼的gif/欢呼2.gif");
    ui->ex->setMovie(exm);
    ui->un->setScaledContents(true);
    unm = new QMovie(":/image/消灭星星素材/欢呼的gif/欢呼7.gif");
    ui->un->setMovie(unm);
    ui->pushButton->hide();
    ui->pushButton_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    brush.setStyle(Qt::DiagCrossPattern);
    painter.drawPixmap(0,0,480,640,QPixmap(":/tupian/tipian/背景图片480x640.png"));

    QString str;
    str = QString("第  %1  关   ").arg(much_pass);
    ui->label_2->setText(str);
    QString str1;
    str1 = QString("分数：  %1          目标分数： %2 ").arg(w->score).arg(much_pass*model);
    ui->title->setText(title);
    ui->label->setText(str1);

    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
            if(w->map[i][j]==1){

                painter.drawPixmap(40+40*(i-1),160+40*(j-1),40,40,QPixmap(":/tupian/tipian/blue.jpg"));
            }
            if(w->map[i][j]==2){
               painter.drawPixmap(40+40*(i-1),160+40*(j-1),40,40,QPixmap(":/tupian/tipian/green.jpg"));

            }
            if(w->map[i][j]==3){
               painter.drawPixmap(40+40*(i-1),160+40*(j-1),40,40,QPixmap(":/tupian/tipian/yellow.jpg"));
            }
            if(w->map[i][j]==4){
                 painter.drawPixmap(40+40*(i-1),160+40*(j-1),40,40,QPixmap(":/tupian/tipian/purple.jpg"));
            }
            if(w->map[i][j]==5){
                 painter.drawPixmap(40+40*(i-1),160+40*(j-1),40,40,QPixmap(":/tupian/tipian/red.jpg"));
            }
            if(w->map[i][j]>10&&w->map[i][j]<100){
              painter.drawPixmap(40+40*(i-1),160+40*(j-1),40,40,QPixmap(":/tupian/tipian/whrite.jpg"));
            }
        }
}
void MainWindow::mousePressEvent(QMouseEvent *event){
   if(!(w->isfinish())){
    flag=0;
    w->back();
    repaint();
    QPoint position=event->pos();
    mouse_x=(position.x()-40)/40+1;
    mouse_y=(position.y()-160)/40+1;
    int n=w->map[mouse_x][mouse_y];
    w->choose(mouse_x,mouse_y,n);
    repaint();
    }
}
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
    if(!(w->isfinish())){
    flag=0;
    QPoint position=event->pos();
    mouse_x=(position.x()-40)/40+1;
    mouse_y=(position.y()-160)/40+1;
    int n=w->map[mouse_x][mouse_y];
    if(!(w->isone(mouse_x,mouse_y)))
    {
    begin=true;
    player1->play();
    timer->start(450);
    w->clear(mouse_x,mouse_y,n);
    w->movedown();
    }
    if(w->company()){
        repaint();
    }
    w->score+=(w->clearnum()-w->lastclearnum)*(w->clearnum()-w->lastclearnum)*5;
    title=QString("消除 %1 个 ， 得 %2 分").arg(w->clearnum()-w->lastclearnum).arg((w->clearnum()-w->lastclearnum)*(w->clearnum()-w->lastclearnum)*5);
    repaint();
    if(w->clearnum()-w->lastclearnum>=5&&w->clearnum()-w->lastclearnum<8){
        begin=true;
        ui->label_4->show();
        movie->start();
        player_vctory->play();
        timer->start(1000);
    }
    if(w->clearnum()-w->lastclearnum>=8&&w->clearnum()-w->lastclearnum<=10){
        begin=true;
        ui->ex->show();
        exm->start();
        ex->play();
        timer->start(1000);
    }
    if(w->clearnum()-w->lastclearnum>10){
        begin=true;
        ui->un->show();
        unm->start();
        un->play();
        timer->start(1000);
    }
    if(w->score>=(much_pass)*model&&flag_1==0)
       {
        title="            过关了";
        repaint();
        ui->pass->show();
        movie2->start();
        player_pass->play();
        pass_timer->start(1000);

       }
    w->lastclearnum=w->clearnum();
    }
   if(w->isfinish())
    {
       flag=1;
       timer->stop();
       num=100-w->clearnum();
       int n=num;
        if(num<10)
        {
            w->score+=(2000-num*5);    
        }

        timer->start(160);
        if(w->score>=(much_pass)*model)
           {
            if(n<10)
               title=QString("还剩 %1 个 ， 得 %2 分").arg(n).arg((2000-n*n*20));
            else  title=QString("还剩 %1 个 ， 得 0 分").arg(n);
            repaint();
            movie1->start();
            ui->label_3->show();
            player_fire->play();
            m_timer->start(3000);
            ui->pushButton_2->show();
            ui->pushButton->show();
      }
        if(w->score<(much_pass)*model)
          {
            player_fail->play();
            QMessageBox::warning(NULL,tr("worning"),tr("游戏结束"));
            this->close();
            class choose *p=new choose;
            p->show();
          }

   }
}
void MainWindow::doTimerService(){

    if(begin&&flag==0){
        player1->stop();
        exm->stop();
        unm->stop();
        movie->stop();
        ui->label_4->hide();
        ui->ex->hide();
        ui->un->hide();
        this->update();
        ex->stop();
        un->stop();
        begin=false;
    }
    if(flag==1){
        int i=1,j=1;
            for(;j<11;j++)
                if((w->map[i][j]<100))
                    goto hh;
         hh:{
                        w->map[i][j]=100;
                        repaint();
                        if(num!=0)
                          num--;
                        this->update();
                        if(w->company())
                        {
                            repaint();
                        }
                        if(num==0)
                            timer->stop();
        }
    }
}
void MainWindow::tryonce(){
    movie1->stop();
    ui->label_3->hide();
    ui->title->hide();
    player_fire->stop();
    m_timer->stop();
}
void MainWindow::on_pushButton_2_clicked()
{
    w->update();
    much_pass++;
    repaint();
    flag_1=0;
    ui->pushButton_2->hide();
    ui->pushButton->hide();
    ui->title->show();
    title=" ";
}

void MainWindow::on_pushButton_clicked()
{
         this->close();
    class choose *p=new choose;
          p->show();
}
void MainWindow::trytwice(){
    movie2->stop();
    ui->pass->hide();
    pass_timer->stop();
    flag_1=1;
}
