#pragma once
#include "mapData.h"

class oLabMap : public mapData
{
private:

public:
	oLabMap();
	~oLabMap();


	virtual void setPokemon() override;
	void potalLoad() override;
};

