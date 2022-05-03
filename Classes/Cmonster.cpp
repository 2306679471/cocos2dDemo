#include"Cmonster.h"
#include"cocos2d.h"
using namespace cocos2d;
void Cmonster::initHpBar()
{
	Sprite* spEmptyHpBar = Sprite::createWithSpriteFrameName("monsterhpenempty.png");
	this->addChild(spEmptyHpBar);

	Vec2 pos = Vec2(this->getContentSize().width / 2, this->getContentSize().height + spEmptyHpBar->getContentSize().height);

	spEmptyHpBar->setPosition(pos);
	// ÑªÌõ 
	hpBar = LoadingBar::create("monsterhpfull.png", ui::Widget::TextureResType::PLIST, 100);
	this->addChild(hpBar);
	hpBar->setPosition(pos);
}