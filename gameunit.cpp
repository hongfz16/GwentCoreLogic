#include "gameunit.h"

GameUnit::GameUnit(int _cardId, QObject *parent) : QObject(parent),cardId(_cardId)
{
	CardManager *cm=new CardManager(_cardId);
    fight=cm->getFight();
    name=cm->getName();
	switch (cm->getType())
	{
	case 1:
		myType=CONSTANT::gold;
		break;
	case 2:
		myType=CONSTANT::sliver;
		break;
	case 3:
		myType=CONSTANT::copper;
		break;
	}
	delete(cm);
    if(fight) type=true;
    else type=false;
    protection=0;
    locked=false;
	oldRowNum=0;
	rowNum=0;
	//qDebug()<<"Here";
	//qDebug()<<name<<": "<<fight<<" "<<type<<" "<<protection<<" "<<locked;
}

void GameUnit::decreaseFight(int num, bool protectionUnseen)
{
    if(protectionUnseen)
    {
		if(num>fight)
			fight=0;
		else
			fight-=num;
    }
    else
    {
        if(num<=protection)
            decreaseProtection(num);
        else
        {
            decreaseProtection(protection);
            decreaseFight(num-protection,true);
        }
    }

	emit stateChanged(this);
}

void GameUnit::addFight(int num)
{
    fight+=num;

	emit stateChanged(this);
}

void GameUnit::decreaseProtection(int num)
{
    protection-=num;

	emit stateChanged(this);
}

void GameUnit::addProtection(int num)
{
    protection+=num;

	emit stateChanged(this);
}

void GameUnit::undoLock()
{
    locked=false;

	emit stateChanged(this);
}

void GameUnit::addLock()
{
    locked=true;

	emit stateChanged(this);
}

void GameUnit::setFightToN(int N)
{
	fight=N;

	emit stateChanged(this);
}

void GameUnit::setRowNum(int num)
{
	oldRowNum=rowNum;
	rowNum=num;
	//emit stateChanged(this);
}

void GameUnit::setSide(bool _side)
{
	side=_side;
	//emit stateChanged(this);
}
