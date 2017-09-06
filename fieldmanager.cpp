#include "fieldmanager.h"

FieldManager::FieldManager(QObject *parent) : QObject(parent)
{
	myField=new GameField();
	srand((unsigned)time(NULL));
	side=(rand()%2==0) ? false:true;
}

void FieldManager::implementInstant()
{
	for(auto it=instantEffects.begin();it!=instantEffects.end();++it)
	{
		(*it)->implementEffect();
	}
}

void FieldManager::implementRoutine()
{
	for(auto it=routineEffects.begin();it!=routineEffects.end();++it)
	{
		(*it)->implementEffect();
	}
}

void FieldManager::implementDeadWish()
{
	for(auto it=deadWish.begin();it!=deadWish.end();++it)
	{
		(*it)->implementEffect();
	}
}

void FieldManager::implementPassive()
{
	for(auto it=passiveEffects.begin();it!=passiveEffects.end();++it)
	{
		(*it)->implementEffect();
	}
}

void FieldManager::addEffect(int _id,GameUnit *target)
{
	CardManager cm(_id);
	EffectManager *em=nullptr;
	if(cm.haveDeployEffect())
	{
		em=new EffectManager(side,target,0);
		instantEffects.push_back(em);
	}
	if(cm.haveRoutineEffect())
	{
		em=new EffectManager(side,target,1);
		routineEffects.push_back(em);
	}
	if(cm.haveDeadWishEffect())
	{
		em=new EffectManager(side,target,2);
		deadWish.push_back(em);
	}
	if(cm.havePassiveEffect())
	{
		em=new EffectManager(side,target,3);
		passiveEffects.push_back(em);
	}
	connect(em,SIGNAL(findWeakestInRow(std::vector<GameUnit*>*,int)),myField,SLOT(findWeakestInRow(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(findWeakestInRow(std::vector<GameUnit*>*,int,int)),myField,SLOT(findWeakestInRow(std::vector<GameUnit*>*,int,int)));
	connect(em,SIGNAL(findStrongestInRow(std::vector<GameUnit*>*,int)),myField,SLOT(findStrongestInRow(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(findStrongestInRow(std::vector<GameUnit*>*,int,int)),myField,SLOT(findStrongestInRow(std::vector<GameUnit*>*,int,int)));
	connect(em,SIGNAL(findNear(std::vector<GameUnit*>*,int,int,GameUnit*,int,int)),myField,SLOT(findNear(std::vector<GameUnit*>*,int,int,GameUnit*,int,int)));
	connect(em,SIGNAL(findWeakestInAll(std::vector<GameUnit*>*)),myField,SLOT(findWeakestInAll(std::vector<GameUnit*>*)));
	connect(em,SIGNAL(findWeakestInAll(std::vector<GameUnit*>*,int)),myField,SLOT(findWeakestInAll(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(findStrongestInAll(std::vector<GameUnit*>*)),myField,SLOT(findStrongestInAll(std::vector<GameUnit*>*)));
	connect(em,SIGNAL(findStrongestInAll(std::vector<GameUnit*>*,int)),myField,SLOT(findStrongestInAll(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(damageByN(std::vector<GameUnit*>*,int)),myField,SLOT(damageByN(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(damageByNUnseenProtection(std::vector<GameUnit*>*,int)),myField,SLOT(damageByNUnseenProtection(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(boostByN(std::vector<GameUnit*>*,int)),myField,SLOT(boostByN(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(addProtectionByN(std::vector<GameUnit*>*,int)),myField,SLOT(addProtectionByN(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(lockTarget(std::vector<GameUnit*>*)),myField,SLOT(lockTarget(std::vector<GameUnit*>*)));
	connect(em,SIGNAL(makePowerToN(std::vector<GameUnit*>*,int)),myField,SLOT(makePowerToN(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(destroyTarget(std::vector<GameUnit*>*)),myField,SLOT(destroyTarget(std::vector<GameUnit*>*)));
	connect(em,SIGNAL(eatTarget(std::vector<GameUnit*>*,GameUnit*)),myField,SLOT(eatTarget(std::vector<GameUnit*>*,GameUnit*)));
	connect(em,SIGNAL(moveTarget(std::vector<GameUnit*>*,int)),myField,SLOT(moveTarget(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(peekNCardsFromBase(int,bool)),myField,SLOT(peekNCardsFromBase(int,bool)));
	connect(em,SIGNAL(peekSpecificCardFromBase(int,bool)),myField,SLOT(peekSpecificCardFromBase(int,bool)));
	connect(em,SIGNAL(putCardBackToBase(GameUnit*,int,bool)),myField,SLOT(putCardBackToBase(GameUnit*,int,bool)));
	connect(em,SIGNAL(resurrectCard(int,bool,bool)),myField,SLOT(resurrectCard(int,bool,bool)));
	connect(em,SIGNAL(generateNCard(int,int,GameUnit*,int)),myField,SLOT(generateNCard(int,int,GameUnit*,int)));
	connect(em,SIGNAL(getRow(std::vector<GameUnit*>*,int)),myField,SLOT(getRow(std::vector<GameUnit*>*,int)));
	connect(em,SIGNAL(deployCards(int,int,std::vector<GameUnit*>*)),myField,SLOT(deployCards(int,int,std::vector<GameUnit*>*)));

//TODO
}
