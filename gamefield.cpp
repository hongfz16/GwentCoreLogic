#include "gamefield.h"

GameField::GameField(QObject *parent) : QObject(parent)
{
	myHandCard.clear();
	opHandCard.clear();
    myFront.clear();
    myMiddle.clear();
    myBack.clear();
    opFront.clear();
    opMiddle.clear();
    opBack.clear();
    myBase.clear();
	opBase.clear();
    myCemetery.clear();
    opCemetery.clear();

	connect(this,SIGNAL(rowChanged(int)),this,SLOT(rowChangedSlot(int)));
	connect(this,SIGNAL(baseChanged(bool)),this,SLOT(baseChangedSlot(bool)));
	connect(this,SIGNAL(cemeteryChanged(bool)),this,SLOT(cemeteryChangedSlot(bool)));
	connect(this,SIGNAL(handCardChanged(bool)),this,SLOT(handCardChangedSlot(bool)));
}

void GameField::gameUnitChanged(GameUnit *target)
{
	std::vector<GameUnit*> *targetRow=getRowByNum(target->getRowNum());
	int count=0;
	auto it=targetRow->begin();
	for(;it!=targetRow->end();++it)
	{
		if((*it)==target)
			break;
		count++;
	}
	QJsonObject info;
	info.insert("type","unitChanged");
	info.insert("rowNum",target->getRowNum());
	info.insert("index",count);
	info.insert("fight",target->getFight());
	info.insert("protection",target->getProtection());
	info.insert("locked",target->isLocked());
	//qDebug()<<">>>>>>>before unitchanged";
	emit gameUnitChangedToClient(info);
	//qDebug()<<">>>>>>unitchanged";
}

void GameField::rowChangedSlot(int rowNum)
{
	QJsonObject info;
	QJsonArray arr;
	std::vector<GameUnit*> *vec=getRowByNum(rowNum);
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		arr.append((*it)->getCardId());
	}
	info.insert("type","rowChanged");
	info.insert("rowNum",rowNum);
	info.insert("sequence",arr);
	emit rowChangedToClient(info);
	emit rowChangedCheckPassive();
}

void GameField::baseChangedSlot(bool side)
{
	QJsonObject info;
	QJsonArray arr;
	std::vector<int> *vec=getBaseBySide(side);
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		arr.append((*it));
	}
	info.insert("type","baseChanged");
	info.insert("side",side);
	info.insert("sequence",arr);
	emit baseChangedToClient(info);
}

void GameField::cemeteryChangedSlot(bool side)
{
	QJsonObject info;
	QJsonArray arr;
	std::vector<int> *vec=getCemeteryBySide(side);
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		arr.append((*it));
	}
	info.insert("type","cemeteryChanged");
	info.insert("side",side);
	info.insert("sequence",arr);
	emit cemeteryChangedToClient(info);
}

void GameField::handCardChangedSlot(bool side)
{
	QJsonObject info;
	QJsonArray arr;
	std::vector<GameUnit*> *vec=getHandCardBySide(side);
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		arr.append((*it)->getCardId());
	}
	info.insert("type","handCardChanged");
	info.insert("side",side);
	info.insert("sequence",arr);
	emit handCardChangedToClient(info);
}

void GameField::setMyBase(std::vector<int> &_base)
{
	myBase=_base;
}

void GameField::setOpBase(std::vector<int> &_base)
{
	opBase=_base;
}

const std::vector<GameUnit *> *GameField::getMyFront()
{
	return &myFront;
}

const std::vector<GameUnit *> *GameField::getMyMiddle()
{
	return &myMiddle;
}

const std::vector<GameUnit *> *GameField::getMyBack()
{
	return &myBack;
}

const std::vector<GameUnit *> *GameField::getOpFront()
{
	return &opFront;
}

const std::vector<GameUnit *> *GameField::getOpMiddle()
{
	return &opMiddle;
}

const std::vector<GameUnit *> *GameField::getOpBack()
{
	return &opBack;
}

const std::vector<GameUnit *> *GameField::getMyHandCard()
{
	return &myHandCard;
}

const std::vector<GameUnit *> *GameField::getOpHandCard()
{
	return &opHandCard;
}

const std::vector<int> *GameField::getMyCemetery()
{
	return &myCemetery;
}

const std::vector<int> *GameField::getOpCemetery()
{
	return &opCemetery;
}

const std::vector<int> *GameField::getMyBase()
{
	return &myBase;
}

const std::vector<int> *GameField::getOpBase()
{
	return &opBase;
}

void GameField::shuffle()
{
	shuffleVec(&myBase);
	shuffleVec(&opBase);
}

void GameField::peekCards(int Num)
{
	peekNCardsFromBase(Num,true);
	peekNCardsFromBase(Num,false);
}

void GameField::exchangeCards(int index,bool side)
{
	if(side)
	{
		exchangeCard(index,&myHandCard,&myBase);
	}
	else
	{
		exchangeCard(index,&opHandCard,&opBase);
	}
	emit handCardChanged(side);
	emit baseChanged(side);
}

std::vector<GameUnit *> *GameField::getRowByNum(int rowNum)
{
	switch (rowNum) {
	case -3:
		return &opBack;
	case -2:
		return &opMiddle;
	case -1:
		return &opFront;
	case 1:
		return &myFront;
	case 2:
		return &myMiddle;
	case 3:
		return &myBack;
	default:
		return nullptr;
	}
}

std::vector<GameUnit *> *GameField::getHandCardBySide(bool side)
{
	if(side)
	{
		return &myHandCard;
	}
	else
	{
		return &opHandCard;
	}
}

std::vector<int> *GameField::getBaseBySide(bool side)
{
	if(side)
	{
		return &myBase;
	}
	else
	{
		return &opBase;
	}
}

std::vector<int> *GameField::getCemeteryBySide(bool side)
{
	if(side)
	{
		return &myCemetery;
	}
	else
	{
		return &opCemetery;
	}
}

void GameField::shuffleVec(std::vector<int> *vec)
{
	int size=static_cast<int>(vec->size());
	std::vector<int> temp;
	srand((unsigned)time(NULL));
	for(int i=0;i<size;++i)
	{
		temp.push_back(rand());
	}
	for(int i=1;i<size;++i)
	{
		for(int j=i;j>0;--j)
		{
			if(temp[j]<temp[j-1])
			{
				int te=temp[j];
				temp[j]=temp[j-1];
				temp[j-1]=te;
				te=(*vec)[j];
				(*vec)[j]=(*vec)[j-1];
				(*vec)[j-1]=te;
			}
		}
	}
}

int GameField::exchangeCard(int index,std::vector<GameUnit*> *handCard,std::vector<int> *base)
{
	int id=(*handCard)[index]->getCardId();
	delete((*handCard)[index]);
	(*handCard)[index]=new GameUnit(*(base->rend()));
	auto itt=base->begin();
	base->erase(itt);
	srand((unsigned)time(NULL));
	auto it=base->begin()+(rand()%static_cast<int>(base->size()));
	base->insert(it,id);
	return (*handCard)[index]->getCardId();
}


void GameField::findWeakestInRow(std::vector<GameUnit *> *vec, int rowNum)
{
	vec->clear();
	const std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	int temp=1<<8;
	for(auto it=targetRow->begin();it!=targetRow->end();++it)
	{
		if((*it)->getFight()<temp && (*it)->getFight()!=0)
			temp=(*it)->getFight();
	}
	for(auto it=targetRow->begin();it!=targetRow->end();++it)
	{
		if((*it)->getFight()==temp && (*it)->getFight()!=0)
			vec->push_back(*it);
	}
}

void GameField::findWeakestInRow(std::vector<GameUnit*>* vec, int rowNum, int maxNum)
{
	findWeakestInRow(vec,rowNum);
	int size=static_cast<int>(vec->size());
	if(size<=maxNum)
		return;
	else
	{
		for(int i=0;i<size-maxNum;++i)
			vec->pop_back();
	}
}

void GameField::findStrongestInRow(std::vector<GameUnit *> *vec, int rowNum)
{
	vec->clear();
	const std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	int temp=-1;
	for(auto it=targetRow->begin();it!=targetRow->end();++it)
	{
		if((*it)->getFight()>temp && (*it)->getFight()!=0)
			temp=(*it)->getFight();
	}
	for(auto it=targetRow->begin();it!=targetRow->end();++it)
	{
		if((*it)->getFight()==temp && (*it)->getFight()!=0)
			vec->push_back(*it);
	}
}

void GameField::findStrongestInRow(std::vector<GameUnit *> *vec, int rowNum, int maxNum)
{
	findStrongestInRow(vec,rowNum);
	int size=static_cast<int>(vec->size());
	if(size<=maxNum)
		return;
	else
	{
		for(int i=0;i<size-maxNum;++i)
			vec->pop_back();
	}
}

void GameField::findNear(std::vector<GameUnit *> *vec, int rowNum,GameUnit* target, int type, int maxNum)
{
	vec->clear();
	const std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	auto it=targetRow->begin();
	int index=0;
	for(it=targetRow->begin();it!=targetRow->end();++it,++index)
		if((*it)==target)
			break;
	int count=0;
	int i=0;
	switch (type) {
	case 0:
		count=0;
		i=1;
		while(true)
		{
			if(count<maxNum && index-i>=0 && (*(it-i))->getFight()!=0)
			{
				vec->push_back((*(it-i)));
				count++;
			}
			if(count==maxNum)
				break;
			if(count<maxNum && it+i!=targetRow->end() && (*(it+i))->getFight()!=0)
			{
				vec->push_back((*(it+i)));
				count++;
			}
			if(count==maxNum)
				break;
			if(index-i<0 && it+i==targetRow->end())
				break;
			++i;
		}
		break;
	case 1:
		count=0;
		index-=1;
		for(auto temp_it=it-1;index>=0 && count<=maxNum && (*temp_it)->getFight()!=0;--temp_it)
		{
			vec->push_back(*temp_it);
			count++;
		}
		break;
	case 2:
		count=0;
		for(auto temp_it=it+1;temp_it!=targetRow->end() && count<=maxNum && (*temp_it)->getFight()!=0;++temp_it)
		{
			vec->push_back(*temp_it);
			count++;
		}
		break;
	default:
		break;
	}
}

void GameField::findWeakestInAll(std::vector<GameUnit *> *vec)
{
	vec->clear();
	int fight=1<<8;
	std::vector<GameUnit*> *temp=nullptr;
	for(int i=-3;i<=3;++i)
	{
		if(i==0)
		{
			continue;
		}
		findWeakestInRow(temp,i);
		if(temp->size()!=0 && (*temp)[0]->getFight()<fight)
			fight=(*temp)[0]->getFight();
		temp->clear();
	}
	for(int i=-3;i<=3;++i)
	{
		if(i==0)
		{
			continue;
		}
		findWeakestInRow(temp,i);
		if(temp->size()!=0 && (*temp)[0]->getFight()==fight)
			vec->insert(vec->end(),temp->begin(),temp->end());
		temp->clear();
	}
}



void GameField::findWeakestInAll(std::vector<GameUnit *> *vec, int maxNum)
{
	findWeakestInAll(vec);
	int size=static_cast<int>(vec->size());
	if(maxNum>=size)
		return;
	else
	{
		for(int i=0;i<size-maxNum;++i)
			vec->pop_back();
	}
}

void GameField::findStrongestInAll(std::vector<GameUnit *> *vec)
{
	vec->clear();
	int fight=-1;
	std::vector<GameUnit*> *temp=nullptr;
	for(int i=-3;i<=3;++i)
	{
		if(i==0)
		{
			continue;
		}
		findStrongestInRow(temp,i);
		if(temp->size()!=0 && (*temp)[0]->getFight()>fight)
			fight=(*temp)[0]->getFight();
		temp->clear();
	}
	for(int i=-3;i<=3;++i)
	{
		if(i==0)
		{
			continue;
		}
		findStrongestInRow(temp,i);
		if(temp->size()!=0 && (*temp)[0]->getFight()==fight)
			vec->insert(vec->end(),temp->begin(),temp->end());
		temp->clear();
	}
}



void GameField::findStrongestInAll(std::vector<GameUnit *> *vec, int maxNum)
{
	findStrongestInAll(vec);
	int size=static_cast<int>(vec->size());
	if(maxNum>=size)
		return;
	else
	{
		for(int i=0;i<size-maxNum;++i)
			vec->pop_back();
	}
}

void GameField::damageByN(std::vector<GameUnit *> *vec, int N)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		(*it)->decreaseFight(N);
		if((*it)->getFight()==0)
		{
			std::vector<GameUnit*> temp;
			temp.push_back((*it));
			destroyTarget(&temp);
		}
	}
}

void GameField::damageByNUnseenProtection(std::vector<GameUnit *> *vec, int N)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		(*it)->decreaseFight(N,true);
		if((*it)->getFight()==0)
		{
			std::vector<GameUnit*> temp;
			temp.push_back((*it));
			destroyTarget(&temp);
		}
	}
}

void GameField::boostByN(std::vector<GameUnit *> *vec, int N)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		(*it)->addFight(N);
	}
}

void GameField::addProtectionByN(std::vector<GameUnit *> *vec, int N)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		(*it)->addProtection(N);
	}
}

void GameField::lockTarget(std::vector<GameUnit *> *vec)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		(*it)->addLock();
	}
}

void GameField::makePowerToN(std::vector<GameUnit *> *vec, int N)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		(*it)->setFightToN(N);
	}
}

void GameField::destroyTarget(std::vector<GameUnit *> *vec)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		if((*it)->getSide())
			addToCemetery((*it)->getCardId(),true);
		else
			addToCemetery((*it)->getCardId(),false);
		std::vector<GameUnit*> *targetRow=getRowByNum((*it)->getRowNum());
		int count=0;
		auto itt=targetRow->begin();
		for(;itt!=targetRow->end();++itt)
		{
			if((*itt)==(*it))
				break;
			count++;
		}
		deleteFromVector((*it));
		emit cardDestroyed((*it));
		delete((*it));
	}
}

void GameField::destroyTarget(GameUnit *target,bool nosignal=false)
{
	if(target->getRowNum()>0)
		addToCemetery(target->getCardId(),true);
	else
		addToCemetery(target->getCardId(),false);
	std::vector<GameUnit*> *targetRow=getRowByNum(target->getRowNum());
	int count=0;
	auto itt=targetRow->begin();
	for(;itt!=targetRow->end();++itt)
	{
		if((*itt)==target)
			break;
		count++;
	}
	if(!nosignal)
		deleteFromVector(target);
	emit cardDestroyed(target);
	delete(target);
}

void GameField::eatTarget(std::vector<GameUnit *> *vec, GameUnit *eator)
{
	bool eatenSide;
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		eatenSide=(*it)->getSide();
		eator->addFight((*it)->getFight());
	}
	destroyTarget(vec);
	emit targetEaten(eator->getSide());
}

void GameField::moveTarget(std::vector<GameUnit *> *vec, int toRow)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		deleteFromVector((*it));
		getRowByNum(toRow)->push_back((*it));
		(*it)->setRowNum(toRow);
		emit rowChanged(toRow);
	}
}

void GameField::peekNCardsFromBase(int N,bool side)
{
	for(int i=0;i<N;++i)
	{
		auto it=getBaseBySide(side)->begin();
		GameUnit *unit=new GameUnit((*it));
		unit->setRowNum(0);
		unit->setSide(side);
		getHandCardBySide(side)->push_back(unit);
		connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
		getBaseBySide(side)->erase(it);
	}
	emit baseChanged(side);
	emit handCardChanged(side);
}

void GameField::peekSpecificCardFromBase(int type,bool side)
{
	std::vector<int> *targetBase=getBaseBySide(side);
	auto it=targetBase->begin();
	for(;it!=targetBase->end();++it)
	{
		CardManager cm((*it));
		if(cm.getType()==type)
			break;
	}
	int id=*it;
	targetBase->erase(it);
	GameUnit *unit=new GameUnit(id);
	unit->setRowNum(0);
	unit->setSide(side);
	getHandCardBySide(side)->push_back(unit);
	connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
	emit baseChanged(side);
	emit handCardChanged(side);
}

void GameField::deployCards(GameUnit *unit, int rowNum, int index)
{
	deleteFromHandCard(unit);
	std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	int id=unit->getCardId();
	if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
	{
		for(auto it=targetRow->begin();it!=targetRow->end();++it)
		{
			int tempid=(*it)->getCardId();
			if(CONSTANT::allWeather.find(tempid)!=CONSTANT::allWeather.end())
			{
				destroyTarget((*it));
				break;
			}
		}
	}
	auto targetIt=targetRow->begin()+index;
	targetRow->insert(targetIt,unit);
	unit->setRowNum(rowNum);
	emit rowChanged(rowNum);
	emit newCardDeployed(unit);
}

void GameField::deployCards(GameUnit *unit, int rowNum, GameUnit *target)
{
	deleteFromHandCard(unit);
	std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	int id=unit->getCardId();
	if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
	{
		for(auto it=targetRow->begin();it!=targetRow->end();++it)
		{
			int tempid=(*it)->getCardId();
			if(CONSTANT::allWeather.find(tempid)!=CONSTANT::allWeather.end())
			{
				destroyTarget((*it));
				break;
			}
		}
	}
	auto targetIt=targetRow->begin();
	for(;targetIt!=targetRow->end();++targetIt)
		if((*targetIt)==target)
			break;
	targetRow->insert(targetIt,unit);
	unit->setRowNum(rowNum);
	emit rowChanged(rowNum);
	emit newCardDeployed(unit);
}

void GameField::putCardBackToBase(GameUnit *unit, int type,bool side)
{
	deleteFromHandCard(unit);
	auto it=getBaseBySide(side)->begin();
	switch (type){
	case 0:
		getBaseBySide(side)->insert(it,unit->getCardId());
		delete(unit);
		break;
	case 1:
		qsrand((unsigned)time(NULL));
		it+=(rand()%static_cast<int>(getBaseBySide(side)->size()));
		getBaseBySide(side)->insert(it,unit->getCardId());
		delete(unit);
		break;
	case 2:
		getBaseBySide(side)->push_back(unit->getCardId());
		delete(unit);
		break;
	default:
		break;
	}
	emit baseChanged(side);
}

void GameField::resurrectCardToRow(int id, bool cemeterySide, int rowNum, int index,int type)
{
	std::vector<int> *targetCeme=getCemeteryBySide(cemeterySide);
	std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);

	if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
	{
		for(auto it=targetRow->begin();it!=targetRow->end();++it)
		{
			int tempid=(*it)->getCardId();
			if(CONSTANT::allWeather.find(tempid)!=CONSTANT::allWeather.end())
			{
				destroyTarget((*it));
				break;
			}
		}
	}

	bool resurrectSide;
	if(rowNum>0) resurrectSide=true;
	else resurrectSide=false;
	if(type==0) //resurrect all
	{
		int count=0;
		for(auto it=targetCeme->begin();it!=targetCeme->end();++it)
			if((*it)==id)
			{
				targetCeme->erase(it);
				count++;
			}
		for(int i=0;i<count;++i)
		{
			GameUnit *unit=new GameUnit(id);
			unit->setSide(resurrectSide);
			unit->setRowNum(rowNum);
			targetRow->insert(targetRow->begin()+index,unit);
			connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
			emit newCardDeployed(unit);
		}
	}
	else
	{
		for(auto it=targetCeme->begin();it!=targetCeme->end();++it)
			if((*it)==id)
			{
				targetCeme->erase(it);
				break;
			}
		GameUnit *unit=new GameUnit(id);
		unit->setSide(resurrectSide);
		unit->setRowNum(rowNum);
		targetRow->insert(targetRow->begin()+index,unit);
		connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
		emit newCardDeployed(unit);
	}
	emit cemeteryChanged(cemeterySide);
	emit rowChanged(rowNum);
}

void GameField::resurrectCardToHand(int id, bool cemeterySide, bool resurrectSide,int type)
{
	std::vector<int> *targetCeme=getCemeteryBySide(cemeterySide);
	std::vector<GameUnit*> *targetHand=getHandCardBySide(resurrectSide);
	if(type==0)
	{
		int count=0;
		for(auto it=targetCeme->begin();it!=targetCeme->end();++it)
			if((*it)==id)
			{
				targetCeme->erase(it);
				count++;
			}
		for(int i=0;i<count;++i)
		{
			GameUnit *unit=new GameUnit(id);
			unit->setSide(resurrectSide);
			unit->setRowNum(0);
			targetHand->push_back(unit);
			connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
		}
	}
	else
	{
		for(auto it=targetCeme->begin();it!=targetCeme->end();++it)
			if((*it)==id)
			{
				targetCeme->erase(it);
				break;
			}
		GameUnit *unit=new GameUnit(id);
		unit->setSide(resurrectSide);
		unit->setRowNum(0);
		targetHand->push_back(unit);
		connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
	}
	emit cemeteryChanged(cemeterySide);
	emit handCardChanged(resurrectSide);
}

void GameField::generateNCard(int id, int rowNum, int index, int N,bool side)
{
	std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
	{
		for(auto it=targetRow->begin();it!=targetRow->end();++it)
		{
			int tempid=(*it)->getCardId();
			if(CONSTANT::allWeather.find(tempid)!=CONSTANT::allWeather.end())
			{
				destroyTarget((*it));
				break;
			}
		}
	}
	for(int i=0;i<N;++i)
	{
		auto it=targetRow->begin()+index;
		GameUnit *unit=new GameUnit(id);
		unit->setRowNum(rowNum);
		unit->setSide(side);
		targetRow->insert(it,unit);
		connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
		emit newCardDeployed(unit);
	}
	emit rowChanged(rowNum);
}

void GameField::generateNCard(int id, int rowNum, std::vector<GameUnit *> *_target, int N,bool side)
{
	std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
	{
		for(auto it=targetRow->begin();it!=targetRow->end();++it)
		{
			int tempid=(*it)->getCardId();
			if(CONSTANT::allWeather.find(tempid)!=CONSTANT::allWeather.end())
			{
				destroyTarget((*it));
				break;
			}
		}
	}
	GameUnit *target=(*_target)[0];
	for(int i=0;i<N;++i)
	{
		auto it=targetRow->begin();
		for(;it!=targetRow->end();++it)
		{
			if((*it)==target)
				break;
		}

		GameUnit *unit=new GameUnit(id);
		unit->setRowNum(rowNum);
		unit->setSide(side);
		targetRow->insert(it,unit);
		connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
		emit newCardDeployed(unit);
	}
	emit rowChanged(rowNum);
}

void GameField::generateNCardWithOutChooseTarget(int id, int rowNum, int N,bool side)
{
	std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	//qDebug()<<"here"<<id<<" "<<N<<" "<<rowNum;
	//TODELETE
	if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
	{
		for(auto it=targetRow->begin();it!=targetRow->end();++it)
		{
			int tempid=(*it)->getCardId();
			if(CONSTANT::allWeather.find(tempid)!=CONSTANT::allWeather.end())
			{
				destroyTarget((*it));
				break;
			}
		}
	}
	for(int i=0;i<N;++i)
	{
		GameUnit *unit=new GameUnit(id);
		unit->setSide(side);
		unit->setRowNum(rowNum);
		targetRow->push_back(unit);
		connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
		emit newCardDeployed(unit);
	}
	emit rowChanged(rowNum);
}

void GameField::getRow(std::vector<GameUnit *> *vec, int rowNum)
{
	//vec=new std::vector<GameUnit*>;
	std::vector<GameUnit*> *ori=nullptr;
	ori=getRowByNum(rowNum);
	for(auto it=ori->begin();it!=ori->end();++it)
	{
		if((*it)->getFight()!=0)
			vec->push_back((*it));
	}
}

void GameField::getRowIncludeWeather(std::vector<GameUnit *> *vec, int rowNum)
{
	std::vector<GameUnit*> *ori=nullptr;
	ori=getRowByNum(rowNum);
	for(auto it=ori->begin();it!=ori->end();++it)
	{
		vec->push_back((*it));
	}
}



void GameField::deployCardsFromBase(int id, int rowNum, int index, bool side, int type)
{
	std::vector<int> *targetBase=getBaseBySide(side);
	std::vector<GameUnit*> *targetVec=getRowByNum(rowNum);
	if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
	{
		for(auto it=targetVec->begin();it!=targetVec->end();++it)
		{
			int tempid=(*it)->getCardId();
			if(CONSTANT::allWeather.find(tempid)!=CONSTANT::allWeather.end())
			{
				destroyTarget((*it));
				break;
			}
		}
	}
	//qDebug()<<"get base and row";
	if(type==0 || type==-1)
	{
		int count=0;
		for(auto it=targetBase->begin();it!=targetBase->end();)
		{
			//qDebug()<<(*it);
			if((*it)==id)
			{
				it=targetBase->erase(it);
				count++;
			}
			else
			{
				++it;
			}
		}
		//qDebug()<<"erase all the id in the base";
		for(int i=0;i<count;++i)
		{
			int myIndex=index;
			int myRowNum=rowNum;
			if(type==-1)
			{
				myRowNum=rand()%3*(side?1:-1);
				targetVec=getRowByNum(myRowNum);
				if(targetVec->empty())
					myIndex=0;
				else
					myIndex=rand()%(targetVec->size());
			}
			GameUnit *unit=new GameUnit(id);
			unit->setSide(side);
			unit->setRowNum(myRowNum);
			targetVec->insert(targetVec->begin()+myIndex,unit);
			connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
			//qDebug()<<"so far so good";
			emit newCardDeployed(unit);
			emit rowChanged(myRowNum);
		}
	}
	else
	{
		for(auto it=targetBase->begin();it!=targetBase->end();)
		{
			if((*it)==id)
			{
				it=targetBase->erase(it);
				break;
			}
			else
			{
				++it;
			}
		}
		GameUnit *unit=new GameUnit(id);
		unit->setSide(side);
		unit->setRowNum(rowNum);
		targetVec->insert(targetVec->begin()+index,unit);
		connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
		emit newCardDeployed(unit);
		emit rowChanged(rowNum);
	}
}

void GameField::deployRandomCardFromBase(int rowNum, int index, bool side)
{
	std::vector<int> *targetBase=getBaseBySide(side);
	srand((unsigned)time(NULL));
	int randindex=rand()%(targetBase->size());
	auto it=targetBase->begin()+randindex;
	int id=(*it);
	targetBase->erase(it);
	emit baseChanged(side);
qDebug()<<"before check weather";
	std::vector<GameUnit*>*targetvec=getRowByNum(rowNum);
	if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
	{
		for(auto it=targetvec->begin();it!=targetvec->end();++it)
		{
			int tempid=(*it)->getCardId();
			if(CONSTANT::allWeather.find(tempid)!=CONSTANT::allWeather.end())
			{
				destroyTarget((*it));
				break;
			}
		}
	}
qDebug()<<"after check weather";
	GameUnit *unit=new GameUnit(id);
	unit->setRowNum(rowNum);
	unit->setSide(side);
	connect(unit,SIGNAL(stateChanged(GameUnit*)),this,SLOT(gameUnitChanged(GameUnit*)));
	targetvec->insert(targetvec->begin()+index,unit);
	emit rowChanged(rowNum);
	emit newCardDeployed(unit);
}

void GameField::roundClear()
{
	qDebug()<<"start clear";
	clearRow(&opBack);
	clearRow(&opMiddle);
	clearRow(&opFront);
	clearRow(&myBack);
	clearRow(&myMiddle);
	clearRow(&myFront);
	qDebug()<<"end clear";
}

void GameField::clearRow(std::vector<GameUnit *> *row)
{
	for(auto it=row->begin();it!=row->end();)
	{
		if((*it)->isLocked())
		{
			(*it)->undoLock();
			++it;
		}
		else
		{
			GameUnit* temp=(*it);
			destroyTarget(temp,true);
			it=row->erase(it);
			//delete(temp);
		}
	}
}

void GameField::updateHandCard(bool side, QJsonObject info)
{
	if(info.find("hand")==info.end())
	{
		qDebug()<<"drawcard: updateHandCard: can not find \"hand\"";
		return;
	}
	std::vector<GameUnit*> *targethandcard=getHandCardBySide(side);
	//for(auto it=targethandcard->begin();it!=targethandcard->end();++it)
	//{
		//delete((*it));
	//}
	targethandcard->clear();
	QJsonArray handarr=info.find("hand").value().toArray();
	for(auto it=handarr.begin();it!=handarr.end();++it)
	{
		qDebug()<<(*it).toInt();
		GameUnit *unit=new GameUnit((*it).toInt());
		unit->setRowNum(0);
		unit->setSide(side);
		targethandcard->push_back(unit);
	}
	emit handCardChanged(side);
}

void GameField::updateBase(bool side, QJsonObject info)
{
	if(info.find("base")==info.end())
	{
		qDebug()<<"drawcard: updatebase: can not find \"base\"";
		return;
	}
	std::vector<int> *targetbase=getBaseBySide(side);
	targetbase->clear();
	QJsonArray basearr=info.find("base").value().toArray();
	for(auto it=basearr.begin();it!=basearr.end();++it)
	{
		targetbase->push_back((*it).toInt());
	}
	emit baseChanged(side);
}

void GameField::exist(int id, bool *re,int type)
{
	qDebug()<<"start exist func";
	qDebug()<<"finding "<<id<<" type: "<<type;
	if(type==1 || type==0)
	{
		for(auto it=myFront.begin();it!=myFront.end();++it)
		{
			if((*it)->getCardId()==id)
			{
				*re=true;
				return;
			}
		}
		for(auto it=myMiddle.begin();it!=myMiddle.end();++it)
		{
			if((*it)->getCardId()==id)
			{
				*re=true;
				return;
			}
		}
		for(auto it=myBack.begin();it!=myBack.end();++it)
		{
			if((*it)->getCardId()==id)
			{
				*re=true;
				return;
			}
		}
	}
	if(type==-1 || type==0)
	{
		for(auto it=opFront.begin();it!=opFront.end();++it)
		{
			if((*it)->getCardId()==id)
			{
				*re=true;
				return;
			}
		}
		for(auto it=opMiddle.begin();it!=opMiddle.end();++it)
		{
			if((*it)->getCardId()==id)
			{
				*re=true;
				return;
			}
		}
		for(auto it=opBack.begin();it!=opBack.end();++it)
		{
			if((*it)->getCardId()==id)
			{
				*re=true;
				return;
			}
		}
	}
	*re=false;
	qDebug()<<(*re)<<"exist func return";
}

void GameField::throwCard(bool side)
{
	std::vector<GameUnit*> *hand=getHandCardBySide(side);
	srand((unsigned)time(NULL));
	int index=rand()%hand->size();
	delete((*hand)[index]);
	hand->erase(hand->begin()+index);
	emit handCardChanged(side);
}

void GameField::findWeather(std::vector<GameUnit *> *vec, bool side)
{
	std::vector<GameUnit*> *vec1=nullptr;
	std::vector<GameUnit*> *vec2=nullptr;
	std::vector<GameUnit*> *vec3=nullptr;

	if(side)
	{
		vec1=getRowByNum(1);
		vec2=getRowByNum(2);
		vec3=getRowByNum(3);
	}
	else
	{
		vec1=getRowByNum(-1);
		vec2=getRowByNum(-2);
		vec3=getRowByNum(-3);
	}
	for(auto it=vec1->begin();it!=vec1->end();++it)
	{
		int id=(*it)->getCardId();
		if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
		{
			vec->push_back((*it));
		}
	}
	for(auto it=vec2->begin();it!=vec2->end();++it)
	{
		int id=(*it)->getCardId();
		if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
		{
			vec->push_back((*it));
		}
	}
	for(auto it=vec3->begin();it!=vec3->end();++it)
	{
		int id=(*it)->getCardId();
		if(CONSTANT::allWeather.find(id)!=CONSTANT::allWeather.end())
		{
			vec->push_back((*it));
		}
	}
}

void GameField::getRight(GameUnit *self, std::vector<GameUnit *> *right)
{
	qDebug()<<"try to getright";
	int rowNum=self->getRowNum();
	std::vector<GameUnit*> *vec=getRowByNum(rowNum);
	auto it=vec->begin();
	for(it=vec->begin();it!=vec->end();++it)
	{
		if((*it)==self)
			break;
	}
	if((it+1)!=vec->end())
	{
		qDebug()<<"found right";
		right->push_back(*(it+1));
	}
}

void GameField::deleteFromVector(GameUnit *target)
{
	std::vector<GameUnit*> *targetRow=getRowByNum(target->getRowNum());
	int count=0;
	auto it=targetRow->begin();
	for(;it!=targetRow->end();++it)
	{
		if((*it)==target)
			break;
		count++;
	}
	targetRow->erase(it);
	emit rowChanged(target->getRowNum());
}

void GameField::addToCemetery(int id,bool side)
{
	if(side)
	{
		auto it=myCemetery.begin();
		myCemetery.insert(it,id);
	}
	else
	{
		auto it=opCemetery.begin();
		opCemetery.insert(it,id);
	}
	emit cemeteryChanged(side);
}

void GameField::deleteFromHandCard(GameUnit *target)
{
	auto it=getHandCardBySide(target->getSide())->begin();
	for(;it!=getHandCardBySide(target->getSide())->end();++it)
	{
		if((*it)==target)
			break;
	}
	getHandCardBySide(target->getSide())->erase(it);
	emit handCardChanged(target->getSide());
}
