#ifndef BEGIN_H
#define BEGIN_H

#include <QWidget>
#include<QTimer>
#include<QMediaPlayer>
#include<QMovie>
namespace Ui {
class begin;
}

class begin : public QWidget
{
    Q_OBJECT

public:
    explicit begin(QWidget *parent = nullptr);
    ~begin();
    int pro;
    QTimer *time;
    QTimer *small_time;
    QMediaPlayer *player;
    QMovie *mv;
public slots:
    void timedo();
    void smalldo();
private:
    Ui::begin *ui;
};

#endif // BEGIN_H
