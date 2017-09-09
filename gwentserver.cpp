#include "gwentserver.h"

GwentServer::GwentServer(QObject *parent) : QTcpServer(parent)
{

}

void GwentServer::startServer()
{
    int port=1234;
    while(!this->listen(QHostAddress::Any,port))
    {
        qDebug()<<"Could not start server in port "<<port;
        ++port;
    }
    if(this->isListening())
        qDebug()<<"Start listening on port "<<port;
}

void GwentServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<<socketDescriptor<<"Connecting...";

    MyThread *thread=new MyThread(socketDescriptor,this);

    addThreadToMap(socketDescriptor,thread);

    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    connect(thread,SIGNAL(needToRemoveFromMap(qintptr)),this,SLOT(removeThreadFromMap(qintptr)));
	connect(thread,SIGNAL(sendSignalToServer(qintptr,QString)),this,SLOT(threadSendSignalToServer(qintptr,QString)));

	thread->start();

}

void GwentServer::removeThreadFromMap(qintptr id)
{
    idThreadMap.erase(id);
    qDebug()<<"erased!";
}

void GwentServer::threadSendSignalToServer(qintptr id, QString mess)
{
	qDebug()<<"Thread "<<id<<" send message "<<mess;
}

void GwentServer::myPair()
{
#ifdef DEBUG
	if(idThreadMap.size()>=2)
	{
		auto it=idThreadMap.begin();
		MyThread *myThread=it->second;
		it++;
		MyThread *opThread=(it)->second;
		GwentGame *d_game=new GwentGame(myThread,opThread);
		d_game->startGame();
	}
#endif
}

void GwentServer::addThreadToMap(qintptr ID, MyThread *thread)
{
    idThreadMap[ID]=thread;
}
