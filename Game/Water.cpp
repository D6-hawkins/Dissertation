#include "Water.h"

Water::Water()
{
	//Vector3 tempPos = Vector3(0.0f, 60.0f, 0.0f);
	//SetPos(tempPos);
}

void Water::init(std::vector<GRIDCELL> gridVec, ID3D11Device * GD)
{
	////Vector3 tempPos = Vector3(10.0f, 40.0f, -10.0f);
	//SetPos(_pos);
	//isAlive = true;
	////bool grounded = false;
	//SetPhysicsOn(true);

}

void Water::Tick(GameData * _GD) //Physics will happen in tick
{
	/*fallSpeed = 50.0f * _GD->m_dt;
	if (isAlive == true)
	{
		if (grounded == false)
		{
			m_acc.y -= fallSpeed;
		}
		if (grounded == true)
		{
			m_vel.y = 0;
		}
	}*/
	VBGO::Tick(_GD);
}

float Water::getErode()
{
	return erodeVal;
}
