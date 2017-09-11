#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "gameunit.h"
#include "gameconstant.h"
#include "cardmanager.h"

class GameField : public QObject
{
	Q_OBJECT
public:
	explicit GameField(QObject *parent = nullptr);

signals:
	void rowChanged(int rowNum);
	void baseChanged(bool side);
	void cemeteryChanged(bool side);
	void handCardChanged(bool side);

	void gameUnitChangedToClient(QJsonObject info);
	void rowChangedToClient(QJsonObject info);
	void baseChangedToClient(QJsonObject info);
	void cemeteryChangedToClient(QJsonObject info);
	void handCardChangedToClient(QJsonObject info);

	void newCardDeployed(GameUnit*);
	void cardDestroyed(GameUnit*);

public slots:

	void gameUnitChanged(GameUnit*target);
	void rowChangedSlot(int rowNum);
	void baseChangedSlot(bool side);
	void cemeteryChangedSlot(bool side);
	void handCardChangedSlot(bool side);

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
	void destroyTarget(GameUnit *target);

	void eatTarget(std::vector<GameUnit*> *vec,GameUnit *eator);

	void moveTarget(std::vector<GameUnit*> *vec,int toRow);

	void peekNCardsFromBase(int N, bool side);
	void peekSpecificCardFromBase(int type,bool side);

	void deployCards(GameUnit *unit, int rowNum, int index);
	void deployCards(GameUnit *unit, int rowNum, GameUnit *target);

	void putCardBackToBase(GameUnit *unit, int type,bool side);

	void resurrectCardToHand(int id, bool cemeterySide,bool resurrectSide,int type);//CHANGED

	void resurrectCardToRow(int id, bool cemeterySide, int rowNum, int index, int type);//CHANGED

	void generateNCard(int id,int rowNum,int index,int N);
	void generateNCard(int id, int rowNum, std::vector<GameUnit*> *_target, int N);
	void generateNCardWithOutChooseTarget(int id, int rowNum, int N, bool side);

	void getRow(std::vector<GameUnit*> *vec,int rowNum);

	void deployCardsFromBase(int id,int rowNum,int index,bool side,int type);


	void clearRow(std::vector<GameUnit*> *row);


private:
	std::vector<GameUnit*> myHandCard;
	std::vector<GameUnit*> opHandCard;
    std::vector<GameUnit*> myFront;
    std::vector<GameUnit*> myMiddle;
    std::vector<GameUnit*> myBack;
    std::vector<GameUnit*> opFront;
    std::vector<GameUnit*> opMiddle;
    std::vector<GameUnit*> opBack;

	std::vector<int> myBase;
	std::vector<int> opBase;
    std::vector<int> myCemetery;
    std::vector<int> opCemetery;
/*
	unsigned int myPoint;
	unsigned int opPoint;
	unsigned int myFronPoint;
	unsigned int myMiddlePoint;
	unsigned int myBackPoint;
	unsigned int opFrontPoint;
	unsigned int opMiddlePoint;
	unsigned int opBackPoint;
*/
	void deleteFromVector(GameUnit *target);
	void addToCemetery(int id, bool side);
	void deleteFromHandCard(GameUnit *target);

	std::vector<GameUnit*>* getRowByNum(int rowNum);
	std::vector<GameUnit*>* getHandCardBySide(bool side);
	std::vector<int> *getBaseBySide(bool side);
	std::vector<int>* getCemeteryBySide(bool side);

	void shuffleVec(std::vector<int>* vec);
	int exchangeCard(int index, std::vector<GameUnit *> *handCard, std::vector<int> *base);

public:
    void setMyBase(std::vector<int>* _base);
	void setOpBase(std::vector<int>* _base);

	const std::vector<GameUnit*>* getMyFront();
    const std::vector<GameUnit*>* getMyMiddle();
    const std::vector<GameUnit*>* getMyBack();
    const std::vector<GameUnit*>* getOpFront();
    const std::vector<GameUnit*>* getOpMiddle();
    const std::vector<GameUnit*>* getOpBack();
	const std::vector<GameUnit*>* getMyHandCard();
	const std::vector<GameUnit*>* getOpHandCard();
    const std::vector<int>* getMyCemetery();
    const std::vector<int>* getOpCemetery();
	const std::vector<int>* getMyBase();
	const std::vector<int>* getOpBase();

	void shuffle();
	void peekCards(int Num);
	void exchangeCards(int index, bool side);
	void roundClear();

};

#endif // GAMEFIELD_H
