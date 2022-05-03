#include"LayerDilot.h"
using namespace cocos2d;
#include"ui\CocosGUI.h"
using namespace cocos2d::ui;

LayerDilot* LayerDilot::create(const std::string filename, SPRITE_TYPE type)
{
	LayerDilot* layer = new LayerDilot;
	if (layer&&layer->init(filename,type))
	{
		layer->autorelease();
	}
	else
	{
		delete layer;
		layer = nullptr;
	}
	return layer;
}
bool LayerDilot::init(const std::string filename , SPRITE_TYPE type)
{
	if (!Layer::init())
	{
		return false;
	}
	else
	{// ��ȡ���ӻ���������
		FileUtils::getInstance()->addSearchPath("GameHall");
		Size visibleSize = Director::getInstance()->getVisibleSize();
		// ���ӻ���������
		Vec2 originPos = Director::getInstance()->getVisibleOrigin();
		// ���ĵ�
		Vec2 centerPos = Vec2(
			originPos.x + visibleSize.width / 2,
			originPos.y + visibleSize.height / 2);
		//��ɫ����
		LayerColor* bg = LayerColor::create(Color4B(0, 0, 0, 127));
		this->addChild(bg);
		switch (type)
		{
		case FILENAME:
			//��Ӿ���
		{
			Sprite* sp = Sprite::create(filename);
		sp->setName("sp");
		this->addChild(sp);
		sp->setPosition(centerPos);
		break; 
		}
		case FRAME:
		{
				SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(filename);
				Sprite* sp1 = Sprite::createWithSpriteFrame(frame);
				sp1->setName("sp1");
				this->addChild(sp1);
				sp1->setPosition(centerPos);
				break;
		}
			
		}
		
		
		EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
		// �������ɴ���// ������ʼ���뷵��true
		listener->setSwallowTouches(true);
		
		listener->onTouchBegan = [this](Touch* touch, Event* event)
		{
			Vec2 touchpos = touch->getLocation();
			return true;
		};
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


		return true;
	}
}