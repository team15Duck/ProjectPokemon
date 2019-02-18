#pragma once
#include "mapData.h"

class centerMap : public mapData
{
private:

public:
	centerMap();
	~centerMap();


	virtual void setPokemon() override;
	void potalLoad() override;
};

