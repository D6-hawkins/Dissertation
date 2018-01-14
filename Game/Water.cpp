#include "Water.h"

void Water::init(Vector3 _pos, GameData * _GD)
{
	//need to give them a body - need to find if they're getting drawn properly (probably not)
	SetPos(_pos);
	isAlive = true;
}

void Water::Tick(GameData * _GD) //Physics will happen in tick
{
	if (isAlive == true)
	{
		//Velocity track - higher velocity, less absorbtion

		//Absorbtion track - less water = slower velocity (maybe)

		//Direction track - need to calculate the correct direction to move

		//Collision track - for collision (need to set up collision for marching cubes)

		//Look into applying boid physics to water - Joining together when getting close, increasing mass and stuff
	}
}
