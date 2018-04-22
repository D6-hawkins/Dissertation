#ifndef _TERRAIN_H_
#define _TERRAIN_H_
#include "VBGO.h"
#include "gridcell.h"
#include <vector>
#include <fstream>
#include <math.h>
#include "vertex.h"
#include "DrawData.h"
#include <mutex>
#include <thread>
class Voxel;
typedef Vector3 XYZ;
typedef struct {
	XYZ p[3];
} TRIANGLE;
class Terrain : public VBGO
{
public:
	Terrain() {};
	virtual ~Terrain() {};

	void Init(float isolevel, Vector3 _origin, Vector3 _size, Vector3 _scale, ID3D11Device* _GD);
	void Init(Vector3 _min, Vector3 _max, float _isolevel, Vector3 _size, ID3D11Device* _GD);
	void Tick(GameData* _GD) override;
	//void Draw(DrawData* _DD) override;
	void Remake();
	GRIDCELL getGrid() { return m_Grid; };
	std::vector<GRIDCELL> getGridVec() { return gridVec; };
	Vector3 getScale() { return m_scale; };
	Vector3 getSize() { return m_size; };
	std::vector<myVertex> getvert() { return m_vertices; };
	void seamlessMesh();
	//void Sorter(std::vector <GRIDCELL>);
	void terrainBuilder(Vector3 _origin, Vector3 _size, Vector3 _scale);
protected:
	float m_isolevel;
	TRIANGLE m_Triangles[5];
	std::vector<myVertex> m_vertices;
	float PosChanger(Vector3 _pos, int i);
	Vector3 m_origin;
	GRIDCELL m_Grid;
	Vector3 m_scale;
	Vector3 m_size;
	ID3D11Device* dev;
	std::vector <GRIDCELL> gridVec;
	std::vector <Voxel*> holderVec;
	int testCount = 0;
	D3D11_BUFFER_DESC bd;
	D3D11_SUBRESOURCE_DATA InitData;
	HRESULT hr = S_OK;
	int counter = 0;
	std::mutex m;
	//std::thread t;
	//std::thread m;
};

#endif