#pragma once
#include"cocos2d.h"
#include"ui\CocosGUI.h"
enum Herotype
{
	HERO_ONE,
	HERO_TWO,
	HERO_THREE,
	HERO_FOUR
};
class Chero : public cocos2d::Sprite
{
public:
	static Chero* create(const std::string filename);
	virtual bool init(const std::string filename);
	// 修改血量
	void setHp(int hp)
	{
		m_nHp = hp;
	}
	// 获取血量
	int getHp()
	{
		return m_nHp;
	}
	
	int m_nHp,m_nMaxHp;
	
};