#include "mrecord.h"
#include "mfieldglobal.h"
MRecord::MRecord()
{
    Longitude=-1.0;
    Latitude=-1.0;
    SteerAngel=-1.0;
    MaxEncode=-1.0;
    Gas=-1.0;
    Brake=-1.0;
    Speed=-1.0;
    RotaSpeed=-1.0;
    FuelConsumtion=-1.0;
    LimitSpeed=-1.0;
    ONOFF=-1;
    Value1=-1.0;
    Value2=-1.0;
    Value3=-1;
}
void MRecord::setField(int field, QVariant value)
{
    switch (field) {
    case MFieldGlobal::BRAKE:
        Brake=value.toFloat();
        break;
    case MFieldGlobal::FUELCONSUMTION:
        FuelConsumtion=value.toFloat();
        break;
    case MFieldGlobal::GAS:
        Gas=value.toFloat();
        break;
    case MFieldGlobal::LATITUDE:
        Latitude=value.toDouble();
        break;
    case MFieldGlobal::LIMITSPEED:
        LimitSpeed=value.toFloat();
        break;
    case MFieldGlobal::LONGITUDE:
        Longitude=value.toDouble();
        break;
    case MFieldGlobal::MAXENCODE:
        MaxEncode=value.toFloat();
        break;
    case MFieldGlobal::ONOFF:
        ONOFF=value.toInt();
        break;
    case MFieldGlobal::ROTASPEED:
        RotaSpeed=value.toFloat();
        break;
    case MFieldGlobal::SPEED:
        Speed=value.toFloat();
        break;
    case MFieldGlobal::STEERANGLE:
        SteerAngel=value.toFloat();
        break;
    case MFieldGlobal::VALUE1:
        Value1=value.toFloat();
        break;
    case MFieldGlobal::VALUE2:
        Value2=value.toFloat();
        break;
    case MFieldGlobal::VALUE3:
        Value3=value.toInt();
        break;
    default:
        qDebug()<<"Value invalid in MRecord::setField!";
        break;
    }
}
void MRecord::setFields(QVariantList list)
{
    for (int i=MFieldGlobal::LONGITUDE;i<=MFieldGlobal::VALUE3;i++)
    {
        switch (i) {
        case MFieldGlobal::BRAKE:
            Brake=list[i].toFloat();
            break;
        case MFieldGlobal::FUELCONSUMTION:
            FuelConsumtion=list[i].toFloat();
            break;
        case MFieldGlobal::GAS:
            Gas=list[i].toFloat();
            break;
        case MFieldGlobal::LATITUDE:
            Latitude=list[i].toDouble();
            break;
        case MFieldGlobal::LIMITSPEED:
            LimitSpeed=list[i].toFloat();
            break;
        case MFieldGlobal::LONGITUDE:
            Longitude=list[i].toDouble();
            break;
        case MFieldGlobal::MAXENCODE:
            MaxEncode=list[i].toFloat();
            break;
        case MFieldGlobal::ONOFF:
            ONOFF=list[i].toInt();
            break;
        case MFieldGlobal::ROTASPEED:
            RotaSpeed=list[i].toFloat();
            break;
        case MFieldGlobal::SPEED:
            Speed=list[i].toFloat();
            break;
        case MFieldGlobal::STEERANGLE:
            SteerAngel=list[i].toFloat();
            break;
        case MFieldGlobal::VALUE1:
            Value1=list[i].toFloat();
            break;
        case MFieldGlobal::VALUE2:
            Value2=list[i].toFloat();
            break;
        case MFieldGlobal::VALUE3:
            Value3=list[i].toInt();
            break;
        default:
            qDebug()<<"Value invalid in MRecord::setFields!";
            break;
        }
    }
}
QVariant MRecord::getField(int field)
{
    QVariant value;
    switch (field) {
    case MFieldGlobal::BRAKE:
        value=Brake;
        break;
    case MFieldGlobal::FUELCONSUMTION:
        value=FuelConsumtion;
        break;
    case MFieldGlobal::GAS:
        value=Gas;
        break;
    case MFieldGlobal::LATITUDE:
        value=Latitude;
        break;
    case MFieldGlobal::LIMITSPEED:
        value=LimitSpeed;
        break;
    case MFieldGlobal::LONGITUDE:
        value=Longitude;
        break;
    case MFieldGlobal::MAXENCODE:
        value=MaxEncode;
        break;
    case MFieldGlobal::ONOFF:
        value=ONOFF;
        break;
    case MFieldGlobal::ROTASPEED:
        value=RotaSpeed;
        break;
    case MFieldGlobal::SPEED:
        value=Speed;
        break;
    case MFieldGlobal::STEERANGLE:
        value=SteerAngel;
        break;
    case MFieldGlobal::VALUE1:
        value=Value1;
        break;
    case MFieldGlobal::VALUE2:
        value=Value2;
        break;
    case MFieldGlobal::VALUE3:
        value=Value3;
        break;
    default:
        value=-1.0;
        qDebug()<<"Invalid Value int MRecord::getField!";
        break;
    }
    return value;
}
QVariantList MRecord::getFields()
{
    QVariantList dataList;
    for (int i=MFieldGlobal::LONGITUDE;i<=MFieldGlobal::VALUE3;i++)
    {
        switch (i) {
        case MFieldGlobal::BRAKE:
            dataList.append(Brake);
            break;
        case MFieldGlobal::FUELCONSUMTION:
            dataList.append(FuelConsumtion);
            break;
        case MFieldGlobal::GAS:
            dataList.append(Gas);
            break;
        case MFieldGlobal::LATITUDE:
            dataList.append(Latitude);
            break;
        case MFieldGlobal::LIMITSPEED:
            dataList.append(LimitSpeed);
            break;
        case MFieldGlobal::LONGITUDE:
            dataList.append(Longitude);
            break;
        case MFieldGlobal::MAXENCODE:
            dataList.append(MaxEncode);
            break;
        case MFieldGlobal::ONOFF:
            dataList.append(ONOFF);
            break;
        case MFieldGlobal::ROTASPEED:
            dataList.append(RotaSpeed);
            break;
        case MFieldGlobal::SPEED:
            dataList.append(Speed);
            break;
        case MFieldGlobal::STEERANGLE:
            dataList.append(SteerAngel);
            break;
        case MFieldGlobal::VALUE1:
            dataList.append(Value1);
            break;
        case MFieldGlobal::VALUE2:
            dataList.append(Value2);
            break;
        case MFieldGlobal::VALUE3:
            dataList.append(Value3);
            break;
        }
    }
    return dataList;
}
void MRecord::reset()
{
    Longitude=-1.0;
    Latitude=-1.0;
    SteerAngel=-1.0;
    MaxEncode=-1.0;
    Gas=-1.0;
    Brake=-1.0;
    Speed=-1.0;
    RotaSpeed=-1.0;
    FuelConsumtion=-1.0;
    LimitSpeed=-1.0;
    ONOFF=-1;
    Value1=-1.0;
    Value2=-1.0;
    Value3=-1;
}
