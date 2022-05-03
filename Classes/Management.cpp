#include"cocos2d.h"
#include"Management.h"
using namespace cocos2d;
void Management::setMonster(Cmonster* monster)
{
	vMonster.pushBack(monster);
}
void Management::setBullet(Cbullet* bullet)
{
	vBullet.pushBack(bullet);
}
void Management::setmonbullet(Sprite* monbullet)
{
	vmonbullet.pushBack(monbullet);
}
Vector<Cmonster*>& Management::getmonstervector()
{
	return vMonster;
}
Vector<Cbullet*>& Management::getbulletvector()
{
	return vBullet;
}
Vector<Sprite*>& Management::getmonbulletvector()
{
	return vmonbullet;
}
Management* Management::getinstance()
{
	if (m_management == nullptr)
	{
		m_management = new Management();
	}
	return m_management;
}
void Management::setisgameover(bool is)
{
	m_isgameover = is;
}
bool Management::getisgameover()
{
	return m_isgameover;
}
Management* Management::m_management = nullptr;