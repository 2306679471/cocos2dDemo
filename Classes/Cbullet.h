#pragma once 
#include"Chero.h"
#include"cocos2d.h"
class Cbullet : public Chero
{
public:
	// ¹¥»÷º¯Êý
	void move(float dt);
	static Cbullet* create(const std::string filename, cocos2d::Vec2);
	virtual bool init(const std::string filename, cocos2d::Vec2);
	int getattack()
	{
		return m_attack;
	}
private:
	int m_attack;
	cocos2d::Vec2 m_speed;
};