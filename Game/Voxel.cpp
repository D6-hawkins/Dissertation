#include "Voxel.h"
#include "GameData.h"

Voxel::Voxel(Vector3 _pos)
{
	SetPos(_pos);
	//SetPhysicsOn(true);
}

void Voxel::Tick(GameData * _GD)
{
	//float z = GetPos().z;
	//float y = GetPos().y;
	//float x = GetPos().x;
	//int randNum = rand() % 6 + 1;
	//switch (randNum) 
	//{
	//	/*case 1: z -= 0.02f;
	//	case 2: z += 0.02f;*/
	//	case 3: y -= 0.04f;
	//	case 4: y += 0.04f;
	//	case 5: x -= 0.04f;
	//	case 6: x += 0.04f;

	//}
	//Vector3 pos = Vector3(x, y, z);
	//SetPos(pos);


	//Matrix  scaleMat = Matrix::CreateScale(m_scale);
	//m_rotMat = Matrix::CreateFromYawPitchRoll(m_yaw, m_pitch, m_roll); //possible not the best way of doing this!
	//Matrix  transMat = Matrix::CreateTranslation(pos);

	//m_worldMat = m_fudge * scaleMat * m_rotMat * transMat;
	VBGO::Tick(_GD);
}