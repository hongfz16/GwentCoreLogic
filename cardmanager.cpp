#include "cardmanager.h"

CardManager::CardManager(int _cardId, QObject *parent) : QObject(parent)
{
    cardId=_cardId;

    fileName=":/json/"+QString::number(cardId)+".json";

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
