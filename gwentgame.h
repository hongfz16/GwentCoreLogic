#ifndef GWENTGAME_H
#define GWENTGAME_H

#include <QObject>

class GwentGame : public QObject
{
	Q_OBJECT
public:
        explicit GwentGame(QObject *parent = nullptr);

signals:

public slots:
};

#endif // GWENTGAME_H
