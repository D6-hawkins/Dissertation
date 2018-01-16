#include "Water.h"

Water::Water(string _fileName, ID3D11Device * _pd3dDevice, IEffectFactory * _EF) : CMOGO(_fileName, _pd3dDevice, _EF)
{
	Vector3 tempPos = Vector3(0.0f, 35.0f, 0.0f);
	SetPos(tempPos);
}

void Water::init(Vector3 _pos, ID3D11Device * GD)
{
	//Vector3 tempPos = Vector3(10.0f, 40.0f, -10.0f);
	//SetPos(tempPos);
	isAlive = true;
	bool grounded = false;
	SetPhysicsOn(true);
}

void Water::Tick(GameData * _GD) //Physics will happen in tick
{
	fallSpeed = 50.0f * _GD->m_dt;
	if (isAlive == true)
	{
		if (grounded == false)
		{
			m_acc.y -= fallSpeed;
		}
		if (grounded == true)
		{
			m_acc = Vector3(0.0f, 0.0f, 0.0f);
		}
	}
	CMOGO::Tick(_GD);
}

float Water::getErode()
{
	return erodeVal;
}
