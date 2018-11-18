#pragma once
#include <vector>
// 调用HALCON头文件
#ifndef __APPLE__
#else
#  ifndef HC_LARGE_IMAGES
#    include <HALCONCpp/HalconCpp.h>
#  else
#    include <HALCONCppxl/HalconCpp.h>
#  endif
#endif // __APPLE__
// 调用HALCON命名空间

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
	double m_dbPointX;//点X坐标
	double m_dbPointY;//点Y坐标
	double m_dbPointZ;//点Y坐标
	double m_dbPointA;//点Y坐标
} PointParam, *PPointParam;

typedef struct tagLineParam
{
	double m_dbStartPointX;//线起点X坐标 
	double m_dbStartPointY; //线起点Y坐标
	double m_dbEndPointX; //线终点X坐标
	double m_dbEndPointY; //线终点Y坐标
} LineParam, *PLineParam;

typedef struct tagCircleParam
{
	double m_dbCenterX;//圆心X坐标
	double m_dbCenterY;//圆心Y坐标
	double m_dbRadius;//圆的半径
} CircleParam, *PCircleParam;


typedef struct tagImageParam
{
	int m_nWidth;//图片宽
	int m_nHeight;//图片高
	int m_nChannel;//图片通道数
	int m_nSize;//m_pData指向的数据大小（byte）
	int m_nPtrType;//指针类型0=byte* ;1=HObject*
	void* m_pData;//图片数据
} ImageParam, *PImageParam;



typedef struct tagOffsetParam
{
	double m_dbOffSetX;//偏移X
	double m_dbOffSetY;//偏移Y
	double m_dbOffSetA;//偏移角度
	double m_dbCenterX;//旋转中心X
	double m_dbCenterY;//旋转中心Y
	double m_dbR;//模板分值
	BOOL m_bOK;//匹配是否成功
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
	CString	 strModel[10];	  //模板名字
	CString	 strResult[20][6];   //查找结果
	COverlay m_Overlay;		 //覆盖层
	COverlay m_Results;		 //结果层

	int      iMaxCount;		//搜索数量
	int		 iMinScore;		//最小分数1~100
	int		 iMinAngle;		//最小角度-180~180
	int		 iMaxAngle;		//最大角度-180~180
	int		 iMinScale;		//最小比例50~200
	int		 iMaxScale;		//最大比例50~200
	int		 iMaxOverlap;	//最大重叠数 
	int		 iMaxSpeed;		//搜索速度 1~10
	int		 iAccuracy;		//定位精度 1~10
	int		 iPolarity;		//匹配极性 1~2   0正常 1反转  2 任意
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