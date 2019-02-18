#pragma once
#include "mapData.h"

class townMap : public mapData
{
private:

public:
	townMap();
	~townMap();


	virtual void setPokemon() override;
	void potalLoad() override;
};
