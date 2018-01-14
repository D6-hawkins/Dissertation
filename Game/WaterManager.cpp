#include "WaterManager.h"
#include "GameData.h"
#include "Water.h"
#include <list>
#include <iterator>
void WaterManager::Init()
{
}

void WaterManager::Tick(GameData * _GD)
{
	if (GetKeyState(VK_LBUTTON) & 0x100 && currentTime >= timerSec)
	{
		currentTime = 0.5f;
		Vector3 MousePos = Vector3(_GD->m_mouseState->lX, _GD->m_mouseState->lY, _GD->m_mouseState->lZ);
		Water* water = new Water();
		water->init(MousePos, _GD);
		waterVec.push_back(water);
	}
	for (int i = 0; i != waterVec.size(); i++)
	{
		waterVec[i]->Tick(_GD);
	}
	currentTime += currentTime * _GD->m_dt;
}

void WaterManager::Draw(DrawData * _DD)
{
	for (int i = 0; i != waterVec.size(); i++)
	{
		waterVec[i]->Draw(_DD);
	}
}
