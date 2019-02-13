#pragma once

//요거 속성별로 다 추가해주세요 이거 있으면 판단이 너무쉬워집니다
//2배로 더해주세요
#define TILE_SIZE	64
#define SAMPLETILE  6

#define ATTR_NONE			0x00000000UL					//NONE
#define ATTR_UNMOVE			0x00000001UL					//못움직임
#define ATTR_WALL			0X00000002UL					//벽
#define ATTR_WATER			0x00000004UL					//물
#define ATTR_FOREST			0x00000008UL					//숲
#define ATTR_TREE			0x00000010UL					//나무

#define ATTR_ROCK			0X00000020UL					//돌
#define ATTR_JUMP			0X00000040UL					//언덕에서 점프
#define ATTR_COMPUTER		0X00000080UL					//컴퓨터(센터/집)
#define ATTR_DOOR			0X00000100UL					//문
#define ATTR_CUT			0X00000200UL					//풀베기
#define ATTR_APPEAR			0X00000400UL					//풀(몬스터등장)
#define ATTR_OAK_MACHINE	0X00000800UL					//오박사기계
#define ATTR_BOOKCASE		0X00001000UL					//책장
#define ATTR_TIP			0X00002000UL					//팁게시판
#define ATTR_MAT			0X00004000UL					//발매트
#define ATTR_SINK			0X00008000UL					//싱크대
#define ATTR_PANTRY			0X00010000UL					//식기장
#define ATTR_GAME			0X00020000UL					//게임기
#define ATTR_STONE_STATUE	0X00040000UL					//석상
#define ATTR_STORE_STAND    0X00800000UL					//진열대(상점)
#define ATTR_STORE_DISPLAY  0X01000000UL					//진열대2(상점)
#define ATTR_MAP			0X02000000UL					//지도





///////// 어트리뷰트는 처음에 0으로 초기화하고 |= 이걸로 더해주세요
///////// 빼낼떄는 ^=



//타일 이미지 이름
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

//오브젝트 이미지 이름
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

	//TERRAIN_NAME_INFO terrainImageName;	//TERRAIN_NAME_NONE 으로 초기화
	UINT	terrainImageIndex;
	UINT	terrainFrameX;			//0으로 초기화
	UINT	terrainFrameY;			//0으로 초기화
	UINT	objectImageIndex;		//OBJECT_NAME_NONE 으로 초기화
	UINT	objectFrameX;			//0으로 초기화
	UINT	objectFrameY;			//0으로 초기화
	DWORD	attr;					//이건 ATTR_NONE으로 초기화 후에 시작합시다

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
//	//TERRAIN_NAME_INFO terrainImageName;	//TERRAIN_NAME_NONE 으로 초기화
//	UINT terrainFrameX;			//0으로 초기화
//	UINT terrainFrameY;			//0으로 초기화
//	string objectImageName;		//OBJECT_NAME_NONE 으로 초기화
//	UINT objectFrameX;			//0으로 초기화
//	UINT objectFrameY;			//0으로 초기화
//	DWORD attr;					//이건 ATTR_NONE으로 초기화 후에 시작합시다
//}TILE;

//타일의 포인터를 LPTILE이라고 하겠다
typedef struct tagTile *LPTILE;

