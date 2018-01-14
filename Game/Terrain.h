#ifndef _TERRAIN_H_
#define _TERRAIN_H_
#include "VBGO.h"


class Terrain : public VBGO
{
public:
	Terrain() {};
	virtual ~Terrain() {};

	void Init(float isolevel, Vector3 _origin, Vector3 _size, Vector3 _scale, ID3D11Device* _GD);
	void Init(Vector3 _min, Vector3 _max, float _isolevel, Vector3 _size, ID3D11Device* _GD);
	void Tick(GameData* _GD) override;
protected:
	float PosChanger(Vector3 _pos, int i);
	Vector3 m_origin;
};

#endif