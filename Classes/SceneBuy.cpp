#include"ui/CocosGUI.h"
#include"SceneGameHall.h"
#include"PowerBuyinfo.h"
#include"DemoBuyinfo.h"
#include"IconBuyinfo.h"
#include"SelectLayerinfo.h"
#include"SceneBuy.h"
using namespace cocos2d;
using namespace cocos2d::ui;
using namespace std;
SceneBuy* SceneBuy::create(int idx,int idx1)
{
	SceneBuy* buy = new SceneBuy;
	if (buy&&buy->init(idx,idx1))
	{
		buy->autorelease();
	}
	else{
		delete buy;
		buy = nullptr;
	}
	return buy;
}
bool SceneBuy::init(int idx,int idx1)
{
	if (!Scene::init())
	{
		return false;
	}
	else
	{	
		FileUtils::getInstance()->addSearchPath("IconBuyinfo");
		Size visible = Director::getInstance()->getVisibleSize();
		Vec2 originpos = Director::getInstance()->getVisibleOrigin();
		Vec2 centerPos = Vec2(
			originpos.x + visible.width / 2,
			originpos.y + visible.height / 2);
		//背景
		Sprite* spbg = Sprite::create("slectpet_back0.jpg");
		//底部按钮背景
		Sprite* spbtbg = Sprite::create("store_backback.png");
		this->addChild(spbtbg);
		spbtbg->setPosition(originpos.x + visible.width / 2,
			originpos.y + spbtbg->getContentSize().height / 2);
		//返回按钮
		Button* btnback = Button::create("back_btn.png");
		spbtbg->addChild(btnback);
		btnback->setPosition(Vec2(72, 36));
		btnback->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, SceneGameHall::create());
			Director::getInstance()->replaceScene(fade);
		});
		for (int i = 0; i < 3; i++)
		{	
			sp[i] = Sprite::create();
			sp[i]->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
			sp[i]->setPosition(0, spbtbg->getContentSize().height);
			this->addChild(sp[i]);
		}
		//第一个精灵
		//1
		spitem1[0] = Sprite::create("store_itemback.png");
		sp[0]->addChild(spitem1[0]);
		spitem1[0]->setPosition(15+spitem1[0]->getContentSize().width/2,spitem1[0]->getContentSize().height/2);
		auto sppower1 = Sprite::create("store_buypowericon.png");
		spitem1[0]->addChild(sppower1);
		sppower1->setPosition(spitem1[0]->getContentSize().width / 2, 
			spitem1[0]->getContentSize().height / 2 + sppower1->getContentSize().height/2);
		TextAtlas* ls1 = TextAtlas::create("10", "buynumber.png", 30, 34, "0");
		spitem1[0]->addChild(ls1);
		ls1->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 + ls1->getContentSize().width/2, spitem1[0]->getContentSize().height / 2-20));
		Rect rect = Rect(Vec2(300,0),Size(30,34));
		auto spx1 = Sprite::create("buynumber.png", rect);
		spitem1[0]->addChild(spx1);
		spx1->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 - spx1->getContentSize().width/2, spitem1[0]->getContentSize().height / 2-20));
		auto sp_demo1 = Sprite::create("ui_gemicon.png");
		spitem1[0]->addChild(sp_demo1);
		sp_demo1->setPosition(45, 50);
		auto ls_1 = TextAtlas::create("22","priceNumber.png",22,21,"0");
		spitem1[0]->addChild(ls_1);
		ls_1->setPosition(Vec2(spitem1[0]->getContentSize().width / 2, 50));
		//2
		spitem1[1] = Sprite::create("store_itemback.png");
		sp[0]->addChild(spitem1[1]);
		spitem1[1]->setPosition(spitem1[0]->getPositionX()+15+spitem1[1]->getContentSize().width, spitem1[1]->getContentSize().height / 2);
		auto sppower2 = Sprite::create("store_buypowericon.png");
		spitem1[1]->addChild(sppower2);
		sppower2->setPosition(spitem1[1]->getContentSize().width / 2, spitem1[1]->getContentSize().height / 2 + sppower1->getContentSize().height / 2);
		TextAtlas* ls2 = TextAtlas::create("20", "buynumber.png", 30, 34, "0");
		spitem1[1]->addChild(ls2);
		ls2->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 + ls2->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2 - 20));
		auto spx2 = Sprite::create("buynumber.png", rect);
		spitem1[1]->addChild(spx2);
		spx2->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 - spx2->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2 - 20));
		auto sp_demo2 = Sprite::create("ui_gemicon.png");
		spitem1[1]->addChild(sp_demo2);
		sp_demo2->setPosition(45, 50);
		auto ls_2 = TextAtlas::create("42", "priceNumber.png", 22, 21, "0");
		spitem1[1]->addChild(ls_2);
		ls_2->setPosition(Vec2(spitem1[0]->getContentSize().width / 2, 50));
		//3
		spitem1[2] = Sprite::create("store_itemback.png");
		sp[0]->addChild(spitem1[2]);
		spitem1[2]->setPosition(spitem1[1]->getPositionX() + 15+spitem1[1]->getContentSize().width, spitem1[2]->getContentSize().height / 2);
		auto sppower3 = Sprite::create("store_buypowericon.png");
		spitem1[2]->addChild(sppower3);
		sppower3->setPosition(spitem1[2]->getContentSize().width / 2, spitem1[2]->getContentSize().height / 2 + sppower1->getContentSize().height / 2);
		TextAtlas* ls3 = TextAtlas::create("50", "buynumber.png", 30, 34, "0");
		spitem1[2]->addChild(ls3);
		ls3->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 + ls3->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2 - 20));
		auto spx3 = Sprite::create("buynumber.png", rect);
		spitem1[2]->addChild(spx3);
		spx3->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 - spx3->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2 - 20));
		auto sp_demo3 = Sprite::create("ui_gemicon.png");
		spitem1[2]->addChild(sp_demo3);
		sp_demo3->setPosition(45, 50);
		auto ls_3 = TextAtlas::create("88", "priceNumber.png", 22, 21, "0");
		spitem1[2]->addChild(ls_3);
		ls_3->setPosition(Vec2(spitem1[0]->getContentSize().width / 2, 50));
		//第二个精灵
		//1
		spitem2[0] = Sprite::create("store_itemback.png");
		sp[1]->addChild(spitem2[0]);
		spitem2[0]->setPosition(15 + spitem1[0]->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2);
		auto spicon1 = Sprite::create("store_buycoinsicon.png");
		spitem2[0]->addChild(spicon1);
		spicon1->setPosition(spitem2[0]->getContentSize().width / 2, 
			spitem2[0]->getContentSize().height / 2 + spicon1->getContentSize().height/2);
		TextAtlas* ls4 = TextAtlas::create("2500", "buynumber.png", 30, 34, "0");
		spitem2[0]->addChild(ls4);
		ls4->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 +10, spitem1[0]->getContentSize().height / 2 - 20));
		auto spx4 = Sprite::create("buynumber.png", rect);
		spitem2[0]->addChild(spx4);
		spx4->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 - spx4->getContentSize().width / 2-50, spitem1[0]->getContentSize().height / 2 - 20));
		auto sp_demo4 = Sprite::create("ui_gemicon.png");
		spitem2[0]->addChild(sp_demo4);
		sp_demo4->setPosition(45, 50);
		auto ls_4 = TextAtlas::create("28", "priceNumber.png", 22, 21, "0");
		spitem2[0]->addChild(ls_4);
		ls_4->setPosition(Vec2(spitem1[0]->getContentSize().width / 2, 50));
		//2
		spitem2[1] = Sprite::create("store_itemback.png");
		sp[1]->addChild(spitem2[1]);
		spitem2[1]->setPosition(spitem1[0]->getPositionX() + 15 + spitem1[1]->getContentSize().width, spitem1[1]->getContentSize().height / 2);
		auto spicon2 = Sprite::create("store_buycoinsicon.png");
		spitem2[1]->addChild(spicon2);
		spicon2->setPosition(spitem2[1]->getContentSize().width / 2, spitem2[1]->getContentSize().height / 2 + spicon1->getContentSize().height / 2);
		TextAtlas* ls5 = TextAtlas::create("10000", "buynumber.png", 30, 34, "0");
		spitem2[1]->addChild(ls5);
		ls5->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 + 10, spitem1[0]->getContentSize().height / 2 - 20));
		auto spx5 = Sprite::create("buynumber.png", rect);
		spitem2[1]->addChild(spx5);
		spx5->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 - spx5->getContentSize().width / 2-60, spitem1[0]->getContentSize().height / 2 - 20));
		auto sp_demo5 = Sprite::create("ui_gemicon.png");
		spitem2[1]->addChild(sp_demo5);
		sp_demo5->setPosition(45, 50);
		auto ls_5 = TextAtlas::create("98", "priceNumber.png", 22, 21, "0");
		spitem2[1]->addChild(ls_5);
		ls_5->setPosition(Vec2(spitem1[0]->getContentSize().width / 2, 50));
		//3
		spitem2[2] = Sprite::create("store_itemback.png");
		sp[1]->addChild(spitem2[2]);
		spitem2[2]->setPosition(spitem1[1]->getPositionX() + 15 + spitem1[1]->getContentSize().width, spitem1[2]->getContentSize().height / 2);
		auto spicon3 = Sprite::create("store_buycoinsicon.png");
		spitem2[2]->addChild(spicon3);
		spicon3->setPosition(spitem2[2]->getContentSize().width / 2, spitem2[2]->getContentSize().height / 2 + spicon1->getContentSize().height / 2);
		TextAtlas* ls6 = TextAtlas::create("50000", "buynumber.png", 30, 34, "0");
		spitem2[2]->addChild(ls6);
		ls6->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 + 10, spitem1[0]->getContentSize().height / 2 - 20));
		auto spx6 = Sprite::create("buynumber.png", rect);
		spitem2[2]->addChild(spx6);
		spx6->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 - spx6->getContentSize().width / 2-60, spitem1[0]->getContentSize().height / 2 - 20));
		auto sp_demo6 = Sprite::create("ui_gemicon.png");
		spitem2[2]->addChild(sp_demo6);
		sp_demo6->setPosition(45, 50);
		auto ls_6 = TextAtlas::create("98", "priceNumber.png", 22, 21, "0");
		spitem2[2]->addChild(ls_6);
		ls_6->setPosition(Vec2(spitem1[0]->getContentSize().width / 2, 50));
		//第三个精灵
		//1
		spitem3[0] = Sprite::create("store_itemback.png");
		sp[2]->addChild(spitem3[0]);
		spitem3[0]->setPosition(15 + spitem1[0]->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2);
		auto spdemo1 = Sprite::create("store_buygemicon.png");
		spitem3[0]->addChild(spdemo1);
		spdemo1->setPosition(spitem3[0]->getContentSize().width / 2, 
			spitem3[0]->getContentSize().height / 2 + spdemo1->getContentSize().height/2);
		TextAtlas* ls7 = TextAtlas::create("60", "buynumber.png", 30, 34, "0");
		spitem3[0]->addChild(ls7);
		ls7->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 + ls7->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2 - 20));
		auto spx7 = Sprite::create("buynumber.png", rect);
		spitem3[0]->addChild(spx7);
		spx7->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 - spx7->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2 - 20));
		auto sp_mon1 = Sprite::create("store_buypays.png");
		spitem3[0]->addChild(sp_mon1);
		sp_mon1->setScale(0.8f);
		sp_mon1->setPosition(45, 50);
		auto ls_7 = TextAtlas::create("6", "priceNumber.png", 22, 21, "0");
		spitem3[0]->addChild(ls_7);
		ls_7->setPosition(Vec2(spitem1[0]->getContentSize().width / 2, 50));
		//2
		spitem3[1] = Sprite::create("store_itemback.png");
		sp[2]->addChild(spitem3[1]);
		spitem3[1]->setPosition(spitem1[0]->getPositionX() + 15 + spitem1[1]->getContentSize().width, spitem1[1]->getContentSize().height / 2);
		auto spdemo2 = Sprite::create("store_buygemicon.png");
		spitem3[1]->addChild(spdemo2);
		spdemo2->setPosition(spitem3[1]->getContentSize().width / 2, spitem3[1]->getContentSize().height / 2 + spdemo1->getContentSize().height / 2);
		TextAtlas* ls8 = TextAtlas::create("120", "buynumber.png", 30, 34, "0");
		spitem3[1]->addChild(ls8);
		ls8->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 + ls8->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2 - 20));
		auto spx8 = Sprite::create("buynumber.png", rect);
		spitem3[1]->addChild(spx8);
		spx8->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 - spx8->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2 - 20));
		auto sp_mon2 = Sprite::create("store_buypays.png");
		spitem3[1]->addChild(sp_mon2);
		sp_mon2->setScale(0.8f);
		sp_mon2->setPosition(45, 50);
		auto ls_8 = TextAtlas::create("12", "priceNumber.png", 22, 21, "0");
		spitem3[1]->addChild(ls_8);
		ls_8->setPosition(Vec2(spitem1[0]->getContentSize().width / 2, 50));
		//3
		spitem3[2] = Sprite::create("store_itemback.png");
		sp[2]->addChild(spitem3[2]);
		spitem3[2]->setPosition(spitem1[1]->getPositionX() + 15 + spitem1[1]->getContentSize().width, spitem1[2]->getContentSize().height / 2);
		auto spdemo3 = Sprite::create("store_buygemicon.png");
		spitem3[2]->addChild(spdemo3);
		spdemo3->setPosition(spitem3[2]->getContentSize().width / 2, spitem3[2]->getContentSize().height / 2 + spdemo1->getContentSize().height / 2);
		TextAtlas* ls9 = TextAtlas::create("500", "buynumber.png", 30, 34, "0");
		spitem3[2]->addChild(ls9);
		ls9->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 + ls9->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2 - 20));
		auto spx9 = Sprite::create("buynumber.png", rect);
		spitem3[2]->addChild(spx9);
		spx9->setPosition(Vec2(spitem1[0]->getContentSize().width / 2 - spx9->getContentSize().width / 2, spitem1[0]->getContentSize().height / 2 - 20));
		auto sp_mon3 = Sprite::create("store_buypays.png");
		spitem3[2]->addChild(sp_mon3);
		sp_mon3->setScale(0.8f);
		sp_mon3->setPosition(45, 50);
		auto ls_9 = TextAtlas::create("50", "priceNumber.png", 22, 21, "0");
		spitem3[2]->addChild(ls_9);
		ls_9->setPosition(Vec2(spitem1[0]->getContentSize().width / 2, 50));
		//底部蓝色条框
		Sprite* spblue = Sprite::create("store_buttonback.png");
		spbtbg->addChild(spblue);
		spblue->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		if (1 == idx1)
		{
			sp[0]->setVisible(true);
			sp[1]->setVisible(false);
			sp[2]->setVisible(false);
			spblue->setPosition(142+spblue->getContentSize().width/2,
				spblue->getContentSize().height/2);
		}
		else if (2 == idx1)
		{
			sp[0]->setVisible(false);
			sp[1]->setVisible(true);
			sp[2]->setVisible(false);
			spblue->setPosition(380 + spblue->getContentSize().width / 2,
				spblue->getContentSize().height / 2);
		}
		else if (3 == idx1)
		{
			sp[0]->setVisible(false);
			sp[1]->setVisible(false);
			sp[2]->setVisible(true);
			spblue->setPosition(617 + spblue->getContentSize().width / 2,
				spblue->getContentSize().height / 2);
		}
		//体力购买
		Button* btnpower = Button::create("store_buypowertips.png");
		spbtbg->addChild(btnpower);
		btnpower->setPosition(Vec2(148 + spblue->getContentSize().width / 2,
			spblue->getContentSize().height / 2));
		btnpower->addClickEventListener([this,btnpower, spblue](Ref* ref){
			sp[0]->setVisible(true);
			sp[1]->setVisible(false);
			sp[2]->setVisible(false);
			MoveTo* move = MoveTo::create(0.5f, Vec2(btnpower->getPosition()));	
			spblue->runAction(move);
		});
		//金币购买按钮
		Button* btnicon = Button::create("store_buycoinstips.png");
		spbtbg->addChild(btnicon);
		btnicon->setPosition(Vec2(380 + spblue->getContentSize().width / 2,
			spblue->getContentSize().height / 2));
		btnicon->addClickEventListener([this, btnicon, spblue](Ref* ref){
			sp[0]->setVisible(false);
			sp[1]->setVisible(true);
			sp[2]->setVisible(false);
			MoveTo* move = MoveTo::create(0.5f, btnicon->getPosition());
			spblue->runAction(move);
		});
		//钻石购买
		Button* btndemo = Button::create("store_buygemtips.png");
		spbtbg->addChild(btndemo);
		btndemo->setPosition(Vec2(617 + spblue->getContentSize().width / 2,
			spblue->getContentSize().height / 2)
			);
		btndemo->addClickEventListener([this, spblue, btndemo](Ref* ref){
			sp[0]->setVisible(false);
			sp[1]->setVisible(false);
			sp[2]->setVisible(true);
			MoveTo* move = MoveTo::create(0.5f, btndemo->getPosition());
			spblue->runAction(move);
		});
		return true;
	}
}