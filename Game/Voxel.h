#ifndef _VOXEL_H_
#define _VOXEL_H_

#include "VBGO.h"
#include <random>
//class GameData;
class Voxel : public VBGO
{
public:
	//Constructor and deconstructor
	Voxel(Vector3);
	virtual ~Voxel() {};
	//----------------------------
	//Tick function
	void Tick(GameData* _GD) override;
	//--------------------------------
	//Getters
	bool getHill() { return hill; };
	float getStrength() { return strength; };
	bool getisEroding() { return beingEroded; };
	//--------------------------------
	//Used for validation in different classes
	void waterErode();
	void isHill();
	//-----------------------
private:
	float strength;
	GameData* GD;
	bool beingEroded;
	bool wasEroded;
	bool hill;
};

#endif // !_VOXEL_H_
