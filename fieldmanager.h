#ifndef FIELDMANAGER_H
#define FIELDMANAGER_H

#include <QObject>
#include <gameunit.h>
#include <effectmanager.h>
#include <vector>

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

public slots:
	void implementInstant();
	void implementRoutine();
	void implementDeadWish();

	void addEffect(int _id,GameUnit* target);

};

#endif // FIELDMANAGER_H
