#include "mythread.h"

MyThread::MyThread(qintptr ID, QObject *parent):QThread(parent)
{
    this->socketDescriptor=ID;
	verified=false;
	pairing=false;
	onGame=false;
}

void MyThread::run()
{
    qDebug()<<"Thread started!";

    socket=new QTcpSocket();

    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        // something's wrong, we just emit a signal
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << socketDescriptor << " Client connected";

    exec();
}

void MyThread::readyRead()
{
    QByteArray Data=socket->readAll();
    dealWithData(&Data);
}

void MyThread::disconnected()
{
    qDebug()<<socketDescriptor<<" Disconnected!";
    emit(needToRemoveFromMap(socketDescriptor));
    socket->deleteLater();
    exit(0);
}

void MyThread::dealWithData(QByteArray *data)
{
    qDebug()<<socketDescriptor<<" data in: "<<data;
}

void MyThread::sendSomeData(QByteArray *data)
{
    socket->write(*data);
    if(socket->waitForBytesWritten())
        qDebug()<<data<<" sent successfully";
    else
        qDebug()<<data<<" sending failed"<<socket->errorString();
}
