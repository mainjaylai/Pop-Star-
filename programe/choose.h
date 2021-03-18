#ifndef CHOOSE_H
#define CHOOSE_H
#include<QMovie>
#include <QWidget>
#include"mainwindow.h"
#include<QMediaPlayer>
namespace Ui {
class choose;
}

class choose : public QWidget
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = nullptr);
    ~choose();
   MainWindow *w=new MainWindow;
     QMovie *movie;
     void mousePressEvent(QMouseEvent *event);
     QMediaPlayer *player;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::choose *ui;
};

#endif // CHOOSE_H
