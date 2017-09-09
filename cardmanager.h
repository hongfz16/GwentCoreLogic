#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include "gameconstant.h"

class CardManager : public QObject
{
	Q_OBJECT
public:
	explicit CardManager(int _cardId, QObject *parent = nullptr);
	~CardManager();

signals:

public slots:

private:
	int cardId;
    QString fileName;
    QJsonDocument *jsonFile;
    QJsonObject *jsonObject;

	bool have(QString key);

public:
    int getFight();
    QString getName();
	int getType();
	QString getPosition();
	bool getLoyalty();
	int getTimer();

	QJsonObject getDeployEffect();
	QJsonObject getRoutineEffect();
	QJsonObject getDeadWishEffect();
	QJsonObject getPrepare();
	QJsonObject getDeployPassiveEffect();
	QJsonObject getBasePassiveEffect();
	QJsonObject getCemeteryPassiveEffect();
	bool haveDeployEffect();
	bool haveRoutineEffect();
	bool haveDeadWishEffect();
	bool haveDeployPassiveEffect();
	bool haveBasePassiveEffect();
	bool haveCemeteryPassiveEffect();
};

#endif // CARDMANAGER_H
