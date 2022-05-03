#pragma once
#include"Cmonster.h"
class Cmonsterpig : public Cmonster
{
public:
	static Cmonsterpig* create();
	virtual bool init();
	virtual void move(float dt);
};