#pragma once
#include "cocos2d.h"
class SceneGameReady : public cocos2d::Scene
{
public:
	static SceneGameReady* create();
	// ≥ı ºªØ
	virtual bool init();
	const char* gb23122utf8(const char* gb2312);
};