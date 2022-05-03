#pragma once
#include "cocos2d.h"
class Layerinfo : public cocos2d::Layer
{
public:
	static Layerinfo* create();
	// 初始化
	virtual bool init();


	// 金币动画精灵对象
	cocos2d::Sprite* spGoldAni;
	//钻石动画精灵
	cocos2d::Sprite* spDemoAni;
	// 体力
	cocos2d::Sprite* spTili[5];
	// 体力max图标
	cocos2d::Sprite* spTiliMax;


	// 播放动画递归函数
	void playAnimation();
};