#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <cardmanager.h>
#include <gameunit.h>
#include <vector>
#include <map>

class EffectManager : public QObject
{
	Q_OBJECT
public:
	explicit EffectManager(bool _side, GameUnit *target, int effectType, QObject *parent = nullptr);

signals:

	/*****************************/
	//FIND TARGET
	void findWeakestInRow(std::vector<GameUnit *> *vec, int rowNum);
	void findWeakestInRow(std::vector<GameUnit*> *vec, int rowNum, int maxNum);

	void findStrongestInRow(std::vector<GameUnit*> *vec,int rowNum);
	void findStrongestInRow(std::vector<GameUnit *> *vec, int rowNum,int maxNum);

	void findNear(std::vector<GameUnit*> *vec, int rowNum, GameUnit *target, int type, int maxNum);
	//type==0 random
	//type==1 left
	//type==2 right

	void findWeakestInAll(std::vector<GameUnit*> *vec);
	void findWeakestInAll(std::vector<GameUnit*> *vec, int maxNum);

	/*rowNum def
	 * -3 opBack
	 * -2 opMiddle
	 * -1 opFront
	 * 1 myFront
	 * 2 myMiddle
	 * 3 myBack
	 */
	void findStrongestInAll(std::vector<GameUnit *> *vec);
	void findStrongestInAll(std::vector<GameUnit *> *vec, int maxNum);

	/****************************/

	void damageByN(std::vector<GameUnit*> *vec,int N);
	void damageByNUnseenProtection(std::vector<GameUnit *> *vec, int N);

	void boostByN(std::vector<GameUnit*> *vec,int N);

	void addProtectionByN(std::vector<GameUnit*> *vec,int N);

	void lockTarget(std::vector<GameUnit*> *vec);

	void makePowerToN(std::vector<GameUnit*> *vec,int N);

	void destroyTarget(std::vector<GameUnit*> *vec);

	void eatTarget(std::vector<GameUnit*> *vec,GameUnit *eator);

	void moveTarget(std::vector<GameUnit*> *vec,int toRow);

	void peekNCardsFromBase(int N, bool side);
	void peekSpecificCardFromBase(int type,bool side);


	void putCardBackToBase(GameUnit *unit, int type,bool side);

	void resurrectCard(int id, bool cemeterySide,bool resurrectSide);

	void generateNCard(int id, int rowNum,GameUnit *target, int N);

	void getRow(std::vector<GameUnit*> *vec,int rowNum);

	/***************/
	//ADD
	void deployCards(int id,int rowNum,std::vector<GameUnit*> *vec);

	//DELETE
	//void deployCards(GameUnit *unit, int rowNum, int index);
	//void deployCards(GameUnit *unit, int rowNum, GameUnit *target);
	//void generateNCard(int id,int rowNum,int index,int N);

	/**************/

private:
	CardManager *cm;

	GameUnit *self;

	bool side;


	std::map<QString,std::vector<GameUnit*>* > vecMap;

	std::map<QString,int> intMap;

	std::map<QString,bool> boolMap;

	std::map<QString,GameUnit*> unitMap;

	std::vector<GameUnit*> *getTargetVec(QString key);
	int getTargetInt(QString key);

	int timer;

	bool myTimerUp();

	QJsonObject effectJson;
	QJsonObject prepareJson;

	int getRowFight(std::vector<GameUnit*> *vec);
	int getTargetFight(std::vector<GameUnit*> *vec);

	bool judgeCondition(QJsonObject JOCondition);

	bool judgeCompare(QJsonObject JOCompare);
	int judgeCompareGetNum(QJsonValue JVNum);

	bool judgeExist(QJsonObject JOCompare);

	void implementFuntion(QJsonObject funcOb);

	int transRowNum(QString rowInfo);

	void findTarget(QJsonObject JOFind);

	void prepare();

public slots:
	void implementEffect();
	void updateTimer();

	int chooseRow(); //TODO UI RELATED
	std::vector<GameUnit*> *chooseTarget();
};

#endif // EFFECTMANAGER_H