#include"SceneGameHall.h"
#include"ui\CocosGUI.h"
#include"SceneGame.h"
#include"Myanimation.h"
#include"Layerinfo.h"
#include"SceneGameReady.h"
#include"SceneRoleSelect.h"
#include"ScenePetSelect.h"
#include"SceneFlybrowSelect.h"
#include"LayerDilot.h"
#include"SceneFankui.h"
using namespace cocos2d;
using namespace cocos2d::ui;
Scene* SceneGameHall::create()
{
	SceneGameHall* scene = new SceneGameHall;
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
bool SceneGameHall::init()
{
	if (!Scene::init())
	{
		return false;
	}
	else
	{
		//����ļ�����·��
		FileUtils::getInstance()->addSearchPath("GameHall");
		//��������
		Size visible = Director::getInstance()->getVisibleSize();
		//���ӻ���������
		Vec2 originpos = Director::getInstance()->getVisibleOrigin();
		Vec2 centerPos = Vec2(
			originpos.x + visible.width / 2,
			originpos.y + visible.height / 2);
		Sprite* spHall = Sprite::create("GameHall/ui_back0.jpg");
		spHall->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		spHall->setPosition(originpos.x + visible.width / 2, originpos.y + visible.height / 2);
		this->addChild(spHall);
		//��ɫ��ť
		Button* btnjs = Button::create("GameHall/ui_actortips.png");
		btnjs->setPosition(Vec2(200, 350));
		this->addChild(btnjs);
		btnjs->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, SceneRoleSelect::create());
			Director::getInstance()->replaceScene(fade);
		});
		//���ﰴť
		Button* btncw = Button::create("GameHall/ui_pettips.png");
		btncw->setPosition(Vec2(200, 260));
		this->addChild(btncw);
		btncw->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, ScenePetSelect::create());
			Director::getInstance()->replaceScene(fade);
		});
		//��ͧ��ť
		Button* btnft = Button::create("GameHall/ui_airshiptips.png");
		btnft->setPosition(Vec2(200, 170));
		this->addChild(btnft);
		btnft->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, SceneFlybrowSelect::create());
			Director::getInstance()->replaceScene(fade);
		});
		//�ײ���Ŀ��
		Sprite* spb = Sprite::create("GameHall/mainLayertoumingBg.png");
		Size size =spb->getContentSize();
		spb->setPosition(originpos.x + visible.width / 2, size.height / 2);
		spb->setLocalZOrder(2);
		this->addChild(spb);
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
		sppet->setPosition(sppet->getContentSize().width/4-20,spP->getContentSize().height/2+40);
		//�޾�ģʽ
		Button* endlessmodel = Button::create("GameHall/wujingbtn.png");
		spb->addChild(endlessmodel);
		endlessmodel->setPosition(Vec2(625,60));
		endlessmodel->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, SceneGameReady::create());
			Director::getInstance()->replaceScene(fade);
		});
		//����ģʽ
		Button* fightmodel = Button::create("GameHall/jingjibg.png");
		spb->addChild(fightmodel);
		fightmodel->setPosition(Vec2(780,60));
		fightmodel->addClickEventListener([](Ref* ref){
		
		});
		//���ð�ť
		Button* setting = Button::create("GameHall/setting.png");
		spb->addChild(setting);
		setting->setPosition(Vec2(495, 45));
		setting->addClickEventListener([this, centerPos](Ref* ref){
			LayerDilot* layer = LayerDilot::create("else_itembuyback.png",SPRITE_TYPE::FILENAME);
			this->addChild(layer,99);
			Button* btn = Button::create("else_backpre.png");
			layer->getChildByName("sp")->addChild(btn);
			btn->setPosition(Vec2(btn->getContentSize().width / 2,
				layer->getChildByName("sp")->getContentSize().height - btn->getContentSize().height / 2
				));
			btn->addClickEventListener([layer](Ref* ref){
				layer->removeFromParent();
			});
		});
		
		//�ʼ���ť
		Button* email = Button::create("GameHall/email.png");
		spb->addChild(email);
		email->setPosition(Vec2(385,45));
		email->addClickEventListener([](Ref* ref){

		});
		//�һ��Ѱ�ť
		Button* huafei = Button::create("GameHall/duihuafei.png");
		spb->addChild(huafei);
		huafei->setPosition(Vec2(275, 45));
		huafei->addClickEventListener([](Ref* ref){

		});
		//����ť
		Button* task = Button::create("GameHall/task.png");
		spb->addChild(task);
		task->setPosition(Vec2(165, 45));
		task->addClickEventListener([](Ref* ref){
		
		});
		//�̵갴ť
		Button* shop = Button::create("GameHall/ui_storebutton.png");
		spb->addChild(shop);
		shop->setPosition(Vec2(55, 45));
		shop->addClickEventListener([](Ref* ref){
		
		});
		//�ͷ�����
		Button* kefu = Button::create("GameHall/feedBack.png");
		spfly->addChild(kefu);
		kefu->setPosition(Vec2(330,370));
		kefu->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, SceneFankui::create());
			Director::getInstance()->replaceScene(fade);
		});

		Layerinfo* info = Layerinfo::create();
		this->addChild(info);
		info->setLocalZOrder(2); 
		return true;
	}
}
