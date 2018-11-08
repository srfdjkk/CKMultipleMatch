#pragma once
#include "CKMultipleDemoMatch.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "Tool.h"
#include "CPAGE1.h"
#include "CPAGE2.h"
#include "CPAGE3.h"
#include "CPAGE4.h"
#include "CLearnDlg.h"
struct StatePara
{
	int svae_ReadType;

};

using namespace std;

// CKMultipleDemoMatchDlg �Ի���

typedef struct tagToolGetPicParam {
	TCHAR	szDocName[MAX_PATH];
	int		nNodeID;
	TCHAR	szNodeName[MAX_PATH];
	TCHAR	szParaName[MAX_PATH];//�������֣����飩
	int		nType;				//�������ͣ������ڲ�����ֵ���ͣ�
	int		nIndex;				//����ĽǱ���
}ToolGetPicParam, *pToolGetPicParam;


class CKMultipleDemoMatchDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CKMultipleDemoMatchDlg)

public:
	CKMultipleDemoMatchDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CKMultipleDemoMatchDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GETLOCALIMG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancelButton();
	afx_msg void OnBnClickedOKButton();

	CShapeModelList	m_Models;   

	CTabCtrl m_Tab;
	CPAGE1 m_page1;
	CPAGE2 m_page2;
	CPAGE3 m_page3;
	CPAGE4 m_page4;
	CLearnDlg m_learnDlg;
	CGdiView m_GdiView;
	CPrImage m_Image;
	COverlay m_Overlay;
	COverlay m_Results;

	CString	 strResult[6];


	//ѧϰģ������
	CGdiRect m_lRoi;

	//��������
	CGdiRect m_sRectROI;
	CGdiRotBox m_sRotBoxROI;
	CShapeMatch		m_Match;
	GetMatchParam m_GetMatchParam;
	int m_nSel;

	LARGE_INTEGER m_Frequency;
	LARGE_INTEGER m_BeginTime;
	LARGE_INTEGER m_EndTime;


	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	void CKMultipleDemoMatchDlg::EnumImage();
	afx_msg void OnBnClickedBTNSeatchModel();
	void AddStringLevel(CComboBox* m_CComboBox);
	void BeginTime();
	void EndTime();

};
