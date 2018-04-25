#include "Water.h"

Water::Water()
{
}

void Water::init(std::vector<GRIDCELL> _gridVec, ID3D11Device * GD, TerrainSculptor* _TS)
{
	TS = _TS;
	gridVec = _gridVec;
	getrandomGrid();
}

void Water::Tick(GameData * _GD) //Erosion is calculated during tick
{
	for (int i = 0; i < 8; i++)
	{
		gridVec[waterPosStart].p[i]->waterErode();
		if (gridVec[waterPosStart].p[i]->getStrength() <= 0) //If the current section is no longer being eroded
		{
			moveGridNum(); //Select new section
		}
	}
	if (riverFormed == true && terraformOn == false) //If the river has finished being formed
	{
		terraformOn = true;
		TS->tagHill();
		TS->setTicking();
	}
	VBGO::Tick(_GD);
}

float Water::getErode()
{
	return erodeVal;
}
void Water::getrandomGrid()
{
	int random = 100;
	if (gridVec[random].failed == true)
	{
		getrandomGrid();
	}
	else
	{
		waterPosStart = random;
	}
}

void Water::moveGridNum() //Decided which way the river will move
{
	int randNum = rand() % 3 + 1;
	if (waterPosStart != gridVec.size()-1)
	{
		bool loopBool = true;
		if (counter == 1)
		{
			if (randNum == 2) //MOVE LEFT
			{
				for (int j = 0; j < gridVec.size() && loopBool == true; j++)
				{
					if (gridVec[j].p[1]->GetPos().x == gridVec[waterPosStart].p[1]->GetPos().x - 1)
					{
						if (gridVec[j].p[1]->GetPos().y == gridVec[waterPosStart].p[1]->GetPos().y)
						{
							waterPosStart = j;
							loopBool = false;
						}
					}
				}
			}
			if (randNum == 3) //MOVE RIGHT
			{
				for (int j = 0; j < gridVec.size() && loopBool == true; j++)
				{
					if (gridVec[j].p[1]->GetPos().x == gridVec[waterPosStart].p[1]->GetPos().x + 1)
					{
						if (gridVec[j].p[1]->GetPos().y == gridVec[waterPosStart].p[1]->GetPos().y)
						{
							waterPosStart = j;
							loopBool = false;
						}
					}
				}
			}
			counter = 0;
		}
		else
		{
			if (gridVec[waterPosStart].p[1]->GetPos().x == (gridVec[waterPosStart + 1].p[1]->GetPos().x)) //Validation to stop erosion when it reaches the edge
			{
				if (loopBool != false)
				{
					waterPosStart++;
					counter++;
				}
			}
			else
			{
				counter = 0;
				riverFormed = true;
			}
		}
	}
}