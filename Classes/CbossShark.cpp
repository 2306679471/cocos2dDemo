#include"CbossShark.h"
#include"cocos2d.h"
#include"Monsterfactory.h"
#include"Myanimation.h"
using namespace cocos2d;
CbossShark* CbossShark::create()
{
	CbossShark* shark = new CbossShark;
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
bool CbossShark::init()
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("shark.png");
#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", "shark.png");
	CCASSERT(frame != nullptr, msg);
#endif
	if (!Sprite::initWithSpriteFrame(frame))
	{
		return true;
	}

	FileUtils::getInstance()->addSearchPath("Boss");
	m_nHp=m_nMaxHp=5000;
	m_nAtk=30;
	m_mscore=500;
	type=BOSSTYPE_SHARK;
	visible = Director::getInstance()->getVisibleSize();
	m_speed = Vec2(-50, 0); 
	m_sharkproducemonstertimer = 0;
	m_sharkproducemonsterduration= 3.0f;
	m_sharkattaktimer=0;
	m_sharkattackduration=5.0f;
	m_bullet = Sprite::create();
	man = Management::getinstance();
	srand(time(nullptr));
	auto spempty = Sprite::create();
	this->addChild(spempty);
	spempty->setPosition(360,80);
	spempty->runAction(
		Myanimation::create("smoke",0,3,0.1f,-1,true)
		);
	auto spback = Sprite::create("gunBack.png");
	this->addChild(spback);
	spback->setPosition(75, 170);
	m_spgun = Sprite::create("gun.png");
	this->addChild(m_spgun);
	m_spgun->setPosition(100, 170);
	this->scheduleUpdate();
	return true;
}
void CbossShark::move(float dt)
{
	if (this->getPositionX() <= visible.width - this->getContentSize().width / 2)
	{
		return;
	}
	this->setPosition(this->getPosition() + m_speed*dt);
}void CbossShark::producemonster(float dt)
{
	
	m_sharkproducemonstertimer += dt;
	if (m_sharkproducemonstertimer > m_sharkproducemonsterduration)
	{
		
		m_sharkproducemonstertimer = 0;
		Cmonster* monster = MonsterFactory::create(MONSTER_SHARK);
		this->getParent()->addChild(monster);
		float xx = visible.width + monster->getContentSize().width / 2;
		float yy = rand() % (int)visible.height;
		monster->setPosition(xx, yy);
		man->setMonster(monster);
	}
}
void CbossShark::update(float dt)
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
void CbossShark::attack(float dt)
{
	FileUtils::getInstance()->addSearchPath("Boss");
	m_sharkattaktimer += dt;
	if (m_sharkattaktimer > m_sharkattackduration)
	{
		
		m_sharkattaktimer = 0;
		m_spgun->runAction(
			RotateBy::create(0.5f,30.0f)
			);
		
		m_spgun->addChild(m_bullet);
		m_bullet->setPosition(12, 60);
		m_bullet->runAction(
			Myanimation::create("sharkBomb",0,2,0.1f,-1,true)
			);
		m_bullet->runAction(
			Sequence::create(
			MoveTo::create(1.5f, Vec2(197, 250)), nullptr
			)
			);
	}
}
