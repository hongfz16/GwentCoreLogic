#ifndef FIELDMANAGER_H
#define FIELDMANAGER_H

#include <QObject>
#include <QPair>
#include "gameunit.h"
#include "effectmanager.h"
#include "gamefield.h"
#include "gameconstant.h"
#include "mythread.h"
#include <vector>
#include <cstdlib>
#include <ctime>



class FieldManager : public QObject
{
	Q_OBJECT
public:
	explicit FieldManager(std::vector<int>* myBase,std::vector<int>* opBase,QObject *parent = nullptr);

signals:
	void effectChooseRowMyThread(QJsonObject*);
	void effectChooseRowOpThread(QJsonObject*);
	void effectChooseTargetMyThread(QJsonObject*);
	void effectChooseTargetOpThread(QJsonObject*);

private:
	std::vector<EffectManager*> instantEffects;
	std::vector<EffectManager*> routineEffects;
	std::vector<EffectManager*> deadWish;
	std::vector<EffectManager*> deployPassiveEffects;
	std::vector<EffectManager*> basePassiveEffects;
	std::vector<EffectManager*> cemeteryPassiveEffects;

	GameField *myField;

	bool turn;

	MyThread *myThread;
	MyThread *opThread;

	bool myPass;
	bool opPass;
	int myScore;
	int opScore;
	int round;


public slots:
	void implementInstant();
	void implementRoutine();

	//TODO
	//need to add more signals to implement deadwish and passive
	void implementDeadWish();
	void implementUnitDeadWish(GameUnit *unit);
	void implementDeployPassive();
	void implementBasePassive();
	void implementCemeteryPassive();

	void shuffle();

	void firstDraw();//TODO
	void secondDraw();//TODO
	void thirdDraw();//TODO

	void newRound();//TODO
	int settlement();//TODO
	void gameOver();//TODO

	void addEffect(int _id, GameUnit* target, int type);//TODO

	void initBaseEffect(int _id, bool side);

	void deleteEffect(int effectType, int id, GameUnit* unit);

	void changeTurn() {turn=!turn;}

	int getFightFromVec(const std::vector<GameUnit *> *vec);

	bool commonChooseCardAndDeploy(bool side);//TODO

	void setPass(bool side);

	void drawCards();

	void receiveEffectChooseRow(QJsonObject *info);
	void receiveEffectChooseTarget(QJsonObject *info);

	void newCardDeployed(GameUnit *unit);
	void cardDestroyed(GameUnit *unit);

public:
	bool getTurn() {return turn;}

	int getMyPoint();
	int getOpPoint();
	int getMyFrontPoint();
	int getOpFrontPoint();
	int getMyMiddlePoint();
	int getOpMiddlePoint();
	int getMyBackPoint();
	int getOpBackPoint();

	void setMyThread(MyThread *th);
	void setOpThread(MyThread *th);

	bool isOtherPassed();

	int getMyScore() {return myScore;}
	int getOpScore() {return opScore;}
	int getRound() {return round;}

};

#endif // FIELDMANAGER_H
