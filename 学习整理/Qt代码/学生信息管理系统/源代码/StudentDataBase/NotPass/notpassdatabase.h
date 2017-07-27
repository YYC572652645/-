﻿
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QtXml>
#include<QFile>
#include<QIODevice>
#include<QDomNodeList>
typedef struct dataNotPass
{
    QString name;          //姓名
    QString sex;           //性别
    QString number;        //学号
    QString profess;       //专业班级
    QString notPassClass;  //挂科名称
    QString notPassGrade;  //挂科学分
    QString notPassPro;    //挂科性质
    QString notPassState;  //挂科状态
}dataNotPass;




class NotPassDataBase
{
public:
    /************构造函数*************/
    NotPassDataBase();


    /************连接数据库*************/
    bool dataCnn();


    /************插入数据*************/
    bool insertData();


    /************查询数据*************/
    int selectData(QString studentNumber,QString studentName,QString studentClass);


    /************删除数据*************/
    bool deleteData( );


    /************读取xml文件**********/
    bool readXML();

public:
    QString number;        //学号
    QString notPassClass;  //挂科名称
    QString notPassGrade;  //挂科学分
    QString notPassPro;    //挂科性质
    QString notPassState;  //挂科状态

    dataNotPass*NotPassMessage;
private:
    QString dataBaseName;          //数据库名称
    QString dataBaseVersion;       //数据库版本
    QString ip;                    //ip地址
    QString port;                  //端口
    QString userName;              //用户名
    QString passWord;              //密码
    QSqlDatabase db;               //定义数据库对象
};

