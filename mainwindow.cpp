#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include<QMessageBox>
#include <QDebug>
#include "ppoe.h"
#include "csimplethread.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(this->width(), this->height());

    QAction *action_say = new QAction((QObject::tr("说明")),this);
     ui->mainToolBar->addAction(action_say);
      connect(action_say,SIGNAL(triggered()),this,SLOT(say()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setdata(QString data){
    this->data=data;
}

void MainWindow::on_commandLinkButton_clicked()
{
    ui->commandLinkButton->setText("Connecting !...");
    ui->commandLinkButton->setEnabled (false);

    bool connectflag=false;
    int  ConnectTime;
    int i=0;
    QString temp;


     for(int j=0;j<data.length();j++){
         if(data[j]=='\n')
             i++;
     }
     ConnectTime=i;

     i=0;

     for(int j=0;j<data.length();j++){
         if(data[j]!='\n'){
             temp=temp+data[j];
         }
        if(data[j]=='\n'){
            qDebug()<<temp;


            ppoe p= ppoe(temp);


            ui->label->setText(QObject::tr("正在进行第")+QString::number(i+1, 10)+QObject::tr("次连接 共")+QString::number(ConnectTime, 10) +QObject::tr("次连接！"));
            if(p.Connect()){

                 QMessageBox::information(NULL, QString(QObject::tr("成功")), QString(QObject::tr("连接成功")));
                 connectflag=true;
                 say();
                 ui->label->setText(QString(QObject::tr("连接成功")));
                 break;
            }

            temp="";
            i++;
        }
     }

     if(connectflag==false)
                QMessageBox::information(NULL, QString(QObject::tr("失败")), QString(QObject::tr("连接失败")));
}
void MainWindow::say(){

    QMessageBox message(QMessageBox::NoIcon,  QString(QObject::tr("觉得不错吗？赏根辣条吧？企鹅号 嘿嘿嘿")), QString(QObject::tr("说明:\n1、此软件开源，如有侵权，请联系原作者删除！\n2、此软件仅供娱乐，使用者后果自负！\n3、此软件一旦失效，不再提供更新.\n4、连接过程中软件会卡死属于正常情况请耐心等待。\n5、此软件不支持无线！！！！/笑哭")));
    message.setIconPixmap(QPixmap("data2"));
    message.exec();


}
