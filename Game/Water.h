#ifndef _WATER_H_
#define _WATER_
#include "VBGO.h"
#include "vertex.h"
#include "GameData.h"
#include <vector>
#include "gridcell.h"
#include "Terrain.h"
#include "TerrainSculptor.h"
class Water : public VBGO
{
public:
	Water();
	virtual ~Water() {};
	void init(std::vector<GRIDCELL> gridVec, ID3D11Device* _GD, TerrainSculptor* _TS);

	virtual void Tick(GameData* _GD) override;
	float getErode();
	void setGrounded(bool val) { grounded = val; };
	bool isGrounded() { return grounded; };
	void getrandomGrid();
	void moveGridNum();
private:
	TerrainSculptor* TS;
	int counter = 0;
	int waterPosStart;
	std::vector<GRIDCELL> gridVec;
	bool isAlive;
	float erodeVal = 1.0f;
	bool grounded;
	myVertex* m_vertices;
	float fallSpeed;
	bool riverFormed = false;
	int tickCounter = 0;
	bool terraformOn = false;
};

#endif