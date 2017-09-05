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

class EffectManager : public QObject
{
	Q_OBJECT
public:
	explicit EffectManager(GameUnit *target,int effectType,QObject *parent = nullptr);

signals:
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

	void deployCards(GameUnit *unit, int rowNum, int index);
	void deployCards(GameUnit *unit, int rowNum, GameUnit *target);

	void putCardBackToBase(GameUnit *unit, int type,bool side);

	void resurrectCard(int id, bool cemeterySide,bool resurrectSide);

	void generateNCard(int id,int rowNum,int index,int N);
	void generateNCard(int id, int rowNum,GameUnit *target, int N);

	void getRow(std::vector<GameUnit*> *vec,int rowNum);

private:
	CardManager *cm;

	GameUnit *self;


	std::vector<std::vector<GameUnit*>* > targetVecs;

	std::vector<int> paraInt;

	std::vector<GameUnit*> *getTargetVec(int index);
	int getParaInt(int index);

	int timer;

	bool myTimerUp();

	QJsonObject effectJson;

	int getRowFight(std::vector<GameUnit*> *vec);
	int getTargetFight(std::vector<GameUnit*> *vec);

	bool judgeCondition(QJsonObject JOCondition);

	bool judgeCompare(QJsonObject JOCompare);
	int judgeCompareGetNum(QJsonValue JVNum);

	bool judgeExist(QJsonObject JOCompare);

	void implementFuntion(QJsonObject funcOb);

	int transRowNum(QString rowInfo);

	std::vector<GameUnit*> transFind(QString transInfo,int rowNum);
	std::vector<GameUnit*> transFind(QString transInfo,int rowNum,int maxNum);
	std::vector<GameUnit*> transFind(QString transInfo, int rowNum,int maxNum,int type,GameUnit *target);

public slots:
	void implementEffect();
	void updateTimer();

	int chooseRow(); //TODO UI RELATED
};

#endif // EFFECTMANAGER_H
