#include "cardmanager.h"

CardManager::CardManager(int _cardId, QObject *parent) : QObject(parent)
{
    cardId=_cardId;

	fileName=":/json/jsonFile/"+QString::number(cardId)+".json";

    qDebug()<<fileName;

    QFile file(fileName);
    file.open(QFile::ReadOnly|QFile::Text);
    QString val=file.readAll();
    file.close();

    qDebug()<<val;

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

QJsonObject CardManager::getDeployEffect()
{
	QJsonValue JVDeploy=jsonObject->value(QString("DeployEffect"));
	return JVDeploy.toObject();
}

QJsonObject CardManager::getRoutineEffect()
{
	QJsonValue JVRoutine=jsonObject->value(QString("RoutineEffect"));
	return JVRoutine.toObject();
}

QJsonObject CardManager::getDeadWishEffect()
{
	QJsonValue JVDeadWish=jsonObject->value(QString("DeadWish"));
	return JVDeadWish.toObject();
}

