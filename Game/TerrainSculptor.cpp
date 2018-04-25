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
	if (ShouldBeTicking == true) //Ticking is disabled until this value is set to true so the river forms before this
	{
		//Initial ticking to stop the ground being completely flat
		if (tickCounter != 10) //Limit of 10 otherwise it would tick forever
		{
			for (int i = 0; i < gridVec.size()-1; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (gridVec[i].p[j]->getisEroding() == false) //So the river isn't changed
					{
						gridVec[i].p[j]->Tick(_GD);
					}
				}
			}
			tickCounter++;
		}
		//Move onto forming hills
		//Limit to only 12 hills
		if (HillCounter >= 12) //Waits until all hills are tagged
		{
			if (HillTickCounter != 40) //Ticks each hill a select number of times
			{
				for (int i = 0; i < gridVec.size()-1; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (gridVec[i].p[j]->getHill() == true) //Validates that the current gridVec member is a hill
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
	ShouldBeTicking = true; //this can be called by Water to start the terraforming
}

void TerrainSculptor::tagHill()
{
	int random = rand() % gridVec.size()-1 + 0;
	if (gridVec[random].p[1]->getisEroding() || gridVec[random].p[1]->getHill() == true) //If the this gridcell is part of the river or is already a hill call the function again
	{
		tagHill();
	}
	else //If it isn't the river or already a hill
	{
		for (int i = 0; i < 8; i++)
		{
			gridVec[random].p[i]->isHill(); //tag all contents as a hill
		}
		HillCounter++;
		if (HillCounter <= 12) //If more hills need to be tagged
		{
			tagHill(); //Call function again
		}
	}
}
