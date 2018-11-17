// GetLocalPictureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CKMultipleDemoMatch.h"
#include "CKMultipleDemoMatchDlg.h"
#include "afxdialogex.h"
#include <atlimage.h>
#include <gdiplus.h>
#include "ToolControl.h"

CKMultipleDemoMatchDlg* pCKMultipleDemoMatchDlg = NULL;
using namespace Gdiplus;


ULONG_PTR GdiplusToken;
GdiplusStartupInput gdiplusStartupInput;

IMPLEMENT_DYNAMIC(CKMultipleDemoMatchDlg, CDialogEx)

CKMultipleDemoMatchDlg::CKMultipleDemoMatchDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_GETLOCALIMG, pParent)

{
	pCKMultipleDemoMatchDlg = this;
}

CKMultipleDemoMatchDlg::~CKMultipleDemoMatchDlg()
{

}

void CKMultipleDemoMatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);



	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(CKMultipleDemoMatchDlg, CDialogEx)

	ON_WM_DESTROY()


	ON_BN_CLICKED(IDC_BUTTON2, &CKMultipleDemoMatchDlg::OnBnClickedCancelButton)
	ON_BN_CLICKED(IDC_BUTTON3, &CKMultipleDemoMatchDlg::OnBnClickedOKButton)

	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CKMultipleDemoMatchDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BTN_SEATCH, &CKMultipleDemoMatchDlg::OnBnClickedBTNSeatchModel)

END_MESSAGE_MAP()

BOOL CKMultipleDemoMatchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//ѡ���ʼ��
	m_Tab.InsertItem(0,_T("��������"));
	m_Tab.InsertItem(1,_T("��������"));
	m_Tab.InsertItem(2,_T("���ݽ��"));
	m_Tab.InsertItem(3,_T("��ʾͼ��"));

	//m_page1.Create(IDD_PAGE1, m_Tab.m_hWnd);
	m_page1.Create(IDD_PAGE1,GetDlgItem(IDC_TAB1));
	m_page2.Create(IDD_PAGE2,GetDlgItem(IDC_TAB1));
	m_page3.Create(IDD_PAGE3,GetDlgItem(IDC_TAB1));
	m_page4.Create(IDD_PAGE4,GetDlgItem(IDC_TAB1));
	m_learnDlg.Create(IDD_LEARN_DLG, GetDlgItem(IDC_TAB1));
	//���IDC_TABTEST�ͻ�����С 
	CRect rs;
	m_Tab.GetClientRect(&rs);
	//�����ӶԻ����ڸ������е�λ�� 
	rs.top = rs.top + 40;
	rs.left = rs.left + 10;
	rs.bottom = rs.bottom - 10;
	rs.right = rs.right - 10;

	//�����ӶԻ���ߴ粢�ƶ���ָ��λ�� 
	m_page1.MoveWindow(&rs);
	m_page2.MoveWindow(&rs);
	m_page3.MoveWindow(&rs);
	m_page4.MoveWindow(&rs);
	m_learnDlg.MoveWindow(&rs);
	//�ֱ��������غ���ʾ 
	m_page1.ShowWindow(true);
	m_page2.ShowWindow(false);
	m_page3.ShowWindow(false);
	m_page4.ShowWindow(false);
	m_learnDlg.ShowWindow(false);
	//����Ĭ�ϵ�ѡ� 
	m_Tab.SetCurSel(0);

	//��ʼ��Page1�����б�
	
	m_page1.m_combox_image.AddString(m_GetMatchParam.str_ImageName);
	m_page1.m_combox_image.SetCurSel(0);
	//��ʼ��ͼƬ�ؼ���
	CRect rect;
	GetDlgItem(IDC_PIC_RECT)->GetWindowRect(&rect);
	ScreenToClient(&rect);

	m_GdiView.Create(m_hWnd, rect);
	m_GdiView.SetBackColor(RGB(0, 0, 64));
	m_Image.Copy(m_GetMatchParam.CPrImage);
	m_GdiView.SetDisplayImage(&m_Image);
	m_GdiView.SetActiveOverlay(&m_Overlay);
	m_GdiView.SetStaticOverlay(&m_Results);

	m_Overlay.AddItem(&m_sRectROI);
	m_Overlay.AddItem(&m_sRotBoxROI);
	m_Overlay.AddItem(&m_lRoi);

	//ѧϰ����
	m_lRoi.left = 100;
	m_lRoi.top = 100;
	m_lRoi.right = 500;
	m_lRoi.bottom = 400;
	m_lRoi.SetPenColor(RGB(80, 200, 200));  //��ɫ
	m_lRoi.SetVisible(false);

	//�������γ�ʼ��
	m_sRectROI.left = 100;
	m_sRectROI.top = 100;
	m_sRectROI.right = 500;
	m_sRectROI.bottom = 400;
	m_sRectROI.SetPenColor(RGB(255, 0, 0));  
	m_sRectROI.SetVisible(false);

	//������ת�����ʼ��
	m_sRotBoxROI.center.x = 100;
	m_sRotBoxROI.center.y = 100;
	m_sRotBoxROI.width = 100;
	m_sRotBoxROI.height = 100;
	m_sRotBoxROI.angle = 60;
	m_sRotBoxROI.SetPenColor(RGB(255, 0, 0));
	m_sRotBoxROI.SetVisible(false);


	//��ʼ��page2����
	m_page2.m_MaxCount = m_GetMatchParam.iMaxCount;
	m_page2.m_iMinScore = m_GetMatchParam.iMinScore;
	m_page2.m_iMinAngle = m_GetMatchParam.iMinAngle;
	m_page2.m_iMaxAngle = m_GetMatchParam.iMaxAngle;
	m_page2.m_iMinScale = m_GetMatchParam.iMinScale;
	m_page2.m_iMaxScale = m_GetMatchParam.iMaxScale;
	m_page2.m_iMaxOverlap = m_GetMatchParam.iMaxOverlap;

	AddStringLevel(&m_page2.m_CCbox_Speed);
	AddStringLevel(&m_page2.m_CCbox_Accuracy);
	m_page2.m_CCbox_Polarity.InsertString(0,_T("����"));
	m_page2.m_CCbox_Polarity.InsertString(1,_T("��ת"));
	m_page2.m_CCbox_Polarity.InsertString(2,_T("����"));

	m_page2.m_iSpeed = m_GetMatchParam.iMaxSpeed;
	m_page2.m_iAccuracy = m_GetMatchParam.iAccuracy;
	m_page2.m_iPolarity = m_GetMatchParam.iPolarity;
	m_page2.m_iPolarity = 0;
	m_page2.UpdateData(FALSE);

	//��ʼ��page3����
	CRect ListRect;
	m_page3.m_ListCtrl.GetWindowRect(ListRect);
	m_page3.m_ListCtrl.SetExtendedStyle(m_page3.m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
	m_page3.m_ListCtrl.InsertColumn(0,_T("���"), LVCFMT_CENTER, ListRect.Width()/6,0);
	m_page3.m_ListCtrl.InsertColumn(1,_T("����"), LVCFMT_CENTER, ListRect.Width()/6,1);
	m_page3.m_ListCtrl.InsertColumn(2, _T("λ��X"), LVCFMT_CENTER, ListRect.Width()/6,2);
	m_page3.m_ListCtrl.InsertColumn(3, _T("λ��Y"), LVCFMT_CENTER, ListRect.Width()/6,3);
	m_page3.m_ListCtrl.InsertColumn(4, _T("�Ƕ�"),LVCFMT_CENTER, ListRect.Width()/6,4);
	m_page3.m_ListCtrl.InsertColumn(5, _T("����"), LVCFMT_CENTER, ListRect.Width()/6,5);

	m_GdiView.SetActiveOverlay(&m_Overlay);
	m_GdiView.SetStaticOverlay(&m_Results);




	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CKMultipleDemoMatchDlg::OnBnClickedCancelButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�ͷ������Դ
	CDialogEx::OnCancel();

}




void CKMultipleDemoMatchDlg::OnBnClickedOKButton()
{
	//HIDBSelectLink(cDocName, &iNodeID, cNodeName, cParamName, &iType, &iIndex);
	//�����������������������
	UpdateData();
	ModePara.iMaxCount = m_page2.m_MaxCount;
	ModePara.iMinScore = m_page2.m_iMinScore;
	ModePara.iMinAngle = m_page2.m_iMinAngle;
	ModePara.iMaxAngle = m_page2.m_iMaxAngle;
	ModePara.iMinScale = m_page2.m_iMinScale;
	ModePara.iMaxScale = m_page2.m_iMaxScale;
	ModePara.iMaxOverlap =  m_page2.m_iMaxOverlap;
	ModePara.iSpeed = m_page2.m_iSpeed;
	ModePara.iAccuracy = m_page2.m_iAccuracy;
	ModePara.iPolarity = m_page2.m_iPolarity;
	
	CDialogEx::OnOK();
}


void CKMultipleDemoMatchDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int CurSel = m_Tab.GetCurSel();
	switch (CurSel)
	{
	case 0:
		m_page1.ShowWindow(true);
		m_page2.ShowWindow(false);
		m_page3.ShowWindow(false);
		m_page4.ShowWindow(false);
		break;
	case 1:
		m_page1.ShowWindow(false);
		m_page2.ShowWindow(true);
		m_page3.ShowWindow(false);
		m_page4.ShowWindow(false);
		break;
	case 2:
		m_page1.ShowWindow(false);
		m_page2.ShowWindow(false);
		m_page3.ShowWindow(true);
		m_page4.ShowWindow(false);
		break;
	case 3:
		m_page1.ShowWindow(false);
		m_page2.ShowWindow(false);
		m_page3.ShowWindow(false);
		m_page4.ShowWindow(true);
	default:
		;
	}
	*pResult = 0;
}

void CKMultipleDemoMatchDlg::EnumImage()
{

}


/*****************************************************************
**FunctionName:	OnBnClickedBTNSeatchModel()
*Description:	���ִ�У�����ģ��
*parameter  :	��

*return		:	��
****************************************************************/
void CKMultipleDemoMatchDlg::OnBnClickedBTNSeatchModel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_page3.m_ListCtrl.DeleteAllItems();
	m_Match.SetMaxCount(m_page2.m_MaxCount);
	m_Match.SetMinScore(m_page2.m_iMinScore);
	m_Match.SetMinAngle(m_page2.m_iMinAngle);
	m_Match.SetMaxAngle(m_page2.m_iMaxAngle);
	m_Match.SetMinScale(m_page2.m_iMinScale);
	m_Match.SetMaxScale(m_page2.m_iMaxScale);
	m_Match.SetMaxOverlap(m_page2.m_iMaxOverlap);
	m_Match.SetMaxSpeed(m_page2.m_iSpeed);
	m_Match.SetAccuracy(m_page2.m_iAccuracy);
	m_Match.SetPolarity(m_page2.m_iPolarity);
	
	CString text;
	CModelContour templ;

	Overlay_DeleteAll(m_Results);

	//BeginTime();

	if (m_sRectROI.GetVisible())
	{
		m_Match.Execute(m_Image, m_Models, m_sRectROI);
	}
	else
	{
		m_Match.Execute(m_Image, m_Models, MaxROI);
	}

	//EndTime();
	SMatchData* data;
	int index = 0;
	for (int i = 0; i < m_Match.GetNumMatchs(); i++)
	{
		
		data = m_Match.GetMatchData(i);
		m_page3.UpdateData();
		if (m_page3.m_CheckNum.GetCheck() == 1 )		//�����������ޣ�����
			if (i > (m_page3.m_iNumUp - 1))
			{
				return;
			}
			
		if (m_page3.m_CheckX.GetCheck() == 1)	//λ��X ����������
			if (data->center.x< m_page3.m_iXDown || data->center.x > m_page3.m_iXUp)
			{
				index++;
				continue;
			}		
		if(m_page3.m_CheckY.GetCheck() == 1)	//λ��Y ����������
			if (data->center.y< m_page3.m_iYDown || data->center.y > m_page3.m_iYUp)
			{
				index++;
				continue;
			}
		if (m_page3.m_CheckAngle.GetCheck() == 1)   //�Ƕȳ���������
			if (data->angle< m_page3.m_iAngleDown || data->angle>m_page3.m_iAngleUp)
			{
				index++;
				continue;
			}
		if(m_page3.m_CheckScale.GetCheck() ==1)
			if (data->scale<m_page3.m_dScaleDown || data->scale>m_page3.m_dScaleUp)
			{
				index++;
				continue;
			}

		strResult[0].Format(_T("%d"), i + 1);
		strResult[1].Format(_T("%0.3f"), data->score);
		strResult[2].Format(_T("%0.3f"), data->center.x);
		strResult[3].Format(_T("%0.3f"), data->center.y);
		strResult[4].Format(_T("%0.3f"), data->angle);
		strResult[5].Format(_T("%0.3f"), data->scale);

		m_page3.m_ListCtrl.InsertItem(i - index, strResult[0]);
		m_page3.m_ListCtrl.SetItemText(i - index, 1, strResult[1]);
		m_page3.m_ListCtrl.SetItemText(i - index, 2, strResult[2]);
		m_page3.m_ListCtrl.SetItemText(i - index, 3, strResult[3]);
		m_page3.m_ListCtrl.SetItemText(i - index, 4, strResult[4]);
		m_page3.m_ListCtrl.SetItemText(i - index, 5, strResult[5]);
	

		CGdiRotBox* p1 = new CGdiRotBox(
			data->center.x,
			data->center.y, 
			data->width,
			data->height,
			data->angle);
		if (p1 != NULL)
		{

			p1->Offset(0.5, 0.5);
			p1->SetPenColor(RGB(0, 255, 0));
			m_Results.AddItem(p1);
		}
		CGdiContour* p2 = new CGdiContour(data->model);
		if (p2 != NULL)
		{
			p2->Offset(0.5, 0.5);
			p2->SetPenWidth(1);
			p2->SetPenColor(RGB(0, 255, 0));
			m_Results.AddItem(p2);
		}
	}
	//ˮƽ����ʹ�ֱ���� ������Ӵ��� 
	//
	//
	m_GdiView.Redraw();
}


/*****************************************************************
**FunctionName:	AddStringLevel()
*Description:	���m_CComboBox�ַ���
*parameter  :	��
*return		:	��
****************************************************************/
void CKMultipleDemoMatchDlg::AddStringLevel(CComboBox* m_CComboBox)
{
	CString strTemp;
	for (int i=0;i<10;i++)
	{
		strTemp.Format(_T("Level%d"), i);
		m_CComboBox->InsertString(i,strTemp);
	}
	
}

void CKMultipleDemoMatchDlg::BeginTime()
{
	QueryPerformanceFrequency(&m_Frequency);
	QueryPerformanceCounter(&m_BeginTime);
}

void CKMultipleDemoMatchDlg::EndTime()
{
	QueryPerformanceCounter(&m_EndTime);
	double fTime = double(m_EndTime.LowPart - m_BeginTime.LowPart) / double(m_Frequency.LowPart);
	CString strTime;
	strTime.Format(_T("����ʱ�䣺%0.3f ms"), fTime*1000.0);
	//SetDlgItemText(IDC_TIMER, strTime);
}

