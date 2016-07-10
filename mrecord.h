#ifndef MRECORD_H
#define MRECORD_H
#include <QVariant>
#include <QTime>
class MRecord
{
public:
    MRecord();
    void setField(int field,QVariant value);
    void setFields(QVariantList list);
    QVariant getField(int field);
    void reset();
    QVariantList getFields();
private:
    double Longitude;
    double Latitude;
    float SteerAngel;
    float MaxEncode;
    float Gas;
    float Brake;
    float Speed;
    float RotaSpeed;
    float FuelConsumtion;
    float LimitSpeed;
    int ONOFF;
    float Value1;
    float Value2;
    int Value3;
};
#endif // RECORD_H
