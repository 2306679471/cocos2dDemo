#include"Myanimation.h"
using namespace cocos2d;
Animate* Myanimation::create(const char* filename,int first,int end,float delayperunit,unsigned int loops,bool restoreOriginalFrame)
{

	//播放动画
	Animation* animation = Animation::create();
	char file[64];
	for (int i = first; i <=end; i++)
	{
		sprintf(file, "%s%d.png",filename,i);
		animation->addSpriteFrameWithFile(file);
	}
	//每一帧间隔时间
	animation->setDelayPerUnit(delayperunit);
	//设置循环次数
	animation->setLoops(loops);
	//动画是否显示起始帧
	animation->setRestoreOriginalFrame(restoreOriginalFrame);
	//创建帧动作
	Animate* animate = Animate::create(animation);
	return animate;
}
