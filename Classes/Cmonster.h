#pragma once
#include"cocos2d.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
enum MonsterType
{
	MONSTER_PIG,
	MONSTER_CHICKEN,
	MONSTER_SHARK,
	MONSTER_MACHINE
};
class Cmonster : public cocos2d::Sprite
{
public:
	virtual void move(float dt) = 0;
	virtual void initHpBar();
	MonsterType gettype()
	{
		return type;
	}
	// 修改血量
	void setHp(int hp)
	{
		m_nHp = hp;
		// 修改血条
		float percent = (float)m_nHp / (float)m_nMaxHp * 100.0f;
		hpBar->setPercent(percent);
	}
	// 获取血量
	int getHp()
	{
		return m_nHp;
	}
	int getatk()
	{
		return m_nAtk;
	}
	int getscore()
	{
		return m_mscore;
	}
protected:
	int m_nHp, m_nMaxHp;
	int m_nAtk;
	int m_mscore;
	cocos2d::Vec2 m_vMoveSpeed;
	MonsterType type;
	LoadingBar* hpBar;
};