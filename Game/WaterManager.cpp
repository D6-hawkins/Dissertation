#include "WaterManager.h"
#include "GameData.h"
#include "Water.h"
#include <list>
#include <iterator>
#include "Terrain.h"
#include "camera.h"
void WaterManager::Init(std::vector<GRIDCELL> Terr, string model, ID3D11Device* _device, IEffectFactory* _effects, Camera* m_cam)
{
	GD = _device;
	gridVecStore = Terr;
	modelStore = model;
	_effect = _effects;
	m_camStore = m_cam;
}

void WaterManager::Tick(GameData * _GD)
{
	//Spawn Water
	if (GetKeyState(VK_LBUTTON) & 0x100 && currentTime >= timerSec)
	{
		currentTime = 0.5f;
		Vector3 MousePos = Vector3(10,30,-20); //= Vector3(_GD->m_mouseState->lX, _GD->m_mouseState->lY, _GD->m_mouseState->lZ);
		//Vector3 worldPos;
		//worldPos.Transform(Vector3(_GD->m_mouseState->lX, _GD->m_mouseState->lY, _GD->m_mouseState->lZ), m_camStore->GetView());
		Water* water = new Water();
		//water->init(MousePos, GD);
		waterVec.push_back(water);
	}
	currentTime += currentTime * _GD->m_dt;
	//-----
	for (int i = 0; i != waterVec.size(); i++)
	{
	//		//Bounding box for collision test with terrain
	//	/*if ((waterVec[i]->GetPos().x + waterVec[i]->GetScale().x) >= terrStore->GetPos().x
	//	&& waterVec[i]->GetPos().x <= (terrStore->GetPos().x + terrStore->getScale().x)
	//	&& (waterVec[i]->GetPos().y + waterVec[i]->GetScale().y) >= terrStore->GetPos().y 
	//	&&	waterVec[i]->GetPos().y <= (terrStore->GetPos().y + terrStore->getScale().y)
	//	&& (waterVec[i]->GetPos().z + waterVec[i]->GetScale().z) >= terrStore->GetPos().z
	//	&& (waterVec[i]->GetPos().z <= (terrStore->GetPos().z + terrStore->getScale().z)))*/
		//for (int j = 0; j != terrStore->getvert().size(); j++)
		//{
		//	if ((waterVec[i]->GetPos().x + waterVec[i]->GetScale().x) >= terrStore->getvert()[j].Pos.x
		//		&& waterVec[i]->GetPos().x <= (terrStore->GetPos().x + terrStore->getScale().x)
		//		&& (waterVec[i]->GetPos().y + waterVec[i]->GetScale().y) >= terrStore->getvert()[j].Pos.y
		//		&&	waterVec[i]->GetPos().y <= (terrStore->GetPos().y + terrStore->getScale().y)
		//		&& (waterVec[i]->GetPos().z + waterVec[i]->GetScale().z) >= terrStore->getvert()[j].Pos.z
		//		&& (waterVec[i]->GetPos().z <= (terrStore->GetPos().z + terrStore->getScale().z)))
		//		{
		//			waterVec[i]->setGrounded(true); //If colliding with ground
		//		}
		//		else
		//		{
		//			waterVec[i]->setGrounded(false); //if not colliding
		//		}
		//}
		//for (int j = 0; j != gridVecStore.size(); j++)
		//{
		//	for (int r = 0; r < 8; r++)
		//	{
		//		if ((waterVec[i]->GetPos().x + waterVec[i]->GetScale().x) >= gridVecStore[j].p[r]->GetPos().x
		//			&& waterVec[i]->GetPos().x <= (gridVecStore[j].p[r]->GetPos().x)
		//			&& (waterVec[i]->GetPos().y + waterVec[i]->GetScale().y) >= gridVecStore[j].p[r]->GetPos().y
		//			&&	waterVec[i]->GetPos().y <= (gridVecStore[j].p[r]->GetPos().y)
		//			&& (waterVec[i]->GetPos().z + waterVec[i]->GetScale().z) >= gridVecStore[j].p[r]->GetPos().z
		//			&& (waterVec[i]->GetPos().z <= (gridVecStore[j].p[r]->GetPos().z)))
		//		{
		//			waterVec[i]->setGrounded(true); //If colliding with ground
		//		}
		//		else
		//		{
		//			waterVec[i]->setGrounded(false); //if not colliding
		//		}
		//	}
		//}
	//	
	//	//Physics checks for water

	//	//Velocity track - higher velocity, less absorbtion

	//	//Absorbtion track - less water = slower velocity (maybe)

	//	//Direction track - need to calculate the correct direction to move

	//	//Collision track - for collision (need to set up collision for marching cubes)

	//	//Look into applying boid physics to water - Joining together when getting close, increasing mass and stuff
	}
	////Tick each water
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
