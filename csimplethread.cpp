#include "csimplethread.h"
#include <QThread>
#include<QDebug>
#include <QString>
#include "ppoe.h"
CSimpleThread::CSimpleThread()
{

}

bool CSimpleThread::run(QString data)
{
      ppoe p= ppoe(data);

      if(p.Connect()) return true;
      else return false;

}
