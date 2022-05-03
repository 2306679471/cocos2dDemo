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
	// 默认调度器（返回值、函数名、形参表都不可以改）
	void update(float dt);
	// 产生怪物
	void produceMonster(float dt);
	// 更新怪物
	void updateMonster(float dt);
	//产生boss
	void produceBoss();
	//更新boss
	void updateBoss(float dt);
	void attack(float dt);
	void updateBullet(float dt);
	void setCannonRotation(cocos2d::Vec2 touchpos);
	void HeroBulletCollisionMonster();
	void sethpbar();
	void setgoldbar();
	void HeroCollisionMonster();
	void setGamestate();
	void HeroMonsterbulletCollision();//怪物的子弹跟英雄的碰撞检测
	void monsterattack(float dt);
	void HeroBulletCollisionBoss();
	void HeroCollisionBossBullet();
private:

	int m_gold,m_Maxgold;//怪物掉落的金币
	int m_getgold;//获得的金币,保存到本地
	int m_distence;//距离
	int m_score;//得分
	float m_fProduceMonsterTimer;
	float m_fProduceMonsterDuration;
	float m_fbulletattackTimer;
	float m_fbulletattackDuration;
	bool istouched;
	//炮管
	cocos2d::Sprite* spCannon;
	cocos2d::Size visibleSize;
	cocos2d::Sprite* spBg2_1;
	cocos2d::Sprite* spBg2_2;
	cocos2d::Sprite* spfly;
	//英雄成员变量
	Chero* m_hero;                    
	cocos2d::Vec2 m_speed;
	LoadingBar* m_hpBar;
	LoadingBar* m_goldBar;
	cocos2d::Label* m_pf;//用来显示评分的数字
	cocos2d::Label* m_jl;//用来显示距离的数字
	Management *man;
	Cboss* m_boss;
};