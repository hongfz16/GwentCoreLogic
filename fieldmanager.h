#ifndef FIELDMANAGER_H
#define FIELDMANAGER_H

#include <QObject>
#include "gameunit.h"
#include "effectmanager.h"
#include "gamefield.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class FieldManager : public QObject
{
	Q_OBJECT
public:
	explicit FieldManager(QObject *parent = nullptr);

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

	void addEffect(int _id,GameUnit* target);

	void changeSide() {side=!side;}

};

#endif // FIELDMANAGER_H
