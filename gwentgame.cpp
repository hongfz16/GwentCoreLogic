#include "gwentgame.h"

GwentGame::GwentGame(MyThread *_myThread, MyThread *_opThread, QObject *parent) : QObject(parent)
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
		myBase->push_back(100014);
		myBase->push_back(100015);
		myBase->push_back(100004);
		myBase->push_back(100015);
		myBase->push_back(100014);
		myBase->push_back(100024);
		
		opBase->push_back(100001);
		opBase->push_back(100003);
		opBase->push_back(100003);
		opBase->push_back(100017);
		opBase->push_back(100018);
		opBase->push_back(100019);
	}
	fm=new FieldManager(myBase,opBase);
	qDebug()<<"new fm success";
	fm->setMyThread(_myThread);
	fm->setOpThread(_opThread);
	QJsonObject myPrepare;
	myPrepare.insert("type","prepare");
	myPrepare.insert("side",true);
	QJsonObject opPrepare;
	opPrepare.insert("type","prepare");
	opPrepare.insert("side",false);
	_myThread->sendQJsonObject(myPrepare);
	_opThread->sendQJsonObject(opPrepare);
#endif
}

void GwentGame::startGame()
{

	QJsonObject record;
	fm->shuffle();
	qDebug()<<">>Shuffled!";
	fm->d_printAll();
	int count=0;
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
			qDebug()<<"start implementing routine";
			fm->implementRoutine();
			qDebug()<<"end implementing routine";
			if(fm->isPass())
			{
				fm->changeTurn();
				continue;
			}
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
				//fm->implementInstant();
				qDebug()<<">>End implement instant!";
				qDebug()<<">>Start implement routine!";
				qDebug()<<">>End implement routine!";
				//if(!fm->isOtherPassed())
					fm->changeTurn();
			}
		}
		fm->settlement(&record,count);
		count++;
	}
	fm->gameOver(record);
}
