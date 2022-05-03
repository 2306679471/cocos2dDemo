#pragma once
#include"Cmonster.h"
#include"Chero.h"
#include"SceneGame.h"
#include"Management.h"
class Cmonsterchicken : public Cmonster
{
public:
	static Cmonsterchicken* create();
	virtual bool init();
	virtual void move(float dt);
	void attack(float dt);
	void updatebullet();
	void update(float dt);
	void setstate();
private:

	float m_chickenatktimer;
	float m_chickenatkduration;
	Management* man;//数据管理类
};