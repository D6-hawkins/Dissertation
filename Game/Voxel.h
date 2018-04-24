#ifndef _VOXEL_H_
#define _VOXEL_H_

#include "VBGO.h"
#include <random>
//class GameData;
class Voxel : public VBGO
{
public:
	Voxel(Vector3);
	virtual ~Voxel() {};

	void Tick(GameData* _GD) override;
	float getStrength() { return strength; };
	void waterErode();
	bool getisEroding() { return beingEroded; };
private:
	float strength;
	GameData* GD;
	bool beingEroded;

};

#endif // !_VOXEL_H_
