#pragma once 
#include"Cmonster.h"
class Cmonstershark : public Cmonster
{
public:
	static Cmonstershark* create();
	virtual bool init();
	void move(float dt);
};