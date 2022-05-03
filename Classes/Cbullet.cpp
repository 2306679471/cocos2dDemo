#include"cocos2d.h"
#include"Cbullet.h"
using namespace cocos2d;
Cbullet* Cbullet::create(const std::string filename, cocos2d::Vec2 speed)
{
	Cbullet* bullet = new Cbullet;
	if (bullet&&bullet->init(filename,speed))
	{
		bullet->autorelease();
	}
	else
	{
		delete bullet;
		bullet = nullptr;
	}
	return bullet;
}
bool Cbullet::init(const std::string filename, cocos2d::Vec2 speed)
{
	if (!Sprite::initWithFile(filename))
	{
		return false;
	}
	else{
		m_attack = 20;
		m_speed = speed;
		return true;
	}
}
void Cbullet::move(float dt)
{
	this->setPosition(this->getPosition() + m_speed*dt);
}