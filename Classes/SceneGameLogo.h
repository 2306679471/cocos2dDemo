#pragma once
#include"cocos2d.h"
//二段构建
class SceneGameLogo : public cocos2d::Scene
{
public:
	//创建 通过类名可以调用
	static Scene* create();
	//初始化
	virtual bool init();
};