#include"SceneGameLogo.h"
#include"ui\CocosGUI.h"
#include"SceneGameHall.h"
using namespace cocos2d;
using namespace cocos2d::ui;
Scene* SceneGameLogo::create()
{
	SceneGameLogo* scene = new SceneGameLogo;
	if (scene&&scene->init())
	{
		scene->autorelease();
	}
	else
	{
		delete scene;
		scene = nullptr;
	}
	return scene;
}

bool SceneGameLogo::init()
{
	if (!Scene::init())
	{
		return false;
	}
	else
	{
		Size visible = Director::getInstance()->getVisibleSize();
		//可视化界面的起点
		Vec2 originpos = Director::getInstance()->getVisibleOrigin();
		Sprite* spLogo = Sprite::create("GameSceneLogo/loadingbg.jpg");
		spLogo->setPosition(originpos.x + visible.width / 2, originpos.y + visible.height/2);
		this->addChild(spLogo);
		//个人模式按钮
		Button* btuoffline = Button::create("offlineBtn.png");
		this->addChild(btuoffline);
		btuoffline->setPosition(Vec2(originpos.x + visible.width / 2 - btuoffline->getContentSize().width * 3 / 2, 60));
		//在线模式
		Button* btuonline = Button::create("onlineBtn.png");
		this->addChild(btuonline);
		btuonline->setPosition(Vec2(originpos.x + visible.width / 2 + btuonline->getContentSize().width * 3 / 2, 60));
		btuoffline->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, SceneGameHall::create());
			Director::getInstance()->replaceScene(fade);
		});
		return true;
	}
}