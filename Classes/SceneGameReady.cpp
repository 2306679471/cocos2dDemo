#include "SceneGameReady.h"
using namespace cocos2d;
#include"SceneGameHall.h"
// GUIͷ�ļ��������ռ�
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
#include"Buytaskbar.h"
#include "MyAnimation.h"
#include "LayerInfo.h"
#include"SceneGame.h"
SceneGameReady* SceneGameReady::create()
{
	SceneGameReady* scene = new SceneGameReady;
	if (scene && scene->init())
	{
		// �����Զ��ͷų�
		scene->autorelease();
	}
	else
	{
		delete scene;
		scene = nullptr;
	}
	return scene;
}
bool SceneGameReady::init()
{
	if (!Scene::init())
	{
		return false;
	}
	FileUtils::getInstance()->addSearchPath("SceneGameReady");
	FileUtils::getInstance()->addSearchPath("GameHall");

	// ��ȡ���ӻ���������
	Size visible = Director::getInstance()->getVisibleSize();
	// ���ӻ���������
	Vec2 originpos = Director::getInstance()->getVisibleOrigin();
	// ���ĵ�
	Vec2 centerPos = Vec2(
		originpos.x + visible.width / 2,
		originpos.y + visible.height / 2);


	// ������Ϣ�㣬��ӵ���ǰ����
	Layerinfo* info = Layerinfo::create();
	this->addChild(info);
	info->setLocalZOrder(2);
	//ѩɽ
	Sprite* spsnowmoutain = Sprite::create("GameHall/ui_back1.png");
	this->addChild(spsnowmoutain);
	spsnowmoutain->setPosition(originpos.x + visible.width / 2 + 145, visible.height / 2 - 130);
	spsnowmoutain->setLocalZOrder(1);
	//�ұ߷�ͧ
	Sprite* spfly = Sprite::create("GameHall/actor_airship0.png");
	spfly->setPosition(originpos.x + visible.width / 2 + 230, originpos.y + visible.height / 2 + 40);
	this->addChild(spfly);
	
	//����
	Sprite* spP = Sprite::create("SceneSelect/selectactor_actoricon0.png");
	spP->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	spsnowmoutain->addChild(spP);
	spP->setPosition(220, 120);
	//����
	Sprite* sppet = Sprite::create("mainscene_pet0.png");
	sppet->setScale(0.6f);
	spP->addChild(sppet);
	sppet->setPosition(sppet->getContentSize().width / 4 - 20, spP->getContentSize().height / 2 + 40);
	// ���߹��򱳾�
	Sprite* spPropBg = Sprite::create("buy_itemback.png");
	this->addChild(spPropBg);
	spPropBg->setLocalZOrder(2);
	spPropBg->setPosition(originpos.x +
		spPropBg->getContentSize().width / 2 + 30,
		centerPos.y - 20
		);
	auto sptip = Sprite::create("buy_tips.png");
	spPropBg->addChild(sptip);
	sptip->setPosition(spPropBg->getContentSize().width/2,spPropBg->getContentSize().height-sptip->getContentSize().height-5);
	//����
	Sprite* spHall = Sprite::create("GameHall/ui_back0.jpg");
	spHall->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	spHall->setPosition(originpos.x + visible.width / 2, originpos.y + visible.height / 2);
	this->addChild(spHall); 
	spHall->setLocalZOrder(-1);
	//��ʼ��Ϸ��ť
	Button* btnstar = Button::create("ui_startbutton0.png");
	this->addChild(btnstar);
	btnstar->setPosition(Vec2(600, originpos.y+btnstar->getContentSize().height / 2));
	btnstar->setLocalZOrder(2);
	btnstar->addClickEventListener([](Ref*)
	{
		SceneGame* scene = SceneGame::create();
		// �л������Ķ���Ч��
		TransitionFade* fade = TransitionFade::create(0.2f, scene);
		// �л�����
		Director::getInstance()->replaceScene(fade);
	});
	//���ؼ�
	Button* btnback = Button::create("buy_backpre.png");
	spPropBg->addChild(btnback);
	btnback->setPosition(Vec2(
		btnback->getContentSize().width / 2, spPropBg->getContentSize().height - btnback->getContentSize().height/2
		));
	btnback->addClickEventListener([](Ref* ref){
		TransitionFade* fade = TransitionFade::create(0.2f, SceneGameHall::create());
		Director::getInstance()->replaceScene(fade);
	});

	// 1.�����б���ͼ
	ListView* listView = ListView::create();
	// 2.��ӵ�����
	spPropBg->addChild(listView);
	// ���ô�С
	listView->setContentSize(Size(spPropBg->getContentSize().width,
		spPropBg->getContentSize().height-btnback->getContentSize().height));
	//  PageView��Ĭ��ê�������½�
	listView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// ��������
	listView->setEnabled(true);
	listView->setPosition(Vec2(spPropBg->getContentSize().width / 2,
		(spPropBg->getContentSize().height - btnback->getContentSize().height) / 2 ) );
	listView->setDirection(ui::ScrollView::Direction::VERTICAL);
	//// �Ƿ�ص�
	listView->setBounceEnabled(true);
	//�Ƿ���Ƭ
	listView->setClippingEnabled(false);
	//���ػ�����
	listView->setScrollBarEnabled(true);
	char filename[64];
	const char* text[3] = { "�������ף��", "���ֳ��1200��", "��������" };
	int num[3] = { 300, 400, 500 };
	for (int i = 0; i < 3; i++)
	{
		// ���ͼƬ��ͼ(��ӵ���¼�)
		ImageView* imageView = ImageView::create("buycell_back.png");
		Layout* layout = Layout::create();
		layout->setContentSize(imageView->getContentSize());
		imageView->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		std::sprintf(filename, "SceneGameReady/buycell_itemicon%d.png", i);
		Sprite* spitem = Sprite::create(filename);
		auto labeltext = Label::create(gb23122utf8(text[i]), "fonts/Marker Felt", 20);
		labeltext->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		labeltext->setTextColor(Color4B(1, 1, 1,192));
		imageView->addChild(labeltext, 2);
		labeltext->setPosition(imageView->getContentSize().width / 2, labeltext->getContentSize().height + 5);
		imageView->addChild(spitem);
		Button* btnbuy = Button::create("buy_buytips.png");
		imageView->addChild(btnbuy);
		btnbuy->setPosition(Vec2(imageView->getContentSize().width
			-btnbuy->getContentSize().width/2-10,
			imageView->getContentSize().height / 2));
		spitem->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		spitem->setPosition(spitem->getContentSize().width/2,
			imageView->getContentSize().height/2);
		auto spicon = Sprite::create("ui_coinsicon.png");
		spitem->addChild(spicon);
		spicon->setScale(0.7f);
		spicon->setPosition(130,50);
		auto labelnum = Label::create(std::to_string(num[i]), "fonts/arial", 28);
		labelnum->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		spitem->addChild(labelnum);
		labelnum->setPosition(180,45);
		layout->addChild(imageView);
		listView->pushBackCustomItem(layout);
		
	}

	return true;
}
const char* SceneGameReady::gb23122utf8(const char* gb2312)
{
	int len = MultiByteToWideChar(0, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(0, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(65001, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(65001, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}