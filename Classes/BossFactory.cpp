#include"BossFactory.h"
#include"cocos2d.h"
using namespace cocos2d;
Cboss* BossFactory::create(const BOSSTYPE& type)
{
	Cboss* boss = nullptr;
	switch (type)
	{
		case BOSSTYPE_MACHINE :
		{
			boss = Cmachine::create();
			break;
		}
		case BOSSTYPE_SHARK:
		{
			boss = CbossShark::create();
			break;
		}
	}
	boss->initHpBar();
	return boss;
}