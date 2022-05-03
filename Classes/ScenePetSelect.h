#pragma once
#include"cocos2d.h"
#define L 5
class ScenePetSelect : public cocos2d::Scene
{public:
	static ScenePetSelect* create();
	virtual bool init();
	std::vector<cocos2d::Sprite*> sp;
	int isclik[L];
	int isbuy[L];
	void initstate();
	const char* gb23122utf8(const char* gb2312);
};