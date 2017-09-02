#include "gameunit.h"

GameUnit::GameUnit(int _cardId, QObject *parent) : QObject(parent),cardId(_cardId)
{
    CardManager *cm=new CardManager(_cardId);
    fight=cm->getFight();
    name=cm->getName();
    delete(cm);
    if(fight) type=true;
    else type=false;
    protection=0;
    locked=false;
    qDebug()<<"Here";
    qDebug()<<name<<": "<<fight<<" "<<type<<" "<<protection<<" "<<locked;
}

void GameUnit::decreaseFight(int num, bool protectionUnseen)
{
    if(protectionUnseen)
    {
        fight-=num;
    }
    else
    {
        if(num<=protection)
            decreaseProtection(num);
        else
        {
            decreaseProtection(protection);
            fight-=(num-protection);
        }
    }

    emit stateChanged();
}

void GameUnit::addFight(int num)
{
    fight+=num;

    emit stateChanged();
}

void GameUnit::decreaseProtection(int num)
{
    protection-=num;

    emit stateChanged();
}

void GameUnit::addProtection(int num)
{
    protection+=num;

    emit stateChanged();
}

void GameUnit::undoLock()
{
    locked=false;

    emit stateChanged();
}

void GameUnit::addLock()
{
    locked=true;

    emit stateChanged();
}
