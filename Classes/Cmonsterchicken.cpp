#include"Cmonsterchicken.h"
#include"Myanimation.h"
using namespace cocos2d;
Cmonsterchicken* Cmonsterchicken::create()
{
	Cmonsterchicken* chicken = new Cmonsterchicken;
	if (chicken&&chicken->init())
	{
		chicken->autorelease();
	}
	else
	{
		delete chicken;
		chicken = nullptr;
	}
	return chicken;
}
bool Cmonsterchicken::init()
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("chicken0.png");

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
	m_mscore = 50;
	m_nHp = m_nMaxHp=80;
	m_nAtk = 10;
	m_vMoveSpeed = Vec2(-120, 0);
	type = MONSTER_CHICKEN;
	m_chickenatktimer = 0;
	m_chickenatkduration = 1.5f;
	man = Management::getinstance();
	this->runAction(
		Myanimation::create("chicken",0,5,0.2f,-1,true)
		);
	this->scheduleUpdate();
	return true;
}
void Cmonsterchicken::move(float dt)
{
	if (this->getPositionX() <= Director::getInstance()->getVisibleSize().width / 2)
	{
		return;
	}
	this->setPosition(this->getPosition() + m_vMoveSpeed * dt);
}
void Cmonsterchicken::update(float dt)
{
	attack(dt);
	updatebullet();
	setstate();
}


void Cmonsterchicken::updatebullet()
{
	for (int i = 0; i < man->getmonbulletvector().size(); i++)
	{
		Sprite* bullet = man->getmonbulletvector().at(i);
		bullet->runAction(MoveTo::create(0.5f, Vec2(197, 250)));
	}
}
void Cmonsterchicken::attack(float dt)//¹ÖÎï·¢Éä×Óµ¯
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (this->getPositionX() <= Director::getInstance()->getVisibleSize().width / 2)
	{
		m_chickenatktimer += dt;
		if (m_chickenatktimer >= m_chickenatkduration)
		{
			m_chickenatktimer = 0;
			auto spemebul = Sprite::create("GameScene/enemyBullet.png");
			this->getParent()->addChild(spemebul);
			spemebul->setPosition(this->getPosition());
			man->setmonbullet(spemebul);
		}
	}
	else
	{
		return;
	}

}
void Cmonsterchicken::setstate()
{
	if (!man->getisgameover())
	{
		this->unscheduleUpdate();
	}
}