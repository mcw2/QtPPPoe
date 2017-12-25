#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include<QDebug>
#include <QString>
#include<QMessageBox>
#include <QFile>
#include"mainwindow.h"
#include "ppoe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon("icon"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QString data;
    QFile file("data.dat");
    if(!file.open(QIODevice::ReadOnly))
    {
         qDebug()<< "error!";
         QMessageBox::information(NULL, QString(QObject::tr("软件初始化失败！")), QString(QObject::tr("请检查数据文件是否丢失！")));
          return a.exec();
    }
    QDataStream in(&file);
    in >>data;
    file.close();
     // qDebug()<<data;
    w.setdata(data);
    w.show();
    return a.exec();
}
