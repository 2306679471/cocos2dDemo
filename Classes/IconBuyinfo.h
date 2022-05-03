#pragma once 
#include"cocos2d.h"
class IconBuyinfo : public cocos2d::Scene
{
public:
	static IconBuyinfo* create(int idx);
	virtual bool init(int idx);
};