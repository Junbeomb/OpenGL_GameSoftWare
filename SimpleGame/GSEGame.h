#pragma once
#include "GSEGlobal.h"
#include "Renderer.h"
#include "GSEObjectMgr.h"
#include "GSEUserInterface.h"

class GSEGame
{
public:

	GSEGame(int windowSizeX, int windowSizeY);
	~GSEGame();

	void DrawAll(float elapsedTime); 
	void KeyInput(GSEUserInterface* ui);

private:
	Renderer * m_Renderer;
	GSEObjectMgr* m_ObjectMgr;

	int m_HeroID = -1;
};

