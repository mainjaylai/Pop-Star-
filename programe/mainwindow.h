#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QPainter>
#include<QMouseEvent>
#include<QTimer>
#include"star.h"
#include<QMediaPlayer>
#include<QString>
#include<QMovie>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    //bool needtime(int a);
    int model;
    QMediaPlayer *player1;
    QMediaPlayer *player_vctory;
    QMediaPlayer *player_pass;
    QMediaPlayer *player_fire;
    QMediaPlayer *un;
    QMediaPlayer *ex;
    QMovie *movie;
    QMovie *movie1;
    QMovie *movie2;
    QMovie *unm;
    QMovie *exm;
    QTimer *m_timer;
    QTimer *pass_timer;
    bool begin;
    int flag;
    int num;
    int flag_1;
    QString title;
   QMediaPlayer *player_fail;
public slots:
    void doTimerService();
    void tryonce();
    void trytwice();
signals:
    void timego();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
      star *w;
      int mouse_x;
      int mouse_y;
      QTimer *timer;
      int much_pass;
     // QTimer *timer1;
};

#endif // MAINWINDOW_H
