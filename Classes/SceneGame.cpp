#include "SceneGame.h"
#include"SceneGameReady.h"
#include"Chero.h"
#include"Myanimation.h"
#include"Monsterfactory.h"
#include"Bulletfactory.h"
#include"Cbullet.h"
#include"LayerDilot.h"
#include "ui/CocosGUI.h"
#include"BossFactory.h"
using namespace cocos2d;
using namespace cocos2d::ui;
SceneGame* SceneGame::create()
{
	SceneGame* scene = new SceneGame;
	if (scene&&scene->init())
	{
		scene->autorelease();
	}
	else{
		delete scene;
		scene = nullptr;
	}
	return scene;
}
bool SceneGame::init()
{
	if (!Scene::init())
	{
		return false;
	}
	else
	{
		// ��ȡ���ӻ���������
		visibleSize = Director::getInstance()->getVisibleSize();
		// ���ӻ���������
		Vec2 originPos = Director::getInstance()->getVisibleOrigin();
		// ���ĵ�
		Vec2 centerPos = Vec2(
			originPos.x + visibleSize.width / 2,
			originPos.y + visibleSize.height / 2);

		FileUtils::getInstance()->addSearchPath("GameScene");
		FileUtils::getInstance()->addSearchPath("GameScene/ingame/actor/actor0");
		spfly = Sprite::create("actor_airship0.png");
		this->addChild(spfly);
		spfly->setLocalZOrder(1);
		spfly->setPosition(0,spfly->getContentSize().height/2);
		spfly->setScale(1.2f);
		m_hero = Chero::create("actor_actor0_stand11.png");
		this->addChild(m_hero);
		m_hero->setLocalZOrder(2);
		m_hero->runAction(Myanimation::create(
			"actor_actor0_stand", 0, 11, 0.08f, -1, true
			));
		m_hero->setPosition(spfly->getContentSize().width/2-50,spfly->getContentSize().height/2);
		m_hero->setScale(1.2f);
		//������
		Sprite* sppf = Sprite::create("gamescene_numberback.png");
		this->addChild(sppf);
		sppf->setLocalZOrder(3);
		sppf->setPosition(visibleSize.width/2+sppf->getContentSize().width/2+15,
			visibleSize.height-sppf->getContentSize().height/2);
		Sprite* sppfwz = Sprite::create("gamescene_scorelabel.png");
		sppf->addChild(sppfwz);
		sppfwz->setPosition(sppfwz->getContentSize().width/2+10
			, sppf->getContentSize().height / 2);
		m_pf = Label::create();
		m_pf->setSystemFontName("fonts/arial.ttf");
		m_pf->setSystemFontSize(20);
		sppf->addChild(m_pf);
		m_pf->setPosition(sppf->getContentSize().width-m_pf->getContentSize().width/2-50,
			sppf->getContentSize().height/2);
		//������
		Sprite* spjl = Sprite::create("gamescene_numberback.png");
		this->addChild(spjl);
		spjl->setLocalZOrder(3);
		spjl->setPosition(visibleSize.width / 2 + sppf->getContentSize().width  + 15+spjl->getContentSize().width/2,
			visibleSize.height-spjl->getContentSize().height/2);
		Sprite* spjlwz = Sprite::create("gamescene_distancelabel.png");
		spjl->addChild(spjlwz);
		spjlwz->setPosition(spjlwz->getContentSize().width/2
			,spjl->getContentSize().height/2);
		m_jl = Label::create();
		spjl->addChild(m_jl);
		m_jl->setSystemFontName("fonts/arial.ttf");
		m_jl->setSystemFontSize(20);
		m_jl->setPosition(spjl->getContentSize().width-m_jl->getContentSize().width/2-50,spjl->getContentSize().height/2);
		//ֹͣ��ť
		Button* btnstop = Button::create("gamescene_pauseicon.png");
		this->addChild(btnstop);
		btnstop->setLocalZOrder(1);
		btnstop->setPosition(Vec2(visibleSize.width-btnstop->getContentSize().width/2,
			visibleSize.height - btnstop->getContentSize().height/2
			));
		btnstop->addClickEventListener([this](Ref* ref){
			this->unscheduleUpdate();
			LayerDilot* layer = LayerDilot::create("tmd.png", SPRITE_TYPE::FILENAME);
			this->addChild(layer, 99);
			//��ͣ���־���
			Sprite* spstop = Sprite::create("ztz.png");
			layer->getChildByName("sp")->addChild(spstop);
			spstop->setPosition(layer->getChildByName("sp")->getContentSize().width / 2, 
				layer->getChildByName("sp")->getContentSize().height - (spstop->getContentSize().height / 2) - 20);
			//������Ϸ��ť
			Button* btncontinue = Button::create("jxyx.png");
			layer->getChildByName("sp")->addChild(btncontinue);
			btncontinue->setPosition(Vec2(spstop->getPositionX(),
				layer->getChildByName("sp")->getContentSize().height / 2 + btncontinue->getContentSize().height 
				));
			btncontinue->setScale(0.8f);
			btncontinue->addClickEventListener([this, layer](Ref* ref){
				this->scheduleUpdate();
				layer->removeFromParent();
			});
			//���¿�ʼ��Ϸ
			Button* btnrestart = Button::create("cxks.png");
			layer->getChildByName("sp")->addChild(btnrestart);
			btnrestart->setPosition(Vec2(spstop->getPositionX(),
				layer->getChildByName("sp")->getContentSize().height / 2 - btnrestart->getContentSize().height / 4 
				));
			btnrestart->setScale(0.8f);
			btnrestart->addClickEventListener([](Ref* ref){
				TransitionFade* fade = TransitionFade::create(0.2f, SceneGame::create());
				Director::getInstance()->replaceScene(fade);
			});
			//�ص�������ť
			Button* btnback = Button::create("fhdt.png");
			layer->getChildByName("sp")->addChild(btnback);
			btnback->setPosition(Vec2(spstop->getPositionX(),
				layer->getChildByName("sp")->getContentSize().height / 3 - btnback->getContentSize().height / 2 - 10
				));
			btnback->setScale(0.8f);
			btnback->addClickEventListener([](Ref* ref){
				TransitionFade* fade = TransitionFade::create(0.2f, SceneGameReady::create());
				Director::getInstance()->replaceScene(fade);
			});
			//���ֿ��ذ�ť
			Button* btnmusicon = Button::create("yyk.png");
			layer->getChildByName("sp")->addChild(btnmusicon);
			btnmusicon->setPosition(Vec2(layer->getChildByName("sp")->getContentSize().width / 4-btnmusicon->getContentSize().width/2
				, btnrestart->getPositionY()));
			btnmusicon->setLocalZOrder(1);
			btnmusicon->addClickEventListener([btnmusicon](Ref* ref){
				btnmusicon->setVisible(false);
			});
			//
			Button* btnmusicoff = Button::create("yyg.png");
			layer->getChildByName("sp")->addChild(btnmusicoff);
			btnmusicoff->setPosition(Vec2(layer->getChildByName("sp")->getContentSize().width / 4 - btnmusicon->getContentSize().width / 2
				, btnrestart->getPositionY()));
			btnmusicoff->addClickEventListener([btnmusicon](Ref* ref){
				btnmusicon->setVisible(true);
			});
			//��Ч���ذ�ť
			Button* btnsoundon = Button::create("yxk.png");
			layer->getChildByName("sp")->addChild(btnsoundon);
			btnsoundon->setPosition(Vec2((layer->getChildByName("sp")->getContentSize().width / 4 * 3) + btnsoundon->getContentSize().width / 2
				, btnrestart->getPositionY()));
			btnsoundon->setLocalZOrder(1);
			btnsoundon->addClickEventListener([btnsoundon](Ref* ref){
				btnsoundon->setVisible(false);
			});
			Button* btnsoundoff = Button::create("yxg.png");
			layer->getChildByName("sp")->addChild(btnsoundoff);
			btnsoundoff->setPosition(Vec2((layer->getChildByName("sp")->getContentSize().width / 4 * 3) + btnsoundon->getContentSize().width / 2
				, btnrestart->getPositionY()));
			btnsoundoff->addClickEventListener([btnsoundon](Ref* ref){
				btnsoundon->setVisible(true);
			});
		});
		//��ҿս�����
		Sprite* spemptygoldbar = Sprite::create("gamescene_energyback.png");
		this->addChild(spemptygoldbar);
		spemptygoldbar->setPosition(originPos.x + visibleSize.width/2,spemptygoldbar->getContentSize().height/2);
		spemptygoldbar->setLocalZOrder(1);
		//��ҽ�����
		m_goldBar = LoadingBar::create("gamescene_energybar.png",100);
		this->addChild(m_goldBar);
		m_goldBar->setPosition(Vec2(spemptygoldbar->getPositionX() + 20, spemptygoldbar->getPositionY()));
		m_goldBar->setLocalZOrder(2);
		//��Ѫ��
		Sprite* spemptyhpbar = Sprite::create("gamescene_hpback.png");
		this->addChild(spemptyhpbar);
		spemptyhpbar->setPosition(spemptyhpbar->getContentSize().width/2,
			this->getContentSize().height - spemptyhpbar->getContentSize().height / 2);
		spemptyhpbar->setLocalZOrder(1);
		//Ѫ��
		m_hpBar = LoadingBar::create("gamescene_hpbar.png", 100);
		this->addChild(m_hpBar);
		m_hpBar->setPosition(Vec2(spemptyhpbar->getPositionX() + 20,
			spemptyhpbar->getPositionY())
			);
		m_hpBar->setLocalZOrder(2);
		
		//����
		Sprite* spbg1_1 = Sprite::create("ltyj.jpg");
		Sprite* spbg1_2 = Sprite::create("ltyj.jpg");
		this->addChild(spbg1_1);
		spbg1_1->addChild(spbg1_2);
		spbg1_1->setTag(1);
		spbg1_1->setPosition(centerPos);
		spbg1_2->setPosition(visibleSize.width / 2 * 3, visibleSize.height / 2);

		spBg2_1 = Sprite::create("ltzj.png");
		spBg2_2 = Sprite::create("ltzj.png");
		this->addChild(spBg2_1);
		spBg2_1->addChild(spBg2_2);
		spBg2_1->setPosition(centerPos);
		spBg2_2->setPosition(visibleSize.width / 2 * 3, visibleSize.height / 2);
		spCannon = Sprite::create("actor_cannon0_1.png");
		this->addChild(spCannon);
		spCannon->setPosition(spfly->getContentSize().width / 2 - 40, spfly->getContentSize().height / 2-70);
		spCannon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
		
		// 1.�����¼�������
		EventListenerTouchOneByOne* _listener = EventListenerTouchOneByOne::create();
		// 2.Ϊ����������¼�״̬Ԥ������
		_listener->onTouchBegan = [this](Touch* touch, Event* event)
		{
			// �ж��Ƿ��д�����Ӣ��(Ӣ�۰�Χ�У�������)
			
			// ������
			
			
			return true;
		};
		_listener->onTouchMoved = [this](Touch* touch, Event* event)
		{
			// ������
			Vec2 touchpos = touch->getLocation();
			// �޸��ڹܵĽǶ�
			setCannonRotation(touchpos);
			istouched = false;
			m_speed = (touch->getLocation() - spCannon->getPosition()).getNormalized();
		};
		_listener->onTouchEnded = [this](Touch* touch, Event* event)
		{
			
		};
		// 3.��ӵ��¼��ַ���
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listener, this);
		//����������
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("gameLayerResources.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("machineBoss.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shark.plist");
		srand(time(nullptr));
	
		m_score = 0;
		m_distence = 2800.0f;
		istouched = true;
		m_fbulletattackTimer = 0;
		m_fbulletattackDuration = 0.05f;
		m_fProduceMonsterTimer = 0;
		m_fProduceMonsterDuration = 1.0f;
		m_gold = 0;
		m_Maxgold = 100;
		m_getgold = 0;
		m_speed = Vec2(1000,0);
		man = Management::getinstance();
		m_boss = nullptr;
		this->scheduleUpdate();
		return true;
	}
}
void SceneGame::setCannonRotation(Vec2 touchpos)
{
	// �Ա�
	float aa = spCannon->getPositionY() - touchpos.y;
	// ���
	float bb = touchpos.x - spCannon->getPositionX();
	// ���ݷ����Ǻ����󻥻���
	float angle = atan(aa / bb);
	// ����ת�Ƕ�
	angle = angle * (180 / 3.1415926f);
	// �ѽǶ����ø��ڹ�
	spCannon->setRotation(angle);
}
void SceneGame::update(float dt)
{
	Sprite* spBg1_1 = (Sprite*)this->getChildByTag(1);
	// s = vt   
	float v = -100; //  ��λÿ�뱳���ƶ�������
	float s = v * dt;
	spBg1_1->setPositionX(spBg1_1->getPositionX() + s);
	if (spBg1_1->getPositionX() <= -(spBg1_1->getContentSize().width / 2))
	{
		spBg1_1->setPositionX(spBg1_1->getContentSize().width / 2);
	}
	v *= 1.5f;
	s = v * dt;
	spBg2_1->setPositionX(spBg2_1->getPositionX() + s);
	if (spBg2_1->getPositionX() <= -spBg2_1->getContentSize().width / 2)
	{
		spBg2_1->setPositionX(visibleSize.width / 2);
	}
	m_distence += dt * 100.0f;
	m_jl->setString(std::to_string(m_distence));
	//������Ϸ״̬
	setGamestate();
	//�����ӵ�
	attack(dt);
	//�ӵ��ƶ�
	updateBullet(dt);
	//���½�ҽ�����
	setgoldbar();
	//����Ӣ������ֵ��
	sethpbar();
	//��ײ���
	HeroBulletCollisionMonster();
	// ���¹���
	updateMonster(dt);
	//�������ͧ����ײ���
	HeroCollisionMonster();
	//Ӣ�۸����﷢���ӵ�����ײ���
	HeroMonsterbulletCollision();
	if (nullptr == m_boss)
	{
		// ��������
		produceMonster(dt);
		if (0 == (int)m_distence % 3000)
		{
			//����boss
			produceBoss();
		}
	}
	//����boss
	updateBoss(dt);	
	//boss����ײ���
	HeroBulletCollisionBoss();
	//boss�ӵ���Ӣ�۵���ײ���
	HeroCollisionBossBullet();
}
// ��������
void SceneGame::produceMonster(float dt)
{
	
	// �ۼӹ��������ʱ��
	m_fProduceMonsterTimer += dt;
	if (m_fProduceMonsterTimer >= m_fProduceMonsterDuration)
	{
		// ��ʱ������
		m_fProduceMonsterTimer = 0;

		// �����������
		MonsterType type = (MonsterType)(rand() % 2);
		// ͨ��������������
		Cmonster* pMonster = MonsterFactory::create(type);
		this->addChild(pMonster);
		
		float xx = visibleSize.width + pMonster->getContentSize().width / 2;
		float yy = rand() % (int)visibleSize.height;
		pMonster->setPosition(xx, yy);

		// ��������ӵ�����
		//vMonster.pushBack(pMonster);
		man->setMonster(pMonster);
	}
}
// ���¹���
void SceneGame::updateMonster(float dt)
{
	for (int i = 0; i < man->getmonstervector().size(); i++)
	{
		Cmonster* pMonster = man->getmonstervector().at(i);
		Rect fBoudingbox = spfly->getBoundingBox();
		// �ƶ�
		pMonster->move(dt);
		if (pMonster->getHp() <= 0 )
		{
			int pissiblity = rand() % 100;
			int pissiblityeng = rand() % 100;
			if (pissiblity > 0 && pissiblity <= 66)
			{

				auto object = Sprite::create();
				this->addChild(object);
				object->setPosition(pMonster->getPosition());
				object->runAction(Myanimation::create("gold", 0, 5, 0.1f, 1, true));
				object->runAction(Sequence::create( MoveTo::create(0.5f, Vec2(m_hero->getPosition())), RemoveSelf::create(), nullptr));
				if (pissiblityeng > 0 && pissiblityeng <= 66)
				{
					auto objecteng = Sprite::create();
					this->addChild(objecteng);
					objecteng->setPosition(pMonster->getPosition());
					objecteng->runAction(Myanimation::create("energy", 1, 1, 1.0f, 1, true));
					objecteng->runAction(Sequence::create(MoveTo::create(0.5f, Vec2(m_goldBar->getPosition())), RemoveSelf::create(), nullptr));
				}
				
			}
			m_score += pMonster->getscore();
			m_pf->setString(std::to_string(m_score));//�޸ĵ�ǰ�ķ���
			UserDefault::getInstance()->setIntegerForKey("curscore", m_score);
			// ����������Ч�� ����ϵͳ
			ParticleSystemQuad* enemyDie = ParticleSystemQuad::create("ParticleSystem/enemyDie.plist");
			this->addChild(enemyDie);
			enemyDie->setPosition(pMonster->getPosition());
			pMonster->removeFromParent();
			man->getmonstervector().eraseObject(pMonster);
			m_gold+=1 ;
			m_getgold+=1;
		}
	}
}
//�����ӵ�
void SceneGame::attack(float dt)
{
	if (!istouched)
	{
		m_fbulletattackTimer += dt;
		if (m_fbulletattackTimer >= m_fbulletattackDuration)
		{
			m_fbulletattackTimer = 0;
			Herotype type = (Herotype)(rand() % 4);

			Cbullet* bullet = Bulletfactory::create(type, m_speed * 1000);
			this->addChild(bullet);
			bullet->setRotation(spCannon->getRotation());
			// �ڹܳ��ȣ�б�ߣ�
			float cc = spCannon->getContentSize().width;
			// ��ȡ�ڹܵĽǶ�
			float angle = spCannon->getRotation();
			// �Ƕ�ת����
			angle = angle * 3.1415926f / 180;
			// �Ա�
			float aa = sin(angle) * cc;
			// ���
			float bb = cos(angle) * cc;

			float xx = spCannon->getPositionX() + abs(bb);
			float yy = spCannon->getPositionY() - aa;

			bullet->setPosition(xx, yy);

			man->setBullet(bullet);
		}
		
	}
	else
	{
		return;
	}
	
} 
//�����ӵ�
void SceneGame::updateBullet(float dt)
{
	for (int i = 0; i < man->getbulletvector().size(); i++)
	{
		Cbullet* bullet = man->getbulletvector().at(i);
		bullet->move(dt);
	}
	Vector<Cbullet*>::iterator it_bullet = man->getbulletvector().begin();
	while (it_bullet != man->getbulletvector().end())
	{
		Cbullet* bullet = *it_bullet;
		if (bullet->getPositionX() > visibleSize.width ||
			bullet->getPositionY() > visibleSize.height ||
			bullet->getPositionY() < 0)
		{
			//  �ӵ�����Ļ�Ƴ�
			bullet->removeFromParent();
			//  �ӵ����������Ƴ�
			it_bullet = man->getbulletvector().erase(it_bullet);  // �Ƴ���ǰԪ�أ���������һ��Ԫ�صĵ�����
		}
		else
		{
			it_bullet++;
		}
	}
}
//�ӵ����������ײ���
void SceneGame::HeroBulletCollisionMonster()
{
	// �����ӵ�
	Vector<Cbullet*>::iterator it_bullet = man->getbulletvector().begin();
	while (it_bullet != man->getbulletvector().end())
	{
		// ��ȡ�ӵ�
		Cbullet* bullet = *it_bullet;

		bool isCollision = false;

		//��������
		Vector<Cmonster*>::iterator it_monster = man->getmonstervector().begin();
		while (it_monster != man->getmonstervector().end())
		{
			// ��ȡ����
			Cmonster* monster = *it_monster;
			// �����Χ��
			Rect mBoundingBox = monster->getBoundingBox();
			// �ӵ���Χ��
			Rect bBoundingBox = bullet->getBoundingBox();
			
			// �ж����������Ƿ��ཻ
			//if (mBoundingBox.intersectsRect(bBoundingBox))
			// ���ӵ�����һ���㣬���ΰ�����
			
			if (mBoundingBox.containsPoint(bullet->getPosition()))
			{
				// ���ù����Ѫ��
				monster->setHp(monster->getHp() - bullet->getattack());
				//  �ӵ�����Ļ�Ƴ�
				bullet->removeFromParent();
				////��������֮�������Ʒ
				//produceObject();
				//  �ӵ����������Ƴ�
				it_bullet = man->getbulletvector().erase(it_bullet);  // �Ƴ���ǰԪ�أ���������һ��Ԫ�صĵ�����
				
				isCollision = true;
				break;
			}
			// ������ָ����һ������
			it_monster++;
		}

		if (!isCollision)
		{
			// �ӵ�������ָ����һ���ӵ�
			it_bullet++;
		}
	}

}
void SceneGame::sethpbar()
{
	float percent = (float)m_hero->m_nHp / (float)m_hero->m_nMaxHp*100.0f;
	m_hpBar->setPercent(percent);
}
void SceneGame::setgoldbar()
{
	if (m_gold == m_Maxgold)
	{
		m_gold = 0;
	}
	float percent = (float)m_gold / (float)m_Maxgold*100.0f;
	m_goldBar->setPercent(percent);
}
void SceneGame::HeroCollisionMonster()
{

	Vector<Cmonster*>::iterator it_monster = man->getmonstervector().begin();
	while (it_monster != man->getmonstervector().end())
	{
		// ��ȡ����
		Cmonster* monster = *it_monster;
		//��ͧ��Χ��
		Rect fBoudingbox = spfly->getBoundingBox();
		if (fBoudingbox.containsPoint(monster->getPosition()))
		{
			m_hero->runAction(
				Sequence::create(TintTo::create(0.1f, Color3B(255, 0, 0)), TintTo::create(0.1f, Color3B(255, 255, 255)), nullptr)
				);
			ParticleSystemQuad* enemyDie = ParticleSystemQuad::create("ParticleSystem/enemyDie.plist");
			this->addChild(enemyDie);
			enemyDie->setPosition(monster->getPosition());
			m_hero->setHp(m_hero->m_nHp - monster->getatk());
			m_score += monster->getscore();
			m_pf->setString(std::to_string(m_score));//�޸ĵ�ǰ�ķ���
			UserDefault::getInstance()->setIntegerForKey("curscore", m_score);
			it_monster = man->getmonstervector().erase(it_monster);
			monster->removeFromParent();
			m_gold += 1;
			
			break;
		}
		it_monster++;
	}
}
void SceneGame::setGamestate()
{
	if (m_hero->m_nHp <= 0)
	{	
		man->setisgameover(false);
		int curscore = UserDefault::getInstance()->getIntegerForKey("curscore", 0);
		int Hightestscore = UserDefault::getInstance()->getIntegerForKey("Hightestscore", 0);
		if (curscore  > Hightestscore)
		{
			Hightestscore = curscore;
			UserDefault::getInstance()->setIntegerForKey("Hightestscore", Hightestscore);
		}
		int gold = UserDefault::getInstance()->getIntegerForKey("Gold", 0);
		UserDefault::getInstance()->setIntegerForKey("Gold", gold+m_getgold);
		this->unscheduleUpdate();
		LayerDilot* layer = LayerDilot::create("hd.png", SPRITE_TYPE::FRAME);
		this->addChild(layer, 99);
		auto sppf = Sprite::createWithSpriteFrameName("pft.png");
		layer->getChildByName("sp1")->addChild(sppf);
		sppf->setPosition(visibleSize.width / 2, layer->getChildByName("sp1")->getContentSize().height);
		auto pf = Label::create();
		pf->setSystemFontName("fonts/arial.ttf");
		pf->setSystemFontSize(50);
		sppf->addChild(pf);
		pf->setPosition(sppf->getContentSize().width/2,sppf->getContentSize().height/2);
		pf->setString(std::to_string(curscore));

		auto spzzpf = Sprite::createWithSpriteFrameName("zzpf.png");
		sppf->addChild(spzzpf);
		spzzpf->setPosition(sppf->getContentSize().width/2,
			sppf->getContentSize().height+spzzpf->getContentSize().height/2);


		auto btn = Button::create("zlyc.png");
		layer->addChild(btn);
		btn->setPosition(Vec2(visibleSize.width/2,btn->getContentSize().height/2));
		btn->addClickEventListener([](Ref* ref){
			TransitionFade* fade = TransitionFade::create(0.2f, SceneGameReady::create());
			Director::getInstance()->replaceScene(fade);
		
		});
		//���
		auto spjb = Sprite::create("jbz.png");
		layer->getChildByName("sp1")->addChild(spjb);
		spjb->setPosition(150, layer->getChildByName("sp1")->getContentSize().height/2);
		auto jb = Label::create();
		layer->getChildByName("sp1")->addChild(jb);
		jb->setPosition(spjb->getPositionX(), spjb->getPositionY() - 30);
		jb->setSystemFontName("fonts/arial.ttf");
		jb->setSystemFontSize(30);
		jb->setString(std::to_string(m_getgold));
		//����
		auto spjl = Sprite::create("jlz.png");
		layer->getChildByName("sp1")->addChild(spjl);
		spjl->setPosition(layer->getChildByName("sp1")->getContentSize().width / 2, 
			layer->getChildByName("sp1")->getContentSize().height/2);
		auto jl = Label::create();
		layer->getChildByName("sp1")->addChild(jl);
		jl->setPosition(spjl->getPositionX(), spjl->getPositionY() - 30);
		jl->setSystemFontName("fonts/arial.ttf");
		jl->setSystemFontSize(30);
		jl->setString(std::to_string(m_distence));
		//��ʷ���
		auto splszg = Sprite::create("lszg.png");
		layer->getChildByName("sp1")->addChild(splszg);
		splszg->setPosition(695, layer->getChildByName("sp1")->getContentSize().height/2);
		auto lszg = Label::create();
		layer->getChildByName("sp1")->addChild(lszg);
		lszg->setPosition(splszg->getPositionX(), splszg->getPositionY() - 30);
		lszg->setSystemFontName("fonts/arial.ttf");
		lszg->setSystemFontSize(30);
		lszg->setString(std::to_string(Hightestscore));
	}
}
void SceneGame::HeroMonsterbulletCollision()
{
	Vector<Sprite*>::iterator it_monbullet = man->getmonbulletvector().begin();
	while (it_monbullet != man->getmonbulletvector().end())
	{
		Sprite* spmonsterbullet = *it_monbullet;
		Rect fBoudingbox = spfly->getBoundingBox();
		if (fBoudingbox.containsPoint(spmonsterbullet->getPosition()))
		{
			m_hero->runAction(
				Sequence::create(TintTo::create(0.1f, Color3B(255, 0, 0)), TintTo::create(0.1f, Color3B(255, 255, 255)), nullptr)
				);
			m_hero->setHp(m_hero->getHp()-10);
			spmonsterbullet->removeFromParent();
			it_monbullet = man->getmonbulletvector().erase(it_monbullet);
			break;
		}
		it_monbullet++;
	}
}
void SceneGame::produceBoss()
{
	BOSSTYPE type = (BOSSTYPE)(rand() % 2);
	m_boss = BossFactory::create(type);
	log("%d", m_boss->gethp());
	this->addChild(m_boss);
	m_boss->setPosition(visibleSize.width + m_boss->getContentSize().width / 2,
			visibleSize.height / 2);
}
void SceneGame::updateBoss(float dt)
{
		if (nullptr == m_boss)
		{
		return;
		}
		else
		{
 			m_boss->move(dt);
			if (m_boss->gethp() <= 0)
			{
				// ����������Ч�� ����ϵͳ
				ParticleSystemQuad* enemyDie = ParticleSystemQuad::create("ParticleSystem/enemyDie.plist");
				this->addChild(enemyDie);
				enemyDie->setPosition(m_boss->getPosition());
				m_boss->removeFromParent();
				m_gold += 100;
				m_getgold += 100;
				m_boss = nullptr;
			}
		} 		
}
void SceneGame::HeroBulletCollisionBoss()
{
	if (nullptr == m_boss)
	{
		return;
	}
	else
	{
		//�Զ���İ�Χ��
		Rect bossboudingbox = Rect(m_boss->getPositionX() - m_boss->getContentSize().width / 2 + 50,
			m_boss->getPositionY() - m_boss->getContentSize().height / 2,
			m_boss->getContentSize().width - 100, m_boss->getContentSize().height);

		Vector<Cbullet*>::iterator it_bullet = man->getbulletvector().begin();
		while (it_bullet != man->getbulletvector().end())
		{
			Cbullet* bullet = *it_bullet;
			if (bossboudingbox.containsPoint(bullet->getPosition()))
			{
				log("%d", m_boss->gethp());
				m_boss->runAction(
					Sequence::create(TintTo::create(0.1f, Color3B(255, 0, 0)), TintTo::create(0.1f, Color3B(255, 255, 255)), nullptr)
					);
				m_boss->sethp(m_boss->gethp() - bullet->getattack());
				bullet->removeFromParent();
				it_bullet = man->getbulletvector().erase(it_bullet);
				break;
			}
			else
				it_bullet++;
		}
	}
	
}
void SceneGame::HeroCollisionBossBullet()
{
	Rect mHeroBoudingbox = spfly->getBoundingBox();
	if (mHeroBoudingbox.containsPoint(m_boss->getbullet()->getPosition()))
	{
		m_hero->runAction(
			Sequence::create(TintTo::create(0.1f, Color3B(255, 0, 0)), TintTo::create(0.1f, Color3B(255, 255, 255)), nullptr)
			);
		m_boss->getbullet()->runAction(RemoveSelf::create());
		m_hero->setHp(m_hero->getHp() - 10);
	}
}
