#ifndef _TERRAIN_H_
#define _TERRAIN_H_
#include "VBGO.h"
#include "gridcell.h"
#include <vector>
#include <fstream>
#include <math.h>
#include "vertex.h"
class Terrain : public VBGO
{
public:
	Terrain() {};
	virtual ~Terrain() {};

	void Init(float isolevel, Vector3 _origin, Vector3 _size, Vector3 _scale, ID3D11Device* _GD);
	void Init(Vector3 _min, Vector3 _max, float _isolevel, Vector3 _size, ID3D11Device* _GD);
	void Tick(GameData* _GD) override;
	GRIDCELL getGrid() { return m_Grid; };
	Vector3 getScale() { return m_scale; };
	Vector3 getSize() { return m_size; };
	std::vector<myVertex> getvert() { return m_vertices; };
protected:
	std::vector<myVertex> m_vertices;
	float PosChanger(Vector3 _pos, int i);
	Vector3 m_origin;
	GRIDCELL m_Grid;
	Vector3 m_scale;
	Vector3 m_size;
};

#endif