#ifndef _CONSTBUFFER_H_
#define _CONSTBUFFER_H_

//=================================================================
//constant buffer for the base shader used for the VBGO renderer
//=================================================================

#include <windows.h>
#include <d3d11.h>
#include <SimpleMath.h>

using namespace DirectX;
using namespace SimpleMath;

//as passing to GPU needs to be correctly memory aligned

_declspec(align(16)) struct ConstantBuffer
{
	Matrix	world;
	Matrix	view;
	Matrix	projection;
	Matrix	rot;
	Color	lightCol;
	Color	ambientCol;
	Vector3 lightPos;

	void* operator new(size_t i)
	{
		return _mm_malloc(i, 16);
	}

	void operator delete(void* p)
	{
		_mm_free(p);
	}
};
#endif