#include "qreadini.h"

QReadIni*QReadIni::instance = NULL;

QReadIni *QReadIni::getInstance()
{
    if(instance == NULL)
    {
        instance = new QReadIni();
    }
    return instance;
}

QReadIni::QReadIni()
{
    this->readIni();
}

void QReadIni::readIni()
{
    QSettings * configIniRead = new QSettings("config.ini",QSettings::IniFormat);//初始化读取Ini文件对象
    iniConfig.ip = configIniRead->value("conn/ip").toString();                          //IP地址
    iniConfig.port = configIniRead->value("conn/port").toString();                      //端口
    iniConfig.dataBaseVersion = configIniRead->value("conn/databaseversion").toString();//数据库版本
    iniConfig.dataBaseName = configIniRead->value("conn/databasename").toString();      //数据库名称
    iniConfig.userName = configIniRead->value("conn/username").toString();              //用户名
    iniConfig.passWord = configIniRead->value("conn/password").toString();              //密码

    delete configIniRead;
}

const IniConfig &QReadIni::getIniConfig()
{
    return iniConfig;
}


