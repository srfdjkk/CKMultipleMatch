typedef struct tagEntityInfoParam
{
	TCHAR szEntityType[MAX_PATH];//ʵ������
	TCHAR szEntityName[MAX_PATH];//ʵ������
	BOOL bCheckWeldContour;//�Ƿ񺸽�����
	BOOL bCheckWeldHatch;//�����������
	int nLoopWeldCount;//ѭ�����Ӵ���
	int nBeatWeldCount;//���Ӵ���
	double dbBeatOffset;//����ƫ��
	int nArrayCountX;//����X��������
	int nArrayCountY;//����Y��������
	double dbArrayIncX;//����X����ļ��
	double dbArrayIncY;//����Y����ļ��
	BOOL bCheckCluster;//�Ƿ����
	BOOL bCheckPenPath;//
	BOOL bCheckOutAsBitmap;//��Ϊ����λͼ
	double dbEditSpeed;//�ٶ�
	double dbEditAcceleration;//���ٶ�
	double dbEditVoidSpeed; //�ճ��ٶ�
	double dbEditVoidAcceleration;//�ճ̼��ٶ�
	int nCoordNum;		//����ϵ���; 1 or 2
	int nAxisX;			//X�����
	int nAxisY;			//Y�����
	int nAxisZ;			//Z�����
	int nAxisA;			//A�����
	int nGasStartDelay;	//��������ʱ
	int nGasCloseDelay;	//�ؼ�����ʱ
	int nWav; //���κ�
}EntityInfoParam, *pEntityInfoParam;


typedef struct tagControlParam
{
	int nDeviceID;
	int nFuncID;
	int nCoordNum;
	int nNodeID;
	TCHAR szDocName[MAX_PATH];
	TCHAR szNodeName[MAX_PATH];
	void * pToolParam;
	pEntityInfoParam pEntityInfoParam;
}ControlParam, *pControlParam;




typedef int (WINAPI *fHWDO				 )(int, int, void*, void*);
typedef int (WINAPI *fGetIDNum			 )();
typedef int (WINAPI *fGetAllID			 )(int*);

extern fHWDO					HWDO;
extern fGetIDNum				GetIDNum;
extern fGetAllID				GetAllID;