#ifndef GWENTGAME_H
#define GWENTGAME_H

#include <QObject>

#include "fieldmanager.h"
#include "gameconstant.h"

class GwentGame : public QObject
{
	Q_OBJECT
public:
	explicit GwentGame(MyThread *myThread,MyThread *opThread,QObject *parent = nullptr);

	void startGame();


private:
	FieldManager *fm;

signals:

public slots:
};

#endif // GWENTGAME_H
