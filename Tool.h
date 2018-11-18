#pragma once
#include <vector>
// ����HALCONͷ�ļ�
#ifndef __APPLE__
#else
#  ifndef HC_LARGE_IMAGES
#    include <HALCONCpp/HalconCpp.h>
#  else
#    include <HALCONCppxl/HalconCpp.h>
#  endif
#endif // __APPLE__
// ����HALCON�����ռ�

#ifdef _USRDLL
#define TOOLAPI	extern "C" __declspec(dllexport)
#else
#define TOOLAPI	extern "C" __declspec(dllimport)
#endif

#define NODETYPE_NONE	0
#define NODETYPE_INT	1
#define NODETYPE_INT64	2
#define NODETYPE_DOUBLE 3
#define NODETYPE_CHAR	4
#define NODETYPE_POINT	5
#define NODETYPE_LINE	6
#define NODETYPE_CIRCLE 7
#define NODETYPE_IMAGE	8
#define NODETYPE_PIMAGE	9
#define NODETYPE_OFFSET	10

typedef struct tagPointParam
{
	double m_dbPointX;//��X����
	double m_dbPointY;//��Y����
	double m_dbPointZ;//��Y����
	double m_dbPointA;//��Y����
} PointParam, *PPointParam;

typedef struct tagLineParam
{
	double m_dbStartPointX;//�����X���� 
	double m_dbStartPointY; //�����Y����
	double m_dbEndPointX; //���յ�X����
	double m_dbEndPointY; //���յ�Y����
} LineParam, *PLineParam;

typedef struct tagCircleParam
{
	double m_dbCenterX;//Բ��X����
	double m_dbCenterY;//Բ��Y����
	double m_dbRadius;//Բ�İ뾶
} CircleParam, *PCircleParam;


typedef struct tagImageParam
{
	int m_nWidth;//ͼƬ��
	int m_nHeight;//ͼƬ��
	int m_nChannel;//ͼƬͨ����
	int m_nSize;//m_pDataָ������ݴ�С��byte��
	int m_nPtrType;//ָ������0=byte* ;1=HObject*
	void* m_pData;//ͼƬ����
} ImageParam, *PImageParam;



typedef struct tagOffsetParam
{
	double m_dbOffSetX;//ƫ��X
	double m_dbOffSetY;//ƫ��Y
	double m_dbOffSetA;//ƫ�ƽǶ�
	double m_dbCenterX;//��ת����X
	double m_dbCenterY;//��ת����Y
	double m_dbR;//ģ���ֵ
	BOOL m_bOK;//ƥ���Ƿ�ɹ�
	tagOffsetParam()
	{
		m_dbOffSetX = 0;
		m_dbOffSetY = 0;
		m_dbOffSetA = 0;
		m_dbCenterX = 0;
		m_dbCenterY = 0;
		m_dbR = 0;
		m_bOK = FALSE;
	}
} OffsetParam, *POffsetParam;


typedef struct GetMatchParam
{
	CPrImage cprImage;
	CString  str_ImageName;
	CShapeModelList	m_Models;
	CString	 strModel[10];	  //ģ������
	CString	 strResult[20][6];   //���ҽ��
	COverlay m_Overlay;		 //���ǲ�
	COverlay m_Results;		 //�����

	int      iMaxCount;		//��������
	int		 iMinScore;		//��С����1~100
	int		 iMinAngle;		//��С�Ƕ�-180~180
	int		 iMaxAngle;		//���Ƕ�-180~180
	int		 iMinScale;		//��С����50~200
	int		 iMaxScale;		//������50~200
	int		 iMaxOverlap;	//����ص��� 
	int		 iMaxSpeed;		//�����ٶ� 1~10
	int		 iAccuracy;		//��λ���� 1~10
	int		 iPolarity;		//ƥ�伫�� 1~2   0���� 1��ת  2 ����
	GetMatchParam()
	{
		CString  str_ImageName = _T("<NULL>");
		cprImage.Clear();
		iMaxCount = 1;
		iMinScore = 80;
		iMinAngle = 0;
		iMaxAngle = 90;
		iMinScale = 100;
		iMaxScale = 100;
		iMaxOverlap = 20;
		iMaxSpeed = 6;
		iAccuracy = 6;
		iPolarity = 0;
	}
}GetMatchParam,*PGetMatchParamParam;


typedef int (WINAPI *fHIDBCreatesLink)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, int nType);
typedef int (WINAPI *fHIDBDeleteLink)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName);
typedef int (WINAPI *fHIDBSelectLink)(TCHAR* pDocName, int* nNodeID, TCHAR* pNodeName, TCHAR* pParaName, int* pnType, int* nIndex);
typedef int (WINAPI *fHIDBSaveInt32)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, int* pValue, int nParaCnt, int nIndex);
typedef int (WINAPI *fHIDBGetInt32)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, int** pValue, int* pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBSaveInt64)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, __int64* pValue, int nParaCnt, int nIndex);
typedef int (WINAPI *fHIDBGetInt64)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, __int64** pValue, int* pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBSaveDouble)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, double* pValue, int nParaCnt, int nIndex);
typedef int (WINAPI *fHIDBGetDouble)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, double** pValue, int* pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBSaveChar)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, TCHAR* pValue, int nParaCnt, int nIndex);
typedef int (WINAPI *fHIDBGetChar)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, TCHAR** pValue, int* pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBSavePointcoord)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, PPointParam pPointValue, int nParaCnt, int nIndex);
typedef int (WINAPI *fHIDBGetPointcoord)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, PPointParam* pPointValue, int *pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBSaveLinecoord)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, PLineParam pLineValue, int nParaCnt, int nIndex);
typedef int (WINAPI *fHIDBGetLinecoord)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, PLineParam* pLineValue, int *pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBSaveCirclecoord)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, PCircleParam pCircleValu, int nParaCnt, int nIndex);
typedef int (WINAPI *fHIDBGetCirclecoord)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, PCircleParam* pCircleValue, int *pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBGetImage)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, PImageParam* pImageValue, int *pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBSaveImage)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, PImageParam pImageValue, int nParaCnt, int nIndex);
typedef int (WINAPI *fHIDBGetImagePointer)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, PImageParam* pImageValue, int *pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBSaveImagePointer)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, PImageParam pImageValue, int nParaCnt, int nIndex);
typedef int (WINAPI *fHIDBSaveOffsetData)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, POffsetParam pOffsetValue, int pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBGetOffsetData)(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, TCHAR* pParaName, POffsetParam* pOffsetValue, int* pnParaCnt, int nIndex);
typedef int (WINAPI *fHIDBDeleteBuf)(void* pBuf);


TOOLAPI int GetCallFun(int nType, void **pParam);
TOOLAPI int SetCallback(int nType, void *pParam);

CDialog* ShowPropertyDialog(CWnd* pParent, void * pToolParam);
void GetToolName(TCHAR* szName);
void GetToolType(TCHAR* szType);
void Save(CArchive& ar, void * pToolParam);
void Load(CArchive& ar, void * pToolParam);
int Do(void * pControlPara);
int CreateTool(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, void ** pToolParam);
int DeleteTool(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, void * pToolParam);
void Copy(void * pDst, void * pSrc);

void WriteString(CArchive& ar, CString str);
void WriteDouble(CArchive& ar, double dbNum);
void WriteInt(CArchive& ar, BOOL nNum);
void WriteBool(CArchive& ar, BOOL nNum);


extern fHIDBCreatesLink			HIDBCreatesLink;
extern fHIDBDeleteLink			HIDBDeleteLink;
extern fHIDBSelectLink			HIDBSelectLink;
extern fHIDBSaveInt32			HIDBSaveInt32;
extern fHIDBGetInt32			HIDBGetInt32;
extern fHIDBSaveInt64			HIDBSaveInt64;
extern fHIDBGetInt64			HIDBGetInt64;
extern fHIDBSaveDouble			HIDBSaveDouble;
extern fHIDBGetDouble			HIDBGetDouble;
extern fHIDBSaveChar			HIDBSaveChar;
extern fHIDBGetChar				HIDBGetChar;
extern fHIDBGetPointcoord		HIDBGetPointcoord;
extern fHIDBGetLinecoord		HIDBGetLinecoord;
extern fHIDBGetCirclecoord		HIDBGetCirclecoord;
extern fHIDBSavePointcoord		HIDBSavePointcoord;
extern fHIDBSaveLinecoord		HIDBSaveLinecoord;
extern fHIDBSaveCirclecoord		HIDBSaveCirclecoord;
extern fHIDBGetImage			HIDBGetImage;
extern fHIDBSaveImage			HIDBSaveImage;
extern fHIDBGetImagePointer		HIDBGetImagePointer;
extern fHIDBSaveImagePointer	HIDBSaveImagePointer;
extern fHIDBSaveOffsetData		HIDBSaveOffsetData;
extern fHIDBGetOffsetData		HIDBGetOffsetData;
extern fHIDBDeleteBuf			HIDBDeleteBuf;