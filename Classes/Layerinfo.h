#pragma once
#include "cocos2d.h"
class Layerinfo : public cocos2d::Layer
{
public:
	static Layerinfo* create();
	// ��ʼ��
	virtual bool init();


	// ��Ҷ����������
	cocos2d::Sprite* spGoldAni;
	//��ʯ��������
	cocos2d::Sprite* spDemoAni;
	// ����
	cocos2d::Sprite* spTili[5];
	// ����maxͼ��
	cocos2d::Sprite* spTiliMax;


	// ���Ŷ����ݹ麯��
	void playAnimation();
};