#include "StdAfx.h"
#include "Tool.h"
#include "ToolControl.h"
#include "CKMultipleDemoMatch_Tool.h"
#include "CKMultipleDemoMatchDlg.h"
//#include ""

fHIDBCreatesLink		HIDBCreatesLink;
fHIDBDeleteLink			HIDBDeleteLink;
fHIDBSelectLink			HIDBSelectLink;
fHIDBSaveInt32			HIDBSaveInt32;
fHIDBGetInt32			HIDBGetInt32;
fHIDBSaveInt64			HIDBSaveInt64;
fHIDBGetInt64			HIDBGetInt64;
fHIDBSaveDouble			HIDBSaveDouble;
fHIDBGetDouble			HIDBGetDouble;
fHIDBSaveChar			HIDBSaveChar;
fHIDBGetChar			HIDBGetChar;
fHIDBGetPointcoord		HIDBGetPointcoord;
fHIDBGetLinecoord		HIDBGetLinecoord;
fHIDBGetCirclecoord		HIDBGetCirclecoord;
fHIDBSavePointcoord		HIDBSavePointcoord;
fHIDBSaveLinecoord		HIDBSaveLinecoord;
fHIDBSaveCirclecoord	HIDBSaveCirclecoord;
fHWDO					HWDO;
fGetIDNum				GetIDNum;
fGetAllID				GetAllID;
fHIDBGetImage			HIDBGetImage;
fHIDBSaveImage			HIDBSaveImage;
fHIDBGetImagePointer	HIDBGetImagePointer;
fHIDBSaveImagePointer	HIDBSaveImagePointer;
fHIDBSaveOffsetData		HIDBSaveOffsetData;
fHIDBGetOffsetData		HIDBGetOffsetData;
fHIDBDeleteBuf			HIDBDeleteBuf;



int GetGUID(TCHAR *szGuid)
{
	//_tcscpy_s(szGuid, MAX_PATH, _T("2CA9B08A-B6AA-40B4-91B2-D6494220D080"));
	//_tcscpy_s(szGuid, MAX_PATH, _T("2CA9B08A-B6AA-40B4-91B2-D6494220D081"));
	_tcscpy_s(szGuid, MAX_PATH, _T("2CA9B08A-B6AA-40B4-91B2-D6494220D082"));
	return 0;
}
int GetCallFun(int nType, void **pParam)
{
	int nResult = -1;
	TRACE(_T("GetCallFun(%d,%x)\n"),nType,pParam);
	switch (nType)
	{
	case 1:
		*pParam = GetToolName;
		nResult = 0;
		break;
	case 2:
		*pParam = ShowPropertyDialog;
		nResult = 0;
		break;
	case 3:
		*pParam = Save;
		nResult = 0;
		break;
	case 4:
		*pParam = Load;
		nResult = 0;
		break;
	case 5:
		*pParam = Do;
		nResult = 0;
		break;
	case 6:
		*pParam = CreateTool;
		nResult = 0;
		break;
	case 7:
		*pParam = DeleteTool;
		nResult = 0;
		break;
	case 8:
		*pParam = GetToolType;
		nResult = 0;
		break;
	case 9:
		*pParam = Copy;
		nResult = 0;
		break;
	case 10:
		*pParam = GetGUID;
		nResult = 0;
		break;
	default:
		break;
	}
	return nResult;
}

int SetCallback(int nType, void *pParam)
{
	int nResult = -1;
	TRACE(_T("SetCallback(%d,%x)\n"),nType,pParam);
	switch (nType)
	{
	case 1:
		HIDBCreatesLink = static_cast<fHIDBCreatesLink>(pParam);
		nResult = 0;
		break;  
	case 2:
		HIDBDeleteLink = static_cast<fHIDBDeleteLink>(pParam);
		nResult = 0;
		break;
	case 3:
		HIDBSelectLink = static_cast<fHIDBSelectLink>(pParam);
		nResult = 0;
		break;
	case 4:
		HIDBSaveInt32 = static_cast<fHIDBSaveInt32>(pParam);
		nResult = 0;
		break;
	case 5:
		HIDBGetInt32 = static_cast<fHIDBGetInt32>(pParam);
		nResult = 0;
		break;
	case 6:
		HIDBSaveInt64 = static_cast<fHIDBSaveInt64>(pParam);
		nResult = 0;
		break;
	case 7:
		HIDBGetInt64 = static_cast<fHIDBGetInt64>(pParam);
		nResult = 0;
		break;
	case 8:
		HIDBSaveDouble = static_cast<fHIDBSaveDouble>(pParam);
		nResult = 0;
		break;
	case 9:
		HIDBGetDouble = static_cast<fHIDBGetDouble>(pParam);
		nResult = 0;
		break;
	case 10:
		HIDBSaveChar = static_cast<fHIDBSaveChar>(pParam);
		nResult = 0;
		break;
	case 11:
		HIDBGetChar = static_cast<fHIDBGetChar>(pParam);
		nResult = 0;
		break;
	case 12:
		HIDBSavePointcoord = static_cast<fHIDBSavePointcoord>(pParam);
		nResult = 0;
		break;
	case 13:
		HIDBGetPointcoord = static_cast<fHIDBGetPointcoord>(pParam);
		nResult = 0;
		break;
	case 14:
		HIDBSaveLinecoord = static_cast<fHIDBSaveLinecoord>(pParam);
		nResult = 0;
		break;
	case 15:
		HIDBGetLinecoord = static_cast<fHIDBGetLinecoord>(pParam);
		nResult = 0;
		break;
	case 16:
		HIDBSaveCirclecoord = static_cast<fHIDBSaveCirclecoord>(pParam);
		nResult = 0;
		break;
	case 17:
		HIDBGetCirclecoord = static_cast<fHIDBGetCirclecoord>(pParam);
		nResult = 0;
		break;
	case 18:
		HIDBSaveImage = static_cast<fHIDBSaveImage>(pParam);
		nResult = 0;
		break;
	case 19:
		HIDBGetImage = static_cast<fHIDBGetImage>(pParam);
		nResult = 0;
		break;
	case 20:
		HIDBSaveImagePointer = static_cast<fHIDBSaveImagePointer>(pParam);
		nResult = 0;
		break;
	case 21:
		HIDBGetImagePointer = static_cast<fHIDBGetImagePointer>(pParam);
		nResult = 0;
		break;
	case 22:
		HIDBSaveOffsetData = static_cast<fHIDBSaveOffsetData>(pParam);
		nResult = 0;
		break;
	case 23:
		HIDBGetOffsetData = static_cast<fHIDBGetOffsetData>(pParam);
		nResult = 0;
		break;
	case 24:
		HIDBDeleteBuf = static_cast<fHIDBDeleteBuf>(pParam);
		nResult = 0;
		break;
	case 100:
		HWDO = static_cast<fHWDO>(pParam);
		nResult = 0;
		break;
	case 101:
		GetIDNum = static_cast<fGetIDNum>(pParam);
		nResult = 0;
		break;
	case 102:
		GetAllID = static_cast<fGetAllID>(pParam);
		nResult = 0;
		break;
	default:
		break;
	}
	return nResult;
}

void Copy(void* pDst,void* pSrc)
{
	
}

void GetToolName(TCHAR* szName)
{
	_tcscpy_s(szName, MAX_PATH, _T("ģ��ƥ��(CK��)"));
}

void GetToolType(TCHAR* szType)
{
	_tcscpy_s(szType, MAX_PATH, _T("����"));
}

void Save(CArchive &ar, void *pToolParam)
{
	CKMultipleDemoMatch* p = (CKMultipleDemoMatch*)pToolParam;
	p->Save(ar);
}

void Load(CArchive &ar, void *pToolParam)
{
	CKMultipleDemoMatch* p = (CKMultipleDemoMatch*)pToolParam;
	p->Load(ar);
}

int Do(void * pControlPara)
{
	ControlParam* pCtrl=(ControlParam*)pControlPara;
	void* pToolParam = pCtrl->pToolParam;
	CKMultipleDemoMatch* p = (CKMultipleDemoMatch*)pToolParam;
	p->Do();

	return 0;

}

int CreateTool(TCHAR * pDocName, int nNodeID, TCHAR * pNodeName, void** pToolParam)
{
	if (*pToolParam == nullptr)
	{
		CKMultipleDemoMatch* p = new CKMultipleDemoMatch(pDocName, nNodeID, pNodeName);
		*pToolParam = p;
	}

	return 0;
}


CDialog* ShowPropertyDialog(CWnd* pParent, void * pToolParam)
{

	CKMultipleDemoMatch* p = (CKMultipleDemoMatch*)pToolParam;
	p->ShowPropertyDialog();

	return NULL;
}


int DeleteTool(TCHAR* pDocName, int nNodeID, TCHAR* pNodeName, void* pToolParam)
{
	CKMultipleDemoMatch* p = (CKMultipleDemoMatch*)pToolParam;
	delete p;

	return 0;
}

void WriteString(CArchive &ar, CString str)
{
	ar.WriteString(str + _T("\r\n"));
	
}

void WriteDouble(CArchive & ar, double dbNum)
{
	CString str;
	str.Format(_T("%lf"), dbNum);
	WriteString(ar, str);
}

void WriteInt(CArchive & ar, int nNum)
{
	CString str;
	str.Format(_T("%d"), nNum);
	WriteString(ar, str);
}

void WriteBool(CArchive& ar, BOOL nNum)
{
	CString str;
	if (nNum == TRUE)
		str = _T("1");
	else
		str = _T("0");
	WriteString(ar, str);
}

