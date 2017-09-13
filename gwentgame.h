#ifndef GWENTGAME_H
#define GWENTGAME_H

#include <QObject>
#include <QDebug>

#include "fieldmanager.h"
#include "gameconstant.h"

class GwentGame : public QObject
{
	Q_OBJECT
public:
	explicit GwentGame(MyThread *_myThread, MyThread *_opThread, QObject *parent = nullptr);

	void startGame();


private:
	FieldManager *fm;

signals:

public slots:
};

#endif // GWENTGAME_H
