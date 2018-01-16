#ifndef  _WATER_MANAGER_H_
#define _WATER_MANAGER_H_
#include "VBGO.h"
#include "CMOGO.h"
#include <vector>
class Water;
class Terrain;
class WaterManager : public VBGO
{
public:
	WaterManager() {};
	virtual ~WaterManager() {};
	void Init(Terrain* Terr, string model, ID3D11Device*_pd3dDevice, IEffectFactory* m_fxFactory);


	virtual void Tick(GameData* _GD) override;
	virtual void Draw(DrawData* _DD) override;
	void setDevice(ID3D11Device*);
private:
	string modelStore;
	IEffectFactory* _effect;
	std::vector<Water*> waterVec;
	float timerSec = 1.0f;
	float currentTime = 0.1f;
	ID3D11Device* GD;
	Terrain* terrStore;
};
#endif // ! _WATER_MANAGER_H_