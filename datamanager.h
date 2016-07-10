#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QBitArray>
#include <bitset>
using namespace std;
class DataManager
{
public:
    void setModel(QSqlTableModel* model);//设定要操作的model
    QSqlTableModel* selectData(int field,QVariant min,QVariant max);//范围选取
    QSqlTableModel* selectData(int field, QVariant value);//定值选取
    QSqlTableModel* selectOnOff(int field,bool onoff);//开关量选取
//    QVariant getFieldData(int field);
    QVector<QVariantList> getData();//取出model中B所有数据，一行存为一个QVriantlist，开关量存为QitArray放入QVariantList中
    QSqlTableModel*getModel();//返回model指针
    QVector<QBitArray> getOnOff();//取出model中所有二进制开关量
private:
    QSqlTableModel* MModel;
    QString carTable;//MModel对应的tableName
};

#endif // DATAMANAGER_H
