#include"Chero.h"
#include"cocos2d.h"
#include"ui\CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocos2d;
Chero* Chero::create(const std::string filename)
{
	Chero* hero = new Chero;
	if (hero&&hero->init(filename))
	{
		hero->autorelease();
	}
	else{
		delete hero;
		hero = nullptr;
	}
	return hero;
}
bool Chero::init(const std::string filename)
{
	if (!Sprite::initWithFile(filename))
	{
		return false;
	}
	else{
		m_nHp = m_nMaxHp = 100;
			return true;
	}
}
