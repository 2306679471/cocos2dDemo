#pragma once
#include"cocos2d.h"
class SelectLayerinfo : public cocos2d::Layer
{
public:
	static SelectLayerinfo* create(const std::string & filename);
	virtual bool init(const std::string & filename);
	//底部文字精灵
	cocos2d::Sprite* sp;
	//背景精灵
	cocos2d::Sprite* spbg;
	//底部框精灵
	cocos2d::Sprite* spbotk;

};