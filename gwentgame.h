#ifndef GWENTGAME_H
#define GWENTGAME_H

#include <QObject>

#include "fieldmanager.h"

class GwentGame : public QObject
{
	Q_OBJECT
public:
	explicit GwentGame(QObject *parent = nullptr);

	void startGame();


private:
	FieldManager *fm;

signals:

public slots:
};

#endif // GWENTGAME_H
