#pragma once
#include "VBGO.h"
#include "gridcell.h"
#include "GameData.h"
class TerrainSculptor : public VBGO
{
public:
	TerrainSculptor();
	virtual ~TerrainSculptor() {};
	void init(std::vector<GRIDCELL> gridVec, ID3D11Device* _GD);
	virtual void Tick(GameData* _GD) override;
	void setTicking();
	void tagHill();
private:

	std::vector<GRIDCELL> gridVec;
	int tickCounter;
	bool ShouldBeTicking = false;
	int HillCounter;
	int HillTickCounter = 0;
};