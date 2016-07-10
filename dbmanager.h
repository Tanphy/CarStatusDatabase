#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QString>
#include <QVariant>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlRecord>
#include <datamanager.h>
#include <QTime>
#include <mrecord.h>
class DbManager
{
public:
    DbManager();
    ~DbManager();
    DbManager(QTime startTime,int freq, QString filename,int carCount);//根据汽车数目和路径初始化数据库
    void append(MRecord datarecord,int carNumber);//添加纪录
    void insertData(int id, MRecord datarecord, int carNumber);
    void open(QString filePath);//根据文件路径打开数据库
    void close();
    QSqlTableModel *getDataModel(int carNumber);//获取车辆数据model
private:
    QSqlDatabase db;
    QTime MStartTime;
    int MFreq;
    int fieldCount;//列数
};

#endif // DBMANAGER_H
