#include "WaterManager.h"
#include "GameData.h"
#include "Water.h"
#include <list>
#include <iterator>
#include "Terrain.h"
void WaterManager::Init(Terrain* Terr, string model, ID3D11Device* _device, IEffectFactory* _effects)
{
	GD = _device;
	terrStore = Terr;
	modelStore = model;
	_effect = _effects;
}

void WaterManager::Tick(GameData * _GD)
{
	//Spawn Water
	if (GetKeyState(VK_LBUTTON) & 0x100 && currentTime >= timerSec)
	{
		currentTime = 0.5f;
		Vector3 MousePos = Vector3(_GD->m_mouseState->lX, _GD->m_mouseState->lY, _GD->m_mouseState->lZ);
		Water* water = new Water(modelStore, GD, _effect);
		water->init(MousePos, GD);
		waterVec.push_back(water);
	}
	currentTime += currentTime * _GD->m_dt;
	//-----
	for (int i = 0; i != waterVec.size(); i++)
	{
			//Bounding box for collision test with terrain
		if ((waterVec[i]->GetPos().x + waterVec[i]->GetScale().x) >= terrStore->GetPos().x
		&& waterVec[i]->GetPos().x <= (terrStore->GetPos().x + terrStore->getSize().x)
		&& (waterVec[i]->GetPos().y + waterVec[i]->GetScale().y) >= terrStore->GetPos().y 
		&&	waterVec[i]->GetPos().y <= (terrStore->GetPos().y + terrStore->getSize().y)
		&& (waterVec[i]->GetPos().z + waterVec[i]->GetScale().z) >= terrStore->GetPos().z
		&& (waterVec[i]->GetPos().z <= (terrStore->GetPos().z + terrStore->getSize().z)))
			{
				waterVec[i]->setGrounded(true); //If colliding with ground
			}
			else
			{
				waterVec[i]->setGrounded(false); //if not colliding
			}
		//Physics checks for water

		//Velocity track - higher velocity, less absorbtion

		//Absorbtion track - less water = slower velocity (maybe)

		//Direction track - need to calculate the correct direction to move

		//Collision track - for collision (need to set up collision for marching cubes)

		//Look into applying boid physics to water - Joining together when getting close, increasing mass and stuff
	}
	//Tick each water
	for (int i = 0; i != waterVec.size(); i++)
	{
		waterVec[i]->Tick(_GD);
	}
	//----
}

void WaterManager::Draw(DrawData * _DD)
{
	for (int i = 0; i != waterVec.size(); i++)
	{
		waterVec[i]->Draw(_DD);
	}
}

void WaterManager::setDevice(ID3D11Device* device)
{
	GD = device;
}
