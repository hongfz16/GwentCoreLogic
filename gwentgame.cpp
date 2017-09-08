#include "gwentgame.h"

GwentGame::GwentGame(QObject *parent) : QObject(parent)
{
	//TODO
	//need to figure out when the player choose the base
	//need to set thread
	fm=new FieldManager(nullptr,nullptr);
}

void GwentGame::startGame()
{
	fm->shuffle();
	while(1)
	{
		if(fm->getMyScore()==2 || fm->getOpScore()==2)
			break;
		fm->newRound();
		fm->drawCards();
		while(1)
		{
			if(!fm->commonChooseCardAndDeploy(fm->getTurn()))
			{
				fm->setPass(fm->getTurn());
				if(fm->isOtherPassed())
					break;
				else
				{
					fm->changeTurn();
				}
			}
			else
			{
				fm->implementInstant();//TODO ADD PASSIVE EFFECT CHECK
				fm->implementRoutine();//TODO ADD PASSIVE EFFECT CHECK
				if(!fm->isOtherPassed())
					fm->changeTurn();
			}
		}
		fm->settlement();
	}
	fm->gameOver();
}
