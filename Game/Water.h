#ifndef _WATER_H_
#define _WATER_
#include "VBGO.h"
#include "vertex.h"
#include "GameData.h"
#include <vector>
#include "gridcell.h"
#include "Terrain.h"
class Water : public VBGO
{
public:
	Water();
	virtual ~Water() {};
	void init(std::vector<GRIDCELL> gridVec, ID3D11Device* _GD);

	virtual void Tick(GameData* _GD) override;
	float getErode();
	void setGrounded(bool val) { grounded = val; };
	bool isGrounded() { return grounded; };
	void getrandomGrid();
private:
	int waterPosStart;
	std::vector<GRIDCELL> gridVec;
	bool isAlive;
	float erodeVal = 1.0f;
	bool grounded;
	myVertex* m_vertices;
	float fallSpeed;
};

#endif