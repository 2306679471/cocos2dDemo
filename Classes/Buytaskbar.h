#pragma once
#include"cocos2d.h"
#include "ui/CocosGUI.h"
class Buytaskbar : public cocos2d::ui::ImageView
{
	//第一个为道具文件名
public:
	static cocos2d::Sprite* create(char* itemname);
};