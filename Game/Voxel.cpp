#include "Voxel.h"
#include "GameData.h"

Voxel::Voxel(Vector3 _pos)
{
	SetPos(_pos);
	//SetPhysicsOn(true);
	int ranStren = rand() % 10 + 1;
}

void Voxel::Tick(GameData * _GD)
{
	float z = GetPos().z;
	float y = GetPos().y;
	float x = GetPos().x;
	int randNum = rand() % 2 + 1;
	switch (randNum) 
	{
	case 1: z -= 0.06f; break;
	case 2: z += 0.07f; break;
	//case 3: y -= 0.04f; break;
	//case 4: y += 0.04f; break;
	//case 5: x -= 0.04f; break;
	//case 6: x += 0.04f; break;

	}
	Vector3 pos = Vector3(x, y, z);
	SetPos(pos);


	Matrix  scaleMat = Matrix::CreateScale(m_scale);
	m_rotMat = Matrix::CreateFromYawPitchRoll(m_yaw, m_pitch, m_roll); //possible not the best way of doing this!
	Matrix  transMat = Matrix::CreateTranslation(pos);

	m_worldMat = m_fudge * scaleMat * m_rotMat * transMat;
	VBGO::Tick(_GD);
}
