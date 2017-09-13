#ifndef GAMECONSTANT_H
#define GAMECONSTANT_H

#define DEBUG
#include <iostream>
#include <set>
namespace CONSTANT {
	const int firstDrawNum=10;
	const int firstExchangeNum=3;
	const int secondDrawNum=2;
	const int secondExchangeNum=1;
	const int thirdDrawNum=1;
	const int thirdExchangeNum=1;
	enum cardType {
		gold,
		sliver,
		copper
	};
	const int waitForEffectTargetChoose=30;
	const int waitForDeploy=30;
	const int millisecPerSec=1000;
	const int connectBreakJudge=30000;
	const int temp[3]={100002,100003,100004};
	const std::set<int> allWeather(temp,temp+3);
}


#endif // GAMECONSTANT_H
