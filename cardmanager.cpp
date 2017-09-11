#include "cardmanager.h"

CardManager::CardManager(int _cardId, QObject *parent) : QObject(parent)
{
    cardId=_cardId;

	fileName=":/json/jsonFile/"+QString::number(cardId)+".json";

	//qDebug()<<fileName;

    QFile file(fileName);
    file.open(QFile::ReadOnly|QFile::Text);
    QString val=file.readAll();
    file.close();

	//qDebug()<<val;

    jsonFile=new QJsonDocument();
    jsonObject=new QJsonObject();

    *jsonFile=QJsonDocument::fromJson(val.toUtf8());
	*jsonObject=jsonFile->object();
}

CardManager::~CardManager()
{
	delete(jsonFile);
	delete(jsonObject);
}

bool CardManager::have(QString key)
{
	auto it=jsonObject->find(key);
	if(it!=jsonObject->end())
		return true;
	return false;
}

int CardManager::getFight()
{
    QJsonValue JVFight=jsonObject->value(QString("fight"));
    return JVFight.toInt();
}

QString CardManager::getName()
{
    QJsonValue JVName=jsonObject->value(QString("name"));
	return JVName.toString();
}

int CardManager::getType()
{
	QJsonValue JVName=jsonObject->value(QString("type"));
	return JVName.toInt();
}

QString CardManager::getPosition()
{
	QJsonValue JVName=jsonObject->value(QString("position"));
	return JVName.toString();
}

bool CardManager::getLoyalty()
{
	QJsonValue JVName=jsonObject->value(QString("loyalty"));
	return JVName.toBool();
}

int CardManager::getTimer()
{
	QJsonValue JVName=jsonObject->value(QString("timer"));
	return JVName.toInt();
}

QJsonObject CardManager::getDeployEffect()
{
	QJsonValue JVDeploy=(*jsonObject)["DeployEffect"];
	return JVDeploy.toObject();
}

QJsonObject CardManager::getRoutineEffect()
{
	QJsonValue JVRoutine=(*jsonObject)["RoutineEffect"];
	return JVRoutine.toObject();
}

QJsonObject CardManager::getDeadWishEffect()
{
	QJsonValue JVDeadWish=(*jsonObject)["DeadWish"];
	return JVDeadWish.toObject();
}

QJsonObject CardManager::getPrepare()
{
	QJsonValue JVDeadWish=(*jsonObject)["prepare"];
	QJsonObject temp=JVDeadWish.toObject();
	return temp;
}

QJsonObject CardManager::getDeployPassiveEffect()
{
	QJsonValue JVDeadWish=(*jsonObject)["DeployPassiveEffect"];
	return JVDeadWish.toObject();
}

QJsonObject CardManager::getBasePassiveEffect()
{
	QJsonValue JVDeadWish=(*jsonObject)["BasePassiveEffect"];
	return JVDeadWish.toObject();
}

QJsonObject CardManager::getCemeteryPassiveEffect()
{
	QJsonValue JVDeadWish=(*jsonObject)["CemeteryPassiveEffect"];
	return JVDeadWish.toObject();
}

bool CardManager::haveDeployEffect()
{
	return have(QString("DeployEffect"));
}

bool CardManager::haveRoutineEffect()
{
	return have(QString("RoutineEffect"));
}

bool CardManager::haveDeadWishEffect()
{
	return have(QString("DeadWish"));
}

bool CardManager::haveDeployPassiveEffect()
{
	return have(QString("DeployPassiveEffect"));
}

bool CardManager::haveBasePassiveEffect()
{
	return have(QString("BasePassiveEffect"));
}

bool CardManager::haveCemeteryPassiveEffect()
{
	return have(QString("CemeteryPassiveEffect"));
}

