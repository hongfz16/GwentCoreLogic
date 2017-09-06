#ifndef FIELDMANAGER_H
#define FIELDMANAGER_H

#include <QObject>
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


private:
	std::vector<EffectManager*> instantEffects;
	std::vector<EffectManager*> routineEffects;
	std::vector<EffectManager*> deadWish;
	std::vector<EffectManager*> passiveEffects;

	GameField *myField;

	bool side;

public slots:
	void implementInstant();
	void implementRoutine();
	void implementDeadWish();
	void implementPassive();

	void shuffle();

	void firstDraw();
	void secondDraw();
	void thirdDraw();

	void addEffect(int _id,GameUnit* target);

	void changeSide() {side=!side;}

	int getFightFromVec(const std::vector<GameUnit *> *vec);

public:
	bool getSide() {return side;}

	int getMyPoint();
	int getOpPoint();
	int getMyFrontPoint();
	int getOpFrontPoint();
	int getMyMiddlePoint();
	int getOpMiddlePoint();
	int getMyBackPoint();
	int getOpBackPoint();

};

#endif // FIELDMANAGER_H
