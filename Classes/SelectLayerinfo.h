#pragma once
#include"cocos2d.h"
class SelectLayerinfo : public cocos2d::Layer
{
public:
	static SelectLayerinfo* create(const std::string & filename);
	virtual bool init(const std::string & filename);
	//�ײ����־���
	cocos2d::Sprite* sp;
	//��������
	cocos2d::Sprite* spbg;
	//�ײ�����
	cocos2d::Sprite* spbotk;

};