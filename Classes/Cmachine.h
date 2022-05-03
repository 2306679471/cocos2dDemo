#pragma once
#include"cocos2d.h"
#include"Cboss.h"
#include"Management.h"
class Cmachine : public Cboss
{
public:
	static Cmachine* create();
	virtual bool init();
	void move(float dt);
	void update(float dt);
	void producemonster(float dt);
	void attack(float dt);
private:
	float m_machineproducemonstertimer;
	float m_machineproducemonsterduration;
	float m_machineattaktimer;
	float m_machineattackduration;
	cocos2d::Sprite* m_spmachinehead;
	
};