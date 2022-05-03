#pragma once
#include"cocos2d.h"
#define N 3
class SceneFlybrowSelect : public cocos2d::Scene
{
public:
	static SceneFlybrowSelect* create();
	virtual bool init();
	std::vector<cocos2d::Sprite*> sp;
	int isclik[N];
	int isbuy[N];
	void initstate();
	const char* gb23122utf8(const char* gb2312);
};