#pragma once
#include"cocos2d.h"
class Myanimation 
{
public:
	//文件名要求必须为png，不带后缀，不带数字变量
	//第一帧
	//最后一帧
	//每一帧之间的间隔时间
	//循环次数
	//是否回到第一帧
	static cocos2d::Animate* create(const char* filename, int first, int end, float delayperunit, unsigned int loops, bool restoreOriginalFrame);
};