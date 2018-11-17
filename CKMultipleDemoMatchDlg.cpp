// GetLocalPictureDlg.cpp : 实现文件
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
	// TODO:  在此添加额外的初始化

	//选项卡初始化
	m_Tab.InsertItem(0,_T("基本设置"));
	m_Tab.InsertItem(1,_T("参数设置"));
	m_Tab.InsertItem(2,_T("数据结果"));
	m_Tab.InsertItem(3,_T("显示图形"));

	//m_page1.Create(IDD_PAGE1, m_Tab.m_hWnd);
	m_page1.Create(IDD_PAGE1,GetDlgItem(IDC_TAB1));
	m_page2.Create(IDD_PAGE2,GetDlgItem(IDC_TAB1));
	m_page3.Create(IDD_PAGE3,GetDlgItem(IDC_TAB1));
	m_page4.Create(IDD_PAGE4,GetDlgItem(IDC_TAB1));
	m_learnDlg.Create(IDD_LEARN_DLG, GetDlgItem(IDC_TAB1));
	//获得IDC_TABTEST客户区大小 
	CRect rs;
	m_Tab.GetClientRect(&rs);
	//调整子对话框在父窗口中的位置 
	rs.top = rs.top + 40;
	rs.left = rs.left + 10;
	rs.bottom = rs.bottom - 10;
	rs.right = rs.right - 10;

	//设置子对话框尺寸并移动到指定位置 
	m_page1.MoveWindow(&rs);
	m_page2.MoveWindow(&rs);
	m_page3.MoveWindow(&rs);
	m_page4.MoveWindow(&rs);
	m_learnDlg.MoveWindow(&rs);
	//分别设置隐藏和显示 
	m_page1.ShowWindow(true);
	m_page2.ShowWindow(false);
	m_page3.ShowWindow(false);
	m_page4.ShowWindow(false);
	m_learnDlg.ShowWindow(false);
	//设置默认的选项卡 
	m_Tab.SetCurSel(0);

	//初始化Page1下拉列表
	
	m_page1.m_combox_image.AddString(m_GetMatchParam.str_ImageName);
	m_page1.m_combox_image.SetCurSel(0);
	//初始化图片控件；
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

	//学习矩阵
	m_lRoi.left = 100;
	m_lRoi.top = 100;
	m_lRoi.right = 500;
	m_lRoi.bottom = 400;
	m_lRoi.SetPenColor(RGB(80, 200, 200));  //青色
	m_lRoi.SetVisible(false);

	//搜索矩形初始化
	m_sRectROI.left = 100;
	m_sRectROI.top = 100;
	m_sRectROI.right = 500;
	m_sRectROI.bottom = 400;
	m_sRectROI.SetPenColor(RGB(255, 0, 0));  
	m_sRectROI.SetVisible(false);

	//搜索旋转矩阵初始化
	m_sRotBoxROI.center.x = 100;
	m_sRotBoxROI.center.y = 100;
	m_sRotBoxROI.width = 100;
	m_sRotBoxROI.height = 100;
	m_sRotBoxROI.angle = 60;
	m_sRotBoxROI.SetPenColor(RGB(255, 0, 0));
	m_sRotBoxROI.SetVisible(false);


	//初始化page2部分
	m_page2.m_MaxCount = m_GetMatchParam.iMaxCount;
	m_page2.m_iMinScore = m_GetMatchParam.iMinScore;
	m_page2.m_iMinAngle = m_GetMatchParam.iMinAngle;
	m_page2.m_iMaxAngle = m_GetMatchParam.iMaxAngle;
	m_page2.m_iMinScale = m_GetMatchParam.iMinScale;
	m_page2.m_iMaxScale = m_GetMatchParam.iMaxScale;
	m_page2.m_iMaxOverlap = m_GetMatchParam.iMaxOverlap;

	AddStringLevel(&m_page2.m_CCbox_Speed);
	AddStringLevel(&m_page2.m_CCbox_Accuracy);
	m_page2.m_CCbox_Polarity.InsertString(0,_T("正常"));
	m_page2.m_CCbox_Polarity.InsertString(1,_T("反转"));
	m_page2.m_CCbox_Polarity.InsertString(2,_T("任意"));

	m_page2.m_iSpeed = m_GetMatchParam.iMaxSpeed;
	m_page2.m_iAccuracy = m_GetMatchParam.iAccuracy;
	m_page2.m_iPolarity = m_GetMatchParam.iPolarity;
	m_page2.m_iPolarity = 0;
	m_page2.UpdateData(FALSE);

	//初始化page3部分
	CRect ListRect;
	m_page3.m_ListCtrl.GetWindowRect(ListRect);
	m_page3.m_ListCtrl.SetExtendedStyle(m_page3.m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
	m_page3.m_ListCtrl.InsertColumn(0,_T("编号"), LVCFMT_CENTER, ListRect.Width()/6,0);
	m_page3.m_ListCtrl.InsertColumn(1,_T("分数"), LVCFMT_CENTER, ListRect.Width()/6,1);
	m_page3.m_ListCtrl.InsertColumn(2, _T("位置X"), LVCFMT_CENTER, ListRect.Width()/6,2);
	m_page3.m_ListCtrl.InsertColumn(3, _T("位置Y"), LVCFMT_CENTER, ListRect.Width()/6,3);
	m_page3.m_ListCtrl.InsertColumn(4, _T("角度"),LVCFMT_CENTER, ListRect.Width()/6,4);
	m_page3.m_ListCtrl.InsertColumn(5, _T("比例"), LVCFMT_CENTER, ListRect.Width()/6,5);

	m_GdiView.SetActiveOverlay(&m_Overlay);
	m_GdiView.SetStaticOverlay(&m_Results);




	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CKMultipleDemoMatchDlg::OnBnClickedCancelButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//释放相关资源
	CDialogEx::OnCancel();

}




void CKMultipleDemoMatchDlg::OnBnClickedOKButton()
{
	//HIDBSelectLink(cDocName, &iNodeID, cNodeName, cParamName, &iType, &iIndex);
	//保存参数，便于流程中运行
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
	// TODO: 在此添加控件通知处理程序代码
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
*Description:	点击执行，搜索模板
*parameter  :	无

*return		:	无
****************************************************************/
void CKMultipleDemoMatchDlg::OnBnClickedBTNSeatchModel()
{
	// TODO: 在此添加控件通知处理程序代码
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
		if (m_page3.m_CheckNum.GetCheck() == 1 )		//数量超出上限，返回
			if (i > (m_page3.m_iNumUp - 1))
			{
				return;
			}
			
		if (m_page3.m_CheckX.GetCheck() == 1)	//位置X 超出上下限
			if (data->center.x< m_page3.m_iXDown || data->center.x > m_page3.m_iXUp)
			{
				index++;
				continue;
			}		
		if(m_page3.m_CheckY.GetCheck() == 1)	//位置Y 超出上下限
			if (data->center.y< m_page3.m_iYDown || data->center.y > m_page3.m_iYUp)
			{
				index++;
				continue;
			}
		if (m_page3.m_CheckAngle.GetCheck() == 1)   //角度超出上下限
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
	//水平排序和垂直排序 后面添加代码 
	//
	//
	m_GdiView.Redraw();
}


/*****************************************************************
**FunctionName:	AddStringLevel()
*Description:	添加m_CComboBox字符串
*parameter  :	无
*return		:	无
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
	strTime.Format(_T("消耗时间：%0.3f ms"), fTime*1000.0);
	//SetDlgItemText(IDC_TIMER, strTime);
}

