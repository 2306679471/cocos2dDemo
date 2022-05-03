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
		// �����Զ��ͷų�
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

	// �����������
	srand(time(NULL));
	//��������
	Size visible = Director::getInstance()->getVisibleSize();
	//���ӻ���������
	Vec2 originpos = Director::getInstance()->getVisibleOrigin();
	// ����ļ�����·��
	FileUtils::getInstance()->addSearchPath("SceneGameHall");
	FileUtils::getInstance()->addSearchPath("SceneGameReady");
	Vec2 centerPos = Vec2(
		originpos.x + visible.width / 2,
		originpos.y + visible.height / 2);
	int gold = UserDefault::getInstance()->getIntegerForKey("Gold", 0);
	// ״̬������
	Sprite* spPowerback = Sprite::create("ui_powerback.png");
	this->addChild(spPowerback);
	spPowerback->setPosition(centerPos.x,
		visible.height - spPowerback->getContentSize().height / 2);

	// ��������
	Scale9Sprite* spPowerBg = Scale9Sprite::create("goldbg.png");
	spPowerBg->setContentSize(Size(300, spPowerBg->getContentSize().height));
	spPowerback->addChild(spPowerBg);
	spPowerBg->setPosition(
		spPowerBg->getContentSize().width / 2 + 10,
		spPowerback->getContentSize().height / 2);
	// ����
	for (int i = 0; i < 5; i++)
	{
		spTili[i] = Sprite::create("ui_powerred.png");
		spPowerBg->addChild(spTili[i]);
		spTili[i]->setPosition(30 + i * (spTili[i]->getContentSize().width + 10), spPowerBg->getContentSize().height / 2);
	}
	// ����max
	spTiliMax = Sprite::create("MAX.png");
	spPowerBg->addChild(spTiliMax);
	spTiliMax->setPosition(
		spTili[4]->getPosition().x +
		spTili[4]->getContentSize().width +
		spTiliMax->getContentSize().width / 2,
		spPowerBg->getContentSize().height / 2
		);
	// ����������ť 
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
	//״̬������
	Sprite* sppowerback = Sprite::create("GameHall/ui_powerback.png");
	this->addChild(sppowerback);
	sppowerback->setPosition(originpos.x + visible.width / 2, visible.height - sppowerback->getContentSize().height / 2);
	//��ұ�����
	Scale9Sprite* spGoldBg = Scale9Sprite::create("goldbg.png");
	auto jb = Label::create();
	jb->setSystemFontName("fonts/arial.ttf");
	jb->setSystemFontSize(20);
	spGoldBg->addChild(jb);
	jb->setPosition(spGoldBg->getContentSize().width / 2,
		spGoldBg->getContentSize().height / 2);
	jb->setString(std::to_string(gold));
	// ��������
	spGoldBg->setContentSize(Size(180, spGoldBg->getContentSize().height));
	spPowerback->addChild(spGoldBg);
	spGoldBg->setPosition(
		spPowerBg->getContentSize().width  +
		spGoldBg->getContentSize().width / 2+10,
		spPowerback->getContentSize().height / 2);
	//��ҼӺ�
	Button* btniconplus = Button::create("ui_addbutton.png");
	spGoldBg->addChild(btniconplus);
	btniconplus->setPosition(Size(spGoldBg->getContentSize().width, spGoldBg->getContentSize().height / 2));
	btniconplus->addClickEventListener([](Ref* ref){
		TransitionFade* fade = TransitionFade::create(0.2f, IconBuyinfo::create(2));
		Director::getInstance()->replaceScene(fade);
	});
	// ���icon
	Sprite* spGoldIcon = Sprite::create("ui_coinsicon.png");
	spGoldBg->addChild(spGoldIcon);
	spGoldIcon->setPosition(spGoldIcon->getContentSize().width / 2,
		spGoldBg->getContentSize().height / 2);
	// ��Ҷ������ž���
	spGoldAni = Sprite::create("ui_coinsicon.png");
	spGoldBg->addChild(spGoldAni);
	spGoldAni->setPosition(spGoldIcon->getPosition());

	// ��ʯ����
	Scale9Sprite* spDiamondBg = Scale9Sprite::create("goldbg.png");
	spDiamondBg->setContentSize(Size(150, spDiamondBg->getContentSize().height));
	spPowerback->addChild(spDiamondBg);
	spDiamondBg->setPosition(
		spGoldBg->getPosition().x +
		spGoldBg->getContentSize().width / 2 +
		spDiamondBg->getContentSize().width / 2 + 40,
		spPowerback->getContentSize().height / 2);
	//��ʯ
	Sprite* spdemo = Sprite::create("ui_gemicon.png");
	spDiamondBg->addChild(spdemo);
	spdemo->setPosition(0, spDiamondBg->getContentSize().height / 2);
	//��ʯ���Ӻ�
	Button* btndemoplus = Button::create("ui_addbutton.png");
	spDiamondBg->addChild(btndemoplus);
	btndemoplus->setPosition(Vec2(spDiamondBg->getContentSize().width, spDiamondBg->getContentSize().height / 2));
	btndemoplus->addClickEventListener([](Ref* ref){
		TransitionFade* fade = TransitionFade::create(0.2f, DemoBuyinfo::create(3));
		Director::getInstance()->replaceScene(fade);
	});
	//��ʯ���ž���
	spDemoAni = Sprite::create("ui_gemicon.png");
	spDiamondBg->addChild(spDemoAni);
	spDemoAni->setPosition(spdemo->getPosition());
	//���ѵ���
	Scale9Sprite* sphuafeipower = Scale9Sprite::create("goldbg.png");
	sphuafeipower->setContentSize(Size(110, sphuafeipower->getContentSize().height));
	sppowerback->addChild(sphuafeipower);
	sphuafeipower->setPosition(sppowerback->getContentSize().width / 2 +
		spDiamondBg->getContentSize().width + sphuafeipower->getContentSize().width + 105, 
		sppowerback->getContentSize().height / 2);
	//���ѵ�
	Sprite* sphuafei = Sprite::create("huafeipoint.png");
	sphuafeipower->addChild(sphuafei);
	sphuafei->setPosition(0, sphuafeipower->getContentSize().height / 2);
	
	
	// �ݹ麯�������Ž�Ҷ���
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
		// �����µ�������������
		Sprite* spTiliAni = Sprite::create();
		// ��ȡ��Ӧ���±�����������+ƫ����
		spTiliAni->setPosition(spTili[curIdxTili]->getPosition() + Vec2(5, 0));
		// ��ȡ�����ĸ��ڵ���Ϊ���������ĸ��ڵ�
		spTili[curIdxTili]->getParent()->addChild(spTiliAni);
		spTiliAni->runAction(
			Sequence::create(
			DelayTime::create(dt),
			Myanimation::create("ui_poweraction", 0, 6, 0.15f, 1, true),
			CallFunc::create([this]() {
			playAnimation();
		}),
			// �Ƴ��Լ�
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