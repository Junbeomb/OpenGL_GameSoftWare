#include "stdafx.h"
#include "GSEGame.h"
#include "math.h"

GSEGame::GSEGame(int windowSizeX, int windowSizeY)
{
	m_Renderer = new Renderer(windowSizeX, windowSizeY);

	m_ObjectMgr = new GSEObjectMgr();

	//create hero object

	m_HeroID = m_ObjectMgr->AddObject(0, 0,0,
		30, 30, 1.f,
		1,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		TYPE_HERO,
		2000,
		-1);

	//create test objects
	for (int i = 0; i < 10; ++i) {
		float x = (500.f * (float)rand() / (float)RAND_MAX) - 250.f;
		float y = (500.f * (float)rand() / (float)RAND_MAX) - 250.f;
		float z = 0;


		float sX = 50.f * (float)rand() / (float)RAND_MAX;
		float sY = 50.f * (float)rand() / (float)RAND_MAX;
		float sZ = 1.f;

		float mass =20.f;

		float velX = (10.f * (float)rand() / (float)RAND_MAX) - 5.f;
		float velY = (10.f * (float)rand() / (float)RAND_MAX) - 5.f;
		float velZ =0.f;

		float accX = 0.f;
		float accY = 0.f;
		float accZ = 0.f;
		
		float forceX = 0.f;
		float forceY = 0.f;
		float forceZ = 0.f;

		int id = m_ObjectMgr->AddObject(x, y, z,
			sX, sY, sZ,
			mass,
			velX, velY, velZ,
			accX, accY, accZ,
			forceX, forceY, forceZ,
			TYPE_DEFAULT,
			100,
			-1);

	}
}

GSEGame::~GSEGame()
{

	delete m_Renderer;
	m_Renderer = NULL;

	delete m_ObjectMgr;
	m_ObjectMgr = NULL;

}

void GSEGame::DrawAll(float elapsedTime)
{
	//objmgr
	if (m_Renderer != NULL) 
	{
		m_ObjectMgr->UpdateAllObjects(elapsedTime);
		m_ObjectMgr->DoGarbageCollect();
		m_ObjectMgr->DoAllObjectsOverlapTest();
		m_ObjectMgr->DrawAllObjects(m_Renderer, elapsedTime);
	}

	m_gameTime += elapsedTime;
}


void GSEGame::KeyInput(GSEUserInterface* ui, float elapsedTime)
{

	//characterMovement
	float x, y,z;
	x = y = z = 0.f;
	float forceAmount = 1000.f;
	if (ui->Is_SP_Arrow_Up_Down()) {
		y += forceAmount;
	}
	if (ui->Is_SP_Arrow_Down_Down()) {
		y -= forceAmount;
	}
	if (ui->Is_SP_Arrow_Right_Down()) {
		x += forceAmount;
	}
	if (ui->Is_SP_Arrow_Left_Down()) {
		x -= forceAmount;
	}

	m_ObjectMgr->AddObjectForce(m_HeroID, x, y, z, elapsedTime);

	if (ui->Is_Spacebar_Down()) {
		//bullet
		// 0. can hero shoot bullet(is cooltime expired?)
		bool canShoot = m_ObjectMgr->IsCooltimeExpired(m_HeroID);
		if (canShoot) {
			//1. get hero position
			float vx, vy, vz;
			float x, y, z;
			m_ObjectMgr->GetObjectPos(m_HeroID,&x, &y, &z);
			m_ObjectMgr->GetObjectVel(m_HeroID,&vx, &vy, &vz);

			//2. clac bullet velocity
			float mag = sqrtf(vx * vx + vy * vy);

			float bulletVX = 1.f;
			float bulletVY = 0.f;
			float bulletSpeed = 1000.f;
			float theta = m_gameTime * 10.f;

			float newBX = cos(theta) * bulletVX - sin(theta) * bulletVY;
			float newBY = sin(theta) * bulletVX + cos(theta) * bulletVY;

			newBX *= bulletSpeed;
			newBY *= bulletSpeed;

			m_ObjectMgr->AddObject(x, y, z,
				5, 5, 5,
				1,
				newBX, newBY, 0,
				0, 0, 0,
				0, 0, 0,
				TYPE_BULLET,
				40,
				m_HeroID);

			/*if (mag > FLT_EPSILON) {

				vx = vx / mag;
				vy = vy / mag;
				bulletVX = bulletSpeed * vx;
				bulletVY = bulletSpeed * vy;

				//3. add object (vel, pos)
				m_ObjectMgr->AddObject(x, y, z,
					20, 20, 10,
					1,
					bulletVX, bulletVY, 0,
					0, 0, 0,
					0, 0, 0,
					TYPE_BULLET);
			}*/

			m_ObjectMgr->ResetCooltime(m_HeroID);
			
		}

	}





}
