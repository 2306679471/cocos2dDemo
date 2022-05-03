#pragma once
#include"cocos2d.h"
#include"Cmonster.h"
#include"Cbullet.h"
#include"Management.h"
#include"Cboss.h"
class SceneGame : public cocos2d::Scene
{
public:
	static SceneGame* create();
	virtual bool init();
	// Ĭ�ϵ�����������ֵ�����������βα������Ըģ�
	void update(float dt);
	// ��������
	void produceMonster(float dt);
	// ���¹���
	void updateMonster(float dt);
	//����boss
	void produceBoss();
	//����boss
	void updateBoss(float dt);
	void attack(float dt);
	void updateBullet(float dt);
	void setCannonRotation(cocos2d::Vec2 touchpos);
	void HeroBulletCollisionMonster();
	void sethpbar();
	void setgoldbar();
	void HeroCollisionMonster();
	void setGamestate();
	void HeroMonsterbulletCollision();//������ӵ���Ӣ�۵���ײ���
	void monsterattack(float dt);
	void HeroBulletCollisionBoss();
	void HeroCollisionBossBullet();
private:

	int m_gold,m_Maxgold;//�������Ľ��
	int m_getgold;//��õĽ��,���浽����
	int m_distence;//����
	int m_score;//�÷�
	float m_fProduceMonsterTimer;
	float m_fProduceMonsterDuration;
	float m_fbulletattackTimer;
	float m_fbulletattackDuration;
	bool istouched;
	//�ڹ�
	cocos2d::Sprite* spCannon;
	cocos2d::Size visibleSize;
	cocos2d::Sprite* spBg2_1;
	cocos2d::Sprite* spBg2_2;
	cocos2d::Sprite* spfly;
	//Ӣ�۳�Ա����
	Chero* m_hero;                    
	cocos2d::Vec2 m_speed;
	LoadingBar* m_hpBar;
	LoadingBar* m_goldBar;
	cocos2d::Label* m_pf;//������ʾ���ֵ�����
	cocos2d::Label* m_jl;//������ʾ���������
	Management *man;
	Cboss* m_boss;
};