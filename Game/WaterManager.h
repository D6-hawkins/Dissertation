#ifndef  _WATER_MANAGER_H_
#define _WATER_MANAGER_H_
#include "VBGO.h"
#include <vector>
class Water;
class WaterManager : public VBGO
{
public:
	WaterManager() {};
	virtual ~WaterManager() {};
	void Init();


	virtual void Tick(GameData* _GD) override;
	virtual void Draw(DrawData* _DD) override;
private:
	std::vector<Water*> waterVec;
	float timerSec = 1.0f;
	float currentTime = 0.1f;
};
#endif // ! _WATER_MANAGER_H_
