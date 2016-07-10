#include <QCoreApplication>
#include <mrecord.h>
#include <QDebug>
#include <bits.h>
#include <iostream>
#include <qglobal.h>
#include <bitset>
#include <dbmanager.h>
#include "mfieldglobal.h"
#include <QTime>
int randInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}
double dRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
float fRand(float fMin, float fMax)
{
    float f = (float)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main(int argc, char *argv[])
{
    //    MFieldGlobal field;
    QCoreApplication a(argc, argv);
    QTime time = QTime::currentTime();
    srand((uint)time.msec());
    MRecord record;
    DbManager *db=new DbManager(time,200,":memory:",4);
    int sum=10;
    while (sum)
    {
        QVector<double> d;
        QVector<float> f;
        int n=2;
        while(n)
        {
            double randomValue = dRand(0.0,100.0);
            d.append(randomValue);
            --n;
        }
        n=10;
        while(n)
        {
            float randomValue=fRand(1.0,50.0);
            f.append(randomValue);
            --n;
        }
        n=2;
        while(n)
        {
            --n;
            record.setField(n,d[n]);
        }
        n=12;
        while(n!=2)
        {
            --n;
            record.setField(n,f[n-2]);
        }
        int onoff=255000;
        record.setField(MFieldGlobal::ONOFF,onoff);
        onoff=randInt(0,2147000000);
        record.setField(MFieldGlobal::VALUE3,onoff);
//        qDebug()<<record.getFields();
        --sum;
        db->append(record,2);
//        record.reset();
    }
    QSqlTableModel *model=db->getDataModel(2);
    DataManager manager;
    manager.setModel(model);
    QVector<QVariantList>list=manager.getData();
    qDebug()<<"*********************ALL DATA**********************";
    for (int i=0;i<list.length();i++)
        qDebug()<<list[i];
//    qDebug()<<"*******************************QUERY RESULT*****************************************";
//    list.clear();
//    //    manager.setModel(manager.selectData(MFieldGlobal::LATITUDE,0,100));
//        QSqlTableModel *model1=manager.selectData(MFieldGlobal::TIME,time,time.addMSecs(53));//time格式为HH:MM:ss.zzz
//        manager.setModel(model1);
//        QSqlTableModel *model2=manager.selectData(MFieldGlobal::LATITUDE,0,10);
//        manager.setModel(model2);
////    manager.setModel(manager.selectOnOff(13,true));
//    //    manager.setModel(model);
//    list=manager.getData();
//    //    QVector<QBitArray> list=manager.getOnOff();
//    for (int i=0;i<list.length();i++)
//        qDebug()<<list[i];
    db->close();
    return a.exec();
}

