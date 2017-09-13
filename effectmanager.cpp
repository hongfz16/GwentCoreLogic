#include "effectmanager.h"

EffectManager::EffectManager(int id, bool _side, GameUnit *target, int effectType, QObject *parent) : QObject(parent), self(target),side(_side)
{
	cm=new CardManager(id);
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
	needToBeDeleted=false;
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
	if(key==QString("chooseTargetRowNum"))
	{
		chooseTarget();
		return intMap["chooseTargetRowNum"];
	}
	if(key==QString("chooseCard"))
	{
		intMap["chooseCard"]=chooseCard(arrMap["QJsonArray"]);
		qDebug()<<"implement chooseCard once";
		return intMap["chooseCard"];
	}
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
	auto itt=JOCondition.find("notExist");
	if(it!=JOCondition.end() || itt!=JOCondition.end())
	{
		qDebug()<<"from judgeCondition enter judgeExist";
		return judgeExist(JOCondition);
	}
	return true;
}

bool EffectManager::judgeCompare(QJsonObject JOCompare)
{
	QJsonValue JVPara1=JOCompare["para1"];
	QJsonValue JVPara2=JOCompare["para2"];
	int para1=judgeCompareGetNum(JVPara1);
	int para2=judgeCompareGetNum(JVPara2);
	return (para1>=para2) ? true:false;
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
	QJsonArray arr;
	bool choose;
	int type=JOCompare["type"].toInt();
	///0 all 1 my -1 op
	if(!side) type=-type;
	if(JOCompare.find("exist")!=JOCompare.end())
	{
		arr=JOCompare["exist"].toArray();
		choose=true;
	}
	else if(JOCompare.find("notExist")!=JOCompare.end())
	{
		arr=JOCompare["notExist"].toArray();
		choose=false;
	}
	bool *re=new bool();
	for(auto it=arr.begin();it!=arr.end();++it)
	{
		qDebug()<<"send exist signal";
		emit exist((*it).toInt(),re,type);
		qDebug()<<"exist signal return";
		if((*re)==true && choose==true)
		{
			return true;
		}
		else if((*re)==false && choose==false)
		{
			return true;
		}
	}
	return false;
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
#ifdef DEBUG
		std::vector<GameUnit*> *targetvec=nullptr;
		targetvec=getTargetVec(paraArray[0].toString());
		qDebug()<<"print all in the targetvec";
		if(targetvec==nullptr)
			qDebug()<<"targetvec==nullptr!";
		for(auto it=targetvec->begin();it!=targetvec->end();++it)
		{
			qDebug()<<(*it)->getName();
		}
#endif
		emit damageByN(getTargetVec(paraArray[0].toString()),getTargetInt(paraArray[1].toString()));
		return;
	}
	if(funcName==QString("damageByNUnseenProtection"))
	{
		emit damageByNUnseenProtection(getTargetVec(paraArray[0].toString()),getTargetInt(paraArray[1].toString()));
		return;
	}
	if(funcName==QString("boostByN"))
	{
		emit boostByN(getTargetVec(paraArray[0].toString()),getTargetInt(paraArray[1].toString()));
		return;
	}
	if(funcName==QString("addProtectionByN"))
	{
		emit addProtectionByN(getTargetVec(paraArray[0].toString()),getTargetInt(paraArray[1].toString()));
		return;
	}
	if(funcName==QString("lockTarget"))
	{
		emit lockTarget(getTargetVec(paraArray[0].toString()));
		return;
	}
	if(funcName==QString("makePowerToN"))
	{
		emit makePowerToN(getTargetVec(paraArray[0].toString()),getTargetInt(paraArray[1].toString()));
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
		emit moveTarget(getTargetVec(paraArray[0].toString()),getTargetInt(paraArray[1].toString()));
		return;
	}
	if(funcName==QString("peekNCardsFromBase"))
	{
		emit peekNCardsFromBase(intMap[paraArray[0].toString()],boolMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("peekSpecificCardFromBase"))
	{
		emit peekSpecificCardFromBase(getTargetInt(paraArray[0].toString()),boolMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("deployCardsFromBase"))
	{
		qDebug()<<"deploycardsfrombase signal send";
		emit deployCardsFromBase(getTargetInt(paraArray[0].toString()),getTargetInt(paraArray[1].toString()),getTargetInt(paraArray[2].toString()),boolMap[paraArray[3].toString()],getTargetInt(paraArray[4].toString()));
		qDebug()<<"deploycardsfrombase signal end";
		return;
	}
	if(funcName==QString("putCardBackToBase"))
	{
		emit putCardBackToBase(getTargetUnit(paraArray[0].toString()),getTargetInt(paraArray[1].toString()),boolMap[paraArray[2].toString()]);
		return;
	}
	if(funcName==QString("resurrectCardToHand"))
	{
		emit resurrectCardToHand(getTargetInt(paraArray[0].toString()),boolMap[paraArray[1].toString()],boolMap[paraArray[2].toString()],getTargetInt(paraArray[3].toString()));
		return;
	}
	if(funcName==QString("resurrectCardToRow"))
	{
		emit resurrectCardToRow(getTargetInt(paraArray[0].toString()),boolMap[paraArray[1].toString()],getTargetInt(paraArray[2].toString()),getTargetInt(paraArray[3].toString()),getTargetInt(paraArray[4].toString()));
	}
	if(funcName==QString("generateNCard"))
	{
		qDebug()<<"generateNCard signal sent";
		emit generateNCard(getTargetInt(paraArray[0].toString()),getTargetInt(paraArray[1].toString()),getTargetVec(paraArray[2].toString()),getTargetInt(paraArray[3].toString()),boolMap[paraArray[4].toString()]);
		qDebug()<<"generateNCard signal end";
		return;
	}
	if(funcName==QString("generateNCardWithOutChooseTarget"))
	{
		//qDebug()<<"Start generate";
		emit generateNCardWithOutChooseTarget(getTargetInt(paraArray[0].toString()),getTargetInt(paraArray[1].toString()),getTargetInt(paraArray[2].toString()),boolMap[paraArray[3].toString()]);
		//qDebug()<<"end generate"<<getTargetInt(paraArray[0].toString());
		return;
	}
	if(funcName==QString("getRow"))
	{
#ifdef DEBUG
		//TODELETE
		int temp=getTargetInt(paraArray[1].toString());
		qDebug()<<"getRow para:rowNum"<<temp;
#endif
		emit getRow(getTargetVec(paraArray[0].toString()),getTargetInt(paraArray[1].toString()));
		return;
	}
	if(funcName==QString("deployRandomCardFromBase"))
	{
		qDebug()<<"DeplyRandomCard signal send";
		emit deployRandomCardFromBase(getTargetInt(paraArray[0].toString()),getTargetInt(paraArray[1].toString()),boolMap[paraArray[2].toString()]);
		qDebug()<<"DeployRandomCard end";
		return;
	}
	if(funcName==QString("findWeather"))
	{
		emit findWeather(getTargetVec(paraArray[0].toString()),boolMap[paraArray[1].toString()]);
		return;
	}
	if(funcName==QString("getRight"))
	{
		qDebug()<<"getright signal send";
		qDebug()<<getTargetUnit(paraArray[0].toString())->getCardId();
		emit getRight(getTargetUnit(paraArray[0].toString()),getTargetVec(paraArray[1].toString()));
		qDebug()<<"getright signal return";
		return;
	}
	if(funcName==QString("getTargetFight"))
	{
		intMap[paraArray[1].toString()]=getTargetFight(getTargetVec(paraArray[0].toString()));
	}
	if(funcName==QString("findSpecWeather"))
	{
		intMap[paraArray[2].toString()]=findSpecWeather(boolMap[paraArray[0].toString()],getTargetInt(paraArray[1].toString()));
		intMap[paraArray[2].toString()+"Reverse"]=-intMap[paraArray[2].toString()];
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
		if(it.key()=="QJsonArray")
		{
			QJsonArray arr=it.value().toArray();
			arrMap["QJsonArray"]=arr;
		}
	}
}

int EffectManager::findSpecWeather(bool _side,int _id)
{
	std::vector<GameUnit*> *temp=new std::vector<GameUnit*>();
	emit findWeather(temp,_side);
	for(auto it=temp->begin();it!=temp->end();++it)
	{
		if((*it)->getCardId()==_id)
			return (*it)->getRowNum();
	}
}

bool EffectManager::implementEffect(bool turn,int type)
{
	qDebug()<<"<start>implement effect</start>" << unitId;
	if(!myTimerUp())
	{
		qDebug()<<"!myTimeup() "<<timer;
		updateTimer();
		return false;
	}
	auto it=effectJson.find("condition");
	if(it!=effectJson.end())
	{
		qDebug()<<"have condition";
		if(!judgeCondition((*it).toObject()))
			return false;
	}
	qDebug()<<"do not have condition";
	it=effectJson.find("waitForEaten");
	if(it!=effectJson.end() && type!=1)
	{
		return false;
	}
	else if(it!=effectJson.end() && type==1 && turn!=side)
	{
		return false;
	}
	it=effectJson.find("steps");
	if(it==effectJson.end())
	{
		return false;
	}
	QJsonArray JAFunctions=((*it).toObject())["function"].toArray();
	for(auto arrayit=JAFunctions.begin();arrayit!=JAFunctions.end();++arrayit)
	{
		implementFuntion((*arrayit).toObject());
		//TODELETE
		qDebug()<<"<end>implement effect</end> " << unitId;
	}
	resetTimer();
	return true;
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
	/*
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
		int temp=0;
		if(cm->getPosition()=="front")
			temp=1;
		if(cm->getPosition()=="middle")
			temp=2;
		if(cm->getPosition()=="back")
			temp=3;
		if(cm->getLoyalty() == side)
			arr.append(temp);
		else
			arr.append(-temp);
	}
	*/
	for(int i=1;i<=3;++i){
		arr.append(i);
		arr.append(-i);
	}
	info.insert("type","EffectChooseRow");
	info.insert("rowRange",arr);
	info.insert("wait",CONSTANT::waitForEffectTargetChoose);
	info.insert("side",side);
	emit EffectChooseRow(&info);

	intMap["chooseRow"]=info["rowNum"].toInt();
	return info["rowNum"].toInt();
}

std::vector<GameUnit *> *EffectManager::chooseTarget()
{
	QJsonObject info;
	QJsonArray arr;
	/*
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
		int temp=0;
		if(cm->getPosition()=="front")
			temp=1;
		if(cm->getPosition()=="middle")
			temp=2;
		if(cm->getPosition()=="back")
			temp=3;
		if(cm->getLoyalty() == side)
			arr.append(temp);
		else
			arr.append(-temp);
	}*/
	for(int i=1;i<=3;++i){
		arr.append(i);
		arr.append(-i);
	}
	info.insert("type","EffectChooseTarget");
	info.insert("rowRange",arr);
	info.insert("wait",CONSTANT::waitForEffectTargetChoose);
	info.insert("side",side);
	emit EffectChooseTarget(&info);
	int rowNum=info["rowNum"].toInt();
	std::vector<GameUnit*> *tempVec=new std::vector<GameUnit*>();
	emit getRowIncludeWeather(tempVec,rowNum);

	auto it=tempVec->begin()+(info["index"].toInt());
	qDebug()<<"after use begin";
	std::vector<GameUnit*> *reVec=new std::vector<GameUnit*>();
	reVec->push_back((*it));

	intMap["chooseTargetRowNum"]=rowNum;
	qDebug()<<"add choose target rowNum"<<rowNum;
	intMap["chooseTargetIndex"]=info["index"].toInt();
	qDebug()<<"add choose target index"<<info["index"].toInt();
	return reVec;
}

int EffectManager::chooseCard(QJsonArray arr)
{
	QJsonObject info;
	info.insert("type","EffectChooseCard");
	info.insert("range",arr);
	emit EffectChooseCard(&info);

	int chosen=info["chosen"].toInt();
	int left=info["left"].toInt();
	intMap["left"]=left;
	return chosen;
}
