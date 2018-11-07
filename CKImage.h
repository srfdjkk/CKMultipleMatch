/************************************************************
* Module:		CKBase.dll
* File:			CKImage.h
*************************************************************/
#ifndef _CK_IMAGE_H_
#define _CK_IMAGE_H_

#include "CKFileStore.h"

namespace CKVision
{

/* ͼ�����ظ�ʽ */
enum ImagePixelFormat 
{
	IpfNull		= 0,		// δ֪
	IpfGray		= 1,		// 8λ�Ҷ�
	IpfColor	= 3			// 24λ��ɫ
};

/* ͼ����������� */
class CKVISION_EXPORT CPrImage
{
public:
	CPrImage();

	// ����+����
	CPrImage( const CPrImage& imgSrc );

	// ����+����( ��ȣ� �߶ȣ� ͼ�����ظ�ʽ )
	CPrImage( int nWidth, int nHeight, int nFormat=1 );

	// ��������
	virtual	~CPrImage();

public:	// ���ݷ���

	// ��ȡ���
	int GetWidth() const;

	// ��ȡ�߶�
	int	GetHeight() const;

	// ��ȡ���ظ�ʽ
	int GetFormat() const;

	// ��ȡ���ֽ���
	int GetLineByte() const;

	// ��ȡ���ֽ���
	UINT GetSizeByte() const;

	// ��ȡ���ݵ�ַ
	BYTE* GetBits() const;

public:	// ���ܺ���

	/*
	����:	����һ��ͼ��( ��ȣ� �߶ȣ� ͼ�����ظ�ʽ )
	����:	
			[in]	nWidth	ͼ����
			[in]	nHeight	ͼ��߶�
			[in]	nFormat	ͼ�����ظ�ʽ { IpfNull= 0 (δ֪), IpfGray= 1 (8λ�Ҷ�), IpfColor= 3 (24λ��ɫ) }

	����:	�ɹ� true, ʧ�� false
	*/ 
	bool Create( int nWidth, int nHeight, int nFormat=1 );
	

	/*
	����:	װ��BMP�ļ�
	����:	
			[in]	strFileName	ȫ·������

	����:	�ɹ� true, ʧ�� false
	*/ 
	bool LoadBmp( const char* strFileName );

	/*
	����:	����BMP�ļ�
	����:	
			[in]	strFileName	ȫ·������

	����:	�ɹ� true, ʧ�� false
	*/
	bool SaveBmp( const char* strFileName ) const;

	/*
	����:	����ͼ������
	����:	
			[in]	pData	ͼ�����ݻ�����
			[in]	bFlip	�Ƿ���

	����:	�ɹ� true, ʧ�� false
	*/ 
	bool SetBits( const BYTE* pData, bool bFlip=true );

	/*
	����:	����ͼ��
	����:	
			[in]	imgSrc	��Դͼ��

	����:	�ɹ� true, ʧ�� false
	*/ 
	bool Copy( const CPrImage& imgSrc );

	/*
	����:	ճ��ͼ��
	����:	
			[in]	imgSrc	��Դͼ��
			[in]	x		ճ��λ��x
			[in]	y		ճ��λ��x

	����:	�ɹ� true, ʧ�� false
	*/ 
	bool Paste( const CPrImage& imgSrc, int x, int y );

	/*
	����:	�ü���������
	����:	
			[in]	imgSrc	��Դͼ��
			[in]	roi		�ü�����

	����:	�ɹ� true, ʧ�� false
	*/ 
	bool Cut( const CPrImage& imgSrc, const IRECT& roi );

	/*
	����:	�ü���ת��������
	����:	
			[in]	imgSrc	��Դͼ��
			[in]	roi		�ü�����

	����:	�ɹ� true, ʧ�� false
	*/
	bool Cut( const CPrImage& imgSrc, const ROTRECT& roi );

	/*
	����:	��ɫת�Ҷ�
	����:	
			[in]	imgSrc	��Դͼ��
			[in]	index	ת��ͨ�� 0~4 { 0(��ɫ) ,1(��ɫ), 2(��ɫ), 3(��Сֵ)��4(���ֵ)}

	����:	�ɹ� true, ʧ�� false
	*/
	bool Gray( const CPrImage& imgSrc, int index );

	/*
	����:	����һ������ֵ
	����:	
			[in]	x		λ��x
			[in]	y		λ��y
			[in]	value	�Ҷ�ֵ (0~255)

	����:	�ɹ� true, ʧ�� false
	*/
	bool SetPixel( int x, int y, int value );

	/*
	����:	��ȡһ������ֵ
	����:	
			[in]	x		λ��x
			[in]	y		λ��y
			[out]	value	�Ҷ�ֵ (0~255)

	����:	�ɹ� true, ʧ�� false
	*/
	bool GetPixel( int x, int y, int& value ) const;

	// ���
	bool Clear( BYTE nVal=0 );

	// ��ת
	bool Reverse();

	// �洢����
	bool Exchange( CFileStore& fs );

	// �ͷ�
	void Release();

protected:

	int		m_nWidth;		// ���
	int		m_nHeight;		// �߶�
	int		m_nFormat;		// ���ظ�ʽ
	int		m_nLineByte;	// ���ֽ���
	UINT	m_nSizeByte;	// ���ֽ���
	BYTE*	m_pDataBits;	// ͼ������

};	// CPrImage

};	// CKVision

/* ���ͱ������ */
#define CPvImage CPrImage

#endif	// _CK_IMAGE_H_
