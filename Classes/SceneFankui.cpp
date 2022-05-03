#include"SceneFankui.h"
#include"ui\CocosGUI.h"
#include"SceneGameHall.h"
using namespace cocos2d;
using namespace cocos2d::ui;
SceneFankui* SceneFankui::create()
{
	SceneFankui* fankui = new SceneFankui;
	if (fankui&&fankui->init())
	{
		fankui->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(fankui);
	}
	return fankui;
}
bool SceneFankui::init()
{
	if (!Scene::init())
	{
		return false;
	}
	else
	{
		FileUtils::getInstance()->addSearchPath("GameHall");
		auto glview = Director::getInstance()->getOpenGLView();
		auto visibleOrigin = glview->getVisibleOrigin();
		auto visibleSize = glview->getVisibleSize();
		Size size = Director::getInstance()->getVisibleSize();
		Vec2 centerPos = Vec2(
			visibleOrigin.x + visibleSize.width / 2,
			visibleOrigin.y + visibleSize.height / 2);
		Sprite* spbg = Sprite::create("ui_dit.jpg" );
		this->addChild(spbg);
		spbg->setPosition(centerPos);
		//发送键
		Button* btnsand = Button::create("btn_fk_send.png");
		spbg->addChild(btnsand);
		btnsand->setScale(0.8f);
		btnsand->setPosition(Vec2(780,spbg->getContentSize().height-455));
		
		//返回键
		Button* btnback = Button::create("mail_backpre.png");
		spbg->addChild(btnback);
		btnback->setPosition(Vec2(
			btnback->getContentSize().width / 2,
			spbg->getContentSize().height - btnback->getContentSize().height / 2
			));
		btnback->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, SceneGameHall::create());
			Director::getInstance()->replaceScene(fade);
		});
		//输入框
		Scale9Sprite* sacel9SprY = Scale9Sprite::create("shurukuangphone.png");
		EditBox* box = EditBox::create(Size(700, 55), sacel9SprY);
		spbg->addChild(box);
		box->setPosition(Vec2(15+box->getContentSize().width/2,btnsand->getPositionY()));
		//获取输入的字符，并且显示出来
		btnsand->addClickEventListener([box, spbg](Ref* ref){
			auto label1 = Label::create(box->getText(), "fonts/Marker Felt.ttf", 20.0f);
			spbg->addChild(label1);
			label1->setPosition(spbg->getContentSize().width/2,
				spbg->getContentSize().height/2);
		});
		return true;
	}
}