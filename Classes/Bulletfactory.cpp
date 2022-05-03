#include"Bulletfactory.h"
using namespace cocos2d;
Cbullet* Bulletfactory::create(const Herotype& type, cocos2d::Vec2 speed)
{
	Cbullet* bullet = nullptr;
	FileUtils::getInstance()->addSearchPath("GameScene/ingame/bullet/actor0bullet");
	FileUtils::getInstance()->addSearchPath("GameScene/ingame/bullet/actor1bullet");
	FileUtils::getInstance()->addSearchPath("GameScene/ingame/bullet/actor2bullet");
	FileUtils::getInstance()->addSearchPath("GameScene/ingame/bullet/actor3bullet");
	switch (type)
	{
	case HERO_ONE:
		bullet = Cbullet::create("bullet0_0.png",speed);
		break;
	case HERO_TWO:
		bullet = Cbullet::create("bullet1_0.png", speed);
		break;
	case HERO_THREE:
		bullet = Cbullet::create("bullet2_0.png", speed);
		break;
	case HERO_FOUR:
		bullet = Cbullet::create("bullet3_0.png", speed);
		break;
	}
	return bullet;
}