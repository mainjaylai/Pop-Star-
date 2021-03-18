#include "star.h"
#include<QTime>
#include<QMessageBox>

#include<QDateTime>
#define chose1(b)  {map[x][y]=b;choose(x+1,y,n);choose(x,y+1,n);choose(x-1,y,n);}
#define chose2(b)  {map[x][y]=b;choose(x+1,y,n);choose(x,y-1,n); choose(x-1,y,n);}
#define chose3(b)  { map[x][y]=b;choose(x+1,y,n);choose(x,y+1,n);choose(x-1,y,n);choose(x,y-1,n);}
#define chose4(b)  {map[x][y]=b;clear(x+1,y,n);clear(x,y+1,n);clear(x-1,y,n);}
#define chose5(b)  {map[x][y]=b;clear(x+1,y,n);clear(x,y-1,n); clear(x-1,y,n);}
#define chose6(b)  { map[x][y]=b;clear(x+1,y,n);clear(x,y+1,n);clear(x-1,y,n);clear(x,y-1,n);}
star::star()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
            map[i][j]=(int)(qrand()%5+1);
        }
    for(int i=0;i<12;i++)
        map[11][i]=map[0][i]=map[i][11]=map[i][0]=-1;
    score=lastclearnum=0;
    m_timer=new QTimer;
    player_vctory=new QMediaPlayer;
     player_vctory->setMedia(QUrl("qrc:/music/消灭星星素材/游戏中音效/游戏开始结束声/游戏开始（新的一关）.mp3"));
     player_vctory->setVolume(50);
     connect(m_timer,SIGNAL(timeout()),this,SLOT(timedo()));
}
star::~star(){

}
void star::choose(int x,int y,int n){
    if(map[x][y]==n&&y==1){
        if(n==1) chose1(11);
        if(n==2) chose1(22);
        if(n==3) chose1(33);
        if(n==4) chose1(44);
        if(n==5) chose1(55);
    }
   else if(map[x][y]==n&&y==10){
        if(n==1) chose2(11);
        if(n==2) chose2(22);
        if(n==3) chose2(33);
        if(n==4) chose2(44);
        if(n==5) chose2(55);
    }
  else  if(map[x][y]==n){
        if(n==1) chose3(11);
        if(n==2) chose3(22);
        if(n==3) chose3(33);
        if(n==4) chose3(44);
        if(n==5) chose3(55);

    }
    else return;
}
void star::back(){
    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
            if(map[i][j]==11)
                map[i][j]=1;
            if(map[i][j]==22)
                map[i][j]=2;
            if(map[i][j]==33)
                map[i][j]=3;
            if(map[i][j]==44)
                map[i][j]=4;
            if(map[i][j]==55)
                map[i][j]=5;
        }
}
void star::clear(int x, int y,int n){
    if(map[x][y]==n&&y==1){
        chose4(100);
    }
   else if(map[x][y]==n&&y==10){
        chose5(100);
    }
   else  if(map[x][y]==n){
       chose6(100);
    }
    else return;
}
void star::movedown(){
    for(int j=1;j<11;j++)
    {
        for(int i=1;i<11;i++){
            if(map[i][j]==100&&check(i,j)){
                int n=top(i);
                    for(int k=j;k>n;k--)
                        map[i][k]=map[i][k-1];
                      map[i][n]=100;

            }
        }

    }
}
bool star::check(int x, int y){
    for(int i=1;i<y;i++)
        if(map[x][i]<10&&map[x][i]>0)
            return true;
    return false;
}
int star::top(int x){
    int i=1;
    for(;i<10;i++){
        if(map[x][i]<10&&map[x][i]>0)
            break;
    }
    return i;
}
int star::clearnum(){
    int total=0;
    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
            if(map[i][j]==100)
                total++;
    return total;
}
bool star::isfinish(){
   for(int i=1;i<11;i++)
       for(int j=1;j<11;j++)
           if(map[i][j]>0&&map[i][j]<100&&(!isone(i,j)))
               return false;
   return true;

}
bool star::isone(int x, int y){
      if((map[x][y]==map[x][y+1]||map[x][y]==map[x][y-1]||map[x][y]==map[x+1][y]||map[x][y]==map[x-1][y])&&map[x][y]>0)
          return false;
      else  return true;
}
bool star::company(){
    for(int i=1;i<11;i++){
        for(int j=1;j<11;j++)
            if(map[i][j]<100)
               goto finishi;
          for(int k=i;k<10;k++)
              moveleft(k);
          for(int m=1;m<11;m++)
              if(map[i][m]<100)
                  goto finishi;
          for(int k=i;k<10;k++)
              moveleft(k);
             return true;
     finishi:{}
    }
    return false;
}
void star::moveleft(int x){
    for(int i=1;i<11;i++)
       { map[x][i]=map[x+1][i];
        map[x+1][i]=100;}

}
void star::update(){
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
            map[i][j]=(int)(qrand()%5+1);
        }
    for(int i=0;i<12;i++)
        map[11][i]=map[0][i]=map[i][11]=map[i][0]=-1;
    lastclearnum=0;
   player_vctory->play();

}
void star::timedo(){
    player_vctory->stop();
    this->update();
}
