// GetLocalPicture.h : GetLocalPicture DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGetLocalPictureApp
// �йش���ʵ�ֵ���Ϣ������� GetLocalPicture.cpp
//

class CGetLocalPictureApp : public CWinApp
{
public:
	CGetLocalPictureApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
