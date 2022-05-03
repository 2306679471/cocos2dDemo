#include "LayerInfo.h"
#include"PowerBuyinfo.h"
#include "ui/CocosGUI.h"
#include"IconBuyinfo.h"
#include "MyAnimation.h"
#include"DemoBuyinfo.h"
#include "SceneGameReady.h"
using namespace cocos2d;
using namespace cocos2d::ui;
Layerinfo* Layerinfo::create()
{
	Layerinfo* layer = new Layerinfo;
	if (layer && layer->init())
	{
		// 加入自动释放池
		layer->autorelease();
	}
	else
	{
		delete layer;
		layer = nullptr;
	}
	return layer;
}
bool Layerinfo::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// 设置随机种子
	srand(time(NULL));
	//大厅背景
	Size visible = Director::getInstance()->getVisibleSize();
	//可视化界面的起点
	Vec2 originpos = Director::getInstance()->getVisibleOrigin();
	// 添加文件搜索路径
	FileUtils::getInstance()->addSearchPath("SceneGameHall");
	FileUtils::getInstance()->addSearchPath("SceneGameReady");
	Vec2 centerPos = Vec2(
		originpos.x + visible.width / 2,
		originpos.y + visible.height / 2);
	int gold = UserDefault::getInstance()->getIntegerForKey("Gold", 0);
	// 状态栏背景
	Sprite* spPowerback = Sprite::create("ui_powerback.png");
	this->addChild(spPowerback);
	spPowerback->setPosition(centerPos.x,
		visible.height - spPowerback->getContentSize().height / 2);

	// 体力背景
	Scale9Sprite* spPowerBg = Scale9Sprite::create("goldbg.png");
	spPowerBg->setContentSize(Size(300, spPowerBg->getContentSize().height));
	spPowerback->addChild(spPowerBg);
	spPowerBg->setPosition(
		spPowerBg->getContentSize().width / 2 + 10,
		spPowerback->getContentSize().height / 2);
	// 体力
	for (int i = 0; i < 5; i++)
	{
		spTili[i] = Sprite::create("ui_powerred.png");
		spPowerBg->addChild(spTili[i]);
		spTili[i]->setPosition(30 + i * (spTili[i]->getContentSize().width + 10), spPowerBg->getContentSize().height / 2);
	}
	// 体力max
	spTiliMax = Sprite::create("MAX.png");
	spPowerBg->addChild(spTiliMax);
	spTiliMax->setPosition(
		spTili[4]->getPosition().x +
		spTili[4]->getContentSize().width +
		spTiliMax->getContentSize().width / 2,
		spPowerBg->getContentSize().height / 2
		);
	// 购买体力按钮 
	Button* btnPower = Button::create("ui_addbutton.png");
	spPowerBg->addChild(btnPower);
	btnPower->setPosition(Vec2(spTiliMax->getPosition().x +
		spTiliMax->getContentSize().width + 5,
		spPowerBg->getContentSize().height / 2
		));
	btnPower->addClickEventListener([](Ref* ref){
		TransitionFade* fade = TransitionFade::create(0.2f, PowerBuyinfo::create(1));
		Director::getInstance()->replaceScene(fade);
	});
	//状态栏背景
	Sprite* sppowerback = Sprite::create("GameHall/ui_powerback.png");
	this->addChild(sppowerback);
	sppowerback->setPosition(originpos.x + visible.width / 2, visible.height - sppowerback->getContentSize().height / 2);
	//金币背景栏
	Scale9Sprite* spGoldBg = Scale9Sprite::create("goldbg.png");
	auto jb = Label::create();
	jb->setSystemFontName("fonts/arial.ttf");
	jb->setSystemFontSize(20);
	spGoldBg->addChild(jb);
	jb->setPosition(spGoldBg->getContentSize().width / 2,
		spGoldBg->getContentSize().height / 2);
	jb->setString(std::to_string(gold));
	// 设置内容
	spGoldBg->setContentSize(Size(180, spGoldBg->getContentSize().height));
	spPowerback->addChild(spGoldBg);
	spGoldBg->setPosition(
		spPowerBg->getContentSize().width  +
		spGoldBg->getContentSize().width / 2+10,
		spPowerback->getContentSize().height / 2);
	//金币加号
	Button* btniconplus = Button::create("ui_addbutton.png");
	spGoldBg->addChild(btniconplus);
	btniconplus->setPosition(Size(spGoldBg->getContentSize().width, spGoldBg->getContentSize().height / 2));
	btniconplus->addClickEventListener([](Ref* ref){
		TransitionFade* fade = TransitionFade::create(0.2f, IconBuyinfo::create(2));
		Director::getInstance()->replaceScene(fade);
	});
	// 金币icon
	Sprite* spGoldIcon = Sprite::create("ui_coinsicon.png");
	spGoldBg->addChild(spGoldIcon);
	spGoldIcon->setPosition(spGoldIcon->getContentSize().width / 2,
		spGoldBg->getContentSize().height / 2);
	// 金币动画播放精灵
	spGoldAni = Sprite::create("ui_coinsicon.png");
	spGoldBg->addChild(spGoldAni);
	spGoldAni->setPosition(spGoldIcon->getPosition());

	// 钻石背景
	Scale9Sprite* spDiamondBg = Scale9Sprite::create("goldbg.png");
	spDiamondBg->setContentSize(Size(150, spDiamondBg->getContentSize().height));
	spPowerback->addChild(spDiamondBg);
	spDiamondBg->setPosition(
		spGoldBg->getPosition().x +
		spGoldBg->getContentSize().width / 2 +
		spDiamondBg->getContentSize().width / 2 + 40,
		spPowerback->getContentSize().height / 2);
	//钻石
	Sprite* spdemo = Sprite::create("ui_gemicon.png");
	spDiamondBg->addChild(spdemo);
	spdemo->setPosition(0, spDiamondBg->getContentSize().height / 2);
	//钻石栏加号
	Button* btndemoplus = Button::create("ui_addbutton.png");
	spDiamondBg->addChild(btndemoplus);
	btndemoplus->setPosition(Vec2(spDiamondBg->getContentSize().width, spDiamondBg->getContentSize().height / 2));
	btndemoplus->addClickEventListener([](Ref* ref){
		TransitionFade* fade = TransitionFade::create(0.2f, DemoBuyinfo::create(3));
		Director::getInstance()->replaceScene(fade);
	});
	//钻石播放精灵
	spDemoAni = Sprite::create("ui_gemicon.png");
	spDiamondBg->addChild(spDemoAni);
	spDemoAni->setPosition(spdemo->getPosition());
	//话费点栏
	Scale9Sprite* sphuafeipower = Scale9Sprite::create("goldbg.png");
	sphuafeipower->setContentSize(Size(110, sphuafeipower->getContentSize().height));
	sppowerback->addChild(sphuafeipower);
	sphuafeipower->setPosition(sppowerback->getContentSize().width / 2 +
		spDiamondBg->getContentSize().width + sphuafeipower->getContentSize().width + 105, 
		sppowerback->getContentSize().height / 2);
	//话费点
	Sprite* sphuafei = Sprite::create("huafeipoint.png");
	sphuafeipower->addChild(sphuafei);
	sphuafei->setPosition(0, sphuafeipower->getContentSize().height / 2);
	
	
	// 递归函数：播放金币动画
	playAnimation();

	return true;
}

void Layerinfo::playAnimation()
{
	int randNum = rand() % 100;
	float dt = 1 + rand() % 2;
	if (randNum < 14)
	{
		spGoldAni->runAction(
			Sequence::create(
			DelayTime::create(dt),
			Myanimation::create("ui_coinsaction", 0, 8, 0.15f, 1, true),
			CallFunc::create([this]() {
			playAnimation();
		}),
			nullptr));
	}
	else if (randNum>14&&randNum<84)
	{
		int curIdxTili = rand() % 5;
		// 创建新的体力动画精灵
		Sprite* spTiliAni = Sprite::create();
		// 获取对应的下标体力的坐标+偏移量
		spTiliAni->setPosition(spTili[curIdxTili]->getPosition() + Vec2(5, 0));
		// 获取体力的父节点作为体力动画的父节点
		spTili[curIdxTili]->getParent()->addChild(spTiliAni);
		spTiliAni->runAction(
			Sequence::create(
			DelayTime::create(dt),
			Myanimation::create("ui_poweraction", 0, 6, 0.15f, 1, true),
			CallFunc::create([this]() {
			playAnimation();
		}),
			// 移除自己
			RemoveSelf::create(),
			nullptr));
	}
	else
	{
		spDemoAni->runAction(
			Sequence::create(
			DelayTime::create(dt),
			Myanimation::create("ui_gemaction", 0, 8, 0.15f, 1, true), CallFunc::create([this](){
			playAnimation(); }),
			nullptr)
			);
	}
}