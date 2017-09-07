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

void MyThread::sendQJsonObject(QJsonObject info)
{
	QByteArray temp=QJsonDocument(info).toJson();
	sendSomeData(&temp);
}

void MyThread::parseQJsonObject(QJsonDocument JDData)
{
	QJsonObject JOData=JDData.object();
	QString to=JOData["to"].toString();
	if(to=="Server")
	{
		QString mess=JOData["Message"].toString();
		emit sendSignalToServer(socketDescriptor,mess);
		return;
	}
	if(to=="Field")
	{
		emit sendSignalTogameField(JOData);
		return;
	}
	if(to=="Controller")
	{
		QString mess=JOData["Message"].toString();
		emit sendSignalToController(side,mess);
		return;
	}
}

void MyThread::dealWithData(QByteArray *data)
{
    qDebug()<<socketDescriptor<<" data in: "<<data;

	QJsonDocument incomeData;
	incomeData.fromJson(*data);
	parseQJsonObject(incomeData);
}

void MyThread::sendSomeData(QByteArray *data)
{
    socket->write(*data);
    if(socket->waitForBytesWritten())
        qDebug()<<data<<" sent successfully";
    else
        qDebug()<<data<<" sending failed"<<socket->errorString();
}
