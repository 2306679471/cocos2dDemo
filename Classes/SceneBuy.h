#pragma once
#include"cocos2d.h"
#include"ui/cocosGUI.h"
class SceneBuy : public cocos2d::Scene
{
public:
	static SceneBuy* create(int idx,int idx1);
	virtual bool init(int idx,int idx1);
	cocos2d::Sprite* sp[3];// ���о���ĸ��ڵ�
	cocos2d::Sprite* spitem1[3];
	cocos2d::Sprite* spitem2[3];
	cocos2d::Sprite* spitem3[3];
};