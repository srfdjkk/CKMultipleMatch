#pragma once


// CPAGE3 对话框

class CPAGE3 : public CDialogEx
{
	DECLARE_DYNAMIC(CPAGE3)

public:
	CPAGE3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CPAGE3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// //显示查找结果
	CListCtrl m_ListCtrl;
};
