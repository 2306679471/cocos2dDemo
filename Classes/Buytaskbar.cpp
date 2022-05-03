#include"Buytaskbar.h"
using namespace cocos2d;
cocos2d::Sprite* Buytaskbar::create(char* itemname)
{
	FileUtils::getInstance()->addSearchPath("SceneGameReady");
	Sprite* spbg = Sprite::create("buycell_back.png");
	Sprite* spbuy = Sprite::create("buy_buytips.png");
	spbg->addChild(spbuy);
	spbuy->setPosition(spbg->getContentSize().width-spbuy->getContentSize().width/2
		,spbg->getContentSize().height/2);
	Sprite* spitem = Sprite::create(itemname);
	spbg->addChild(spitem);
	spitem->setPosition(spbuy->getContentSize().width / 2,
		spbg->getContentSize().height / 2);
	return spbg;
}

