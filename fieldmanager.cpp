#include "fieldmanager.h"

FieldManager::FieldManager(std::vector<int> *myBase, std::vector<int> *opBase, QObject *parent) : QObject(parent)
{
	myField=new GameField();

	myField->setMyBase(myBase);
	myField->setOpBase(opBase);

	srand((unsigned)time(NULL));
	turn=(rand()%2==0) ? false:true;

	myPass=false;
	opPass=false;
	myScore=0;
	opScore=0;
	round=1;
}

void FieldManager::implementInstant()
{
	for(auto it=instantEffects.begin();it!=instantEffects.end();++it)
	{
		(*it)->implementEffect(turn);
	}
	for(auto it=instantEffects.begin();it!=instantEffects.end();++it)
	{
		delete((*it));
	}
	instantEffects.clear();
}

void FieldManager::implementRoutine()
{
	for(auto it=routineEffects.begin();it!=routineEffects.end();++it)
	{
		(*it)->implementEffect(turn);
	}
}

void FieldManager::implementDeadWish()
{
	for(auto it=deadWish.begin();it!=deadWish.end();++it)
	{
		(*it)->implementEffect(turn);
	}
	for(auto it=deadWish.begin();it!=deadWish.end();++it)
	{
		delete((*it));
	}
	deadWish.clear();
}

void FieldManager::implementUnitDeadWish(GameUnit *unit)
{
	for(auto it=deadWish.begin();it!=deadWish.end();++it)
	{
		if((*it)->getSelf()==unit)
		{
			(*it)->implementEffect(turn);
			delete(*it);
			deadWish.erase(it);
			break;
		}
	}
}

void FieldManager::implementDeployPassive()
{
	for(auto it=deployPassiveEffects.begin();it!=deployPassiveEffects.end();++it)
	{
		(*it)->implementEffect(turn);
	}
}

void FieldManager::implementBasePassive()
{
	for(auto it=basePassiveEffects.begin();it!=basePassiveEffects.end();++it)
	{
		(*it)->implementEffect(turn);
	}
}

void FieldManager::implementCemeteryPassive()
{
	for(auto it=basePassiveEffects.begin();it!=basePassiveEffects.end();++it)
	{
		(*it)->implementEffect(turn);
	}
}

void FieldManager::shuffle()
{
	myField->shuffle();
}

void FieldManager::firstDraw()
{
	myField->peekCards(CONSTANT::firstDrawNum);
	QJsonObject myInfo,opInfo;
	myInfo.insert("type","firstDraw");
	opInfo.insert("type","firstDraw");
	myThread->sendQJsonObject(myInfo);
	opThread->sendQJsonObject(opInfo);
	myThread->waitForDrawCard(&myInfo);
	opThread->waitForDrawCard(&opInfo);
	if(myInfo.find("error")!=myInfo.end())
	{
		//TODO
		//deal with connect broke
	}
	else if(opInfo.find("error")!=opInfo.end())
	{
		//TODO
	}
	else
	{
		myField->updateHandCard(true,&myInfo);//TODO
		myField->updateHandCard(false,&opInfo);//TODO
		myField->updateBase(true,&myInfo);
		myField->updateBase(false,&opInfo);
	}
}

void FieldManager::secondDraw()
{
	myField->peekCards(CONSTANT::secondDrawNum);
	QJsonObject myInfo,opInfo;
	myInfo.insert("type","secondDraw");
	opInfo.insert("type","secondDraw");
	myThread->sendQJsonObject(myInfo);
	opThread->sendQJsonObject(opInfo);
	myThread->waitForDrawCard(&myInfo);
	opThread->waitForDrawCard(&opInfo);
	if(myInfo.find("error")!=myInfo.end())
	{
		//TODO
		//deal with connect broke
	}
	else if(opInfo.find("error")!=opInfo.end())
	{
		//TODO
	}
	else
	{
		myField->updateHandCard(true,&myInfo);
		myField->updateHandCard(false,&opInfo);
		myField->updateBase(true,&myInfo);
		myField->updateBase(false,&opInfo);
	}
}

void FieldManager::thirdDraw()
{
	myField->peekCards(CONSTANT::thirdDrawNum);
	QJsonObject myInfo,opInfo;
	myInfo.insert("type","thirdDraw");
	opInfo.insert("type","thirdDraw");
	myThread->sendQJsonObject(myInfo);
	opThread->sendQJsonObject(opInfo);
	myThread->waitForDrawCard(&myInfo);
	opThread->waitForDrawCard(&opInfo);
	if(myInfo.find("error")!=myInfo.end())
	{
		//TODO
		//deal with connect broke
	}
	else if(opInfo.find("error")!=opInfo.end())
	{
		//TODO
	}
	else
	{
		myField->updateHandCard(true,&myInfo);
		myField->updateHandCard(false,&opInfo);
		myField->updateBase(true,&myInfo);
		myField->updateBase(false,&opInfo);
	}
}

void FieldManager::newRound()
{
	//implementDeadWish();
	myPass=false;
	opPass=false;
}

int FieldManager::settlement()
{
	//TODO
	//return 1 if my win
	//return 2 if op win
	//return 3 if draw
	/* decide who wins
	 * update myScore and opScore and round
	 * destroy all units who are not locked
	 * add all dead wishes of destroyed units to deadWish vector waiting for void newRound() to implement
	 * send message to client telling them all units remaining on the field
	 * send message to tell clients the current score
	 */
}

void FieldManager::gameOver()
{
//TODO
}

void FieldManager::addEffect(int _id,GameUnit *target,int type=0)
{
	CardManager cm(_id);
	EffectManager *em=nullptr;
	if(target!=nullptr)
	{
		if(cm.haveDeployEffect())
		{
			em=new EffectManager(_id,turn,target,0);
			instantEffects.push_back(em);
		}
		if(cm.haveRoutineEffect())
		{
			em=new EffectManager(_id,turn,target,1);
			routineEffects.push_back(em);
		}
		if(cm.haveDeadWishEffect())
		{
			em=new EffectManager(_id,turn,target,2);
			deadWish.push_back(em);
		}
		if(cm.haveDeployPassiveEffect())
		{
			em=new EffectManager(_id,turn,target,3);
			deployPassiveEffects.push_back(em);
		}
	}
	else
	{
		if(type==1 && cm.haveBasePassiveEffect())
		{
			em=new EffectManager(_id,turn,nullptr,4);
			basePassiveEffects.push_back(em);
		}
		if(type==2 && cm.haveCemeteryPassiveEffect())
		{
			em=new EffectManager(_id,turn,nullptr,5);
			cemeteryPassiveEffects.push_back(em);
		}
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

	connect(em,SIGNAL(resurrectCardToHand(int,bool,bool,int)),myField,SLOT(resurrectCardToHand(int,bool,bool,int)));

	connect(em,SIGNAL(resurrectCardToRow(int,bool,int,int,int)),myField,SLOT(resurrectCardToRow(int,bool,int,int,int)));

	connect(em,SIGNAL(generateNCard(int,int,GameUnit*,int)),myField,SLOT(generateNCard(int,int,GameUnit*,int)));

	connect(em,SIGNAL(getRow(std::vector<GameUnit*>*,int)),myField,SLOT(getRow(std::vector<GameUnit*>*,int)));

	connect(em,SIGNAL(deployCardsFromBase(int,int,int,bool,int)),myField,SLOT(deployCardsFromBase(int,int,int,bool,int)));

	connect(em,SIGNAL(EffectChooseRow(QJsonObject*)),this,SLOT(receiveEffectChooseRow(QJsonObject*)));

	connect(em,SIGNAL(EffectChooseTarget(QJsonObject*)),this,SLOT(receiveEffectChooseTarget(QJsonObject*)));

}

void FieldManager::initBaseEffect(int _id, bool side)
{
	CardManager cm(_id);
	EffectManager *em=nullptr;
	if(cm.haveBasePassiveEffect())
	{
		em=new EffectManager(_id,side,nullptr,4);
		basePassiveEffects.push_back(em);
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

	connect(em,SIGNAL(resurrectCardToHand(int,bool,bool,int)),myField,SLOT(resurrectCardToHand(int,bool,bool,int)));

	connect(em,SIGNAL(resurrectCardToRow(int,bool,int,int,int)),myField,SLOT(resurrectCardToRow(int,bool,int,int,int)));

	connect(em,SIGNAL(generateNCard(int,int,GameUnit*,int)),myField,SLOT(generateNCard(int,int,GameUnit*,int)));

	connect(em,SIGNAL(getRow(std::vector<GameUnit*>*,int)),myField,SLOT(getRow(std::vector<GameUnit*>*,int)));

	connect(em,SIGNAL(deployCardsFromBase(int,int,int,bool,int)),myField,SLOT(deployCardsFromBase(int,int,int,bool,int)));

	connect(em,SIGNAL(EffectChooseRow(QJsonObject*)),this,SLOT(receiveEffectChooseRow(QJsonObject*)));

	connect(em,SIGNAL(EffectChooseTarget(QJsonObject*)),this,SLOT(receiveEffectChooseTarget(QJsonObject*)));
}

void FieldManager::deleteEffect(int effectType,int id,GameUnit* unit=nullptr)
{
	std::vector<EffectManager*> *targetVec=nullptr;
	switch (effectType)
	{
	case 0:
		targetVec=&instantEffects;
		break;
	case 1:
		targetVec=&routineEffects;
		break;
	case 2:
		targetVec=&deadWish;
		break;
	case 3:
		targetVec=&deployPassiveEffects;
		break;
	case 4:
		targetVec=&basePassiveEffects;
		break;
	case 5:
		targetVec=&cemeteryPassiveEffects;
		break;
	}
	if(unit==nullptr)
	{
		for(auto it=targetVec->begin();it!=targetVec->end();++it)
		{
			if((*it)->getUnitId()==id)
			{
				delete((*it));
				it=targetVec->erase(it);
			}
		}
	}
	else
	{
		for(auto it=targetVec->begin();it!=targetVec->end();++it)
		{
			if((*it)->getSelf()==unit)
			{
				delete(*it);
				targetVec->erase(it);
				break;
			}
		}
	}
}

int FieldManager::getFightFromVec(const std::vector<GameUnit *> *vec)
{
	int count=0;
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		count+=(*it)->getFight();
	}
	return count;
}

bool FieldManager::commonChooseCardAndDeploy(bool side)
{

}

void FieldManager::setPass(bool side)
{
	if(side)
		myPass=true;
	else
		opPass=true;
}

void FieldManager::drawCards()
{
	switch (getRound()) {
	case 1:
		firstDraw();
		break;
	case 2:
		secondDraw();
		break;
	case 3:
		thirdDraw();
		break;
	default:
		break;
	}
}

void FieldManager::receiveEffectChooseRow(QJsonObject *info)
{
	if(turn)
		emit effectChooseRowMyThread(info);
	else
		emit effectChooseRowOpThread(info);
}

void FieldManager::receiveEffectChooseTarget(QJsonObject *info)
{
	if(turn)
		emit effectChooseTargetMyThread(info);
	else
		emit effectChooseTargetOpThread(info);
}

void FieldManager::newCardDeployed(GameUnit *unit)
{
	addEffect(unit->getCardId(),unit,0);

	//TODO
	//IMPLEMENT INSTANT EFFECT ??
}

void FieldManager::cardDestroyed(GameUnit *unit)
{
	implementUnitDeadWish(unit);
	deleteEffect(1,unit->getCardId(),unit);
	addEffect(unit->getCardId(),nullptr,2);
}

int FieldManager::getMyPoint()
{
	int count=0;
	count+=getMyBackPoint();
	count+=getMyFrontPoint();
	count+=getMyMiddlePoint();
	return count;
}

int FieldManager::getOpPoint()
{
	int count=0;
	count+=getOpBackPoint();
	count+=getOpFrontPoint();
	count+=getOpMiddlePoint();
	return count;
}

int FieldManager::getMyFrontPoint()
{
	return getFightFromVec(myField->getMyFront());
}

int FieldManager::getOpFrontPoint()
{
	return getFightFromVec(myField->getOpFront());
}

int FieldManager::getMyMiddlePoint()
{
	return getFightFromVec(myField->getMyMiddle());
}

int FieldManager::getOpMiddlePoint()
{
	return getFightFromVec(myField->getOpMiddle());
}

int FieldManager::getMyBackPoint()
{
	return getFightFromVec(myField->getMyBack());
}

int FieldManager::getOpBackPoint()
{
	return getFightFromVec(myField->getOpBack());
}

void FieldManager::setMyThread(MyThread *th)
{
	myThread=th;
	connect(myField,SIGNAL(baseChangedToClient(QJsonObject)),myThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(gameUnitChangedToClient(QJsonObject)),myThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(rowChangedToClient(QJsonObject)),myThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(cemeteryChangedToClient(QJsonObject)),myThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(handCardChangedToClient(QJsonObject)),myThread,SLOT(sendQJsonObject(QJsonObject)));

	connect(this,SIGNAL(effectChooseRowMyThread(QJsonObject*)),myThread,SLOT(sendQJsonObjectAndWaitForRespode(QJsonObject*)));
	connect(this,SIGNAL(effectChooseTargetMyThread(QJsonObject*)),myThread,SLOT(sendQJsonObjectAndWaitForRespode(QJsonObject*)));
}

void FieldManager::setOpThread(MyThread *th)
{
	opThread=th;
	connect(myField,SIGNAL(baseChangedToClient(QJsonObject)),opThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(gameUnitChangedToClient(QJsonObject)),opThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(rowChangedToClient(QJsonObject)),opThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(cemeteryChangedToClient(QJsonObject)),opThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(handCardChangedToClient(QJsonObject)),opThread,SLOT(sendQJsonObject(QJsonObject)));

	connect(this,SIGNAL(effectChooseRowOpThread(QJsonObject*)),opThread,SLOT(sendQJsonObjectAndWaitForRespode(QJsonObject*)));
	connect(this,SIGNAL(effectChooseTargetOpThread(QJsonObject*)),opThread,SLOT(sendQJsonObjectAndWaitForRespode(QJsonObject*)));
}

bool FieldManager::isOtherPassed()
{
	if(turn)
	{
		if(opPass==false)
			return false;
		else
			return true;
	}
	else
	{
		if(myPass==false)
			return false;
		else
			return true;
	}
}
