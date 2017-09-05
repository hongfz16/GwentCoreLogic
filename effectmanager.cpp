#include "effectmanager.h"

EffectManager::EffectManager(GameUnit *target, int effectType, QObject *parent) : QObject(parent), self(target)
{
	cm=new CardManager(target->getCardId());
	timer=0;
	/* effectType == 0 -> instant
	 * effectType == 1 -> routine
	 * effectType == 2 -> deadWish
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
	default:
		break;
	}
}

std::vector<GameUnit *> *EffectManager::getTargetVec(int index)
{
	return targetVecs[index];
}

int EffectManager::getParaInt(int index)
{
	return paraInt[index];
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

			std::vector<GameUnit*> *vec;
			getRow(vec,para);
			return getRowFight(vec);
		}
		else if(funcName==QString("getTargetFight"))
		{
			int para=0;
			QJsonValue JVPara=JONum["parameter"];

			QJsonArray JAPara=JVPara.toArray();
			QJsonObject JOPara=JAPara[0].toObject();
			QString findInfo=JOPara["name"].toString();
			QJsonArray findPara=JOPara["parameter"].toArray();
			switch (findPara.size()) {
			case 1:

				break;
			default:
				break;
			}
		}
	}
}

bool EffectManager::judgeExist(QJsonObject JOCompare)
{

}

void EffectManager::implementFuntion(QJsonObject funcOb)
{

}

int EffectManager::transRowNum(QString rowInfo)
{
	if(rowInfo=="selfRow")
		return self->getRowNum();
	if(rowInfo=="oppositeRow")
		return -(self->getRowNum());
	if(rowInfo=="choose")
		return chooseRow();
}

std::vector<GameUnit *> EffectManager::transFind(QString transInfo, int rowNum)
{

}

std::vector<GameUnit *> EffectManager::transFind(QString transInfo, int rowNum, int maxNum)
{

}

std::vector<GameUnit *> EffectManager::transFind(QString transInfo, int rowNum, int maxNum, int type, GameUnit *target)
{

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

}
