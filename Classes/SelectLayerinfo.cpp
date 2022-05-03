#include"SelectLayerinfo.h"
#include"Layerinfo.h"
#include"SceneGameHall.h"
#include "ui/CocosGUI.h"
#include"cocos2d.h"
using namespace cocos2d;
using namespace cocos2d::ui;
SelectLayerinfo* SelectLayerinfo::create(const std::string & filename)
{
	SelectLayerinfo* info = new SelectLayerinfo;
	if (info&&info->init(filename))
	{
		info->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(info);
	}
	return info;
}
bool SelectLayerinfo::init(const std::string & filename)
{
	if (!Layer::init())
	{
		return false;
	}
	else{
		Size visible = Director::getInstance()->getVisibleSize();
		Vec2 originpos = Director::getInstance()->getVisibleOrigin();
		FileUtils::getInstance()->addSearchPath("SelectLayerinfo");
		//±³¾°
		spbg = Sprite::create("slectpet_back0.jpg");
		this->addChild(spbg);
		spbg->setPosition(originpos.x + visible.width / 2
			, originpos.y + visible.height / 2);
		//µ×²¿¿ò
		spbotk = Sprite::create("slectpet_back1.png"); 
		spbg->addChild(spbotk);
		spbotk->setPosition(spbotk->getContentSize().width/2
			,spbotk->getContentSize().height/2);
		Button* btnback = Button::create("select_close.png");
		spbotk->addChild(btnback);
		btnback->setPosition(Vec2(72, 36));
		btnback->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, SceneGameHall::create());
			Director::getInstance()->replaceScene(fade);
		});
		Layerinfo* info = Layerinfo::create();
		this->addChild(info);
		Sprite* spst = cocos2d::Sprite::create(filename);
		spst->setPosition(visible.width / 2 + originpos.x, originpos.y + visible.height / 10 - 22); 
		this->addChild(spst);
		return true;
	}
}
