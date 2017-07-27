﻿#include "comparethread.h"
#include "DetectAlgorithm.h"
#include <QDebug>
#pragma comment(lib,"DetectAlgorithm.lib")

/************************    模板图         ***************************************/
void CompareThread::setTemplateImage(const QImage &value)
{
    templateImage = value;
}

/************************    目标图         ***************************************/
void CompareThread::setCompareImage(const QImage &value)
{
    compareImage = value;
}

/************************    检验类型         ***************************************/
void CompareThread::setContourType(int value)
{
    contourType = value;
}

/************************    数据点         ***************************************/
void CompareThread::setPointStr(const std::string &value)
{
    pointStr = value;
}

/************************    线程函数         ***************************************/
void CompareThread::run()
{
    getInspectResultData();
}

/************************    获取检测结果    **************************************/
void CompareThread::getInspectResultData()
{
    if (templateImage.isNull() || compareImage.isNull()) return;

    mutex.lock();                                             //加互斥锁
    DAMat dmDetect;                                           //模板图像结构体
    DAMat dmTemplate;                                         //待检测图像结构体
    char* pData = NULL;                                       //异常坐标位置数据
    int pDataCount = 0;                                       //异常数据个数
    char* pTransformData = NULL;                              //模板图像 检测图像三点对应位置数据
    int pTransformDataCount = 0;                              //模板图像数据个数
    int densityDiffThr = 40;                                  //亮度差值阈值
    int noiseAreaDiffThr = 10;                                //污点面积阈值

    //模板图像数据
    dmDetect.width = compareImage.width();                    //宽
    dmDetect.height = compareImage.height();                  //高
    dmDetect.bits = compareImage.bits();                      //字节
    dmDetect.bytesPerLine = compareImage.bytesPerLine();      //行字节数

    //待检测图像数据
    dmTemplate.width = templateImage.width();                  //宽
    dmTemplate.height = templateImage.height();                //高
    dmTemplate.bits = templateImage.bits();                    //字节
    dmTemplate.bytesPerLine = templateImage.bytesPerLine();    //行字节数

    //目标检测算法
    int flage = DetectFlaw(dmTemplate, dmDetect, &pData, pDataCount, densityDiffThr, noiseAreaDiffThr, (char*)pointStr.data(),
                           pointStr.size(), contourType, &pTransformData, pTransformDataCount);

    QString data(pData);                               //转化为QString类型
    QString transformData(pTransformData);             //转化为QString类型

    emit sendString(flage, data, transformData);       //发送数据给主线程
    mutex.unlock();                                    //解锁
}

