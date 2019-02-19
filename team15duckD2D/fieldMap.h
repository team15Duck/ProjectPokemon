#pragma once
#include "mapData.h"

class fieldMap : public mapData
{
private:

public:
	fieldMap();
	~fieldMap();


	virtual void setPokemon() override;
	void potalLoad() override;
	void fieldItemLoad() override;
};

