/************************************************************
* Module:		CKBase.dll
* File:			CKBaseDef.h
*************************************************************/
#ifndef _CK_BASE_DEF_H_
#define _CK_BASE_DEF_H_

// ����/����
#ifdef CKVISION_DLL
#define CKVISION_EXPORT __declspec(dllexport)
#else
#define CKVISION_EXPORT __declspec(dllimport)
#endif

/* API�������� */
#define CKVISION_API		CKVISION_EXPORT

/* CKVision dll ��ʶ */
#define	CKDll

/* ������ض��� */
#define RECT_WIDTH(r)		(r.right-r.left)
#define RECT_HEIGHT(r)		(r.bottom-r.top)

/* Բ���� */
#define PI					3.1415926535897932384626433832795

/* ���Χ */
#define MaxROI				_maxRect

/* ���ͱ������ */
#define Frame2D				FRAME2D

/* MCPNT��� */
#define MCP_START			0x01	// ��ʼ���
#define MCP_CLOSE			0x02	// �պϱ��

#ifndef _WINDEF_

typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned int        UINT;
typedef unsigned long       DWORD;

#endif

// ���ƿռ�
namespace CKVision
{

/* �� */
typedef struct tagIPNT 
{
	int		x;			// X
	int		y;			// Y
} IPNT;

/* �� */
typedef struct tagDPNT
{
	double	x;			// X
	double	y;			// Y
} DPNT;

/* �߶� */
typedef struct tagDLINE
{
	DPNT	st;			// ���
	DPNT	ed;			// �յ�
} DLINE;

/* ���� */
typedef struct tagIRECT 
{
	int		left;		// ���
	int		top;		// �ϱ�
	int		right;		// �ұ�
	int		bottom;		// �±�
} IRECT;

/* ���� */
typedef struct tagDRECT 
{
	double	left;		// ���
	double	top;		// �ϱ�
	double	right;		// �ұ�
	double	bottom;		// �±�
} DRECT;

/* ��ת���� */
typedef struct tagROTRECT
{
	DPNT	center;		// ����
	double	width;		// ���
	double	height;		// �߶�
	double	angle;		// �Ƕ�
} ROTRECT, RRECT;

/* Բ�� */
typedef struct tagCIRCLE 
{
	DPNT	center;		// ����
	double	radius;		// �뾶
} CIRCLE;

/* Բ���� */
typedef struct tagRING 
{
	DPNT	center;		// ����
	double	radius;		// �뾶
	double	range;		// �뾶��Χ
	double	angle;		// �Ƕ�
	double	sweep;		// �Ƕȷ�Χ
} RING;

/* ��Բ�� */
typedef struct tagELLIPSE
{
	DPNT	center;		// ����
	double	radiusX;	// �뾶X
	double	radiusY;	// �뾶Y
	double	angle;		// �Ƕ�
} ELLIPSE;

/* ����� */
typedef struct tagPOLYGON
{
	int		count;		// ����
	DPNT*	vertex;		// ����
} POLYGON;

/* ������ */
typedef struct tagMPNT
{
	double	x;			// X
	double	y;			// Y
	double	a;			// �Ƕ�
	BYTE	m;			// ���
} MPNT;

/* �������� */
typedef struct tagCONTOUR
{
	int		count;		// ����
	MPNT*	points;		// ������
} CONTOUR;

/* 2D����ϵ��� */
typedef struct tagFRAME2D
{
	DPNT	point;		// ԭ��
	double	angle;		// �Ƕ�
} FRAME2D;

/* 3D����� */
typedef struct tagPNT3D
{
	double x;
	double y;
	double z;
} PNT3D;

/* 3Dƽ��ϵ�� */
typedef struct tagPLANE
{
	double a;
	double b;
	double c;
} PLANE;


/* ������ */
const IRECT _maxRect = { 0, 0, 0x7FFFFFFF, 0x7FFFFFFF };

};	// End

#endif	// _CK_BASE_DEF_H_
