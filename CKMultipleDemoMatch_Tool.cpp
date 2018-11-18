#include "stdafx.h"
#include "CKMultipleDemoMatch_Tool.h"
#include "CKMultipleDemoMatchDlg.h"

extern CKMultipleDemoMatchDlg* pCKMultipleDemoMatchDlg;

CKMultipleDemoMatch::CKMultipleDemoMatch(TCHAR * pDocName, int nNodeID, TCHAR * pNodeName)
{
	m_stLinkParam.szDocName[0] = '\0';
	m_stLinkParam.szNodeName[0] = '\0';
	if (_tcslen(pDocName) > 0)
	{
		_tcscpy_s(m_stLinkParam.szDocName, MAX_PATH, pDocName);
		_tcscpy_s(m_stLinkParam.szNodeName, MAX_PATH, pNodeName);
		m_stLinkParam.nNodeID = nNodeID;
	}
	//创建链接
	if (HIDBCreatesLink != nullptr)
	{
		//可以被外部调用的数据
		HIDBCreatesLink(pDocName, nNodeID, pNodeName, _T("RESCORE"), NODETYPE_DOUBLE); //分数
		HIDBCreatesLink(pDocName, nNodeID, pNodeName, _T("RX"), NODETYPE_DOUBLE);	   //位置X
		HIDBCreatesLink(pDocName, nNodeID, pNodeName, _T("RY"), NODETYPE_DOUBLE);		//位置Y
		HIDBCreatesLink(pDocName, nNodeID, pNodeName, _T("RAngle"), NODETYPE_DOUBLE);		//角度
		HIDBCreatesLink(pDocName, nNodeID, pNodeName, _T("RESCALE"), NODETYPE_DOUBLE);  //缩放比例
	}
}


CKMultipleDemoMatch::~CKMultipleDemoMatch()
{
	//释放链接
	HIDBDeleteLink(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RESCORE")); //分数
	HIDBDeleteLink(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RX"));	   //位置X
	HIDBDeleteLink(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RY"));		//位置Y
	HIDBDeleteLink(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RAngle"));		//角度
	HIDBDeleteLink(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RESCALE"));  //缩放比例
	//m_GetMatchParam.CPrImage.Release();
}

void CKMultipleDemoMatch::Save(CArchive &ar)
{
	WriteString(ar, _T("HANSLIGHT_CCD_CKMULTIPLEMATCH_B"));
	//保存采集图片工具的参数
	WriteInt(ar, 100);
	//ar.WriteObject(m_GetMatchParam.cprImage);
	WriteInt(ar, 101);
	WriteString(ar, m_GetMatchParam.str_ImageName);
	WriteInt(ar, 102);
	//model;
	WriteInt(ar, 103);
	for (int i=0;i<10;i++)
	{
		WriteString(ar, m_GetMatchParam.strModel[i]);
	}
	
	WriteInt(ar, 104);
	for (int i = 0; i < 20; i++)
	{
		for (int j=0;j<6;j++)
		{
			WriteString(ar, m_GetMatchParam.strResult[i][j]);
		}
	}
	
	WriteInt(ar, 105);
	//m_Overlay;
	WriteInt(ar, 106);
	//m_Results;
	WriteInt(ar, 107);
	WriteInt(ar, m_GetMatchParam.iMaxCount);
	WriteInt(ar, 108);
	WriteInt(ar, m_GetMatchParam.iMinScore);
	WriteInt(ar, 109);
	WriteInt(ar, m_GetMatchParam.iMinAngle);
	WriteInt(ar, 110);
	WriteInt(ar, m_GetMatchParam.iMaxAngle);
	WriteInt(ar, 111);
	WriteInt(ar, m_GetMatchParam.iMinScale);
	WriteInt(ar, 112);
	WriteInt(ar, m_GetMatchParam.iMaxScale);
	WriteInt(ar, 113);
	WriteInt(ar, m_GetMatchParam.iMaxOverlap);
	WriteInt(ar, 114);
	WriteInt(ar, m_GetMatchParam.iMaxSpeed);
	WriteInt(ar, 115);
	WriteInt(ar, m_GetMatchParam.iAccuracy);
	WriteInt(ar, 116);
	WriteInt(ar, m_GetMatchParam.iPolarity);
	WriteString(ar, _T("HANSLIGHT_CCD_CKMULTIPLEMATCH_E"));
}
void CKMultipleDemoMatch::Load(CArchive &ar)
{
	CString str;
	while (ar.ReadString(str))
	{
		if (str == _T("100"))
		{
			//ar.Read(&m_GetMatchParam, sizeof(m_GetMatchParam));
			continue;
		}
		if (str == _T("101"))
		{
			ar.ReadString(str);
			m_GetMatchParam.str_ImageName = str;
			continue;
		}
		if (str == _T("102"))
		{
			//m_Models;
			continue;
		}
		if (str == _T("103"))
		{
			for (int i = 0; i < 10; i++)
			{
				ar.ReadString(str);
				m_GetMatchParam.strModel[i] = str;
			}
			continue;
		}
		if (str == _T("104"))
		{
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					ar.ReadString(str);
					m_GetMatchParam.strResult[i][j] = str;
				}
			}
			continue;
		}
		if (str == _T("105"))
		{
				//m_Overlay;
			continue;
		}
		if (str == _T("106"))
		{
				//m_Results;		 
			continue;
		}
		if (str == _T("107"))
		{
			ar.ReadString(str);
			m_GetMatchParam.iMaxCount = atoi(CW2A(str));
			continue;
		}
		if (str == _T("108"))
		{
			ar.ReadString(str);
			m_GetMatchParam.iMinScore = atoi(CW2A(str));
			continue;
		}
		if (str == _T("109"))
		{
			ar.ReadString(str);
			m_GetMatchParam.iMinAngle = atoi(CW2A(str));
			continue;
		}

		if (str == _T("110"))
		{
			ar.ReadString(str);
			m_GetMatchParam.iMaxAngle = atoi(CW2A(str));
			continue;
		}
		if (str == _T("111"))
		{
			ar.ReadString(str);
			m_GetMatchParam.iMinScale = atoi(CW2A(str));
			continue;
		}
		if (str == _T("112"))
		{
			ar.ReadString(str);
			m_GetMatchParam.iMaxScale = atoi(CW2A(str));
			continue;
		}
		if (str == _T("113"))
		{
			ar.ReadString(str);
			m_GetMatchParam.iMaxOverlap = atoi(CW2A(str));
			continue;
		}
		if (str == _T("114"))
		{
			ar.ReadString(str);
			m_GetMatchParam.iMaxSpeed = atoi(CW2A(str));
			continue;
		}
		if (str == _T("115"))
		{	
			ar.ReadString(str);
			m_GetMatchParam.iAccuracy = atoi(CW2A(str));
			continue;
		}
		if (str == _T("116"))
		{
			ar.ReadString(str);
			m_GetMatchParam.iPolarity = atoi(CW2A(str));
			continue;
		}
		if (str == _T("HANSLIGHT_CCD_COLLECTPICTURE_E"))
		{
			break;
		}

	}
	
}
void CKMultipleDemoMatch::ShowPropertyDialog()
{
	dlg.m_GetMatchParam = m_GetMatchParam;
	dlg.DoModal();
	m_GetMatchParam = dlg.m_GetMatchParam;
	m_Match = &dlg.m_Match;
	for (int i = 0; i < 6; i++)
	{
		strResult[i] = dlg.strResult[i];
	}
	SaveData();
}
void CKMultipleDemoMatch::Do()
{
	//查找模板
	try
	{
		SearchModePara *m_SearchModePara = NULL;
		m_SearchModePara = &pCKMultipleDemoMatchDlg->ModePara;
		m_Match->SetMaxCount(m_SearchModePara->iMaxCount);
		m_Match->SetMinScore(m_SearchModePara->iMinScore);
		m_Match->SetMinAngle(m_SearchModePara->iMinAngle);
		m_Match->SetMaxAngle(m_SearchModePara->iMaxAngle);
		m_Match->SetMinScale(m_SearchModePara->iMinScale);
		m_Match->SetMaxScale(m_SearchModePara->iMaxScale);
		m_Match->SetMaxOverlap(m_SearchModePara->iMaxOverlap);
		m_Match->SetMaxSpeed(m_SearchModePara->iSpeed);
		m_Match->SetAccuracy(m_SearchModePara->iAccuracy);
		m_Match->SetPolarity(m_SearchModePara->iPolarity);
		if (pCKMultipleDemoMatchDlg->m_sRectROI.GetVisible())
		{
			m_Match->Execute(pCKMultipleDemoMatchDlg->m_Image, pCKMultipleDemoMatchDlg->m_Models, pCKMultipleDemoMatchDlg->m_sRectROI);
		}
		else
		{
			m_Match->Execute(pCKMultipleDemoMatchDlg->m_Image, pCKMultipleDemoMatchDlg->m_Models, MaxROI);
		}
		SMatchData* data;
		int index = 0;
		for (int i = 0; i < m_Match->GetNumMatchs(); i++)
		{
			data = m_Match->GetMatchData(i);
			if (pCKMultipleDemoMatchDlg->m_page3.m_Num == 1)		//数量超出上限，返回
				if (i > (pCKMultipleDemoMatchDlg->m_page3.m_iNumUp - 1))
				{
					return;
				}
			if (pCKMultipleDemoMatchDlg->m_page3.m_PosX == 1)	//位置X 超出上下限
				if (data->center.x< pCKMultipleDemoMatchDlg->m_page3.m_iXDown || data->center.x >pCKMultipleDemoMatchDlg->m_page3.m_iXUp)
				{
					index++;
					continue;
				}
			if (pCKMultipleDemoMatchDlg->m_page3.m_PosY == 1)	//位置Y 超出上下限
				if (data->center.y< pCKMultipleDemoMatchDlg->m_page3.m_iYDown || data->center.y > pCKMultipleDemoMatchDlg->m_page3.m_iYUp)
				{
					index++;
					continue;
				}
			if (pCKMultipleDemoMatchDlg->m_page3.m_Angle == 1)   //角度超出上下限
				if (data->angle< pCKMultipleDemoMatchDlg->m_page3.m_iAngleDown || data->angle>pCKMultipleDemoMatchDlg->m_page3.m_iAngleUp)
				{
					index++;
					continue;
				}
			if (pCKMultipleDemoMatchDlg->m_page3.m_Scale == 1)
				if (data->scale<pCKMultipleDemoMatchDlg->m_page3.m_dScaleDown || data->scale > pCKMultipleDemoMatchDlg->m_page3.m_dScaleUp)
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
		}

		//保存到数据库
		SaveData();
	}
	catch (...)
	{
		return;
	}

}

void CKMultipleDemoMatch::SaveData()
{
	try
	{
		double dbRx, dbRy, dbAngle, dbScale, dbScore;
		dbScore = _wtof(strResult[1].GetBuffer());
		dbRx    = _wtof(strResult[2].GetBuffer());
		dbRy    = _wtof(strResult[3].GetBuffer());
		dbAngle = _wtof(strResult[4].GetBuffer());
		dbScale = _wtof(strResult[5].GetBuffer());
	
		//存储数据
		int irt; 
		irt = HIDBSaveDouble(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RESCORE"), &dbScore, 1, -1);
		irt = HIDBSaveDouble(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RX"), &dbRx, 1, -1);
		irt = HIDBSaveDouble(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RY"), &dbRy, 1, -1);
		irt = HIDBSaveDouble(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RAngle"), &dbAngle, 1, -1);
		irt = HIDBSaveDouble(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RESCALE"), &dbScale, 1, -1);
		
		//test
		double te1[2] = { 1.2 ,2.2};
		double te2 = 2.2;
		//irt = HIDBSaveDouble(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RESCORE"), te1, 2, -1);
		//irt = HIDBSaveDouble(m_stLinkParam.szDocName, m_stLinkParam.nNodeID, m_stLinkParam.szNodeName, _T("RESCORE"), &te2, 1, 1);
	}
	catch (...)
	{
		
	}


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


