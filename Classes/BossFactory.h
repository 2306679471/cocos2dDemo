#pragma once
#include"Cboss.h"
#include"CbossShark.h"
#include"Cmachine.h"
class BossFactory
{
public:
	static Cboss* create(const BOSSTYPE& type);
};