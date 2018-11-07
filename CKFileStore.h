/************************************************************
* Module:		CKBase.dll
* File:			CKFileStore.h
*************************************************************/
#ifndef _CK_FILESTORE_H_
#define _CK_FILESTORE_H_

#include "CKBaseDef.h"


namespace CKVision
{

/* �ļ��洢�ṹ */
struct tagFileStore;

/* CFileStore Class */
class CKVISION_EXPORT CFileStore
{
public: 
	CFileStore();
	CFileStore( const char* strFileName, UINT nFlag );
	virtual ~CFileStore();

	enum OpenFlag { save=0, load=1 };

public: 
	virtual bool Open( const char* strFileName, UINT nFlag );
	virtual void Close();
	virtual bool IsOpen() const;
	virtual bool IsLoading() const;
	virtual bool Read( void* lpData, UINT nSize ) const;
	virtual bool Write( const void* lpData, UINT nSize );
	virtual bool Flush();

protected:
	tagFileStore* pp;

};	// CFileStore


};	// CKVision

/* ���ļ�װ������ */
#define CKLoadFile( pvsObject, vsFileName )\
	{\
		CFileStore _vsfs;\
		if( _vsfs.Open( vsFileName, CFileStore::load ) )\
		{\
			(pvsObject)->Exchange( _vsfs );\
			_vsfs.Close();\
		}\
	}\

/* �������ݵ��ļ� */
#define CKSaveFile( pvsObject, vsFileName )\
	{\
		CFileStore _vsfs;\
		if( _vsfs.Open( vsFileName, CFileStore::save ) )\
		{\
			(pvsObject)->Exchange( _vsfs );\
			_vsfs.Close();\
		}\
	}\

#endif	// _CK_FILESTORE_H_