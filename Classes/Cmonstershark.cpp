#include"Cmonstershark.h"
#include"cocos2d.h"
#include"Myanimation.h"
using namespace cocos2d;
Cmonstershark* Cmonstershark::create()
{
	Cmonstershark* shark = new Cmonstershark;
	if (shark&&shark->init())
	{
		shark->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(shark);
	}
	return shark;
}
bool Cmonstershark::init()
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("machineFish0.png");
#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", "machineFish0.png");
	CCASSERT(frame != nullptr, msg);
#endif
	if (!Sprite::initWithSpriteFrame(frame))
	{
		return true;
	}
	FileUtils::getInstance()->addSearchPath("Boss");
	m_mscore = 100;
	m_nHp = m_nMaxHp = 100;
	m_nAtk = 20;
	m_vMoveSpeed = Vec2(-100, 0);
	type = MONSTER_SHARK;
	this->runAction(
		Myanimation::create("machineFish", 0, 5, 0.2f, -1, true)
		);
	return true;
}
void Cmonstershark::move(float dt)
{
	this->setPosition(this->getPosition() + m_vMoveSpeed*dt);
}