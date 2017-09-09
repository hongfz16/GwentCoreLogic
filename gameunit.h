#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#include <QObject>
#include <QDebug>
#include "cardmanager.h"
#include "gameconstant.h"

class GameUnit : public QObject
{
	Q_OBJECT
public:
        explicit GameUnit(int _cardId, QObject *parent = nullptr);

signals:
	void stateChanged(GameUnit*);
public slots:

private:
    const int cardId;
    QString name;
    bool type;
    int fight;
    int protection;
    bool locked;

	int rowNum;
	int oldRowNum;
	bool side;

	CONSTANT::cardType myType;

public:
    int getCardId() const {return cardId;}
	QString getName() const {return name;}
    bool getType() const {return type;}
    int getFight() const {return fight;}
    int getProtection() const {return protection;}
    bool isLocked() const {return locked;}
	int getRowNum() const {return rowNum;}
	int getOldRowNum() const {return oldRowNum;}
	int getSide() const {return side;}

    void decreaseFight(int num, bool protectionUnseen=false);
    void addFight(int num);
    void decreaseProtection(int num);
    void addProtection(int num);
    void undoLock();
    void addLock();

	void setFightToN(int N);
	void setRowNum(int num);
	void setSide(bool _side);
};

#endif // GAMEUNIT_H
