#include<QApplication>
#include"mainwindow.h"
#include<QStyleFactory>
#include"login.h"
#include"begin.h"
int main(int argc,char *argv[]){
    QApplication a(argc,argv);
    a.setStyle(QStyleFactory::create("Fusion"));
   class begin hh;
   hh.show();
    return a.exec();
}
