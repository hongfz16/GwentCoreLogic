#ifndef GAMEEFFECT_H
#define GAMEEFFECT_H

#include <QObject>
#include <vector>
#include <gameunit.h>

class GameEffect : public QObject
{
	Q_OBJECT
public:
	explicit GameEffect(QObject *parent = nullptr);

signals:

public slots:

private:
	std::vector<GameUnit*> *targets;
	int
};

#endif // GAMEEFFECT_H
