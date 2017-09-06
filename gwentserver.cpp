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

void GwentServer::addThreadToMap(qintptr ID, MyThread *thread)
{
    idThreadMap[ID]=thread;
}
