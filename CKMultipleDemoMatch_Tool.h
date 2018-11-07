#pragma once
#include "Tool.h"
#include "CKMultipleDemoMatchDlg.h"


//������Ϣ�ṹ��
typedef struct stt_Param {
	TCHAR	szDocName[MAX_PATH];
	int		nNodeID;
	TCHAR	szNodeName[MAX_PATH];
	TCHAR	szParaName[MAX_PATH];//�������֣����飩
	int		nType;				//�������ͣ������ڲ�����ֵ���ͣ�
	int		nIndex;				//����ĽǱ���
}STTP,*PSTTP;



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

