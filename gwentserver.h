#ifndef GWENTSERVER_H
#define GWENTSERVER_H

#include <QObject>
#include <QTcpServer>
#include <gwentgame.h>
#include <map>
#include "mythread.h"
#include "gameconstant.h"

class GwentServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit GwentServer(QObject *parent = nullptr);
    void startServer(); // need to be called in main after a new GwentServer instance created

protected:
    void incomingConnection(qintptr socketDescriptor); // auto called by QTcpServer

signals:

public slots:
    void removeThreadFromMap(qintptr id); // SIGNAL: MyThread::needToRemoveFromMap
    void threadSendSignalToServer(qintptr id,QString mess); //SIGNAL: MyThread::sendSignalToServer

private:
    std::map<qintptr,MyThread*> idThreadMap;

	std::vector<GwentGame*> gameManager;



public:
    void addThreadToMap(qintptr ID,MyThread *thread);

#ifdef DEBUG
	void myPair();
#endif
};

#endif // GWENTSERVER_H
