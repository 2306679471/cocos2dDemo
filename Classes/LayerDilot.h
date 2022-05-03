#include"cocos2d.h"
enum SPRITE_TYPE
{
	FILENAME,
	FRAME
};
class LayerDilot : public cocos2d::Layer
{
public:
	static LayerDilot* create(const std::string filename, SPRITE_TYPE type);
	virtual bool init(const std::string filename, SPRITE_TYPE type);
};