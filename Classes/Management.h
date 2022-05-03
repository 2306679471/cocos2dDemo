#pragma once
#include"cocos2d.h"
#include"Cmonster.h"
#include"Cbullet.h"
#include"Cboss.h"
class Management
{
public:
	void setMonster(Cmonster* monster);
	void setBullet(Cbullet* bullet);
	void setmonbullet(cocos2d::Sprite* bullet);
	cocos2d::Vector<Cmonster*>& getmonstervector();
	cocos2d::Vector<Cbullet*>& getbulletvector();
	cocos2d::Vector<cocos2d::Sprite*>& getmonbulletvector();
	void setisgameover(bool is);
	bool getisgameover();
	static Management* getinstance();
private:	
	Management(){};
	static Management* m_management;
	cocos2d::Vector<Cmonster*> vMonster;
	cocos2d::Vector<Cbullet*> vBullet;
	cocos2d::Vector<cocos2d::Sprite*> vmonbullet;
	bool m_isgameover;
};