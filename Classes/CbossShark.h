#pragma once
#include"cocos2d.h"
#include"Cboss.h"
#include"Management.h"
class CbossShark : public Cboss
{
public:
	static CbossShark* create();
	virtual bool init();
	void update(float dt);
	void move(float dt);
	void producemonster(float dt);
	void attack(float dt);

private:
	float m_sharkproducemonstertimer;
	float m_sharkproducemonsterduration;
	float m_sharkattaktimer;
	float m_sharkattackduration;
	cocos2d::Sprite* m_spgun;
};