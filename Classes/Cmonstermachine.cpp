#include"Cmonstermachine.h"
#include"cocos2d.h"
#include"Myanimation.h"
using namespace cocos2d;
Cmonstermachine* Cmonstermachine::create()
{
	Cmonstermachine* machine = new Cmonstermachine;
	if (machine&&machine->init())
	{
		machine->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(machine);
	}
	return machine;
}
bool Cmonstermachine::init()
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("FlyMachine0.png");
#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", "FlyMachine0.png");
	CCASSERT(frame != nullptr, msg);
#endif
	if (!Sprite::initWithSpriteFrame(frame))
	{
		return true;
	}
	FileUtils::getInstance()->addSearchPath("Boss");
	this->runAction(
		Myanimation::create("FlyMachine",0,3,0.1f,-1,true)
		);
	m_mscore = 100;
	m_nHp = m_nMaxHp = 100;
	m_nAtk = 20;
	m_vMoveSpeed = Vec2(-100, 0);
	type = MONSTER_MACHINE;
	return true;
}
void Cmonstermachine::move(float dt)
{
	this->setPosition(this->getPosition() + m_vMoveSpeed*dt);
}