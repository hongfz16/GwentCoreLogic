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
    myPoint=0;
    opPoint=0;
	myFronPoint=0;
	myMiddlePoint=0;
	myBackPoint=0;
	opFrontPoint=0;
	opMiddlePoint=0;
	opBackPoint=0;
}

void GameField::setMyBase(std::vector<int> *_base)
{
	myBase=*_base;
}

void GameField::setOpBase(std::vector<int> *_base)
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


//TODO
void choseByPlayer(std::vector<GameUnit*>& vec, int numToChose)
{

}


void GameField::findWeakestInRow(std::vector<GameUnit *> *vec, int rowNum)
{
	vec->clear();
	const std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	int temp=1<<8;
	for(auto it=targetRow->begin();it!=targetRow->end();++it)
	{
		if((*it)->getFight()<temp)
			temp=(*it)->getFight();
	}
	for(auto it=targetRow->begin();it!=targetRow->end();++it)
	{
		if((*it)->getFight()==temp)
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
		if((*it)->getFight()>temp)
			temp=(*it)->getFight();
	}
	for(auto it=targetRow->begin();it!=targetRow->end();++it)
	{
		if((*it)->getFight()==temp)
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
			if(count<maxNum && index-i>=0)
			{
				vec->push_back((*(it-i)));
				count++;
			}
			if(count==maxNum)
				break;
			if(count<maxNum && it+i!=targetRow->end())
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
		for(auto temp_it=it-1;index>=0 && count<=maxNum;--temp_it)
		{
			vec->push_back(*temp_it);
			count++;
		}
		break;
	case 2:
		count=0;
		for(auto temp_it=it+1;temp_it!=targetRow->end() && count<=maxNum;++temp_it)
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
	}
}

void GameField::damageByNUnseenProtection(std::vector<GameUnit *> *vec, int N)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		(*it)->decreaseFight(N,true);
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
		if((*it)->getRowNum()>0)
			addToCemetery((*it)->getCardId(),true);
		else
			addToCemetery((*it)->getCardId(),false);

		deleteFromVector((*it));
		delete((*it));
	}
}

void GameField::eatTarget(std::vector<GameUnit *> *vec, GameUnit *eator)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		eator->addFight((*it)->getFight());
	}
	destroyTarget(vec);
}

void GameField::moveTarget(std::vector<GameUnit *> *vec, int toRow)
{
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		deleteFromVector((*it));
		getRowByNum(toRow)->push_back((*it));
		(*it)->setRowNum(toRow);
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
		getBaseBySide(side)->erase(it);
	}
}

//TODO
void GameField::peekSpecificCardFromBase(int type,bool side)
{

}

void GameField::deployCards(GameUnit *unit, int rowNum, int index)
{
	deleteFromHandCard(unit);
	std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	auto targetIt=targetRow->begin()+index;
	targetRow->insert(targetIt,unit);
}

void GameField::deployCards(GameUnit *unit, int rowNum, GameUnit *target)
{
	deleteFromHandCard(unit);
	std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	auto targetIt=targetRow->begin();
	for(;targetIt!=targetRow->end();++targetIt)
		if((*targetIt)==target)
			break;
	targetRow->insert(targetIt,unit);
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
}

void GameField::resurrectCard(int id, bool cemeterySide, bool resurrectSide)
{
	std::vector<int> *targetCeme=getCemeteryBySide(cemeterySide);
	std::vector<GameUnit*> *targetHand=getHandCardBySide(resurrectSide);
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
}

void GameField::generateNCard(int id, int rowNum, int index, int N)
{
	std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	for(int i=0;i<N;++i)
	{
		auto it=targetRow->begin()+index;
		GameUnit *unit=new GameUnit(id);
		targetRow->insert(it,unit);
	}
}

void GameField::generateNCard(int id, int rowNum, GameUnit *target, int N)
{
	std::vector<GameUnit*> *targetRow=getRowByNum(rowNum);
	for(int i=0;i<N;++i)
	{
		auto it=targetRow->begin();
		for(;it!=targetRow->end();++it)
		{
			if((*it)==target)
				break;
		}

		GameUnit *unit=new GameUnit(id);
		targetRow->insert(it,unit);
	}
}

void GameField::deleteFromVector(GameUnit *target)
{
	std::vector<GameUnit*> *targetRow=getRowByNum(target->getRowNum());
	auto it=targetRow->begin();
	for(;it!=targetRow->end();++it)
	{
		if((*it)==target)
			break;
	}
	targetRow->erase(it);
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
}
