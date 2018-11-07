#include "stdafx.h"
#include "CKMultipleDemoMatch_Tool.h"


CKMultipleDemoMatch::CKMultipleDemoMatch(TCHAR * pDocName, int nNodeID, TCHAR * pNodeName)
{
	m_Toolparam.szDocName[0] = '\0';
	m_Toolparam.szNodeName[0] = '\0';
	if (_tcslen(pDocName) > 0)
	{
		_tcscpy_s(m_Toolparam.szDocName, MAX_PATH, pDocName);
		_tcscpy_s(m_Toolparam.szNodeName, MAX_PATH, pNodeName);
		m_Toolparam.nNodeID = nNodeID;
	}
	TCHAR pParaName[MAX_PATH] = _T("采集图片");
	_tcscpy_s(m_Toolparam.szParaName, MAX_PATH, pParaName);
	m_Toolparam.nIndex = 0;
	m_Toolparam.nType = NODETYPE_PIMAGE;

	m_NOdomodel = 0;
	m_ImageSelect = 0;
	m_pBuffer = nullptr;
	
	m_imagepinT = new ImageParam();
	m_pCImage = new ImageParam(); //转换
}


CKMultipleDemoMatch::~CKMultipleDemoMatch()
{
	HIDBDeleteLink(m_Toolparam.szDocName, m_Toolparam.nNodeID, m_Toolparam.szNodeName, _T("采集图片指针"));

	if (m_pBuffer)
	{
		delete[]m_pBuffer;
		m_pBuffer = nullptr;
	}

	delete m_imagepinT;
	delete m_pCImage;
}

void CKMultipleDemoMatch::Save(CArchive &ar)
{
	//WriteString(ar, _T("HANSLIGHT_CCD_COLLECTPICTURE_B"));
	////保存采集图片工具的参数
	//WriteInt(ar, 100);
	//WriteBool(ar, m_GLPPT.BtnSingleIn);
	//WriteInt(ar, 101);
	//WriteBool(ar, m_GLPPT.BtnMultipleIn);
	//WriteInt(ar, 102);
	//WriteBool(ar, m_GLPPT.BtnCamIn);
	//WriteInt(ar, 103);
	//WriteBool(ar, m_GLPPT.CheckFile);
	//WriteInt(ar, 104);
	//WriteInt(ar, m_GLPPT.BtnType);
	//WriteInt(ar, 105);
	//WriteString(ar, m_GLPPT.ImagePath);
	//WriteInt(ar, 106);
	//WriteString(ar, m_GLPPT.ImgFolderPath);
	//WriteInt(ar, 107);
	//WriteString(ar, m_GLPPT.ImageTyoe);
	//WriteInt(ar, 108);
	//WriteString(ar, m_GLPPT.CheckFileName);
	//WriteInt(ar, 109);
	//WriteInt(ar, m_GLPPT.ImgFileNameVect_Count);
	//for (int i = 0; i < m_GLPPT.ImgFileNameVect_Count;i++)
	//{
	//	WriteInt(ar, 110+i);
	//	WriteString(ar, m_GLPPT.ImgFileNameVect[i]);
	//}

	//WriteString(ar, _T("HANSLIGHT_CCD_COLLECTPICTURE_E"));
}
void CKMultipleDemoMatch::Load(CArchive &ar)
{
	//CString str;
	//while (ar.ReadString(str))
	//{
	//	if (str == _T("100"))
	//	{
	//		ar.ReadString(str);
	//		m_GLPPT.BtnSingleIn = atoi(CW2A(str));
	//		continue;
	//	}
	//	if (str == _T("101"))
	//	{
	//		ar.ReadString(str);
	//		m_GLPPT.BtnMultipleIn = atoi(CW2A(str));
	//		continue;
	//	}
	//	if (str == _T("102"))
	//	{
	//		ar.ReadString(str);
	//		m_GLPPT.BtnCamIn = atoi(CW2A(str));
	//		continue;
	//	}
	//	if (str == _T("103"))
	//	{
	//		ar.ReadString(str);
	//		m_GLPPT.CheckFile = atoi(CW2A(str));
	//		continue;
	//	}
	//	if (str == _T("104"))
	//	{
	//		ar.ReadString(str);
	//		m_GLPPT.BtnType = atoi(CW2A(str));
	//		continue;
	//	}
	//	if (str == _T("105"))
	//	{
	//		ar.ReadString(str);
	//		m_GLPPT.ImagePath = str;
	//		continue;
	//	}
	//	if (str == _T("106"))
	//	{
	//		ar.ReadString(str);
	//		m_GLPPT.ImgFolderPath = str;
	//		continue;
	//	}
	//	if (str == _T("107"))
	//	{
	//		ar.ReadString(str);
	//		m_GLPPT.ImageTyoe = str;
	//		continue;
	//	}
	//	if (str == _T("108"))
	//	{
	//		ar.ReadString(str);
	//		m_GLPPT.CheckFileName = str;
	//		continue;
	//	}
	//	if (str == _T("109"))
	//	{
	//		ar.ReadString(str);
	//		m_GLPPT.ImgFileNameVect_Count = atoi(CW2A(str));
	//		continue;
	//	}
	//	m_GLPPT.ImgFileNameVect.clear();
	//	if (str == _T("110"))
	//	{			
	//		for (int i=0;i< m_GLPPT.ImgFileNameVect_Count;i++)
	//		{
	//			ar.ReadString(str);
	//			m_GLPPT.ImgFileNameVect.push_back(str);
	//		}
	//	
	//	}
	//	if (str == _T("HANSLIGHT_CCD_COLLECTPICTURE_E"))
	//	{
	//		break;
	//	}
	//	
	//}

}
void CKMultipleDemoMatch::ShowPropertyDialog()
{
	CKMultipleDemoMatchDlg dlg;

	dlg.m_GetMatchParam = m_GetMatchParam;
	dlg.DoModal();
	m_GetMatchParam = dlg.m_GetMatchParam;

	DoCreate();
}
void CKMultipleDemoMatch::Do()
{
	DoCreate();
}

void CKMultipleDemoMatch::DoCreate()
{


}

void CKMultipleDemoMatch::SetImageParamByCkImage(ImageParam* pImageParam, CPrImage* pho_Img)
{
	pImageParam->m_nChannel = pho_Img->GetFormat();
	pImageParam->m_nWidth = pho_Img->GetWidth();
	pImageParam->m_nHeight = pho_Img->GetHeight();
	pImageParam->m_nSize = pho_Img->GetSizeByte();
	pImageParam->m_nPtrType =0;
	pImageParam->m_pData = pho_Img->GetBits();

}


void CKMultipleDemoMatch::ReadpCharA(CArchive &ar, TCHAR* pchar)
{
	//USES_CONVERSION;
	CString strRd;
	ar.ReadString(strRd);
	_tcscpy_s(pchar,256, strRd.GetBuffer());
}

void CKMultipleDemoMatch::ReadDouble(CArchive &ar, double& dbVal)
{
	//CString str;
	//ar.ReadString(str);
	//dbVal = _wtof(str.GetBuffer());
}

void CKMultipleDemoMatch::WritepCharA(CArchive &ar, TCHAR* pchar)
{
	CString strWt(pchar);
	ar.WriteString(strWt + _T("\r\n"));
}

void CKMultipleDemoMatch::WriteDouble(CArchive &ar, double dbVal)
{
	CString str;
	str.Format(_T("%lf"), dbVal);
	ar.WriteString(str + _T("\r\n"));
}


