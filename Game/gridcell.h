#ifndef _GRIDCELL_H_
#define _GRIDCELL_H_

#include <d3d11_1.h>
#include "SimpleMath.h"

using namespace DirectX;
using namespace SimpleMath;

typedef Vector3 XYZ;
typedef struct {
	XYZ p[8];
	double val[8];
} GRIDCELL;



#endif // !_GRIDCELL_H_
