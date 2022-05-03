#pragma once
#include"cocos2d.h"

class PowerBuyinfo : public cocos2d::Scene
{
public:
	static PowerBuyinfo* create(int idx);
	virtual bool init(int idx);
};