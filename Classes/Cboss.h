#pragma once
#include"cocos2d.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
enum BOSSTYPE
{
	BOSSTYPE_SHARK,
	BOSSTYPE_MACHINE
};
class Cboss : public cocos2d::Sprite
{
public:
	virtual void move(float dt) = 0;
	virtual void attack(float dt)=0;
	virtual void initHpBar();
	int getattack()
	{
		return m_nAtk;
	}
	int getscore()
	{
		return m_mscore;
	}
	int gethp()
	{
		return m_nHp;
	}
	void sethp(int hp)
	{
		m_nHp = hp;
	}
	Sprite* getbullet()
	{
		return m_bullet;
	}
protected:
	int m_nHp, m_nMaxHp;
	int m_nAtk;
	int m_mscore;
	BOSSTYPE type;
	LoadingBar* hpBar;
	cocos2d::Size visible; 
	cocos2d::Vec2 m_speed;
	cocos2d::Sprite* m_bullet;
	Management* man;
};