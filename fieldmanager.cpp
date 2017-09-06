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
	if(cm.haveDeployEffect())
	{
		EffectManager *em=new EffectManager(side,target,0);
		instantEffects.push_back(em);
	}
	if(cm.haveRoutineEffect())
	{
		EffectManager *em=new EffectManager(side,target,1);
		routineEffects.push_back(em);
	}
	if(cm.haveDeadWishEffect())
	{
		EffectManager *em=new EffectManager(side,target,2);
		deadWish.push_back(em);
	}
	if(cm.havePassiveEffect())
	{
		EffectManager *em=new EffectManager(side,target,3);
		passiveEffects.push_back(em);
	}
	connect(em,SIGNAL(findWeakestInRow(std::vector<GameUnit*>*,int)),myField,SLOT(findWeakestInRow(std::vector<GameUnit*>*,int)));
//TODO
}
