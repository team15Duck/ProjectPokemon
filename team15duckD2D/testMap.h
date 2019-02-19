#pragma once
#include "mapData.h"

class testMap : public mapData
{
private:
	
public:
	testMap();
	~testMap();


	virtual void setPokemon() override;

	void potalLoad() override;
	void fieldItemLoad() override;
};

