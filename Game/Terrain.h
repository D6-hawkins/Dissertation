#ifndef _TERRAIN_H_
#define _TERRAIN_H_
#include "VBGO.h"
#include "gridcell.h"
#include <vector>
#include "vertex.h"
#include "DrawData.h"
#include <thread>
class Voxel;
typedef Vector3 XYZ;
typedef struct {
	XYZ p[3];
} TRIANGLE;
class Terrain : public VBGO
{
public:
	//Constructor and deconstructor
	Terrain() {};
	virtual ~Terrain() {};
	//-----------------------------
	//Init functions to set the correct values and build the initial terrain
	void Init(float isolevel, Vector3 _origin, Vector3 _size, Vector3 _scale, ID3D11Device* _GD);
	void Init(Vector3 _min, Vector3 _max, float _isolevel, Vector3 _size, ID3D11Device* _GD);
	//----------------------------------
	//Tick and Draw
	void Tick(GameData* _GD) override;
	void Draw(DrawData* _DD) override;
	//--------------------------------
	//Getters
	std::vector<GRIDCELL> getGridVec() { return gridVec; };
	std::vector<myVertex> getvert() { return m_vertices; };
	//---------------------------
	//Functions used to create the terrain
	void seamlessMesh(int startNum, int endNum);
	void terrainBuilder(Vector3 _origin, Vector3 _size, Vector3 _scale);
	void gapFiller(std::vector<int> gapVec, int);
	void meshThreadGen();
	//-------------------------------------
protected:
	std::vector <GRIDCELL> gridVec; //Vector that holds all grid locations
	int numOfThreads;
	std::vector<int> gaps; //Holds all last grid sections that were created, these would not have been connected correctly
	float m_isolevel;
	TRIANGLE m_Triangles[5];
	std::vector<myVertex> m_vertices; //Holds the vertices
	float PosChanger(Vector3 _pos, int i); //Used to return a value used in the marching cubes algorithm
	Vector3 m_origin;
	ID3D11Device* dev;
	D3D11_BUFFER_DESC bd;
	D3D11_SUBRESOURCE_DATA InitData;
	HRESULT hr = S_OK;
	int counter = 0;
	ID3D11Device* _GDStore;
	int* indices;
	int startVal;
	int startValRem;
};

#endif