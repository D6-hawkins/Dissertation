#include "Water.h"

Water::Water()
{
	//Vector3 tempPos = Vector3(0.0f, 60.0f, 0.0f);
	//SetPos(tempPos);
}

void Water::init(std::vector<GRIDCELL> _gridVec, ID3D11Device * GD)
{
	gridVec = _gridVec;
	getrandomGrid();
}

void Water::Tick(GameData * _GD) //Physics will happen in tick
{
	//waterPosStart = rand() % gridVec.size() + 0;
	for (int i = 0; i < 8; i++)
	{
		gridVec[waterPosStart].p[i]->waterErode();
		gridVec[waterPosStart].p[i]->Tick(_GD);
	}
	VBGO::Tick(_GD);
}

float Water::getErode()
{
	return erodeVal;
}
void Water::getrandomGrid()
{
	int random = rand() % gridVec.size() + 0;
	if (gridVec[random].failed == true)
	{
		getrandomGrid();
	}
	else
	{
		waterPosStart = random;
	}
}