#pragma once
#include"cocos2d.h"
#include "ui/CocosGUI.h"
class Buytaskbar : public cocos2d::ui::ImageView
{
	//��һ��Ϊ�����ļ���
public:
	static cocos2d::Sprite* create(char* itemname);
};