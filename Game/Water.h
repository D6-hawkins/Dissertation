#ifndef _WATER_H_
#define _WATER_
#include "CMOGO.h"
#include "vertex.h"
#include "GameData.h"
class Water : public CMOGO
{
public:
	Water(string _fileName, ID3D11Device* _pd3dDevice, IEffectFactory* _EF);
	virtual ~Water() {};
	void init(Vector3 _pos, ID3D11Device* _GD);

	virtual void Tick(GameData* _GD) override;
	float getErode();
	void setGrounded(bool val) { grounded = val; };
	bool isGrounded() { return grounded; };
private:
	bool isAlive;
	float erodeVal = 1.0f;
	bool grounded;
	myVertex* m_vertices;
	float fallSpeed;
};

#endif