#pragma once

//��� �Ӽ����� �� �߰����ּ��� �̰� ������ �Ǵ��� �ʹ��������ϴ�
//2��� �����ּ���
#define TILE_SIZE	64
#define SAMPLETILE  6

#define ATTR_NONE			0x00000000UL					//NONE
#define ATTR_UNMOVE			0x00000001UL					//��������
#define ATTR_WALL			0X00000002UL					//��
#define ATTR_WATER			0x00000004UL					//��
#define ATTR_FOREST			0x00000008UL					//��
#define ATTR_TREE			0x00000010UL					//����

#define ATTR_ROCK			0X00000020UL					//��
#define ATTR_JUMP			0X00000040UL					//������� ����
#define ATTR_COMPUTER		0X00000080UL					//��ǻ��(����/��)
#define ATTR_DOOR			0X00000100UL					//��
#define ATTR_CUT			0X00000200UL					//Ǯ����
#define ATTR_APPEAR			0X00000400UL					//Ǯ(���͵���)
#define ATTR_OAK_MACHINE	0X00000800UL					//���ڻ���
#define ATTR_BOOKCASE		0X00001000UL					//å��
#define ATTR_TIP			0X00002000UL					//���Խ���
#define ATTR_MAT			0X00004000UL					//�߸�Ʈ
#define ATTR_SINK			0X00008000UL					//��ũ��
#define ATTR_PANTRY			0X00010000UL					//�ı���
#define ATTR_GAME			0X00020000UL					//���ӱ�
#define ATTR_STONE_STATUE	0X00040000UL					//����
#define ATTR_STORE_STAND    0X00800000UL					//������(����)
#define ATTR_STORE_DISPLAY  0X01000000UL					//������2(����)
#define ATTR_MAP			0X02000000UL					//����





///////// ��Ʈ����Ʈ�� ó���� 0���� �ʱ�ȭ�ϰ� |= �̰ɷ� �����ּ���
///////// �������� ^=



//Ÿ�� �̹��� �̸�
//static string TERRAIN_NAME_NONE = "";
//static string TERRAIN_NAME1		= "tile_01";
//static string TERRAIN_NAME2		= "tile_02";
//static string TERRAIN_NAME3		= "tile_03";
//static string TERRAIN_NAME4		= "tile_04";
//static string TERRAIN_NAME5		= "tile_05";
//static string TERRAIN_NAME6		= "tile_06";
//static string TERRAIN_NAME7		= "tile_07";
//static string TERRAIN_NAME8		= "tile_08";
//static string TERRAIN_NAME9		= "tile_09";
//static string TERRAIN_NAME10	= "tile_10";
//static string TERRAIN_NAME11	= "tile_11";

//������Ʈ �̹��� �̸�
//static string OBJECT_NAME_NONE	= "";
//static string OBJECT_NAME1		= "object_01";
//static string OBJECT_NAME2		= "object_02";
//static string OBJECT_NAME3		= "object_03";
//static string OBJECT_NAME4		= "object_04";
//static string OBJECT_NAME5		= "object_05";
//static string OBJECT_NAME6		= "object_06";
//static string OBJECT_NAME7		= "object_07";
//static string OBJECT_NAME8		= "object_08";
//static string OBJECT_NAME9		= "object_09";
//static string OBJECT_NAME10		= "object_10";
//static string OBJECT_NAME11		= "object_11";
//static string OBJECT_NAME12		= "object_12";
//static string OBJECT_NAME13		= "object_13";
//static string OBJECT_NAME14		= "object_14";
//static string OBJECT_NAME15		= "object_15";
//static string OBJECT_NAME16		= "object_16";
//static string OBJECT_NAME17		= "object_17";
//static string OBJECT_NAME18		= "object_18";

enum TERRAIN_NAME_INFO
{
	TERRAIN_NAME_NONE,
	TERRAIN_NAME1	 ,
	TERRAIN_NAME2	 ,
	TERRAIN_NAME3	 ,
	TERRAIN_NAME4	 ,
	TERRAIN_NAME5	 ,
	TERRAIN_NAME6	 ,
	TERRAIN_NAME7	 ,
	TERRAIN_NAME8	 ,
	TERRAIN_NAME9	 ,
	TERRAIN_NAME10	 ,
	TERRAIN_NAME11	 ,

	TERRAIN_NAME_COUNT
};
enum OBJECT_NAME_INFO
{
	OBJECT_NAME_NONE,
	OBJECT_NAME1	,
	OBJECT_NAME2	,
	OBJECT_NAME3	,
	OBJECT_NAME4	,
	OBJECT_NAME5	,
	OBJECT_NAME6	,
	OBJECT_NAME7	,
	OBJECT_NAME8	,
	OBJECT_NAME9	,
	OBJECT_NAME10	,
	OBJECT_NAME11	,
	OBJECT_NAME12	,
	OBJECT_NAME13	,
	OBJECT_NAME14	,
	OBJECT_NAME15	,
	OBJECT_NAME16	,
	OBJECT_NAME17	,

	OBJECT_NAME_COUNT
};

static string TERRAIN_NAME[TERRAIN_NAME_COUNT] = { "none","tile_01" ,"tile_02" ,"tile_03" ,"tile_04" ,"tile_05" ,"tile_06" ,"tile_07" ,"tile_08" ,"tile_09", "tile_10", "tile_11" };
static string OBJECT_NAME[OBJECT_NAME_COUNT] = { "none", "object_01", "object_02", "object_03", "object_04", "object_05", "object_06", "object_07", "object_08", "object_09",
												 "object_10", "object_11", "object_12", "object_13", "object_14", "object_15", "object_16", "object_17"};



typedef class tagTile
{
public:
	tagTile()  :terrainImageIndex	(NULL),
				objectImageIndex	(NULL),
				terrainFrameX		(NULL),
				terrainFrameY		(NULL),
				objectFrameX		(NULL),
				objectFrameY		(NULL),
				attr				(NULL) 
	{};
	~tagTile()
	{};

	//TERRAIN_NAME_INFO terrainImageName;	//TERRAIN_NAME_NONE ���� �ʱ�ȭ
	UINT	terrainImageIndex;
	UINT	terrainFrameX;			//0���� �ʱ�ȭ
	UINT	terrainFrameY;			//0���� �ʱ�ȭ
	UINT	objectImageIndex;		//OBJECT_NAME_NONE ���� �ʱ�ȭ
	UINT	objectFrameX;			//0���� �ʱ�ȭ
	UINT	objectFrameY;			//0���� �ʱ�ȭ
	DWORD	attr;					//�̰� ATTR_NONE���� �ʱ�ȭ �Ŀ� �����սô�

	void setTile(tagTile tile)
	{
		if(tile.terrainImageIndex > 0)
			terrainImageIndex = tile.terrainImageIndex;
		terrainFrameX = tile.terrainFrameX;
		terrainFrameY = tile.terrainFrameY;
		if (tile.objectImageIndex > 0)
			objectImageIndex = tile.objectImageIndex;
		objectFrameX = tile.objectFrameX;
		objectFrameY = tile.objectFrameY;
		attr = tile.attr;
	}

}TILE;



//typedef struct tagTile
//{
//	string terrainImageName;
//	//TERRAIN_NAME_INFO terrainImageName;	//TERRAIN_NAME_NONE ���� �ʱ�ȭ
//	UINT terrainFrameX;			//0���� �ʱ�ȭ
//	UINT terrainFrameY;			//0���� �ʱ�ȭ
//	string objectImageName;		//OBJECT_NAME_NONE ���� �ʱ�ȭ
//	UINT objectFrameX;			//0���� �ʱ�ȭ
//	UINT objectFrameY;			//0���� �ʱ�ȭ
//	DWORD attr;					//�̰� ATTR_NONE���� �ʱ�ȭ �Ŀ� �����սô�
//}TILE;

//Ÿ���� �����͸� LPTILE�̶�� �ϰڴ�
typedef struct tagTile *LPTILE;

