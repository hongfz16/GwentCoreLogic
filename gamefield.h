#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <vector>
#include <gameunit.h>

class GameField : public QObject
{
	Q_OBJECT
public:
	explicit GameField(QObject *parent = nullptr);

signals:

public slots:
    /*rowNum def
     * -3 opBack
     * -2 opMiddle
     * -1 opFront
     * 1 myFront
     * 2 myMiddle
     * 3 myBack
     */

//#FIND TARGETS:

//TODO
/*
void choseByPlayer(std::vector<GameUnit*>&, int numToChose);

void findWeakestInRow(std::vector<GameUnit*>&, int rowNum, int maxNum);

void findStrongestInRow(vector<card*>&, int rowNum, int maxNum);

void findNear(vector<card*>&, int rowNum, int index, int maxNum);

void findWeakestInAll(vector<card*>&, int maxNum);
void findStrongestInAll(vector<card*>&, int maxNum);

//#CHANGE CONDITION:

void damageByN(vector<card*>&, int N);
void damageByNUnseenProtection(vector<card*>&, int N);

void boostByN(vector<card*>&, int N);

void addProtectionByN(vector<card*>&, int N);

void lockTarget(vector<card*>&);

void makePowerToN(vector<card*>&, int N);

void destroyTarget(vector<card*>&);

void eatTarget(vector<card*>&);

void moveTarget(vector<card*>&, int rowNum,int index);

//#CHANGE HAND CARD

void peekNCardsFromBase(int N);
void peekSpecificCardFromBase(int type);

void deployCards(int id);

void putCardBackToBase(int id, int type);

#CHANGE SEMETREY

void resurrectCard(int id,int rowNum,int index);

#GENERATE CARD

void generateNCard(int id,int rowNum,int index,int num);

#ABOUT SKILLS

void activateDeadWish(vector<card*>&);

void changeWeatherDamageToN(int weatherType, int N);

void removeWeather(int rowNum);

*/
private:
    std::vector<GameUnit*> handCard;
    std::vector<GameUnit*> myFront;
    std::vector<GameUnit*> myMiddle;
    std::vector<GameUnit*> myBack;
    std::vector<GameUnit*> opFront;
    std::vector<GameUnit*> opMiddle;
    std::vector<GameUnit*> opBack;

    std::vector<int> myBase;
    std::vector<int> myCemetery;
    std::vector<int> opCemetery;

    int myPoint;
    int opPoint;

public:
    void setMyBase(std::vector<int>* _base);
    const std::vector<GameUnit*>* getMyFront();
    const std::vector<GameUnit*>* getMyMiddle();
    const std::vector<GameUnit*>* getMyBack();
    const std::vector<GameUnit*>* getOpFront();
    const std::vector<GameUnit*>* getOpMiddle();
    const std::vector<GameUnit*>* getOpBack();
    const std::vector<GameUnit*>* getHandCard();
    const std::vector<int>* getMyCemetery();
    const std::vector<int>* getOpCemetery();
};

#endif // GAMEFIELD_H
