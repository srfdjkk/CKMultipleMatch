#pragma once
#include "Tool.h"
#include "CKMultipleDemoMatchDlg.h"


//�������ӽڵ�ṹ��
typedef struct LinkParam {
	TCHAR	szDocName[MAX_PATH];
	int		nNodeID;
	TCHAR	szNodeName[MAX_PATH];
	TCHAR	szParaName[MAX_PATH];//�������֣����飩
	int		nType;				//�������ͣ������ڲ�����ֵ���ͣ�
	int		nIndex;				//����ĽǱ���
}stLinkParam,*pSTLinkParam;



class CKMultipleDemoMatch
{
public:
	CKMultipleDemoMatch(TCHAR * pDocName, int nNodeID, TCHAR * pNodeName);
	~CKMultipleDemoMatch();
	//��д���캯��
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

