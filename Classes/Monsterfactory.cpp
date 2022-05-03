#include"Monsterfactory.h"
using namespace cocos2d;
Cmonster* MonsterFactory::create(const MonsterType type)
{
	Cmonster* monster = nullptr;
	switch (type)
	{
	case MONSTER_PIG:
	{monster = Cmonsterpig::create();
	break; }
	case MONSTER_CHICKEN:
	{monster = Cmonsterchicken::create();
	break; }
	case MONSTER_SHARK:
	{
		monster = Cmonstershark::create();
		break;
	}
	case MONSTER_MACHINE:
	{
		monster = Cmonstermachine::create();
		break;
	}
	}
	monster->initHpBar();
	return monster;
}