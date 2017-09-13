#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "gameconstant.h"


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(qintptr ID, QObject *parent=0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketError);
    void needToRemoveFromMap(qintptr id); //SLOT: GwentServer::removeThreadFromMap

	void sendSignalToServer(qintptr id,QString mess); //SLOT: GwentServer::threadSendSignalToServer
	void sendSignalTogameField(QJsonObject info);
	void sendSignalToController(bool side,QString mess);

public slots:
    void readyRead();
    void disconnected();

	void sendQJsonObject(QJsonObject info);

	void sendQJsonObjectAndWaitForResponde(QJsonObject* info);

	void waitForDrawCard(QJsonObject* info);

	void waitForDeploy(QJsonObject* info);

	void waitForChooseCard(QJsonObject *info);


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

	void parseQJsonObject(QJsonDocument JDData);


public:
    void dealWithData(QByteArray *data); // Called by void readyRead function
    void sendSomeData(QByteArray *data); // Used to send some data

	bool isVerified() {return verified;}
	bool isPairing() {return pairing;}
	bool isOnGame() {return onGame;}

	QString getUserName() {return userName;}
	int getUserId() {return userId;}

	bool getSide() {return side;}
};

#endif // MYTHREAD_H
