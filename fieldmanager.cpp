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

void FieldManager::shuffle()
{
	myField->shuffle();
}

void FieldManager::firstDraw()
{
	myField->peekCards(CONSTANT::firstDrawNum);
	for(int i=0;i<CONSTANT::firstExchangeNum;++i)
	{

	}
}

void FieldManager::secondDraw()
{

}

void FieldManager::thirdDraw()
{

}

void FieldManager::newRound()
{
	implementDeadWish();
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
	 * destroy all units who is not locked
	 * add all dead wishes of destroyed units to deadWish vector waiting for void newRound() to implement
	 * send message to client telling them all units remaining on the field
	 * send message to tell clients the current score
	 */
}

void FieldManager::gameOver()
{
//TODO
}

void FieldManager::addEffect(int _id,GameUnit *target)
{
	CardManager cm(_id);
	EffectManager *em=nullptr;
	if(cm.haveDeployEffect())
	{
		em=new EffectManager(turn,target,0);
		instantEffects.push_back(em);
	}
	if(cm.haveRoutineEffect())
	{
		em=new EffectManager(turn,target,1);
		routineEffects.push_back(em);
	}
	if(cm.haveDeadWishEffect())
	{
		em=new EffectManager(turn,target,2);
		deadWish.push_back(em);
	}
	if(cm.havePassiveEffect())
	{
		em=new EffectManager(turn,target,3);
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

	connect(em,SIGNAL(resurrectCardToHand(int,bool,bool,int)),myField,SLOT(resurrectCardToHand(int,bool,bool,int)));

	connect(em,SIGNAL(resurrectCardToRow(int,bool,int,int,int)),myField,SLOT(resurrectCardToRow(int,bool,int,int,int)));

	connect(em,SIGNAL(generateNCard(int,int,GameUnit*,int)),myField,SLOT(generateNCard(int,int,GameUnit*,int)));

	connect(em,SIGNAL(getRow(std::vector<GameUnit*>*,int)),myField,SLOT(getRow(std::vector<GameUnit*>*,int)));

	connect(em,SIGNAL(deployCardsFromBase(int,int,int,bool,int)),myField,SLOT(deployCardsFromBase(int,int,int,bool,int)));

	connect(em,SIGNAL(EffectChooseRow(QJsonObject*)),this,SLOT(receiveEffectChooseRow(QJsonObject*)));

	connect(em,SIGNAL(EffectChooseTarget(QJsonObject*)),this,SLOT(receiveEffectChooseTarget(QJsonObject*)));

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
