#include"Cmonster.h"
class Cmonstermachine :public Cmonster
{
public:
	static Cmonstermachine* create();
	virtual bool init();
	void move(float dt);
};