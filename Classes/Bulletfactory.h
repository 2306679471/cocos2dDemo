#pragma once
#include"Cbullet.h"
#include"cocos2d.h"
class Bulletfactory
{
public:
	static Cbullet* create(const Herotype& type, cocos2d::Vec2);
};