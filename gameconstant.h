#ifndef GAMECONSTANT_H
#define GAMECONSTANT_H

#define DEBUG

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
}


#endif // GAMECONSTANT_H
