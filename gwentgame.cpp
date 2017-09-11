#include "gwentgame.h"

GwentGame::GwentGame(MyThread *myThread, MyThread *opThread, QObject *parent) : QObject(parent)
{
#ifndef DEBUG
	//TODO
	//need to figure out when the player choose the base
	//need to set thread
	fm=new FieldManager(nullptr,nullptr);
#endif

#ifdef DEBUG
	std::vector<int> *myBase=new std::vector<int>;
	std::vector<int> *opBase=new std::vector<int>;
	for(int i=0;i<4;++i)
	{
		myBase->push_back(100002);
		myBase->push_back(100003);
		myBase->push_back(100004);
		myBase->push_back(100005);
		myBase->push_back(100011);
		opBase->push_back(100002);
		opBase->push_back(100003);
		opBase->push_back(100004);
		opBase->push_back(100005);
		opBase->push_back(100011);
	}
	fm=new FieldManager(myBase,opBase);
	fm->setMyThread(myThread);
	fm->setOpThread(opThread);
#endif
}

void GwentGame::startGame()
{
	fm->shuffle();
	qDebug()<<">>Shuffled!";
	fm->d_printAll();
	while(1)
	{
		qDebug()<<">>New round!";
		if(fm->getMyScore()==2 || fm->getOpScore()==2)
			break;
		fm->newRound();
		qDebug()<<">>Start draw cards!";
		fm->drawCards();
		qDebug()<<">>End draw cards!";
		while(1)
		{
			qDebug()<<">>New turn!";
			fm->d_printAll();
			qDebug()<<">>"<<fm->getTurn();
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
				qDebug()<<">>Start implement instant!";
				fm->implementInstant();//TODO ADD PASSIVE EFFECT CHECK
				qDebug()<<">>End implement instant!";
				qDebug()<<">>Start implement routine!";
				fm->implementRoutine();//TODO ADD PASSIVE EFFECT CHECK
				qDebug()<<">>End implement routine!";
				if(!fm->isOtherPassed())
					fm->changeTurn();
			}
		}
		fm->settlement();
	}
	fm->gameOver();
}
