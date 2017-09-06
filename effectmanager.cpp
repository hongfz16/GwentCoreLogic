#include "effectmanager.h"

EffectManager::EffectManager(bool _side,GameUnit *target, int effectType, QObject *parent) : QObject(parent), self(target),side(_side)
{
	cm=new CardManager(target->getCardId());
	timer=0;
	/* effectType == 0 -> instant
	 * effectType == 1 -> routine
	 * effectType == 2 -> deadWish
	 * effectType == 3 -> passive
	 */
	switch (effectType) {
	case 0:
		effectJson=cm->getDeployEffect();
		break;
	case 1:
		effectJson=cm->getRoutineEffect();
		break;
	case 2:
		effectJson=cm->getDeadWishEffect();
	case 3:
		effectJson=cm->getPassiveEffect();
	default:
		break;
	}
	prepareJson=cm->getPrepare();
	prepare();
}

std::vector<GameUnit *> *EffectManager::getTargetVec(QString key)
{
	auto it=vecMap.find(key);
	if(it==vecMap.end())
	{
		if(key==QString("chooseTarget"))
		{
			vecMap["chooseTarget"]=chooseTarget();
			return vecMap["chooseTarget"];
		}
		if(key==QString("chooseRow"))
		{
			std::vector<GameUnit*> *vec=nullptr;
			getRow(vec,chooseRow());
			vecMap["chooseRow"]=vec;
			return vec;
		}
		return nullptr;
	}
	return (*it).second;
}

int EffectManager::getTargetInt(QString key)
{
	auto it=intMap.find(key);
	if(it==intMap.end())
		return -1;
	return (*it).second;
}

bool EffectManager::myTimerUp()
{
	return (timer==0) ? true:false;
}

int EffectManager::getRowFight(std::vector<GameUnit *> *vec)
{
	if(vec->empty())
		return 0;
	int total=0;
	for(auto it=vec->begin();it!=vec->end();++it)
	{
		total+=(*it)->getFight();
	}
	return total;
}

int EffectManager::getTargetFight(std::vector<GameUnit *> *vec)
{
	if(vec->empty())
		return 0;
	return (*vec)[0]->getFight();
}

bool EffectManager::judgeCondition(QJsonObject JOCondition)
{
	auto it=JOCondition.find("compare");
	if(it!=JOCondition.end())
	{
		return judgeCompare((*it).toObject());
	}
	it=JOCondition.find("exist");
	if(it!=JOCondition.end())
	{
		return judgeExist((*it).toObject());
	}
	return true;
}

bool EffectManager::judgeCompare(QJsonObject JOCompare)
{
	QJsonValue JVPara1=JOCompare["para1"];
	QJsonValue JVPara2=JOCompare["para2"];
	int para1=judgeCompareGetNum(JVPara1);
	int para2=judgeCompareGetNum(JVPara2);
	return (para1>para2) ? true:false;
}

int EffectManager::judgeCompareGetNum(QJsonValue JVNum)
{
	if(!JVNum.isObject())
	{
		return JVNum.toInt();
	}
	else
	{
		QJsonObject JONum=JVNum.toObject();
		QString funcName=JONum["name"].toString();
		if(funcName==QString("getRowFight"))
		{
			int para=0;
			QJsonValue JVPara=JONum["parameter"];

			QJsonArray JAPara=JVPara.toArray();
			QString paraString=JAPara[0].toString();
			para=transRowNum(paraString);

			std::vector<GameUnit*> *vec=nullptr;
			getRow(vec,para);
			return getRowFight(vec);
		}
		else if(funcName==QString("getTargetFight"))
		{
			QJsonValue JVPara=JONum["parameter"];

			QJsonArray JAPara=JVPara.toArray();
			QJsonObject JOPara=JAPara[0].toObject();
			QString key=(JOPara["parameter"].toArray())[0].toString();
			findTarget(JOPara);
			return getTargetFight(getTargetVec(key));
		}
		return -1;
	}
}

bool EffectManager::judgeExist(QJsonObject JOCompare)
{
//TODO
}

void EffectManager::implementFuntion(QJsonObject funcOb)
{
	QString funcName=funcOb["name"].toString();
	QJsonArray paraArray=funcOb["parameter"].toArray();
	if(funcName==QString("damageByN"))
	{
		emit damageByN(vecMap[paraArray[0].toString()],intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("damageByNUnseenProtection"))
	{
		emit damageByNUnseenProtection(vecMap[paraArray[0].toString()],intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("boostByN"))
	{
		emit boostByN(vecMap[paraArray[0].toString()],intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("addProtectionByN"))
	{
		emit addProtectionByN(vecMap[paraArray[0].toString()],intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("lockTarget"))
	{
		emit lockTarget(vecMap[paraArray[0].toString()]);
		return;
	}
	if(funcName==QString("makePowerToN"))
	{
		emit makePowerToN(vecMap[paraArray[0].toString()],intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("destroyTarget"))
	{
		emit destroyTarget(vecMap[paraArray[0].toString()]);
		return;
	}
	if(funcName==QString("eatTarget"))
	{
		emit eatTarget(vecMap[paraArray[0].toString()],self);
		return;
	}
	if(funcName==QString("moveTarget"))
	{
		emit moveTarget(vecMap[paraArray[0].toString()],intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("peekNCardsFromBase"))
	{
		emit peekNCardsFromBase(intMap[paraArray[0].toString()],boolMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("peekSpecificCardFromBase"))
	{
		emit peekSpecificCardFromBase(intMap[paraArray[0].toString()],boolMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("deployCards"))
	{
		emit deployCards(intMap[paraArray[0].toString()],intMap[paraArray[1].toString()],vecMap[paraArray[0].toString()]);
		return;
	}
	if(funcName==QString("putCardBackToBase"))
	{
		emit putCardBackToBase(unitMap[paraArray[0].toString()],intMap[paraArray[1].toString()],boolMap[paraArray[2].toString()]);
		return;
	}
	if(funcName==QString("resurrectCard"))
	{
		emit resurrectCard(intMap[paraArray[0].toString()],boolMap[paraArray[1].toString()],boolMap[paraArray[2].toString()]);
		return;
	}
	if(funcName==QString("generateNCard"))
	{
		emit generateNCard(intMap[paraArray[0].toString()],intMap[paraArray[1].toString()],unitMap[paraArray[2].toString()],intMap[paraArray[3].toString()]);
		return;
	}

	if(funcName==QString("getRow"))
	{
		emit getRow(vecMap[paraArray[0].toString()],intMap[paraArray[1].toString()]);
		return;
	}

}

int EffectManager::transRowNum(QString rowInfo)
{
	if(rowInfo=="selfRow")
		return self->getRowNum();
	if(rowInfo=="oppositeRow")
		return -(self->getRowNum());
	if(rowInfo=="choose")
		return chooseRow();
	return -1;
}

void EffectManager::findTarget(QJsonObject JOFind)
{
	std::vector<GameUnit*> *vec=nullptr;
	QString paraNum=(JOFind["parameter"].toArray())[0].toString();
	vecMap[paraNum]=vec;
	int size=(JOFind["parameter"].toArray()).size();
	QString funcName=(JOFind["name"].toString());
	int para2=0;
	QJsonArray JAPara=JOFind["parameter"].toArray();
	if(funcName==QString("findWeakestInRow"))
	{
		para2=transRowNum((JOFind["parameter"].toArray())[1].toString());
		switch(size)
		{
		case 2:
			emit findWeakestInRow(vec,para2);
			return;
		case 3:
			emit findWeakestInRow(vec,para2,intMap[JAPara[2].toString()]);
			return;
		}
	}
	if(funcName==QString("findStrongestInRow"))
	{
		para2=transRowNum((JOFind["parameter"].toArray())[1].toString());
		switch(size)
		{
		case 2:
			emit findStrongestInRow(vec,para2);
			return;
		case 3:
			emit findStrongestInRow(vec,para2,intMap[JAPara[2].toString()]);
			return;
		}
	}
	if(funcName==QString("findNear"))
	{
		para2=transRowNum((JOFind["parameter"].toArray())[1].toString());
		emit findNear(vec,para2,self,intMap[JAPara[3].toString()],intMap[JAPara[4].toString()]);
		return;
	}
	if(funcName==QString("findWeakestInAll"))
	{
		switch (size) {
		case 1:
			emit findWeakestInAll(vec);
			return;
		case 2:
			para2=transRowNum((JOFind["parameter"].toArray())[1].toString());
			emit findWeakestInAll(vec,para2);
			return;
		}
	}
	if(funcName==QString("findStrongestInAll"))
	{
		switch(size){
		case 1:
			emit findStrongestInAll(vec);
			return;
		case 2:
			para2=transRowNum((JOFind["parameter"].toArray())[1].toString());
			emit findStrongestInAll(vec,para2);
			return;
		}
	}
}

void EffectManager::prepare()
{
	unitMap["self"]=self;
	boolMap["this"]=side;
	boolMap["that"]=!side;
	for(auto it=prepareJson.begin();it!=prepareJson.end();++it)
	{
		if(it.key()=="int")
		{
			QJsonArray tempArray=it.value().toArray();
			for(auto itt=tempArray.begin();itt!=tempArray.end();++itt)
			{
				QJsonArray insideArray=(*itt).toArray();
				intMap[insideArray[0].toString()]=insideArray[1].toInt();
			}
		}
		if(it.key()=="vector<GameUnit*>*")
		{
			QJsonArray tempArray=it.value().toArray();
			for(auto itt=tempArray.begin();itt!=tempArray.end();++itt)
			{
				vecMap[(*itt).toString()]=nullptr;
			}
		}
		if(it.key()=="bool")
		{
			QJsonArray tempArray=it.value().toArray();
			for(auto itt=tempArray.begin();itt!=tempArray.end();++itt)
			{
				QJsonArray insideArray=(*itt).toArray();
				boolMap[insideArray[0].toString()]=insideArray[1].toBool();
			}
		}
		if(it.key()=="GameUnit*")
		{
			QJsonArray tempArray=it.value().toArray();
			for(auto itt=tempArray.begin();itt!=tempArray.end();++itt)
			{
				QJsonArray insideArray=(*itt).toArray();
				unitMap[insideArray[0].toString()]=nullptr;
			}

		}
	}
}

void EffectManager::implementEffect()
{
	if(!myTimerUp())
		return;
	//TODO
	auto it=effectJson.find("condition");
	if(it!=effectJson.end())
	{
		if(!judgeCondition((*it).toObject()))
			return;
	}
	it=effectJson.find("steps");
	if(it==effectJson.end())
	{
		return;
	}
	QJsonArray JAFunctions=((*it).toObject())["function"].toArray();
	for(auto arrayit=JAFunctions.begin();arrayit!=JAFunctions.end();++arrayit)
	{
		implementFuntion((*arrayit).toObject());
	}
}

void EffectManager::updateTimer()
{
	--timer;
}

int EffectManager::chooseRow()
{
	//TODO
}

std::vector<GameUnit *> *EffectManager::chooseTarget()
{
	//TODO
}
