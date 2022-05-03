#pragma once 
#include"cocos2d.h"
class DemoBuyinfo : public cocos2d::Scene
{
public:
	static DemoBuyinfo* create(int idx);
	virtual bool init(int idxs);
};