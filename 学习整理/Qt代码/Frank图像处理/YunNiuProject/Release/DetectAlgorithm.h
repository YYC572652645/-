#pragma once
#ifndef DetectAlgorithm_API
#define DetectAlgorithm_API  extern "C" __declspec(dllexport)
#endif

typedef void (*CallBackFun)(int step);

#ifndef UNICODE                    // UNICODE 2 need  define this
typedef  char     DATACHAR; 
#else
typedef  wchar_t  DATACHAR;
#endif

//��װQImage����
struct DAMat
{
	int height;
	int width;
	void* bits;
	int bytesPerLine;
};

//��λ��������
struct DAPoint 
{
	float x;
	float y;
};

//����ֵ�����Ϊ0������쳣��������ز���
//0.�ȶ�ͼ�񷵻��쳣λ��
//contourType �������� 
//0 ��ָ������ ģ��ͼ������Ϊͼ������ ���ͼ��Ϊͼ������
//1 ģ��ͼ��ָ������Σ�������4���ǵ��ʾ�� ���ͼ��Ϊͼ������
//2 ˫���Σ�ǰ2���ʾģ����ͼ�����Ȥ���򣬺�2���ʾ���ͼ�����Ȥ����
DetectAlgorithm_API int DetectFlaw(
	DAMat imgTemplate,//ģ��ͼ��
	DAMat imgDetect,//�����ͼ��
	char** pData,int& dataCount,//ȱ�ݽ�� ��һ��Ϊ��⵽��ƥ������ �ڶ���һ��ͼ����ȱ�ݸ������ڼ��ͼ���е�λ��
	float densityDiffThr,//���Ȳ�ֵ��ֵ ���Ϊ-1 ������Զ�ģʽ
	float noiseAreaDiffThr,//�۵������ֵ ���Ϊ-1 ������Զ�ģʽ
	char* pointStr,int pointStrCount,//�������ݼ����ݳ��� ��ʽΪx1,y1;x2,y2......
	int roiType,//����Ȥ��������
	//���ģ��ͼ�� ���ͼ���Ӧ�� ��ʽΪx1,y1;x2,y2;x3,y3|xx1,yy1;...... ��һ��������λΪģ��ͼ������ �ڶ�������Ϊ��⵽��Ŀ��ͼ������
	char** pTranformPts,int pTranformPtsCount,
	const CallBackFun opch=NULL,//�ص�������ַ
	char** pErrMsg=NULL);//������Ϣ��ʾ�ַ���