#pragma once
#include"cocos2d.h"
class Myanimation 
{
public:
	//�ļ���Ҫ�����Ϊpng��������׺���������ֱ���
	//��һ֡
	//���һ֡
	//ÿһ֮֡��ļ��ʱ��
	//ѭ������
	//�Ƿ�ص���һ֡
	static cocos2d::Animate* create(const char* filename, int first, int end, float delayperunit, unsigned int loops, bool restoreOriginalFrame);
};