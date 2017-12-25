#include "ppoe.h"
#include<QString>
#include<QDebug>
#include <QThread>
#include <QProcess>
ppoe::ppoe(QString nameandpass)
{
    this->nameandpass=nameandpass;

}
bool ppoe::Connect(){
    QString ConnectName = QObject::tr("宽带连接");
    QString cmd = "Rasdial "+ConnectName+" " + nameandpass;

    qDebug() << cmd;
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<cmd);
    p.waitForStarted();
    p.waitForFinished();

    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    p.close();

    for(int j = 0; j < strTemp.length(); j++)
    {
    if(strTemp[j] > '0' && strTemp[j] < '9'){

        return false;
    }

   }

    return true;
  }


