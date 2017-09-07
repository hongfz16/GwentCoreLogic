#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

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
	QJsonObject getDeployEffect();
	QJsonObject getRoutineEffect();
	QJsonObject getDeadWishEffect();
	QJsonObject getPrepare();
	QJsonObject getPassiveEffect();
	bool haveDeployEffect();
	bool haveRoutineEffect();
	bool haveDeadWishEffect();
	bool havePassiveEffect();
};

#endif // CARDMANAGER_H
