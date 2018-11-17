#pragma once
#include "Tool.h"
#include "CKMultipleDemoMatchDlg.h"


//创建链接节点结构体
typedef struct LinkParam {
	TCHAR	szDocName[MAX_PATH];
	int		nNodeID;
	TCHAR	szNodeName[MAX_PATH];
	TCHAR	szParaName[MAX_PATH];//变量名字（数组）
	int		nType;				//变量类型（数组内部的数值类型）
	int		nIndex;				//数组的角标编号
}stLinkParam,*pSTLinkParam;



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
	void SaveData();
	void ReadpCharA(CArchive &ar, TCHAR* pchar);
	void ReadDouble(CArchive &ar, double& dbVal);
	void WritepCharA(CArchive &ar, TCHAR* pchar);
	void WriteDouble(CArchive &ar, double dbVal);
	void SetImageParamByCkImage(ImageParam* pImageParam, CPrImage* pho_Img);

	CPrImage	m_Image;
	stLinkParam m_stLinkParam;
	GetMatchParam m_GetMatchParam;
	CShapeMatch	*m_Match;
	CKMultipleDemoMatchDlg dlg;
	CString	 strResult[6];

};

