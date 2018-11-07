#pragma once
#include "Tool.h"
#include "CKMultipleDemoMatchDlg.h"


//参数信息结构体
typedef struct stt_Param {
	TCHAR	szDocName[MAX_PATH];
	int		nNodeID;
	TCHAR	szNodeName[MAX_PATH];
	TCHAR	szParaName[MAX_PATH];//变量名字（数组）
	int		nType;				//变量类型（数组内部的数值类型）
	int		nIndex;				//数组的角标编号
}STTP,*PSTTP;



class CKMultipleDemoMatch
{
public:
	CKMultipleDemoMatch(TCHAR * pDocName, int nNodeID, TCHAR * pNodeName);
	~CKMultipleDemoMatch();
	//重写构造函数
	void Save(CArchive &ar);
	void Load(CArchive &ar);
	void ShowPropertyDialog();
	void Do();
	void DoCreate();
	void ReadpCharA(CArchive &ar, TCHAR* pchar);
	void ReadDouble(CArchive &ar, double& dbVal);
	void WritepCharA(CArchive &ar, TCHAR* pchar);
	void WriteDouble(CArchive &ar, double dbVal);
	
	void SetImageParamByCkImage(ImageParam* pImageParam, CPrImage* pho_Img);
	void Hobject2PImage(ImageParam* pHImage, ImageParam* pCImage);

	BYTE *m_pBuffer;
	CPrImage	m_Image;
	CString m_strImgFolderPathT;
	std::vector<CString> m_VectImgFileNameT;

	STTP m_Toolparam;

	PImageParam m_pCImage;
	GetMatchParam m_GetMatchParam;

	PImageParam m_imagepinT;
	//CKVision::CPrImage m_ckImage;
	int m_NOdomodel;
	int m_ImageSelect;
};

