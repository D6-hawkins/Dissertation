#ifndef _GRIDCELL_H_
#define _GRIDCELL_H_

#include <d3d11_1.h>
#include "SimpleMath.h"
#include "Voxel.h"
#include <vector>
using namespace DirectX;
using namespace SimpleMath;

typedef Vector3 XYZ;
typedef struct {
	Voxel* p[8];
	double val[8];
	int size;
	bool failed = false;
} GRIDCELL;



#endif // !_GRIDCELL_H_
//Struct originally from Marching cubes algorithm - http://paulbourke.net/geometry/polygonise/
//heavily modified - the only part left from the original struct is double val[8];
//This struct is used to create each gridcell member with the same information, linked to the Voxel
//gameobject to allow me to tick through the voxels moving them, moving the actual grid