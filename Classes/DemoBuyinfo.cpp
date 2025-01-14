#include"DemoBuyinfo.h"
#include"Layerinfo.h"
#include"SceneBuy.h"
#include"SelectLayerinfo.h"
#include "ui/CocosGUI.h"
#include"SceneGameHall.h"
using namespace cocos2d;
using namespace cocos2d::ui;
DemoBuyinfo* DemoBuyinfo::create(int idx)
{
	DemoBuyinfo* demo = new DemoBuyinfo;
	if (demo&&demo->init(idx))
	{
		demo->autorelease();
	}
	else
	{
		delete demo;
		demo = nullptr;
	}
	return demo;
}
bool DemoBuyinfo::init(int idx)
{
	if (!Scene::init())
	{
		return false;
	}
	else{
		Size visible = Director::getInstance()->getVisibleSize();
		Vec2 originpos = Director::getInstance()->getVisibleOrigin();
		FileUtils::getInstance()->addSearchPath("SelectLayerinfo");
		Layerinfo* info = Layerinfo::create();
		this->addChild(info);
		SceneBuy* buy = SceneBuy::create(3,idx);
		this->addChild(buy);
		//����
		auto spbg = Sprite::create("slectpet_back0.jpg");
		this->addChild(spbg);
		spbg->setLocalZOrder(-2);
		spbg->setPosition(originpos.x + visible.width / 2
			, originpos.y + visible.height / 2);
		//�ײ���
		auto spbotk = Sprite::create("slectpet_back1.png");
		this->addChild(spbotk);
		spbotk->setLocalZOrder(-1);
		spbotk->setPosition(spbotk->getContentSize().width / 2
			, spbotk->getContentSize().height / 2);
		auto* btnback = Button::create("select_close.png");
		spbotk->addChild(btnback);
		btnback->setPosition(Vec2(72, 36));
		btnback->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, SceneGameHall::create());
			Director::getInstance()->replaceScene(fade);
		});
		return true;
	}
}