#include"Cmonsterpig.h"
#include"Myanimation.h"
using namespace cocos2d;
Cmonsterpig* Cmonsterpig::create()
{
	Cmonsterpig* pig = new Cmonsterpig;
	if (pig && pig->init())
	{
		pig->autorelease();
	}
	else
	{
		delete pig;
		pig = nullptr;
	}
	return pig;
}
bool Cmonsterpig::init()
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("pig0.png");
#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", "pig0.png");
	CCASSERT(frame != nullptr, msg);
#endif
	if (!Sprite::initWithSpriteFrame(frame))
	{
		return true;
	}
	FileUtils::getInstance()->addSearchPath("Boss");
	m_mscore = 100;
	m_nHp = m_nMaxHp= 100;
	m_nAtk = 20; 
	m_vMoveSpeed = Vec2(-100, 0);
	type = MONSTER_PIG;
	this->runAction(
		Myanimation::create("pig",0,5,0.2f,-1,true)
		);
	return true;
}
void Cmonsterpig::move(float dt)
{
	this->setPosition(this->getPosition() + m_vMoveSpeed * dt);
}