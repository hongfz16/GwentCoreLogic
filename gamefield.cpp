#include "gamefield.h"

GameField::GameField(QObject *parent) : QObject(parent)
{
    handCard.clear();
    myFront.clear();
    myMiddle.clear();
    myBack.clear();
    opFront.clear();
    opMiddle.clear();
    opBack.clear();
    myBase.clear();
    myCemetery.clear();
    opCemetery.clear();
    myPoint=0;
    opPoint=0;
}

void GameField::setMyBase(std::vector<int> *_base)
{
    myBase=*_base;
}
/*
//TODO
void choseByPlayer(std::vector<GameUnit*>& vec, int numToChose)
{

}


void findWeakestInRow(std::vector<GameUnit*>& vec, int rowNum, int maxNum)
{

}
//END TODO
*/
