#pragma once
#include "VBGO.h"
#include "gridcell.h"
#include "GameData.h"
class TerrainSculptor : public VBGO
{
public:
	//Constructor and deconstructor
	TerrainSculptor();
	virtual ~TerrainSculptor() {};
	//-----------------------------
	//Init function to set base values
	void init(std::vector<GRIDCELL> gridVec, ID3D11Device* _GD);
	//--------------------------------------
	//Tick
	virtual void Tick(GameData* _GD) override;
	//--------------------------
	//Used to enable ticking when the river is completed
	void setTicking();
	//Used to tag the correct amount of grid sections to create hills
	void tagHill();
private:

	std::vector<GRIDCELL> gridVec;
	int tickCounter;
	bool ShouldBeTicking = false;
	int HillCounter;
	int HillTickCounter = 0;
};