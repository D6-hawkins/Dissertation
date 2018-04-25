#include "TerrainSculptor.h"

TerrainSculptor::TerrainSculptor()
{

}

void TerrainSculptor::init(std::vector<GRIDCELL> _gridVec, ID3D11Device * _GD)
{
	gridVec = _gridVec;
	tickCounter = 0;
	HillCounter = 0;
}

void TerrainSculptor::Tick(GameData * _GD)
{
	if (ShouldBeTicking == true)
	{
		//Initial faked tesselation
		if (tickCounter != 10)
		{
			for (int i = 0; i < gridVec.size()-1; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (gridVec[i].p[j]->getisEroding() == false)
					{
						gridVec[i].p[j]->Tick(_GD);
					}
				}
			}
			tickCounter++;
		}
		//Move onto forming mountains
		//Limit to only 4 mountains
		if (HillCounter >= 4)
		{
			if (HillTickCounter != 40)
			{
				for (int i = 0; i < gridVec.size()-1; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (gridVec[i].p[j]->getHill() == true)
						{
							gridVec[i].p[j]->Tick(_GD);
						}
					}
				}
				HillTickCounter++;
			}
		}
	}
	VBGO::Tick(_GD);
}

void TerrainSculptor::setTicking()
{
	ShouldBeTicking = true;
}

void TerrainSculptor::tagHill()
{
	int random = rand() % gridVec.size()-1 + 0;
	if (gridVec[random].p[1]->getisEroding() || gridVec[random].p[1]->getHill() == true)
	{
		tagHill();
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			gridVec[random].p[i]->isHill();
		}
		HillCounter++;
		if (HillCounter <= 12)
		{
			tagHill();
		}
	}
}
