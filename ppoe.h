#ifndef PPOE_H
#define PPOE_H
#include<QString>
class ppoe
{
public:
    QString nameandpass;

    ppoe(QString nameandpass);
    bool Connect();
};

#endif // PPOE_H
