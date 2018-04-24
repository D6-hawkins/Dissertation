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
		if (gridVec[waterPosStart].p[i]->getStrength() <= 0)
		{
			moveGridNum();
		}
	}
	if (riverFormed == true)
	{
		if (tickCounter != 4)
		{
			for (int i = 0; i < gridVec.size(); i++)
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

void Water::moveGridNum()
{
	int randNum = rand() % 3 + 1;
	if (waterPosStart != gridVec.size()-1)
	{
		////if (randNum == 1) //MOVE FORWARD
		////{
		////	if (gridVec[waterPosStart].p[1]->GetPos().x == (gridVec[waterPosStart + 1].p[1]->GetPos().x))
		////	{
		////		waterPosStart++;
		////	}
		////}
		bool loopBool = true;
		if (counter == 2)
		{
			if (randNum == 2) //MOVE LEFT
			{
				//FIND WHICHEVER GRID IS ONE DOWN AND ONE LEFT //PROBABLY A BIG LOOP
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
				//call mountainmakerorsomething
			}
		}
	}
}