// CPAGE3.cpp: 实现文件
//

#include "stdafx.h"
#include "CKMultipleDemoMatch.h"
#include "CPAGE3.h"
#include "afxdialogex.h"


// CPAGE3 对话框

IMPLEMENT_DYNAMIC(CPAGE3, CDialogEx)

CPAGE3::CPAGE3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CPAGE3::~CPAGE3()
{
}

void CPAGE3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(CPAGE3, CDialogEx)
END_MESSAGE_MAP()


// CPAGE3 消息处理程序
