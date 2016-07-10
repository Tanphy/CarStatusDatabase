#include "datamanager.h"
#include <QDebug>
#include "mfieldglobal.h"
#include <QTime>

void  DataManager::setModel(QSqlTableModel* model)
{
    MModel=model;
    MModel->select();
    carTable=MModel->tableName();
}
QSqlTableModel* DataManager::selectData(int field, QVariant min, QVariant max)
{
    MFieldGlobal fieldGlobal;
    QSqlTableModel* model=new QSqlTableModel;
    model->setTable(carTable);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setFilter(MModel->filter());
    QString fieldName=fieldGlobal.getValue(field);
    if (field==MFieldGlobal::TIME) model->setFilter(QString("%1>='%2' and %1 <='%3'").arg(fieldName).arg(min.toTime().toString("hh:mm:ss.zzz")).arg(max.toTime().toString("hh:mm:ss.zzz")));
    else if (field==MFieldGlobal::LATITUDE||field==MFieldGlobal::LONGITUDE)
    {
        model->setFilter(QString("%1>=%2 and %1 <=%3").arg(fieldName).arg(min.toDouble()).arg(max.toDouble()));
    }
    else if(field<=MFieldGlobal::VALUE2)
    {
        model->setFilter(QString("%1>=%2 and %1 <=%3").arg(fieldName).arg(min.toFloat()).arg(max.toFloat()));
    }
    else qDebug()<<"Out of range";
    //    qDebug()<<model->filter();
    model->select();
    //    int rowCOunt=model->rowCount();
    return model;
}
QSqlTableModel* DataManager::selectData(int field, QVariant value)
{
    MFieldGlobal fieldGlobal;
    QString fieldName=fieldGlobal.getValue(field);
    qDebug()<<fieldName;
    QSqlTableModel* model=new QSqlTableModel;
    model->setTable(carTable);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setFilter(MModel->filter());
    if (field==MFieldGlobal::TIME) model->setFilter(QString("%1='%2'").arg(fieldName).arg(value.toTime().toString("hh:mm:ss.zzz")));
    else if (field==MFieldGlobal::LATITUDE||field==MFieldGlobal::LONGITUDE)
    {
        model->setFilter(QString("%1=%2").arg(fieldName).arg(value.toDouble()));
    }
    else if(field<=MFieldGlobal::VALUE2)
    {
        model->setFilter(QString("%1=%2").arg(fieldName).arg(value.toFloat()));
    }
    else qDebug()<<"Out of range";
    qDebug()<<model->filter();
    model->select();
    //    int rowCOunt=model->rowCount();
    return model;
}
QVector<QVariantList> DataManager::getData()
{
    QVector<QVariantList> vector;
    while(MModel->canFetchMore()) MModel->fetchMore();
    int rowCount=MModel->rowCount();
    for (int i=0;i<rowCount;i++)
    {
        QSqlRecord record=MModel->record(i);
        QVariantList list;
    //提取所有数据，开关量为整型值形式
        for(int j=0;j<record.count();j++)
        {
            list.append(record.value(j));
        }

//    //下面用来提取将后两个整型值转换为开关量后的结果
//        for(int j=0;j<record.count()-2;j++)
//        {
//            list.append(record.value(j));
//        }
//        int onoff=record.value(record.count()-2).toInt();
//        bitset<32> set1(onoff);
//        QBitArray bit(32);
//        for (int j=0;j<32;j++)
//        {
//            bit[j]=set1[j];
//        }
//        list.append(bit);
//        onoff=record.value(record.count()-1).toInt();
//        bitset<32> set2(onoff);
//        QBitArray bit2(32);
//        for (int j=0;j<32;j++)
//        {
//            bit2[j]=set2[j];
//        }
//        list.append(bit2);


        vector.append(list);
    }
    return vector;
}
QSqlTableModel* DataManager::getModel()
{
    return MModel;
}
QSqlTableModel* DataManager::selectOnOff(int field, bool onoff)//field为查询的开关量在开关量内部的相对位置，不是在整体中的位置，1-32为第一个开关量整形值，33-64为第二个开关量整型值
{
    int value=onoff;
    QSqlTableModel* model=new QSqlTableModel;
    model->setTable(carTable);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setFilter(MModel->filter());
    //在第一个整形值里查询
    if (field<=32&&field>0)
    {
    model->setFilter(QString("BitHandler(OnOff,%1,%2)=1").arg(field).arg(value));
    qDebug()<<model->filter();
    model->select();
    }
    //在第二个整形值里查询
    else if (field>32 and field<=64)
    {
        model->setFilter(QString("BitHandler(Value3,%1,%2)=1").arg(field-32).arg(value));
        qDebug()<<model->filter();
        model->select();
    }
    else
    {
        qDebug()<<"Invalide field number in DataManager::selectOnOff";
    }
    return model;
}
//QVector<QBitArray> DataManager::getOnOff()
//{
//    QVector<QBitArray> vector;
//    while(MModel->canFetchMore()) MModel->fetchMore();
//    int rowCount=MModel->rowCount();
//    for (int i=0;i<rowCount;i++)
//    {
//        QSqlRecord record=MModel->record(i);
//        int onoff=record.value(MFieldGlobal::ONOFF).toInt();
//        bitset<4> set1(onoff);
//        QBitArray bit(4);
//        for (int j=0;j<4;j++)
//        {
//            bit[j]=set1[j];
//        }
//        vector.append(bit);
//    }
//    return vector;
//}
