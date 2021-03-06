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

void MyThread::sendQJsonObjectAndWaitForResponde(QJsonObject *info)
{
#ifndef DEBUG
	disconnect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
	sendQJsonObject(*info);
	int millisec=(*info)["wait"].toInt()*CONSTANT::millisecPerSec;
	if(!socket->waitForReadyRead(millisec+CONSTANT::connectBreakJudge))
	{
		info->insert("error","connection broken");
		qDebug()<<"Connection broken!"<<side;
		/*
		QJsonObject timeout;
		timeout.insert("type","command");
		timeout.insert("commands","cancel");
		sendQJsonObject(timeout);
		*/
	}
	else
	{
		QByteArray data=socket->readAll();
		qDebug()<<data;
		QJsonDocument temp;
		temp=QJsonDocument::fromJson(data);
		QJsonObject infoBack=temp.object();
		if(infoBack.find("to")==infoBack.end())
		{
			qDebug()<<"no to";
		}
		QString to=infoBack["to"].toString();
		qDebug()<<to;
		if(to==QString("Field"))
		{
			if(infoBack.find("timeout")!=infoBack.end())
				info->insert("exception","timeout");
			if(infoBack.find("rowNum")!=infoBack.end())
				info->insert("rowNum",infoBack["rowNum"]);
			if(infoBack.find("index")!=infoBack.end())
				info->insert("index",infoBack["index"]);
		}
		if(to==QString("Controller"))
		{
			QString mess=infoBack["Message"].toString();
			emit sendSignalToController(side,mess);
		}
	}
	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);

#endif

#ifdef DEBUG
	int d_rownum,d_index;
	qDebug()<<"input a rowNum";
	std::cin>>d_rownum;
	info->insert("rowNum",d_rownum);
	qDebug()<<"input an index";
	std::cin>>d_index;
	info->insert("index",d_index);
#endif

}

void MyThread::waitForDrawCard(QJsonObject *info)
{
#ifndef DEBUG
	disconnect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

	//sendQJsonObject(*info);
	int millisec=(*info)["wait"].toInt()*CONSTANT::millisecPerSec;
	if(!socket->waitForReadyRead(millisec+CONSTANT::connectBreakJudge))
	{
		info->insert("error","connection broken");
		qDebug()<<"Connection broken!"<<side;
	}
	else
	{
		QByteArray data=socket->readAll();
		QJsonDocument temp;
		temp=QJsonDocument::fromJson(data);
		QJsonObject infoBack=temp.object();
		QString to=infoBack.find("to").value().toString();
		if(infoBack.find("to")==infoBack.end())
			qDebug()<<"infoback no to";
		qDebug()<<side<<" data "<<data<<"\n"<<to;

		if(to==QString("Field"))
		{
			if(infoBack.find("timeout")!=infoBack.end())
				info->insert("exception","timeout");
			if(infoBack.find("hand")!=infoBack.end())
			{
				info->insert("hand",infoBack["hand"]);
			}
			else
			{
				qDebug()<<"can not find hand in infoback";
			}
			if(infoBack.find("base")!=infoBack.end())
			{
				info->insert("base",infoBack["base"]);
			}
		}
		if(to==QString("Controller"))
		{
			QString mess=infoBack["Message"].toString();
			emit sendSignalToController(side,mess);
		}
	}

	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
#endif
#ifdef DEBUG
	info->insert("cancel",0);
#endif
}

void MyThread::waitForDeploy(QJsonObject *info)
{
#ifndef DEBUG
	disconnect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

	sendQJsonObject(*info);
	int millisec=(*info)["wait"].toInt()*CONSTANT::millisecPerSec;
	if(!socket->waitForReadyRead(millisec+CONSTANT::connectBreakJudge))
	{
		info->insert("error","conection broken");
		qDebug()<<"Connection broken!"<<side;
	}
	else
	{
		QByteArray data=socket->readAll();
		QJsonDocument temp;
		temp=QJsonDocument::fromJson(data);
		QJsonObject infoBack=temp.object();
		QString to=infoBack["to"].toString();
		if(to==QString("Field"))
		{
			if(infoBack.find("timeout")!=infoBack.end())
			{
				info->insert("exception","timeout");
			}
			if(infoBack.find("handCardIndex")!=infoBack.end())
			{
				info->insert("handCardIndex",infoBack["handCardIndex"]);
			}
			if(infoBack.find("rowNum")!=infoBack.end())
			{
				info->insert("rowNum",infoBack["rowNum"]);
			}
			if(infoBack.find("index")!=infoBack.end())
			{
				info->insert("index",infoBack["index"]);
			}
		}
		if(to==QString("Controller"))
		{
			QString mess=infoBack["Message"].toString();
			emit sendSignalToController(side,mess);
		}
	}

	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
#endif

#ifdef DEBUG
	int d_handcardindex,d_rownum,d_index;
	qDebug()<<"input a handcard index";
	std::cin>>d_handcardindex;
	if(d_handcardindex==1234)
	{
		info->insert("pass",0);
		return;
	}
	qDebug()<<"input a rownum";
	std::cin>>d_rownum;
	qDebug()<<"input an index";
	std::cin>>d_index;
	info->insert("handCardIndex",d_handcardindex);
	info->insert("rowNum",d_rownum);
	info->insert("index",d_index);
	//qDebug()<<*info;
#endif
}

void MyThread::waitForChooseCard(QJsonObject *info)
{
#ifndef DEBUG
	disconnect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

	sendQJsonObject(*info);
	//int millisec=(*info)["wait"].toInt()*CONSTANT::millisecPerSec;
	if(!socket->waitForReadyRead(millisec+CONSTANT::connectBreakJudge))
	{
		info->insert("error","conection broken");
		qDebug()<<"Connection broken!"<<side;
	}
	else
	{
		QByteArray data=socket->readAll();
		QJsonDocument temp;
		temp=QJsonDocument::fromJson(data);
		QJsonObject infoBack=temp.object();
		QString to=infoBack["to"].toString();
		if(to==QString("Field"))
		{
			if(infoBack.find("timeout")!=infoBack.end())
			{
				info->insert("exception","timeout");
			}
			if(infoBack.find("chosen")!=infoBack.end())
			{
				info->insert("chosen",infoBack["chosen"]);
			}
			if(infoBack.find("left")!=infoBack.end())
			{
				info->insert("left",infoBack["left"]);
			}
		}
		if(to==QString("Controller"))
		{
			QString mess=infoBack["Message"].toString();
			emit sendSignalToController(side,mess);
		}
	}

	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
#endif
#ifdef DEBUG
	qDebug()<<"ChooseCard";
	QJsonArray arr=info->find("range").value().toArray();
	for(auto it=arr.begin();it!=arr.end();++it)
	{
		qDebug()<<(*it).toInt();
	}
	int index=0;
	qDebug()<<"Input Chosen Index (count from 0):";
	std::cin>>index;
	int chosen=arr[index].toInt();
	qDebug()<<"Chosen: "<<chosen;
	if(arr.size()==2)
	{
		int left=0;
		if(index==0)
			left=arr[1].toInt();
		else if(index==1)
			left=arr[0].toInt();
		info->insert("left",left);
		qDebug()<<"Left: "<<left;
	}
	info->insert("chosen",chosen);
#endif
}

void MyThread::parseQJsonObject(QJsonDocument JDData)
{
	QJsonObject JOData=JDData.object();
	QString to=JOData["to"].toString();
	if(to==QString("Server"))
	{
		QString mess=JOData["Message"].toString();
		emit sendSignalToServer(socketDescriptor,mess);
		return;
	}
	if(to==QString("Field"))
	{
		emit sendSignalTogameField(JOData);
		return;
	}
	if(to==QString("Controller"))
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
	//wait(300);
    socket->write(*data);
    if(socket->waitForBytesWritten())
        qDebug()<<data<<" sent successfully";
    else
        qDebug()<<data<<" sending failed"<<socket->errorString();
}
