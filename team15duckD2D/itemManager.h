#pragma once
#include "gameNode.h"
#include "item.h"
#include <vector>
class itemManager : public gameNode
{
private:
	vector<item*> _vItems;	//�����۵�
	ITEM_TYPE _choiceItem;

public:
	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void initItems();



	// ========== GET & SET ==========
	vector<item*> getItems() { return _vItems; }

};

