#include"Cmachine.h"
#include"cocos2d.h"
#include"Monsterfactory.h"
#include"Management.h"
#include"Myanimation.h"
using namespace cocos2d;
Cmachine* Cmachine::create()
{
	Cmachine* machine = new Cmachine;
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
bool Cmachine::init()
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("machineBody.png");
#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", "machineBody.png");
	CCASSERT(frame != nullptr, msg);
#endif
	if (!Sprite::initWithSpriteFrame(frame))
	{
		return true;
	}
	m_nHp = m_nMaxHp = 5000;
	m_nAtk = 30;
	m_mscore = 500;
	type = BOSSTYPE_MACHINE;
	visible = Director::getInstance()->getVisibleSize();
	m_speed = Vec2(-50, 0);
	man = Management::getinstance();
	m_machineproducemonstertimer = 0;
	m_machineproducemonsterduration = 3.0f;
	m_machineattaktimer=0;
	m_machineattackduration=5.0f;
	m_bullet = Sprite::create();
	m_spmachinehead = Sprite::create("face0.png");
	this->addChild(m_spmachinehead);
	m_spmachinehead->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
	m_spmachinehead->setPosition(0, 294);
	srand(time(nullptr));
	this->scheduleUpdate();
	return true;
}
void Cmachine::move(float dt)
{
	if (this->getPositionX() <= visible.width - this->getContentSize().width / 2)
	{
		return;
	}
	this->setPosition(this->getPosition() + m_speed*dt);
}
void Cmachine::update(float dt)
{
	if (!man->getisgameover())
	{
		this->unscheduleUpdate();
	}
	else
	{
		producemonster(dt);
		attack(dt);
	}
}
void Cmachine::producemonster(float dt)
{
	m_machineproducemonstertimer += dt;
	if (m_machineproducemonstertimer > m_machineproducemonsterduration)
	{
		m_machineproducemonstertimer = 0;
		Cmonster* monster = MonsterFactory::create(MONSTER_MACHINE);
		this->getParent()->addChild(monster);
		float xx = visible.width + monster->getContentSize().width / 2;
		float yy = rand() % (int)visible.height;
		monster->setPosition(xx, yy);
		man->setMonster(monster);
	}
}
void Cmachine::attack(float dt)
{
	m_machineattaktimer += dt;
	if (m_machineattaktimer > m_machineattackduration)
	{
		m_machineattaktimer = 0;
		m_spmachinehead->runAction(
			Myanimation::create("face",0,6,0.2f,1,false)
			);
		m_bullet = Sprite::create("fire0.png");
		m_spmachinehead->addChild(m_bullet);
		m_bullet->setPosition(25, 112);
		m_bullet->runAction(
			Myanimation::create("fire",0,3,0.1f,-1,true)
			);
		m_bullet->runAction(
			Sequence::create(
			MoveTo::create(1.5f, Vec2(197, 250)), nullptr
			)
			);
	}
}