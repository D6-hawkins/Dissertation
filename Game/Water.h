#ifndef _WATER_H_
#define _WATER_
#include "VBGO.h"
class Water : public VBGO
{
public:
	Water() {};
	virtual ~Water() {};
	void init(Vector3 _pos, GameData* _GD);

	virtual void Tick(GameData* _GD) override;
private:
	bool isAlive;
};

#endif