#include "Cmonsterpig.h"
#include "Cmonsterchicken.h"
#include"Cmonstershark.h"
#include"Cmonstermachine.h"
class MonsterFactory
{
public:
	static Cmonster* create(const MonsterType type);
};
