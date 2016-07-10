#include <dbmanager.h>
#include <QStringList>
#include <QSqlDatabase>
#include "mfieldglobal.h"
#include <bitset>
#include <sqlite3.h>
#include <QtSql>
void bitHandler(sqlite3_context* ctx,int nargs,sqlite3_value** values)
{
    if(nargs!=3)qDebug()<<"Check argument count!";
    int dbvalue(sqlite3_value_int(values[0]));//数据库里的整形开关量
    int pos(sqlite3_value_int(values[1]));//查询的开关量位置，从1开始计数
    int value(sqlite3_value_int(values[2]));//查询的开关量值
    std::bitset<32> bit1(dbvalue);
    if (bit1[pos-1]==value)//符合条件则返回1，否则返回0
    {
        sqlite3_result_int(ctx, 1);
    }
    else
    {
        sqlite3_result_int(ctx, 0);
    }
}
DbManager::~DbManager()
{
    db.close();
}
DbManager::DbManager(QTime startTime, int freq, QString filename, int carCount)
{
    MStartTime=startTime;
    MFreq=freq;
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filename);//以后改为具体路径和名称
    if (!db.open()) qDebug()<<db.lastError().text();
    QSqlQuery query;
    for (int i=1;i<carCount+1;i++)
    {
        query.exec(QString("create table Car%1Status (Time QTime,Longitude double , Latitude double,"
                           "SteerAngle float, MaxEncode float,Gas float,Brake float,"
                           "Speed float,RotaSpeed float,FuelConsumtion float,LimitSpeed float,"
                           "Value1 float,Value2 float,ONOFF int,Value3 int)").arg(i));
    }
    if (query.lastError().isValid()) qDebug()<<query.lastError().text();
    sqlite3* sldb=*static_cast<sqlite3 **>(db.driver()->handle().data());
    sqlite3_initialize();
    sqlite3_create_function(sldb, "BitHandler",3, SQLITE_UTF8, NULL, &bitHandler, NULL, NULL);
    //    qDebug()<<db.tables();
}
QSqlTableModel* DbManager::getDataModel(int carNumber)
{
    QSqlTableModel* model=new QSqlTableModel;
    model->setTable(QString("Car%1Status").arg(carNumber));
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    return model;
}
void DbManager::append(MRecord datarecord, int carNumber)
{
    QSqlTableModel* model=new QSqlTableModel;
    model->setTable(QString("Car%1Status").arg(carNumber));
    if(model->lastError().isValid()) qDebug()<<model->lastError().text();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    while (model->canFetchMore()) model->fetchMore();
    QSqlRecord record=model->record();
    int id=model->rowCount();
    record.setValue("Time",MStartTime.addMSecs(id*1000/MFreq));
    if(model->lastError().isValid()) qDebug()<<model->lastError().text();
    record.setValue("Longitude",datarecord.getField(MFieldGlobal::LONGITUDE));
    record.setValue("Latitude",datarecord.getField(MFieldGlobal::LATITUDE));
    record.setValue("SteerAngle",datarecord.getField(MFieldGlobal::STEERANGLE));
    record.setValue("MaxEncode",datarecord.getField(MFieldGlobal::MAXENCODE));
    record.setValue("Gas",datarecord.getField(MFieldGlobal::GAS));
    record.setValue("Brake",datarecord.getField(MFieldGlobal::BRAKE));
    record.setValue("Speed",datarecord.getField(MFieldGlobal::SPEED));
    record.setValue("RotaSpeed",datarecord.getField(MFieldGlobal::ROTASPEED));
    record.setValue("FuelConsumtion",datarecord.getField(MFieldGlobal::FUELCONSUMTION));
    record.setValue("LimitSpeed",datarecord.getField(MFieldGlobal::LIMITSPEED));
    record.setValue("Value1",datarecord.getField(MFieldGlobal::VALUE1));
    record.setValue("Value2",datarecord.getField(MFieldGlobal::VALUE2));
    record.setValue("ONOFF",datarecord.getField(MFieldGlobal::ONOFF));
    record.setValue("Value3",datarecord.getField(MFieldGlobal::VALUE3));
    model->insertRecord(-1,record);
    if(model->lastError().isValid()) qDebug()<<model->lastError().text();
}
void DbManager::insertData(int id, MRecord datarecord, int carNumber)
{
    QSqlTableModel* model=new QSqlTableModel;
    model->setTable(QString("Car%1Status").arg(carNumber));
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    //    QVariantList list=datarecord.getFields();
    //    if (fieldCount!=list.count()+1) qDebug()<<"Invalid data.Please Check!";
    QSqlRecord record=model->record();
    record.setValue("Time",MStartTime.addMSecs(id*1000/MFreq));

    record.setValue("Longitude",datarecord.getField(MFieldGlobal::LONGITUDE));
    record.setValue("Latitude",datarecord.getField(MFieldGlobal::LATITUDE));
    record.setValue("SteerAngle",datarecord.getField(MFieldGlobal::STEERANGLE));
    record.setValue("MaxEncode",datarecord.getField(MFieldGlobal::MAXENCODE));
    record.setValue("Gas",datarecord.getField(MFieldGlobal::GAS));
    record.setValue("Brake",datarecord.getField(MFieldGlobal::BRAKE));
    record.setValue("Speed",datarecord.getField(MFieldGlobal::SPEED));
    record.setValue("RotaSpeed",datarecord.getField(MFieldGlobal::ROTASPEED));
    record.setValue("FuelConsumtion",datarecord.getField(MFieldGlobal::FUELCONSUMTION));
    record.setValue("LimitSpeed",datarecord.getField(MFieldGlobal::LIMITSPEED));
    record.setValue("ONOFF",datarecord.getField(MFieldGlobal::ONOFF));
    record.setValue("Value1",datarecord.getField(MFieldGlobal::VALUE1));
    record.setValue("Value2",datarecord.getField(MFieldGlobal::VALUE2));
    record.setValue("Value3",datarecord.getField(MFieldGlobal::VALUE3));
    model->insertRecord(id+1,record);
}
void DbManager::close()
{
    db.close();
}
void DbManager::open(QString filePath)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filePath);//以后改为具体路径和名称
    if (!db.open()) qDebug()<<db.lastError().text();
}


