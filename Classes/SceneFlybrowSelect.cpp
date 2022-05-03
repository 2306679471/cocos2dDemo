#include"SceneFlybrowSelect.h"
#include"Layerinfo.h"
#include"SelectLayerinfo.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace cocos2d::ui;
void SceneFlybrowSelect::initstate()
{
	isclik[0] = 1; isbuy[0] = 1;
	for (int i = 1; i < N; i++)
	{
		isclik[i] = 0;
		isbuy[i] = 0;
	}
}
SceneFlybrowSelect* SceneFlybrowSelect::create()
{
	SceneFlybrowSelect* flybrow = new SceneFlybrowSelect;
	if (flybrow&&flybrow->init())
	{
		flybrow->autorelease();
	}
	else
	{
		delete flybrow;
		flybrow = nullptr;
	}
	return flybrow;
}
bool SceneFlybrowSelect::init()
{
	if (!Scene::init())
	{
		return false;
	}
	else
	{
		initstate();
		FileUtils::getInstance()->addSearchPath("SceneSelect");
		Size visible = Director::getInstance()->getVisibleSize();
		Vec2 originpos = Director::getInstance()->getVisibleOrigin();
		SelectLayerinfo* sinfo = SelectLayerinfo::create("selectairship_tips.png");
		sinfo->setPosition(originpos);
		this->addChild(sinfo);
		PageView* pageview = PageView::create();
		sinfo->addChild(pageview);
		pageview->setContentSize(Size(originpos.x + 270, originpos.y + 334));
		pageview->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		// ¿ªÆô½»»¥
		pageview->setEnabled(true);
		pageview->setPosition(Vec2(sinfo->getContentSize().width / 2, this->getContentSize().height / 2));
		pageview->setClippingEnabled(false);
		char filename[64];
		
		for (int i = 0; i < N; i++)
		{
			
			Layout* layout = Layout::create();
			layout->setContentSize(pageview->getContentSize());
			ImageView* imageview = ImageView::create("select_iconback0.png");
			imageview->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
			imageview->setTouchEnabled(true);
			Sprite* sphl = Sprite::create("select_iconback0.png");
			sp.push_back(sphl);
			imageview->addChild(sphl);
			sphl->setPosition(imageview->getContentSize().width / 2,
				imageview->getContentSize().height / 2);
			sphl->setVisible(false);
			layout->addChild(imageview);
			pageview->addPage(layout);
			imageview->addClickEventListener([this, i](Ref* ref){
				for (int n = 0; n < N; n++)
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
			//Ìí¼Ó¹ºÂò°´Å¥
			Button* btn = Button::create("select_buyback0.png");
			imageview->addChild(btn);
			btn->setPosition(Vec2(sp[i]->getContentSize().width / 2, 0));
			btn->addClickEventListener([this, i](Ref* ref){
				this->isbuy[i] = 1;
			});
			//Ìí¼ÓÓ¢ÐÛÍ¼Æ¬
			std::sprintf(filename, "selectairship_airshipicon%d.png", i);
			Sprite* spFlybrow = Sprite::create(filename);
			imageview->addChild(spFlybrow);
			spFlybrow->setPosition(Vec2(imageview->getContentSize().width / 2 - 10,
				imageview->getContentSize().height / 2 + 15));
			spFlybrow->setScale(0.75f);
		}
		
		return true;
	}
}
const char* SceneFlybrowSelect::gb23122utf8(const char* gb2312)
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