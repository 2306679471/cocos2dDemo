#include"SceneRoleSelect.h"
#include"SelectLayerinfo.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace cocos2d::ui;
void SceneRoleSelect::initstate()
{	
	isclik[0] = 1; isbuy[0] = 1;
	for (int i = 1; i < M; i++)
	{
		isclik[i] = 0;
		isbuy[i] = 0;
	}
}
SceneRoleSelect* SceneRoleSelect::create()
{
	SceneRoleSelect* role = new SceneRoleSelect;
	if (role&&role->init())
	{
		role->autorelease();
	}
	else{
		delete role;
		role = nullptr;
	}
	return role;
}
bool SceneRoleSelect::init()
{
	if (!Scene::init())
	{
		return false;
	}
	else{
		initstate();
		FileUtils::getInstance()->addSearchPath("SceneSelect");
		Size visible = Director::getInstance()->getVisibleSize();
		Vec2 originpos = Director::getInstance()->getVisibleOrigin();
		SelectLayerinfo* sinfo = SelectLayerinfo::create("selectactor_tips.png");
		sinfo->setPosition(originpos);
		this->addChild(sinfo);
		//创建翻页视图
		// 1.创建翻页视图
		PageView* pageView = PageView::create();
		// 2.添加到场景
		sinfo->addChild(pageView);
		// 设置大小
		pageView->setContentSize(Size(originpos.x + 270, originpos.y+334));
		//  PageView的默认锚点在左下角
		pageView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		// 开启交互
		pageView->setEnabled(true);
		pageView->setPosition(Vec2(sinfo->getContentSize().width/2,this->getContentSize().height/2));
		pageView->setClippingEnabled(false);
		char filename[64];
		for (int i = 0; i < M; i++)
		{
			// 创建布局
			Layout* layout = Layout::create();
			layout->setContentSize(pageView->getContentSize());
			// 添加图片视图(添加点击事件)
			ImageView* imageView = ImageView::create("select_iconback0.png");
			imageView->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
			//高光精灵背景
			Sprite* sphl = Sprite::create("select_iconback0.png");
			sp.push_back(sphl);
			imageView->addChild(sphl);
			sphl->setPosition(imageView->getContentSize().width / 2,
				imageView->getContentSize().height / 2);
			sphl->setVisible(false);
			// 开启触摸监听
			imageView->setTouchEnabled(true);
			layout->addChild(imageView);
			pageView->addPage(layout);
			sp[0]->setVisible(true);
			imageView->addClickEventListener([this,i](Ref* ref){
				for (int n = 0; n < M; n++)
				{ 
					if (1 == this->isbuy[n])
					{
						if (1 == this->isclik[n])
							{
								sp[n]->setVisible(false);
								sp[i]->setVisible(true);
								isclik[n] = 0;
							}
					}
					else
					{
						continue;
					}
					
				}
				isclik[i] = 1;
			});
			//添加购买按钮
			Button* btn = Button::create("select_buyback0.png");
			imageView->addChild(btn);
			btn->setPosition(Vec2(sp[i]->getContentSize().width / 2, 0));
			btn->addClickEventListener([this, i](Ref* ref){
				this->isbuy[i] = 1;
			});
			//添加英雄图片
			std::sprintf(filename, "selectactor_actoricon%d.png", i);
			Sprite* spHero = Sprite::create(filename);
			imageView->addChild(spHero);
			spHero->setPosition(Vec2(imageView->getContentSize().width / 2 - 10,
				imageView->getContentSize().height / 2 + 15));
			spHero->setScale(0.75f);
		}
		return true;
	}
}
const char* SceneRoleSelect::gb23122utf8(const char* gb2312)
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