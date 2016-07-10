#include <QMap>
#include <QString>
#include <QDebug>
class MFieldGlobal
{
public:
    MFieldGlobal()
    {
        map[TIME]=QString("Time");
        map[LONGITUDE]=QString("Longitude");
        map[LATITUDE]=QString("Latitude");
        map[STEERANGLE]=QString("SteerAngle");
        map[MAXENCODE]=QString("MaxEncode");
        map[GAS]=QString("Gas");
        map[BRAKE]=QString("Brake");
        map[SPEED]=QString("Speed");
        map[ROTASPEED]=QString("RotaSpeed");
        map[FUELCONSUMTION]=QString("FuelConsumtion");
        map[LIMITSPEED]=QString("LimitSpeed");
        map[VALUE1]=QString("Value1");
        map[VALUE2]=QString("Value2");
        map[ONOFF]=QString("OnOff");
        map[VALUE3]=QString("Value3");
    }
    //Value1、2、3为预留位
    enum
    {
        TIME=-1,LONGITUDE=0,LATITUDE,STEERANGLE,MAXENCODE,GAS,BRAKE,SPEED,ROTASPEED,FUELCONSUMTION,LIMITSPEED,VALUE1,VALUE2,VALUE3,ONOFF
    };
    QString getValue(int field)
    {
        return map[field];
    }
private:
    QMap<int,QString> map;
};
class MOnOffGlobal
{
 public:
    MOnOffGlobal()
    {
//        map[QString("Brake")]=BRAKE;
//        map[QString("Belt")]=BELT;
//        map[QString("Engine")]=ENGINE;
//        map[QString("Geer_P")]=GEER_P;
//        map[QString("Geer_N")]=GEER_N;
//        map[QString("Geer_D")]=GEER_D;
//        map[QString("Geer_R")]=GEER_R;
//        map[QString("Geer_Plus")]=GEER_PLUS;
//        map[QString("Geer_Decre")]=GEER_DECRE;
//        map[QString("Geer_First")]=GEER_FIRST;
//        map[QString("Geer_Second")]=GEER_SECOND;
//        map[QString("Geer_Third")]=GEER_THIRD;
//        map[QString("Geer_Fourth")]=GEER_FOURTH;
//        map[QString("Geer_Fifth")]=GEER_FIFTH;
//        map[QString("Light_Left")]=LIGHT_LEFT;
//        map[QString("Light_Right")]=LIGHT_RIGHT;
//        map[QString("Light_Low")]=LIGHT_LOW;
//        map[BRAKE]=QString("Brake");
//        map[BELT]=QString("Belt");
//        map[ENGINE]=QString("Engine");
//        map[GEER_P]=QString("Geer_P");
//        map[GEER_N]=QString("Geer_N");
//        map[GEER_D]=QString("Geer_D");
//        map[GEER_R]=QString("Geer_R");
//        map[GEER_PLUS]=QString("Geer_Plus");
//        map[GEER_DECRE]=QString("Geer_Decre");
//        map[GEER_FIRST]=QString("Geer_First");
//        map[GEER_SECOND]=QString("Geer_Second");
//        map[GEER_THIRD]=QString("Geer_Third");
//        map[GEER_FOURTH]=QString("Geer_Fourth");
//        map[GEER_FIFTH]=QString("Geer_Fifth");
//        map[LIGHT_LEFT]=QString("Light_Left");
//        map[LIGHT_RIGHT]=QString("Light_Right");
//        map[LIGHT_LOW]=QString("Light_Low");
//        map[LIGHT_HIGH]=QString("Light_High");
//        map[LIGHT_HIGHLOCK]=QString("Light_HighLock");
//        map[LIGHT_BRAKE]=QString("Light_Brake");
//        map[LIGHT_FOG]=QString("Light_Fog");
//        map[LIGHT_BROKEN]=QString("Light_Broken");
    }
    enum
    {
       GEER_P,GEER_N,GEER_D,GEER_R,GEER_UP,GEER_DOWN,VALUE1,VALUE2,GEER_1,GEER_2,GEER_3,GEER_4,GEER_5,GEER_r,VALUE3,VALUE4,LAMP_LEFT,
        LAMP_RIGHT,LAMP_LOW_BEAM,LAMP_HIGH_BEAM,LAMP_HIGH_BEAM_LOCK,LAMP_BRAKE,LIGHT_FOG,LIGHT_FAULT,HAND_BRAKE,SEAT_BELT,ENGINE_START
    };
//    QString getValue(int field)
//    {
//        return map[field];
//    }
//private:
//    QMap<int,QString> map;
};
//class GEER
//{
//public:
//    enum
//    {
//        P=13,N,D,R,PLUS,DECRE,FIRST,SECOND,THIRD,FOURTH,FIFTH
//    };
//};
//class LIGHT
//{
//public:
//    enum
//    {
//        LEFT=24,RIGHT,LOW,HIGH,HIGHLOCK,BRAKE,FOG,BROKEN
//    };
//};
