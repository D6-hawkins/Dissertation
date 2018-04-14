#ifndef _GRIDCELL_H_
#define _GRIDCELL_H_

#include <d3d11_1.h>
#include "SimpleMath.h"
#include "Voxel.h"
#include <vector>
using namespace DirectX;
using namespace SimpleMath;

typedef Vector3 XYZ;
//typedef Voxel* Vox;
typedef struct {
	Voxel* p[8];
	double val[8];
	int size;
	bool beenChecked = false;
} GRIDCELL;



#endif // !_GRIDCELL_H_
