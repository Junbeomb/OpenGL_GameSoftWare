#include "stdafx.h"
#include "GSEUserInterface.h"

GSEUserInterface::GSEUserInterface()
{
	m_SP_Arrow_Up = false;
	m_SP_Arrow_Down = false;
	m_SP_Arrow_Left = false;
	m_SP_Arrow_Right = false;
}

GSEUserInterface::~GSEUserInterface()
{
}

void GSEUserInterface::KeyDown(char key, int id)
{
	switch (key)
	{
	default:
		break;
	}
	switch (id)
	{
	case 100://SP_Key_Left
		m_SP_Arrow_Left = true;
		break;
	case 101://SP_Key_Up
		m_SP_Arrow_Up = true;
		break;
	case 102://SP_Key_Right
		m_SP_Arrow_Right= true;
		break;
	case 103://SP_Key_Down
		m_SP_Arrow_Down = true;
		break;
	default:
		break;
	}

	std::cout << m_SP_Arrow_Left << std::endl;

}

void GSEUserInterface::KeyUp(char key, int id)
{

	switch (key)
	{
	default:
		break;
	}
	switch (id)
	{
	case 100://SP_Key_Left
		m_SP_Arrow_Left = false;
		break;
	case 101://SP_Key_Up
		m_SP_Arrow_Up = false;
		break;
	case 102://SP_Key_Right
		m_SP_Arrow_Right = false;
		break;
	case 103://SP_Key_Down
		m_SP_Arrow_Down = false;
		break;
	default:
		break;

	}
}

bool GSEUserInterface::Is_SP_Arrow_Up_Down()
{
	return m_SP_Arrow_Up;
}

bool GSEUserInterface::Is_SP_Arrow_Down_Down()
{
	return m_SP_Arrow_Down;
}

bool GSEUserInterface::Is_SP_Arrow_Left_Down()
{
	return m_SP_Arrow_Left;
}

bool GSEUserInterface::Is_SP_Arrow_Right_Down()
{
	return m_SP_Arrow_Right;
}
