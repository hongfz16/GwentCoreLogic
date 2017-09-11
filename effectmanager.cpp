#include "effectmanager.h"

EffectManager::EffectManager(int id, bool _side, GameUnit *target, int effectType, QObject *parent) : QObject(parent), self(target),side(_side)
{
	cm=new CardManager(target->getCardId());
	timer=0;
	unitId=id;
	needTimer=false;
	/* effectType == 0 -> instant
	 * effectType == 1 -> routine
	 * effectType == 2 -> deadWish
	 * effectType == 3 -> deploypassive
	 * effectType == 4 -> basePassive
	 * effectType == 5 -> cemeteryPassive
	 */
	switch (effectType) {
	case 0:
		effectJson=cm->getDeployEffect();
		break;
	case 1:
		effectJson=cm->getRoutineEffect();
		timer=cm->getTimer();
		needTimer=true;
		break;
	case 2:
		effectJson=cm->getDeadWishEffect();
		break;
	case 3:
		effectJson=cm->getDeployPassiveEffect();
		break;
	case 4:
		effectJson=cm->getBasePassiveEffect();
		break;
	case 5:
		effectJson=cm->getCemeteryPassiveEffect();
		break;
	default:
		break;
	}
	prepareJson=cm->getPrepare();
	prepare();
	//TODELETE
	//QJsonDocument temp(effectJson);
	//qDebug()<<temp.toJson();
}

std::vector<GameUnit *> *EffectManager::getTargetVec(QString key)
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
	auto it=vecMap.find(key);
	return it.value();
}

int EffectManager::getTargetInt(QString key)
{
	auto it=intMap.find(key);
	if(it==intMap.end())
	{
		return transRowNum(key);
	}
	return it.value();
}

GameUnit *EffectManager::getTargetUnit(QString key)
{
	if(key==QString("chooseTarget"))
	{
		unitMap["chooseTarget"]=(*chooseTarget())[0];
		return unitMap["chooseTarget"];
	}
	auto it=unitMap.find(key);
	return it.value();
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
	QJsonObject JOFind=funcOb;
	QString funcName=(JOFind["name"].toString());
	int para2=0;
	QJsonArray JAPara=JOFind["parameter"].toArray();
	if(funcName==QString("findWeakestInRow"))
	{
		std::vector<GameUnit*> *vec=new std::vector<GameUnit*>();
		QString paraNum=(JOFind["parameter"].toArray())[0].toString();
		vecMap[paraNum]=vec;
		int size=(JOFind["parameter"].toArray()).size();

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
		std::vector<GameUnit*> *vec=new std::vector<GameUnit*>();
		QString paraNum=(JOFind["parameter"].toArray())[0].toString();
		vecMap[paraNum]=vec;
		int size=(JOFind["parameter"].toArray()).size();

		para2=getTargetInt((JOFind["parameter"].toArray())[1].toString());
		switch(size)
		{
		case 2:
			emit findStrongestInRow(vec,para2);
			return;
		case 3:
			emit findStrongestInRow(vec,para2,intMap[JAPara[2].toString()]);
			return;
		default:
			qDebug()<<"cannot emit find signal";
			return;
		}
	}
	if(funcName==QString("findNear"))
	{
		std::vector<GameUnit*> *vec=new std::vector<GameUnit*>();
		QString paraNum=(JOFind["parameter"].toArray())[0].toString();
		vecMap[paraNum]=vec;
		int size=(JOFind["parameter"].toArray()).size();

		para2=transRowNum((JOFind["parameter"].toArray())[1].toString());
		emit findNear(vec,para2,unitMap[JAPara[2].toString()],intMap[JAPara[3].toString()],intMap[JAPara[4].toString()]);
		return;
	}
	if(funcName==QString("findWeakestInAll"))
	{
		std::vector<GameUnit*> *vec=new std::vector<GameUnit*>();
		QString paraNum=(JOFind["parameter"].toArray())[0].toString();
		vecMap[paraNum]=vec;
		int size=(JOFind["parameter"].toArray()).size();

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
		std::vector<GameUnit*> *vec=new std::vector<GameUnit*>();
		QString paraNum=(JOFind["parameter"].toArray())[0].toString();
		vecMap[paraNum]=vec;
		int size=(JOFind["parameter"].toArray()).size();

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
	//QString funcName=funcOb["name"].toString();
	QJsonArray paraArray=funcOb["parameter"].toArray();
	if(funcName==QString("damageByN"))
	{
		std::vector<GameUnit*> *targetvec=nullptr;
		targetvec=getTargetVec(paraArray[0].toString());
		qDebug()<<"print all in the targetvec";
		if(targetvec==nullptr)
			qDebug()<<"targetvec==nullptr!";
		for(auto it=targetvec->begin();it!=targetvec->end();++it)
		{
			qDebug()<<(*it)->getName();
		}
		emit damageByN(getTargetVec(paraArray[0].toString()),intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("damageByNUnseenProtection"))
	{
		emit damageByNUnseenProtection(getTargetVec(paraArray[0].toString()),intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("boostByN"))
	{
		emit boostByN(getTargetVec(paraArray[0].toString()),intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("addProtectionByN"))
	{
		emit addProtectionByN(getTargetVec(paraArray[0].toString()),intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("lockTarget"))
	{
		emit lockTarget(getTargetVec(paraArray[0].toString()));
		return;
	}
	if(funcName==QString("makePowerToN"))
	{
		emit makePowerToN(getTargetVec(paraArray[0].toString()),intMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("destroyTarget"))
	{
		emit destroyTarget(getTargetVec(paraArray[0].toString()));
		return;
	}
	if(funcName==QString("eatTarget"))
	{
		emit eatTarget(getTargetVec(paraArray[0].toString()),self);
		return;
	}
	if(funcName==QString("moveTarget"))
	{
		emit moveTarget(getTargetVec(paraArray[0].toString()),intMap[paraArray[1].toString()]);
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
	if(funcName==QString("deployCardsFromBase"))
	{
		emit deployCardsFromBase(intMap[paraArray[0].toString()],intMap[paraArray[1].toString()],intMap[paraArray[2].toString()],boolMap[paraArray[3].toString()],intMap[paraArray[4].toString()]);
		return;
	}
	if(funcName==QString("putCardBackToBase"))
	{
		emit putCardBackToBase(getTargetUnit(paraArray[0].toString()),intMap[paraArray[1].toString()],boolMap[paraArray[2].toString()]);
		return;
	}
	if(funcName==QString("resurrectCardToHand"))
	{
		emit resurrectCardToHand(intMap[paraArray[0].toString()],boolMap[paraArray[1].toString()],boolMap[paraArray[2].toString()],intMap[paraArray[3].toString()]);
		return;
	}
	if(funcName==QString("resurrectCardToRow"))
	{
		emit resurrectCardToRow(intMap[paraArray[0].toString()],boolMap[paraArray[1].toString()],intMap[paraArray[2].toString()],intMap[paraArray[3].toString()],intMap[paraArray[4].toString()]);
	}
	if(funcName==QString("generateNCard"))
	{
		emit generateNCard(intMap[paraArray[0].toString()],intMap[paraArray[1].toString()],getTargetVec(paraArray[2].toString()),intMap[paraArray[3].toString()]);
		return;
	}
	if(funcName==QString("generateNCardWithOutChooseTarget"))
	{
		emit generateNCardWithOutChooseTarget(getTargetInt(paraArray[0].toString()),getTargetInt(paraArray[1].toString()),getTargetInt(paraArray[2].toString()),boolMap[paraArray[3].toString()]);
		return;
	}
	if(funcName==QString("getRow"))
	{
		//TODELETE
		int temp=getTargetInt(paraArray[1].toString());
		qDebug()<<"getRow para:rowNum"<<temp;
		emit getRow(getTargetVec(paraArray[0].toString()),getTargetInt(paraArray[1].toString()));
		return;
	}

}

int EffectManager::transRowNum(QString rowInfo)
{
	if(rowInfo=="selfRow")
	{
		//qDebug()<<self->getRowNum();
		return self->getRowNum();
	}
	if(rowInfo=="oppositeRow")
		return -(self->getRowNum());
	if(rowInfo=="chooseRow")
		return chooseRow();
	return -1;
}

void EffectManager::findTarget(QJsonObject JOFind)
{
	std::vector<GameUnit*> *vec=new std::vector<GameUnit*>();
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
		emit findNear(vec,para2,unitMap[JAPara[2].toString()],intMap[JAPara[3].toString()],intMap[JAPara[4].toString()]);
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
	std::vector<GameUnit*> *selfVec=new std::vector<GameUnit*>;
	selfVec->push_back(self);
	vecMap["self"]=selfVec;
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
				vecMap[(*itt).toString()]=new std::vector<GameUnit*>();
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

void EffectManager::implementEffect(bool turn)
{
//	if(side!=turn)
//	{
//		qDebug()<<"side!=turn";
//		return;
//	}
	if(!myTimerUp())
	{
		qDebug()<<"!myTimeup() "<<timer;
		updateTimer();
		return;
	}
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
		//TODELETE
		qDebug()<<"implement effect";
	}
	resetTimer();
}

void EffectManager::updateTimer()
{
	if(needTimer)
		--timer;
}

void EffectManager::resetTimer()
{
	if(needTimer)
		timer=cm->getTimer();
}

int EffectManager::chooseRow()
{
	QJsonObject info;
	QJsonArray arr;
	if(cm->getPosition()==QString("anywhere"))
	{
		if(cm->getLoyalty() == side)
		{
			arr.append(1);
			arr.append(2);
			arr.append(3);
		}
		else
		{
			arr.append(-1);
			arr.append(-2);
			arr.append(-3);
		}
	}
	else
	{
		int temp=cm->getPosition().toInt();
		if(cm->getLoyalty() == side)
			arr.append(temp);
		else
			arr.append(-temp);
	}
	info.insert("type","EffectChooseRow");
	info.insert("rowRange",arr);
	info.insert("wait",CONSTANT::waitForEffectTargetChoose);
	emit EffectChooseRow(&info);

	intMap["chooseRow"]=info["rowNum"].toInt();
	return info["rowNum"].toInt();
}

std::vector<GameUnit *> *EffectManager::chooseTarget()
{
	QJsonObject info;
	QJsonArray arr;
	if(cm->getPosition()==QString("anywhere"))
	{
		if(cm->getLoyalty() == side)
		{
			arr.append(1);
			arr.append(2);
			arr.append(3);
		}
		else
		{
			arr.append(-1);
			arr.append(-2);
			arr.append(-3);
		}
	}
	else
	{
		int temp=cm->getPosition().toInt();
		if(cm->getLoyalty() == side)
			arr.append(temp);
		else
			arr.append(-temp);
	}
	info.insert("type","EffectChooseTarget");
	info.insert("rowRange",arr);
	info.insert("wait",CONSTANT::waitForEffectTargetChoose);
	emit EffectChooseTarget(&info);

	int rowNum=info["rowNum"].toInt();
	std::vector<GameUnit*> *tempVec=new std::vector<GameUnit*>();
	emit getRow(tempVec,rowNum);
	auto it=tempVec->begin()+info["index"].toInt();
	std::vector<GameUnit*> *reVec=new std::vector<GameUnit*>();
	reVec->push_back((*it));
	return reVec;
}
