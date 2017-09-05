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

public:
    int getFight();
    QString getName();
	QJsonObject getDeployEffect();
	QJsonObject getRoutineEffect();
	QJsonObject getDeadWishEffect();
};

#endif // CARDMANAGER_H
