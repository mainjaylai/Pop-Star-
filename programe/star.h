#ifndef STAR_H
#define STAR_H
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QTimer>
#include<QMovie>
class star :public QObject
{
public:
   int map[12][12];
    star();
   void choose(int x,int y,int n);
   void back();
   void movedown();
   bool check(int x,int y);
   void clear(int x, int y, int n);
   int top(int x);
   int score;
   int clearnum();
   int lastclearnum;
   bool isfinish();
   bool isone(int x, int y);
   bool company();
   void moveleft(int x);
   void update();
   QMediaPlayer *player_vctory;
   QTimer *m_timer;
    QMovie *movie;
   ~star();
public slots:
   void timedo();
};

#endif // STAR_H
