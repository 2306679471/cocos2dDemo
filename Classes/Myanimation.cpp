#include"Myanimation.h"
using namespace cocos2d;
Animate* Myanimation::create(const char* filename,int first,int end,float delayperunit,unsigned int loops,bool restoreOriginalFrame)
{

	//���Ŷ���
	Animation* animation = Animation::create();
	char file[64];
	for (int i = first; i <=end; i++)
	{
		sprintf(file, "%s%d.png",filename,i);
		animation->addSpriteFrameWithFile(file);
	}
	//ÿһ֡���ʱ��
	animation->setDelayPerUnit(delayperunit);
	//����ѭ������
	animation->setLoops(loops);
	//�����Ƿ���ʾ��ʼ֡
	animation->setRestoreOriginalFrame(restoreOriginalFrame);
	//����֡����
	Animate* animate = Animate::create(animation);
	return animate;
}
