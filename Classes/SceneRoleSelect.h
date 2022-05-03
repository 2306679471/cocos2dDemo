#pragma once
#include"cocos2d.h"
#include"ui\CocosGUI.h"
#define M 5
class SceneRoleSelect : public cocos2d::Scene
{
public:
	static SceneRoleSelect* create();
	virtual bool init();
	int isclik[M];
	int isbuy[M];
	void initstate();
	std::vector<cocos2d::Sprite* > sp;
	const char* gb23122utf8(const char* gb2312);
};