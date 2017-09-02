#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#include <QObject>
#include <QDebug>
#include "cardmanager.h"

class GameUnit : public QObject
{
	Q_OBJECT
public:
        explicit GameUnit(int _cardId, QObject *parent = nullptr);

signals:
    void stateChanged();
public slots:

private:
    const int cardId;
    QString name;
    bool type;
    int fight;
    int protection;
    bool locked;

public:
    int getCardId() const {return cardId;}
    bool getType() const {return type;}
    int getFight() const {return fight;}
    int getProtection() const {return protection;}
    bool isLocked() const {return locked;}

    void decreaseFight(int num, bool protectionUnseen=false);
    void addFight(int num);
    void decreaseProtection(int num);
    void addProtection(int num);
    void undoLock();
    void addLock();
};

#endif // GAMEUNIT_H
