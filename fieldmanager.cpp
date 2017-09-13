#include "fieldmanager.h"

FieldManager::FieldManager(std::vector<int> *myBase, std::vector<int> *opBase, QObject *parent) : QObject(parent)
{
	myField=new GameField();
	myField->setMyBase(*myBase);
	myField->setOpBase(*opBase);
	srand((unsigned)time(NULL));
	turn=(rand()%2==0) ? false:true;

	myPass=false;
	opPass=false;
	myScore=0;
	opScore=0;
	round=1;

	connect(myField,SIGNAL(newCardDeployed(GameUnit*)),this,SLOT(newCardDeployed(GameUnit*)));
	connect(myField,SIGNAL(cardDestroyed(GameUnit*)),this,SLOT(cardDestroyed(GameUnit*)));
	connect(myField,SIGNAL(targetEaten(bool)),this,SLOT(targetEaten(bool)));
	connect(myField,SIGNAL(rowChangedCheckPassive()),this,SLOT(checkAllPassive()));

	qDebug()<<"before init";
	for(auto it=myBase->begin();it!=myBase->end();++it)
	{
		initBaseEffect((*it),true);
	}
	for(auto it=opBase->begin();it!=opBase->end();++it)
	{
		initBaseEffect((*it),false);
	}

	qDebug()<<"after init";
}
/*
void FieldManager::eraseDuplication(std::vector<EffectManager *> *vec)
{
	std::vector<EffectManager*> *revec=new std::vector<EffectManager*>();
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		for(auto it=vec)
	}
}
*/
void FieldManager::implementInstant()
{
	if(instantEffects.empty())
	{
		qDebug()<<"instant effect empty!";
		return;
	}
	for(auto it=instantEffects.begin();it!=instantEffects.end();++it)
	{
		(*it)->implementEffect(turn);
	}
	instantEffects.clear();
	qDebug()<<"implement instant effect";
}

void FieldManager::implementRoutine()
{
	if(routineEffects.empty())
	{
		qDebug()<<"routine effects empty!";
		return;
	}
	for(auto it=routineEffects.begin();it!=routineEffects.end();)
	{
		(*it)->implementEffect(turn);
		if((*it)->getNeedToBeDeleted())
		{
			delete(*it);
			it=routineEffects.erase(it);
		}
		else
			++it;
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
	qDebug()<<"implement deadwish";
}

void FieldManager::implementUnitDeadWish(GameUnit *unit)
{
	for(auto it=deadWish.begin();it!=deadWish.end();++it)
	{
		if((*it)->getSelf()==unit)
		{
			(*it)->implementEffect(turn);
			qDebug()<<"implement single deadwish";
			delete(*it);
			deadWish.erase(it);
			break;
		}
	}
}

void FieldManager::implementDeployPassive()
{
	for(auto it=deployPassiveEffects.begin();it!=deployPassiveEffects.end();)
	{
		if((*it)->implementEffect(turn))
		{
			delete(*it);
			it=deployPassiveEffects.erase(it);
			qDebug()<<"implement deploy passive";
		}
		else
		{
			++it;
		}
	}
}

void FieldManager::implementBasePassive()
{
	qDebug()<<">>>check for basepassive";
	for(auto it=basePassiveEffects.begin();it!=basePassiveEffects.end();)
	{
		
		EffectManager *temp=(*it);
		it=basePassiveEffects.erase(it);
		if(!temp->implementEffect(turn))
		{
			it=basePassiveEffects.insert(it, temp);
			++it;
		}
		/*
		if((*it)->implementEffect(turn))
		{
			delete(*it);
			it=basePassiveEffects.erase(it);
			qDebug()<<"implement base passive";
		}
		 
		else
		{
			++it;
			qDebug()<<"do not satisfy the condition";
		}
		 */
	}
	qDebug()<<">>>end check for basepassive";
	if(basePassiveEffects.empty())
		qDebug()<<"empty basepassiveeffects";
}

void FieldManager::implementCemeteryPassive()
{
	for(auto it=cemeteryPassiveEffects.begin();it!=cemeteryPassiveEffects.end();)
	{
		if((*it)->implementEffect(turn))
		{
			delete(*it);
			it=cemeteryPassiveEffects.erase(it);
			qDebug()<<"implement cemetery passive";
		}
		else
		{
			++it;
		}
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
	myThread->waitForDrawCard(&myInfo);
	opThread->sendQJsonObject(opInfo);
	opThread->waitForDrawCard(&opInfo);
	if(myInfo.find("error")!=myInfo.end())
	{
		QJsonObject err;
		err.insert("type","error");
		opThread->sendQJsonObject(err);
	}
	else if(opInfo.find("error")!=opInfo.end())
	{
		QJsonObject err;
		err.insert("type","error");
		myThread->sendQJsonObject(err);
	}
#ifdef DEBUG
	else if(myInfo.find("cancel")!=myInfo.end() &&opInfo.find("cancel")!=opInfo.end())
	{
		return;
		qDebug()<<"here";
	}
#endif
//#ifndef DEBUG
	else
	{
		myField->updateHandCard(true,myInfo);
		myField->updateHandCard(false,opInfo);
		myField->updateBase(true,myInfo);
		myField->updateBase(false,opInfo);
	}
//#endif
}

void FieldManager::secondDraw()
{
	qDebug()<<"secondDrawCard";
	myField->peekCards(CONSTANT::secondDrawNum);
	QJsonObject myInfo,opInfo;
	myInfo.insert("type","secondDraw");
	opInfo.insert("type","secondDraw");
	myThread->sendQJsonObject(myInfo);
	myThread->waitForDrawCard(&myInfo);
	opThread->sendQJsonObject(opInfo);
	opThread->waitForDrawCard(&opInfo);
	qDebug()<<"qjsonobject return";
	if(myInfo.find("error")!=myInfo.end())
	{
		QJsonObject err;
		err.insert("type","error");
		opThread->sendQJsonObject(err);
	}
	else if(opInfo.find("error")!=opInfo.end())
	{
		QJsonObject err;
		err.insert("type","error");
		myThread->sendQJsonObject(err);
	}
#ifdef DEBUG
	else if(myInfo.find("cancel")!=myInfo.end() &&opInfo.find("cancel")!=opInfo.end())
	{
		return;
	}
#endif
//#ifndef DEBUG
	else
	{
		myField->updateHandCard(true,myInfo);
		myField->updateHandCard(false,opInfo);
		myField->updateBase(true,myInfo);
		myField->updateBase(false,opInfo);
	}
//#endif
}

void FieldManager::thirdDraw()
{
	myField->peekCards(CONSTANT::thirdDrawNum);
	QJsonObject myInfo,opInfo;
	myInfo.insert("type","thirdDraw");
	opInfo.insert("type","thirdDraw");
	myThread->sendQJsonObject(myInfo);
	myThread->waitForDrawCard(&myInfo);
	opThread->sendQJsonObject(opInfo);
	opThread->waitForDrawCard(&opInfo);
	if(myInfo.find("error")!=myInfo.end())
	{
		QJsonObject err;
		err.insert("type","error");
		opThread->sendQJsonObject(err);
	}
	else if(opInfo.find("error")!=opInfo.end())
	{
		QJsonObject err;
		err.insert("type","error");
		myThread->sendQJsonObject(err);
	}
#ifdef DEBUG
	else if(myInfo.find("cancel")!=myInfo.end() &&opInfo.find("cancel")!=opInfo.end())
	{
		return;
	}
#endif
//#ifndef DEBUG
	else
	{
		myField->updateHandCard(true,myInfo);
		myField->updateHandCard(false,opInfo);
		myField->updateBase(true,myInfo);
		myField->updateBase(false,opInfo);
	}
//#endif
}

void FieldManager::newRound()
{
	//implementDeadWish();
	myPass=false;
	opPass=false;
}

int FieldManager::settlement(QJsonObject *re,int count)
{
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
	int myRoundPoint=getMyPoint();
	int opRoundPoint=getOpPoint();
	re->insert(QString::number(count)+"My",myRoundPoint);
	re->insert(QString::number(count)+"Op",opRoundPoint);
	int returnValue=0;
	if(myRoundPoint > opRoundPoint)
	{
		++myScore;
		returnValue=1;
		turn=true;
	}
	else if(myRoundPoint < opRoundPoint)
	{
		++opScore;
		returnValue=2;
		turn=true;
	}
	else
	{
		++myScore;
		++opScore;
		returnValue=3;
	}
	disconnect(myField,SIGNAL(rowChangedCheckPassive()),this,SLOT(checkAllPassive()));
	myField->roundClear();
	//routineEffects.clear();
	connect(myField,SIGNAL(rowChangedCheckPassive()),this,SLOT(checkAllPassive()));
	QJsonObject settle;
	settle["type"]="settle";
	settle["myScore"]=myScore;
	settle["opScore"]=opScore;
	myThread->sendQJsonObject(settle);
	opThread->sendQJsonObject(settle);
	round++;
	return returnValue;
}

void FieldManager::gameOver(QJsonObject re)
{
	re.insert("type","gameover");
	myThread->sendQJsonObject(re);
	opThread->sendQJsonObject(re);
	exit(0);
}

void FieldManager::addEffect(int _id,GameUnit *target,int type=0)
{
	CardManager cm(_id);
	EffectManager *em=nullptr;
	EffectManager *temp=nullptr;
	if(target!=nullptr)
	{
		if(cm.haveDeployEffect())
		{
			em=new EffectManager(_id,turn,target,0);
			temp=em;
			//instantEffects.push_back(em);
		}
		if(cm.haveRoutineEffect())
		{
			em=new EffectManager(_id,turn,target,1);
			//qDebug()<<"have routine effect";
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
	if(em!=nullptr)
	{
	connect(em,SIGNAL(findWeakestInRow(std::vector<GameUnit*>*,int)),myField,SLOT(findWeakestInRow(std::vector<GameUnit*>*,int)));

	connect(em,SIGNAL(findWeakestInRow(std::vector<GameUnit*>*,int,int)),myField,SLOT(findWeakestInRow(std::vector<GameUnit*>*,int,int)));

	connect(em,SIGNAL(findStrongestInRow(std::vector<GameUnit*>*,int)),myField,SLOT(findStrongestInRow(std::vector<GameUnit*>*,int)));

	connect(em,SIGNAL(findStrongestInRow(std::vector<GameUnit*>*,int,int)),myField,SLOT(findStrongestInRow(std::vector<GameUnit*>*,int,int)));

	connect(em,SIGNAL(findNear(std::vector<GameUnit*>*,int,GameUnit*,int,int)),myField,SLOT(findNear(std::vector<GameUnit*>*,int,GameUnit*,int,int)));

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

	connect(em,SIGNAL(generateNCard(int,int,std::vector<GameUnit*>*,int,bool)),myField,SLOT(generateNCard(int,int,std::vector<GameUnit*>*,int,bool)));

	connect(em,SIGNAL(getRow(std::vector<GameUnit*>*,int)),myField,SLOT(getRow(std::vector<GameUnit*>*,int)));

	connect(em,SIGNAL(deployCardsFromBase(int,int,int,bool,int)),myField,SLOT(deployCardsFromBase(int,int,int,bool,int)));

	connect(em,SIGNAL(EffectChooseRow(QJsonObject*)),this,SLOT(receiveEffectChooseRow(QJsonObject*)));

	connect(em,SIGNAL(EffectChooseTarget(QJsonObject*)),this,SLOT(receiveEffectChooseTarget(QJsonObject*)));

	connect(em,SIGNAL(EffectChooseCard(QJsonObject*)),this,SLOT(receiveEffectChooseCard(QJsonObject*)));

	connect(em,SIGNAL(generateNCardWithOutChooseTarget(int,int,int,bool)),myField,SLOT(generateNCardWithOutChooseTarget(int,int,int,bool)));

	connect(em,SIGNAL(exist(int,bool*,int)),myField,SLOT(exist(int,bool*,int)));

	connect(em,SIGNAL(findWeather(std::vector<GameUnit*>*,bool)),myField,SLOT(findWeather(std::vector<GameUnit*>*,bool)));

	connect(em,SIGNAL(getRight(GameUnit*,std::vector<GameUnit*>*)),myField,SLOT(getRight(GameUnit*,std::vector<GameUnit*>*)));

	connect(em,SIGNAL(deployRandomCardFromBase(int,int,bool)),myField,SLOT(deployRandomCardFromBase(int,int,bool)));

	connect(em,SIGNAL(getRowIncludeWeather(std::vector<GameUnit*>*,int)),myField,SLOT(getRowIncludeWeather(std::vector<GameUnit*>*,int)));
	}
	if(temp!=nullptr)
		temp->implementEffect(turn);
}

void FieldManager::initBaseEffect(int _id, bool side)
{
	for(auto it=basePassiveEffects.begin();it!=basePassiveEffects.end();++it)
	{
		if((*it)->getUnitId()==_id && (*it)->getSide()==side)
			return;
	}
	//basePassiveEffects.clear();
	CardManager cm(_id);
	EffectManager *em=nullptr;
	if(cm.haveBasePassiveEffect())
	{
		em=new EffectManager(_id,side,nullptr,4);
		basePassiveEffects.push_back(em);
		qDebug()<<"add new base effect "<<_id << basePassiveEffects.size();

	connect(em,SIGNAL(findWeakestInRow(std::vector<GameUnit*>*,int)),myField,SLOT(findWeakestInRow(std::vector<GameUnit*>*,int)));

	connect(em,SIGNAL(findWeakestInRow(std::vector<GameUnit*>*,int,int)),myField,SLOT(findWeakestInRow(std::vector<GameUnit*>*,int,int)));

	connect(em,SIGNAL(findStrongestInRow(std::vector<GameUnit*>*,int)),myField,SLOT(findStrongestInRow(std::vector<GameUnit*>*,int)));

	connect(em,SIGNAL(findStrongestInRow(std::vector<GameUnit*>*,int,int)),myField,SLOT(findStrongestInRow(std::vector<GameUnit*>*,int,int)));

	connect(em,SIGNAL(findNear(std::vector<GameUnit*>*,int,GameUnit*,int,int)),myField,SLOT(findNear(std::vector<GameUnit*>*,int,GameUnit*,int,int)));

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

	connect(em,SIGNAL(generateNCard(int,int,std::vector<GameUnit*>*,int,bool)),myField,SLOT(generateNCard(int,int,std::vector<GameUnit*>*,int,bool)));

	connect(em,SIGNAL(getRow(std::vector<GameUnit*>*,int)),myField,SLOT(getRow(std::vector<GameUnit*>*,int)));

	connect(em,SIGNAL(deployCardsFromBase(int,int,int,bool,int)),myField,SLOT(deployCardsFromBase(int,int,int,bool,int)));

	connect(em,SIGNAL(EffectChooseRow(QJsonObject*)),this,SLOT(receiveEffectChooseRow(QJsonObject*)));

	connect(em,SIGNAL(EffectChooseTarget(QJsonObject*)),this,SLOT(receiveEffectChooseTarget(QJsonObject*)));

	connect(em,SIGNAL(exist(int,bool*,int)),myField,SLOT(exist(int,bool*,int)));

	connect(em,SIGNAL(findWeather(std::vector<GameUnit*>*,bool)),myField,SLOT(findWeather(std::vector<GameUnit*>*,bool)));

	connect(em,SIGNAL(getRight(GameUnit*,std::vector<GameUnit*>*)),myField,SLOT(getRight(GameUnit*,std::vector<GameUnit*>*)));

	connect(em,SIGNAL(deployRandomCardFromBase(int,int,bool)),myField,SLOT(deployRandomCardFromBase(int,int,bool)));

	}
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
	if(effectType==1)
	{
		for(auto it=targetVec->begin();it!=targetVec->end();++it)
		{
			if((*it)->getSelf()==unit)
			{
				(*it)->setDeleteLater();
				break;
			}
		}
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
	QJsonObject info;
	info.insert("type","chooseAndDeploy");
	if(side)
	{
		myThread->waitForDeploy(&info);
	}
	else
	{
		opThread->waitForDeploy(&info);
	}
	if(info.find("error")!=info.end())
	{
		QJsonObject err;
		err.insert("type","error");
		if(!side)
			myThread->sendQJsonObject(err);
		else
			opThread->sendQJsonObject(err);
	}
	else if(info.find("exception")!=info.end() && info["exception"].toString()==QString("timeout"))
	{
		throwOneCard(side);
		return false;
	}
	else if(info.find("pass")!=info.end())
	{
		return false;
	}
	else
	{
		//qDebug()<<info;
		int handIndex=info["handCardIndex"].toInt();
		//qDebug()<<handIndex;
		GameUnit *target=nullptr;
		if(side)
		{
			target=(*(myField->getMyHandCard()))[handIndex];
		}
		else
		{
			target=(*(myField->getOpHandCard()))[handIndex];
		}
		int infoRowNum=info["rowNum"].toInt();
		int infoIndex=info["index"].toInt();
		myField->deployCards(target,infoRowNum,infoIndex);
		return true;
	}
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

void FieldManager::receiveEffectChooseCard(QJsonObject *info)
{
	if(turn)
		emit effectChooseCardMyThread(info);
	else
		emit effectChooseCardOpThread(info);
}

void FieldManager::newCardDeployed(GameUnit *unit)
{
	addEffect(unit->getCardId(),unit,0);
	qDebug()<<unit->getCardId();
	//implementInstant();
}

void FieldManager::cardDestroyed(GameUnit *unit)
{
	implementUnitDeadWish(unit);
	deleteEffect(1,unit->getCardId(),unit);
	addEffect(unit->getCardId(),nullptr,2);
}

void FieldManager::throwOneCard(bool side)
{
	myField->throwCard(side);
	qDebug()<<"throwcard";
}

void FieldManager::checkAllPassive()
{
	qDebug()<<"check all passive";
	implementBasePassive();
	implementDeployPassive();
	implementCemeteryPassive();
	qDebug()<<"check all passive end";
}

void FieldManager::targetEaten(bool eatenside)
{
	for(auto it=deployPassiveEffects.begin();it!=deployPassiveEffects.end();)
	{
		if((*it)->implementEffect(eatenside,1))
		{
			delete(*it);
			it=deployPassiveEffects.erase(it);
		}
		else
		{
			++it;
		}
	}
	for(auto it=basePassiveEffects.begin();it!=basePassiveEffects.end();)
	{
		if((*it)->implementEffect(eatenside,1))
		{
			delete(*it);
			it=basePassiveEffects.erase(it);
		}
		else
		{
			++it;
		}
	}
	for(auto it=cemeteryPassiveEffects.begin();it!=cemeteryPassiveEffects.end();)
	{
		if((*it)->implementEffect(eatenside,1))
		{
			delete(*it);
			it=basePassiveEffects.erase(it);
		}
		else
		{
			++it;
		}
	}
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

	connect(this,SIGNAL(effectChooseRowMyThread(QJsonObject*)),myThread,SLOT(sendQJsonObjectAndWaitForResponde(QJsonObject*)));
	connect(this,SIGNAL(effectChooseTargetMyThread(QJsonObject*)),myThread,SLOT(sendQJsonObjectAndWaitForResponde(QJsonObject*)));
	connect(this,SIGNAL(effectChooseCardMyThread(QJsonObject*)),myThread,SLOT(waitForChooseCard(QJsonObject*)));
}

void FieldManager::setOpThread(MyThread *th)
{
	opThread=th;
	connect(myField,SIGNAL(baseChangedToClient(QJsonObject)),opThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(gameUnitChangedToClient(QJsonObject)),opThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(rowChangedToClient(QJsonObject)),opThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(cemeteryChangedToClient(QJsonObject)),opThread,SLOT(sendQJsonObject(QJsonObject)));
	connect(myField,SIGNAL(handCardChangedToClient(QJsonObject)),opThread,SLOT(sendQJsonObject(QJsonObject)));

	connect(this,SIGNAL(effectChooseRowOpThread(QJsonObject*)),opThread,SLOT(sendQJsonObjectAndWaitForResponde(QJsonObject*)));
	connect(this,SIGNAL(effectChooseTargetOpThread(QJsonObject*)),opThread,SLOT(sendQJsonObjectAndWaitForResponde(QJsonObject*)));
	connect(this,SIGNAL(effectChooseCardOpThread(QJsonObject*)),myThread,SLOT(waitForChooseCard(QJsonObject*)));
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

#ifdef DEBUG
void FieldManager::d_printAll()
{
	qDebug()<<"my point: "<<getMyPoint();
	qDebug()<<"op point: "<<getOpPoint();
	qDebug()<<"my front: "<<getMyFrontPoint();
	d_printRow(1);
	qDebug()<<"my middle: "<<getMyMiddlePoint();
	d_printRow(2);
	qDebug()<<"my back: "<<getMyBackPoint();
	d_printRow(3);
	qDebug()<<"op front: "<<getOpFrontPoint();
	d_printRow(-1);
	qDebug()<<"op middle: "<<getOpMiddlePoint();
	d_printRow(-2);
	qDebug()<<"op back: "<<getOpBackPoint();
	d_printRow(-3);
	qDebug()<<"my handcard";
	d_printHand(true);
	qDebug()<<"op handcard";
	d_printHand(false);
	qDebug()<<"my cemetery";
	d_printCemetery(true);
	qDebug()<<"op cemetery";
	d_printCemetery(false);
	qDebug()<<"my base";
	d_printBase(true);
	qDebug()<<"op base";
	d_printBase(false);
}

void FieldManager::d_printRow(int rowNum)
{
	const std::vector<GameUnit*> *target=nullptr;
	switch(rowNum)
	{
	case 1:
		target=myField->getMyFront();
		break;
	case 2:
		target=myField->getMyMiddle();
		break;
	case 3:
		target=myField->getMyBack();
		break;
	case -1:
		target=myField->getOpFront();
		break;
	case -2:
		target=myField->getOpMiddle();
		break;
	case -3:
		target=myField->getOpBack();
		break;
	}
	for(auto it=target->begin();it!=target->end();++it)
	{
		d_printUnit(*it);
	}
}

void FieldManager::d_printUnit(GameUnit *unit)
{
//	qDebug()<<"    {";
//	qDebug()<<"        id: "<<unit->getCardId();
	qDebug()<<"        name: "<<unit->getName();
//	qDebug()<<"        type: "<<unit->getType();
//	qDebug()<<"        fight: "<<unit->getFight();
//	qDebug()<<"        protection: "<<unit->getProtection();
//	qDebug()<<"    }";
}

void FieldManager::d_printCard(int id)
{
	CardManager cm(id);
//	qDebug()<<"    {";
//	qDebug()<<"        id: "<<id;
	qDebug()<<"        name: "<<cm.getName();
//	qDebug()<<"        type: "<<cm.getType();
//	qDebug()<<"        fight: "<<cm.getFight();
//	qDebug()<<"    }";
}

void FieldManager::d_printHand(bool side)
{
	const std::vector<GameUnit*> *target=nullptr;
	if(side)
	{
		target=myField->getMyHandCard();
	}
	else
	{
		target=myField->getOpHandCard();
	}
	for(auto it=target->begin();it!=target->end();++it)
	{
		d_printUnit(*it);
	}
}

void FieldManager::d_printCemetery(bool side)
{
	const std::vector<int> *target=nullptr;
	if(side)
	{
		target=myField->getMyCemetery();
	}
	else
	{
		target=myField->getOpCemetery();
	}
	for(auto it=target->begin();it!=target->end();++it)
	{
		d_printCard(*it);
	}
}

void FieldManager::d_printBase(bool side)
{
	const std::vector<int> *target=nullptr;
	if(side)
	{
		target=myField->getMyBase();
	}
	else
	{
		target=myField->getOpBase();
	}
	for(auto it=target->begin();it!=target->end();++it)
	{
		d_printCard(*it);
	}
}
#endif
