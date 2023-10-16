#pragma once
#include "GSEObject.h"
#include "Renderer.h"

#define MAX_NUM_OBJECT 1000

class GSEObjectMgr
{

public:
	GSEObjectMgr();
	~GSEObjectMgr();
	int AddObject(float posX, float posY, float posZ, 
							float sizeX, float sizeY, float sizeZ,
							float mass,
							float velX, float velY, float velZ,
							float accX, float accY, float accZ,
							float forceX, float forceY, float forceZ);

	float m_sizeX, m_sizeY, m_sizeZ = 0.f;
	float m_posX, m_posY, m_posZ = 0.f;
	float m_mass;
	float m_velX, m_velY, m_velZ;
	float m_accX, m_accY, m_accZ;
	float m_forceX, m_forceY, m_forceZ = 0.f;


	bool DeleteObject(int id);
	void DrawAllObjects(Renderer* renderer, float elapsedTime);
	void UpdateAllObjects(float elapsedTime);

private:
	GSEObject* m_Objects[MAX_NUM_OBJECT];
};

