#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>
#include <QObject>


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(qintptr ID, QObject *parent=0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketError);
    void needToRemoveFromMap(qintptr id); //SLOT: GwentServer::removeThreadFromMap
    void sendSignalToServer(qintptr id); //SLOT: GwentServer::threadSendSignalToServer

public slots:
    void readyRead();
    void disconnected();

	//game involved slots
	void gameUnitChanged(int rowNum,int index,bool side,QJsonObject unitInfo);
	void toBeDestroyed(int rowNum,int index,bool side);

private:
    qintptr socketDescriptor;
    QTcpSocket *socket;

	//main status
	bool verified;
	bool pairing;
	bool onGame;
	QString userName;
	int userId;

	//game status
	bool side;


public:
    void dealWithData(QByteArray *data); // Called by void readyRead function
    void sendSomeData(QByteArray *data); // Used to send some data

	bool isVerified() {return verified;}
	bool isPairing() {return pairing;}
	bool isOnGame() {return onGame;}

	QString getUserName() {return userName;}
	int getUserId() {return userId;}

	bool getSide() {if(isOnGame()) return side;}
};

#endif // MYTHREAD_H
